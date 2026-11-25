/* gta_mss.c -- the Miles Sound System (mss32.dll) the game imports, answered
 * by the native macOS host.
 *
 * Ported from src/sound/miles_shim.c (the Windows host's shim), on the mixer
 * gta_mixer.c ports: samples mix from the game's own memory, the radio's
 * streams load from the game's WAVs, timers fire the guest callback, and
 * AIL_ms_count returns a moving clock (the frame limiter busy-waits on it).
 *
 * The shim ABI is win32hle's: when a shim is entered, g_esp points at
 * [ret][arg0][arg1]..., arguments are read with A32/ASTR and the shim
 * returns with RET(eax, argc), which pops ret + argc*4 (stdcall, callee
 * cleans). The shims run under the machine lock; the mixer's own lock is
 * only ever held briefly around a voice, and the SDL audio thread never
 * touches the machine, so the two never nest.
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>

#include "win32hle.h"
#include "gta_mixer.h"

#define MAX_MSS_SAMPLES  48
#define MAX_MSS_STREAMS  4
#define MAX_MSS_TIMERS   8

/* Miles's own values (mss.h): bit flags, and the game compares them --
 * GTA1 reads 4 as "playing", GTA2 reads 2 as "done". Miles has no paused
 * status: a paused sample or stream reports stopped. */
#define SMP_FREE      0x0001
#define SMP_DONE      0x0002
#define SMP_PLAYING   0x0004
#define SMP_STOPPED   0x0008
#define SMP_PAUSED    SMP_STOPPED

typedef struct {
    int active;
    int status;
    int was_playing;
    const void *data;        /* the game's own PCM, guest memory */
    uint32_t data_len;
    int rate, bits, channels, is_signed;
    int volume, pan;
    int loop_count;
    int32_t loop_start, loop_end;   /* AIL_set_sample_loop_block, bytes; end -1 = the end */
    int voice;               /* mixer voice, or -1 */
} MSS_Sample;

typedef struct {
    int active;
    int status;
    char filename[260];
    int volume, pan;
    int loop_count;
    int paused;
    int voice;               /* mixer voice, or -1 */
    void *pcm;               /* decoded WAV, owned */
    uint32_t pcm_bytes;
    uint32_t byte_rate;      /* bytes per second, from the WAV header */
    int rate;                /* the playback rate, Hz (AIL_set_stream_playback_rate) */
    uint32_t dig_format;     /* DIG_F_*: bit 0 16-bit, bit 1 stereo */
} MSS_Stream;

typedef struct {
    int      active;
    uint32_t cb;             /* the guest callback VA */
    uint32_t user;
    long     period_us;
    int      running;
    pthread_t th;
} MSS_Timer;

static MSS_Sample g_samples[MAX_MSS_SAMPLES];
static MSS_Stream g_streams[MAX_MSS_STREAMS];
static MSS_Timer  g_timers[MAX_MSS_TIMERS];
static int g_mss_up;
static uint32_t g_ms_base;  /* host ms at AIL_startup */
static uint32_t g_next_sample = 1;
static int g_master_volume = 127;

/* ---- lifecycle ---- */

static void mss_AIL_startup(void) {
    if (!g_mss_up) {
        g_ms_base = hle_ticks_ms();
        memset(g_timers, 0, sizeof g_timers);
        memset(g_samples, 0, sizeof g_samples);
        memset(g_streams, 0, sizeof g_streams);
        g_mss_up = 1;
        mixer_init();
    }
    RET(1, 0);               /* success */
}

static void mss_AIL_shutdown(void) {
    if (g_mss_up) {
        for (int i = 0; i < MAX_MSS_TIMERS; i++) {
            g_timers[i].active = 0;
            if (g_timers[i].running) pthread_join(g_timers[i].th, NULL);
            g_timers[i].running = 0;
        }
        for (int i = 0; i < MAX_MSS_STREAMS; i++) {
            if (g_streams[i].active) {
                if (g_streams[i].voice >= 0) { mixer_voice_stop(g_streams[i].voice); mixer_voice_free(g_streams[i].voice); }
                mixer_free_wav(g_streams[i].pcm);
                memset(&g_streams[i], 0, sizeof g_streams[i]);
            }
        }
        for (int i = 0; i < MAX_MSS_SAMPLES; i++)
            if (g_samples[i].voice >= 0) mixer_voice_free(g_samples[i].voice);
        memset(g_samples, 0, sizeof g_samples);
        mixer_shutdown();
        g_mss_up = 0;
    }
    RET(0, 0);
}

static void mss_AIL_ms_count(void) {
    static uint32_t n, tick;
    if (getenv("GTA_TRACE") && ++n >= 1) {
        uint32_t now = hle_ticks_ms();
        if (now - tick >= 1000) {
            fprintf(stderr, "[mss] ms_count %u calls/s (spin: %s)\n", n, n > 1000 ? "yes" : "no");
            tick = now, n = 0;
        }
    }
    RET(hle_ticks_ms() - g_ms_base, 0);
}

/* ---- timers: the callback runs in the guest, on a host thread --------- */

/* Absolute scheduling: the callback is due at next, and next advances by
 * exactly the period, so the guest's tick count rises at exactly the
 * frequency asked for. A plain sleep(period)-then-fire loop accumulates the
 * callback's own cost into the period, and GTA's frame limiter is a spin on
 * this counter -- any drift lands on the frame pacing, and the picture
 * judders however fast the host is. The clock is in microseconds: GTA1 asks
 * for 70 Hz and waits three ticks a frame in the city, and a period rounded
 * up to whole milliseconds (15 ms, not 14.286) ran the game at 66.7 Hz, 5%
 * slow -- 22.2 frames a second instead of the original 23.3. */
static int64_t now_us(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
}
static void *timer_thread(void *arg) {
    MSS_Timer *t = arg;
    int64_t next = now_us() + t->period_us;
    while (t->active) {
        int64_t now = now_us();
        if (next > now) {
            struct timespec w = { (time_t)((next - now) / 1000000), (long)((next - now) % 1000000) * 1000 };
            nanosleep(&w, NULL);
            continue;
        }
        if (next < now - 1000000) next = now;     /* the machine was held a long while: resynchronise */
        hle_call_guest(t->cb, 1, &t->user);
        next += t->period_us > 0 ? t->period_us : 1000;
    }
    return NULL;
}

static MSS_Timer *timer_get(uint32_t handle) {
    uint32_t i = handle - 1;
    return (i < MAX_MSS_TIMERS && g_timers[i].active) ? &g_timers[i] : NULL;
}

static void mss_AIL_register_timer(void) {
    uint32_t cb = A32(0);
    for (int i = 0; i < MAX_MSS_TIMERS; i++) {
        if (!g_timers[i].active) {
            memset(&g_timers[i], 0, sizeof(MSS_Timer));
            g_timers[i].active = 1;
            g_timers[i].cb = cb;
            g_timers[i].period_us = 1000000;      /* default 1 Hz */
            RET((uint32_t)(i + 1), 1);
        }
    }
    RET(0, 1);
}

static void mss_AIL_set_timer_frequency(void) {
    MSS_Timer *t = timer_get(A32(0));
    uint32_t hz = A32(1);
    if (t && hz) t->period_us = (long)(1000000.0 / hz + 0.5);
    if (getenv("GTA_TRACE")) fprintf(stderr, "[mss] timer %u -> %u Hz (%ld us)\n", A32(0), hz, t ? t->period_us : 0);
    RET(0, 2);
}

static void mss_AIL_start_timer(void) {
    MSS_Timer *t = timer_get(A32(0));
    if (t && !t->running) {
        t->running = 1;
        if (pthread_create(&t->th, NULL, timer_thread, t) != 0)
            t->running = 0;
    }
    RET(0, 1);
}

static void mss_AIL_stop_timer(void) {
    MSS_Timer *t = timer_get(A32(0));
    if (t) {
        t->active = 0;
        if (t->running) { pthread_join(t->th, NULL); t->running = 0; }
        t->active = 1;                            /* stop, not release: restartable */
    }
    RET(0, 1);
}

static void mss_AIL_release_timer_handle(void) {
    MSS_Timer *t = timer_get(A32(0));
    if (t) {
        t->active = 0;
        if (t->running) { pthread_join(t->th, NULL); t->running = 0; }
        memset(t, 0, sizeof *t);
    }
    RET(0, 1);
}

/* ---- memory ---- */

static void mss_AIL_mem_alloc_lock(void) {
    uint32_t n = A32(0);
    void *p = n ? hle_alloc(n) : NULL;            /* guest memory */
    RET((uint32_t)(uintptr_t)p, 1);
}

static void mss_AIL_mem_free_lock(void) {
    RET(0, 1);   /* the guest block goes with the heap */
}

/* ---- digital driver ---- */

static void mss_AIL_waveOutOpen(void) {
    /* Return a non-null driver handle (arg 0 is HDIGDRIVER*): the game
     * tests it before every sound call. */
    if (A32(0)) MEM32(A32(0)) = 0x44494700u;
    RET(0, 4);
}

static void mss_AIL_waveOutClose(void) {
    RET(0, 1);
}

static void mss_AIL_digital_configuration(void) {
    /* (dig, *rate, *bits, *channels): the mixer's own format. */
    if (A32(1)) MEM32(A32(1)) = MIXER_RATE;
    if (A32(2)) MEM32(A32(2)) = 16;
    if (A32(3)) MEM32(A32(3)) = MIXER_CHANNELS;
    RET(1, 4);
}

static void mss_AIL_set_digital_master_volume(void) {
    g_master_volume = (int32_t)A32(1);
    mixer_set_master_volume((int32_t)A32(1));
    RET(0, 2);
}

static void mss_AIL_set_preference(void) {
    if (getenv("GTA_TRACE")) fprintf(stderr, "[mss] set_preference(0x%X, 0x%X)\n", A32(0), A32(1));
    RET(0, 2);   /* the previous value: 0 is fine for every preference set at boot */
}

/* ---- samples: the game's sound effects, mixed from its own memory ----- */

static MSS_Sample *sample_get(uint32_t h) {
    uint32_t i = h - 1;
    return (i < MAX_MSS_SAMPLES && g_samples[i].active) ? &g_samples[i] : NULL;
}

static void sample_push(MSS_Sample *smp) {
    if (!smp || smp->voice < 0) return;
    mixer_voice_set_pcm(smp->voice, smp->data, smp->data_len,
                        smp->rate, smp->bits, smp->channels, smp->is_signed);
    mixer_voice_set_volume(smp->voice, smp->volume);
    mixer_voice_set_pan(smp->voice, smp->pan);
    mixer_voice_set_loop(smp->voice, smp->loop_count);
    mixer_voice_set_loop_block(smp->voice, smp->loop_start, smp->loop_end);
}

static uint32_t sample_alloc(void) {
    for (int i = 0; i < MAX_MSS_SAMPLES; i++) {
        if (!g_samples[i].active) {
            memset(&g_samples[i], 0, sizeof(MSS_Sample));
            g_samples[i].active = 1;
            g_samples[i].status = SMP_DONE;      /* Miles: allocated, never started */
            g_samples[i].loop_end = -1;
            g_samples[i].volume = 127;
            g_samples[i].pan = 64;
            g_samples[i].rate = 22050;
            g_samples[i].bits = 8;        /* Miles default until set_sample_type */
            g_samples[i].channels = 1;
            g_samples[i].voice = mixer_voice_alloc();
            return (uint32_t)(i + 1);
        }
    }
    (void)g_next_sample;
    return 0;
}

static void mss_AIL_allocate_sample_handle(void) { RET(sample_alloc(), 1); }

static void sample_free(MSS_Sample *smp) {
    if (smp->voice >= 0) { mixer_voice_stop(smp->voice); mixer_voice_free(smp->voice); smp->voice = -1; }
    smp->active = 0;
    smp->status = SMP_FREE;
}

static void sample_start(MSS_Sample *smp) {
    smp->status = SMP_PLAYING;
    smp->was_playing = 1;
    sample_push(smp);
    if (mixer_trace_enabled())
        fprintf(stderr, "[mss] start_sample data=%p len=%u %dHz %dbit %dch vol=%d\n",
                smp->data, smp->data_len, smp->rate, smp->bits, smp->channels, smp->volume);
    if (smp->voice >= 0) mixer_voice_start(smp->voice);
}

static void sample_end(MSS_Sample *smp) {
    smp->status = SMP_DONE;
    smp->was_playing = 0;
    if (smp->voice >= 0) mixer_voice_stop(smp->voice);
}

static uint32_t sample_status(MSS_Sample *smp) {
    if (smp->was_playing && smp->voice >= 0 && !mixer_voice_playing(smp->voice)) {
        smp->was_playing = 0;
        smp->status = SMP_DONE;
    }
    return (uint32_t)smp->status;
}

static void mss_AIL_release_sample_handle(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) sample_free(smp);
    RET(0, 1);
}

static void mss_AIL_init_sample(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->status = SMP_DONE;
        smp->data = NULL;
        smp->data_len = 0;
        smp->loop_count = 1;
        smp->loop_start = 0, smp->loop_end = -1;
        if (smp->voice >= 0) mixer_voice_stop(smp->voice);
    }
    RET(0, 1);
}

static void mss_AIL_set_sample_address(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->data = hle_ptr(A32(1));              /* the game's own PCM */
        smp->data_len = A32(2);
        sample_push(smp);
    }
    RET(0, 3);
}

/* Miles DIG_F_: 0 mono 8, 1 mono 16, 2 stereo 8, 3 stereo 16. */
#define DIG_PCM_SIGN 0x0001u

static void mss_AIL_set_sample_type(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->bits     = (A32(1) & 1) ? 16 : 8;
        smp->channels = (A32(1) & 2) ? 2 : 1;
        /* DIG_PCM_SIGN. GTA1's banks are signed 8-bit; taking them as offset
         * binary turns 0x00 -- digital silence -- into full-scale output. */
        smp->is_signed = (A32(2) & DIG_PCM_SIGN) != 0;
        sample_push(smp);
        if (mixer_trace_enabled())
            fprintf(stderr, "[mss] sample_type format=%u flags=0x%X -> %dbit %dch %s\n",
                    A32(1), A32(2), smp->bits, smp->channels, smp->is_signed ? "signed" : "unsigned");
    }
    RET(0, 3);
}

static void mss_AIL_set_sample_playback_rate(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->rate = (int32_t)A32(1);
        if (smp->voice >= 0) mixer_voice_set_rate(smp->voice, smp->rate);
    }
    RET(0, 2);
}

static void mss_AIL_set_sample_volume(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->volume = (int32_t)A32(1);
        if (smp->voice >= 0) mixer_voice_set_volume(smp->voice, smp->volume);
    }
    RET(0, 2);
}

static void mss_AIL_set_sample_pan(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->pan = (int32_t)A32(1);
        if (smp->voice >= 0) mixer_voice_set_pan(smp->voice, smp->pan);
    }
    RET(0, 2);
}

static void mss_AIL_set_sample_loop_count(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->loop_count = (int32_t)A32(1);
        if (smp->voice >= 0) mixer_voice_set_loop(smp->voice, smp->loop_count);
    }
    RET(0, 2);
}

static void mss_AIL_start_sample(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) sample_start(smp);
    RET(0, 1);
}

static void mss_AIL_end_sample(void) {
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) sample_end(smp);
    RET(0, 1);
}

static void mss_AIL_set_sample_loop_block(void) {     /* (sample, start offset, end offset) */
    MSS_Sample *smp = sample_get(A32(0));
    if (smp) {
        smp->loop_start = (int32_t)A32(1), smp->loop_end = (int32_t)A32(2);
        if (smp->voice >= 0) mixer_voice_set_loop_block(smp->voice, smp->loop_start, smp->loop_end);
    }
    RET(0, 3);
}

static void mss_AIL_sample_status(void) {
    MSS_Sample *smp = sample_get(A32(0));
    RET(smp ? sample_status(smp) : SMP_FREE, 1);
}

/* ---- streams: the radio's ten tracks, loaded from the game's WAVs ------ */

static MSS_Stream *stream_get(uint32_t h) {
    uint32_t i = h - 1;
    return (i < MAX_MSS_STREAMS && g_streams[i].active) ? &g_streams[i] : NULL;
}

static void mss_AIL_open_stream(void) {
    for (int i = 0; i < MAX_MSS_STREAMS; i++) {
        if (!g_streams[i].active) {
            const char *filename = ASTR(1);       /* (dig, filename, stream_mem) */
            memset(&g_streams[i], 0, sizeof(MSS_Stream));
            g_streams[i].active = 1;
            g_streams[i].status = SMP_STOPPED;
            g_streams[i].volume = 127;
            g_streams[i].pan = 64;
            g_streams[i].loop_count = 1;
            g_streams[i].voice = -1;
            if (filename) {
                char host[1024];
                int rate = MIXER_RATE, bits = 16, chans = MIXER_CHANNELS;
                uint32_t nbytes = 0;
                snprintf(g_streams[i].filename, sizeof g_streams[i].filename, "%s", filename);
                if (hle_host_path(filename, host, sizeof host))
                    g_streams[i].pcm = mixer_load_wav(host, &nbytes, &rate, &bits, &chans);
                if (g_streams[i].pcm) {
                    g_streams[i].pcm_bytes = nbytes;
                    g_streams[i].byte_rate = (uint32_t)(rate * (bits / 8) * chans);
                    g_streams[i].rate = rate;
                    g_streams[i].dig_format = (bits == 16 ? 1u : 0u) | (chans == 2 ? 2u : 0u);
                    g_streams[i].voice = mixer_voice_alloc();
                    if (g_streams[i].voice >= 0)
                        mixer_voice_set_pcm(g_streams[i].voice, g_streams[i].pcm,
                                            nbytes, rate, bits, chans, 0);
                }
                fprintf(stderr, "[mss] stream %s '%s' (%u bytes, %d Hz %d-bit %dch)\n",
                        g_streams[i].pcm ? "loaded" : "FAILED", filename, nbytes, rate, bits, chans);
            }
            RET((uint32_t)(i + 1), 3);
        }
    }
    RET(0, 3);
}

static void mss_AIL_close_stream(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (str) {
        if (str->voice >= 0) { mixer_voice_stop(str->voice); mixer_voice_free(str->voice); }
        mixer_free_wav(str->pcm);
        str->pcm = NULL;
        str->voice = -1;
        str->active = 0;
        str->status = SMP_FREE;
    }
    RET(0, 1);
}

static void mss_AIL_start_stream(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (str) {
        str->status = SMP_PLAYING;
        str->paused = 0;
        if (str->voice >= 0) {
            mixer_voice_set_volume(str->voice, str->volume);
            mixer_voice_set_pan(str->voice, str->pan);
            mixer_voice_set_loop(str->voice, str->loop_count);
            mixer_voice_start(str->voice);
        }
    }
    RET(0, 1);
}

static void mss_AIL_pause_stream(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (str) {
        str->paused = (int32_t)A32(1);
        if (str->voice >= 0) {
            if (str->paused) mixer_voice_stop(str->voice);
            else             mixer_voice_start(str->voice);
        }
    }
    RET(0, 2);
}

static void mss_AIL_service_stream(void) {
    RET(0, 2);   /* the whole track is in memory: nothing to buffer */
}

static void mss_AIL_stream_status(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (!str) RET(SMP_FREE, 1);
    if (str->status == SMP_PLAYING && !str->paused &&
        str->voice >= 0 && !mixer_voice_playing(str->voice))
        str->status = SMP_DONE;
    RET((uint32_t)str->status, 1);
}

static void mss_AIL_stream_position(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (!str || str->voice < 0) RET(0, 1);
    RET(mixer_voice_position(str->voice), 1);
}

/* Miles: data rate in bytes per second, the DIG_F_ format, the length in
 * bytes and the buffer memory. GTA1 probes its ten radio tracks with this at
 * startup and treats a length below 1 as "no such track": answering 0 here
 * switched the radio off for the whole game. */
static void mss_AIL_stream_info(void) {
    MSS_Stream *st = stream_get(A32(0));
    if (A32(1)) MEM32(A32(1)) = st ? st->byte_rate : 0;
    if (A32(2)) MEM32(A32(2)) = st ? st->dig_format : 0;
    if (A32(3)) MEM32(A32(3)) = st ? st->pcm_bytes : 0;
    if (A32(4)) MEM32(A32(4)) = 0;
    RET(0, 5);
}

static void mss_AIL_set_stream_volume(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (str) {
        str->volume = (int32_t)A32(1);
        if (str->voice >= 0) mixer_voice_set_volume(str->voice, str->volume);
    }
    RET(0, 2);
}

static void mss_AIL_set_stream_loop_count(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (str) {
        str->loop_count = (int32_t)A32(1);
        if (str->voice >= 0) mixer_voice_set_loop(str->voice, str->loop_count);
    }
    RET(0, 2);
}

static void mss_AIL_set_stream_position(void) {
    MSS_Stream *str = stream_get(A32(0));
    int32_t offset = (int32_t)A32(1);
    if (str && str->voice >= 0 && offset >= 0 && (uint32_t)offset < str->pcm_bytes)
        mixer_voice_seek(str->voice, (uint32_t)offset);
    RET(0, 2);
}

/* ---- GTA2's: stream time and rate, and Miles' 3D ------------------------ */

static void mss_AIL_stream_volume(void) {
    MSS_Stream *str = stream_get(A32(0));
    RET(str ? (uint32_t)str->volume : 0, 1);
}

static void mss_AIL_stream_playback_rate(void) {
    MSS_Stream *str = stream_get(A32(0));
    RET(str ? (uint32_t)str->rate : 0, 1);
}

static void mss_AIL_set_stream_playback_rate(void) {
    MSS_Stream *str = stream_get(A32(0));
    if (str && (int32_t)A32(1) > 0) {
        str->rate = (int)A32(1);
        if (str->voice >= 0) mixer_voice_set_rate(str->voice, str->rate);
    }
    RET(0, 2);
}

static void mss_AIL_stream_ms_position(void) {            /* (stream, &total ms, &current ms) */
    MSS_Stream *str = stream_get(A32(0));
    uint32_t total = 0, cur = 0;
    if (str && str->byte_rate) {
        total = (uint32_t)((uint64_t)str->pcm_bytes * 1000u / str->byte_rate);
        if (str->voice >= 0) cur = (uint32_t)((uint64_t)mixer_voice_position(str->voice) * 1000u / str->byte_rate);
    }
    if (A32(1)) MEM32(A32(1)) = total;
    if (A32(2)) MEM32(A32(2)) = cur;
    RET(0, 3);
}

static void mss_AIL_set_stream_ms_position(void) {        /* (stream, ms) */
    MSS_Stream *str = stream_get(A32(0));
    if (str && str->voice >= 0 && str->byte_rate) {
        uint64_t at = (uint64_t)A32(1) * str->byte_rate / 1000u;
        uint32_t align = str->byte_rate / (uint32_t)(str->rate > 0 ? str->rate : 1);
        if (align) at -= at % align;
        if (at < str->pcm_bytes) mixer_voice_seek(str->voice, (uint32_t)at);
    }
    RET(0, 2);
}

static void mss_AIL_delay(void) {                         /* in 60ths of a second */
    uint32_t n = A32(0);
    if (n > 600) n = 600;
    hle_block_begin();
    struct timespec ts = { (time_t)(n / 60), (long)(n % 60) * (1000000000L / 60) };
    nanosleep(&ts, NULL);
    hle_block_end();
    RET(0, 1);
}

static void mss_AIL_digital_handle_release(void) { RET(1, 1); }
static void mss_AIL_digital_handle_reacquire(void) { RET(1, 1); }

/* Miles' 3D sound goes through a provider. GTA2 looks for the one it ships,
 * MSSDS3DH.M3D, by name ("Microsoft DirectSound3D hardware support"), asks
 * for 8 to 16 voices, and plays the world through them -- without one it
 * falls back to a thinner stereo path. So one is offered, in software: a 3D
 * sample is a 2D sample whose volume and pan follow its position, the
 * listener at the origin facing +z (Miles' default; GTA2 never moves it),
 * DirectSound3D's model -- full inside the minimum distance, 1/distance
 * past it, silent beyond the maximum. No EAX: the game asks, and goes
 * without. */
#define MAX_3D 16
#define H3D_BASE 0x3D00u
typedef struct {
    int active;
    uint32_t smp;                     /* the 2D sample underneath (handle) */
    int volume;                       /* the game's 0..127 */
    float x, y, z, min_d, max_d;
} S3D;
static S3D g_3d[MAX_3D];
static const char k_provider[] = "Microsoft DirectSound3D hardware support";
static uint32_t g_provider_name;

static S3D *s3d_get(uint32_t h) {
    uint32_t i = h - H3D_BASE;
    return i < MAX_3D && g_3d[i].active ? &g_3d[i] : NULL;
}
static void s3d_apply(S3D *t) {
    MSS_Sample *smp = sample_get(t->smp);
    if (!smp) return;
    float d = sqrtf(t->x * t->x + t->y * t->y + t->z * t->z);
    float gain = 1.0f;
    if (t->max_d > 0 && d > t->max_d) gain = 0;
    else if (d > t->min_d && t->min_d > 0) gain = t->min_d / d;
    float side = d > 0.001f ? t->x / (d > t->min_d ? d : (t->min_d > 0 ? t->min_d : d)) : 0;
    if (side > 1) side = 1;
    if (side < -1) side = -1;
    smp->volume = (int)((float)t->volume * gain + 0.5f);
    smp->pan = 64 + (int)(side * 50.0f);   /* DirectSound3D pans, it never isolates an ear */
    if (smp->voice >= 0) mixer_voice_set_volume(smp->voice, smp->volume), mixer_voice_set_pan(smp->voice, smp->pan);
    if (getenv("GTA_3D_TRACE"))
        fprintf(stderr, "[mss3d] %u at %.1f,%.1f,%.1f (min %.1f max %.1f) vol %d -> %d pan %d\n",
                t->smp, t->x, t->y, t->z, t->min_d, t->max_d, t->volume, smp->volume, smp->pan);
}

static void mss_AIL_enumerate_3D_providers(void) {        /* (&next, &provider, &name) -> more? */
    uint32_t next = A32(0) ? MEM32(A32(0)) : 1;
    if (next != 0) RET(0, 3);
    if (!g_provider_name) g_provider_name = hle_guest_strdup(k_provider);
    MEM32(A32(0)) = 1;
    if (A32(1)) MEM32(A32(1)) = 1;
    if (A32(2)) MEM32(A32(2)) = g_provider_name;
    RET(1, 3);
}
static void mss_AIL_open_3D_provider(void) { RET(A32(0) == 1 ? 0u : 1u, 1); }   /* M3D_NOERR, M3D_NOTFOUND */
static void mss_AIL_close_3D_provider(void) { RET(0, 1); }
static void mss_AIL_3D_provider_attribute(void) {         /* (provider, name, &value) */
    const char *name = A32(1) ? ASTR(1) : "";
    uint32_t v = 0;
    if (!strcmp(name, "Maximum supported samples")) v = MAX_3D;
    else if (!strncmp(name, "EAX", 3)) v = 0xFFFFFFFFu;   /* no EAX */
    if (A32(2)) MEM32(A32(2)) = v;
    RET(0, 3);
}
static void mss_AIL_set_3D_provider_preference(void) { RET(0, 3); }
static void mss_AIL_allocate_3D_sample_handle(void) {
    for (int i = 0; i < MAX_3D; i++) {
        if (g_3d[i].active) continue;
        uint32_t h = sample_alloc();
        if (!h) break;
        memset(&g_3d[i], 0, sizeof g_3d[i]);
        g_3d[i].active = 1, g_3d[i].smp = h, g_3d[i].volume = 127, g_3d[i].min_d = 1, g_3d[i].max_d = 1e9f;
        RET(H3D_BASE + (uint32_t)i, 1);
    }
    RET(0, 1);
}
#define S3D_SMP(t) ((t) ? sample_get((t)->smp) : NULL)
static void mss_AIL_release_3D_sample_handle(void) {
    S3D *t = s3d_get(A32(0));
    MSS_Sample *smp = S3D_SMP(t);
    if (smp) sample_free(smp);
    if (t) t->active = 0;
    RET(0, 1);
}
static void mss_AIL_set_3D_sample_info(void) {            /* (sample, AILSOUNDINFO *) -> success */
    MSS_Sample *smp = S3D_SMP(s3d_get(A32(0)));
    uint32_t info = A32(1);
    if (!smp || !info || MEM32(info) != 1) RET(0, 2);      /* WAVE_FORMAT_PCM only */
    smp->data = hle_ptr(MEM32(info + 4));
    smp->data_len = MEM32(info + 8);
    smp->rate = (int)MEM32(info + 12);
    smp->bits = MEM32(info + 16) == 16 ? 16 : 8;
    smp->channels = MEM32(info + 20) == 2 ? 2 : 1;
    smp->is_signed = 0;                                    /* WAV: 8-bit is offset binary */
    smp->loop_count = 1, smp->loop_start = 0, smp->loop_end = -1;
    sample_push(smp);
    RET(1, 2);
}
static void mss_AIL_start_3D_sample(void) { MSS_Sample *smp = S3D_SMP(s3d_get(A32(0))); if (smp) sample_start(smp); RET(0, 1); }
static void mss_AIL_end_3D_sample(void) { MSS_Sample *smp = S3D_SMP(s3d_get(A32(0))); if (smp) sample_end(smp); RET(0, 1); }
static void mss_AIL_3D_sample_status(void) { MSS_Sample *smp = S3D_SMP(s3d_get(A32(0))); RET(smp ? sample_status(smp) : SMP_FREE, 1); }
static void mss_AIL_set_3D_sample_loop_count(void) {
    MSS_Sample *smp = S3D_SMP(s3d_get(A32(0)));
    if (smp) { smp->loop_count = (int32_t)A32(1); if (smp->voice >= 0) mixer_voice_set_loop(smp->voice, smp->loop_count); }
    RET(0, 2);
}
static void mss_AIL_set_3D_sample_loop_block(void) {
    MSS_Sample *smp = S3D_SMP(s3d_get(A32(0)));
    if (smp) {
        smp->loop_start = (int32_t)A32(1), smp->loop_end = (int32_t)A32(2);
        if (smp->voice >= 0) mixer_voice_set_loop_block(smp->voice, smp->loop_start, smp->loop_end);
    }
    RET(0, 3);
}
static void mss_AIL_set_3D_sample_playback_rate(void) {
    MSS_Sample *smp = S3D_SMP(s3d_get(A32(0)));
    if (smp && (int32_t)A32(1) > 0) { smp->rate = (int32_t)A32(1); if (smp->voice >= 0) mixer_voice_set_rate(smp->voice, smp->rate); }
    RET(0, 2);
}
static float f32(uint32_t v) { float f; memcpy(&f, &v, 4); return f; }
static void mss_AIL_set_3D_sample_volume(void) {
    S3D *t = s3d_get(A32(0));
    if (t) t->volume = (int)A32(1), s3d_apply(t);
    RET(0, 2);
}
static void mss_AIL_set_3D_position(void) {               /* (object, x, y, z) */
    S3D *t = s3d_get(A32(0));
    if (t) t->x = f32(A32(1)), t->y = f32(A32(2)), t->z = f32(A32(3)), s3d_apply(t);
    RET(0, 4);
}
static void mss_AIL_set_3D_sample_float_distances(void) { /* (sample, max front, min front, max back, min back) */
    S3D *t = s3d_get(A32(0));
    if (t) t->max_d = f32(A32(1)), t->min_d = f32(A32(2)), s3d_apply(t);
    RET(0, 5);
}

/* The imports, by their stdcall-decorated names (GTA1's 38, GTA2's more). Registered before
 * win32hle's own mss module, so these win. */
const win32hle_shim gta_mss_shims[] = {
    { "_AIL_allocate_sample_handle@4",        mss_AIL_allocate_sample_handle },
    { "_AIL_close_stream@4",                  mss_AIL_close_stream },
    { "_AIL_digital_configuration@16",        mss_AIL_digital_configuration },
    { "_AIL_end_sample@4",                    mss_AIL_end_sample },
    { "_AIL_init_sample@4",                   mss_AIL_init_sample },
    { "_AIL_mem_alloc_lock@4",                mss_AIL_mem_alloc_lock },
    { "_AIL_mem_free_lock@4",                 mss_AIL_mem_free_lock },
    { "_AIL_ms_count@0",                      mss_AIL_ms_count },
    { "_AIL_open_stream@12",                  mss_AIL_open_stream },
    { "_AIL_pause_stream@8",                  mss_AIL_pause_stream },
    { "_AIL_register_timer@4",                mss_AIL_register_timer },
    { "_AIL_release_sample_handle@4",         mss_AIL_release_sample_handle },
    { "_AIL_release_timer_handle@4",          mss_AIL_release_timer_handle },
    { "_AIL_sample_status@4",                 mss_AIL_sample_status },
    { "_AIL_service_stream@8",                mss_AIL_service_stream },
    { "_AIL_set_digital_master_volume@8",     mss_AIL_set_digital_master_volume },
    { "_AIL_set_preference@8",                mss_AIL_set_preference },
    { "_AIL_set_sample_address@12",           mss_AIL_set_sample_address },
    { "_AIL_set_sample_loop_block@12",        mss_AIL_set_sample_loop_block },
    { "_AIL_set_sample_loop_count@8",         mss_AIL_set_sample_loop_count },
    { "_AIL_set_sample_pan@8",                mss_AIL_set_sample_pan },
    { "_AIL_set_sample_playback_rate@8",      mss_AIL_set_sample_playback_rate },
    { "_AIL_set_sample_type@12",              mss_AIL_set_sample_type },
    { "_AIL_set_sample_volume@8",             mss_AIL_set_sample_volume },
    { "_AIL_set_stream_loop_count@8",         mss_AIL_set_stream_loop_count },
    { "_AIL_set_stream_position@8",           mss_AIL_set_stream_position },
    { "_AIL_set_stream_volume@8",             mss_AIL_set_stream_volume },
    { "_AIL_set_timer_frequency@8",           mss_AIL_set_timer_frequency },
    { "_AIL_shutdown@0",                      mss_AIL_shutdown },
    { "_AIL_start_sample@4",                   mss_AIL_start_sample },
    { "_AIL_start_stream@4",                  mss_AIL_start_stream },
    { "_AIL_start_timer@4",                   mss_AIL_start_timer },
    { "_AIL_startup@0",                       mss_AIL_startup },
    { "_AIL_stop_timer@4",                    mss_AIL_stop_timer },
    { "_AIL_stream_info@20",                  mss_AIL_stream_info },
    { "_AIL_stream_position@4",              mss_AIL_stream_position },
    { "_AIL_stream_status@4",                mss_AIL_stream_status },
    { "_AIL_waveOutClose@4",                  mss_AIL_waveOutClose },
    { "_AIL_waveOutOpen@16",                  mss_AIL_waveOutOpen },
    { "_AIL_stream_volume@4",                 mss_AIL_stream_volume },
    { "_AIL_stream_playback_rate@4",          mss_AIL_stream_playback_rate },
    { "_AIL_set_stream_playback_rate@8",      mss_AIL_set_stream_playback_rate },
    { "_AIL_stream_ms_position@12",           mss_AIL_stream_ms_position },
    { "_AIL_set_stream_ms_position@8",        mss_AIL_set_stream_ms_position },
    { "_AIL_delay@4",                         mss_AIL_delay },
    { "_AIL_digital_handle_release@4",        mss_AIL_digital_handle_release },
    { "_AIL_digital_handle_reacquire@4",      mss_AIL_digital_handle_reacquire },
    { "_AIL_enumerate_3D_providers@12",       mss_AIL_enumerate_3D_providers },
    { "_AIL_open_3D_provider@4",              mss_AIL_open_3D_provider },
    { "_AIL_close_3D_provider@4",             mss_AIL_close_3D_provider },
    { "_AIL_3D_provider_attribute@12",        mss_AIL_3D_provider_attribute },
    { "_AIL_set_3D_provider_preference@12",   mss_AIL_set_3D_provider_preference },
    { "_AIL_allocate_3D_sample_handle@4",     mss_AIL_allocate_3D_sample_handle },
    { "_AIL_release_3D_sample_handle@4",      mss_AIL_release_3D_sample_handle },
    { "_AIL_start_3D_sample@4",               mss_AIL_start_3D_sample },
    { "_AIL_end_3D_sample@4",                 mss_AIL_end_3D_sample },
    { "_AIL_3D_sample_status@4",              mss_AIL_3D_sample_status },
    { "_AIL_set_3D_sample_loop_count@8",      mss_AIL_set_3D_sample_loop_count },
    { "_AIL_set_3D_sample_loop_block@12",     mss_AIL_set_3D_sample_loop_block },
    { "_AIL_set_3D_sample_playback_rate@8",   mss_AIL_set_3D_sample_playback_rate },
    { "_AIL_set_3D_sample_volume@8",          mss_AIL_set_3D_sample_volume },
    { "_AIL_set_3D_sample_info@8",            mss_AIL_set_3D_sample_info },
    { "_AIL_set_3D_position@16",              mss_AIL_set_3D_position },
    { "_AIL_set_3D_sample_float_distances@20", mss_AIL_set_3D_sample_float_distances },
    { 0, 0 }
};
