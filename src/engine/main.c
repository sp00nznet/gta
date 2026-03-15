/*
 * GTA Static Recompilation -- Main Entry Point
 *
 * Skips MSVC CRT startup and calls WinMain (0x00437230) directly.
 */

#include "recomp_runtime.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

/* The recompiled WinMain (original: 0x00437230) */
extern void sub_00437230(void);

/* Path to original game data */
static const char *g_exe_path = "game/WINO/Grand Theft Auto.exe";

int main(int argc, char *argv[]) {
    if (argc > 1) {
        g_exe_path = argv[1];
    }

    /* Initialize runtime */
    if (!recomp_init()) {
        fprintf(stderr, "FATAL: Runtime initialization failed\n");
        return 1;
    }

    /* Load original binary's data sections */
    fprintf(stderr, "Loading original binary data from: %s\n", g_exe_path);
    load_original_data(g_exe_path);

    /* Set up IAT bridges (Win32 APIs, MSS, Smacker) */
    setup_iat_bridges();

    /* Also populate IAT slots not covered by bridges with stubs */
    /* (Remaining KERNEL32/USER32/GDI32/etc. that bridges don't cover
     * will need to be added as we discover which ones are called) */

    fprintf(stderr, "\n--- Calling WinMain (sub_00437230) ---\n\n");

#ifdef _WIN32
    {
        HMODULE hInst = GetModuleHandleA(NULL);
        char *cmdLine = GetCommandLineA();

        /* Store command line string in mapped memory */
        u32 cmdline_va = 0x00780000;
        strncpy((char *)(g_mem_base + cmdline_va), cmdLine, 255);

        /* Push WinMain args onto simulated stack */
        PUSH32(esp, 10);                     /* nShowCmd = SW_SHOWDEFAULT */
        PUSH32(esp, cmdline_va);             /* lpCmdLine */
        PUSH32(esp, 0);                      /* hPrevInstance = NULL */
        PUSH32(esp, (u32)(uintptr_t)hInst);  /* hInstance */
        PUSH32(esp, 0xDEADBEEF);             /* fake return address */

        sub_00437230();
    }
#endif

    fprintf(stderr, "\n--- WinMain returned (eax=%u) ---\n", eax);
    recomp_shutdown();
    return 0;
}
