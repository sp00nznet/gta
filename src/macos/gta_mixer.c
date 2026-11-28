/* gta_mixer.c -- the software mixer, ported from src/sound/mixer.c to the
 * native macOS host.
 *
 * Same mixer, same maths: 22050 Hz 16-bit stereo output (the format of the
 * game's music tracks, so those mix in without resampling), point-resampled
 * sound effects, Miles' 0..127 volume and pan, loop counts, and the 64-bit
 * 16.16 frame position that stops the radio wrapping every three seconds.
 * The backend is SDL2's audio device instead of waveOut, and the lock is a
 * pthread mutex: the shims call the voice API under win32hle's machine lock,
 * and SDL's audio thread pulls the mix under this one.
 *
 * The trace switches survive: GTA_AUDIO_TRACE (peak + voices, once a second),
 * GTA_AUDIO_MUTE and GTA_AUDIO_DUMP=FILE (the mix written as a WAV, its
 * header kept current: runs usually die by watchdog).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <SDL2/SDL.h>

#include "gta_mixer.h"

#define FRAMES_PER_BUF  512
#define FRAC_BITS       16

typedef struct {
    const unsigned char *pcm;
    uint32_t bytes;
    int rate, bits, channels;
    int is_signed;   /* 8-bit only */
    int volume, pan;
    int loop;          /* remaining plays; <= 0 means forever */
    uint32_t loop_start, loop_end;   /* the looped block in frames; end 0 = the buffer's end */
    unsigned long long pos;   /* frame position, 16.16 fixed point: 64-bit, or it
                               * wraps after 65,536 frames (3 s of a radio track) */
    int playing;
    int allocated;
} Voice;

static Voice g_voice[MIXER_VOICES];
static int   g_master = 127;
static volatile int g_running;   /* read by the audio thread */
static int g_trace;
static int g_mute;
static int g_peak;
static FILE *g_dump;
static uint32_t g_dump_bytes;
static int g_dump_ticks;
static SDL_AudioDeviceID g_dev;

static pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;
#define LOCK()   pthread_mutex_lock(&g_lock)
#define UNLOCK() pthread_mutex_unlock(&g_lock)

/* Stamp a 44-byte canonical WAV header for data_bytes of PCM.
 *
 * Re-stamped as the dump grows rather than only at shutdown: these runs are
 * usually ended by the watchdog killing the process, so a header written once
 * at the end never gets written at all. */
static void put32le(unsigned char *p, uint32_t v) {
    p[0] = (unsigned char)v; p[1] = (unsigned char)(v >> 8);
    p[2] = (unsigned char)(v >> 16); p[3] = (unsigned char)(v >> 24);
}
static void put16le(unsigned char *p, uint32_t v) {
    p[0] = (unsigned char)v; p[1] = (unsigned char)(v >> 8);
}

static void wav_stamp(FILE *f, uint32_t data_bytes) {
    unsigned char h[44];
    uint32_t rate = MIXER_RATE, ch = MIXER_CHANNELS, bits = 16;
    uint32_t block = ch * bits / 8, byterate = rate * block;
    long here = ftell(f);

    memset(h, 0, sizeof h);
    memcpy(h + 0,  "RIFF", 4);
    put32le(h + 4,  data_bytes + 36);
    memcpy(h + 8, "WAVE", 4);
    memcpy(h + 12, "fmt ", 4);
    put32le(h + 16, 16);                       /* the fmt chunk's size */
    put16le(h + 20, 1);                        /* PCM */
    put16le(h + 22, ch);
    put32le(h + 24, rate);
    put32le(h + 28, byterate);
    put16le(h + 32, block);
    put16le(h + 34, bits);
    memcpy(h + 36, "data", 4);
    put32le(h + 40, data_bytes);
    fseek(f, 0, SEEK_SET);
    fwrite(h, 1, sizeof h, f);
    fseek(f, here, SEEK_SET);
    fflush(f);
}

/* One frame from a voice, as two signed 16-bit channels. */
static void fetch(const Voice *v, uint32_t frame, int *l, int *r) {
    uint32_t stride = (uint32_t)v->channels * (uint32_t)(v->bits / 8);
    const unsigned char *p = v->pcm + (size_t)frame * stride;
    int a, b;

    if (v->bits == 16) {
        a = ((const short *)p)[0];
        b = v->channels == 2 ? ((const short *)p)[1] : a;
    } else if (v->is_signed) {
        a = (int)(signed char)p[0] << 8;
        b = v->channels == 2 ? ((int)(signed char)p[1] << 8) : a;
    } else {
        a = ((int)p[0] - 128) << 8;               /* offset binary */
        b = v->channels == 2 ? (((int)p[1] - 128) << 8) : a;
    }
    *l = a;
    *r = b;
}

static void mix_into(short *out, int frames) {
    static int acc[FRAMES_PER_BUF * MIXER_CHANNELS];
    int i, vi;

    memset(acc, 0, sizeof(int) * (size_t)frames * MIXER_CHANNELS);

    LOCK();
    for (vi = 0; vi < MIXER_VOICES; vi++) {
        Voice *v = &g_voice[vi];
        uint32_t stride, total_frames, step;
        int gain_l, gain_r;

        if (!v->playing || !v->pcm || !v->bytes) continue;

        stride = (uint32_t)v->channels * (uint32_t)(v->bits / 8);
        if (!stride) { v->playing = 0; continue; }
        total_frames = v->bytes / stride;
        if (!total_frames) { v->playing = 0; continue; }

        /* Source frames consumed per output frame, 16.16. */
        step = (uint32_t)(((unsigned long long)v->rate << FRAC_BITS) / MIXER_RATE);
        if (!step) step = 1;

        /* Miles pan is 0..127 with 64 centre; keep it linear and cheap. */
        gain_l = v->volume * (127 - v->pan) * g_master;
        gain_r = v->volume * v->pan * g_master;

        for (i = 0; i < frames; i++) {
            uint32_t f = (uint32_t)(v->pos >> FRAC_BITS);
            int sl, sr;

            /* Miles: a count of 1 plays once, n plays n times, 0 or less
             * forever; with a loop block, each pass but the last goes back
             * to the block's start at its end, the last plays out the rest. */
            uint32_t end = v->loop_end && v->loop_end < total_frames ? v->loop_end : total_frames;
            if (v->loop != 1 && f >= end) {
                if (v->loop > 1) v->loop--;
                f = v->loop_start < end ? v->loop_start : 0;
                v->pos = (unsigned long long)f << FRAC_BITS;
            } else if (f >= total_frames) {
                v->playing = 0;
                break;
            }
            /* Linear interpolation between this frame and the next, as Miles
             * resamples: nearest-frame stepping made a pitched sound (an
             * engine at 13 kHz into the 22 kHz mix) gritty and metallic. */
            fetch(v, f, &sl, &sr);
            {
                uint32_t frac = (uint32_t)(v->pos & ((1u << FRAC_BITS) - 1));
                uint32_t g = f + 1;
                if (g >= end) g = (v->loop != 1 && end <= total_frames) ? (v->loop_start < end ? v->loop_start : 0) : f;
                if (frac && g < total_frames) {
                    int nl, nr;
                    fetch(v, g, &nl, &nr);
                    sl += (int)(((long long)(nl - sl) * frac) >> FRAC_BITS);
                    sr += (int)(((long long)(nr - sr) * frac) >> FRAC_BITS);
                }
            }
            /* volume 0..127, pan 0..127, master 0..127 -> shift by 21 */
            acc[i * 2 + 0] += (int)(((long long)sl * gain_l) >> 21);
            acc[i * 2 + 1] += (int)(((long long)sr * gain_r) >> 21);
            v->pos += step;
        }
    }
    UNLOCK();

    if (g_dump) {
        short w[FRAMES_PER_BUF * MIXER_CHANNELS];
        for (i = 0; i < frames * MIXER_CHANNELS; i++) {
            int s = acc[i];
            if (s >  32767) s =  32767;
            if (s < -32768) s = -32768;
            w[i] = (short)s;
        }
        fwrite(w, sizeof(short), (size_t)frames * MIXER_CHANNELS, g_dump);
        g_dump_bytes += (uint32_t)(frames * MIXER_CHANNELS * (int)sizeof(short));
        if (++g_dump_ticks >= 4) {           /* keep the header within ~0.1s */
            g_dump_ticks = 0;
            wav_stamp(g_dump, g_dump_bytes);
        }
    }

    for (i = 0; i < frames * MIXER_CHANNELS; i++) {
        int s = g_mute ? 0 : acc[i];
        if (s >  32767) s =  32767;
        if (s < -32768) s = -32768;
        out[i] = (short)s;
    }

    /* GTA_AUDIO_TRACE: peak level and voice count. Without speakers on the
     * far end of a headless run, this is the only way to tell "mixing silence"
     * from "mixing nothing". */
    if (g_trace) {
        static int ticks;
        int peak = 0, live = 0;
        for (i = 0; i < frames * MIXER_CHANNELS; i++) {
            int a = acc[i] < 0 ? -acc[i] : acc[i];
            if (a > peak) peak = a;
        }
        for (i = 0; i < MIXER_VOICES; i++) if (g_voice[i].playing) live++;
        if (peak > g_peak) g_peak = peak;
        if (++ticks >= 43) {                 /* about once a second */
            fprintf(stderr, "  AUDIO: %d voice(s) playing, peak %d\n", live, g_peak);
            ticks = 0;
            g_peak = 0;
        }
    }
}
static void SDLCALL audio_cb(void *userdata, Uint8 *stream, int len) {
    (void)userdata;
    if (!g_running) { memset(stream, 0, (size_t)len); return; }
    mix_into((short *)stream, len / (int)(MIXER_CHANNELS * sizeof(short)));
}

int mixer_init(void) {
    if (g_running) return 1;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "  MIXER: SDL audio init failed: %s -- running silent\n", SDL_GetError());
        return 0;
    }
    SDL_AudioSpec want;
    memset(&want, 0, sizeof want);
    want.freq = MIXER_RATE;
    want.format = AUDIO_S16SYS;
    want.channels = MIXER_CHANNELS;
    want.samples = FRAMES_PER_BUF;
    want.callback = audio_cb;
    SDL_AudioSpec have;
    g_dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (!g_dev) {
        fprintf(stderr, "  MIXER: SDL_OpenAudioDevice failed: %s -- running silent\n", SDL_GetError());
        return 0;
    }

    g_trace = getenv("GTA_AUDIO_TRACE") != NULL;
    g_mute  = getenv("GTA_AUDIO_MUTE")  != NULL;
    if (g_mute) fprintf(stderr, "  MIXER: muted (GTA_AUDIO_MUTE)\n");
    { static int dump_tried; const char *path;
      if (!dump_tried && (path = getenv("GTA_AUDIO_DUMP")) && *path) {
          dump_tried = 1;
          g_dump = fopen(path, "wb");
          if (g_dump) {
              wav_stamp(g_dump, 0);
              fprintf(stderr, "  MIXER: writing mix to %s\n", path);
          }
      } }

    g_running = 1;
    SDL_PauseAudioDevice(g_dev, 0);
    fprintf(stderr, "  MIXER: SDL audio %d Hz 16-bit stereo, %d-frame buffers\n",
            have.freq, (int)have.samples);
    return 1;
}

void mixer_shutdown(void) {
    if (!g_running) return;
    g_running = 0;
    SDL_PauseAudioDevice(g_dev, 1);
    SDL_CloseAudioDevice(g_dev);
    g_dev = 0;
    /* The dump stays open: MSS restarts (MGL's exit to the front end), and
     * a run's audio is one file. */
    if (g_dump) fflush(g_dump);
}

int mixer_trace_enabled(void) { return g_trace; }

/* ===== voices ===== */

int mixer_voice_alloc(void) {
    int i;
    LOCK();
    for (i = 0; i < MIXER_VOICES; i++) {
        if (!g_voice[i].allocated) {
            memset(&g_voice[i], 0, sizeof(Voice));
            g_voice[i].allocated = 1;
            g_voice[i].volume = 127;
            g_voice[i].pan    = 64;
            UNLOCK();
            return i;
        }
    }
    UNLOCK();
    return -1;
}

static Voice *get(int v) { return v >= 0 && v < MIXER_VOICES && g_voice[v].allocated ? &g_voice[v] : NULL; }

void mixer_voice_free(int v) {
    LOCK();
    if (get(v)) g_voice[v].allocated = 0;
    UNLOCK();
}

/* pcm is borrowed, not copied -- for samples it points into guest memory,
 * which outlives the voice. */
void mixer_voice_set_pcm(int v, const void *pcm, uint32_t bytes, int rate, int bits,
                         int channels, int is_signed) {
    Voice *x;
    LOCK();
    if ((x = get(v))) {
        x->pcm = (const unsigned char *)pcm;
        x->bytes = bytes;
        x->rate = rate > 0 ? rate : MIXER_RATE;
        x->bits = bits == 16 ? 16 : 8;
        x->channels = channels == 2 ? 2 : 1;
        x->is_signed = is_signed;
    }
    UNLOCK();
}

/* Miles' loop block: the bytes from start to end repeat, the rest plays
 * once (end < 0: to the buffer's end). */
void mixer_voice_set_loop_block(int v, int32_t start_byte, int32_t end_byte) {
    Voice *x;
    LOCK();
    if ((x = get(v))) {
        uint32_t stride = (uint32_t)x->channels * (uint32_t)(x->bits / 8);
        if (!stride) stride = 1;
        x->loop_start = start_byte > 0 ? (uint32_t)start_byte / stride : 0;
        x->loop_end = end_byte > 0 ? (uint32_t)end_byte / stride : 0;
    }
    UNLOCK();
}

void mixer_voice_set_volume(int v, int vol) {
    Voice *x;
    LOCK();
    if ((x = get(v))) x->volume = vol;
    UNLOCK();
}

void mixer_voice_set_pan(int v, int pan) {
    Voice *x;
    LOCK();
    if ((x = get(v))) x->pan = pan;
    UNLOCK();
}

void mixer_voice_set_rate(int v, int rate) {
    Voice *x;
    LOCK();
    if ((x = get(v)) && rate > 0) x->rate = rate;
    UNLOCK();
}

void mixer_voice_set_loop(int v, int count) {
    Voice *x;
    LOCK();
    if ((x = get(v))) x->loop = count;
    UNLOCK();
}

void mixer_voice_start(int v) {
    Voice *x;
    LOCK();
    if ((x = get(v)) && x->pcm && x->bytes) {
        x->pos = 0;
        x->playing = 1;
    }
    UNLOCK();
}

void mixer_voice_stop(int v) {
    Voice *x;
    LOCK();
    if ((x = get(v))) x->playing = 0;
    UNLOCK();
}

int mixer_voice_playing(int v) {
    Voice *x;
    int r = 0;
    LOCK();
    if ((x = get(v))) r = x->playing;
    UNLOCK();
    return r;
}

uint32_t mixer_voice_position(int v) {
    Voice *x;
    uint32_t r = 0;
    LOCK();
    if ((x = get(v)))
        r = (uint32_t)(x->pos >> FRAC_BITS) * (uint32_t)x->channels * (uint32_t)(x->bits / 8);
    UNLOCK();
    return r;
}

/* Move a voice to a byte offset in its PCM (AIL_set_stream_position). */
void mixer_voice_seek(int v, uint32_t byte_pos) {
    Voice *x;
    LOCK();
    if ((x = get(v)) && x->channels && x->bits)
        x->pos = (unsigned long long)(byte_pos / ((uint32_t)x->channels * (uint32_t)(x->bits / 8))) << FRAC_BITS;
    UNLOCK();
}

void mixer_set_master_volume(int vol) {
    g_master = vol < 0 ? 0 : (vol > 127 ? 127 : vol);
}

/* ===== WAV loading =====
 *
 * Chunk-walking rather than assuming a 44-byte header: the game's tracks are
 * plain RIFF/WAVE but nothing guarantees fmt is first or that there is no LIST.
 */
/* IMA ADPCM, Microsoft's WAV layout (format 0x11): each block starts with a
 * header per channel (the first sample, the step index), then 4-bit codes,
 * low nibble first, in runs of eight samples a channel interleaved four
 * bytes at a time. GTA2's radio stations and vocals are all this; read as
 * PCM they were noise -- the hiss in the city. */
static const int k_ima_step[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97,
    107, 118, 130, 143, 157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871,
    5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623,
    27086, 29794, 32767 };
static const int k_ima_index[16] = { -1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8 };
static int ima_nibble(int code, int *pred, int *index) {
    int step = k_ima_step[*index], diff = step >> 3;
    if (code & 1) diff += step >> 2;
    if (code & 2) diff += step >> 1;
    if (code & 4) diff += step;
    *pred += (code & 8) ? -diff : diff;
    if (*pred > 32767) *pred = 32767;
    if (*pred < -32768) *pred = -32768;
    *index += k_ima_index[code & 15];
    if (*index < 0) *index = 0;
    if (*index > 88) *index = 88;
    return *pred;
}
static int16_t *ima_decode(const unsigned char *in, uint32_t n, int chans, int block, uint32_t *out_bytes) {
    if (chans < 1 || chans > 2 || block < 4 * chans) return NULL;
    uint32_t per_block = (uint32_t)((block - 4 * chans) * 2 / chans + 1);   /* samples a channel */
    uint32_t blocks = (n + (uint32_t)block - 1) / (uint32_t)block;
    int16_t *out = (int16_t *)malloc((size_t)blocks * per_block * (size_t)chans * 2 + 2);
    if (!out) return NULL;
    size_t w = 0;
    for (uint32_t b = 0; b < blocks; b++) {
        const unsigned char *p = in + (size_t)b * (size_t)block;
        uint32_t len = n - b * (uint32_t)block < (uint32_t)block ? n - b * (uint32_t)block : (uint32_t)block;
        if (len < (uint32_t)(4 * chans)) break;
        int pred[2], index[2];
        for (int c = 0; c < chans; c++) {
            pred[c] = (int16_t)(p[4 * c] | p[4 * c + 1] << 8);
            index[c] = p[4 * c + 2] > 88 ? 88 : p[4 * c + 2];
            out[w + (size_t)c] = (int16_t)pred[c];
        }
        w += (size_t)chans;
        const unsigned char *d = p + 4 * chans, *end = p + len;
        int16_t *frame = out + w;                    /* this block's samples after the header one */
        uint32_t got = 0;
        while (d + 4 * chans <= end) {               /* eight samples a channel */
            for (int c = 0; c < chans; c++, d += 4)
                for (int k = 0; k < 8; k++) {
                    int code = (d[k >> 1] >> ((k & 1) * 4)) & 15;
                    frame[(size_t)(got + (uint32_t)k) * (size_t)chans + (size_t)c] = (int16_t)ima_nibble(code, &pred[c], &index[c]);
                }
            got += 8;
        }
        w += (size_t)got * (size_t)chans;
    }
    *out_bytes = (uint32_t)(w * 2);
    return out;
}

void *mixer_load_wav(const char *path, uint32_t *bytes, int *rate, int *bits, int *channels) {
    FILE *f = fopen(path, "rb");
    unsigned char hdr[12], ch[8];
    void *pcm = NULL;
    int have_fmt = 0, tag = 1, block = 0;

    if (!f) return NULL;
    if (fread(hdr, 1, 12, f) != 12 || memcmp(hdr, "RIFF", 4) || memcmp(hdr + 8, "WAVE", 4)) {
        fclose(f);
        return NULL;
    }

    while (fread(ch, 1, 8, f) == 8) {
        uint32_t size = (uint32_t)ch[4] | ((uint32_t)ch[5] << 8) | ((uint32_t)ch[6] << 16) | ((uint32_t)ch[7] << 24);
        if (!memcmp(ch, "fmt ", 4)) {
            unsigned char fmt[16];
            uint32_t want = size < sizeof(fmt) ? size : sizeof(fmt);
            if (fread(fmt, 1, want, f) != want) break;
            *channels = fmt[2] | (fmt[3] << 8);
            *rate     = (int)((uint32_t)fmt[4] | ((uint32_t)fmt[5] << 8) | ((uint32_t)fmt[6] << 16) | ((uint32_t)fmt[7] << 24));
            *bits     = fmt[14] | (fmt[15] << 8);
            tag       = fmt[0] | (fmt[1] << 8);
            block     = fmt[12] | (fmt[13] << 8);
            have_fmt  = 1;
            if (size > want) fseek(f, (long)(size - want), SEEK_CUR);
        } else if (!memcmp(ch, "data", 4)) {
            long here = ftell(f);
            pcm = malloc(size ? size : 1);
            if (pcm && fread(pcm, 1, size, f) == size) {
                *bytes = size;
            } else {
                free(pcm), pcm = NULL;
            }
            fseek(f, here + (long)size, SEEK_SET);   /* keep walking: another data may follow */
        } else {
            fseek(f, (long)size, SEEK_CUR);
        }
        if (size & 1) fseek(f, 1, SEEK_CUR);          /* chunks are word-aligned */
    }
    fclose(f);
    if (!have_fmt) { free(pcm); pcm = NULL; }
    if (pcm && tag == 0x11) {                        /* IMA ADPCM: to 16-bit PCM */
        uint32_t n = 0;
        int16_t *dec = ima_decode((const unsigned char *)pcm, *bytes, *channels, block, &n);
        free(pcm);
        pcm = dec;
        if (dec) *bytes = n, *bits = 16;
    } else if (pcm && tag != 1) {                    /* a codec not decoded here: silence, not noise */
        fprintf(stderr, "  MIXER: %s: WAV format 0x%X not decoded\n", path, tag);
        free(pcm);
        pcm = NULL;
    }
    return pcm;
}

void mixer_free_wav(void *pcm) { free(pcm); }
