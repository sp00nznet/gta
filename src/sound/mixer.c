#include "mixer.h"

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <mmsystem.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FRAMES_PER_BUF  512
#define NUM_BUFS        8
#define FRAC_BITS       16

typedef struct {
    const unsigned char *pcm;
    u32   bytes;
    int   rate, bits, channels;
    int   is_signed;   /* 8-bit only */
    int   volume, pan;
    int   loop;          /* remaining plays; <= 0 means forever */
    u32   pos;           /* frame position, 16.16 fixed point */
    int   playing;
    int   allocated;
} Voice;

static Voice g_voice[MIXER_VOICES];
static int   g_master = 127;
static int   g_running;
static int   g_trace;
static int   g_peak;
static int   g_mute;
static FILE *g_dump;
static u32   g_dump_bytes;
static int   g_dump_ticks;

#ifdef _WIN32
static HWAVEOUT   g_dev;
static WAVEHDR    g_hdr[NUM_BUFS];
static short     *g_buf[NUM_BUFS];
static HANDLE     g_thread, g_event;
static CRITICAL_SECTION g_lock;
#define LOCK()   EnterCriticalSection(&g_lock)
#define UNLOCK() LeaveCriticalSection(&g_lock)
#else
#define LOCK()
#define UNLOCK()
#endif

/* Stamp a 44-byte canonical WAV header for data_bytes of PCM.
 *
 * Re-stamped as the dump grows rather than only at shutdown: these runs are
 * usually ended by the watchdog killing the process, so a header written once
 * at the end never gets written at all. The first version of this left RIFF
 * size, data size AND the byte-rate field all zero, which no player will touch.
 */
static void wav_stamp(FILE *f, u32 data_bytes) {
    unsigned char h[44];
    u32 rate = MIXER_RATE, ch = MIXER_CHANNELS, bits = 16;
    u32 block = ch * bits / 8, byterate = rate * block;
    long here = ftell(f);

    memset(h, 0, sizeof(h));
    memcpy(h + 0,  "RIFF", 4);
    h[4]  = (unsigned char)((data_bytes + 36));
    h[5]  = (unsigned char)((data_bytes + 36) >> 8);
    h[6]  = (unsigned char)((data_bytes + 36) >> 16);
    h[7]  = (unsigned char)((data_bytes + 36) >> 24);
    memcpy(h + 8,  "WAVE", 4);
    memcpy(h + 12, "fmt ", 4);
    h[16] = 16;
    h[20] = 1;                                   /* PCM */
    h[22] = (unsigned char)ch;
    h[24] = (unsigned char)(rate);
    h[25] = (unsigned char)(rate >> 8);
    h[26] = (unsigned char)(rate >> 16);
    h[28] = (unsigned char)(byterate);           /* the field that was missing */
    h[29] = (unsigned char)(byterate >> 8);
    h[30] = (unsigned char)(byterate >> 16);
    h[32] = (unsigned char)block;
    h[34] = (unsigned char)bits;
    memcpy(h + 36, "data", 4);
    h[40] = (unsigned char)(data_bytes);
    h[41] = (unsigned char)(data_bytes >> 8);
    h[42] = (unsigned char)(data_bytes >> 16);
    h[43] = (unsigned char)(data_bytes >> 24);

    fseek(f, 0, SEEK_SET);
    fwrite(h, 1, sizeof(h), f);
    if (here > 0) fseek(f, here, SEEK_SET);
    else          fseek(f, 0, SEEK_END);
    fflush(f);
}

/* One frame from a voice, as two signed 16-bit channels. */
static void fetch(const Voice *v, u32 frame, int *l, int *r) {
    u32 stride = (u32)v->channels * (u32)(v->bits / 8);
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
        u32 stride, total_frames, step;
        int gain_l, gain_r;

        if (!v->playing || !v->pcm || !v->bytes) continue;

        stride = (u32)v->channels * (u32)(v->bits / 8);
        if (!stride) { v->playing = 0; continue; }
        total_frames = v->bytes / stride;
        if (!total_frames) { v->playing = 0; continue; }

        /* Source frames consumed per output frame, 16.16. */
        step = (u32)(((unsigned long long)v->rate << FRAC_BITS) / MIXER_RATE);
        if (!step) step = 1;

        /* Miles pan is 0..127 with 64 centre; keep it linear and cheap. */
        gain_l = v->volume * (127 - v->pan) * g_master;
        gain_r = v->volume * v->pan * g_master;

        for (i = 0; i < frames; i++) {
            u32 f = v->pos >> FRAC_BITS;
            int sl, sr;

            if (f >= total_frames) {
                if (v->loop > 0) v->loop--;
                if (v->loop == 0) { v->playing = 0; break; }
                v->pos = 0;
                f = 0;
            }
            fetch(v, f, &sl, &sr);
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
        g_dump_bytes += (u32)(frames * MIXER_CHANNELS * (int)sizeof(short));
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

    /* GTA_AUDIO_TRACE: peak level and voice count. Without speakers on the far
     * end of a headless run, this is the only way to tell "mixing silence"
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
        if (++ticks >= 40) {                 /* about once a second */
            fprintf(stderr, "  AUDIO: %d voice(s) playing, peak %d\n", live, g_peak);
            ticks = 0;
            g_peak = 0;
        }
    }
}

#ifdef _WIN32
static DWORD WINAPI mixer_thread(LPVOID arg) {
    (void)arg;
    while (g_running) {
        int did = 0, i;
        for (i = 0; i < NUM_BUFS; i++) {
            if (!(g_hdr[i].dwFlags & WHDR_INQUEUE)) {
                mix_into(g_buf[i], FRAMES_PER_BUF);
                g_hdr[i].dwFlags &= ~WHDR_DONE;
                waveOutWrite(g_dev, &g_hdr[i], sizeof(WAVEHDR));
                did = 1;
            }
        }
        if (!did) WaitForSingleObject(g_event, 20);
    }
    return 0;
}

int mixer_init(void) {
    WAVEFORMATEX wf;
    int i;

    if (g_running) return 1;

    memset(&wf, 0, sizeof(wf));
    wf.wFormatTag      = WAVE_FORMAT_PCM;
    wf.nChannels       = MIXER_CHANNELS;
    wf.nSamplesPerSec  = MIXER_RATE;
    wf.wBitsPerSample  = 16;
    wf.nBlockAlign     = (WORD)(wf.nChannels * wf.wBitsPerSample / 8);
    wf.nAvgBytesPerSec = wf.nSamplesPerSec * wf.nBlockAlign;

    g_event = CreateEventA(NULL, FALSE, FALSE, NULL);
    if (waveOutOpen(&g_dev, WAVE_MAPPER, &wf, (DWORD_PTR)g_event, 0,
                    CALLBACK_EVENT) != MMSYSERR_NOERROR) {
        fprintf(stderr, "  MIXER: waveOutOpen failed -- running silent\n");
        CloseHandle(g_event);
        g_event = NULL;
        return 0;
    }

    InitializeCriticalSection(&g_lock);
    for (i = 0; i < NUM_BUFS; i++) {
        g_buf[i] = (short *)calloc(FRAMES_PER_BUF * MIXER_CHANNELS, sizeof(short));
        memset(&g_hdr[i], 0, sizeof(WAVEHDR));
        g_hdr[i].lpData         = (LPSTR)g_buf[i];
        g_hdr[i].dwBufferLength = FRAMES_PER_BUF * MIXER_CHANNELS * sizeof(short);
        waveOutPrepareHeader(g_dev, &g_hdr[i], sizeof(WAVEHDR));
    }

    { char b[8];
      g_trace = GetEnvironmentVariableA("GTA_AUDIO_TRACE", b, sizeof(b)) ? 1 : 0;
      g_mute  = GetEnvironmentVariableA("GTA_AUDIO_MUTE", b, sizeof(b)) ? 1 : 0;
      if (g_mute) fprintf(stderr, "  MIXER: muted (GTA_AUDIO_MUTE)\n"); }
    { static int dump_tried; char path[260];
      if (!dump_tried && GetEnvironmentVariableA("GTA_AUDIO_DUMP", path, sizeof(path))) {
          dump_tried = 1;
          g_dump = fopen(path, "wb");
          if (g_dump) {
              wav_stamp(g_dump, 0);
              fprintf(stderr, "  MIXER: writing mix to %s\n", path);
          }
      } }
    g_running = 1;
    g_thread = CreateThread(NULL, 0, mixer_thread, NULL, 0, NULL);
    fprintf(stderr, "  MIXER: waveOut %d Hz %d-bit stereo, %d buffers of %d frames\n",
            MIXER_RATE, 16, NUM_BUFS, FRAMES_PER_BUF);
    return 1;
}

void mixer_shutdown(void) {
    int i;
    if (!g_running) return;
    g_running = 0;
    SetEvent(g_event);
    WaitForSingleObject(g_thread, 500);
    waveOutReset(g_dev);
    for (i = 0; i < NUM_BUFS; i++) {
        waveOutUnprepareHeader(g_dev, &g_hdr[i], sizeof(WAVEHDR));
        free(g_buf[i]);
        g_buf[i] = NULL;
    }
    if (g_dump) {
        wav_stamp(g_dump, g_dump_bytes);       /* keep it open: MSS restarts */
        fprintf(stderr, "  MIXER: mix dump now %u bytes\n", g_dump_bytes);
    }
    waveOutClose(g_dev);
    CloseHandle(g_event);
    DeleteCriticalSection(&g_lock);
}
#else
int  mixer_init(void)     { return 0; }
void mixer_shutdown(void) { }
#endif

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
            g_voice[i].rate   = MIXER_RATE;
            g_voice[i].bits   = 16;
            g_voice[i].channels = 1;
            g_voice[i].loop   = 1;
            UNLOCK();
            return i;
        }
    }
    UNLOCK();
    return -1;
}

static Voice *get(int v) {
    if (v < 0 || v >= MIXER_VOICES || !g_voice[v].allocated) return NULL;
    return &g_voice[v];
}

void mixer_voice_free(int v) {
    Voice *x;
    LOCK();
    if ((x = get(v))) memset(x, 0, sizeof(Voice));
    UNLOCK();
}

void mixer_voice_set_pcm(int v, const void *pcm, u32 bytes, int rate, int bits,
                         int channels, int is_signed) {
    Voice *x;
    LOCK();
    if ((x = get(v))) {
        x->pcm      = (const unsigned char *)pcm;
        x->bytes    = bytes;
        if (rate > 0)     x->rate = rate;
        if (bits == 8 || bits == 16) x->bits = bits;
        if (channels == 1 || channels == 2) x->channels = channels;
        x->is_signed = is_signed;
        x->pos = 0;
    }
    UNLOCK();
}

void mixer_voice_set_volume(int v, int vol) {
    Voice *x;
    LOCK();
    if ((x = get(v))) x->volume = vol < 0 ? 0 : (vol > 127 ? 127 : vol);
    UNLOCK();
}

void mixer_voice_set_pan(int v, int pan) {
    Voice *x;
    LOCK();
    if ((x = get(v))) x->pan = pan < 0 ? 0 : (pan > 127 ? 127 : pan);
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

u32 mixer_voice_position(int v) {
    Voice *x;
    u32 r = 0;
    LOCK();
    if ((x = get(v)))
        r = (x->pos >> FRAC_BITS) * (u32)x->channels * (u32)(x->bits / 8);
    UNLOCK();
    return r;
}

void mixer_set_master_volume(int vol) {
    g_master = vol < 0 ? 0 : (vol > 127 ? 127 : vol);
}

/* ===== WAV loading =====
 *
 * Chunk-walking rather than assuming a 44-byte header: the game's tracks are
 * plain RIFF/WAVE but nothing guarantees fmt is first or that there is no LIST.
 */
void *mixer_load_wav(const char *path, u32 *bytes, int *rate, int *bits, int *channels) {
    FILE *f = fopen(path, "rb");
    unsigned char hdr[12], ch[8];
    void *pcm = NULL;
    int have_fmt = 0;

    if (!f) return NULL;
    if (fread(hdr, 1, 12, f) != 12 || memcmp(hdr, "RIFF", 4) || memcmp(hdr + 8, "WAVE", 4)) {
        fclose(f);
        return NULL;
    }

    while (fread(ch, 1, 8, f) == 8) {
        u32 size = (u32)ch[4] | ((u32)ch[5] << 8) | ((u32)ch[6] << 16) | ((u32)ch[7] << 24);
        if (!memcmp(ch, "fmt ", 4)) {
            unsigned char fmt[16];
            u32 want = size < sizeof(fmt) ? size : sizeof(fmt);
            if (fread(fmt, 1, want, f) != want) break;
            *channels = fmt[2] | (fmt[3] << 8);
            *rate     = (int)((u32)fmt[4] | ((u32)fmt[5] << 8) | ((u32)fmt[6] << 16) | ((u32)fmt[7] << 24));
            *bits     = fmt[14] | (fmt[15] << 8);
            have_fmt  = 1;
            if (size > want) fseek(f, (long)(size - want), SEEK_CUR);
        } else if (!memcmp(ch, "data", 4) && have_fmt) {
            pcm = malloc(size ? size : 1);
            if (pcm && fread(pcm, 1, size, f) == size) *bytes = size;
            else { free(pcm); pcm = NULL; }
            break;
        } else {
            fseek(f, (long)size + (size & 1), SEEK_CUR);
        }
    }
    fclose(f);
    return pcm;
}

void mixer_free_wav(void *pcm) {
    free(pcm);
}
