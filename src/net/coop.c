/*
 * coop.c -- --coop: a network game on the single-player campaign.
 *
 * GTA1's network game is deathmatch: its levels are MISSION.INI sections
 * 1001-1204, each with four PLAYER spawn points and powerups. The campaign
 * levels (1, 2, 102, 103, 202, 203) are the same engine running the same
 * kind of script, with one PLAYER. Co-op, as the smallest change that works
 * (docs/coop.md has the design and what the game's code allows):
 *
 *  - the level: the mission number a network game sets (sub_0044AB50) is
 *    turned from the city's deathmatch level into that city's first campaign
 *    level; the host sends it to the others as it always does, and every copy
 *    maps it the same way;
 *  - the players: the campaign level gets three more PLAYER spawn points,
 *    each with a parked car of the player's own model, beside the first.
 *    MISSION.INI is not touched: the game opens a copy, rewritten in the
 *    temp folder, in its place;
 *  - the missions: the scripts run on every copy in lock-step, as all of the
 *    network game does, and drive player 1 (the host) as in single player:
 *    the phones, the pager, the score target. The partner rides along, fights
 *    alongside and can drive.
 *
 * Off unless every player passes --coop (or [net] coop=1).
 */
#ifdef _WIN32
#include <windows.h>
#endif
#define RECOMP_GENERATED_CODE
#include "../engine/recomp_runtime.h"
#include "dplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_coop;   /* settings.c */

/* sub_0044AB50(mission): set the mission number. */
void coop_on_set_mission(void) {
    u32 m = MEM32(esp + 4), to;
    if (!g_coop || m < 1001 || m > 1299) return;
    to = m < 1100 ? 1 : m < 1200 ? 102 : 202;
    fprintf(stderr, "[coop] mission %u -> %u (the campaign)\n", m, to);
    MEM32(esp + 4) = to;
}

/* The campaign sections, each given four spawn points. */
static int campaign_section(int n) { return n == 1 || n == 2 || n == 102 || n == 103 || n == 202 || n == 203; }

/* "294 1 (105,119,4) PLAYER 293 256": the player, the car it starts beside. */
static int parse_player(const char *l, int *id, int *x, int *y, int *z, int *car, int *rot) {
    return sscanf(l, "%d 1 (%d,%d,%d) PLAYER %d %d", id, x, y, z, car, rot) == 6;
}

/* Rewrite MISSION.INI into out. Returns 1 on success. */
static int write_overlay(const char *in, const char *out) {
    FILE *f = fopen(in, "rb"), *o;
    char line[1024], car_line[1024] = "";
    int section = 0, added = 0;
    if (!f) return 0;
    o = fopen(out, "wb");
    if (!o) { fclose(f); return 0; }
    while (fgets(line, sizeof line, f)) {
        int id, x, y, z, car, rot, cid, cx, cy, cz, model, crot;
        if (line[0] == '[') section = atoi(line + 1);
        if (campaign_section(section) && sscanf(line, "%d 1 (%d,%d,%d) PARKED %d %d", &cid, &cx, &cy, &cz, &model, &crot) == 6)
            strcpy(car_line, line);                     /* the last parked car: the player's is just before it */
        fputs(line, o);
        if (campaign_section(section) && parse_player(line, &id, &x, &y, &z, &car, &rot)) {
            int k, have_car = sscanf(car_line, "%d 1 (%d,%d,%d) PARKED %d %d", &cid, &cx, &cy, &cz, &model, &crot) == 6 && cid == car;
            for (k = 1; k <= 3; k++) {
                int nc = 9000 + k * 2, np = nc + 1;
                if (have_car)
                    fprintf(o, "%d 1 (%d,%d,%d) PARKED %d %d \r\n", nc, cx, cy + k, cz, model, crot);
                fprintf(o, "%d 1 (%d,%d,%d) PLAYER %d %d \r\n", np, x, y + k, z, have_car ? nc : car, rot);
            }
            added++;
        }
    }
    fclose(f);
    fclose(o);
    fprintf(stderr, "[coop] %s: four players in %d campaign levels\n", out, added);
    return added > 0;
}

/* iat_bridge.c's CreateFileA: the path the game should open instead, or NULL. */
const char *coop_redirect(const char *path) {
    static char out[MAX_PATH];
    static int state;   /* 0 untried, 1 ready, -1 failed */
    size_t n = strlen(path);
    if (!g_coop || n < 11 || _stricmp(path + n - 11, "mission.ini")) return NULL;
    if (!state) {
        char dir[MAX_PATH];
        GetTempPathA(sizeof dir, dir);
        _snprintf(out, sizeof out, "%sgta-coop-%lu.ini", dir, GetCurrentProcessId());
        state = write_overlay(path, out) ? 1 : -1;
    }
    return state > 0 ? out : NULL;
}
