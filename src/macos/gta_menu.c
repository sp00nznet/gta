/* gta_menu.c -- F10, the settings menu, for the native macOS host.
 *
 * Modeled on redalert2-recomp's src/linux/menu.c (the same win32hle popup,
 * hle_screen_menu): drawn over the picture, the game's input paused while it
 * is open. Scaling and fullscreen take effect at once and are remembered in
 * gta-macos.ini beside the program; the in-game resolution and the view are
 * the remaster's (src/remaster/hires.c) and are read as the next game
 * starts, as Options would.
 *
 * On a Mac keyboard the F keys are media keys unless fn is held: F10 is the
 * menu, and so is Cmd+M.
 */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <limits.h>
#include <SDL2/SDL.h>

#include "win32hle.h"
#include "gta_mixer.h"
#include "../remaster/remaster.h"      /* g_rm */

enum { ID_SCALE = 100, ID_FULL = 200, ID_RES = 300, ID_VIEW = 400, ID_SOUND = 500, ID_SCALE_BASE = 1000 };

static const char *const k_scale[] = { "sharp", "smooth", "crt", "nearest", "integer" };
static const char *const k_scale_label[] = { "Sharp (default)", "Smooth", "CRT", "Nearest", "Whole pixels" };

/* The remaster's resolutions (hires.c k_modes), as Options lists them. */
static const struct { int w, h; } k_res[] = {
    { 640, 480 }, { 800, 600 }, { 1024, 768 }, { 1600, 1200 },
    { 1280, 720 }, { 1366, 768 }, { 1600, 900 }, { 1920, 1080 },
    { 2560, 1080 }, { 2560, 1440 }, { 3440, 1440 }, { 3840, 2160 },
};
#define NRES ((int)(sizeof k_res / sizeof *k_res))

static int k_views[] = { 100, 90, 75, 60, 45 };

static char g_ini[PATH_MAX];
static int g_muted;

static hle_menu_item_t g_main[7], g_scale[SCALE_COUNT], g_res[NRES], g_view[5], g_sound[2];
static char g_res_label[NRES][40], g_view_label[5][24];

/* ---- the ini (gta-macos.ini beside the program) ------------------------ */

static int ini_get(const char *sec, const char *key, char *out, size_t n) {
    FILE *f = g_ini[0] ? fopen(g_ini, "r") : NULL;
    char line[256];
    int in = 0, found = 0;
    out[0] = 0;
    while (f && fgets(line, sizeof line, f)) {
        line[strcspn(line, "\r\n")] = 0;
        if (line[0] == '[') {
            char sec_line[64];
            snprintf(sec_line, sizeof sec_line, "[%s]", sec);
            in = !strncasecmp(line, sec_line, strlen(sec_line));
            continue;
        }
        if (!in) continue;
        char *eq = strchr(line, '=');
        if (!eq) continue;
        *eq = 0;
        if (!strcasecmp(line, key)) { snprintf(out, n, "%s", eq + 1); found = 1; break; }
    }
    if (f) fclose(f);
    return found;
}
static void ini_set(const char *sec, const char *key, const char *val) {
    /* read-modify-write the whole file: a handful of keys, and the menu is
     * not a hot path */
    char buf[16384] = "";
    FILE *f = g_ini[0] ? fopen(g_ini, "rb") : NULL;
    if (f) { size_t n = fread(buf, 1, sizeof buf - 1, f); buf[n] = 0; fclose(f); }
    char need[256];
    snprintf(need, sizeof need, "%s=%s", key, val);
    FILE *o = g_ini[0] ? fopen(g_ini, "wb") : NULL;
    if (!o) return;
    int in_sec = 0, done = 0;
    for (char *p = buf; *p;) {
        char *e = strchr(p, '\n');
        size_t len = e ? (size_t)(e - p + 1) : strlen(p);
        if (*p == '[') {
            if (in_sec && !done) fprintf(o, "%s\n", need), done = 1;
            char sec_line[64];
            snprintf(sec_line, sizeof sec_line, "[%s]", sec);
            in_sec = !strncasecmp(p, sec_line, strlen(sec_line));
        }
        if (in_sec && !done && !strncasecmp(p, key, strlen(key)) && p[strlen(key)] == '=') {
            fprintf(o, "%s\n", need);
            done = 1;
        } else fwrite(p, 1, len, o);
        p += len;
    }
    if (!done) {
        if (buf[0] && buf[strlen(buf) - 1] != '\n') fputc('\n', o);
        if (!in_sec) fprintf(o, "[%s]\n", sec);
        fprintf(o, "%s\n", need);
    }
    fclose(o);
}

static void save_all(void) {
    int bars, full;
    const char *scale = hle_screen_settings(&bars, &full);
    ini_set("present", "scale", scale);
    ini_set("present", "fullscreen", full ? "1" : "0");
    char v[16];
    snprintf(v, sizeof v, "%dx%d", g_rm.res_w, g_rm.res_h);
    ini_set("game", "res", v);
    snprintf(v, sizeof v, "%d", g_rm.view);
    ini_set("game", "view", v);
    ini_set("sound", "mute", g_muted ? "1" : "0");
}

/* ---- the menu ----------------------------------------------------------- */

static void menu_open(void);

/* The DualSense touchpad opens it (gta_pad.c), as F10 does. */
void gta_menu_open(void) { menu_open(); }

static void menu_chosen(int id) {
    if (id >= ID_SCALE_BASE) {                        /* scaling: at once, as F12 does */
        int k = id - ID_SCALE_BASE;
        hle_screen_scale(k_scale[k]);
    }
    else if (id == ID_FULL) hle_screen_fullscreen(-1);
    else if (id >= ID_RES && id < ID_RES + NRES) {    /* for the next game, as Options */
        g_rm.res_w = k_res[id - ID_RES].w;
        g_rm.res_h = k_res[id - ID_RES].h;
    }
    else if (id >= ID_VIEW && id < ID_VIEW + 5) g_rm.view = k_views[id - ID_VIEW];
    else if (id == ID_SOUND) {
        g_muted = !g_muted;
        mixer_set_master_volume(g_muted ? 0 : 127);
    }
    save_all();
    if (id == 0) return;                              /* a grayed item */
    menu_open();                                      /* as the Windows presenter: stays up */
}

static void menu_open(void) {
    const char *cur_scale = hle_screen_settings(NULL, NULL);
    for (int k = 0; k < SCALE_COUNT; k++) {
        g_scale[k].label = k_scale_label[k];
        g_scale[k].id = ID_SCALE_BASE + k;
        g_scale[k].checked = cur_scale && !strcasecmp(cur_scale, k_scale[k]);
    }
    int n = 0;
    g_main[n].label = "Scaling";  g_main[n].hint = "F12";
    g_main[n].sub = g_scale, g_main[n].nsub = SCALE_COUNT, g_main[n].id = 0, n++;
    {   int bars, full;
        hle_screen_settings(&bars, &full);
        g_main[n].label = "Fullscreen"; g_main[n].hint = "F11";
        g_main[n].id = ID_FULL, g_main[n].checked = full, n++; }
    for (int k = 0; k < NRES; k++) {
        snprintf(g_res_label[k], sizeof g_res_label[k], "%d x %d%s",
                 k_res[k].w, k_res[k].h, k < 4 ? "" : " (widescreen)");
        g_res[k].label = g_res_label[k];
        g_res[k].id = ID_RES + k;
        g_res[k].checked = g_rm.res_w == k_res[k].w && g_rm.res_h == k_res[k].h;
    }
    g_main[n].label = "Resolution"; g_main[n].hint = "next game";
    g_main[n].sub = g_res, g_main[n].nsub = NRES, g_main[n].id = 0, n++;
    for (int k = 0; k < 5; k++) {
        snprintf(g_view_label[k], sizeof g_view_label[k], k_views[k] == 100 ? "100%% (original)" : "%d%% zoom out", k_views[k]);
        g_view[k].label = g_view_label[k];
        g_view[k].id = ID_VIEW + k;
        g_view[k].checked = g_rm.view == k_views[k];
    }
    g_main[n].label = "View"; g_main[n].hint = "zoom";
    g_main[n].sub = g_view, g_main[n].nsub = 5, g_main[n].id = 0, n++;
    g_sound[0].label = "On",  g_sound[0].id = ID_SOUND, g_sound[0].checked = !g_muted;
    g_sound[1].label = "Muted", g_sound[1].id = ID_SOUND, g_sound[1].checked = g_muted;
    g_main[n].label = "Sound"; g_main[n].hint = NULL;
    g_main[n].sub = g_sound, g_main[n].nsub = 2, g_main[n].id = 0, n++;
    hle_screen_menu(g_main, n, menu_chosen);
}

/* F10 (fn+F10 on a Mac) and Cmd+M open the menu; the host takes the key. */
static int menu_key(int sdl_scancode, int down) {
    if (!down) return 0;
    if (sdl_scancode == SDL_SCANCODE_F10 || (sdl_scancode == SDL_SCANCODE_M && (SDL_GetModState() & KMOD_GUI))) {
        menu_open();
        return 1;
    }
    return 0;
}

void gta_menu_start(void) {
    char v[64];
    if (hle_exe_path(g_ini, sizeof g_ini - 20)) {
        char *slash = strrchr(g_ini, '/');
        strcpy(slash ? slash + 1 : g_ini, "gta-macos.ini");
        if (ini_get("present", "scale", v, sizeof v)) {
            if (!hle_screen_scale(v)) g_rm.scale = SCALE_SHARP;
            for (int k = 0; k < SCALE_COUNT; k++) if (!strcasecmp(v, k_scale[k])) g_rm.scale = k;
        }
        if (ini_get("present", "fullscreen", v, sizeof v) && !strcmp(v, "1")) g_rm.fullscreen = 1;
        if (ini_get("game", "res", v, sizeof v)) {
            int w, h;
            if (sscanf(v, "%dx%d", &w, &h) == 2 && w >= 640 && h >= 480) g_rm.res_w = w, g_rm.res_h = h;
        }
        if (ini_get("game", "view", v, sizeof v)) {
            int z = atoi(v);
            if (z >= 25 && z <= 100) g_rm.view = z;
        }
        if (ini_get("sound", "mute", v, sizeof v) && !strcmp(v, "1")) {
            g_muted = 1;
            mixer_set_master_volume(0);
        }
    } else g_ini[0] = 0;
    hle_screen_key_hook = menu_key;
}

void gta_menu_save(void) { save_all(); }
