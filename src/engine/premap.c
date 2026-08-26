/*
 * Getting 0x400000 for the original image.
 *
 * The lifted code stores pointers into the original image, so the image has to
 * live at its original VA. Nothing in-process can claim that range: by the time
 * even a TLS callback runs, kernel32 has already mapped C_437.NLS / l_intl.nls
 * and the first CRT heap segments straight through 0x400000-0x800000.
 *
 * So the exe launches itself: the parent creates the child suspended -- at which
 * point only ntdll, the image and the main thread's stack exist -- reserves the
 * range in it with VirtualAllocEx, and resumes. The child's loader then maps NLS
 * and the heap somewhere else because our reservation is in the way. The child
 * commits the image straight into that reservation (see image_loader.c) rather
 * than releasing it first -- releasing leaves a hole the next malloc falls into.
 *
 * Keep the host stack small (see /STACK in CMakeLists): an 8 MB main-thread
 * stack gets placed at exactly 0x400000, before even the parent can intervene.
 */

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#pragma comment(lib, "psapi.lib")

#define PREMAP_BASE  0x00400000
#define PREMAP_MIN   0x00400000  /* floor; the real size comes from the image */
#define PREMAP_ENV   "GTA_RECOMP_CHILD"

/*
 * How much to reserve at 0x400000.
 *
 * This was a flat 4 MB, which fits GTA1's 3.57 MB image and not London's
 * 4.42 MB -- London reserved successfully, then failed to map, and the error
 * pointed at the host's link base, which was fine. Read the size the image
 * actually needs out of its section headers instead of guessing.
 */
static DWORD image_span(const char *path) {
    unsigned char hdr[0x400];
    DWORD got = 0, pe, nsec, opt, i, top = 0;
    HANDLE h = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                           OPEN_EXISTING, 0, NULL);
    if (h == INVALID_HANDLE_VALUE) return 0;
    ReadFile(h, hdr, sizeof(hdr), &got, NULL);
    CloseHandle(h);
    if (got < 0x200 || hdr[0] != 'M' || hdr[1] != 'Z') return 0;

    pe = *(DWORD *)(hdr + 0x3C);
    if (pe + 0x18 > got) return 0;
    nsec = *(WORD *)(hdr + pe + 0x06);
    opt  = *(WORD *)(hdr + pe + 0x14);          /* SizeOfOptionalHeader */
    for (i = 0; i < nsec; i++) {
        unsigned char *s = hdr + pe + 0x18 + opt + i * 40;
        DWORD vsize, rsize, va, end;
        if ((size_t)(s - hdr) + 40 > got) break;
        vsize = *(DWORD *)(s + 0x08);
        va    = *(DWORD *)(s + 0x0C);
        rsize = *(DWORD *)(s + 0x10);
        end   = va + (vsize > rsize ? vsize : rsize);
        if (end > top) top = end;
    }
    if (!top) return 0;
    return (top + 0xFFFFF) & ~0xFFFFFu;         /* round up to 1 MB */
}

static const char *type_name(DWORD t) {
    switch (t) {
    case MEM_IMAGE:   return "IMAGE";
    case MEM_MAPPED:  return "MAPPED";
    case MEM_PRIVATE: return "PRIVATE";
    default:          return "-";
    }
}

/* Walk the low address space so a failure says who took the range, and whether
 * it is an image, a file mapping, or private pages. */
static void report_low_memory(uintptr_t from, uintptr_t to) {
    MEMORY_BASIC_INFORMATION mbi;
    char name[MAX_PATH];
    uintptr_t va = from;
    while (va < to) {
        if (!VirtualQuery((void *)va, &mbi, sizeof(mbi))) break;
        if (mbi.State != MEM_FREE) {
            name[0] = 0;
            GetMappedFileNameA(GetCurrentProcess(), (void *)va, name, (DWORD)sizeof(name));
            fprintf(stderr, "    %p +%08zX  %-7s state=%lX prot=%lX  %s\n",
                    mbi.BaseAddress, mbi.RegionSize, type_name(mbi.Type),
                    mbi.State, mbi.Protect, name);
        }
        va = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
    }
}

int premap_is_child(void) {
    return GetEnvironmentVariableA(PREMAP_ENV, NULL, 0) != 0;
}

/* Parent half: spawn ourselves suspended, reserve the image range, resume.
 * Returns the child's exit code, or -1 if the child could not be started. */
int premap_relaunch(const char *game_exe) {
    char cmdline[MAX_PATH * 2];
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    DWORD code = (DWORD)-1;

    DWORD span = image_span(game_exe);

    lstrcpynA(cmdline, GetCommandLineA(), sizeof(cmdline));
    SetEnvironmentVariableA(PREMAP_ENV, "1");

    if (!CreateProcessA(NULL, cmdline, NULL, NULL, TRUE, CREATE_SUSPENDED,
                        NULL, NULL, &si, &pi)) {
        fprintf(stderr, "FATAL: could not relaunch self (%lu)\n", GetLastError());
        return -1;
    }

    if (!span) span = PREMAP_MIN;
    if (span < PREMAP_MIN) span = PREMAP_MIN;
    fprintf(stderr, "  premap: reserving 0x%08X bytes at 0x%08X\n", span, PREMAP_BASE);

    if (!VirtualAllocEx(pi.hProcess, (void *)(uintptr_t)PREMAP_BASE, span,
                        MEM_RESERVE, PAGE_NOACCESS)) {
        fprintf(stderr, "FATAL: could not reserve 0x%08X in the child (%lu)\n",
                PREMAP_BASE, GetLastError());
        TerminateProcess(pi.hProcess, 1);
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
        return -1;
    }

    ResumeThread(pi.hThread);
    WaitForSingleObject(pi.hProcess, INFINITE);
    GetExitCodeProcess(pi.hProcess, &code);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return (int)code;
}

/* Diagnostics for when the image range could not be claimed. */
void premap_report(void) {
    fprintf(stderr, "  premap: low memory looks like:\n");
    report_low_memory(0x00010000, 0x01000000);
}
#else
int  premap_is_child(void) { return 1; }
int  premap_relaunch(const char *game_exe) { (void)game_exe; return -1; }
void premap_report(void)   {}
#endif
