/*
 * Recompilation runtime for GTA static recompilation.
 *
 * Memory model (Fury3 layout -- fixed-base, no offset fallback):
 *
 *   0x00100000  TIB      simulated TEB, 1 page (fs: base)
 *   0x00200000  stack    1 MB, grows down from 0x00300000
 *   0x00390000  scratch  64 KB for host strings handed to the game
 *   0x00400000  image    the original .text/.rdata/.data at their real VAs
 *
 * Offset-based mapping is deliberately NOT supported: it works for data reads
 * and silently breaks every pointer the game stores. If 0x400000 cannot be had,
 * that is a link-base problem in this host exe, not something to work around.
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
#include "image_loader.h"
#include "hybrid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ===== global register model (contract: recomp_types.h) ===== */
uint32_t g_eax, g_ecx, g_edx, g_esp;
uint32_t g_ebx, g_esi, g_edi;
double   g_st[8];
int      g_fp_top;
uint16_t g_fpu_cw = 0x037F;
uint16_t g_seg_cs, g_seg_ds, g_seg_es, g_seg_fs, g_seg_gs, g_seg_ss;

ptrdiff_t g_mem_base = 0;      /* fixed-base mapping: VA == host address */
uint32_t  g_fs_base  = 0;
uint32_t  g_gs_base  = 0;

uint32_t g_icall_trace[ICALL_TRACE_SIZE];
uint32_t g_icall_trace_idx;
uint32_t g_icall_count;
uint32_t g_cur_func;

#ifdef RECOMP_TRACE
uint32_t g_enter_trace[RECOMP_ENTER_SIZE];
uint32_t g_enter_idx;
void recomp_trace_enter(uint32_t va) {
    g_enter_trace[g_enter_idx & (RECOMP_ENTER_SIZE - 1)] = va;
    g_enter_idx++;
}
#endif

/* ===== memory layout ===== */
#define GTA_IMAGE_BASE   0x00400000u
#define GTA_TIB_SIZE     0x00001000u
#define GTA_STACK_SIZE   0x00100000u
/* Objects, vtables and the DirectDraw surfaces the shim hands the game all
 * live here, so it needs room for a few 640x480 buffers. */
#define GTA_SCRATCH_SIZE 0x00400000u

static void *g_tib_view, *g_stack_view, *g_scratch_view;
static uint32_t g_stack_base, g_scratch_base, g_scratch_next;

/* Bump-allocate scratch VA space for strings the host hands to the game
 * (command line, module path). Never inside the image: that would overwrite
 * .data the game is still using. */
uint32_t recomp_scratch_alloc(uint32_t n) {
    uint32_t va = g_scratch_next;
    n = (n + 15u) & ~15u;
    if (va + n > g_scratch_base + GTA_SCRATCH_SIZE) {
        fprintf(stderr, "[scratch] exhausted\n");
        return 0;
    }
    g_scratch_next = va + n;
    return va;
}

uint32_t recomp_scratch_str(const char *s) {
    uint32_t n = (uint32_t)strlen(s) + 1;
    uint32_t va = recomp_scratch_alloc(n);
    if (va) memcpy((void *)(uintptr_t)ADDR(va), s, n);
    return va;
}

/* ===== dispatch ===== */
recomp_func_t recomp_lookup(uint32_t va) {
    int lo = 0, hi = (int)recomp_dispatch_count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        uint32_t a = recomp_dispatch_table[mid].address;
        if (a == va) return recomp_dispatch_table[mid].func;
        if (a < va) lo = mid + 1; else hi = mid - 1;
    }
    return NULL;
}

/* ===== lifted -> real =====
 *
 * GTA loads ddraw.dll itself and calls DirectDrawCreate through the pointer
 * GetProcAddress hands back, then dispatches every IDirectDraw method through
 * a COM vtable. Those targets are real host code, so dispatch has to be able to
 * leave the lifted world and come back.
 *
 * hybrid_call_machine runs the real function with esp pointing at the SIMULATED
 * stack, so a stdcall callee pops its own arguments and we never need to know
 * how many there were -- which is the only reason this works for COM, where
 * every vtable slot has a different arity.
 */
static uint32_t g_image_span;

static int is_host_code(uint32_t va) {
    MEMORY_BASIC_INFORMATION mbi;
    if (va >= GTA_IMAGE_BASE && va < GTA_IMAGE_BASE + g_image_span)
        return 0;                      /* the game's own image: lifted, not real */
    if (!VirtualQuery((void *)(uintptr_t)va, &mbi, sizeof(mbi)))
        return 0;
    return mbi.State == MEM_COMMIT
        && mbi.Type  == MEM_IMAGE
        && (mbi.Protect & (PAGE_EXECUTE | PAGE_EXECUTE_READ |
                           PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
}

/* Read at thunk entry, before the real code can nest another dispatch. */
static uint32_t g_pending_host_target;
static int g_host_call_verbose = 1;

static void host_call_thunk(void) {
    hybrid_regs r;
    uint32_t target = g_pending_host_target;

    r.eax = g_eax; r.ecx = g_ecx; r.edx = g_edx; r.ebx = g_ebx;
    r.esp = g_esp; r.esi = g_esi; r.edi = g_edi;
    r.ebp = 0;     /* lifted ebp is per-function; real callees here don't use ours */

    hybrid_call_machine(&r, target);

    if (g_host_call_verbose)
        fprintf(stderr, "  HOSTCALL: 0x%08X from 0x%08X -> eax=0x%08X\n",
                target, g_cur_func, r.eax);

    g_eax = r.eax; g_ecx = r.ecx; g_edx = r.edx; g_ebx = r.ebx;
    g_esp = r.esp; g_esi = r.esi; g_edi = r.edi;
}

recomp_func_t recomp_lookup_manual(uint32_t va) {
    if (is_host_code(va)) {
        g_pending_host_target = va;
        return host_call_thunk;
    }
    return NULL;
}

recomp_func_t recomp_lookup_import(uint32_t va) { return iat_bridge_lookup(va); }

void recomp_dump_trace(const char *why) {
    fprintf(stderr, "--- trace (%s): cur_func=0x%08X, %u icalls ---\n",
            why ? why : "?", g_cur_func, g_icall_count);
    for (uint32_t i = 0; i < ICALL_TRACE_SIZE; i++) {
        uint32_t idx = (g_icall_trace_idx - ICALL_TRACE_SIZE + i) & (ICALL_TRACE_SIZE - 1);
        if (g_icall_trace[idx]) fprintf(stderr, "  [%2u] 0x%08X\n", i, g_icall_trace[idx]);
    }
#ifdef RECOMP_TRACE
    fprintf(stderr, "--- last %d functions entered ---\n", RECOMP_ENTER_SIZE);
    for (uint32_t i = 0; i < RECOMP_ENTER_SIZE; i++) {
        uint32_t idx = (g_enter_idx - RECOMP_ENTER_SIZE + i) & (RECOMP_ENTER_SIZE - 1);
        if (g_enter_trace[idx]) fprintf(stderr, "  0x%08X\n", g_enter_trace[idx]);
    }
#endif
    fflush(stderr);
}

/* ===== crash handler ===== */
#ifdef _WIN32
static LONG WINAPI crash_handler(EXCEPTION_POINTERS *ep) {
    fprintf(stderr, "\n=== CRASH: exception 0x%08lX at %p ===\n",
            ep->ExceptionRecord->ExceptionCode, ep->ExceptionRecord->ExceptionAddress);
    fprintf(stderr, "  eax=%08X ecx=%08X edx=%08X ebx=%08X\n", g_eax, g_ecx, g_edx, g_ebx);
    fprintf(stderr, "  esi=%08X edi=%08X esp=%08X\n", g_esi, g_edi, g_esp);
    recomp_dump_trace("VEH");
    return EXCEPTION_CONTINUE_SEARCH;
}
#endif

/* ===== init / shutdown ===== */
int recomp_init(void) {
    fprintf(stderr, "GTA Static Recompilation Runtime\n");

#ifdef _WIN32
    g_tib_view = VirtualAlloc(NULL, GTA_TIB_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!g_tib_view) { fprintf(stderr, "FATAL: TIB alloc failed (%lu)\n", GetLastError()); return 0; }

    g_stack_view = VirtualAlloc(NULL, GTA_STACK_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!g_stack_view) { fprintf(stderr, "FATAL: stack alloc failed (%lu)\n", GetLastError()); return 0; }

    g_scratch_view = VirtualAlloc(NULL, GTA_SCRATCH_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (!g_scratch_view) { fprintf(stderr, "FATAL: scratch alloc failed (%lu)\n", GetLastError()); return 0; }

    AddVectoredExceptionHandler(1, crash_handler);
#else
    fprintf(stderr, "FATAL: fixed-base mapping needs Win32\n");
    return 0;
#endif

    g_fs_base      = (uint32_t)(uintptr_t)g_tib_view;
    g_stack_base   = (uint32_t)(uintptr_t)g_stack_view;
    g_scratch_base = g_scratch_next = (uint32_t)(uintptr_t)g_scratch_view;

    g_esp = g_stack_base + GTA_STACK_SIZE - 64;

    /* Simulated TIB: the CRT's SEH prologue reads and writes fs:[0]. */
    MEM32(g_fs_base + 0x00) = 0xFFFFFFFFu;                     /* ExceptionList (end) */
    MEM32(g_fs_base + 0x04) = g_stack_base + GTA_STACK_SIZE; /* StackBase   */
    MEM32(g_fs_base + 0x08) = g_stack_base;                  /* StackLimit  */
    MEM32(g_fs_base + 0x18) = g_fs_base;                       /* Self        */

    g_eax = g_ebx = g_ecx = g_edx = g_esi = g_edi = 0;
    g_fp_top = 0;
    memset(g_st, 0, sizeof(g_st));
    memset(g_icall_trace, 0, sizeof(g_icall_trace));

    fprintf(stderr, "  tib 0x%08X  stack 0x%08X..0x%08X (esp=0x%08X)  scratch 0x%08X\n",
            g_fs_base, g_stack_base, g_stack_base + GTA_STACK_SIZE, g_esp, g_scratch_base);
    return 1;
}

int load_original_data(const char *exe_path) {
    uint32_t span = recomp_load_image(exe_path, GTA_IMAGE_BASE);
    if (!span) {
        fprintf(stderr, "FATAL: could not map %s at 0x%08X -- link this host exe at a high base\n",
                exe_path, GTA_IMAGE_BASE);
        extern void premap_report(void);
        premap_report();
        return 0;
    }
    g_image_span = span;
    fprintf(stderr, "  image 0x%08X..0x%08X from %s\n",
            GTA_IMAGE_BASE, GTA_IMAGE_BASE + span, exe_path);
    return 1;
}

void recomp_shutdown(void) {
#ifdef _WIN32
    if (g_scratch_view) VirtualFree(g_scratch_view, 0, MEM_RELEASE);
    if (g_stack_view)   VirtualFree(g_stack_view, 0, MEM_RELEASE);
    if (g_tib_view)     VirtualFree(g_tib_view, 0, MEM_RELEASE);
#endif
}
