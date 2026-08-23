/*
 * Software mixer on waveOut.
 *
 * The Miles shim needs somewhere to actually put sound. SDL2 was the intended
 * backend but is not present in this build (and the vcpkg copy on hand is x64,
 * while this target is Win32), so every SDL entry point fell through to a stub
 * -- which is how AIL_ms_count came to return a constant zero and hang the
 * level loader. winmm is already linked for joystick input, so waveOut costs no
 * new dependency and works for anyone who clones the repo.
 *
 * Output is 22050 Hz 16-bit stereo, which is exactly the format of the game's
 * music tracks, so those mix in without resampling. Sound effects arrive at
 * whatever rate Miles was told and are point-resampled.
 */
#ifndef GTA_MIXER_H
#define GTA_MIXER_H

#include "../common/types.h"

#define MIXER_RATE      22050
#define MIXER_CHANNELS  2
#define MIXER_VOICES    40

int  mixer_init(void);
void mixer_shutdown(void);

/* Voices. Allocation is independent of playback: Miles hands out a sample
 * handle long before it has any PCM to put in it. */
int  mixer_voice_alloc(void);
void mixer_voice_free(int v);

/* pcm is borrowed, not copied -- for samples it points into game memory, which
 * outlives the voice. bits is 8 (unsigned, offset binary, as Miles uses) or 16
 * (signed). */
void mixer_voice_set_pcm(int v, const void *pcm, u32 bytes, int rate, int bits, int channels);
void mixer_voice_set_volume(int v, int vol);     /* 0..127 */
void mixer_voice_set_pan(int v, int pan);        /* 0 left, 64 centre, 127 right */
void mixer_voice_set_rate(int v, int rate);
void mixer_voice_set_loop(int v, int count);     /* 0 or negative = forever */
void mixer_voice_start(int v);
void mixer_voice_stop(int v);
int  mixer_voice_playing(int v);
u32  mixer_voice_position(int v);                /* bytes consumed from pcm */

void mixer_set_master_volume(int vol);           /* 0..127 */
int  mixer_trace_enabled(void);                  /* GTA_AUDIO_TRACE */

/* Load a RIFF/WAVE file into a malloc'd PCM block. Returns NULL on failure.
 * Caller frees with mixer_free_wav. */
void *mixer_load_wav(const char *path, u32 *bytes, int *rate, int *bits, int *channels);
void  mixer_free_wav(void *pcm);

#endif
