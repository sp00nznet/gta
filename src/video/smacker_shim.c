/*
 * Smacker Video shim -- stub implementation
 *
 * GTA1 uses Smacker for intro/cutscene videos.
 * This is a stub that skips video playback.
 * TODO: Implement actual Smacker decoding (open source decoders exist).
 */

#include "smacker_shim.h"
#include <stdio.h>
#include <stdlib.h>

/* The handle is the game's Smack*: it reads the SDK's fields straight out of
 * it and writes some back, so it has to be the real struct's size with the
 * header where the SDK puts it. A 20-byte struct here let London scribble
 * over the host heap, which surfaced much later as a fault in ntdll or
 * wdmaud during AIL_shutdown. */
typedef struct {
    u32 Version, Width, Height, Frames, MSPerFrame;   /* SDK header, offsets 0..0x10 */
    u8  sdk_rest[0x1000 - 5 * 4];                     /* ponytail: zeroed, never decoded */
    u32 current_frame;
} SmackState;

HSMACK SmackOpen(const char *name, u32 flags, u32 extrabuf) {
    fprintf(stderr, "Smacker shim: SmackOpen('%s', 0x%X)\n",
            name ? name : "(null)", flags);

    SmackState *state = (SmackState *)calloc(1, sizeof(SmackState));
    if (state) {
        state->Version = 0x324B4D53;   /* "SMK2" */
        state->Frames = 1;             /* pretend 1 frame so we finish immediately */
        state->Width = 640;
        state->Height = 480;
        state->MSPerFrame = 66;
    }
    return (HSMACK)state;
}

void SmackClose(HSMACK smk) {
    if (smk) {
        free(smk);
    }
    fprintf(stderr, "Smacker shim: SmackClose\n");
}

u32 SmackDoFrame(HSMACK smk) {
    /* Decode current frame -- stub: do nothing */
    return 0;
}

u32 SmackNextFrame(HSMACK smk) {
    SmackState *state = (SmackState *)smk;
    if (state) {
        state->current_frame++;
        if (state->current_frame >= state->Frames) {
            return SMACKDONE;
        }
    }
    return 1;
}

u32 SmackWait(HSMACK smk) {
    /* Return 0 = no need to wait (skip immediately) */
    return 0;
}

void SmackToBuffer(HSMACK smk, u32 left, u32 top, u32 pitch,
                   u32 destheight, void *buf, u32 flags) {
    /* Stub: don't render anything */
}

void SmackSoundUseDirectSound(void *dd) {
    fprintf(stderr, "Smacker shim: SmackSoundUseDirectSound (ignored)\n");
}

HSMACKBUF SmackBufferOpen(void *hWnd, u32 blitType, u32 w, u32 h,
                          u32 zoom, u32 flags) {
    fprintf(stderr, "Smacker shim: SmackBufferOpen(%ux%u)\n", w, h);
    return (HSMACKBUF)(intptr_t)1; /* non-null dummy handle */
}
