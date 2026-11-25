/* GTA mixer (gta_mixer.c): 22050 Hz 16-bit stereo out, the format of the
 * game's music tracks. Ported from src/sound/mixer.h. */
#ifndef GTA_MACOS_MIXER_H
#define GTA_MACOS_MIXER_H

#include <stdint.h>

#define MIXER_RATE      22050
#define MIXER_CHANNELS  2
#define MIXER_VOICES    40

int  mixer_init(void);
void mixer_shutdown(void);

int  mixer_voice_alloc(void);
void mixer_voice_free(int v);
void mixer_voice_set_pcm(int v, const void *pcm, uint32_t bytes, int rate, int bits,
                         int channels, int is_signed);
void mixer_voice_set_volume(int v, int vol);     /* 0..127 */
void mixer_voice_set_pan(int v, int pan);        /* 0 left, 64 centre, 127 right */
void mixer_voice_set_rate(int v, int rate);
void mixer_voice_set_loop(int v, int count);     /* 0 or negative = forever */
void mixer_voice_set_loop_block(int v, int32_t start_byte, int32_t end_byte);   /* end < 0: the buffer's end */
void mixer_voice_start(int v);
void mixer_voice_stop(int v);
int  mixer_voice_playing(int v);
void mixer_voice_seek(int v, uint32_t byte_pos);
uint32_t mixer_voice_position(int v);

void mixer_set_master_volume(int vol);
int  mixer_trace_enabled(void);

void *mixer_load_wav(const char *path, uint32_t *bytes, int *rate, int *bits, int *channels);
void  mixer_free_wav(void *pcm);

#endif
