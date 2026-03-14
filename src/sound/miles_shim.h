#ifndef GTA_MILES_SHIM_H
#define GTA_MILES_SHIM_H

/*
 * Miles Sound System (MSS32.DLL) shim layer.
 *
 * Replaces RAD Game Tools Miles Sound System with SDL2 audio.
 * GTA1 imports 38 AIL_ functions from mss32.dll for:
 *   - Digital audio playback (samples)
 *   - Streaming audio (music tracks)
 *   - Timer management
 *   - Memory allocation
 *   - Volume/pan/pitch control
 *
 * Only 4 game functions directly call MSS -- very clean separation.
 */

#include "../common/types.h"

/* Opaque handle types matching MSS API */
typedef void *HDIGDRIVER;      /* Digital audio driver handle */
typedef void *HSAMPLE;         /* Sample handle */
typedef void *HSTREAM;         /* Stream handle */
typedef void *HTIMER;          /* Timer handle */
typedef void *HPROVIDER;       /* Provider handle */

/* Stream status values */
#define SMP_FREE      0
#define SMP_DONE      1
#define SMP_PLAYING   2
#define SMP_STOPPED   3
#define SMP_PAUSED    4

/* --- Core lifecycle --- */
u32  AIL_startup(void);
void AIL_shutdown(void);

/* --- Digital driver --- */
s32  AIL_waveOutOpen(HDIGDRIVER *pDig, void *hWndApp, s32 wDeviceID, void *pWaveFormat);
void AIL_waveOutClose(HDIGDRIVER dig);
s32  AIL_digital_configuration(HDIGDRIVER dig, s32 *pRate, s32 *pBits, s32 *pChannels);

/* --- Sample playback --- */
HSAMPLE AIL_allocate_sample_handle(HDIGDRIVER dig);
void    AIL_release_sample_handle(HSAMPLE s);
void    AIL_init_sample(HSAMPLE s);
void    AIL_set_sample_file(HSAMPLE s, void *file_image, s32 block);
void    AIL_set_sample_address(HSAMPLE s, void *start, u32 len);
void    AIL_set_sample_type(HSAMPLE s, s32 format, u32 flags);
void    AIL_set_sample_playback_rate(HSAMPLE s, s32 rate);
void    AIL_set_sample_volume(HSAMPLE s, s32 volume);
void    AIL_set_sample_pan(HSAMPLE s, s32 pan);
void    AIL_set_sample_loop_count(HSAMPLE s, s32 count);
void    AIL_start_sample(HSAMPLE s);
void    AIL_stop_sample(HSAMPLE s);
void    AIL_end_sample(HSAMPLE s);
void    AIL_resume_sample(HSAMPLE s);
s32     AIL_sample_status(HSAMPLE s);
s32     AIL_sample_playback_rate(HSAMPLE s);
s32     AIL_sample_volume(HSAMPLE s);
s32     AIL_sample_pan(HSAMPLE s);

/* --- Streaming audio --- */
HSTREAM AIL_open_stream(HDIGDRIVER dig, const char *filename, s32 stream_mem);
void    AIL_close_stream(HSTREAM stream);
void    AIL_pause_stream(HSTREAM stream, s32 onoff);
void    AIL_start_stream(HSTREAM stream);
s32     AIL_stream_status(HSTREAM stream);
void    AIL_set_stream_loop_count(HSTREAM stream, s32 count);
void    AIL_set_stream_volume(HSTREAM stream, s32 volume);
void    AIL_set_stream_pan(HSTREAM stream, s32 pan);
s32     AIL_stream_position(HSTREAM stream);
void    AIL_stream_info(HSTREAM stream, s32 *datarate, s32 *sndtype, s32 *length, s32 *memory);

/* --- Master volume --- */
void AIL_set_digital_master_volume(HDIGDRIVER dig, s32 volume);
s32  AIL_digital_master_volume(HDIGDRIVER dig);

/* --- Timers --- */
HTIMER AIL_register_timer(void (*callback)(u32 user));
void   AIL_release_timer_handle(HTIMER timer);
void   AIL_set_timer_period(HTIMER timer, u32 microseconds);
void   AIL_set_timer_user(HTIMER timer, u32 user);
void   AIL_start_timer(HTIMER timer);
void   AIL_stop_timer(HTIMER timer);

/* --- Memory --- */
void *AIL_mem_alloc_lock(u32 size);
void  AIL_mem_free_lock(void *ptr);

/* --- Utility --- */
u32 AIL_ms_count(void);

#endif /* GTA_MILES_SHIM_H */
