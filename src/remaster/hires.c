/* hires.c -- high resolution and widescreen for GTA1.
 *
 * GTA1 draws the city through a perspective camera whose scale follows the
 * screen width, and it takes whatever modes SciTech MGL (linked into the exe)
 * reports. Four things stood between it and a 16:9 screen:
 *
 *  1. MGL knows only the modes in its compiled-in tables of 0x4C-byte records
 *     (maxX, maxY, bits, pages, maxColor, .., aspect), one per mode number,
 *     and matches what DirectDraw enumerates against them (sub_00491B00).
 *     Eight 16-bit records the game has no use for (modes 0x29-0x30, 320x200
 *     to 640x400, which no current display lists) become the widescreen
 *     modes, before MGL registers anything; the DirectDraw shim lists them.
 *  2. The game builds its mode table (Options' list, 0x504CD0) from
 *     MGL_modeResolution (sub_0048B770), which answers from constants in its
 *     code: it is hooked to answer the new sizes. The builder kept only modes
 *     up to 1600 wide that are 4:3 or 16:10; tools/patch_gen.py lifts both.
 *  3. A game starts in the mode its table index says (sub_00414CC0); that is
 *     the settings' resolution now, so Options and F10 agree on what to use.
 *  4. The frame's row table held 1706 rows (g_rows_va below).
 *  5. The camera's scale is width * zoom / 320, which is Vert- (16:9 lost the
 *     top and bottom of the 4:3 picture), and any frame not 4:3 was squashed
 *     to 5/6 as if its pixels were 320x200's. See hires_view_width.
 *
 * GTA1's exe only: London's MGL sits elsewhere, and the check on the first
 * record keeps this from writing into anything else. --classic skips it all.
 */
#include <windows.h>
#include <stdio.h>
#define RECOMP_GENERATED_CODE
#include "../engine/recomp_runtime.h"
#include "remaster.h"

#define MGL_REC16      0x004B6180u   /* mode 0x29, 320x200x16 */
#define MGL_REC_SIZE   0x4Cu
#define MGL_FIRST16    0x29u
#define MGL_LAST16     0x37u         /* 1600x1200x16 */
#define GAME_MODES     0x00504CD0u   /* the game's mode table: 28-byte records, +0x18 -> {mode, w, h} */

static const struct { uint32_t w, h; } k_wide[8] = {      /* modes 0x29..0x30 */
    { 1280, 720 }, { 1366, 768 }, { 1600, 900 }, { 1920, 1080 },
    { 2560, 1080 }, { 2560, 1440 }, { 3440, 1440 }, { 3840, 2160 },
};
/* What the shim lists: 4:3 (MGL's own records), then widescreen. */
static const struct { uint32_t w, h; } k_modes[] = {
    { 640, 480 }, { 800, 600 }, { 1024, 768 }, { 1600, 1200 },
    { 1280, 720 }, { 1366, 768 }, { 1600, 900 }, { 1920, 1080 },
    { 2560, 1080 }, { 2560, 1440 }, { 3440, 1440 }, { 3840, 2160 },
};
#define NMODES ((int)(sizeof k_modes / sizeof k_modes[0]))

static int s_on;

/* The frame's row addresses (sub_00497BFA fills one per scanline). The game
 * kept them at 0x503228 with room for 1706 rows, and 2160 rows overwrote its
 * mode table; tools/patch_gen.py points every use here. Allocated whatever
 * the settings, since the patched code always reads it. */
#define MAX_ROWS 4096
#define ROW_SLACK 8192   /* rows either side: clipped sprites index above the top (-36 seen), as they read the game's globals before */
uint32_t g_rows_va = 0x00503228u;

void hires_init(void) {
    int i;
    void *rows = VirtualAlloc(NULL, (MAX_ROWS + 2 * ROW_SLACK) * 4, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (rows) g_rows_va = (uint32_t)(uintptr_t)rows + ROW_SLACK * 4;
    if (g_rm.classic) return;
    if (MEM32(MGL_REC16) != 319 || MEM32(MGL_REC16 + 4) != 199 || MEM32(MGL_REC16 + 8) != 16)
        return;                                  /* not GTA1's MGL */
    for (i = 0; i < 8; i++) {
        uint32_t r = MGL_REC16 + i * MGL_REC_SIZE;
        MEM32(r + 0) = k_wide[i].w - 1;
        MEM32(r + 4) = k_wide[i].h - 1;
        MEM32(r + 0x1C) = 1000;                  /* square pixels */
    }
    s_on = 1;
    fprintf(stderr, "[hires] widescreen modes 1280x720..3840x2160; in game %dx%d\n", g_rm.res_w, g_rm.res_h);
}

int hires_mode_count(void) { return s_on ? NMODES : 3; }
void hires_mode(int i, uint32_t *w, uint32_t *h) { *w = k_modes[i].w; *h = k_modes[i].h; }

/* sub_0048B770 MGL_modeResolution(mode, &x, &y, &bits): the new modes' sizes.
 * Returns 1 when it answered (the hook then returns 1 for the function). */
int hires_mode_resolution(void) {
    uint32_t m = MEM32(esp + 4);
    if (!s_on || m < MGL_FIRST16 || m >= MGL_FIRST16 + 8) return 0;
    MEM32(MEM32(esp + 8)) = k_wide[m - MGL_FIRST16].w;
    MEM32(MEM32(esp + 12)) = k_wide[m - MGL_FIRST16].h;
    MEM32(MEM32(esp + 16)) = 16;
    return 1;
}

/* sub_00414CC0(&index): the in-game mode change, by index into the game's
 * mode table. The front end calls it as a game starts with the index Options
 * chose; the settings' resolution wins if the table has it. */
void hires_on_change_mode(void) {
    uint32_t pidx = MEM32(esp + 4), tab = MEM32(GAME_MODES), k;
    if (!s_on || !pidx || !tab) return;
    for (k = 0; k < 64; k++) {
        uint32_t p = MEM32(tab + k * 28 + 0x18);
        if (!p) break;
        if ((int)MEM32(p + 4) == g_rm.res_w && (int)MEM32(p + 8) == g_rm.res_h) {
            if (MEM8(pidx) != k)
                fprintf(stderr, "[hires] in game: %dx%d (mode 0x%02X, the game's entry %u)\n",
                        g_rm.res_w, g_rm.res_h, MEM32(p), k);
            MEM8(pidx) = (uint8_t)k;
            return;
        }
    }
    fprintf(stderr, "[hires] %dx%d is not in the game's mode table: keeping its choice\n", g_rm.res_w, g_rm.res_h);
}

/* The in-game view (sub_00464500 sets it up from the screen size; 0x1BC bytes
 * per player from 0x74F160): +8 width, +0xC height, +0x24 the projection's
 * scale, +0x28 the camera's zoom, +0x2C "pixels are not square". Each frame
 * the camera (0x43BB10, 0x43C9A3) makes the scale width * zoom / 320.
 *
 * Hor+: tools/patch_gen.py has both read the width through this, which answers
 * the width a 4:3 frame of the same height would have. Every mode shows at
 * least what 640x480 shows, widescreen shows more of the city to the sides,
 * and view= below 100 zooms out further. 640x480 is exactly the original. */
uint32_t hires_view_width(uint32_t v) {
    uint32_t w = MEM32(v + 8), h = MEM32(v + 0xC);
    if (!s_on || !h) return w;
    MEM8(v + 0x2C) = 0;                          /* square pixels */
    return (uint32_t)(((uint64_t)h * 4 * (uint64_t)g_rm.view) / 300);
}
