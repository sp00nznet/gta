/* settings.c -- the remaster's settings: <exe>.ini beside the executable, and
 * the command line, which wins. The F10 menu writes the file back.
 *
 *   [remaster]
 *   resolution=1920x1080
 *   scale=sharp           sharp | smooth | crt | nearest | integer
 *   fullscreen=0
 *   controller=1
 *   view=100              the city's zoom, percent of the original (less shows more)
 *   window=100,100,1600,900
 *   [net]
 *   join=192.168.1.20      where a network game's host is (127.0.0.1)
 *   port=2350              the port it listens on
 *   coop=1                 network games are co-op on the campaign (docs/coop.md)
 *
 *   --classic  --res WxH  --view PCT  --scale NAME   --fullscreen  --windowed  --no-pad
 *   --join ADDR[:PORT]  --port N  --coop
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "remaster.h"
#include "../net/dplay.h"

remaster_t g_rm = { 0, 1280, 720, SCALE_SHARP, 0, 1, 100 };

static const char *const k_scale[SCALE_COUNT] = { "sharp", "smooth", "crt", "nearest", "integer" };
static char s_ini[MAX_PATH];

static int scale_from(const char *s) {
    for (int i = 0; i < SCALE_COUNT; i++) if (!_stricmp(s, k_scale[i])) return i;
    return SCALE_SHARP;
}

static void ini_path(void) {
    char *dot;
    if (s_ini[0]) return;
    GetModuleFileNameA(NULL, s_ini, MAX_PATH);
    dot = strrchr(s_ini, '.');
    if (dot) strcpy(dot, ".ini");
}

static void load(void) {
    char v[64];
    ini_path();
    if (GetPrivateProfileStringA("remaster", "resolution", "", v, sizeof v, s_ini) &&
        sscanf(v, "%dx%d", &g_rm.res_w, &g_rm.res_h) != 2) g_rm.res_w = 1280, g_rm.res_h = 720;
    if (GetPrivateProfileStringA("remaster", "scale", "", v, sizeof v, s_ini)) g_rm.scale = scale_from(v);
    g_rm.fullscreen = GetPrivateProfileIntA("remaster", "fullscreen", 0, s_ini);
    g_rm.pad = GetPrivateProfileIntA("remaster", "controller", 1, s_ini);
    g_rm.view = GetPrivateProfileIntA("remaster", "view", 100, s_ini);
    GetPrivateProfileStringA("net", "join", g_dp_join, g_dp_join, sizeof g_dp_join, s_ini);
    g_dp_port = GetPrivateProfileIntA("net", "port", g_dp_port, s_ini);
    g_coop = GetPrivateProfileIntA("net", "coop", 0, s_ini);
    if (GetPrivateProfileStringA("remaster", "window", "", v, sizeof v, s_ini))
        sscanf(v, "%d,%d,%d,%d", &g_rm.win_x, &g_rm.win_y, &g_rm.win_w, &g_rm.win_h);
}

void remaster_save(void) {
    char v[64];
    ini_path();
    sprintf(v, "%dx%d", g_rm.res_w, g_rm.res_h);
    WritePrivateProfileStringA("remaster", "resolution", v, s_ini);
    WritePrivateProfileStringA("remaster", "scale", k_scale[g_rm.scale], s_ini);
    WritePrivateProfileStringA("remaster", "fullscreen", g_rm.fullscreen ? "1" : "0", s_ini);
    WritePrivateProfileStringA("remaster", "controller", g_rm.pad ? "1" : "0", s_ini);
    sprintf(v, "%d", g_rm.view);
    WritePrivateProfileStringA("remaster", "view", v, s_ini);
    if (g_rm.win_w > 0) {
        sprintf(v, "%d,%d,%d,%d", g_rm.win_x, g_rm.win_y, g_rm.win_w, g_rm.win_h);
        WritePrivateProfileStringA("remaster", "window", v, s_ini);
    }
}

void remaster_parse_args(int *argc, char **argv) {
    int i, o = 1;
    load();
    for (i = 1; i < *argc; i++) {
        const char *a = argv[i];
        if (!strcmp(a, "--classic")) g_rm.classic = 1;
        else if (!strcmp(a, "--fullscreen")) g_rm.fullscreen = 1;
        else if (!strcmp(a, "--windowed")) g_rm.fullscreen = 0;
        else if (!strcmp(a, "--no-pad")) g_rm.pad = 0;
        else if (!strcmp(a, "--res") && i + 1 < *argc) sscanf(argv[++i], "%dx%d", &g_rm.res_w, &g_rm.res_h);
        else if (!strcmp(a, "--scale") && i + 1 < *argc) g_rm.scale = scale_from(argv[++i]);
        else if (!strcmp(a, "--view") && i + 1 < *argc) g_rm.view = atoi(argv[++i]);
        else if (!strcmp(a, "--join") && i + 1 < *argc) lstrcpynA(g_dp_join, argv[++i], sizeof g_dp_join);
        else if (!strcmp(a, "--port") && i + 1 < *argc) g_dp_port = atoi(argv[++i]);
        else if (!strcmp(a, "--coop")) g_coop = 1;
        else argv[o++] = argv[i];
    }
    *argc = o;
    if (g_rm.view < 40 || g_rm.view > 200) g_rm.view = 100;
    if (g_rm.classic) { g_rm.res_w = 640; g_rm.res_h = 480; g_rm.pad = 0; g_rm.fullscreen = 0; }
}
