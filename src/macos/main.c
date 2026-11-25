/*
 * Grand Theft Auto (1997) static recompilation -- the native macOS host.
 *
 * The same lifted C as the Windows build (src/recomp/gen), on pcrecomp's
 * runtime/win32hle instead of the Windows engine: every Win32 import the
 * game makes is answered by win32hle itself (files, windows and messages,
 * GDI and palettes, DirectDraw in software, Winsock, the registry, Miles
 * by our own gta_mss.c), so no Wine, no Rosetta, no Windows DLLs: a 64-bit
 * arm64 program whose guest is the game's own code.
 *
 * The guest's 4 GB is one block of the host's memory at RECOMP_MEM_BASE
 * (win32hle's guest_mem.c), the image goes at its own address in it, and
 * what is specific to this game is what is here: where the image goes, the
 * registry the game cannot start without, the remaster settings, and the
 * fault report.
 *
 * Modeled on redalert2-recomp's src/linux/main.c and this repo's
 * src/engine/main.c.
 */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/stat.h>
#include <limits.h>
#include <SDL2/SDL.h>

#include "win32hle.h"
#include "gta_keys.h"
#include "pe_loader.h"
#include "host.h"

#include "../remaster/remaster.h"   /* g_rm (defined in gta_hooks.c) */

/* the Miles answers (gta_mss.c) and the Smacker answers (gta_smack.c) */
extern const win32hle_shim gta_mss_shims[];
extern const win32hle_shim gta_smack_shims[];
extern const win32hle_shim gta_net_shims[];

/* the network game (gta_net.c): where the host is */
extern char g_dp_join[128];
extern int  g_dp_port;

/* the F10 settings menu (gta_menu.c) and the gamepad (gta_pad.c) */
void gta_menu_start(void);
void gta_pad_start(void);
void gta_pad_pump(void);

#define GTA_IMAGE_BASE 0x00400000u
#define GTA_EXE_NAME   "WINO\\Grand Theft Auto.exe"

static int g_headless, g_fullscreen = -1;   /* -1: as the settings say */
static int g_pacing_even = 1;                /* the default: one present per game frame -- the game writes
                                             * the primary in passes (city, then HUD), and a flip under
                                             * 48 ms after the last one shown waits for the pump, which
                                             * shows the finished frame (--pacing all: every write) */
static unsigned g_watchdog_s;
extern int win32hle_trace;

/* ---- game-specific answers ------------------------------------------- */

/* Message boxes print; headless, a question is answered No (as RA2's host
 * answers: a MessageBox in an unattended run must not stop it). */
static int g_msg_no;
static void gta_MessageBoxA(void) {
    uint32_t type = A32(3), buttons = type & 0xF;
    uint32_t answer = g_msg_no && (buttons == 4 || buttons == 3) ? 7u
                    : (buttons == 4 || buttons == 3) ? 6u : 1u;
    fprintf(stderr, "[messagebox] %s: %s -> %u\n",
            ASTR(2) ? ASTR(2) : "", ASTR(1) ? ASTR(1) : "", answer);
    RET(answer, 4);
}

static const win32hle_shim g_gta_shims[] = {
    { "MessageBoxA", gta_MessageBoxA },
    { 0, 0 }
};

/*
 * A registry of the game's own, for the two keys it cannot start without
 * (src/engine/iat_bridge.c): the installer and GTA Settings.exe write these,
 * and a failed lookup is fatal (FatalError -257). The bindings are scan
 * codes (0x80 set = extended key), the "Default Keys" preset of GTA
 * Settings.exe: turn left, turn right, forwards, backwards, brake,
 * enter/exit vehicle, attack, next weapon, previous weapon, special.
 */
#define HKLM 0x80000002u
static const uint32_t k_controls[10] = { 0xCB, 0xCD, 0xC8, 0xD0, 0x39, 0x1C, 0x1D, 0x2D, 0x2C, 0x0F };

static void registry_seed(void) {
    char name[16];
    for (int i = 0; i < 10; i++) {
        snprintf(name, sizeof name, "Control %d", i);
        hle_reg_set_dword(HKLM, "SOFTWARE\\DMA Design\\Grand Theft Auto\\Controls", name, k_controls[i]);
    }
    hle_reg_set_dword(HKLM, "SOFTWARE\\DMA Design\\Grand Theft Auto", "Language", 0);
}

/* ---- faults and the watchdog ------------------------------------------ */

static void report(const char *why) {
    fprintf(stderr, "\n=== %s ===\n  in lifted sub_%08X, last import %s\n", why, g_cur_func,
            g_cur_import ? g_cur_import : "(none)");
    fprintf(stderr, "  eax=%08X ecx=%08X edx=%08X ebx=%08X esp=%08X ebp=%08X esi=%08X edi=%08X\n",
            g_eax, g_ecx, g_edx, g_ebx, g_esp, g_ebp, g_esi, g_edi);
    fprintf(stderr, "last indirect calls (newest first):\n");
    for (int i = 1; i <= 40 && i <= (int)g_icall_trace_idx; i++) {
        uint32_t k = (g_icall_trace_idx - i) & (ICALL_TRACE_SIZE - 1);
        const char *nm = hle_name(g_icall_trace[k]);
        fprintf(stderr, "  0x%08X  from 0x%08X  %s\n", g_icall_trace[k], g_icall_from[k], nm ? nm : "");
    }
    fprintf(stderr, "guest stack at %08X:", g_esp);
    for (int k = 0; k < 64; k++) fprintf(stderr, "%s%08X", k % 8 ? " " : "\n  ", MEM32(g_esp + 4 * k));
    fprintf(stderr, "\n");
}

static void on_fault(int sig, siginfo_t *si, void *uc) {
    static volatile int once;
    (void)uc;
    if (__sync_lock_test_and_set(&once, 1)) _exit(3);
    char why[96];
    snprintf(why, sizeof why, "fault: signal %d, address %p", sig, si->si_addr);
    report(why);
    fflush(stderr);
    _exit(3);
}

static void *watchdog(void *arg) {
    (void)arg;
    sleep(g_watchdog_s);
    fprintf(stderr, "\n[watchdog] %u s: in sub_%08X, last import %s, %u indirect calls\n",
            g_watchdog_s, g_cur_func, g_cur_import ? g_cur_import : "(none)", g_icall_count);
    fflush(stderr);
    hle_exit(4);
    return NULL;
}

/* ---- the pump: what the host does while the game pumps messages ------- */

/*
 * --pacing even: the game's own in-game cadence is ~48-52 ms a frame (the
 * engine's, at any resolution), and 22 frames a second on a 60 Hz display
 * holds each one for 2 then 3 vsyncs alternately -- the picture is even but
 * the motion stutters. Holding every frame for at least ~48 ms makes the
 * display skip to the game's own rhythm instead: frames that arrive a few ms
 * apart show together, and the cadence stays even. screen.c's hook draws
 * the primary; wrapping it decides when. */
static void (*s_show_frame)(void);
static uint32_t g_last_show;
static void pacing_hook(void) {
    if (g_pacing_even) {
        uint32_t now = hle_ticks_ms();
        if (g_last_show && (int32_t)(now - g_last_show) < 48) return;   /* hold */
        g_last_show = now;
    }
    s_show_frame();
}

/* Every ~3.3 s, a checksum of the frame: a run's progress can be seen from
 * the log (headless) without a picture. The seq the primary carries counts
 * the frames the game flipped, so a rate goes here too. */
static long g_shown;
static uint32_t checksum(const uint8_t *px, int w, int h, int pitch, int bpp) {
    uint32_t sum = 0;
    for (int y = 0; y < h; y += 4)
        for (int x = 0; x < w * bpp / 8; x += 16) sum = sum * 31 + px[(size_t)y * pitch + x];
    return sum;
}
static uint32_t g_last_seq, g_seq_per_s, g_seq_tick;
/* What reached the screen: presents a second, and of them the distinct game
 * frames (a frame the game flipped but the presenter never showed is lost to
 * the eye). The frame hook runs on each present. */
static uint32_t g_shown_per_s, g_distinct_per_s, g_shown_seq_last = ~0u;
static void count_shown(const uint8_t *px, int w, int h, int pitch, int bpp) {
    (void)px, (void)w, (void)h, (void)pitch, (void)bpp;
    unsigned seq = 0;
    const uint8_t *p; const uint32_t *pal; int a, b, c, d;
    g_shown_per_s++;
    static int log_iv = -1;
    static uint32_t last_at;
    if (log_iv < 0) log_iv = getenv("GTA_PRESENT_LOG") != NULL;
    if (log_iv) { uint32_t now = hle_ticks_ms(); if (last_at) fprintf(stderr, "[present] +%u\n", now - last_at); last_at = now; }
    if (hle_dd_frame(&p, &a, &b, &c, &d, &pal, &seq) && seq != g_shown_seq_last) g_distinct_per_s++, g_shown_seq_last = seq;
}
static uint32_t g_seq_last_at, g_seq_max_gap;   /* pacing: the worst gap between two flips, in ms */

/* Quit from the window's close button or Cmd+Q is SDL_QUIT, which the
 * presenter turns into WM_CLOSE. Give the game a moment to exit on its own,
 * then go: RA2's host had to, and the quit prompt may be unanswered. */
#define QUIT_GRACE_S 3
static void *quit_grace(void *arg) {
    (void)arg;
    sleep(QUIT_GRACE_S);
    fprintf(stderr, "[host] quit: the game did not exit in %d s, leaving\n", QUIT_GRACE_S);
    hle_exit(0);
    return NULL;
}
static int quit_watch(void *ud, SDL_Event *e) {
    static int once;
    (void)ud;
    if (e->type == SDL_QUIT && !once++) {
        pthread_t t;
        pthread_create(&t, NULL, quit_grace, NULL);
        pthread_detach(t);
    }
    return 1;
}

static void frame_pump(void) {
    static int watching;
    if (!watching && SDL_WasInit(SDL_INIT_EVENTS)) { SDL_AddEventWatch(quit_watch, NULL); watching = 1; }
    static uint32_t next;
    const uint8_t *px;
    const uint32_t *pal;
    int w, h, pitch, bpp;
    unsigned seq = 0;
    hle_screen_pump();
    gta_pad_pump();                       /* the game does not poll SDL: the pad is read here */
    uint32_t now = hle_ticks_ms();
    if (hle_dd_frame(&px, &w, &h, &pitch, &bpp, &pal, &seq) && seq != g_last_seq) {
        if (g_seq_last_at) {
            uint32_t gap = now - g_seq_last_at;
            if (gap > g_seq_max_gap) g_seq_max_gap = gap;
        }
        g_seq_last_at = now;
        g_last_seq = seq, g_seq_per_s++;
    }
    if (now - g_seq_tick >= 1000) {
        fprintf(stderr, "[perf] %u game frames/s, worst gap %u ms, %u of them shown (%u presents)%s\n",
                g_seq_per_s, g_seq_max_gap, g_distinct_per_s, g_shown_per_s,
                g_seq_per_s && g_seq_max_gap > 60 ? "  <-- judder" : "");
        g_seq_tick = now, g_seq_per_s = 0, g_seq_max_gap = 0, g_shown_per_s = 0, g_distinct_per_s = 0;
    }
    if ((int32_t)(now - next) < 0 || !hle_dd_frame(&px, &w, &h, &pitch, &bpp, &pal, NULL)) return;
    next = now + 3333;
    fprintf(stderr, "[host] frame %ld checksum %08X (%dx%dx%d)\n",
            g_shown, checksum(px, w, h, pitch, bpp), w, h, bpp);
    gta_shoot(px, w, h, pitch, bpp, pal, g_shown++);
}

/* ---- main -------------------------------------------------------------- */

static uint32_t exe_stamp(const char *path) {
    uint8_t head[4096] = { 0 };
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    size_t n = fread(head, 1, sizeof head, f);
    fclose(f);
    uint32_t nt = n >= 0x40 ? *(const uint32_t *)(head + 0x3C) : 0;
    return nt && nt < sizeof head - 12 ? *(const uint32_t *)(head + nt + 8) : 0;
}
#define GTA_EXE_STAMP 0x3dcfd617u   /* the freeware build this repo lifts */

int main(int argc, char **argv) {
    char game_buf[PATH_MAX];
    const char *game = "game";
    const char *scale = NULL;
    int run = 0;
    setvbuf(stderr, NULL, _IONBF, 0);

    g_rm.res_w = 1920; g_rm.res_h = 1080;   /* the remaster's defaults; --classic for 640x480 */
    g_rm.view = 100;
    g_rm.scale = SCALE_SHARP;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--run")) run = 1;
        else if (!strcmp(argv[i], "--headless")) { g_headless = 1; g_msg_no = 1; }
        else if (!strcmp(argv[i], "--fullscreen")) g_fullscreen = 1;
        else if (!strcmp(argv[i], "--classic")) g_rm.classic = 1;
        else if (!strcmp(argv[i], "--mute")) hle_dsound_set_master(0.0f);
        else if (!strcmp(argv[i], "--pacing") && i + 1 < argc) g_pacing_even = strcmp(argv[++i], "all") != 0;
        else if (!strcmp(argv[i], "--scale") && i + 1 < argc) scale = argv[++i];
        else if (!strcmp(argv[i], "--res") && i + 1 < argc) {
            if (sscanf(argv[++i], "%dx%d", &g_rm.res_w, &g_rm.res_h) != 2)
                { fprintf(stderr, "--res WxH\n"); return 1; }
        }
        else if (!strcmp(argv[i], "--view") && i + 1 < argc) g_rm.view = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--game") && i + 1 < argc) game = argv[++i];
        else if (!strcmp(argv[i], "--join") && i + 1 < argc) snprintf(g_dp_join, sizeof g_dp_join, "%s", argv[++i]);
        else if (!strcmp(argv[i], "--port") && i + 1 < argc) g_dp_port = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--watchdog") && i + 1 < argc) g_watchdog_s = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--trace")) win32hle_trace = 1;
        else {
            printf("usage: gta1 [--run] [--headless | --fullscreen] [--scale sharp|smooth|crt|nearest|integer]\n"
                   "            [--res WxH] [--view 25..100] [--classic] [--pacing even|all] [--game DIR]\n"
                   "            [--join ADDR[:PORT]] [--port N] [--mute] [--watchdog S] [--trace]\n"
                   "\n"
                   "--game DIR is the game's install root: the folder holding WINO and GTADATA\n"
                   "            (default ./game). Controls: arrows move, Enter the car, Ctrl attack,\n"
                   "            Space brake, Z/X weapons, Tab special, Esc quit.\n");
            return !strcmp(argv[i], "--help") || !strcmp(argv[i], "-h") ? 0 : 1;
        }
    }

    char game_full[PATH_MAX], exe_host[PATH_MAX + 16];
    if (!realpath(game, game_full)) {
        /* not where we were invoked: try beside the binary
         * (build-macos/bin -> the repo root -> game) */
        char here[PATH_MAX];
        if (hle_exe_path(here, sizeof here)) {
            char *slash = strrchr(here, '/');
            if (slash) *slash = 0;
            char *bin = strrchr(here, '/');
            if (bin && !strcmp(bin + 1, "bin")) *bin = 0;
            snprintf(game_buf, sizeof game_buf, "%s/game", here);
            if (!realpath(game_buf, game_full)) {
                fprintf(stderr, "no game folder at %s (or %s)\n", game, game_buf);
                return 1;
            }
            game = game_buf;
        } else {
            fprintf(stderr, "no game folder at %s\n", game);
            return 1;
        }
    }
    hle_set_drive('C', game_full);
    /* An overlay on the game's folder: the files the game probes for but the
     * host answers itself. MGL checks that C:\WINDOWS\SYSTEM32\ddraw.dll
     * exists before it will use DirectDraw at all (GetSystemDirectoryA +
     * FindFirstFileA); win32hle answers LoadLibraryA("ddraw.dll") from its
     * own pseudo-module, so the file is never read -- but it must be found.
     * Writes under C:\ also land here, keeping the game folder pristine.
     * The stub is written here if the folder has none. */
    char overlay_full[PATH_MAX] = { 0 };
    if (!realpath("macos-overlay", overlay_full)) {
        /* not where we were invoked: beside the game folder. It need not
         * exist yet: the stub is written below. */
        char *slash = strrchr(game_full, '/');
        if (slash) snprintf(overlay_full, sizeof overlay_full, "%.*s/macos-overlay", (int)(slash - game_full), game_full);
    }
    if (overlay_full[0]) {
        char solved[PATH_MAX], stub[PATH_MAX + 32];
        mkdir(overlay_full, 0755);
        if (realpath(overlay_full, solved)) snprintf(overlay_full, sizeof overlay_full, "%s", solved);
        snprintf(stub, sizeof stub, "%s/WINDOWS", overlay_full), mkdir(stub, 0755);
        snprintf(stub, sizeof stub, "%s/WINDOWS/SYSTEM32", overlay_full), mkdir(stub, 0755);
        snprintf(stub, sizeof stub, "%s/WINDOWS/SYSTEM32/ddraw.dll", overlay_full);
        FILE *f = fopen(stub, "rb");
        if (!f) { f = fopen(stub, "wb"); if (f) fputs("MZ", f); }   /* a stub: never read, only found */
        if (!f) fprintf(stderr, "[host] cannot write the ddraw.dll stub: %s\n", strerror(errno));
        if (f) fclose(f);
        hle_set_overlay(game_full, overlay_full);
        fprintf(stderr, "[host] overlay %s on %s\n", overlay_full, game_full);
    } else fprintf(stderr, "[host] no overlay: MGL's ddraw.dll probe will fail\n");
    if (!hle_host_path("C:\\" GTA_EXE_NAME, exe_host, sizeof exe_host)) {
        fprintf(stderr, "no %s in %s\n", GTA_EXE_NAME, game_full);
        return 1;
    }
    uint32_t stamp = exe_stamp(exe_host);
    if (stamp != GTA_EXE_STAMP) {
        fprintf(stderr, "%s is not the build this host was lifted from (PE timestamp 0x%08X, wanted 0x%08X).\n",
                exe_host, stamp, GTA_EXE_STAMP);
        return 1;
    }

    signal(SIGPIPE, SIG_IGN);           /* a recorder whose ffmpeg went away gets an error, not a signal */
    {   /* faults report on their own stack: a guest stack overflow is one */
        static uint8_t alt[1 << 16];
        stack_t ss = { .ss_sp = alt, .ss_size = sizeof alt };
        sigaltstack(&ss, NULL);
        struct sigaction sa;
        memset(&sa, 0, sizeof sa);
        sa.sa_sigaction = on_fault;
        sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
        sigaction(SIGSEGV, &sa, NULL);
        sigaction(SIGBUS, &sa, NULL);
        sigaction(SIGFPE, &sa, NULL);
        sigaction(SIGILL, &sa, NULL);
    }

    win32hle_register(g_gta_shims);     /* first: the game's own answers win */
    win32hle_register(gta_mss_shims);   /* then our Miles, over win32hle's mss */
    win32hle_register(gta_smack_shims); /* and our Smacker (the video is skipped) */
    win32hle_register(gta_net_shims);    /* and our DirectPlay (the network game) */
    recomp_host_init();
    registry_seed();
    printf("Grand Theft Auto recomp host (native macOS)\n  lifted functions in dispatch: %u\n", recomp_dispatch_count);

    pe_image img;
    if (recomp_pe_map(exe_host, &img) != 0 || img.base != GTA_IMAGE_BASE) {
        fprintf(stderr, "cannot map %s at 0x%08X\n", exe_host, GTA_IMAGE_BASE);
        return 1;
    }
    hle_module_add("C:\\" GTA_EXE_NAME, img.base, img.resource_rva, img.resource_size, 1);
    int unresolved = recomp_pe_bind(&img, hle_resolve_or_stub);
    printf("  mapped %s: 0x%08X-0x%08X, %d imports not implemented yet\n",
           exe_host, img.base, img.base + img.span, unresolved);
    hle_set_command_line("\"C:\\" GTA_EXE_NAME "\"");

    /* The remaster's hooks (gta_hooks.c): the widescreen mode records in the
     * image we just mapped, and the row table in guest memory. */
    hires_init();

    /* The entry point, read from the header of the image we just mapped:
     * the CRT startup, which reads its own command line (GetCommandLineA).
     * src/engine/main.c does the same on Windows. */
    uint32_t pe = GTA_IMAGE_BASE + MEM32(GTA_IMAGE_BASE + 0x3C);
    uint32_t entry_va = GTA_IMAGE_BASE + MEM32(pe + 0x28);
    if (!run) {
        printf("\n(dry run: image mapped and bound; --run enters 0x%08X)\n", entry_va);
        return 0;
    }

    /* Run from the directory holding the executable: the game finds its data
     * as ..\gtadata\, which is C:\GTADATA the way the drive is mapped. */
    char *slash = strrchr(exe_host, '/');
    if (slash) *slash = 0;
    if (chdir(exe_host) != 0) { fprintf(stderr, "cannot enter %s\n", exe_host); return 1; }
    if (slash) *slash = '/';

    if (scale && !hle_screen_scale(scale))
        fprintf(stderr, "[host] no scaling \"%s\": sharp, smooth, crt, nearest or integer\n", scale);
    gta_menu_start();                     /* the ini's settings, and F10 */
    if (g_fullscreen > 0) g_rm.fullscreen = 1;   /* the command line wins over the ini */
    if (hle_screen_open("Grand Theft Auto", g_rm.fullscreen, g_headless) != 0) return 1;
    hle_set_pump_hook(frame_pump);
    if (!hle_screen_frame_hook) hle_screen_frame_hook = count_shown;
    gta_pad_start();                      /* a controller maps to the game's keys */
    if (g_pacing_even) {
        s_show_frame = hle_dd_primary_hook;      /* screen.c's: the picture (NULL headless) */
        if (s_show_frame) {
            hle_dd_primary_hook = pacing_hook;
            fprintf(stderr, "[host] pacing even: holding each frame ~48 ms (--pacing all turns it off)\n");
        }
    }

    if (g_watchdog_s) {
        pthread_t t;
        pthread_create(&t, NULL, watchdog, NULL);
        pthread_detach(t);
    }
    gta_keys_start(0);                    /* GTA_KEYS: a bring-up run's key script */
    printf("  entering 0x%08X\n\n", entry_va);
    fflush(stdout);
    uint32_t rc = hle_call_guest(entry_va, 0, NULL);
    printf("\nentry returned eax=%08X\n", rc);
    hle_exit((int)rc);
    return 0;
}
