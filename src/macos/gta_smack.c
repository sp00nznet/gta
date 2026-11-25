/* gta_smack.c -- the Smacker video (smackw32.dll) the game imports, answered
 * by the native macOS host.
 *
 * Ported from src/video/smacker_shim.c: a stub that skips video playback.
 * GTA1 uses Smacker for its intro and cutscenes, and the shim pretends each
 * video is one frame long and decodes nothing, so the game moves straight
 * past it. (Actual Smacker decoding can come later: open-source decoders
 * exist, and win32hle's bink.c shows the pattern -- ffmpeg into the game's
 * own buffer.)
 *
 * The handle is the game's Smack*: it reads the SDK's fields straight out of
 * it and writes some back, so it has to be the real struct's size with the
 * header where the SDK puts it (src/video/smacker_shim.c: a 20-byte struct
 * let London scribble over the host heap). Here it lives in guest memory.
 *
 * Ordinals (from the RAD Game Tools Smacker SDK):
 *   14 = SmackOpen              18 = SmackClose
 *   19 = SmackDoFrame           21 = SmackNextFrame
 *   23 = SmackWait              28 = SmackToBuffer
 *   32 = SmackSoundUseDirectSound
 *   33 = SmackBufferOpen
 */
#include <stdio.h>
#include <string.h>

#include "win32hle.h"

/* the SDK's header, at the offsets the game reads */
#define SMK_VERSION   0x00   /* "SMK2" */
#define SMK_WIDTH     0x04
#define SMK_HEIGHT    0x08
#define SMK_FRAMES    0x0C
#define SMK_MSPERFRM  0x10
#define SMK_STATE     0x1000 /* our own: the frame counter (sdk_rest ends there) */
#define SMK_SIZE      0x1008

static void smk_SmackOpen(void) {
    const char *name = ASTR(0);
    uint32_t h = (uint32_t)(uintptr_t)hle_alloc(SMK_SIZE);   /* guest memory, zeroed */
    fprintf(stderr, "[smack] SmackOpen('%s') -> 0x%08X\n", name ? name : "(null)", h);
    if (h) {
        MEM32(h + SMK_VERSION)  = 0x324B4D53u;   /* "SMK2" */
        MEM32(h + SMK_WIDTH)    = 640;
        MEM32(h + SMK_HEIGHT)   = 480;
        MEM32(h + SMK_FRAMES)   = 1;             /* pretend 1 frame: finish immediately */
        MEM32(h + SMK_MSPERFRM) = 66;
    }
    RET(h, 3);
}

static void smk_SmackClose(void) { RET(0, 1); }

static void smk_SmackDoFrame(void) { RET(0, 1); }   /* decode: nothing */

static void smk_SmackNextFrame(void) {
    uint32_t h = A32(0);
    if (h) {
        uint32_t f = MEM32(h + SMK_STATE) + 1;
        MEM32(h + SMK_STATE) = f;
        RET(f >= MEM32(h + SMK_FRAMES) ? 0 /* SMACKDONE */ : 1, 1);
    }
    RET(0, 1);
}

static void smk_SmackWait(void) { RET(0, 1); }      /* no need to wait: skip */

static void smk_SmackToBuffer(void) { RET(0, 7); }  /* render: nothing */

static void smk_SmackSoundUseDirectSound(void) { RET(0, 1); }

static void smk_SmackBufferOpen(void) {
    fprintf(stderr, "[smack] SmackBufferOpen(%ux%u)\n", A32(3), A32(4));
    RET(1, 6);                                      /* a non-null dummy handle */
}

const win32hle_shim gta_smack_shims[] = {
    { "smackw32.dll#14", smk_SmackOpen },
    { "smackw32.dll#18", smk_SmackClose },
    { "smackw32.dll#19", smk_SmackDoFrame },
    { "smackw32.dll#21", smk_SmackNextFrame },
    { "smackw32.dll#23", smk_SmackWait },
    { "smackw32.dll#28", smk_SmackToBuffer },
    { "smackw32.dll#32", smk_SmackSoundUseDirectSound },
    { "smackw32.dll#33", smk_SmackBufferOpen },
    { 0, 0 }
};
