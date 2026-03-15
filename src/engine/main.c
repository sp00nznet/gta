/*
 * GTA Static Recompilation -- Main Entry Point
 *
 * Initializes the recompilation runtime, loads original binary data,
 * and calls the recompiled entry point.
 */

#include "recomp_runtime.h"
#include <stdio.h>
#include <string.h>

/* The recompiled entry point function (original: 0x0049DC30) */
extern void sub_0049DC30(void);

/* Path to original game data */
static const char *g_exe_path = "game/WINO/Grand Theft Auto.exe";
static const char *g_data_dir = "game/GTADATA";

int main(int argc, char *argv[]) {
    /* Allow overriding exe path from command line */
    if (argc > 1) {
        g_exe_path = argv[1];
    }

    /* Initialize runtime (memory mapping, registers, crash handler) */
    if (!recomp_init()) {
        fprintf(stderr, "FATAL: Runtime initialization failed\n");
        return 1;
    }

    /* Load original binary's data sections into mapped memory */
    fprintf(stderr, "Loading original binary data from: %s\n", g_exe_path);
    if (!load_original_data(g_exe_path)) {
        fprintf(stderr, "WARNING: Could not load original binary data.\n");
        fprintf(stderr, "  The game may not function correctly without original .data/.rdata sections.\n");
        fprintf(stderr, "  Continuing anyway...\n");
    }

    fprintf(stderr, "\n--- Entering recompiled code at 0x0049DC30 ---\n\n");

    /* Call the recompiled WinMain/entry point */
    sub_0049DC30();

    fprintf(stderr, "\n--- Recompiled code returned ---\n");

    recomp_shutdown();
    return 0;
}
