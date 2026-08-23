/*
 * Miles Sound System shim -- SDL2 implementation
 *
 * Replaces mss32.dll (RAD Game Tools Miles Sound System) with SDL2 audio.
 * GTA1 uses MSS for all audio: music streaming, sound effects, and timers.
 */

#include "miles_shim.h"
#include "mixer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
static DWORD g_ms_base;   /* GetTickCount at AIL_startup */
#endif

#if HAS_SDL2
#include <SDL2/SDL.h>
#else
/* Stub SDL types when SDL2 is not available */
typedef u32 SDL_AudioDeviceID;
typedef u32 SDL_TimerID;
static u32 SDL_GetTicks(void) { return 0; }
static int SDL_InitSubSystem(u32 f) { return 0; }
static void SDL_QuitSubSystem(u32 f) {}
static SDL_TimerID SDL_AddTimer(u32 ms, void *cb, void *p) { return 0; }
static int SDL_RemoveTimer(SDL_TimerID t) { return 0; }
static const char *SDL_GetError(void) { return "SDL2 not available"; }
#define SDL_INIT_AUDIO 0
#define SDL_INIT_TIMER 0
#endif

/* --- Internal state --- */

#define MAX_SAMPLES  32
#define MAX_STREAMS  4
#define MAX_TIMERS   8

typedef struct {
    int active;
    int status;
    void *data;
    u32 data_len;
    s32 rate;
    s32 volume;    /* 0-127 */
    s32 pan;       /* 0(left) - 64(center) - 127(right) */
    s32 loop_count;
    SDL_AudioDeviceID device;
    int voice;          /* mixer voice, or -1 */
    int bits, channels; /* from AIL_set_sample_type */
    int was_playing;
} MSS_Sample;

typedef struct {
    int active;
    int status;
    char filename[260];
    s32 volume;
    s32 pan;
    s32 loop_count;
    int paused;
    int voice;          /* mixer voice, or -1 */
    void *pcm;          /* decoded WAV, owned */
    u32 pcm_bytes;
} MSS_Stream;

typedef struct {
    int active;
    void (*callback)(u32 user);
    u32 user;
    u32 period_us;
    SDL_TimerID sdl_timer;
} MSS_Timer;

static int g_mss_initialized = 0;
static s32 g_master_volume = 127;
static MSS_Sample g_samples[MAX_SAMPLES];
static MSS_Stream g_streams[MAX_STREAMS];
static MSS_Timer g_timers[MAX_TIMERS];

/* --- Core lifecycle --- */

u32 AIL_startup(void) {
    if (g_mss_initialized) return 1;

#ifdef _WIN32
    g_ms_base = GetTickCount();
#endif
    mixer_init();

    if (SDL_InitSubSystem(SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
        fprintf(stderr, "MSS shim: SDL audio init failed: %s\n", SDL_GetError());
        return 0;
    }

    memset(g_samples, 0, sizeof(g_samples));
    memset(g_streams, 0, sizeof(g_streams));
    memset(g_timers, 0, sizeof(g_timers));
    g_master_volume = 127;
    g_mss_initialized = 1;

    fprintf(stderr, "MSS shim: initialized (waveOut mixer)\n");
    return 1;
}

void AIL_shutdown(void) {
    mixer_shutdown();
    if (!g_mss_initialized) return;

    /* Stop all timers */
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (g_timers[i].active && g_timers[i].sdl_timer) {
            SDL_RemoveTimer(g_timers[i].sdl_timer);
        }
    }

    SDL_QuitSubSystem(SDL_INIT_AUDIO | SDL_INIT_TIMER);
    g_mss_initialized = 0;
    fprintf(stderr, "MSS shim: shutdown\n");
}

/* --- Digital driver --- */

s32 AIL_waveOutOpen(HDIGDRIVER *pDig, void *hWndApp, s32 wDeviceID, void *pWaveFormat) {
    /* Return a non-null handle */
    static int driver_handle = 1;
    if (pDig) *pDig = (HDIGDRIVER)(intptr_t)driver_handle;
    return 0; /* success */
}

void AIL_waveOutClose(HDIGDRIVER dig) {
    /* no-op */
}

s32 AIL_digital_configuration(HDIGDRIVER dig, s32 *pRate, s32 *pBits, s32 *pChannels) {
    if (pRate) *pRate = 22050;
    if (pBits) *pBits = 16;
    if (pChannels) *pChannels = 2;
    return 0;
}

/* --- Sample playback --- */

HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig) {
    for (int i = 0; i < MAX_SAMPLES; i++) {
        if (!g_samples[i].active) {
            memset(&g_samples[i], 0, sizeof(MSS_Sample));
            g_samples[i].active = 1;
            g_samples[i].status = SMP_FREE;
            g_samples[i].volume = 127;
            g_samples[i].pan = 64;
            g_samples[i].rate = 22050;
            g_samples[i].bits = 8;        /* Miles default until set_sample_type */
            g_samples[i].channels = 1;
            g_samples[i].voice = mixer_voice_alloc();
            return (HSAMPLE)(intptr_t)(i + 1);
        }
    }
    return NULL;
}

static MSS_Sample *get_sample(HSAMPLE s) {
    int idx = (int)(intptr_t)s - 1;
    if (idx < 0 || idx >= MAX_SAMPLES || !g_samples[idx].active) return NULL;
    return &g_samples[idx];
}

void AIL_release_sample_handle(HSAMPLE s) {
    { MSS_Sample *smp = get_sample(s);
      if (smp && smp->voice >= 0) { mixer_voice_free(smp->voice); smp->voice = -1; } }
    MSS_Sample *smp = get_sample(s);
    if (smp) {
        smp->active = 0;
        smp->status = SMP_FREE;
    }
}

void AIL_init_sample(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    if (smp) {
        smp->status = SMP_FREE;
        smp->data = NULL;
        smp->data_len = 0;
        smp->loop_count = 1;
    }
}

void AIL_set_sample_file(HSAMPLE s, void *file_image, s32 block) {
    MSS_Sample *smp = get_sample(s);
    if (smp) {
        smp->data = file_image;
        /* TODO: parse WAV header to get length */
    }
}

static void sample_push(MSS_Sample *smp) {
    if (!smp || smp->voice < 0) return;
    mixer_voice_set_pcm(smp->voice, smp->data, smp->data_len,
                        smp->rate, smp->bits, smp->channels);
    mixer_voice_set_volume(smp->voice, smp->volume);
    mixer_voice_set_pan(smp->voice, smp->pan);
    mixer_voice_set_loop(smp->voice, smp->loop_count);
}

void AIL_set_sample_address(HSAMPLE s, void *start, u32 len) {
    MSS_Sample *smp = get_sample(s);
    if (smp) {
        smp->data = start;
        smp->data_len = len;
        sample_push(smp);
    }
}

void AIL_set_sample_type(HSAMPLE s, s32 format, u32 flags) {
    /* Miles DIG_F_: 0 mono 8, 1 mono 16, 2 stereo 8, 3 stereo 16. */
    MSS_Sample *smp = get_sample(s);
    (void)flags;
    if (!smp) return;
    smp->bits     = (format & 1) ? 16 : 8;
    smp->channels = (format & 2) ? 2 : 1;
    sample_push(smp);
}

void AIL_set_sample_playback_rate(HSAMPLE s, s32 rate) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return;
    smp->rate = rate;
    if (smp->voice >= 0) mixer_voice_set_rate(smp->voice, rate);
}

void AIL_set_sample_volume(HSAMPLE s, s32 volume) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return;
    smp->volume = volume;
    if (smp->voice >= 0) mixer_voice_set_volume(smp->voice, volume);
}

void AIL_set_sample_pan(HSAMPLE s, s32 pan) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return;
    smp->pan = pan;
    if (smp->voice >= 0) mixer_voice_set_pan(smp->voice, pan);
}

void AIL_set_sample_loop_count(HSAMPLE s, s32 count) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return;
    smp->loop_count = count;
    if (smp->voice >= 0) mixer_voice_set_loop(smp->voice, count);
}

void AIL_start_sample(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    if (smp) {
        smp->status = SMP_PLAYING;
        smp->was_playing = 1;
        sample_push(smp);
        if (mixer_trace_enabled())
            fprintf(stderr, "MSS shim: start_sample voice=%d data=%p len=%u %dHz %dbit %dch vol=%d\n",
                smp->voice, smp->data, smp->data_len, (int)smp->rate,
                smp->bits, smp->channels, (int)smp->volume);
        if (smp->voice >= 0) mixer_voice_start(smp->voice);
    }
}

void AIL_stop_sample(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return;
    smp->status = SMP_STOPPED;
    if (smp->voice >= 0) mixer_voice_stop(smp->voice);
}

void AIL_end_sample(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return;
    smp->status = SMP_DONE;
    smp->was_playing = 0;
    if (smp->voice >= 0) mixer_voice_stop(smp->voice);
}

void AIL_resume_sample(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    if (smp && smp->status == SMP_STOPPED) smp->status = SMP_PLAYING;
}

s32 AIL_sample_status(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    if (!smp) return SMP_FREE;
    if (smp->was_playing && smp->voice >= 0 && !mixer_voice_playing(smp->voice)) {
        smp->was_playing = 0;
        smp->status = SMP_DONE;
    }
    return smp->status;
}

s32 AIL_sample_playback_rate(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    return smp ? smp->rate : 22050;
}

s32 AIL_sample_volume(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    return smp ? smp->volume : 0;
}

s32 AIL_sample_pan(HSAMPLE s) {
    MSS_Sample *smp = get_sample(s);
    return smp ? smp->pan : 64;
}

/* --- Streaming audio --- */

HSTREAM AIL_open_stream(HDIGDRIVER dig, const char *filename, s32 stream_mem) {
    for (int i = 0; i < MAX_STREAMS; i++) {
        if (!g_streams[i].active) {
            memset(&g_streams[i], 0, sizeof(MSS_Stream));
            g_streams[i].active = 1;
            g_streams[i].status = SMP_STOPPED;
            g_streams[i].volume = 127;
            g_streams[i].pan = 64;
            g_streams[i].loop_count = 1;
            g_streams[i].voice = -1;
            if (filename) {
                int rate = 22050, bits = 16, chans = 2;
                u32 nbytes = 0;
                strncpy(g_streams[i].filename, filename, sizeof(g_streams[i].filename) - 1);
                g_streams[i].pcm = mixer_load_wav(filename, &nbytes, &rate, &bits, &chans);
                if (g_streams[i].pcm) {
                    g_streams[i].pcm_bytes = nbytes;
                    g_streams[i].voice = mixer_voice_alloc();
                    if (g_streams[i].voice >= 0)
                        mixer_voice_set_pcm(g_streams[i].voice, g_streams[i].pcm,
                                            nbytes, rate, bits, chans);
                }
                fprintf(stderr, "MSS shim: stream %s (%u bytes, %d Hz %d-bit %dch)\n",
                        g_streams[i].pcm ? "loaded" : "FAILED", nbytes, rate, bits, chans);
            }
            fprintf(stderr, "MSS shim: open_stream '%s'\n", filename ? filename : "(null)");
            return (HSTREAM)(intptr_t)(i + 1);
        }
    }
    return NULL;
}

static MSS_Stream *get_stream(HSTREAM stream) {
    int idx = (int)(intptr_t)stream - 1;
    if (idx < 0 || idx >= MAX_STREAMS || !g_streams[idx].active) return NULL;
    return &g_streams[idx];
}

void AIL_close_stream(HSTREAM stream) {
    MSS_Stream *str = get_stream(stream);
    if (str) {
        if (str->voice >= 0) { mixer_voice_stop(str->voice); mixer_voice_free(str->voice); }
        mixer_free_wav(str->pcm);
        str->pcm = NULL;
        str->voice = -1;
        str->active = 0;
        str->status = SMP_FREE;
    }
}

void AIL_pause_stream(HSTREAM stream, s32 onoff) {
    MSS_Stream *str = get_stream(stream);
    if (!str) return;
    str->paused = onoff;
    if (str->voice >= 0) {
        if (onoff) mixer_voice_stop(str->voice);
        else       mixer_voice_start(str->voice);
    }
}

void AIL_start_stream(HSTREAM stream) {
    MSS_Stream *str = get_stream(stream);
    if (str) {
        str->status = SMP_PLAYING;
        str->paused = 0;
        if (str->voice >= 0) {
            mixer_voice_set_volume(str->voice, str->volume);
            mixer_voice_set_pan(str->voice, str->pan);
            mixer_voice_set_loop(str->voice, str->loop_count);
            mixer_voice_start(str->voice);
        }
        /* TODO: start SDL2 audio stream from file */
    }
}

s32 AIL_stream_status(HSTREAM stream) {
    MSS_Stream *str = get_stream(stream);
    if (!str) return SMP_FREE;
    if (str->status == SMP_PLAYING && !str->paused &&
        str->voice >= 0 && !mixer_voice_playing(str->voice))
        str->status = SMP_DONE;
    return str->status;
}

void AIL_set_stream_loop_count(HSTREAM stream, s32 count) {
    MSS_Stream *str = get_stream(stream);
    if (str) str->loop_count = count;
}

void AIL_set_stream_volume(HSTREAM stream, s32 volume) {
    MSS_Stream *str = get_stream(stream);
    if (!str) return;
    str->volume = volume;
    if (str->voice >= 0) mixer_voice_set_volume(str->voice, volume);
}

void AIL_set_stream_pan(HSTREAM stream, s32 pan) {
    MSS_Stream *str = get_stream(stream);
    if (str) str->pan = pan;
}

s32 AIL_stream_position(HSTREAM stream) {
    MSS_Stream *str = get_stream(stream);
    if (!str || str->voice < 0) return 0;
    return (s32)mixer_voice_position(str->voice);
}

void AIL_stream_info(HSTREAM stream, s32 *datarate, s32 *sndtype, s32 *length, s32 *memory) {
    if (datarate) *datarate = 22050;
    if (sndtype) *sndtype = 1; /* PCM */
    if (length) *length = 0;
    if (memory) *memory = 0;
}

/* --- Master volume --- */

void AIL_set_digital_master_volume(HDIGDRIVER dig, s32 volume) {
    (void)dig;
    g_master_volume = volume;
    mixer_set_master_volume(volume);
}

s32 AIL_digital_master_volume(HDIGDRIVER dig) {
    return g_master_volume;
}

/* --- Timers --- */

#if HAS_SDL2
static Uint32 timer_callback_wrapper(Uint32 interval, void *param) {
#else
static u32 timer_callback_wrapper(u32 interval, void *param) {
#endif
    MSS_Timer *t = (MSS_Timer *)param;
    if (t->callback) {
        t->callback(t->user);
    }
    return interval;
}

HTIMER AIL_register_timer(void (*callback)(u32 user)) {
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (!g_timers[i].active) {
            memset(&g_timers[i], 0, sizeof(MSS_Timer));
            g_timers[i].active = 1;
            g_timers[i].callback = callback;
            g_timers[i].period_us = 1000000; /* default 1 second */
            return (HTIMER)(intptr_t)(i + 1);
        }
    }
    return NULL;
}

static MSS_Timer *get_timer(HTIMER timer) {
    int idx = (int)(intptr_t)timer - 1;
    if (idx < 0 || idx >= MAX_TIMERS || !g_timers[idx].active) return NULL;
    return &g_timers[idx];
}

void AIL_release_timer_handle(HTIMER timer) {
    MSS_Timer *t = get_timer(timer);
    if (t) {
        if (t->sdl_timer) SDL_RemoveTimer(t->sdl_timer);
        t->active = 0;
    }
}

void AIL_set_timer_period(HTIMER timer, u32 microseconds) {
    MSS_Timer *t = get_timer(timer);
    if (t) t->period_us = microseconds;
}

void AIL_set_timer_user(HTIMER timer, u32 user) {
    MSS_Timer *t = get_timer(timer);
    if (t) t->user = user;
}

void AIL_start_timer(HTIMER timer) {
    MSS_Timer *t = get_timer(timer);
    if (t) {
        u32 ms = t->period_us / 1000;
        if (ms < 1) ms = 1;
        t->sdl_timer = SDL_AddTimer(ms, timer_callback_wrapper, t);
    }
}

void AIL_stop_timer(HTIMER timer) {
    MSS_Timer *t = get_timer(timer);
    if (t && t->sdl_timer) {
        SDL_RemoveTimer(t->sdl_timer);
        t->sdl_timer = 0;
    }
}

/* --- Memory --- */

void *AIL_mem_alloc_lock(u32 size) {
    return malloc(size);
}

void AIL_mem_free_lock(void *ptr) {
    free(ptr);
}

/* --- Utility --- */

u32 AIL_ms_count(void) {
    /*
     * Milliseconds since AIL_startup, from the host clock.
     *
     * Deliberately NOT SDL_GetTicks(): when SDL2 is absent the stub above
     * returns 0 forever, and the game busy-waits on this counter to pace
     * itself. It would load Liberty City and then spin here for good, which
     * looks exactly like a hang in the level loader. A millisecond counter has
     * no business depending on whether the audio library is available.
     */
#ifdef _WIN32
    return (u32)(GetTickCount() - g_ms_base);
#else
    return SDL_GetTicks();
#endif
}
