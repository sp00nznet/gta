#ifndef GTA_SMACKER_SHIM_H
#define GTA_SMACKER_SHIM_H

/*
 * Smacker Video (smackw32.dll) shim layer.
 *
 * GTA1 imports 8 ordinals from smackw32.dll for cutscene playback.
 * Only 1 game function directly calls Smacker.
 *
 * Ordinal mapping (from RAD Game Tools Smacker SDK):
 *   14 = SmackOpen
 *   18 = SmackClose
 *   19 = SmackDoFrame
 *   21 = SmackNextFrame
 *   23 = SmackWait
 *   28 = SmackToBuffer
 *   32 = SmackSoundUseDirectSound
 *   33 = SmackBufferOpen
 */

#include "../common/types.h"

/* Opaque handle types */
typedef void *HSMACK;
typedef void *HSMACKBUF;

/* Smack open flags */
#define SMACKTRACK1     0x0001
#define SMACKTRACKS     0x0001
#define SMACKPRELOADALL 0x0002
#define SMACKFRAMERATE  0x0004
#define SMACKLOADEXTRA  0x0008
#define SMACKNEEDPAN    0x0020
#define SMACKNEEDVOLUME 0x0040
#define SMACKFILEHANDLE 0x0100
#define SMACKTRACK2     0x0200
#define SMACKTRACK3     0x0400
#define SMACKTRACK4     0x0800
#define SMACKAUTOEXTRA  0x4000
#define SMACK2XSMOOTH   0x8000

/* Smack frame status */
#define SMACKDONE 0

/* --- API functions (ordinal-mapped) --- */

/* ordinal 14 */ HSMACK SmackOpen(const char *name, u32 flags, u32 extrabuf);
/* ordinal 18 */ void   SmackClose(HSMACK smk);
/* ordinal 19 */ u32    SmackDoFrame(HSMACK smk);
/* ordinal 21 */ u32    SmackNextFrame(HSMACK smk);
/* ordinal 23 */ u32    SmackWait(HSMACK smk);
/* ordinal 28 */ void   SmackToBuffer(HSMACK smk, u32 left, u32 top, u32 pitch,
                                      u32 destheight, void *buf, u32 flags);
/* ordinal 32 */ void   SmackSoundUseDirectSound(void *dd);
/* ordinal 33 */ HSMACKBUF SmackBufferOpen(void *hWnd, u32 blitType, u32 w, u32 h,
                                            u32 zoom, u32 flags);

#endif /* GTA_SMACKER_SHIM_H */
