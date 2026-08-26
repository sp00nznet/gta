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


#ifndef GTA_IMAGE_BASE
#define GTA_IMAGE_BASE 0x00400000u
#endif

/* The PE entry point, read from the header of the image we just mapped.
 *
 * This used to be `extern void sub_0049DC30(void)`, which is GTA1's CRT
 * startup and nothing else's -- London links against the same engine and its
 * entry is somewhere else entirely, so the hardcoded symbol simply failed to
 * resolve. The header is mapped along with the sections, so the right answer is
 * already in memory.
 */
static recomp_func_t resolve_entry(uint32_t base, uint32_t *out_va) {
    uint32_t pe = base + MEM32(base + 0x3C);          /* e_lfanew        */
    uint32_t rva = MEM32(pe + 0x28);                  /* AddressOfEntry  */
    *out_va = base + rva;
    return recomp_lookup(*out_va);
}

/* src/engine/premap.c -- how we get the image range at 0x400000 */
int  premap_is_child(void);
int  premap_relaunch(const char *game_exe);

static const char *g_exe_path = "game/extracted/WINO/Grand Theft Auto.exe";

int main(int argc, char *argv[]) {
    if (argc > 1) g_exe_path = argv[1];

    /* First invocation is the launcher: it reserves 0x400000 in a suspended
     * copy of us, because nothing running inside this process can get there. */
    if (!premap_is_child()) return premap_relaunch(g_exe_path);

    /* Image first: it is the only mapping that must land at a fixed VA. */
    if (!load_original_data(g_exe_path)) return 1;
    if (!recomp_init()) return 1;
    setup_iat_bridges();  /* patches IAT slots in the just-loaded image */

    {
        uint32_t entry_va = 0;
        recomp_func_t entry = resolve_entry(GTA_IMAGE_BASE, &entry_va);
        if (!entry) {
            fprintf(stderr, "entry point 0x%08X was not lifted\n", entry_va);
            return 1;
        }
        fprintf(stderr, "\n--- entry point (0x%08X) ---\n\n", entry_va);
        PUSH32(esp, RECOMP_RETADDR);   /* CRT startup takes no arguments */
        entry();
    }

    recomp_dump_trace("exit");
    recomp_shutdown();
    return 0;
}
