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

#include "recomp_runtime.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#endif

#include "../sound/miles_shim.h"
#include "../video/smacker_shim.h"

/* ===== Bridge address allocation ===== */
#define BRIDGE_BASE 0xB0000000u
#define MAX_BRIDGES 256

typedef struct {
    u32 iat_va;
    const char *name;
    void (*handler)(void);
} bridge_entry_t;

static bridge_entry_t bridges[MAX_BRIDGES];
static int num_bridges = 0;

#define ARG(n) MEM32(esp + 4 * (n))

static void register_bridge(u32 iat_va, const char *name, void (*handler)(void)) {
    if (num_bridges >= MAX_BRIDGES) return;
    u32 bridge_addr = BRIDGE_BASE + num_bridges;
    bridges[num_bridges].iat_va = iat_va;
    bridges[num_bridges].name = name;
    bridges[num_bridges].handler = handler;
    MEM32(iat_va) = bridge_addr;
    num_bridges++;
}

int iat_bridge_try_dispatch(u32 target_va) {
    if (target_va >= BRIDGE_BASE && target_va < BRIDGE_BASE + (u32)num_bridges) {
        bridges[target_va - BRIDGE_BASE].handler();
        return 1;
    }
    return 0;
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
#define VA2PTR(va) ((void *)(g_mem_base + (u32)(va)))
#define VA2STR(va) ((const char *)(g_mem_base + (u32)(va)))

/* ===== KERNEL32 bridges ===== */
static void bridge_GetVersion(void) { eax = (u32)GetVersion(); esp += 4; }
static void bridge_GetLastError(void) { eax = (u32)GetLastError(); esp += 4; }
static void bridge_SetLastError(void) { SetLastError(ARG(1)); esp += 4 + 4; }
static void bridge_GetTickCount(void) { eax = GetTickCount(); esp += 4; }
static void bridge_Sleep(void) { Sleep(ARG(1)); esp += 4 + 4; }
static void bridge_ExitProcess(void) { fprintf(stderr, "ExitProcess(%u)\n", ARG(1)); exit(ARG(1)); }
static void bridge_GetModuleHandleA(void) { eax = (u32)(uintptr_t)GetModuleHandleA(ARG(1) ? VA2STR(ARG(1)) : NULL); esp += 4 + 4; }
static void bridge_GetCommandLineA(void) {
    static u32 cl_va = 0x780000;
    char *cl = GetCommandLineA();
    strncpy((char*)VA2PTR(cl_va), cl, 255);
    eax = cl_va;
    esp += 4;
}
static void bridge_GetStartupInfoA(void) { GetStartupInfoA((STARTUPINFOA*)VA2PTR(ARG(1))); esp += 4 + 4; }
static void bridge_GetVersionExA(void) { eax = GetVersionExA((OSVERSIONINFOA*)VA2PTR(ARG(1))); esp += 4 + 4; }
static void bridge_CreateMutexA(void) { eax = (u32)(uintptr_t)CreateMutexA(ARG(1)?VA2PTR(ARG(1)):NULL, ARG(2), ARG(3)?VA2STR(ARG(3)):NULL); esp += 4 + 12; }
static void bridge_ReleaseMutex(void) { eax = ReleaseMutex((HANDLE)(uintptr_t)ARG(1)); esp += 4 + 4; }
static void bridge_LoadLibraryA(void) { eax = (u32)(uintptr_t)LoadLibraryA(VA2STR(ARG(1))); esp += 4 + 4; }
static void bridge_GetProcAddress(void) { eax = (u32)(uintptr_t)GetProcAddress((HMODULE)(uintptr_t)ARG(1), VA2STR(ARG(2))); esp += 4 + 8; }
static void bridge_VirtualAlloc(void) { eax = (u32)(uintptr_t)VirtualAlloc((void*)(uintptr_t)ARG(1), ARG(2), ARG(3), ARG(4)); esp += 4 + 16; }
static void bridge_VirtualFree(void) { eax = VirtualFree((void*)(uintptr_t)ARG(1), ARG(2), ARG(3)); esp += 4 + 12; }
static void bridge_HeapCreate(void) { eax = (u32)(uintptr_t)HeapCreate(ARG(1), ARG(2), ARG(3)); esp += 4 + 12; }
static void bridge_HeapDestroy(void) { eax = HeapDestroy((HANDLE)(uintptr_t)ARG(1)); esp += 4 + 4; }
static void bridge_HeapAlloc(void) { eax = (u32)(uintptr_t)HeapAlloc((HANDLE)(uintptr_t)ARG(1), ARG(2), ARG(3)); esp += 4 + 12; }
static void bridge_HeapFree(void) { eax = HeapFree((HANDLE)(uintptr_t)ARG(1), ARG(2), (void*)(uintptr_t)ARG(3)); esp += 4 + 12; }
static void bridge_HeapReAlloc(void) { eax = (u32)(uintptr_t)HeapReAlloc((HANDLE)(uintptr_t)ARG(1), ARG(2), (void*)(uintptr_t)ARG(3), ARG(4)); esp += 4 + 16; }
static void bridge_CreateFileA(void) { eax = (u32)(uintptr_t)CreateFileA(VA2STR(ARG(1)), ARG(2), ARG(3), ARG(4)?VA2PTR(ARG(4)):NULL, ARG(5), ARG(6), (HANDLE)(uintptr_t)ARG(7)); esp += 4 + 28; }
static void bridge_ReadFile(void) { eax = ReadFile((HANDLE)(uintptr_t)ARG(1), VA2PTR(ARG(2)), ARG(3), (LPDWORD)VA2PTR(ARG(4)), ARG(5)?VA2PTR(ARG(5)):NULL); esp += 4 + 20; }
static void bridge_WriteFile(void) { eax = WriteFile((HANDLE)(uintptr_t)ARG(1), VA2PTR(ARG(2)), ARG(3), (LPDWORD)VA2PTR(ARG(4)), ARG(5)?VA2PTR(ARG(5)):NULL); esp += 4 + 20; }
static void bridge_CloseHandle(void) { eax = CloseHandle((HANDLE)(uintptr_t)ARG(1)); esp += 4 + 4; }
static void bridge_SetFilePointer(void) { eax = SetFilePointer((HANDLE)(uintptr_t)ARG(1), ARG(2), ARG(3)?VA2PTR(ARG(3)):NULL, ARG(4)); esp += 4 + 16; }
static void bridge_GetModuleFileNameA(void) { eax = GetModuleFileNameA((HMODULE)(uintptr_t)ARG(1), (char*)VA2PTR(ARG(2)), ARG(3)); esp += 4 + 12; }
static void bridge_FindFirstFileA(void) { eax = (u32)(uintptr_t)FindFirstFileA(VA2STR(ARG(1)), (WIN32_FIND_DATAA*)VA2PTR(ARG(2))); esp += 4 + 8; }
static void bridge_FindNextFileA(void) { eax = FindNextFileA((HANDLE)(uintptr_t)ARG(1), (WIN32_FIND_DATAA*)VA2PTR(ARG(2))); esp += 4 + 8; }
static void bridge_FindClose(void) { eax = FindClose((HANDLE)(uintptr_t)ARG(1)); esp += 4 + 4; }
static void bridge_GetSystemDirectoryA(void) { eax = GetSystemDirectoryA((char*)VA2PTR(ARG(1)), ARG(2)); esp += 4 + 8; }
static void bridge_GetLocalTime(void) { GetLocalTime((SYSTEMTIME*)VA2PTR(ARG(1))); esp += 4 + 4; }
static void bridge_GetCurrentProcess(void) { eax = (u32)(uintptr_t)GetCurrentProcess(); esp += 4; }
static void bridge_IsBadWritePtr(void) { eax = IsBadWritePtr(VA2PTR(ARG(1)), ARG(2)); esp += 4 + 8; }
static void bridge_IsBadReadPtr(void) { eax = IsBadReadPtr(VA2PTR(ARG(1)), ARG(2)); esp += 4 + 8; }
static void bridge_GetStdHandle(void) { eax = (u32)(uintptr_t)GetStdHandle(ARG(1)); esp += 4 + 4; }
static void bridge_TerminateProcess(void) { TerminateProcess((HANDLE)(uintptr_t)ARG(1), ARG(2)); esp += 4 + 8; }
static void bridge_GetEnvironmentVariableA(void) { eax = GetEnvironmentVariableA(VA2STR(ARG(1)), (char*)VA2PTR(ARG(2)), ARG(3)); esp += 4 + 12; }
static void bridge_SetEnvironmentVariableA(void) { eax = SetEnvironmentVariableA(VA2STR(ARG(1)), ARG(2)?VA2STR(ARG(2)):NULL); esp += 4 + 8; }
static void bridge_GetACP(void) { eax = GetACP(); esp += 4; }
static void bridge_GetOEMCP(void) { eax = GetOEMCP(); esp += 4; }
static void bridge_GetCPInfo(void) { eax = GetCPInfo(ARG(1), (CPINFO*)VA2PTR(ARG(2))); esp += 4 + 8; }
static void bridge_MultiByteToWideChar(void) { eax = MultiByteToWideChar(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),(LPWSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp+=4+24; }
static void bridge_WideCharToMultiByte(void) { eax = WideCharToMultiByte(ARG(1),ARG(2),(LPCWSTR)VA2PTR(ARG(3)),(int)ARG(4),(LPSTR)VA2PTR(ARG(5)),(int)ARG(6),ARG(7)?VA2STR(ARG(7)):NULL,NULL); esp+=4+32; }
static void bridge_FlushFileBuffers(void) { eax = FlushFileBuffers((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetHandleCount(void) { eax = ARG(1); esp += 4+4; } /* noop on NT */
static void bridge_GetFileType(void) { eax = GetFileType((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetStdHandle(void) { eax = SetStdHandle(ARG(1),(HANDLE)(uintptr_t)ARG(2)); esp += 4+8; }
static void bridge_SetEndOfFile(void) { eax = SetEndOfFile((HANDLE)(uintptr_t)ARG(1)); esp += 4+4; }
static void bridge_SetUnhandledExceptionFilter(void) { eax = (u32)(uintptr_t)SetUnhandledExceptionFilter(NULL); esp += 4+4; }
static void bridge_UnhandledExceptionFilter(void) { eax = EXCEPTION_EXECUTE_HANDLER; esp += 4+4; }
static void bridge_RtlUnwind(void) { /* stub - SEH unwinding, not supported */ esp += 4+16; }
static void bridge_LCMapStringA(void) { eax = LCMapStringA(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),(LPSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp+=4+24; }
static void bridge_LCMapStringW(void) { eax = LCMapStringW(ARG(1),ARG(2),(LPCWSTR)VA2PTR(ARG(3)),(int)ARG(4),(LPWSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp+=4+24; }
static void bridge_CompareStringA(void) { eax = CompareStringA(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),VA2STR(ARG(5)),(int)ARG(6)); esp+=4+24; }
static void bridge_CompareStringW(void) { eax = CompareStringW(ARG(1),ARG(2),(LPCWSTR)VA2PTR(ARG(3)),(int)ARG(4),(LPCWSTR)VA2PTR(ARG(5)),(int)ARG(6)); esp+=4+24; }
static void bridge_GetStringTypeA(void) { eax = GetStringTypeA(ARG(1),ARG(2),VA2STR(ARG(3)),(int)ARG(4),(LPWORD)VA2PTR(ARG(5))); esp+=4+20; }
static void bridge_GetStringTypeW(void) { eax = GetStringTypeW(ARG(1),(LPCWSTR)VA2PTR(ARG(2)),(int)ARG(3),(LPWORD)VA2PTR(ARG(4))); esp+=4+16; }
static void bridge_FreeEnvironmentStringsA(void) { eax = 1; esp += 4+4; }
static void bridge_FreeEnvironmentStringsW(void) { eax = 1; esp += 4+4; }
static void bridge_GetEnvironmentStrings(void) { eax = 0; esp += 4; }
static void bridge_GetEnvironmentStringsW(void) { eax = 0; esp += 4; }
static void bridge_GetTimeZoneInformation(void) { eax = GetTimeZoneInformation((TIME_ZONE_INFORMATION*)VA2PTR(ARG(1))); esp+=4+4; }
static void bridge_GetSystemTime(void) { GetSystemTime((SYSTEMTIME*)VA2PTR(ARG(1))); esp+=4+4; }
static void bridge_GetSystemTimeAsFileTime(void) { GetSystemTimeAsFileTime((FILETIME*)VA2PTR(ARG(1))); esp+=4+4; }
static void bridge_IsBadCodePtr(void) { eax = 0; esp += 4+4; } /* always valid */

/* ===== USER32 bridges ===== */
static void bridge_MessageBoxA(void) { eax = MessageBoxA((HWND)(uintptr_t)ARG(1), VA2STR(ARG(2)), VA2STR(ARG(3)), ARG(4)); esp += 4+16; }
static void bridge_CreateWindowExA(void) {
    eax = (u32)(uintptr_t)CreateWindowExA(ARG(1), VA2STR(ARG(2)), VA2STR(ARG(3)), ARG(4), (int)ARG(5),(int)ARG(6),(int)ARG(7),(int)ARG(8), (HWND)(uintptr_t)ARG(9), (HMENU)(uintptr_t)MEM32(esp+40), (HINSTANCE)(uintptr_t)MEM32(esp+44), MEM32(esp+48)?VA2PTR(MEM32(esp+48)):NULL);
    esp += 4+48;
}
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
static void bridge_RegisterClassA(void) { eax = RegisterClassA((WNDCLASSA*)VA2PTR(ARG(1))); esp += 4+4; }
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
static void bridge_GetActiveWindow(void) { eax = (u32)(uintptr_t)GetActiveWindow(); esp += 4; }
static void bridge_GetWindowPlacement(void) { eax = GetWindowPlacement((HWND)(uintptr_t)ARG(1),(WINDOWPLACEMENT*)VA2PTR(ARG(2))); esp += 4+8; }
static void bridge_SetWindowPos(void) { eax = SetWindowPos((HWND)(uintptr_t)ARG(1),(HWND)(uintptr_t)ARG(2),(int)ARG(3),(int)ARG(4),(int)ARG(5),(int)ARG(6),ARG(7)); esp += 4+28; }
static void bridge_GetCursorPos(void) { eax = GetCursorPos((POINT*)VA2PTR(ARG(1))); esp += 4+4; }
static void bridge_SetCursorPos(void) { eax = SetCursorPos((int)ARG(1),(int)ARG(2)); esp += 4+8; }

/* ===== GDI32 bridges ===== */
static void bridge_GetDeviceCaps(void) { eax = GetDeviceCaps((HDC)(uintptr_t)ARG(1),(int)ARG(2)); esp+=4+8; }
static void bridge_CreateCompatibleDC(void) { eax = (u32)(uintptr_t)CreateCompatibleDC((HDC)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_DeleteDC(void) { eax = DeleteDC((HDC)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_SelectObject(void) { eax = (u32)(uintptr_t)SelectObject((HDC)(uintptr_t)ARG(1),(HGDIOBJ)(uintptr_t)ARG(2)); esp+=4+8; }
static void bridge_DeleteObject(void) { eax = DeleteObject((HGDIOBJ)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_CreatePalette(void) { eax = (u32)(uintptr_t)CreatePalette((LOGPALETTE*)VA2PTR(ARG(1))); esp+=4+4; }
static void bridge_SelectPalette(void) { eax = (u32)(uintptr_t)SelectPalette((HDC)(uintptr_t)ARG(1),(HPALETTE)(uintptr_t)ARG(2),(BOOL)ARG(3)); esp+=4+12; }
static void bridge_RealizePalette(void) { eax = RealizePalette((HDC)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_BitBlt(void) { eax = BitBlt((HDC)(uintptr_t)ARG(1),(int)ARG(2),(int)ARG(3),(int)ARG(4),(int)ARG(5),(HDC)(uintptr_t)ARG(6),(int)ARG(7),(int)MEM32(esp+32),(DWORD)MEM32(esp+36)); esp+=4+36; }
static void bridge_CreateCompatibleBitmap(void) { eax = (u32)(uintptr_t)CreateCompatibleBitmap((HDC)(uintptr_t)ARG(1),(int)ARG(2),(int)ARG(3)); esp+=4+12; }
static void bridge_GetStockObject(void) { eax = (u32)(uintptr_t)GetStockObject((int)ARG(1)); esp+=4+4; }
/* Remaining GDI stubs */
static void bridge_gdi_stub(void) { eax = 0; esp += 4+4; }

/* ===== ADVAPI32 bridges ===== */
static void bridge_RegOpenKeyExA(void) { eax = RegOpenKeyExA((HKEY)(uintptr_t)ARG(1),VA2STR(ARG(2)),ARG(3),ARG(4),(PHKEY)VA2PTR(ARG(5))); esp+=4+20; }
static void bridge_RegQueryValueExA(void) { eax = RegQueryValueExA((HKEY)(uintptr_t)ARG(1),VA2STR(ARG(2)),NULL,ARG(4)?VA2PTR(ARG(4)):NULL,ARG(5)?VA2PTR(ARG(5)):NULL,ARG(6)?VA2PTR(ARG(6)):NULL); esp+=4+24; }
static void bridge_RegSetValueExA(void) { eax = RegSetValueExA((HKEY)(uintptr_t)ARG(1),VA2STR(ARG(2)),0,ARG(4),VA2PTR(ARG(5)),ARG(6)); esp+=4+24; }
static void bridge_RegCloseKey(void) { eax = RegCloseKey((HKEY)(uintptr_t)ARG(1)); esp+=4+4; }

/* ===== WINMM bridges ===== */
static void bridge_joyGetPosEx(void) { eax = joyGetPosEx(ARG(1),(JOYINFOEX*)VA2PTR(ARG(2))); esp+=4+8; }
static void bridge_joyGetDevCapsA(void) { eax = joyGetDevCapsA(ARG(1),(JOYCAPSA*)VA2PTR(ARG(2)),ARG(3)); esp+=4+12; }

/* ===== MSS bridges ===== */
static void bridge_AIL_startup(void) { eax = AIL_startup(); esp+=4; }
static void bridge_AIL_shutdown(void) { AIL_shutdown(); esp+=4; }
static void bridge_AIL_ms_count(void) { eax = AIL_ms_count(); esp+=4; }
static void bridge_AIL_set_digital_master_volume(void) { AIL_set_digital_master_volume((HDIGDRIVER)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_allocate_sample_handle(void) { eax=(u32)(uintptr_t)AIL_allocate_sample_handle((HDIGDRIVER)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_release_sample_handle(void) { AIL_release_sample_handle((HSAMPLE)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_init_sample(void) { AIL_init_sample((HSAMPLE)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_start_sample(void) { AIL_start_sample((HSAMPLE)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_end_sample(void) { AIL_end_sample((HSAMPLE)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_sample_status(void) { eax=AIL_sample_status((HSAMPLE)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_set_sample_volume(void) { AIL_set_sample_volume((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_set_sample_pan(void) { AIL_set_sample_pan((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_set_sample_playback_rate(void) { AIL_set_sample_playback_rate((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_set_sample_loop_count(void) { AIL_set_sample_loop_count((HSAMPLE)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_set_sample_address(void) { AIL_set_sample_address((HSAMPLE)(uintptr_t)ARG(1),VA2PTR(ARG(2)),ARG(3)); esp+=4+12; }
static void bridge_AIL_set_sample_type(void) { esp+=4+12; }
static void bridge_AIL_open_stream(void) { eax=(u32)(uintptr_t)AIL_open_stream((HDIGDRIVER)(uintptr_t)ARG(1),VA2STR(ARG(2)),(s32)ARG(3)); esp+=4+12; }
static void bridge_AIL_close_stream(void) { AIL_close_stream((HSTREAM)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_start_stream(void) { AIL_start_stream((HSTREAM)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_pause_stream(void) { AIL_pause_stream((HSTREAM)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_stream_status(void) { eax=AIL_stream_status((HSTREAM)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_stream_position(void) { eax=AIL_stream_position((HSTREAM)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_set_stream_volume(void) { AIL_set_stream_volume((HSTREAM)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_set_stream_loop_count(void) { AIL_set_stream_loop_count((HSTREAM)(uintptr_t)ARG(1),(s32)ARG(2)); esp+=4+8; }
static void bridge_AIL_stream_info(void) { AIL_stream_info((HSTREAM)(uintptr_t)ARG(1),ARG(2)?VA2PTR(ARG(2)):NULL,ARG(3)?VA2PTR(ARG(3)):NULL,ARG(4)?VA2PTR(ARG(4)):NULL,ARG(5)?VA2PTR(ARG(5)):NULL); esp+=4+20; }
static void bridge_AIL_mem_alloc_lock(void) { void*p=AIL_mem_alloc_lock(ARG(1)); eax=p?(u32)((u8*)p-g_mem_base):0; esp+=4+4; }
static void bridge_AIL_mem_free_lock(void) { AIL_mem_free_lock(VA2PTR(ARG(1))); esp+=4+4; }
static void bridge_AIL_waveOutOpen(void) { eax=AIL_waveOutOpen(VA2PTR(ARG(1)),(void*)(uintptr_t)ARG(2),(s32)ARG(3),ARG(4)?VA2PTR(ARG(4)):NULL); esp+=4+16; }
static void bridge_AIL_waveOutClose(void) { esp+=4+4; }
static void bridge_AIL_digital_configuration(void) { eax=0; esp+=4+16; }
static void bridge_AIL_register_timer(void) { eax=(u32)(uintptr_t)AIL_register_timer(NULL); esp+=4+4; }
static void bridge_AIL_release_timer_handle(void) { AIL_release_timer_handle((HTIMER)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_set_timer_frequency(void) { esp+=4+8; }
static void bridge_AIL_start_timer(void) { AIL_start_timer((HTIMER)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_stop_timer(void) { AIL_stop_timer((HTIMER)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_AIL_set_preference(void) { esp+=4+8; }
static void bridge_AIL_set_stream_position(void) { esp+=4+8; }
static void bridge_AIL_service_stream(void) { esp+=4+8; }

/* ===== Smacker bridges ===== */
static void bridge_SmackOpen(void) { eax=(u32)(uintptr_t)SmackOpen(VA2STR(ARG(1)),ARG(2),ARG(3)); esp+=4+12; }
static void bridge_SmackClose(void) { SmackClose((HSMACK)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_SmackDoFrame(void) { eax=SmackDoFrame((HSMACK)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_SmackNextFrame(void) { eax=SmackNextFrame((HSMACK)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_SmackWait(void) { eax=SmackWait((HSMACK)(uintptr_t)ARG(1)); esp+=4+4; }
static void bridge_SmackToBuffer(void) { esp+=4+28; }
static void bridge_SmackSoundUseDirectSound(void) { esp+=4+4; }
static void bridge_SmackBufferOpen(void) { eax=1; esp+=4+24; }

/* ===== DPLAYX bridges ===== */
static void bridge_dplay_stub1(void) { eax=0x80004005; esp+=4; }
static void bridge_dplay_stub2(void) { eax=0x80004005; esp+=4; }

#endif /* _WIN32 */

/* ===== Registration ===== */
void setup_iat_bridges(void) {
#ifdef _WIN32
    fprintf(stderr, "Setting up IAT bridges...\n");

    /* KERNEL32.dll (63 functions) */
    register_bridge(0x4A7074, "HeapReAlloc", bridge_HeapReAlloc);
    register_bridge(0x4A7078, "VirtualAlloc", bridge_VirtualAlloc);
    register_bridge(0x4A707C, "VirtualFree", bridge_VirtualFree);
    register_bridge(0x4A7080, "HeapCreate", bridge_HeapCreate);
    register_bridge(0x4A7084, "HeapDestroy", bridge_HeapDestroy);
    register_bridge(0x4A7088, "GetVersionExA", bridge_GetVersionExA);
    register_bridge(0x4A708C, "IsBadWritePtr", bridge_IsBadWritePtr);
    register_bridge(0x4A7090, "GetEnvironmentVariableA", bridge_GetEnvironmentVariableA);
    register_bridge(0x4A7094, "GetModuleFileNameA", bridge_GetModuleFileNameA);
    register_bridge(0x4A7098, "ReadFile", bridge_ReadFile);
    register_bridge(0x4A709C, "WriteFile", bridge_WriteFile);
    register_bridge(0x4A70A0, "CloseHandle", bridge_CloseHandle);
    register_bridge(0x4A70A4, "GetCommandLineA", bridge_GetCommandLineA);
    register_bridge(0x4A70A8, "GetStartupInfoA", bridge_GetStartupInfoA);
    register_bridge(0x4A70AC, "HeapAlloc", bridge_HeapAlloc);
    register_bridge(0x4A70B0, "HeapFree", bridge_HeapFree);
    register_bridge(0x4A70B4, "GetStdHandle", bridge_GetStdHandle);
    register_bridge(0x4A70B8, "TerminateProcess", bridge_TerminateProcess);
    register_bridge(0x4A70BC, "GetOEMCP", bridge_GetOEMCP);
    register_bridge(0x4A70C0, "SetHandleCount", bridge_SetHandleCount);
    register_bridge(0x4A70C4, "SetFilePointer", bridge_SetFilePointer);
    register_bridge(0x4A70C8, "ReleaseMutex", bridge_ReleaseMutex);
    register_bridge(0x4A70CC, "Sleep", bridge_Sleep);
    register_bridge(0x4A70D0, "GetLastError", bridge_GetLastError);
    register_bridge(0x4A70D4, "CreateMutexA", bridge_CreateMutexA);
    register_bridge(0x4A70D8, "LoadLibraryA", bridge_LoadLibraryA);
    register_bridge(0x4A70DC, "GetProcAddress", bridge_GetProcAddress);
    register_bridge(0x4A70E0, "GetVersion", bridge_GetVersion);
    register_bridge(0x4A70E4, "FindClose", bridge_FindClose);
    register_bridge(0x4A70E8, "FindFirstFileA", bridge_FindFirstFileA);
    register_bridge(0x4A70EC, "GetSystemDirectoryA", bridge_GetSystemDirectoryA);
    register_bridge(0x4A70F0, "GetModuleHandleA", bridge_GetModuleHandleA);
    register_bridge(0x4A70F4, "GetLocalTime", bridge_GetLocalTime);
    register_bridge(0x4A70F8, "GetTimeZoneInformation", bridge_GetTimeZoneInformation);
    register_bridge(0x4A70FC, "SetEnvironmentVariableA", bridge_SetEnvironmentVariableA);
    register_bridge(0x4A7100, "LCMapStringA", bridge_LCMapStringA);
    register_bridge(0x4A7104, "LCMapStringW", bridge_LCMapStringW);
    register_bridge(0x4A7108, "SetEndOfFile", bridge_SetEndOfFile);
    register_bridge(0x4A710C, "GetFileType", bridge_GetFileType);
    register_bridge(0x4A7110, "WideCharToMultiByte", bridge_WideCharToMultiByte);
    register_bridge(0x4A7114, "UnhandledExceptionFilter", bridge_UnhandledExceptionFilter);
    register_bridge(0x4A7118, "FreeEnvironmentStringsA", bridge_FreeEnvironmentStringsA);
    register_bridge(0x4A711C, "FreeEnvironmentStringsW", bridge_FreeEnvironmentStringsW);
    register_bridge(0x4A7120, "GetEnvironmentStrings", bridge_GetEnvironmentStrings);
    register_bridge(0x4A7124, "GetEnvironmentStringsW", bridge_GetEnvironmentStringsW);
    register_bridge(0x4A7128, "FlushFileBuffers", bridge_FlushFileBuffers);
    register_bridge(0x4A712C, "SetUnhandledExceptionFilter", bridge_SetUnhandledExceptionFilter);
    register_bridge(0x4A7130, "IsBadReadPtr", bridge_IsBadReadPtr);
    register_bridge(0x4A7134, "IsBadCodePtr", bridge_IsBadCodePtr);
    register_bridge(0x4A7138, "SetStdHandle", bridge_SetStdHandle);
    register_bridge(0x4A713C, "CreateFileA", bridge_CreateFileA);
    register_bridge(0x4A7140, "MultiByteToWideChar", bridge_MultiByteToWideChar);
    register_bridge(0x4A7144, "GetStringTypeA", bridge_GetStringTypeA);
    register_bridge(0x4A7148, "GetStringTypeW", bridge_GetStringTypeW);
    register_bridge(0x4A714C, "GetCPInfo", bridge_GetCPInfo);
    register_bridge(0x4A7150, "GetACP", bridge_GetACP);
    register_bridge(0x4A7154, "CompareStringA", bridge_CompareStringA);
    register_bridge(0x4A7158, "CompareStringW", bridge_CompareStringW);
    register_bridge(0x4A715C, "ExitProcess", bridge_ExitProcess);
    register_bridge(0x4A7160, "GetCurrentProcess", bridge_GetCurrentProcess);
    register_bridge(0x4A7164, "GetSystemTime", bridge_GetSystemTime);
    register_bridge(0x4A7168, "GetSystemTimeAsFileTime", bridge_GetSystemTimeAsFileTime);
    register_bridge(0x4A716C, "RtlUnwind", bridge_RtlUnwind);

    /* USER32.dll (29 functions) */
    register_bridge(0x4A7174, "LoadStringA", bridge_LoadStringA);
    register_bridge(0x4A7178, "MessageBoxA", bridge_MessageBoxA);
    register_bridge(0x4A717C, "DestroyWindow", bridge_DestroyWindow);
    register_bridge(0x4A7180, "EnableWindow", bridge_EnableWindow);
    register_bridge(0x4A7184, "SetActiveWindow", bridge_SetActiveWindow);
    register_bridge(0x4A7188, "SetForegroundWindow", bridge_SetForegroundWindow);
    register_bridge(0x4A718C, "SetCursor", bridge_SetCursor);
    register_bridge(0x4A7190, "LoadCursorA", bridge_LoadCursorA);
    register_bridge(0x4A7194, "LoadIconA", bridge_LoadIconA);
    register_bridge(0x4A7198, "RegisterClassA", bridge_RegisterClassA);
    register_bridge(0x4A719C, "CreateWindowExA", bridge_CreateWindowExA);
    register_bridge(0x4A71A0, "ShowWindow", bridge_ShowWindow);
    register_bridge(0x4A71A4, "UpdateWindow", bridge_UpdateWindow);
    register_bridge(0x4A71A8, "GetClientRect", bridge_GetClientRect);
    register_bridge(0x4A71AC, "GetDC", bridge_GetDC);
    register_bridge(0x4A71B0, "ReleaseDC", bridge_ReleaseDC);
    register_bridge(0x4A71B4, "GetAsyncKeyState", bridge_GetAsyncKeyState);
    register_bridge(0x4A71B8, "GetKeyState", bridge_GetKeyState);
    register_bridge(0x4A71BC, "SetTimer", bridge_SetTimer);
    register_bridge(0x4A71C0, "KillTimer", bridge_KillTimer);
    register_bridge(0x4A71C4, "PeekMessageA", bridge_PeekMessageA);
    register_bridge(0x4A71C8, "TranslateMessage", bridge_TranslateMessage);
    register_bridge(0x4A71CC, "DispatchMessageA", bridge_DispatchMessageA);
    register_bridge(0x4A71D0, "PostQuitMessage", bridge_PostQuitMessage);
    register_bridge(0x4A71D4, "DefWindowProcA", bridge_DefWindowProcA);
    register_bridge(0x4A71D8, "GetActiveWindow", bridge_GetActiveWindow);
    register_bridge(0x4A71DC, "GetWindowPlacement", bridge_GetWindowPlacement);
    register_bridge(0x4A71E0, "SetWindowPos", bridge_SetWindowPos);
    register_bridge(0x4A71E4, "GetCursorPos", bridge_GetCursorPos);
    register_bridge(0x4A71E8, "SetCursorPos", bridge_SetCursorPos);

    /* GDI32.dll (20 functions) */
    register_bridge(0x4A7024, "GetDeviceCaps", bridge_GetDeviceCaps);
    register_bridge(0x4A7038, "CreateCompatibleDC", bridge_CreateCompatibleDC);
    register_bridge(0x4A7034, "DeleteDC", bridge_DeleteDC);
    register_bridge(0x4A7030, "SelectObject", bridge_SelectObject);
    register_bridge(0x4A703C, "DeleteObject", bridge_DeleteObject);
    register_bridge(0x4A7040, "CreatePalette", bridge_CreatePalette);
    register_bridge(0x4A7028, "SelectPalette", bridge_SelectPalette);
    register_bridge(0x4A702C, "RealizePalette", bridge_RealizePalette);
    register_bridge(0x4A7060, "BitBlt", bridge_BitBlt);
    register_bridge(0x4A7058, "CreateCompatibleBitmap", bridge_CreateCompatibleBitmap);
    register_bridge(0x4A706C, "GetStockObject", bridge_GetStockObject);
    register_bridge(0x4A7020, "SetSystemPaletteUse", bridge_gdi_stub);
    register_bridge(0x4A7044, "GetSystemPaletteUse", bridge_gdi_stub);
    register_bridge(0x4A7048, "GetSystemPaletteEntries", bridge_gdi_stub);
    register_bridge(0x4A704C, "CreateDCA", bridge_gdi_stub);
    register_bridge(0x4A7050, "Escape", bridge_gdi_stub);
    register_bridge(0x4A7054, "GetDIBits", bridge_gdi_stub);
    register_bridge(0x4A705C, "AnimatePalette", bridge_gdi_stub);
    register_bridge(0x4A7064, "StretchBlt", bridge_gdi_stub);
    register_bridge(0x4A7068, "SetStretchBltMode", bridge_gdi_stub);

    /* ADVAPI32.dll (4 functions) */
    register_bridge(0x4A7000, "RegCloseKey", bridge_RegCloseKey);
    register_bridge(0x4A7004, "RegQueryValueExA", bridge_RegQueryValueExA);
    register_bridge(0x4A7008, "RegOpenKeyExA", bridge_RegOpenKeyExA);
    register_bridge(0x4A700C, "RegSetValueExA", bridge_RegSetValueExA);

    /* WINMM.dll (2 functions) */
    register_bridge(0x4A71EC, "joyGetPosEx", bridge_joyGetPosEx);
    register_bridge(0x4A71F0, "joyGetDevCapsA", bridge_joyGetDevCapsA);

    /* DPLAYX.dll (2 functions) */
    register_bridge(0x4A7014, "DirectPlayCreate", bridge_dplay_stub1);
    register_bridge(0x4A7018, "DirectPlayEnumerate", bridge_dplay_stub2);

    /* mss32.dll (38 functions) */
    register_bridge(0x4A71F8, "AIL_stream_position", bridge_AIL_stream_position);
    register_bridge(0x4A71FC, "AIL_set_digital_master_volume", bridge_AIL_set_digital_master_volume);
    register_bridge(0x4A7200, "AIL_shutdown", bridge_AIL_shutdown);
    register_bridge(0x4A7204, "AIL_release_sample_handle", bridge_AIL_release_sample_handle);
    register_bridge(0x4A7208, "AIL_close_stream", bridge_AIL_close_stream);
    register_bridge(0x4A720C, "AIL_stream_info", bridge_AIL_stream_info);
    register_bridge(0x4A7210, "AIL_open_stream", bridge_AIL_open_stream);
    register_bridge(0x4A7214, "AIL_pause_stream", bridge_AIL_pause_stream);
    register_bridge(0x4A7218, "AIL_startup", bridge_AIL_startup);
    register_bridge(0x4A721C, "AIL_set_stream_loop_count", bridge_AIL_set_stream_loop_count);
    register_bridge(0x4A7220, "AIL_stop_timer", bridge_AIL_stop_timer);
    register_bridge(0x4A7224, "AIL_release_timer_handle", bridge_AIL_release_timer_handle);
    register_bridge(0x4A7228, "AIL_register_timer", bridge_AIL_register_timer);
    register_bridge(0x4A722C, "AIL_set_timer_frequency", bridge_AIL_set_timer_frequency);
    register_bridge(0x4A7230, "AIL_start_timer", bridge_AIL_start_timer);
    register_bridge(0x4A7234, "AIL_sample_status", bridge_AIL_sample_status);
    register_bridge(0x4A7238, "AIL_end_sample", bridge_AIL_end_sample);
    register_bridge(0x4A723C, "AIL_start_sample", bridge_AIL_start_sample);
    register_bridge(0x4A7240, "AIL_set_sample_address", bridge_AIL_set_sample_address);
    register_bridge(0x4A7244, "AIL_set_sample_pan", bridge_AIL_set_sample_pan);
    register_bridge(0x4A7248, "AIL_set_sample_playback_rate", bridge_AIL_set_sample_playback_rate);
    register_bridge(0x4A724C, "AIL_init_sample", bridge_AIL_init_sample);
    register_bridge(0x4A7250, "AIL_ms_count", bridge_AIL_ms_count);
    register_bridge(0x4A7254, "AIL_start_stream", bridge_AIL_start_stream);
    register_bridge(0x4A7258, "AIL_set_stream_position", bridge_AIL_set_stream_position);
    register_bridge(0x4A725C, "AIL_set_preference", bridge_AIL_set_preference);
    register_bridge(0x4A7260, "AIL_waveOutOpen", bridge_AIL_waveOutOpen);
    register_bridge(0x4A7264, "AIL_digital_configuration", bridge_AIL_digital_configuration);
    register_bridge(0x4A7268, "AIL_waveOutClose", bridge_AIL_waveOutClose);
    register_bridge(0x4A726C, "AIL_allocate_sample_handle", bridge_AIL_allocate_sample_handle);
    register_bridge(0x4A7270, "AIL_mem_free_lock", bridge_AIL_mem_free_lock);
    register_bridge(0x4A7274, "AIL_set_sample_type", bridge_AIL_set_sample_type);
    register_bridge(0x4A7278, "AIL_set_sample_volume", bridge_AIL_set_sample_volume);
    register_bridge(0x4A727C, "AIL_set_sample_loop_count", bridge_AIL_set_sample_loop_count);
    register_bridge(0x4A7280, "AIL_mem_alloc_lock", bridge_AIL_mem_alloc_lock);
    register_bridge(0x4A7284, "AIL_service_stream", bridge_AIL_service_stream);
    register_bridge(0x4A7288, "AIL_stream_status", bridge_AIL_stream_status);
    register_bridge(0x4A728C, "AIL_set_stream_volume", bridge_AIL_set_stream_volume);

    /* smackw32.dll (8 functions) */
    register_bridge(0x4A7294, "SmackNextFrame", bridge_SmackNextFrame);
    register_bridge(0x4A7298, "SmackDoFrame", bridge_SmackDoFrame);
    register_bridge(0x4A729C, "SmackSoundUseDirectSound", bridge_SmackSoundUseDirectSound);
    register_bridge(0x4A72A0, "SmackToBuffer", bridge_SmackToBuffer);
    register_bridge(0x4A72A4, "SmackWait", bridge_SmackWait);
    register_bridge(0x4A72A8, "SmackClose", bridge_SmackClose);
    register_bridge(0x4A72AC, "SmackOpen", bridge_SmackOpen);
    register_bridge(0x4A72B0, "SmackBufferOpen", bridge_SmackBufferOpen);

    fprintf(stderr, "  Registered %d IAT bridges (all 166 imports covered)\n", num_bridges);
#endif
}
