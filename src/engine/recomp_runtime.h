#ifndef GTA_RECOMP_RUNTIME_H
#define GTA_RECOMP_RUNTIME_H

/*
 * GTA runtime = the canonical pcrecomp recomp32 contract + GTA-specific API.
 *
 * recomp_types.h is a verbatim copy of pcrecomp/runtime/recomp32/recomp_types.h
 * and MUST stay that way: it is the interface the lifter generates against.
 * Re-sync it whenever the toolkit's lifter changes; put GTA-only things here.
 */

#include "../common/types.h"
#include "recomp_types.h"

/* Runtime lifecycle */
int  recomp_init(void);
void recomp_shutdown(void);
int  load_original_data(const char *exe_path);

/* IAT bridge system (src/engine/iat_bridge.c) */
void setup_iat_bridges(void);
recomp_func_t iat_bridge_lookup(u32 target_va);

/* Scratch VA space for strings the host hands the game (never inside the image) */
u32 recomp_scratch_alloc(u32 n);
u32 recomp_scratch_str(const char *s);

#endif /* GTA_RECOMP_RUNTIME_H */
