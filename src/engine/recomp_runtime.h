#ifndef GTA_RECOMP_RUNTIME_H
#define GTA_RECOMP_RUNTIME_H

#include "../common/types.h"

/*
 * Recompilation runtime for GTA.
 *
 * Global register model: x86 registers become C globals.
 * Memory model: MEM32(addr) dereferences original virtual addresses
 * through a base offset computed at startup.
 */

/* --- Global register model --- */
extern u32 reg_eax, reg_ebx, reg_ecx, reg_edx;
extern u32 reg_esi, reg_edi, reg_ebp, reg_esp;
extern u32 reg_eflags;

/* FPU stack */
extern f64 fpu_stack[8];
extern int fpu_top;

/* --- Memory access via VA translation --- */
extern u8 *g_mem_base;  /* Base pointer for VA translation */

#define MEM8(addr)   (*(u8  *)(g_mem_base + (u32)(addr)))
#define MEM16(addr)  (*(u16 *)(g_mem_base + (u32)(addr)))
#define MEM32(addr)  (*(u32 *)(g_mem_base + (u32)(addr)))
#define MEMF32(addr) (*(f32 *)(g_mem_base + (u32)(addr)))
#define MEMF64(addr) (*(f64 *)(g_mem_base + (u32)(addr)))
#define MEMPTR(addr) ((void *)(g_mem_base + (u32)(addr)))

/* --- Comparison macros (flag-setter/consumer pairs) --- */
#define CMP_E(a, b)   ((a) == (b))
#define CMP_NE(a, b)  ((a) != (b))
#define CMP_L(a, b)   ((s32)(a) < (s32)(b))
#define CMP_LE(a, b)  ((s32)(a) <= (s32)(b))
#define CMP_G(a, b)   ((s32)(a) > (s32)(b))
#define CMP_GE(a, b)  ((s32)(a) >= (s32)(b))
#define CMP_B(a, b)   ((u32)(a) < (u32)(b))
#define CMP_BE(a, b)  ((u32)(a) <= (u32)(b))
#define CMP_A(a, b)   ((u32)(a) > (u32)(b))
#define CMP_AE(a, b)  ((u32)(a) >= (u32)(b))

/* --- Indirect call dispatch --- */
typedef void (*recomp_func_t)(void);

/* Dispatch an indirect call to a recompiled function by original VA */
void recomp_icall(u32 target_va);

/* Register a function in the dispatch table */
void recomp_register(u32 original_va, recomp_func_t func);

/* --- ICALL trace ring buffer (for debugging) --- */
#define ICALL_TRACE_SIZE 32
extern u32 icall_trace[ICALL_TRACE_SIZE];
extern int icall_trace_idx;

#define RECOMP_ICALL(target_va) do { \
    icall_trace[icall_trace_idx] = (target_va); \
    icall_trace_idx = (icall_trace_idx + 1) % ICALL_TRACE_SIZE; \
    recomp_icall(target_va); \
} while(0)

#endif /* GTA_RECOMP_RUNTIME_H */
