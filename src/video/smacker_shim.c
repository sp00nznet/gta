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

typedef struct {
    int active;
    u32 frames;
    u32 current_frame;
    u32 width;
    u32 height;
} SmackState;

HSMACK SmackOpen(const char *name, u32 flags, u32 extrabuf) {
    fprintf(stderr, "Smacker shim: SmackOpen('%s', 0x%X)\n",
            name ? name : "(null)", flags);

    SmackState *state = (SmackState *)calloc(1, sizeof(SmackState));
    if (state) {
        state->active = 1;
        state->frames = 1; /* Pretend 1 frame so we finish immediately */
        state->current_frame = 0;
        state->width = 640;
        state->height = 480;
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
        if (state->current_frame >= state->frames) {
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
