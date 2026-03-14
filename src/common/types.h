#ifndef GTA_RECOMP_TYPES_H
#define GTA_RECOMP_TYPES_H

#include <stdint.h>
#include <stddef.h>

/*
 * Core types for the GTA static recompilation.
 *
 * The original GTA1 was compiled with MSVC 6.0 targeting Win32 (i386).
 * These types match the original binary's data model.
 */

typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;
typedef int8_t    s8;
typedef int16_t   s16;
typedef int32_t   s32;
typedef int64_t   s64;
typedef float     f32;
typedef double    f64;

/* Boolean (Win32 BOOL = int) */
typedef int BOOL32;
#define TRUE32  1
#define FALSE32 0

/* Original image base for VA translation */
#define GTA1_IMAGE_BASE   0x00400000
#define GTA1_CODE_START   0x00401000
#define GTA1_CODE_END     0x004A63D9
#define GTA1_DATA_START   0x004AB000
#define GTA1_DATA_END     0x00790298
#define GTA1_ENTRY_POINT  0x0049DC30

#endif /* GTA_RECOMP_TYPES_H */
