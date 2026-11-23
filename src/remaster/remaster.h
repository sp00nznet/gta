/* The remaster: settings, the presenter window, the resolution, the pad.
 * Everything here sits around the game's own code; --classic turns it off. */
#ifndef GTA_REMASTER_H
#define GTA_REMASTER_H
#include <stdint.h>

enum { SCALE_SHARP, SCALE_SMOOTH, SCALE_CRT, SCALE_NEAREST, SCALE_INTEGER, SCALE_COUNT };

typedef struct {
    int classic;        /* --classic: the original 640x480 window, GDI, no pad */
    int res_w, res_h;   /* the in-game resolution (the front end is always 640x480) */
    int scale;          /* SCALE_* */
    int fullscreen;     /* borderless */
    int pad;            /* Xbox controller */
    int view;           /* percent: 100 = the original zoom at any size (Hor+); less shows more city */
    int win_x, win_y, win_w, win_h;   /* the window's last place (0 = default) */
} remaster_t;

extern remaster_t g_rm;

/* settings.c */
void remaster_parse_args(int *argc, char **argv);   /* takes our --flags out of argv */
void remaster_save(void);

/* present.c: the frame as the game left it -- 8-bit indices with a palette,
 * or 16-bit 5-6-5 -- shown in our window. Returns 0 to fall back to GDI. */
int  present_frame(void *hwnd, const void *bits, int w, int h, int bpp, const void *pal_rgbx);

/* hires.c */
void hires_init(void);
int  hires_mode_count(void);
void hires_mode(int i, uint32_t *w, uint32_t *h);

/* pad.c */
void pad_start(void *hwnd);

#endif
