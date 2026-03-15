#ifndef GTA_RECOMP_RUNTIME_H
#define GTA_RECOMP_RUNTIME_H

#include "../common/types.h"
#include <stdint.h>

/*
 * Recompilation runtime for GTA.
 *
 * Global register model: x86 registers become C globals.
 * Memory model: MEM32(addr) dereferences original virtual addresses
 * through a base pointer. On Windows we VirtualAlloc at the original
 * image base so g_mem_base == 0 and addresses work directly.
 */

/* =====================================================
 * Global register model
 * ===================================================== */
extern u32 eax, ebx, ecx, edx;
extern u32 esi, edi, ebp, esp;
extern u32 eflags;

/* FPU stack */
extern f64 fpu_stack[8];
extern int fpu_top;

/* =====================================================
 * Memory access via VA translation
 * ===================================================== */
extern u8 *g_mem_base;  /* Base pointer for VA translation (0 if mapped at original base) */

#define MEM8(addr)   (*(u8  *)(g_mem_base + (u32)(addr)))
#define MEM16(addr)  (*(u16 *)(g_mem_base + (u32)(addr)))
#define MEM32(addr)  (*(u32 *)(g_mem_base + (u32)(addr)))
#define MEMF32(addr) (*(f32 *)(g_mem_base + (u32)(addr)))
#define MEMF64(addr) (*(f64 *)(g_mem_base + (u32)(addr)))
#define MEMPTR(addr) ((void *)(g_mem_base + (u32)(addr)))

/* =====================================================
 * Stack operations (simulated x86 stack)
 * ===================================================== */
#define PUSH32(sp, val) do { \
    (sp) -= 4; \
    MEM32(sp) = (u32)(val); \
} while(0)

#define POP32(sp, dest) do { \
    (dest) = MEM32(sp); \
    (sp) += 4; \
} while(0)

/* POP32_VAL: returns the value at top of stack and increments SP.
 * Used as: reg = POP32_VAL(esp);
 * The comma operator ensures sp is incremented after the read. */
static __inline u32 _pop32_val(u32 *sp) {
    u32 val = *(u32 *)(g_mem_base + *sp);
    *sp += 4;
    return val;
}
#define POP32_VAL(sp) _pop32_val(&(sp))

/* =====================================================
 * Comparison and test macros
 *
 * These replace x86 flag-setter/consumer pairs.
 * CMP_ variants do signed/unsigned comparisons.
 * TEST_ variants check bitwise AND results.
 * ===================================================== */

/* Signed comparisons */
#define CMP_EQ(a, b)  ((u32)(a) == (u32)(b))
#define CMP_E(a, b)   ((u32)(a) == (u32)(b))
#define CMP_NE(a, b)  ((u32)(a) != (u32)(b))
#define CMP_L(a, b)   ((s32)(a) < (s32)(b))
#define CMP_LE(a, b)  ((s32)(a) <= (s32)(b))
#define CMP_G(a, b)   ((s32)(a) > (s32)(b))
#define CMP_GE(a, b)  ((s32)(a) >= (s32)(b))

/* Unsigned comparisons */
#define CMP_B(a, b)   ((u32)(a) < (u32)(b))
#define CMP_BE(a, b)  ((u32)(a) <= (u32)(b))
#define CMP_A(a, b)   ((u32)(a) > (u32)(b))
#define CMP_AE(a, b)  ((u32)(a) >= (u32)(b))

/* Sign/parity flag checks */
#define CMP_S(a, b)   ((s32)((u32)(a) - (u32)(b)) < 0)
#define CMP_NS(a, b)  ((s32)((u32)(a) - (u32)(b)) >= 0)
#define CMP_P(a, b)   (__builtin_parity((u8)((u32)(a) - (u32)(b))))
#define CMP_NP(a, b)  (!__builtin_parity((u8)((u32)(a) - (u32)(b))))

/* Test (bitwise AND) */
#define TEST_Z(a, b)  (((u32)(a) & (u32)(b)) == 0)
#define TEST_NZ(a, b) (((u32)(a) & (u32)(b)) != 0)
#define TEST_S(a, b)  ((s32)((u32)(a) & (u32)(b)) < 0)
#define TEST_NS(a, b) ((s32)((u32)(a) & (u32)(b)) >= 0)

/* =====================================================
 * Sub-register access (8-bit and 16-bit parts of 32-bit registers)
 * ===================================================== */
#define LO8(reg)  ((u8)(reg))
#define HI8(reg)  ((u8)((reg) >> 8))
#define LO16(reg) ((u16)(reg))

#define SET_LO8(reg, val)  do { (reg) = ((reg) & 0xFFFFFF00u) | ((u32)(u8)(val)); } while(0)
#define SET_HI8(reg, val)  do { (reg) = ((reg) & 0xFFFF00FFu) | (((u32)(u8)(val)) << 8); } while(0)
#define SET_LO16(reg, val) do { (reg) = ((reg) & 0xFFFF0000u) | ((u32)(u16)(val)); } while(0)

/* =====================================================
 * Direct function call (for known call targets)
 * ===================================================== */
#define RECOMP_CALL(func) (func)()

/* =====================================================
 * FPU (x87 floating-point) simulation
 * ===================================================== */
extern f64 fpu_st[8];
extern int fpu_sp;

/* Push a value onto the FPU stack */
static __inline void fp_push(f64 val) {
    /* Shift stack down, push onto ST(0) */
    for (int i = 7; i > 0; i--) fpu_st[i] = fpu_st[i-1];
    fpu_st[0] = val;
}

/* Pop a value from the FPU stack */
static __inline f64 fp_pop(void) {
    f64 val = fpu_st[0];
    for (int i = 0; i < 7; i++) fpu_st[i] = fpu_st[i+1];
    fpu_st[7] = 0.0;
    return val;
}

/* =====================================================
 * Additional memory/address macros
 * ===================================================== */
#define MEM64(addr)    (*(u64 *)(g_mem_base + (u32)(addr)))
#define ADDR(addr)     ((u32)(addr))
#define MEMSET32(addr, val, count) do { \
    u32 *_p = (u32 *)(g_mem_base + (u32)(addr)); \
    for (u32 _i = 0; _i < (count); _i++) _p[_i] = (val); \
} while(0)

/* Bit rotation */
static __inline u32 ROL32(u32 val, int n) { n &= 31; return (val << n) | (val >> (32 - n)); }
static __inline u32 ROR32(u32 val, int n) { n &= 31; return (val >> n) | (val << (32 - n)); }

/* FPU comparison flag helpers (single-arg versions for FCOM results) */
/* _fpu_cmp is -1, 0, or 1 from fcomp */
#define FPU_CMP_BE(c) ((c) <= 0)  /* below or equal = less or equal */
#define FPU_CMP_B(c)  ((c) < 0)   /* below = less */
#define FPU_CMP_E(c)  ((c) == 0)  /* equal */
#define FPU_CMP_NE(c) ((c) != 0)  /* not equal */
#define FPU_CMP_A(c)  ((c) > 0)   /* above = greater */
#define FPU_CMP_AE(c) ((c) >= 0)  /* above or equal */

/* Segment register stubs (not meaningful in flat memory model) */
#define _seg_cs 0
#define _seg_ds 0
#define _seg_es 0
#define _seg_ss 0

/* =====================================================
 * Indirect call / tail-call dispatch
 * ===================================================== */
typedef void (*recomp_func_t)(void);

typedef struct {
    u32 addr;
    recomp_func_t func;
} recomp_dispatch_entry_t;

/* Dispatch tables (defined in generated code) */
extern const recomp_dispatch_entry_t recomp_dispatch_table[];
extern const u32 recomp_dispatch_count;

/* Dispatch an indirect call to a recompiled function by original VA */
void recomp_icall(u32 target_va);

/* --- ICALL trace ring buffer (for debugging) --- */
#define ICALL_TRACE_SIZE 32
extern u32 icall_trace[ICALL_TRACE_SIZE];
extern int icall_trace_idx;

#define RECOMP_ICALL(target_va) do { \
    icall_trace[icall_trace_idx] = (target_va); \
    icall_trace_idx = (icall_trace_idx + 1) % ICALL_TRACE_SIZE; \
    recomp_icall(target_va); \
} while(0)

/* Indirect tail-call (jmp through function pointer) */
#define RECOMP_ITAIL(target_va) do { \
    icall_trace[icall_trace_idx] = (target_va); \
    icall_trace_idx = (icall_trace_idx + 1) % ICALL_TRACE_SIZE; \
    recomp_icall(target_va); \
} while(0)

/* =====================================================
 * MSVC compatibility
 * ===================================================== */
#ifdef _MSC_VER
  /* MSVC doesn't have __builtin_parity */
  #undef CMP_P
  #undef CMP_NP
  static __inline int _parity8(u8 v) {
      v ^= v >> 4; v ^= v >> 2; v ^= v >> 1; return v & 1;
  }
  #define CMP_P(a, b)  (_parity8((u8)((u32)(a) - (u32)(b))))
  #define CMP_NP(a, b) (!_parity8((u8)((u32)(a) - (u32)(b))))
#endif

/* =====================================================
 * Import bridge (IAT call simulation)
 * ===================================================== */
#define STUB(name) fprintf(stderr, "STUB: %s\n", name)

/* Runtime initialization/shutdown */
int recomp_init(void);
void recomp_shutdown(void);
int load_original_data(const char *exe_path);

/* IAT bridge system */
void setup_iat_bridges(void);
int iat_bridge_try_dispatch(u32 target_va);

#endif /* GTA_RECOMP_RUNTIME_H */
