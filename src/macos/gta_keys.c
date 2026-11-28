/*
 * gta_keys.c - bring-up aids both macOS hosts share: a key script played into
 * the game (GTA_KEYS, --autotap) and the sampled frames written to disk
 * (GTA_SHOTS), so a headless run can be driven past menus and looked at.
 */
#include <ctype.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include "win32hle.h"
#include "gta_keys.h"

/* GTA_SHOTS=DIR: every sampled frame also written as DIR/frameNNN.ppm (bring-up:
 * what the screen shows, headless). 16-bit is 565, 8-bit goes through the palette. */
void gta_shoot(const uint8_t *px, int w, int h, int pitch, int bpp, const uint32_t *pal, long n) {
    const char *dir = getenv("GTA_SHOTS");
    if (!dir || w <= 0 || h <= 0) return;
    char path[1024];
    snprintf(path, sizeof path, "%s/frame%03ld.ppm", dir, n);
    FILE *f = fopen(path, "wb");
    if (!f) return;
    fprintf(f, "P6\n%d %d\n255\n", w, h);
    for (int y = 0; y < h; y++) {
        const uint8_t *row = px + (size_t)y * (size_t)pitch;
        for (int x = 0; x < w; x++) {
            uint8_t rgb[3] = { 0, 0, 0 };
            if (bpp == 16) {
                uint16_t v = (uint16_t)(row[2 * x] | row[2 * x + 1] << 8);
                rgb[0] = (uint8_t)((v >> 11) << 3), rgb[1] = (uint8_t)(((v >> 5) & 63) << 2), rgb[2] = (uint8_t)((v & 31) << 3);
            } else if (bpp == 32) {
                rgb[0] = row[4 * x + 2], rgb[1] = row[4 * x + 1], rgb[2] = row[4 * x];
            } else if (bpp == 8 && pal) {
                uint32_t c = pal[row[x]];
                rgb[0] = (uint8_t)(c >> 16), rgb[1] = (uint8_t)(c >> 8), rgb[2] = (uint8_t)c;
            }
            fwrite(rgb, 1, 3, f);
        }
    }
    fclose(f);
}

static void tap(int vk, int scan, const char *name, double hold) {
    fprintf(stderr, "[host] autotap: %s\n", name);
    hle_input_key(1, vk, scan);
    hle_block_begin();
    if (hold < 0.15) hold = 0.15;
    struct timespec ts = { (time_t)hold, (long)((hold - (double)(time_t)hold) * 1e9) };
    nanosleep(&ts, NULL);
    hle_block_end();
    hle_input_key(0, vk, scan);
}

/* GTA_KEYS="15:enter,17.5:down,19:enter,30:up*3": a key script for bring-up
 * runs, the time in seconds from launch, *S to hold the key S seconds. Names:
 * enter esc space up down left right tab ctrl shift backspace lctrl lalt rshift,
 * or a letter or
 * digit. --autotap S is GTA_KEYS="S:enter". */
static int g_autotap;
static void *autotap_thread(void *arg) {
    static const struct { const char *name; int vk, scan; } keys[] = {
        { "enter", 0x0D, 0x1C }, { "esc", 0x1B, 0x01 }, { "space", 0x20, 0x39 }, { "tab", 0x09, 0x0F },
        { "up", 0x26, 0x48 }, { "down", 0x28, 0x50 }, { "left", 0x25, 0x4B }, { "right", 0x27, 0x4D },
        { "ctrl", 0x11, 0x1D }, { "shift", 0x10, 0x2A }, { "backspace", 0x08, 0x0E },
        { "lctrl", 0xA2, 0x1D }, { "lalt", 0xA4, 0x38 }, { "rshift", 0xA1, 0x36 },
    };
    static const char row_scan[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    static const int row_code[] = { 2,3,4,5,6,7,8,9,10,11, 16,17,18,19,20,21,22,23,24,25, 30,31,32,33,34,35,36,37,38, 44,45,46,47,48,49,50 };
    const char *script = getenv("GTA_KEYS");
    char fallback[32];
    (void)arg;
    if (!script) { snprintf(fallback, sizeof fallback, "%d:enter", g_autotap); script = fallback; }
    char *copy = strdup(script), *save = NULL;
    struct timespec t0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (char *item = strtok_r(copy, ",", &save); item; item = strtok_r(NULL, ",", &save)) {
        char *colon = strchr(item, ':');
        if (!colon) continue;
        *colon = 0;
        double at = atof(item);
        char *name = colon + 1, *star = strchr(name, '*');
        double hold = 0;
        if (star) *star = 0, hold = atof(star + 1);
        int vk = 0, scan = 0;
        for (size_t k = 0; k < sizeof keys / sizeof keys[0]; k++)
            if (!strcasecmp(name, keys[k].name)) vk = keys[k].vk, scan = keys[k].scan;
        if (!vk && name[0] && !name[1]) {
            const char *at_row = strchr(row_scan, toupper((unsigned char)name[0]));
            if (at_row) vk = toupper((unsigned char)name[0]), scan = row_code[at_row - row_scan];
        }
        if (!vk) { fprintf(stderr, "[host] autotap: no key '%s'\n", name); continue; }
        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);
        double wait = at - ((double)(now.tv_sec - t0.tv_sec) + (double)(now.tv_nsec - t0.tv_nsec) / 1e9);
        if (wait > 0) { struct timespec w = { (time_t)wait, (long)((wait - (double)(time_t)wait) * 1e9) }; nanosleep(&w, NULL); }
        tap(vk, scan, name, hold);
    }
    free(copy);
    return NULL;
}

void gta_keys_start(int autotap_s) {
    g_autotap = autotap_s;
    if (!g_autotap && !getenv("GTA_KEYS")) return;
    pthread_t t;
    pthread_create(&t, NULL, autotap_thread, NULL);
    pthread_detach(t);
}
