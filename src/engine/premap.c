/*
 * Pre-map memory at 0x400000 before CRT initializes.
 *
 * Uses a TLS callback which runs before main(). This ensures
 * the original GTA image base range is available for our
 * memory-mapped recompilation.
 */

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#define PREMAP_BASE  0x00010000
#define PREMAP_SIZE  0x00800000  /* 8MB: covers 0x10000 to 0x810000 */

static void *g_premap = NULL;

static void NTAPI premap_callback(PVOID DllHandle, DWORD Reason, PVOID Reserved) {
    if (Reason == DLL_PROCESS_ATTACH && g_premap == NULL) {
        /* Reserve the range before CRT heap can grab it */
        g_premap = VirtualAlloc(
            (void *)(uintptr_t)PREMAP_BASE,
            PREMAP_SIZE,
            MEM_RESERVE,
            PAGE_NOACCESS
        );
        /* We'll commit the parts we need later in recomp_init */
    }
}

/* Register TLS callback - this runs before CRT/main */
#pragma section(".CRT$XLB", read)
__declspec(allocate(".CRT$XLB"))
PIMAGE_TLS_CALLBACK p_premap_callback = premap_callback;

/* Accessor for the premap pointer */
void *get_premap_alloc(void) { return g_premap; }

#endif
