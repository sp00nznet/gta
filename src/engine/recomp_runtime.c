/*
 * Recompilation runtime for GTA static recompilation.
 *
 * Handles:
 *   - Memory mapping at original image base via VirtualAlloc
 *   - Global x86 register storage
 *   - Indirect call dispatch (binary search over dispatch table)
 *   - VEH crash handler with register dump
 *   - ICALL trace ring buffer for debugging
 */

#include "recomp_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

/* =====================================================
 * Global register storage
 * ===================================================== */
u32 eax, ebx, ecx, edx;
u32 esi, edi, ebp, esp;
u32 eflags;

f64 fpu_stack[8];
int fpu_top;

/* FPU stack for fp_push/fp_pop */
f64 fpu_st[8];
int fpu_sp;

/* Memory base pointer */
u8 *g_mem_base;

/* ICALL trace */
u32 icall_trace[ICALL_TRACE_SIZE];
int icall_trace_idx;

/* =====================================================
 * Memory mapping
 *
 * We VirtualAlloc at address 0 to get the full 32-bit
 * address space mapped. Then g_mem_base = 0 so all
 * original VAs work directly via MEM32(addr).
 *
 * The original GTA1 binary uses:
 *   .text:  0x00401000 - 0x004A63D9  (code)
 *   .rdata: 0x004A7000 - 0x004AAABA  (read-only data)
 *   .data:  0x004AB000 - 0x00790298  (read-write data)
 *   .rsrc:  0x00791000 - 0x007918B0  (resources)
 *   Stack:  somewhere below 0x00400000
 * ===================================================== */

#define STACK_SIZE       (8 * 1024 * 1024)  /* 8MB stack */
#define STACK_BASE_VA    0x00100000          /* Stack grows down from here */
#define DATA_START_VA    0x00400000          /* Image base */
#define DATA_END_VA      0x00800000          /* Past end of all sections */
#define HEAP_START_VA    0x00800000          /* Heap area */
#define HEAP_SIZE        (64 * 1024 * 1024)  /* 64MB heap */

static void *g_stack_alloc;
static void *g_image_alloc;
static void *g_heap_alloc;

static int map_memory(void) {
#ifdef _WIN32
    /* Map the image region (covers .text, .data, .rdata, .rsrc) */
    g_image_alloc = VirtualAlloc(
        (void *)(uintptr_t)DATA_START_VA,
        DATA_END_VA - DATA_START_VA,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE
    );
    if (!g_image_alloc) {
        /* Try MEM_RESERVE first to find conflicting allocation, then commit */
        fprintf(stderr, "WARNING: Cannot map at 0x%08X (error %lu), trying offset-based approach\n",
                DATA_START_VA, GetLastError());

        /* Allocate anywhere and use offset */
        g_image_alloc = VirtualAlloc(
            NULL,
            DATA_END_VA,  /* Allocate full range from 0 */
            MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE
        );
        if (!g_image_alloc) {
            fprintf(stderr, "FATAL: Failed to allocate %u MB for memory mapping (error %lu)\n",
                    DATA_END_VA / (1024*1024), GetLastError());
            return 0;
        }
        /* Set base so that g_mem_base + VA gives the right pointer */
        g_mem_base = (u8 *)g_image_alloc;
        fprintf(stderr, "  Using offset-based mapping at %p\n", g_image_alloc);
    }

    if (g_mem_base == NULL) {
        /* Direct mapping succeeded - need separate stack/heap allocations */
        g_mem_base = (u8 *)0;

        /* Map the stack region */
        g_stack_alloc = VirtualAlloc(
            (void *)(uintptr_t)(STACK_BASE_VA - STACK_SIZE),
            STACK_SIZE,
            MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE
        );
        if (!g_stack_alloc) {
            fprintf(stderr, "WARNING: Failed to map stack at fixed address, using offset in image alloc\n");
        }

        /* Map the heap region */
        g_heap_alloc = VirtualAlloc(
            (void *)(uintptr_t)HEAP_START_VA,
            HEAP_SIZE,
            MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE
        );
    }
    /* else: offset-based mode - stack/heap covered by the large alloc */

    fprintf(stderr, "Memory mapped:\n");
    fprintf(stderr, "  Image:  0x%08X - 0x%08X (%u KB)\n",
            DATA_START_VA, DATA_END_VA, (DATA_END_VA - DATA_START_VA) / 1024);
    fprintf(stderr, "  Stack:  0x%08X - 0x%08X (%u KB)\n",
            STACK_BASE_VA - STACK_SIZE, STACK_BASE_VA, STACK_SIZE / 1024);
    if (g_heap_alloc) {
        fprintf(stderr, "  Heap:   0x%08X - 0x%08X (%u MB)\n",
                HEAP_START_VA, HEAP_START_VA + HEAP_SIZE, HEAP_SIZE / (1024*1024));
    }

    return 1;
#else
    /* Non-Windows: use malloc and set g_mem_base as offset */
    g_mem_base = (u8 *)calloc(1, DATA_END_VA);
    if (!g_mem_base) {
        fprintf(stderr, "FATAL: Failed to allocate memory\n");
        return 0;
    }
    return 1;
#endif
}

/* =====================================================
 * Load original binary data into mapped memory
 * ===================================================== */
int load_original_data(const char *exe_path) {
    FILE *f = fopen(exe_path, "rb");
    if (!f) {
        fprintf(stderr, "WARNING: Could not open original exe: %s\n", exe_path);
        return 0;
    }

    /* Read PE headers to find section layout */
    u8 header[4096];
    size_t nread = fread(header, 1, sizeof(header), f);
    if (nread < 0x100) {
        fclose(f);
        return 0;
    }

    /* Parse PE header */
    u32 pe_offset = *(u32 *)(header + 0x3C);
    if (pe_offset + 0x18 > nread) { fclose(f); return 0; }

    u16 num_sections = *(u16 *)(header + pe_offset + 0x06);
    u16 opt_header_size = *(u16 *)(header + pe_offset + 0x14);
    u32 image_base = *(u32 *)(header + pe_offset + 0x34);

    u8 *section_table = header + pe_offset + 0x18 + opt_header_size;

    fprintf(stderr, "Loading %d sections from %s (image base 0x%08X)\n",
            num_sections, exe_path, image_base);

    for (int i = 0; i < num_sections && i < 16; i++) {
        u8 *sec = section_table + i * 40;
        char name[9] = {0};
        memcpy(name, sec, 8);
        u32 vsize = *(u32 *)(sec + 8);
        u32 va = *(u32 *)(sec + 12);
        u32 raw_size = *(u32 *)(sec + 16);
        u32 raw_offset = *(u32 *)(sec + 20);

        u32 target_va = image_base + va;
        u32 copy_size = (raw_size < vsize) ? raw_size : vsize;

        if (copy_size > 0 && target_va >= DATA_START_VA && target_va < DATA_END_VA) {
            fseek(f, raw_offset, SEEK_SET);
            size_t read = fread(g_mem_base + target_va, 1, copy_size, f);
            fprintf(stderr, "  %-8s VA 0x%08X  size 0x%06X  loaded %zu bytes\n",
                    name, target_va, vsize, read);
        }
    }

    fclose(f);
    return 1;
}

/* =====================================================
 * Indirect call dispatch
 *
 * Binary search over the sorted dispatch table.
 * Falls back to stderr logging for unresolved calls.
 * ===================================================== */
void recomp_icall(u32 target_va) {
    /* Check IAT bridges first */
    if (iat_bridge_try_dispatch(target_va)) {
        return;
    }

    /* Binary search the main dispatch table */
    int lo = 0, hi = (int)recomp_dispatch_count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        u32 addr = recomp_dispatch_table[mid].addr;
        if (addr == target_va) {
            recomp_dispatch_table[mid].func();
            return;
        } else if (addr < target_va) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    /* Unresolved -- log but don't crash */
    static int unresolved_count = 0;
    unresolved_count++;
    if (unresolved_count <= 20) {
        fprintf(stderr, "UNRESOLVED ICALL #%d: 0x%08X\n", unresolved_count, target_va);
    } else if (unresolved_count == 21) {
        fprintf(stderr, "  (suppressing further ICALL warnings)\n");
    }
    /* Return 0 in eax as a safe default */
    eax = 0;
}

/* =====================================================
 * VEH crash handler (Windows only)
 * ===================================================== */
#ifdef _WIN32
static LONG WINAPI crash_handler(EXCEPTION_POINTERS *ep) {
    DWORD code = ep->ExceptionRecord->ExceptionCode;
    void *addr = ep->ExceptionRecord->ExceptionAddress;

    fprintf(stderr, "\n=== CRASH ===\n");
    fprintf(stderr, "Exception 0x%08lX at 0x%p\n", code, addr);
    fprintf(stderr, "Registers:\n");
    fprintf(stderr, "  eax=0x%08X  ebx=0x%08X  ecx=0x%08X  edx=0x%08X\n",
            eax, ebx, ecx, edx);
    fprintf(stderr, "  esi=0x%08X  edi=0x%08X  ebp=0x%08X  esp=0x%08X\n",
            esi, edi, ebp, esp);
    fprintf(stderr, "Recent ICALL trace:\n");
    for (int i = 0; i < ICALL_TRACE_SIZE; i++) {
        int idx = (icall_trace_idx - ICALL_TRACE_SIZE + i + ICALL_TRACE_SIZE) % ICALL_TRACE_SIZE;
        if (icall_trace[idx] != 0) {
            fprintf(stderr, "  [%2d] 0x%08X\n", i, icall_trace[idx]);
        }
    }
    fprintf(stderr, "=============\n");
    fflush(stderr);

    return EXCEPTION_CONTINUE_SEARCH;
}
#endif

/* =====================================================
 * Initialization / Shutdown
 * ===================================================== */
int recomp_init(void) {
    fprintf(stderr, "GTA Static Recompilation Runtime\n");
    fprintf(stderr, "================================\n");

    /* Map memory */
    if (!map_memory()) {
        return 0;
    }

    /* Initialize stack pointer */
    esp = STACK_BASE_VA - 16;  /* Leave a little headroom */

    /* Clear registers */
    eax = ebx = ecx = edx = 0;
    esi = edi = ebp = 0;
    eflags = 0;
    fpu_top = 0;
    memset(fpu_stack, 0, sizeof(fpu_stack));

    /* Clear ICALL trace */
    memset(icall_trace, 0, sizeof(icall_trace));
    icall_trace_idx = 0;

    /* Install crash handler */
#ifdef _WIN32
    AddVectoredExceptionHandler(1, crash_handler);
#endif

    fprintf(stderr, "Runtime initialized. ESP = 0x%08X\n", esp);
    return 1;
}

void recomp_shutdown(void) {
#ifdef _WIN32
    if (g_heap_alloc)  VirtualFree(g_heap_alloc, 0, MEM_RELEASE);
    if (g_stack_alloc)  VirtualFree(g_stack_alloc, 0, MEM_RELEASE);
    if (g_image_alloc)  VirtualFree(g_image_alloc, 0, MEM_RELEASE);
#else
    free(g_mem_base);
#endif
    g_mem_base = NULL;
    fprintf(stderr, "Runtime shutdown.\n");
}
