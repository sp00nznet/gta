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
#define PREMAP_SIZE  0x00400000  /* 0x400000..0x800000: .text/.rdata/.data/.rsrc */
#define PREMAP_ENV   "GTA_RECOMP_CHILD"

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
int premap_relaunch(void) {
    char cmdline[MAX_PATH * 2];
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    DWORD code = (DWORD)-1;

    lstrcpynA(cmdline, GetCommandLineA(), sizeof(cmdline));
    SetEnvironmentVariableA(PREMAP_ENV, "1");

    if (!CreateProcessA(NULL, cmdline, NULL, NULL, TRUE, CREATE_SUSPENDED,
                        NULL, NULL, &si, &pi)) {
        fprintf(stderr, "FATAL: could not relaunch self (%lu)\n", GetLastError());
        return -1;
    }

    if (!VirtualAllocEx(pi.hProcess, (void *)(uintptr_t)PREMAP_BASE, PREMAP_SIZE,
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
int  premap_relaunch(void) { return -1; }
void premap_report(void)   {}
#endif
