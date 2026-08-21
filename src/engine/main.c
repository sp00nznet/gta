/*
 * GTA Static Recompilation -- entry point.
 *
 * Skips the MSVC CRT startup in the original binary and calls its WinMain
 * (0x00437230) directly.
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


extern void sub_00437230(void);  /* WinMain */

/* src/engine/premap.c -- how we get the image range at 0x400000 */
int  premap_is_child(void);
int  premap_relaunch(void);

static const char *g_exe_path = "game/extracted/WINO/Grand Theft Auto.exe";

int main(int argc, char *argv[]) {
    if (argc > 1) g_exe_path = argv[1];

    /* First invocation is the launcher: it reserves 0x400000 in a suspended
     * copy of us, because nothing running inside this process can get there. */
    if (!premap_is_child()) return premap_relaunch();

    /* Image first: it is the only mapping that must land at a fixed VA. */
    if (!load_original_data(g_exe_path)) return 1;
    if (!recomp_init()) return 1;
    setup_iat_bridges();  /* patches IAT slots in the just-loaded image */

    fprintf(stderr, "\n--- WinMain (sub_00437230) ---\n\n");

    {
        u32 cmdline_va = recomp_scratch_str(GetCommandLineA());
        PUSH32(esp, 10);                                            /* nShowCmd */
        PUSH32(esp, cmdline_va);                                    /* lpCmdLine */
        PUSH32(esp, 0);                                             /* hPrevInstance */
        PUSH32(esp, (u32)(uintptr_t)GetModuleHandleA(NULL));        /* hInstance */
        PUSH32(esp, RECOMP_RETADDR);                                /* return address */
        sub_00437230();
    }

    fprintf(stderr, "\n--- WinMain returned (eax=%u) ---\n", eax);
    recomp_dump_trace("exit");
    recomp_shutdown();
    return 0;
}
