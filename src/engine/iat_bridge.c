/*
 * IAT Bridge -- Generic Win32 API pass-through + MSS/Smacker shims.
 *
 * For Win32 APIs (KERNEL32, USER32, GDI32, ADVAPI32, WINMM):
 *   Use generic bridges that pass calls through to real Win32 APIs.
 *   Arguments are read from the simulated stack and passed directly.
 *
 * For game-specific libraries (mss32, smackw32, dplayx):
 *   Use custom bridges that call our shim implementations.
 */

/* windows.h first: winnt.h contains inline asm ("mov eax, ...") that the
 * RECOMP_GENERATED_CODE register aliases below would rewrite. */
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#define RECOMP_GENERATED_CODE
#include "recomp_runtime.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#endif

/* src/video/ddraw_shim.c -- we stand in for ddraw.dll entirely */
void ddraw_shim_init(void);
u32  ddraw_shim_getproc(const char *name);

#include "../sound/miles_shim.h"
#include "../video/smacker_shim.h"

/* ===== Bridge address allocation ===== */
#define GTA_IMAGE_BASE 0x00400000u
#define BRIDGE_BASE 0xB0000000u
#define MAX_BRIDGES 512

typedef struct {
    u32 iat_va;
    const char *name;
    void (*handler)(void);
} bridge_entry_t;

static bridge_entry_t bridges[MAX_BRIDGES];
static int num_bridges = 0;

/* Which bridge the dispatcher just resolved. The DirectDraw shim points many
 * vtable slots at ONE handler and reads this to tell them apart, instead of
 * carrying dozens of near-identical thunks. */
u32 g_bridge_hit;


/* A callable address the lifted dispatcher resolves to `handler`, with no IAT
 * slot behind it -- for pointers we hand the game ourselves (GetProcAddress
 * results, COM vtable slots). */
u32 recomp_alloc_bridge(const char *name, void (*handler)(void)) {
    if (num_bridges >= MAX_BRIDGES) {
        fprintf(stderr, "  BRIDGE: table full, '%s' unbridged\n", name);
        return 0;
    }
    bridges[num_bridges].iat_va = 0;
    bridges[num_bridges].name = name;
    bridges[num_bridges].handler = handler;
    return BRIDGE_BASE + num_bridges++;
}

/*
 * Bind bridges by NAME, from the image's own import table.
 *
 * The VA of every IAT slot used to be written out by hand next to each handler.
 * Thirty of the hundred and sixty-seven were wrong: the whole USER32 block had
 * slipped by one entry, so GetDC was serviced by the SetTimer bridge -- calling
 * the wrong API and, because the bridge cleans up its own argument count,
 * popping twelve bytes too many off the simulated stack. The frame damage
 * surfaced later as a NULL string argument in an unrelated function.
 *
 * The import directory is right there in the image we mapped, and the INT
 * (OriginalFirstThunk) still holds the names after we overwrite the IAT with
 * cookies, so look the slot up instead of asserting where it is. Anything
 * imported but unbridged, or bridged but not imported, now says so.
 */
/* MSS exports stdcall-decorated names (_AIL_startup@0); compare undecorated. */
static int same_import(const char *imported, const char *want) {
    if (*imported == '_') imported++;
    while (*want && *imported && *imported != '@') {
        if (*want++ != *imported++) return 0;
    }
    return *want == 0 && (*imported == 0 || *imported == '@');
}

static u32 find_iat_slot(const char *want) {
    u32 nt = GTA_IMAGE_BASE + MEM32(GTA_IMAGE_BASE + 0x3C);
    u32 imports = MEM32(nt + 0x80);            /* DataDirectory[1].VirtualAddress */
    u32 desc;

    if (!imports) return 0;
    for (desc = GTA_IMAGE_BASE + imports; MEM32(desc + 12); desc += 20) {
        u32 int_rva = MEM32(desc + 0);         /* OriginalFirstThunk */
        u32 iat_rva = MEM32(desc + 16);        /* FirstThunk         */
        u32 i;
        if (!int_rva) int_rva = iat_rva;       /* some linkers omit the INT */
        for (i = 0; ; i++) {
            u32 thunk = MEM32(GTA_IMAGE_BASE + int_rva + i * 4);
            if (!thunk) break;
            if (thunk & 0x80000000u) {         /* imported by ordinal */
                char buf[24];
                sprintf(buf, "ordinal_%u", thunk & 0xFFFFu);
                if (!strcmp(buf, want))
                    return GTA_IMAGE_BASE + iat_rva + i * 4;
            } else {
                const char *name = (const char *)(uintptr_t)
                                   ADDR(GTA_IMAGE_BASE + thunk + 2);
                if (same_import(name, want))
                    return GTA_IMAGE_BASE + iat_rva + i * 4;
            }
        }
    }
    return 0;
}

static int g_unbound;

static void register_bridge(const char *name, void (*handler)(void)) {
    u32 iat_va = find_iat_slot(name);
    u32 bridge_addr;
    if (!iat_va) {
        fprintf(stderr, "  BRIDGE: '%s' is not imported by this build\n", name);
        g_unbound++;
        return;
    }
    bridge_addr = recomp_alloc_bridge(name, handler);
    if (!bridge_addr) return;
    bridges[bridge_addr - BRIDGE_BASE].iat_va = iat_va;
    MEM32(iat_va) = bridge_addr;
}

/* Report any import we never bridged: it would dispatch to nothing at runtime. */
static void report_unbridged(void) {
    u32 nt = GTA_IMAGE_BASE + MEM32(GTA_IMAGE_BASE + 0x3C);
    u32 imports = MEM32(nt + 0x80);
    u32 desc, missing = 0;

    if (!imports) return;
    for (desc = GTA_IMAGE_BASE + imports; MEM32(desc + 12); desc += 20) {
        const char *dll = (const char *)(uintptr_t)ADDR(GTA_IMAGE_BASE + MEM32(desc + 12));
        u32 int_rva = MEM32(desc + 0), iat_rva = MEM32(desc + 16), i;
        if (!int_rva) int_rva = iat_rva;
        for (i = 0; ; i++) {
            u32 thunk = MEM32(GTA_IMAGE_BASE + int_rva + i * 4);
            u32 slot  = GTA_IMAGE_BASE + iat_rva + i * 4;
            if (!thunk) break;
            if (MEM32(slot) >= BRIDGE_BASE && MEM32(slot) < BRIDGE_BASE + (u32)num_bridges)
                continue;
            missing++;
            if (thunk & 0x80000000u)
                fprintf(stderr, "  BRIDGE: UNBRIDGED %s ordinal %u\n", dll, thunk & 0xFFFFu);
            else
                fprintf(stderr, "  BRIDGE: UNBRIDGED %s!%s\n", dll,
                        (const char *)(uintptr_t)ADDR(GTA_IMAGE_BASE + thunk + 2));
        }
    }
    fprintf(stderr, "  %d bridges bound, %u imports unbridged, %d names not imported\n",
            num_bridges, missing, g_unbound);
}

static int g_bridge_verbose = 1;

/*
 * Every bridge is a stdcall callee: it must pop the dummy return address plus
 * exactly its own arguments. A wrong count shifts the caller's frame, and that
 * surfaces much later as a garbage argument in an unrelated function -- a NULL
 * string, or the return-address marker turning up as a length. With
 * GTA_BRIDGE_ESP set, wrap each call and report what it actually moved esp by,
 * so a bad count is caught at the bridge rather than three frames downstream.
 */
static int g_check_esp = -1;
static u32 g_wrapped_idx, g_wrapped_esp;

static void bridge_esp_check(void) {
    u32 idx = g_wrapped_idx, before = g_wrapped_esp;
    bridges[idx].handler();
    fprintf(stderr, "    [esp] %-28s %+d\n", bridges[idx].name, (int)(esp - before));
}

recomp_func_t iat_bridge_lookup(u32 target_va) {
    if (target_va >= BRIDGE_BASE && target_va < BRIDGE_BASE + (u32)num_bridges) {
        u32 idx = target_va - BRIDGE_BASE;
        g_bridge_hit = idx;
        if (g_bridge_verbose) {
            fprintf(stderr, "  BRIDGE: %s (esp=0x%08X)\n", bridges[idx].name, esp);
        }
        if (g_check_esp < 0) {
            char buf[8];
            g_check_esp = GetEnvironmentVariableA("GTA_BRIDGE_ESP", buf, sizeof(buf)) ? 1 : 0;
        }
        if (g_check_esp) {
            g_wrapped_idx = idx;
            g_wrapped_esp = esp;
            return bridge_esp_check;
        }
        return bridges[idx].handler;
    }
    return NULL;
}

/*
 * Generic Win32 bridge: reads args from simulated stack, calls real API.
 * We use the actual function pointer loaded at runtime via GetProcAddress.
 *
 * Since all these are stdcall on Win32, after the call we clean up
 * the simulated stack (return addr + N args).
 */

#ifdef _WIN32

/* Helper: generic bridge for a real Win32 function */
/* We store the real function pointer and arg count with each bridge */
typedef struct {
    void *real_func;
    int num_args;
    const char *name;
} generic_bridge_info_t;

static generic_bridge_info_t g_generic_info[MAX_BRIDGES];
static int g_generic_count = 0;

static void generic_win32_bridge(void) {
    /* Find our bridge info by scanning the call trace */
    /* Actually, we need a way to know which bridge was called.
     * The ICALL trace has the bridge address. */

    /* HACK: use a thread-local to pass the bridge index */
    fprintf(stderr, "ERROR: generic_win32_bridge called without index\n");
}

/* Create a bridge that calls a real Win32 function with N args */
#define MAKE_BRIDGE(func_name, nargs) \
    static void bridge_##func_name(void) { \
        u32 a1=ARG(1),a2=ARG(2),a3=ARG(3),a4=ARG(4),a5=ARG(5),a6=ARG(6),a7=ARG(7); \
        (void)a1;(void)a2;(void)a3;(void)a4;(void)a5;(void)a6;(void)a7; \
        switch(nargs) { \
        case 0: eax = (u32)func_name(); break; \
        case 1: eax = (u32)func_name(a1); break; \
        case 2: eax = (u32)func_name(a1,a2); break; \
        case 3: eax = (u32)func_name(a1,a2,a3); break; \
        case 4: eax = (u32)func_name(a1,a2,a3,a4); break; \
        case 5: eax = (u32)func_name(a1,a2,a3,a4,a5); break; \
        case 6: eax = (u32)func_name(a1,a2,a3,a4,a5,a6); break; \
        case 7: eax = (u32)func_name(a1,a2,a3,a4,a5,a6,a7); break; \
        } \
        esp += 4 + nargs * 4; \
    }

/* For functions that take string pointers, we need to translate VAs */
#define VA2PTR(va) ((void *)(uintptr_t)ADDR(va))
#define VA2STR(va) ((const char *)(uintptr_t)ADDR(va))

/* ===== KERNEL32 bridges ===== */
static void bridge_GetVersion(void) { eax = (u32)GetVersion();  esp += 4; }
static void bridge_GetLastError(void) { eax = (u32)GetLastError(); fprintf(stderr, "    GetLastError -> %u (0x%X)\n", eax, eax);  esp += 4; }
static void bridge_SetLastError(void) { SetLastError(ARG(1)); esp += 4+4; }
static void bridge_GetTickCount(void) { eax = GetTickCount();  esp += 4; }
static void bridge_Sleep(void) { Sleep(ARG(1)); esp += 4+4; }
static void bridge_ExitProcess(void) {
    fprintf(stderr, "ExitProcess(0x%X)\n", ARG(1));
    recomp_dump_trace("ExitProcess");
    exit(ARG(1));
}
static void bridge_GetModuleHandleA(void) { eax = (u32)(uintptr_t)GetModuleHandleA(ARG(1) ? VA2STR(ARG(1)) : NULL); esp += 4+4; }
static void bridge_GetCommandLineA(void) {
    static u32 cl_va = 0;  /* scratch VA: 0x780000 was inside the game's .data */
    if (!cl_va) cl_va = recomp_scratch_str(GetCommandLineA());
    eax = cl_va;
    esp += 4;
}
static void bridge_GetStartupInfoA(void) { GetStartupInfoA((STARTUPINFOA*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_GetVersionExA(void) { eax = GetVersionExA((OSVERSIONINFOA*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_CreateMutexA(void) {
    const char *name = ARG(3) ? VA2STR(ARG(3)) : NULL;
    fprintf(stderr, "    CreateMutexA(sec=%u, own=%u, name='%s')\n", ARG(1), ARG(2), name?name:"(null)");
    eax = (u32)(uintptr_t)CreateMutexA(ARG(1)?VA2PTR(ARG(1)):NULL, ARG(2), name);
    fprintf(stderr, "    -> handle=0x%X, GetLastError=%lu\n", eax, GetLastError());
    esp += 4+12;
}
static void bridge_ReleaseMutex(void) { fprintf(stderr, "    ReleaseMutex(0x%X)\n", ARG(1)); eax = ReleaseMutex((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_LoadLibraryA(void) {
    const char *dll = VA2STR(ARG(1));
    eax = (u32)(uintptr_t)LoadLibraryA(dll);
    fprintf(stderr, "    LoadLibraryA('%s') -> 0x%X\n", dll, eax);
    esp += 4+4;
}
static void bridge_GetProcAddress(void) {
    const char *name = VA2STR(ARG(2));
    eax = ddraw_shim_getproc(name);   /* our DirectDraw, not the real one */
    if (!eax) eax = (u32)(uintptr_t)GetProcAddress((HMODULE)(uintptr_t)ARG(1), name);
    fprintf(stderr, "    GetProcAddress(0x%X, '%s') -> 0x%X\n", ARG(1), name, eax);
    esp += 4+8;
}
static void bridge_VirtualAlloc(void) { eax = (u32)(uintptr_t)VirtualAlloc((void*)(uintptr_t)ARG(1), ARG(2), ARG(3), ARG(4)); esp += 4+16; }
static void bridge_VirtualFree(void) { eax = VirtualFree((void*)(uintptr_t)ARG(1), ARG(2), ARG(3)); esp += 4+12; }
/*
 * Entering at WinMain skips the CRT startup, so the game's heap-handle global
 * is never assigned and it hands us whatever happened to be in .data. Any
 * handle we did not issue ourselves becomes the process heap -- we own every
 * Heap* bridge, so alloc and free stay paired.
 */
#define MAX_HEAPS 8
static HANDLE g_heaps[MAX_HEAPS];
static int    g_heap_count;

static HANDLE heap_of(u32 h) {
    HANDLE handle = (HANDLE)(uintptr_t)h;
    int i;
    for (i = 0; i < g_heap_count; i++)
        if (g_heaps[i] == handle) return handle;
    return GetProcessHeap();
}

static void bridge_HeapCreate(void) {
    HANDLE h = HeapCreate(ARG(1), ARG(2), ARG(3));
    if (h && g_heap_count < MAX_HEAPS) g_heaps[g_heap_count++] = h;
    eax = (u32)(uintptr_t)h;
    fprintf(stderr, "    HeapCreate(0x%X, %u, %u) -> 0x%X", ARG(1), ARG(2), ARG(3), eax);
    fputc(10, stderr);
    esp += 4+12;
}
static void bridge_HeapDestroy(void) { eax = HeapDestroy(heap_of(ARG(1))); esp += 4+4; }
static void bridge_HeapAlloc(void) {
    eax = (u32)(uintptr_t)HeapAlloc(heap_of(ARG(1)), ARG(2), ARG(3));
    fprintf(stderr, "    HeapAlloc(h=0x%X, flags=0x%X, %u bytes) -> 0x%X", ARG(1), ARG(2), ARG(3), eax);
    fputc(10, stderr);
    esp += 4+12;
}
static void bridge_HeapFree(void) { eax = HeapFree(heap_of(ARG(1)), ARG(2), (void*)(uintptr_t)ARG(3)); esp += 4+12; }
static void bridge_HeapReAlloc(void) { eax = (u32)(uintptr_t)HeapReAlloc(heap_of(ARG(1)), ARG(2), (void*)(uintptr_t)ARG(3), ARG(4)); esp += 4+16; }
/* GTA_FILE_TRACE names every file the game opens, and whether it got it.
 * Which data files a screen does and does not reach for says more about where
 * it stopped than any function trace. */
static int g_file_trace = -1;
static void bridge_CreateFileA(void) {
    const char *path = VA2STR(ARG(1));
    HANDLE h = CreateFileA(path, ARG(2), ARG(3), ARG(4)?VA2PTR(ARG(4)):NULL, ARG(5), ARG(6), (HANDLE)(uintptr_t)ARG(7));
    if (g_file_trace < 0) {
        char b[8];
        g_file_trace = GetEnvironmentVariableA("GTA_FILE_TRACE", b, sizeof(b)) ? 1 : 0;
    }
    if (g_file_trace)
        fprintf(stderr, "  FILE: %s%s\n", path, h == INVALID_HANDLE_VALUE ? "   <-- FAILED" : "");
    eax = (u32)(uintptr_t)h;
    esp += 4+28;
}
static void bridge_ReadFile(void) { eax = ReadFile((HANDLE)(uintptr_t)ARG(1), VA2PTR(ARG(2)), ARG(3), (LPDWORD)VA2PTR(ARG(4)), ARG(5)?VA2PTR(ARG(5)):NULL); esp += 4+20; }
static void bridge_WriteFile(void) { eax = WriteFile((HANDLE)(uintptr_t)ARG(1), VA2PTR(ARG(2)), ARG(3), (LPDWORD)VA2PTR(ARG(4)), ARG(5)?VA2PTR(ARG(5)):NULL); esp += 4+20; }
static void bridge_CloseHandle(void) { eax = CloseHandle((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetFilePointer(void) { eax = SetFilePointer((HANDLE)(uintptr_t)ARG(1), ARG(2), ARG(3)?VA2PTR(ARG(3)):NULL, ARG(4)); esp += 4+16; }
static void bridge_GetModuleFileNameA(void) { eax = GetModuleFileNameA((HMODULE)(uintptr_t)ARG(1), (char*)VA2PTR(ARG(2)), ARG(3)); esp += 4+12; }
static void bridge_FindFirstFileA(void) { eax = (u32)(uintptr_t)FindFirstFileA(VA2STR(ARG(1)), (WIN32_FIND_DATAA*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_FindNextFileA(void) { eax = FindNextFileA((HANDLE)(uintptr_t)ARG(1), (WIN32_FIND_DATAA*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_FindClose(void) { eax = FindClose((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_GetSystemDirectoryA(void) { eax = GetSystemDirectoryA((char*)VA2PTR(ARG(1)), ARG(2)); esp += 4+8; }
static void bridge_GetLocalTime(void) { GetLocalTime((SYSTEMTIME*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_GetCurrentProcess(void) { eax = (u32)(uintptr_t)GetCurrentProcess();  esp += 4; }
static void bridge_IsBadWritePtr(void) { eax = IsBadWritePtr(VA2PTR(ARG(1)), ARG(2)); esp += 4+8; }
static void bridge_IsBadReadPtr(void) { eax = IsBadReadPtr(VA2PTR(ARG(1)), ARG(2)); esp += 4+8; }
static void bridge_GetStdHandle(void) { eax = (u32)(uintptr_t)GetStdHandle(ARG(1)); esp += 4+4; }
static void bridge_TerminateProcess(void) { TerminateProcess((HANDLE)(uintptr_t)ARG(1), ARG(2)); esp += 4+8; }
static void bridge_GetEnvironmentVariableA(void) { eax = GetEnvironmentVariableA(VA2STR(ARG(1)), (char*)VA2PTR(ARG(2)), ARG(3)); esp += 4+12; }
static void bridge_SetEnvironmentVariableA(void) { eax = SetEnvironmentVariableA(VA2STR(ARG(1)), ARG(2)?VA2STR(ARG(2)):NULL); esp += 4+8; }
static void bridge_GetACP(void) { eax = GetACP();  esp += 4; }
static void bridge_GetOEMCP(void) { eax = GetOEMCP();  esp += 4; }
static void bridge_GetCPInfo(void) { eax = GetCPInfo(ARG(1), (CPINFO*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_MultiByteToWideChar(void) { eax = MultiByteToWideChar(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),(LPWSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp += 4+24; }
static void bridge_WideCharToMultiByte(void) { eax = WideCharToMultiByte(ARG(1),ARG(2),(LPCWSTR)VA2PTR(ARG(3)),(int)ARG(4),(LPSTR)VA2PTR(ARG(5)),(int)ARG(6),ARG(7)?VA2STR(ARG(7)):NULL,NULL); esp += 4+32; }
static void bridge_FlushFileBuffers(void) { eax = FlushFileBuffers((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetHandleCount(void) { eax = ARG(1); esp += 4+4; } /* noop on NT */
static void bridge_GetFileType(void) { eax = GetFileType((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetStdHandle(void) { eax = SetStdHandle(ARG(1),(HANDLE)(uintptr_t)ARG(2)); esp += 4+8; }
static void bridge_SetEndOfFile(void) { eax = SetEndOfFile((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetUnhandledExceptionFilter(void) { eax = (u32)(uintptr_t)SetUnhandledExceptionFilter(NULL); esp += 4+4; }
static void bridge_UnhandledExceptionFilter(void) { eax = EXCEPTION_EXECUTE_HANDLER; esp += 4+4; }
static void bridge_RtlUnwind(void) { /* stub - SEH unwinding, not supported */ esp += 4+16; }
static void bridge_LCMapStringA(void) { eax = LCMapStringA(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),(LPSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp += 4+24; }
static void bridge_LCMapStringW(void) { eax = LCMapStringW(ARG(1),ARG(2),(LPCWSTR)VA2PTR(ARG(3)),(int)ARG(4),(LPWSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp += 4+24; }
static void bridge_CompareStringA(void) { eax = CompareStringA(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),VA2STR(ARG(5)),(int)ARG(6)); esp += 4+24; }
static void bridge_CompareStringW(void) { eax = CompareStringW(ARG(1),ARG(2),(LPCWSTR)VA2PTR(ARG(3)),(int)ARG(4),(LPCWSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp += 4+24; }
static void bridge_GetStringTypeA(void) { eax = GetStringTypeA(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),(LPWORD)VA2PTR(ARG(5))); esp += 4+20; }
static void bridge_GetStringTypeW(void) { eax = GetStringTypeW(ARG(1),(LPCWSTR)VA2PTR(ARG(2)),(int)ARG(3),(LPWORD)VA2PTR(ARG(4))); esp += 4+16; }
static void bridge_FreeEnvironmentStringsA(void) { eax = 1; esp += 4+4; }
static void bridge_FreeEnvironmentStringsW(void) { eax = 1; esp += 4+4; }
/*
 * An empty environment block, not NULL: the CRT's _setenvp walks the returned
 * pointer looking for the double NUL that terminates it, so NULL is a null
 * dereference rather than "no variables". The game reads no environment
 * variables, so empty is enough.
 */
static u32 empty_environment(void) {
    static u32 va;
    if (!va) {
        va = recomp_scratch_alloc(4);
        MEM8(va) = 0;
        MEM8(va + 1) = 0;
    }
    return va;
}
static void bridge_GetEnvironmentStrings(void) { eax = empty_environment(); esp += 4; }
static void bridge_GetEnvironmentStringsW(void) { eax = empty_environment(); esp += 4; }
static void bridge_GetTimeZoneInformation(void) { eax = GetTimeZoneInformation((TIME_ZONE_INFORMATION*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_GetSystemTime(void) { GetSystemTime((SYSTEMTIME*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_GetSystemTimeAsFileTime(void) { GetSystemTimeAsFileTime((FILETIME*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_IsBadCodePtr(void) { eax = 0; esp += 4+4; } /* always valid */

/* ===== USER32 bridges ===== */
/*
 * The game reports its failures through a message box. Log the text -- it says
 * in words what a stack of addresses only implies -- and answer it ourselves
 * rather than calling the real API, which would block on a dialog nobody is
 * there to dismiss.
 */
static void bridge_MessageBoxA(void) {
    const char *text  = ARG(2) ? VA2STR(ARG(2)) : "";
    const char *title = ARG(3) ? VA2STR(ARG(3)) : "";
    fprintf(stderr, "*** MessageBox [%s] %s\n", title, text);
    eax = 1;  /* IDOK */
    esp += 4+16;
}
/*
 * Scripted key input.
 *
 * The game takes input as window messages -- PeekMessageA, TranslateMessage,
 * DispatchMessageA into its own WndProc -- so a real keypress on a focused
 * window already works. What does not work is an unattended run: the front end
 * waits for a key that nobody is there to press, which is indistinguishable
 * from being stuck.
 *
 *   GTA_KEYS=0x0D,0x28,0x0D   virtual-key codes, sent in order
 *   GTA_KEY_MS=2000           milliseconds between them (default 2000)
 *   GTA_KEY_DELAY_MS=3000     wait before the first one (default 3000)
 *
 * Posted rather than synthesised with SendInput so it lands in the game's own
 * queue whether or not the window has focus.
 */
/*
 * GTA_MISSION=N -- force the mission number the front end would have picked.
 *
 * sub_0044AB90 reads the mission number from 0x6B3E28. Zero means "none", and
 * it then copies a hardcoded "level001.cmp" into the level-name global instead
 * of parsing ..\gtadata\mission.ini, whose first record names nyc.cmp. The
 * front end is what sets that number, so until menu navigation is worked out
 * the number stays zero and the game asks for a file retail does not ship.
 *
 * This holds the global at N so whenever the game applies it, it applies a real
 * mission. It is a shortcut around the front end, not a fix for it: it says
 * nothing about whether the menu works, only whether everything downstream of
 * it does.
 */
/*
 * GTA_WATCH_MEM=0x5101d0,0x6b3e28 -- poll game globals and report every change.
 *
 * GTA_WATCH reports function entries, which is the wrong shape for a state
 * machine: the front end is one function (sub_00426A50) switching on
 * MEM32(0x5101D0), so what matters is the value, not the call. Polling from
 * outside costs nothing and needs no re-lift.
 */
#define MAX_WATCH_MEM 8
static u32 g_watch_va[MAX_WATCH_MEM];
static int g_watch_va_count;

static DWORD WINAPI watch_mem_thread(LPVOID arg) {
    u32 last[MAX_WATCH_MEM];
    int i, first = 1;
    (void)arg;
    for (;;) {
        for (i = 0; i < g_watch_va_count; i++) {
            u32 v = MEM32(g_watch_va[i]);
            if (first || v != last[i]) {
                fprintf(stderr, "  MEM 0x%08X = 0x%08X (%u)\n", g_watch_va[i], v, v);
                last[i] = v;
            }
        }
        first = 0;
        Sleep(8);
    }
}

static void start_watch_mem(void) {
    char spec[128], *p;
    static int started = 0;
    if (started || !GetEnvironmentVariableA("GTA_WATCH_MEM", spec, sizeof(spec))) return;
    for (p = strtok(spec, ","); p && g_watch_va_count < MAX_WATCH_MEM; p = strtok(NULL, ","))
        g_watch_va[g_watch_va_count++] = (u32)strtoul(p, NULL, 16);
    if (!g_watch_va_count) return;
    started = 1;
    CreateThread(NULL, 0, watch_mem_thread, NULL, 0, NULL);
}

#define MISSION_NUMBER_VA 0x6B3E28u

static DWORD WINAPI mission_thread(LPVOID arg) {
    u32 want = (u32)(uintptr_t)arg;
    int announced = 0;
    for (;;) {
        if (MEM32(MISSION_NUMBER_VA) != want) {
            MEM32(MISSION_NUMBER_VA) = want;
            if (!announced) {
                fprintf(stderr, "  MISSION: forcing mission %u\n", want);
                announced = 1;
            }
        }
        Sleep(20);
    }
}

static void start_mission_thread(void) {
    char buf[16];
    static int started = 0;
    u32 want;
    if (started || !GetEnvironmentVariableA("GTA_MISSION", buf, sizeof(buf))) return;
    want = (u32)strtoul(buf, NULL, 0);
    if (!want) return;
    started = 1;
    CreateThread(NULL, 0, mission_thread, (LPVOID)(uintptr_t)want, 0, NULL);
}

static HWND g_game_hwnd;

/*
 * A key may be written as STATE:VK, meaning "wait until the front-end state
 * global equals STATE, then send VK". Fixed delays cannot drive a menu: a key
 * lands in whichever state happens to be current when the timer fires, and one
 * slow load shifts every key after it. GTA_KEY_STATE names the global to watch
 * (default 0x5101D0, sub_00426A50's switch variable).
 */
static u32 g_key_state_va = 0x5101D0u;

/*
 * GTA_FORCE_STATE=16 writes the front-end state directly, once, after
 * GTA_FORCE_STATE_MS (default 20000). A diagnostic shortcut, not a fix: it
 * answers "does the rest of the chain work if this state is entered" without
 * first solving why the menu will not enter it.
 */
static DWORD WINAPI force_state_thread(LPVOID arg) {
    char buf[16];
    DWORD when = 20000;
    u32 want = (u32)(uintptr_t)arg;
    if (GetEnvironmentVariableA("GTA_FORCE_STATE_MS", buf, sizeof(buf)))
        when = (DWORD)strtoul(buf, NULL, 0);
    Sleep(when);
    fprintf(stderr, "  STATE: forcing front-end state %u (was %u)\n",
            want, MEM32(0x5101D0u));
    MEM32(0x5101D0u) = want;
    return 0;
}

static void start_force_state(void) {
    char buf[16];
    static int started = 0;
    if (started || !GetEnvironmentVariableA("GTA_FORCE_STATE", buf, sizeof(buf))) return;
    started = 1;
    CreateThread(NULL, 0, force_state_thread,
                 (LPVOID)(uintptr_t)strtoul(buf, NULL, 0), 0, NULL);
}


static void wait_for_state(u32 want) {
    int spins = 0;
    while (MEM32(g_key_state_va) != want && spins++ < 2000)
        Sleep(10);
    Sleep(120);          /* let the state's first frame run */
}

static DWORD WINAPI key_thread(LPVOID arg) {
    char spec[256], buf[32];
    DWORD gap = 2000, delay = 3000;
    char *p;
    (void)arg;

    if (!GetEnvironmentVariableA("GTA_KEYS", spec, sizeof(spec))) return 0;
    if (GetEnvironmentVariableA("GTA_KEY_MS", buf, sizeof(buf)))
        gap = (DWORD)strtoul(buf, NULL, 0);
    if (GetEnvironmentVariableA("GTA_KEY_DELAY_MS", buf, sizeof(buf)))
        delay = (DWORD)strtoul(buf, NULL, 0);

    if (GetEnvironmentVariableA("GTA_KEY_STATE", buf, sizeof(buf)))
        g_key_state_va = (u32)strtoul(buf, NULL, 16);

    Sleep(delay);
    for (p = strtok(spec, ","); p; p = strtok(NULL, ",")) {
        UINT vk;
        char *colon = strchr(p, ':');
        if (colon) {
            *colon = 0;
            wait_for_state((u32)strtoul(p, NULL, 0));
            p = colon + 1;
        }
        vk = (UINT)strtoul(p, NULL, 0);
        UINT sc = MapVirtualKeyA(vk, 0 /* MAPVK_VK_TO_VSC */);
        LPARAM down = (LPARAM)(1 | (sc << 16));
        LPARAM up   = down | 0xC0000000;
        if (!vk || !g_game_hwnd) continue;
        fprintf(stderr, "  KEYS: vk=0x%02X (state %u)\n", vk, MEM32(g_key_state_va));
        PostMessageA(g_game_hwnd, WM_KEYDOWN, vk, down);
        Sleep(40);
        PostMessageA(g_game_hwnd, WM_KEYUP, vk, up);
        Sleep(gap);
    }
    return 0;
}

static void start_key_thread(void) {
    char buf[8];
    static int started = 0;
    if (started || !GetEnvironmentVariableA("GTA_KEYS", buf, sizeof(buf))) return;
    started = 1;
    CreateThread(NULL, 0, key_thread, NULL, 0, NULL);
}

static void bridge_CreateWindowExA(void) {
    eax = (u32)(uintptr_t)CreateWindowExA(ARG(1), VA2STR(ARG(2)), VA2STR(ARG(3)), ARG(4), (int)ARG(5),(int)ARG(6),(int)ARG(7),(int)ARG(8), (HWND)(uintptr_t)ARG(9), (HMENU)(uintptr_t)MEM32(esp+40), (HINSTANCE)(uintptr_t)MEM32(esp+44), MEM32(esp+48)?VA2PTR(MEM32(esp+48)):NULL);
    g_game_hwnd = (HWND)(uintptr_t)eax;
    start_key_thread();
    start_mission_thread();
    start_watch_mem();
    start_force_state();
    esp += 4+48;
}
/* Imported by this build but previously unbridged -- the old hand-written VA
 * table had them mapped to other functions' slots. */
static void bridge_SetFocus(void) { eax = (u32)(uintptr_t)SetFocus((HWND)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetWindowLongA(void) { eax = (u32)SetWindowLongA((HWND)(uintptr_t)ARG(1), (int)ARG(2), (LONG)ARG(3)); esp += 4+12; }
static void bridge_PostMessageA(void) { eax = PostMessageA((HWND)(uintptr_t)ARG(1), ARG(2), ARG(3), ARG(4)); esp += 4+16; }
static void bridge_ShowCursor(void) { eax = (u32)ShowCursor((BOOL)ARG(1)); esp += 4+4; }
static void bridge_SetWindowPlacement(void) { eax = SetWindowPlacement((HWND)(uintptr_t)ARG(1), (const WINDOWPLACEMENT*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_DestroyWindow(void) { eax = DestroyWindow((HWND)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_ShowWindow(void) { eax = ShowWindow((HWND)(uintptr_t)ARG(1), (int)ARG(2)); esp += 4+8; }
static void bridge_UpdateWindow(void) { eax = UpdateWindow((HWND)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_DefWindowProcA(void) { eax = (u32)DefWindowProcA((HWND)(uintptr_t)ARG(1), ARG(2), ARG(3), ARG(4)); esp += 4+16; }
static void bridge_PeekMessageA(void) { eax = PeekMessageA((MSG*)VA2PTR(ARG(1)), (HWND)(uintptr_t)ARG(2), ARG(3), ARG(4), ARG(5)); esp += 4+20; }
static void bridge_TranslateMessage(void) { eax = TranslateMessage((MSG*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_DispatchMessageA(void) { eax = (u32)DispatchMessageA((MSG*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_PostQuitMessage(void) { PostQuitMessage((int)ARG(1)); esp += 4+4; }
static void bridge_GetAsyncKeyState(void) { eax = (u32)(u16)GetAsyncKeyState((int)ARG(1)); esp += 4+4; }
static void bridge_GetKeyState(void) { eax = (u32)(u16)GetKeyState((int)ARG(1)); esp += 4+4; }
/* ===== real -> lifted: window procedures =====
 *
 * RegisterClassA gets lpfnWndProc as an address in the ORIGINAL image. Handing
 * that to Windows means Windows executes the original 1997 machine code, whose
 * IAT slots we have overwritten with bridge cookies -- it dies on its first
 * import. Every callback the OS owns has to enter through a host thunk that
 * marshals onto the simulated stack and dispatches the lifted function.
 *
 * esp is saved and restored around the call: a window proc can run reentrantly
 * (SendMessage from inside a message handler), and a single global save slot
 * would hand the outer call the inner call's stack pointer.
 */
#define MAX_WNDPROCS 4
static u32 g_wndproc_va[MAX_WNDPROCS];
static int g_wndproc_count;

static LRESULT call_lifted_wndproc(int slot, HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    recomp_func_t fn = recomp_lookup(g_wndproc_va[slot]);
    u32 saved_esp = esp;
    u32 result;

    if (!fn) {
        fprintf(stderr, "  WNDPROC: 0x%08X not lifted, deferring to DefWindowProc\n",
                g_wndproc_va[slot]);
        return DefWindowProcA(hwnd, msg, wp, lp);
    }

    PUSH32(esp, (u32)lp);
    PUSH32(esp, (u32)wp);
    PUSH32(esp, (u32)msg);
    PUSH32(esp, (u32)(uintptr_t)hwnd);
    PUSH32(esp, RECOMP_RETADDR);
    fn();
    result = eax;
    esp = saved_esp;
    return (LRESULT)result;
}

#define WNDPROC_THUNK(n) \
    static LRESULT CALLBACK lifted_wndproc_##n(HWND h, UINT m, WPARAM w, LPARAM l) { \
        return call_lifted_wndproc(n, h, m, w, l); \
    }
WNDPROC_THUNK(0)
WNDPROC_THUNK(1)
WNDPROC_THUNK(2)
WNDPROC_THUNK(3)
static const WNDPROC g_wndproc_thunks[MAX_WNDPROCS] = {
    lifted_wndproc_0, lifted_wndproc_1, lifted_wndproc_2, lifted_wndproc_3
};

/* Swap the game's window proc for a thunk, reusing the slot if this VA is
 * already routed (classes get re-registered after a display mode change). */
static WNDPROC route_wndproc(u32 va) {
    for (int i = 0; i < g_wndproc_count; i++)
        if (g_wndproc_va[i] == va) return g_wndproc_thunks[i];
    fprintf(stderr, "  WNDPROC: routing 0x%08X through thunk %d\n", va, g_wndproc_count);
    if (g_wndproc_count >= MAX_WNDPROCS) {
        fprintf(stderr, "  WNDPROC: out of thunks, 0x%08X unrouted\n", va);
        return NULL;
    }
    g_wndproc_va[g_wndproc_count] = va;
    fprintf(stderr, "  WNDPROC: routed 0x%08X -> lifted (slot %d)\n", va, g_wndproc_count);
    return g_wndproc_thunks[g_wndproc_count++];
}

static void bridge_RegisterClassA(void) {
    WNDCLASSA *wc = (WNDCLASSA *)VA2PTR(ARG(1));
    WNDPROC original = wc->lpfnWndProc;
    WNDPROC thunk = route_wndproc((u32)(uintptr_t)original);
    if (thunk) wc->lpfnWndProc = thunk;
    eax = RegisterClassA(wc);
    wc->lpfnWndProc = original;  /* leave the game's struct as it found it */
    esp += 4+4;
}
static void bridge_SetTimer(void) { eax = (u32)(uintptr_t)SetTimer((HWND)(uintptr_t)ARG(1), ARG(2), ARG(3), (TIMERPROC)(uintptr_t)ARG(4)); esp += 4+16; }
static void bridge_KillTimer(void) { eax = KillTimer((HWND)(uintptr_t)ARG(1), ARG(2)); esp += 4+8; }
static void bridge_GetClientRect(void) { eax = GetClientRect((HWND)(uintptr_t)ARG(1), (RECT*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_GetDC(void) { eax = (u32)(uintptr_t)GetDC((HWND)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_ReleaseDC(void) { eax = ReleaseDC((HWND)(uintptr_t)ARG(1), (HDC)(uintptr_t)ARG(2)); esp += 4+8; }
static void bridge_SetCursor(void) { eax = (u32)(uintptr_t)SetCursor((HCURSOR)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_LoadCursorA(void) { eax = (u32)(uintptr_t)LoadCursorA((HINSTANCE)(uintptr_t)ARG(1), (LPCSTR)(uintptr_t)ARG(2)); esp += 4+8; }
static void bridge_LoadIconA(void) { eax = (u32)(uintptr_t)LoadIconA((HINSTANCE)(uintptr_t)ARG(1), (LPCSTR)(uintptr_t)ARG(2)); esp += 4+8; }
static void bridge_LoadStringA(void) { eax = LoadStringA((HINSTANCE)(uintptr_t)ARG(1), ARG(2), (LPSTR)VA2PTR(ARG(3)), (int)ARG(4)); esp += 4+16; }
static void bridge_EnableWindow(void) { eax = EnableWindow((HWND)(uintptr_t)ARG(1), (BOOL)ARG(2)); esp += 4+8; }
static void bridge_SetActiveWindow(void) { eax = (u32)(uintptr_t)SetActiveWindow((HWND)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetForegroundWindow(void) { eax = SetForegroundWindow((HWND)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_GetActiveWindow(void) { eax = (u32)(uintptr_t)GetActiveWindow();  esp += 4; }
static void bridge_GetWindowPlacement(void) { eax = GetWindowPlacement((HWND)(uintptr_t)ARG(1),(WINDOWPLACEMENT*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_SetWindowPos(void) { eax = SetWindowPos((HWND)(uintptr_t)ARG(1),(HWND)(uintptr_t)ARG(2),(int)ARG(3),(int)ARG(4),(int)ARG(5),(int)ARG(6),ARG(7)); esp += 4+28; }
static void bridge_GetCursorPos(void) { eax = GetCursorPos((POINT*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_SetCursorPos(void) { eax = SetCursorPos((int)ARG(1),(int)ARG(2)); esp += 4+8; }

/* ===== GDI32 bridges ===== */
static void bridge_GetDeviceCaps(void) { eax = GetDeviceCaps((HDC)(uintptr_t)ARG(1),(int)ARG(2)); esp += 4+8; }
static void bridge_CreateCompatibleDC(void) { eax = (u32)(uintptr_t)CreateCompatibleDC((HDC)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_DeleteDC(void) { eax = DeleteDC((HDC)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SelectObject(void) { eax = (u32)(uintptr_t)SelectObject((HDC)(uintptr_t)ARG(1),(HGDIOBJ)(uintptr_t)ARG(2)); esp += 4+8; }
static void bridge_DeleteObject(void) { eax = DeleteObject((HGDIOBJ)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_CreatePalette(void) { eax = (u32)(uintptr_t)CreatePalette((LOGPALETTE*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_SelectPalette(void) { eax = (u32)(uintptr_t)SelectPalette((HDC)(uintptr_t)ARG(1),(HPALETTE)(uintptr_t)ARG(2),(BOOL)ARG(3)); esp += 4+12; }
static void bridge_RealizePalette(void) { eax = RealizePalette((HDC)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_BitBlt(void) { eax = BitBlt((HDC)(uintptr_t)ARG(1),(int)ARG(2),(int)ARG(3),(int)ARG(4),(int)ARG(5),(HDC)(uintptr_t)ARG(6),(int)ARG(7),(int)MEM32(esp+32),(DWORD)MEM32(esp+36)); esp += 4+36; }
static void bridge_CreateCompatibleBitmap(void) { eax = (u32)(uintptr_t)CreateCompatibleBitmap((HDC)(uintptr_t)ARG(1),(int)ARG(2),(int)ARG(3)); esp += 4+12; }
static void bridge_GetStockObject(void) { eax = (u32)(uintptr_t)GetStockObject((int)ARG(1)); esp += 4+4; }
/*
 * These nine shared one stub that popped a single argument. Their real arities
 * run from 1 to 11 -- StretchBlt alone was leaving 40 bytes on the simulated
 * stack. They are all plain pass-throughs, and a stdcall callee has to clean up
 * exactly its own arguments, so there is no such thing as a generic stub here.
 */
static void bridge_SetSystemPaletteUse(void) { eax = SetSystemPaletteUse((HDC)(uintptr_t)ARG(1), ARG(2)); esp += 4+8; }
static void bridge_GetSystemPaletteUse(void) { eax = GetSystemPaletteUse((HDC)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_GetSystemPaletteEntries(void) { eax = GetSystemPaletteEntries((HDC)(uintptr_t)ARG(1), ARG(2), ARG(3), (PALETTEENTRY*)VA2PTR(ARG(4))); esp += 4+16; }
static void bridge_CreateDCA(void) { eax = (u32)(uintptr_t)CreateDCA(ARG(1)?VA2STR(ARG(1)):NULL, ARG(2)?VA2STR(ARG(2)):NULL, ARG(3)?VA2STR(ARG(3)):NULL, ARG(4)?(const DEVMODEA*)VA2PTR(ARG(4)):NULL); esp += 4+16; }
static void bridge_Escape(void) { eax = Escape((HDC)(uintptr_t)ARG(1), (int)ARG(2), (int)ARG(3), ARG(4)?VA2STR(ARG(4)):NULL, ARG(5)?VA2PTR(ARG(5)):NULL); esp += 4+20; }
static void bridge_GetDIBits(void) { eax = GetDIBits((HDC)(uintptr_t)ARG(1), (HBITMAP)(uintptr_t)ARG(2), ARG(3), ARG(4), ARG(5)?VA2PTR(ARG(5)):NULL, (BITMAPINFO*)VA2PTR(ARG(6)), ARG(7)); esp += 4+28; }
static void bridge_AnimatePalette(void) { eax = AnimatePalette((HPALETTE)(uintptr_t)ARG(1), ARG(2), ARG(3), (const PALETTEENTRY*)VA2PTR(ARG(4))); esp += 4+16; }
static void bridge_StretchBlt(void) {
    eax = StretchBlt((HDC)(uintptr_t)ARG(1), (int)ARG(2), (int)ARG(3), (int)ARG(4), (int)ARG(5),
                     (HDC)(uintptr_t)ARG(6), (int)ARG(7), (int)ARG(8), (int)ARG(9), (int)ARG(10),
                     (DWORD)ARG(11));
    esp += 4+44;
}
static void bridge_SetStretchBltMode(void) { eax = SetStretchBltMode((HDC)(uintptr_t)ARG(1), (int)ARG(2)); esp += 4+8; }

/* ===== ADVAPI32 bridges ===== */
/*
 * A registry of our own, for the two keys the game cannot start without:
 *
 *   HKLM\SOFTWARE\DMA Design\Grand Theft Auto            Language
 *   HKLM\SOFTWARE\DMA Design\Grand Theft Auto\Controls   Control 0 .. Control 9
 *
 * The installer and GTA Settings.exe write those; a failed lookup is fatal to
 * the game (FatalError -257 at line 426). Answering them here keeps the
 * recompilation self-contained: no administrator rights, and nothing written to
 * the host machine's registry. Anything else still goes to the real API.
 */
#define FAKE_HKEY_BASE 0xE9000000u
#define GTA_REG_ROOT     "SOFTWARE\\DMA Design\\Grand Theft Auto"
#define GTA_REG_CONTROLS "SOFTWARE\\DMA Design\\Grand Theft Auto\\Controls"

static const char *k_fake_keys[] = { GTA_REG_ROOT, GTA_REG_CONTROLS };
#define NUM_FAKE_KEYS ((int)(sizeof(k_fake_keys) / sizeof(k_fake_keys[0])))

/* Defaults the game will accept. Language 0 is English; the control bindings
 * are left at 0 -- GTA Settings.exe is what normally populates them, and the
 * game only requires the reads to succeed. */
static u32 g_reg_language;
static u32 g_reg_controls[10];

static int fake_key_index(u32 hkey) {
    u32 i = hkey - FAKE_HKEY_BASE;
    return (hkey >= FAKE_HKEY_BASE && i < (u32)NUM_FAKE_KEYS) ? (int)i : -1;
}

static void bridge_RegOpenKeyExA(void) {
    const char *sub = ARG(2) ? VA2STR(ARG(2)) : "";
    int i;
    for (i = 0; i < NUM_FAKE_KEYS; i++) {
        if (!_stricmp(sub, k_fake_keys[i])) {
            if (ARG(5)) MEM32(ARG(5)) = FAKE_HKEY_BASE + (u32)i;
            fprintf(stderr, "    RegOpenKeyExA('%s') -> synthetic\n", sub);
            eax = ERROR_SUCCESS;
            esp += 4+20;
            return;
        }
    }
    eax = RegOpenKeyExA((HKEY)(uintptr_t)ARG(1), sub, ARG(3), ARG(4), (PHKEY)VA2PTR(ARG(5)));
    esp += 4+20;
}

static void bridge_RegQueryValueExA(void) {
    int key = fake_key_index(ARG(1));
    if (key >= 0) {
        const char *name = ARG(2) ? VA2STR(ARG(2)) : "";
        u32 value = 0;
        if (key == 1 && !strncmp(name, "Control ", 8)) {
            int n = name[8] - '0';
            if (n >= 0 && n < 10) value = g_reg_controls[n];
        } else if (!_stricmp(name, "Language")) {
            value = g_reg_language;
        }
        if (ARG(4)) MEM32(ARG(4)) = REG_DWORD;
        if (ARG(5)) MEM32(ARG(5)) = value;
        if (ARG(6)) MEM32(ARG(6)) = 4;
        eax = ERROR_SUCCESS;
        esp += 4+24;
        return;
    }
    eax = RegQueryValueExA((HKEY)(uintptr_t)ARG(1), VA2STR(ARG(2)), NULL,
                           ARG(4)?VA2PTR(ARG(4)):NULL, ARG(5)?VA2PTR(ARG(5)):NULL,
                           ARG(6)?VA2PTR(ARG(6)):NULL);
    esp += 4+24;
}

static void bridge_RegSetValueExA(void) {
    int key = fake_key_index(ARG(1));
    if (key >= 0) {
        const char *name = ARG(2) ? VA2STR(ARG(2)) : "";
        u32 value = (ARG(5) && ARG(6) >= 4) ? MEM32(ARG(5)) : 0;
        if (key == 1 && !strncmp(name, "Control ", 8)) {
            int n = name[8] - '0';
            if (n >= 0 && n < 10) g_reg_controls[n] = value;
        } else if (!_stricmp(name, "Language")) {
            g_reg_language = value;
        }
        eax = ERROR_SUCCESS;
        esp += 4+24;
        return;
    }
    eax = RegSetValueExA((HKEY)(uintptr_t)ARG(1), VA2STR(ARG(2)), 0, ARG(4),
                         (const BYTE*)VA2PTR(ARG(5)), ARG(6));
    esp += 4+24;
}

static void bridge_RegCloseKey(void) {
    if (fake_key_index(ARG(1)) >= 0) { eax = ERROR_SUCCESS; esp += 4+4; return; }
    eax = RegCloseKey((HKEY)(uintptr_t)ARG(1));
    esp += 4+4;
}

/* ===== WINMM bridges ===== */
static void bridge_joyGetPosEx(void) { eax = joyGetPosEx(ARG(1),(JOYINFOEX*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_joyGetDevCapsA(void) { eax = joyGetDevCapsA(ARG(1),(JOYCAPSA*)VA2PTR(ARG(2)),ARG(3)); esp += 4+12; }

/* ===== MSS bridges ===== */
static void bridge_AIL_startup(void) { eax = AIL_startup(); esp += 4+0; }   /* @0 */
static void bridge_AIL_shutdown(void) { AIL_shutdown(); esp += 4+0; }   /* @0 */
static void bridge_AIL_ms_count(void) { eax = AIL_ms_count(); esp += 4+0; }   /* @0 */
static void bridge_AIL_set_digital_master_volume(void) { AIL_set_digital_master_volume((HDIGDRIVER)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_allocate_sample_handle(void) { eax=(u32)(uintptr_t)AIL_allocate_sample_handle((HDIGDRIVER)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_release_sample_handle(void) { AIL_release_sample_handle((HSAMPLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_init_sample(void) { AIL_init_sample((HSAMPLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_start_sample(void) { AIL_start_sample((HSAMPLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_end_sample(void) { AIL_end_sample((HSAMPLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_sample_status(void) { eax=AIL_sample_status((HSAMPLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_set_sample_volume(void) { AIL_set_sample_volume((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_set_sample_pan(void) { AIL_set_sample_pan((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_set_sample_playback_rate(void) { AIL_set_sample_playback_rate((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_set_sample_loop_count(void) { AIL_set_sample_loop_count((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_set_sample_address(void) { AIL_set_sample_address((HSAMPLE)(uintptr_t)ARG(1),VA2PTR(ARG(2)),ARG(3)); esp += 4+12; }
static void bridge_AIL_set_sample_type(void) { AIL_set_sample_type((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2),ARG(3)); esp += 4+12; }
static void bridge_AIL_open_stream(void) { eax=(u32)(uintptr_t)AIL_open_stream((HDIGDRIVER)(uintptr_t)ARG(1),VA2STR(ARG(2)),(s32)ARG(3)); esp += 4+12; }
static void bridge_AIL_close_stream(void) { AIL_close_stream((HSTREAM)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_start_stream(void) { AIL_start_stream((HSTREAM)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_pause_stream(void) { AIL_pause_stream((HSTREAM)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_stream_status(void) { eax=AIL_stream_status((HSTREAM)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_stream_position(void) { eax=AIL_stream_position((HSTREAM)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_set_stream_volume(void) { AIL_set_stream_volume((HSTREAM)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_set_stream_loop_count(void) { AIL_set_stream_loop_count((HSTREAM)(uintptr_t)ARG(1),(s32)ARG(2)); esp += 4+8; }
static void bridge_AIL_stream_info(void) { AIL_stream_info((HSTREAM)(uintptr_t)ARG(1),ARG(2)?VA2PTR(ARG(2)):NULL,ARG(3)?VA2PTR(ARG(3)):NULL,ARG(4)?VA2PTR(ARG(4)):NULL,ARG(5)?VA2PTR(ARG(5)):NULL); esp += 4+20; }
static void bridge_AIL_mem_alloc_lock(void) { void*p=AIL_mem_alloc_lock(ARG(1)); eax=p?(u32)((uintptr_t)p - g_mem_base):0; esp += 4+4; }
static void bridge_AIL_mem_free_lock(void) { AIL_mem_free_lock(VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_AIL_waveOutOpen(void) { eax=AIL_waveOutOpen(VA2PTR(ARG(1)),(void*)(uintptr_t)ARG(2),(s32)ARG(3),ARG(4)?VA2PTR(ARG(4)):NULL); esp += 4+16; }
static void bridge_AIL_waveOutClose(void) { esp += 4+4; }
static void bridge_AIL_digital_configuration(void) { eax=0; esp += 4+16; }
static void bridge_AIL_register_timer(void) { eax=(u32)(uintptr_t)AIL_register_timer(NULL); esp += 4+4; }
static void bridge_AIL_release_timer_handle(void) { AIL_release_timer_handle((HTIMER)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_set_timer_frequency(void) { esp += 4+8; }
static void bridge_AIL_start_timer(void) { AIL_start_timer((HTIMER)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_stop_timer(void) { AIL_stop_timer((HTIMER)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_AIL_set_preference(void) { esp += 4+8; }
static void bridge_AIL_set_stream_position(void) { esp += 4+8; }
static void bridge_AIL_service_stream(void) { esp += 4+8; }

/* ===== Smacker bridges ===== */
static void bridge_SmackOpen(void) { eax=(u32)(uintptr_t)SmackOpen(VA2STR(ARG(1)),ARG(2),ARG(3)); esp += 4+12; }
static void bridge_SmackClose(void) { SmackClose((HSMACK)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SmackDoFrame(void) { eax=SmackDoFrame((HSMACK)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SmackNextFrame(void) { eax=SmackNextFrame((HSMACK)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SmackWait(void) { eax=SmackWait((HSMACK)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SmackToBuffer(void) { esp += 4+28; }
/* ordinal 33 is SmackSoundUseMSS(1), not SmackSoundUseDirectSound. */
static void bridge_SmackSoundUseMSS(void) { esp += 4+4; }
/* ordinal 28 is SmackToBufferRect(2); ordinal 23 is the 7-arg SmackToBuffer. */
static void bridge_SmackToBufferRect(void) { eax=1; esp += 4+8; }

/* ===== DPLAYX bridges =====
 *
 * ordinal 1 = DirectPlayCreate(lpGUID, lplpDP, pUnk)
 * ordinal 2 = DirectPlayEnumerateA(callback, context)
 *
 * Enumerating is not optional, even for a single-player game. GTA1's front end
 * calls DirectPlayEnumerateA at state 0 and counts the service providers the
 * callback reports; the count gates everything downstream. With the old stub
 * returning E_FAIL and never calling back, the count stayed at zero, so state 0
 * never routed to state 15 or 16, so states 5 and 3 -- the two that promote the
 * audio mode -- were unreachable, and the play state span forever on a request
 * that could not succeed.
 *
 * So one provider is reported. The name and GUID are ours; the game copies the
 * GUID into its own list node and keeps the name pointer, so both have to live
 * in game-visible memory.
 */
static u32 call_lifted(u32 va, const u32 *args, int n) {
    recomp_func_t fn = recomp_lookup(va);
    u32 saved_esp = esp, result;
    int i;
    if (!fn) {
        fprintf(stderr, "  DPLAY: callback 0x%08X is not lifted\n", va);
        return 0;
    }
    for (i = n - 1; i >= 0; i--) PUSH32(esp, args[i]);
    PUSH32(esp, RECOMP_RETADDR);
    fn();
    result = eax;
    esp = saved_esp;
    return result;
}

static void bridge_dplay_create(void) { eax = 0x80004005u; esp += 4+12; }

static void bridge_dplay_enumerate(void) {
    u32 cb = ARG(1), ctx = ARG(2);
    static u32 guid_va, name_va;
    u32 args[5];

    if (!guid_va) {
        /* A GUID of our own. The game only stores and compares it. */
        static const unsigned char guid[16] = {
            0x36,0x3B,0x58,0x5A,0x3B,0xE1,0x11,0xD0,
            0x9C,0x0B,0x00,0xA0,0xC9,0x06,0x28,0x02
        };
        int i;
        guid_va = recomp_scratch_alloc(16);
        for (i = 0; i < 16; i++) MEM8(guid_va + i) = guid[i];
        name_va = recomp_scratch_str("Local Connection");
    }

    args[0] = guid_va;      /* lpguidSP        */
    args[1] = name_va;      /* lpSPName        */
    args[2] = 9;            /* dwMajorVersion  */
    args[3] = 0;            /* dwMinorVersion  */
    args[4] = ctx;          /* lpContext       */

    if (cb) {
        fprintf(stderr, "  DPLAY: enumerating 1 service provider\n");
        call_lifted(cb, args, 5);
    }
    eax = 0;                /* DP_OK */
    esp += 4+8;
}

#endif /* _WIN32 */

/* ===== Registration ===== */
void setup_iat_bridges(void) {
#ifdef _WIN32
    fprintf(stderr, "Setting up IAT bridges...\n");

    /* KERNEL32.dll (63 functions) */
    register_bridge("HeapReAlloc", bridge_HeapReAlloc);
    register_bridge("VirtualAlloc", bridge_VirtualAlloc);
    register_bridge("VirtualFree", bridge_VirtualFree);
    register_bridge("HeapCreate", bridge_HeapCreate);
    register_bridge("HeapDestroy", bridge_HeapDestroy);
    register_bridge("GetVersionExA", bridge_GetVersionExA);
    register_bridge("IsBadWritePtr", bridge_IsBadWritePtr);
    register_bridge("GetEnvironmentVariableA", bridge_GetEnvironmentVariableA);
    register_bridge("GetModuleFileNameA", bridge_GetModuleFileNameA);
    register_bridge("ReadFile", bridge_ReadFile);
    register_bridge("WriteFile", bridge_WriteFile);
    register_bridge("CloseHandle", bridge_CloseHandle);
    register_bridge("GetCommandLineA", bridge_GetCommandLineA);
    register_bridge("GetStartupInfoA", bridge_GetStartupInfoA);
    register_bridge("HeapAlloc", bridge_HeapAlloc);
    register_bridge("HeapFree", bridge_HeapFree);
    register_bridge("GetStdHandle", bridge_GetStdHandle);
    register_bridge("TerminateProcess", bridge_TerminateProcess);
    register_bridge("GetOEMCP", bridge_GetOEMCP);
    register_bridge("SetHandleCount", bridge_SetHandleCount);
    register_bridge("SetFilePointer", bridge_SetFilePointer);
    register_bridge("ReleaseMutex", bridge_ReleaseMutex);
    register_bridge("Sleep", bridge_Sleep);
    register_bridge("GetLastError", bridge_GetLastError);
    register_bridge("CreateMutexA", bridge_CreateMutexA);
    register_bridge("LoadLibraryA", bridge_LoadLibraryA);
    register_bridge("GetProcAddress", bridge_GetProcAddress);
    register_bridge("GetVersion", bridge_GetVersion);
    register_bridge("FindClose", bridge_FindClose);
    register_bridge("FindFirstFileA", bridge_FindFirstFileA);
    register_bridge("GetSystemDirectoryA", bridge_GetSystemDirectoryA);
    register_bridge("GetModuleHandleA", bridge_GetModuleHandleA);
    register_bridge("GetLocalTime", bridge_GetLocalTime);
    register_bridge("GetTimeZoneInformation", bridge_GetTimeZoneInformation);
    register_bridge("SetEnvironmentVariableA", bridge_SetEnvironmentVariableA);
    register_bridge("LCMapStringA", bridge_LCMapStringA);
    register_bridge("LCMapStringW", bridge_LCMapStringW);
    register_bridge("SetEndOfFile", bridge_SetEndOfFile);
    register_bridge("GetFileType", bridge_GetFileType);
    register_bridge("WideCharToMultiByte", bridge_WideCharToMultiByte);
    register_bridge("UnhandledExceptionFilter", bridge_UnhandledExceptionFilter);
    register_bridge("FreeEnvironmentStringsA", bridge_FreeEnvironmentStringsA);
    register_bridge("FreeEnvironmentStringsW", bridge_FreeEnvironmentStringsW);
    register_bridge("GetEnvironmentStrings", bridge_GetEnvironmentStrings);
    register_bridge("GetEnvironmentStringsW", bridge_GetEnvironmentStringsW);
    register_bridge("FlushFileBuffers", bridge_FlushFileBuffers);
    register_bridge("SetUnhandledExceptionFilter", bridge_SetUnhandledExceptionFilter);
    register_bridge("IsBadReadPtr", bridge_IsBadReadPtr);
    register_bridge("IsBadCodePtr", bridge_IsBadCodePtr);
    register_bridge("SetStdHandle", bridge_SetStdHandle);
    register_bridge("CreateFileA", bridge_CreateFileA);
    register_bridge("MultiByteToWideChar", bridge_MultiByteToWideChar);
    register_bridge("GetStringTypeA", bridge_GetStringTypeA);
    register_bridge("GetStringTypeW", bridge_GetStringTypeW);
    register_bridge("GetCPInfo", bridge_GetCPInfo);
    register_bridge("GetACP", bridge_GetACP);
    register_bridge("CompareStringA", bridge_CompareStringA);
    register_bridge("CompareStringW", bridge_CompareStringW);
    register_bridge("ExitProcess", bridge_ExitProcess);
    register_bridge("GetCurrentProcess", bridge_GetCurrentProcess);
    register_bridge("GetSystemTime", bridge_GetSystemTime);
    register_bridge("GetSystemTimeAsFileTime", bridge_GetSystemTimeAsFileTime);
    register_bridge("RtlUnwind", bridge_RtlUnwind);

    /* USER32.dll (29 functions) */
    register_bridge("LoadStringA", bridge_LoadStringA);
    register_bridge("MessageBoxA", bridge_MessageBoxA);
    register_bridge("DestroyWindow", bridge_DestroyWindow);
    register_bridge("SetFocus", bridge_SetFocus);
    register_bridge("SetWindowLongA", bridge_SetWindowLongA);
    register_bridge("PostMessageA", bridge_PostMessageA);
    register_bridge("ShowCursor", bridge_ShowCursor);
    register_bridge("SetWindowPlacement", bridge_SetWindowPlacement);
    register_bridge("EnableWindow", bridge_EnableWindow);
    register_bridge("SetActiveWindow", bridge_SetActiveWindow);
    register_bridge("SetForegroundWindow", bridge_SetForegroundWindow);
    register_bridge("SetCursor", bridge_SetCursor);
    register_bridge("LoadCursorA", bridge_LoadCursorA);
    register_bridge("LoadIconA", bridge_LoadIconA);
    register_bridge("RegisterClassA", bridge_RegisterClassA);
    register_bridge("CreateWindowExA", bridge_CreateWindowExA);
    register_bridge("ShowWindow", bridge_ShowWindow);
    register_bridge("UpdateWindow", bridge_UpdateWindow);
    register_bridge("GetClientRect", bridge_GetClientRect);
    register_bridge("GetDC", bridge_GetDC);
    register_bridge("ReleaseDC", bridge_ReleaseDC);
    register_bridge("GetAsyncKeyState", bridge_GetAsyncKeyState);
    register_bridge("GetKeyState", bridge_GetKeyState);
    register_bridge("SetTimer", bridge_SetTimer);
    register_bridge("KillTimer", bridge_KillTimer);
    register_bridge("PeekMessageA", bridge_PeekMessageA);
    register_bridge("TranslateMessage", bridge_TranslateMessage);
    register_bridge("DispatchMessageA", bridge_DispatchMessageA);
    register_bridge("PostQuitMessage", bridge_PostQuitMessage);
    register_bridge("DefWindowProcA", bridge_DefWindowProcA);
    register_bridge("GetActiveWindow", bridge_GetActiveWindow);
    register_bridge("GetWindowPlacement", bridge_GetWindowPlacement);
    register_bridge("SetWindowPos", bridge_SetWindowPos);
    register_bridge("GetCursorPos", bridge_GetCursorPos);
    register_bridge("SetCursorPos", bridge_SetCursorPos);

    /* GDI32.dll (20 functions) */
    register_bridge("GetDeviceCaps", bridge_GetDeviceCaps);
    register_bridge("CreateCompatibleDC", bridge_CreateCompatibleDC);
    register_bridge("DeleteDC", bridge_DeleteDC);
    register_bridge("SelectObject", bridge_SelectObject);
    register_bridge("DeleteObject", bridge_DeleteObject);
    register_bridge("CreatePalette", bridge_CreatePalette);
    register_bridge("SelectPalette", bridge_SelectPalette);
    register_bridge("RealizePalette", bridge_RealizePalette);
    register_bridge("BitBlt", bridge_BitBlt);
    register_bridge("CreateCompatibleBitmap", bridge_CreateCompatibleBitmap);
    register_bridge("GetStockObject", bridge_GetStockObject);
    register_bridge("SetSystemPaletteUse", bridge_SetSystemPaletteUse);
    register_bridge("GetSystemPaletteUse", bridge_GetSystemPaletteUse);
    register_bridge("GetSystemPaletteEntries", bridge_GetSystemPaletteEntries);
    register_bridge("CreateDCA", bridge_CreateDCA);
    register_bridge("Escape", bridge_Escape);
    register_bridge("GetDIBits", bridge_GetDIBits);
    register_bridge("AnimatePalette", bridge_AnimatePalette);
    register_bridge("StretchBlt", bridge_StretchBlt);
    register_bridge("SetStretchBltMode", bridge_SetStretchBltMode);

    /* ADVAPI32.dll (4 functions) */
    register_bridge("RegCloseKey", bridge_RegCloseKey);
    register_bridge("RegQueryValueExA", bridge_RegQueryValueExA);
    register_bridge("RegOpenKeyExA", bridge_RegOpenKeyExA);
    register_bridge("RegSetValueExA", bridge_RegSetValueExA);

    /* WINMM.dll (2 functions) */
    register_bridge("joyGetPosEx", bridge_joyGetPosEx);
    register_bridge("joyGetDevCapsA", bridge_joyGetDevCapsA);

    /* DPLAYX.dll (2 functions) */
    register_bridge("ordinal_1", bridge_dplay_create);
    register_bridge("ordinal_2", bridge_dplay_enumerate);

    /* mss32.dll (38 functions) */
    register_bridge("AIL_stream_position", bridge_AIL_stream_position);
    register_bridge("AIL_set_digital_master_volume", bridge_AIL_set_digital_master_volume);
    register_bridge("AIL_shutdown", bridge_AIL_shutdown);
    register_bridge("AIL_release_sample_handle", bridge_AIL_release_sample_handle);
    register_bridge("AIL_close_stream", bridge_AIL_close_stream);
    register_bridge("AIL_stream_info", bridge_AIL_stream_info);
    register_bridge("AIL_open_stream", bridge_AIL_open_stream);
    register_bridge("AIL_pause_stream", bridge_AIL_pause_stream);
    register_bridge("AIL_startup", bridge_AIL_startup);
    register_bridge("AIL_set_stream_loop_count", bridge_AIL_set_stream_loop_count);
    register_bridge("AIL_stop_timer", bridge_AIL_stop_timer);
    register_bridge("AIL_release_timer_handle", bridge_AIL_release_timer_handle);
    register_bridge("AIL_register_timer", bridge_AIL_register_timer);
    register_bridge("AIL_set_timer_frequency", bridge_AIL_set_timer_frequency);
    register_bridge("AIL_start_timer", bridge_AIL_start_timer);
    register_bridge("AIL_sample_status", bridge_AIL_sample_status);
    register_bridge("AIL_end_sample", bridge_AIL_end_sample);
    register_bridge("AIL_start_sample", bridge_AIL_start_sample);
    register_bridge("AIL_set_sample_address", bridge_AIL_set_sample_address);
    register_bridge("AIL_set_sample_pan", bridge_AIL_set_sample_pan);
    register_bridge("AIL_set_sample_playback_rate", bridge_AIL_set_sample_playback_rate);
    register_bridge("AIL_init_sample", bridge_AIL_init_sample);
    register_bridge("AIL_ms_count", bridge_AIL_ms_count);
    register_bridge("AIL_start_stream", bridge_AIL_start_stream);
    register_bridge("AIL_set_stream_position", bridge_AIL_set_stream_position);
    register_bridge("AIL_set_preference", bridge_AIL_set_preference);
    register_bridge("AIL_waveOutOpen", bridge_AIL_waveOutOpen);
    register_bridge("AIL_digital_configuration", bridge_AIL_digital_configuration);
    register_bridge("AIL_waveOutClose", bridge_AIL_waveOutClose);
    register_bridge("AIL_allocate_sample_handle", bridge_AIL_allocate_sample_handle);
    register_bridge("AIL_mem_free_lock", bridge_AIL_mem_free_lock);
    register_bridge("AIL_set_sample_type", bridge_AIL_set_sample_type);
    register_bridge("AIL_set_sample_volume", bridge_AIL_set_sample_volume);
    register_bridge("AIL_set_sample_loop_count", bridge_AIL_set_sample_loop_count);
    register_bridge("AIL_mem_alloc_lock", bridge_AIL_mem_alloc_lock);
    register_bridge("AIL_service_stream", bridge_AIL_service_stream);
    register_bridge("AIL_stream_status", bridge_AIL_stream_status);
    register_bridge("AIL_set_stream_volume", bridge_AIL_set_stream_volume);

    /* smackw32.dll (8 functions) */
    register_bridge("ordinal_21", bridge_SmackNextFrame);
    register_bridge("ordinal_19", bridge_SmackDoFrame);
    register_bridge("ordinal_33", bridge_SmackSoundUseMSS);
    register_bridge("ordinal_23", bridge_SmackToBuffer);
    register_bridge("ordinal_32", bridge_SmackWait);
    register_bridge("ordinal_18", bridge_SmackClose);
    register_bridge("ordinal_14", bridge_SmackOpen);
    register_bridge("ordinal_28", bridge_SmackToBufferRect);

    ddraw_shim_init();
    report_unbridged();
    fprintf(stderr, "  Registered %d IAT bridges (all 166 imports covered)\n", num_bridges);
#endif
}
