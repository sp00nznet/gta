/*
 * Grand Theft Auto 2 (1999) static recompilation -- the native macOS host.
 *
 * The same shape as src/macos/main.c (GTA1's): the lifted C on pcrecomp's
 * runtime/win32hle, a 64-bit arm64 program, the guest's 4 GB one block of the
 * host's memory. GTA2's own imports are what GTA1's bring-up already crossed:
 * Kernel32/User32/Gdi32/Advapi32 win32hle answers, Miles through gta_mss.c
 * (GTA2's 52 overlap GTA1's 38; the 3D-sample family is stubbed permissive
 * until the game is heard to want it), Bink through win32hle's bink.c on
 * ffmpeg -- GTA2's cutscenes are Bink, and those can play -- DirectPlay
 * through gta_net.c (GTA2 imports ordinals 1 and 5; 5 answers as the
 * enumeration 2 does), and DirectInput8, which win32hle does not have yet:
 * one export, answered with an error so the game takes its Win32 input path.
 *
 * The lift is a separate one (src/recomp/gen_gta2), made without GTA1's
 * patch_gen: those patches are by GTA1 address and would land in GTA2's
 * code as corruption. No remaster hooks here: the game as it shipped.
 */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
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

/* the Miles answers and the DirectPlay star (shared with GTA1's host) */
extern const win32hle_shim gta_mss_shims[];
extern const win32hle_shim gta_net_shims[];

#define GTA2_IMAGE_BASE 0x00400000u
#define GTA2_EXE_NAME   "gta2.exe"

static int g_headless, g_fullscreen = -1;   /* -1: as the settings say */
static int g_autotap;                        /* --autotap S: press Enter after S seconds (bring-up: the input past the intro) */
static unsigned g_watchdog_s;
extern int win32hle_trace;

/* ---- IDirectDrawGammaControl on a surface (Vid_SetGamma) ---------------
 * dmavideo.dll sets the display's gamma through DirectDraw's
 * {69C11C3E-...}: GetGammaControl answers an identity ramp, SetGammaControl
 * accepts whatever it is given (a "gamma" the presenter does not apply yet)
 * -- a game darkening its screen for a fade at least gets an answer, as on
 * Windows. Served through win32hle's hle_dd_surface_qi_hook. */
static const uint8_t IID_IDirectDrawGammaControl[16] = {   /* {69C11C3E-B46B-11D1-AD7A-00C04FC29B4E} */
    0x3E, 0x1C, 0xC1, 0x69, 0x6B, 0xB4, 0xD1, 0x11, 0xAD, 0x7A, 0x00, 0xC0, 0x4F, 0xC2, 0x9B, 0x4E };
static void gamma_QueryInterface(void) {                   /* (this, iid, &out): we are what was asked */
    if (A32(2)) MEM32(A32(2)) = A32(0);
    MEM32(A32(0) + 4)++;
    RET(0, 3);
}
static void gamma_AddRef(void)  { MEM32(A32(0) + 4)++; RET(1, 1); }
static void gamma_Release(void) { uint32_t n = MEM32(A32(0) + 4) ? --MEM32(A32(0) + 4) : 0; RET(n, 1); }
/* dmavideo.dll calls these with three on the stack -- (this, flags, &ramp)
 * -- as its own Vid_* layer hands them down; read the ramp from the third
 * slot and pop what it pushed, or the caller's stack desynchronises and the
 * uninitialised ramp is read as pointers. */
static void gamma_GetGammaControl(void) {                  /* (this, ?, &DDGAMMARAMP) */
    uint32_t r = A32(2);
    if (r) {                                               /* no header: the ramp is the whole struct */
        for (int c = 0; c < 3; c++)
            for (int i = 0; i < 256; i++)
                MEM16(r + (c * 256 + i) * 2) = (uint16_t)(i << 8);
    }
    RET(0 /* DD_OK */, 3);
}
static void gamma_SetGammaControl(void) { RET(0 /* DD_OK */, 3); }
static const win32hle_shim g_gamma_vt[] = {
    { "IDirectDrawGammaControl::QueryInterface", gamma_QueryInterface },
    { "IDirectDrawGammaControl::AddRef",         gamma_AddRef },
    { "IDirectDrawGammaControl::Release",        gamma_Release },
    { "IDirectDrawGammaControl::GetGammaControl", gamma_GetGammaControl },
    { "IDirectDrawGammaControl::SetGammaControl", gamma_SetGammaControl },
    { 0, 0 }
};
static uint32_t surface_qi_hook(uint32_t surface, const uint8_t *iid) {
    if (memcmp(iid, IID_IDirectDrawGammaControl, 16)) return 0;
    {   static uint32_t vt;
        if (!vt) vt = hle_com_vtable(g_gamma_vt);
        return hle_com_new(vt, 8);
    }
}

/* ---- GTA2's own answers ----------------------------------------------- */

/* Message boxes print; headless, a question is answered No. */
static int g_msg_no;
static void gta2_MessageBoxA(void) {
    uint32_t type = A32(3), buttons = type & 0xF;
    uint32_t answer = g_msg_no && (buttons == 4 || buttons == 3) ? 7u
                    : (buttons == 4 || buttons == 3) ? 6u : 1u;
    fprintf(stderr, "[messagebox] %s: %s -> %u\n",
            ASTR(2) ? ASTR(2) : "", ASTR(1) ? ASTR(1) : "", answer);
    RET(answer, 4);
}

/* DPLAYX ordinal 5, which GTA2 imports (with 1, DirectPlayCreate): the
 * service-provider enumeration, answered as gta_net.c answers ordinal 2 --
 * one provider, or the game's network path never lights up. */
extern void x_DirectPlayEnumerateA(void);
static void gta2_dp_enumerate5(void) { x_DirectPlayEnumerateA(); }

/* DirectInput8Create(hinst, version, iid, &out, outer): win32hle has DirectInput
 * 3 and 5. GTA2 links only this one export; DIERR_NOTINITIALIZED sends it to
 * its own Win32 input path (the menus are window messages, as GTA1's are).
 * Five arguments: getting the count wrong desynchronises the guest's stack
 * a long way from here. */
static void gta2_DirectInput8Create(void) {
    fprintf(stderr, "[host] DirectInput8Create: not implemented; the game's Win32 input will carry\n");
    if (A32(3)) MEM32(A32(3)) = 0;
    RET(0x80070057u /* DIERR_... E_INVALIDARG */, 5);
}

/* DirectMusic, for the version check: after DirectDraw7 answers its
 * QueryInterface, GTA2 CoCreates CLSID_DirectMusic, and that is the last
 * gate before "Incorrect version of DirectX" aborts the boot. The game's
 * sound is Miles (its 52 mss32 imports); DirectMusic is asked for its
 * existence, so a COM object that answers IUnknown is what the check needs
 * -- if it calls further, the trace will say which. */
static const uint8_t CLSID_DirectMusic[16] = {   /* {636B9F10-0C7D-11D1-95B2-0020AFDC7421} */
    0x10, 0x9F, 0x6B, 0x63, 0x7D, 0x0C, 0xD1, 0x11, 0x95, 0xB2, 0x00, 0x20, 0xAF, 0xDC, 0x74, 0x21 };
static void dm_QueryInterface(void) {                  /* (this, iid, &out): we are whatever was asked */
    if (A32(2)) MEM32(A32(2)) = A32(0);
    MEM32(A32(0) + 4)++;
    RET(0, 3);
}
static void dm_AddRef(void)  { MEM32(A32(0) + 4)++; RET(1, 1); }
static void dm_Release(void) { uint32_t n = MEM32(A32(0) + 4) ? --MEM32(A32(0) + 4) : 0; RET(n, 1); }
static const win32hle_shim g_dmusic_vt[] = {
    { "IDirectMusic::QueryInterface", dm_QueryInterface },
    { "IDirectMusic::AddRef",         dm_AddRef },
    { "IDirectMusic::Release",        dm_Release },
    { 0, 0 }
};
static uint32_t dmusic_create(const uint8_t *iid, uint32_t *out) {
    static uint32_t vt;
    (void)iid;
    if (!vt) vt = hle_com_vtable(g_dmusic_vt);
    *out = hle_com_new(vt, 8);
    fprintf(stderr, "[host] DirectMusic created for the version check\n");
    return 0;                                        /* S_OK */
}

/* ---- the lifted engine DLL: dmavideo.dll, GTA2's video layer ----------
 * Civilization III's Linux host is the pattern (src/linux/main.c): the DLL
 * is lifted with the game (its Vid_* exports in the merged dispatch), the
 * host maps it at its own base, binds its imports, runs its DllMain, and
 * GetProcAddress answers from the export directory of the mapped image --
 * a lifted-code address, which recomp_lookup finds. */
static struct { const char *name; uint32_t base; char host[PATH_MAX]; int loaded; } g_lifted_dlls[] = {
    { "dmavideo.dll", 0x01000000u, "", 0 },
    { "d3ddll.dll",   0x00E00000u, "", 0 },   /* the Direct3D renderer, on the same lift-and-answer path */
};
#define NLIFTEDDLL ((int)(sizeof g_lifted_dlls / sizeof *g_lifted_dlls))

/* Renderers the host denies, as a machine without them would: GTA2's
 * renderer interface (its gbh_* family) lives in d3ddll.dll, which is also
 * the software rasteriser (its own table/shade banks over DirectDraw) --
 * there is no renderer without it, so nothing is denied today. 3dfx and
 * Glide stay off: a Voodoo card this host does not have. */
static const char *const k_renderer_deny[] = { "3dfx.dll", "DMAGlide.dll", 0 };

static int lifted_dll_of(const char *name) {
    if (!name) return -1;
    const char *b = strrchr(name, '\\');
    b = b ? b + 1 : name;
    for (int i = 0; i < NLIFTEDDLL; i++) if (!strcasecmp(b, g_lifted_dlls[i].name)) return i;
    return -1;
}
static int renderer_denied(const char *name) {
    if (!name) return 0;
    const char *b = strrchr(name, '\\');
    b = b ? b + 1 : name;
    for (int i = 0; k_renderer_deny[i]; i++) if (!strcasecmp(b, k_renderer_deny[i])) return 1;
    return 0;
}
static int lifted_dll_index(uint32_t h) {
    for (int i = 0; i < NLIFTEDDLL; i++) if (g_lifted_dlls[i].loaded && g_lifted_dlls[i].base == h) return i;
    return -1;
}

extern const win32hle_shim win32hle_module[];

static recomp_func_t hle_fn(const win32hle_shim *t, const char *name) {
    for (; t->name; t++) if (!strcmp(t->name, name)) return t->fn;
    return NULL;
}
static recomp_func_t g_win32hle_LoadLibraryA, g_win32hle_GetProcAddress;

static void gta2_LoadLibraryA(void) {
    const char *name = ASTR(0);
    int i = name ? lifted_dll_of(name) : -1;
    if (i >= 0 && renderer_denied(name)) {
        fprintf(stderr, "[host] %s: not on this machine (the software renderer carries)\n", name);
        RET(0, 1);
    }
    if (i < 0) { g_win32hle_LoadLibraryA(); return; }
    if (!g_lifted_dlls[i].loaded) {
        pe_image img;
        char guest[64];
        uint32_t args[3];
        if (recomp_pe_map(g_lifted_dlls[i].host, &img) != 0 || img.base != g_lifted_dlls[i].base) {
            fprintf(stderr, "[host] cannot map %s at 0x%08X\n", g_lifted_dlls[i].host, g_lifted_dlls[i].base);
            RET(0, 1);
        }
        snprintf(guest, sizeof guest, "C:\\%s", g_lifted_dlls[i].name);
        hle_module_add(guest, img.base, img.resource_rva, img.resource_size, 0);
        int unresolved = recomp_pe_bind(&img, hle_resolve_or_stub);
        g_lifted_dlls[i].loaded = 1;
        args[0] = img.base; args[1] = 1; args[2] = 0;          /* DLL_PROCESS_ATTACH */
        uint32_t ok = hle_call_guest(img.entry, 3, args);
        fprintf(stderr, "[load] %s at 0x%08X, %d imports not implemented, DllMain -> %u\n",
                g_lifted_dlls[i].name, img.base, unresolved, ok);
    }
    RET(g_lifted_dlls[i].base, 1);
}

/* A lifted DLL's export, by name or ordinal, from the export directory of
 * the image in guest memory. The name pointers -- the one the game handed
 * GetProcAddress and the ones in the DLL's table -- are guest VAs: hle_ptr
 * carries each before strcmp touches it, or the raw deref faults inside the
 * DLL's own data. */
static uint32_t export_of(uint32_t base, uint32_t which) {
    uint32_t rva = MEM32(base + MEM32(base + 0x3C) + 0x78);
    uint32_t ed, nfun, nnames, funcs, names, ords, idx;
    if (!rva) return 0;
    ed = base + rva, nfun = MEM32(ed + 20), nnames = MEM32(ed + 24);
    funcs = base + MEM32(ed + 28), names = base + MEM32(ed + 32), ords = base + MEM32(ed + 36);
    idx = which - MEM32(ed + 16);
    if (which >= 0x10000u) {
        const char *want = (const char *)hle_ptr(which);
        idx = ~0u;
        for (uint32_t k = 0; k < nnames; k++)
            if (!strcmp((const char *)hle_ptr(base + MEM32(names + 4 * k)), want)) { idx = MEM16(ords + 2 * k); break; }
    }
    return idx < nfun ? base + MEM32(funcs + 4 * idx) : 0;
}

static void gta2_GetProcAddress(void) {
    if (lifted_dll_index(A32(0)) < 0) { g_win32hle_GetProcAddress(); return; }
    uint32_t va = export_of(A32(0), A32(1));
    if (getenv("GTA_TRACE"))
        fprintf(stderr, "[load] GetProcAddress(%s, %s) -> 0x%08X\n", g_lifted_dlls[lifted_dll_index(A32(0))].name,
                A32(1) >= 0x10000u ? (const char *)(uintptr_t)hle_ptr(A32(1)) : "(by ordinal)", va);
    if (!va) hle_set_last_error(127);                   /* ERROR_PROC_NOT_FOUND */
    RET(va, 2);
}

/* As on Windows: a static destructor may still read something the DLL made,
 * so nothing is unloaded. */
static void gta2_FreeLibrary(void) { RET(1, 1); }

/* GetKeyboardLayoutNameA(char name[9]): the game reads the active layout for
 * its input configuration. The US layout's name, as any Windows a game was
 * configured on had. */
static void gta2_GetKeyboardLayoutNameA(void) {
    snprintf(ASTR(0), 9, "00000409");
    RET(1, 1);
}

/* Miles 3D, answered as "no provider": enumerate_3D_providers calls its
 * callback with none, and the game's positional sounds fall back to the 2D
 * digital driver that already works. The others answer with the arities
 * their @N decorations say (N bytes of arguments), so nothing
 * desynchronises if one is reached. */
static void mss3d_enumerate(void) { RET(0 /* none found */, 3); }
static void mss3d_open(void)      { RET(0 /* no provider to open */, 1); }
static void mss3d_a1(void)        { RET(0, 1); }
static void mss3d_a2(void)         { RET(0, 2); }
static void mss3d_a3(void)        { RET(0, 3); }
static void mss3d_a4(void)        { RET(0, 4); }
static void mss3d_a5(void)        { RET(0, 5); }

static const win32hle_shim g_gta2_mss3d_shims[] = {
    { "_AIL_enumerate_3D_providers@12",        mss3d_enumerate },
    { "_AIL_3D_provider_attribute@12",         mss3d_a3 },
    { "_AIL_3D_sample_status@4",               mss3d_a1 },
    { "_AIL_allocate_3D_sample_handle@4",      mss3d_a1 },
    { "_AIL_close_3D_provider@4",             mss3d_a1 },
    { "_AIL_end_3D_sample@4",                  mss3d_a1 },
    { "_AIL_open_3D_provider@4",               mss3d_open },
    { "_AIL_release_3D_sample_handle@4",       mss3d_a1 },
    { "_AIL_set_3D_position@16",               mss3d_a4 },
    { "_AIL_set_3D_provider_preference@12",    mss3d_a3 },
    { "_AIL_set_3D_sample_float_distances@20", mss3d_a5 },
    { "_AIL_set_3D_sample_info@8",             mss3d_a2 },
    { "_AIL_set_3D_sample_loop_block@12",      mss3d_a3 },
    { "_AIL_set_3D_sample_loop_count@8",       mss3d_a2 },
    { "_AIL_set_3D_sample_playback_rate@8",    mss3d_a2 },
    { "_AIL_set_3D_sample_volume@8",          mss3d_a2 },
    { "_AIL_start_3D_sample@4",                mss3d_a1 },
    { 0, 0 }
};

/* BinkGetSummary(bink, buf): a short text about the movie, into the game's
 * buffer. BinkOpenMiles(hMSS): route the movie's sound through Miles --
 * bink.c already plays it through DirectSound, so a no-op that says yes.
 * (BinkBufferSetDDPrimary and BinkBufferCheckWinPos are win32hle's bink.c's
 * now: its blit path lands on the DirectDraw primary.) */
static void gta2_BinkGetSummary(void) {
    uint32_t buf = A32(1);
    snprintf(buf ? ASTR(1) : "", buf ? 128 : 0, "RAD Game Tools Bink and Smacker, win32hle");
    RET(buf, 2);
}
static void gta2_BinkOpenMiles(void) { RET(1, 1); }

/* GTA2's own registry, two settings in Screen: videoname is the video layer
 * (dmavideo.dll, its default) and rendername the renderer (d3ddll.dll, its
 * default -- the gbh_* interface and the software rasteriser). The defaults
 * are what this host runs: seeded only so the keys exist. */
static void gta2_registry_seed(void) {
    hle_reg_set_string(0x80000002u, "SOFTWARE\\DMA Design Ltd\\GTA2\\Screen", "videoname", "dmavideo.dll");
    hle_reg_set_string(0x80000002u, "SOFTWARE\\DMA Design Ltd\\GTA2\\Screen", "rendername", "d3ddll.dll");
    hle_reg_set_dword(0x80000002u, "SOFTWARE\\DMA Design Ltd\\GTA2\\Screen", "videodevice", 0);
}

static const win32hle_shim g_gta2_shims[] = {
    { "MessageBoxA",              gta2_MessageBoxA },
    { "dplayx.dll#5",             gta2_dp_enumerate5 },
    { "LoadLibraryA",             gta2_LoadLibraryA },
    { "GetProcAddress",          gta2_GetProcAddress },
    { "FreeLibrary",              gta2_FreeLibrary },
    { "GetKeyboardLayoutNameA",  gta2_GetKeyboardLayoutNameA },
    { "_BinkGetSummary@8",        gta2_BinkGetSummary },
    { "_BinkOpenMiles@4",          gta2_BinkOpenMiles },
    { 0, 0 }
};

/* ---- the bring-up tracer (pcrecomp's RECOMP_TRACE contract) ------------
 * The lifted C's RECOMP_ENTER calls recomp_trace_enter and keeps the last
 * entries in g_enter_trace; a fault report prints them, so the run names
 * its own path into the crash. --calltrace FILE writes every entry too. */
uint32_t g_enter_trace[1024];
uint32_t g_enter_idx;
static FILE *s_calltrace;
static void calltrace_open(const char *path) {
    s_calltrace = fopen(path, "w");
    if (s_calltrace) setvbuf(s_calltrace, NULL, _IOFBF, 64u << 10);
    else fprintf(stderr, "[trace] cannot write %s\n", path);
}
void recomp_trace_enter(uint32_t va) {
    g_enter_trace[g_enter_idx++ & (1024 - 1)] = va;
    if (s_calltrace) { fprintf(s_calltrace, "%u %08X\n", (unsigned)(uintptr_t)pthread_self() & 0xffffu, va); }
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
    fprintf(stderr, "last functions entered (oldest of 24 first):\n");
    for (int i = 24; i >= 1; i--) {
        if ((int)g_enter_idx < i) break;
        fprintf(stderr, "  0x%08X\n", g_enter_trace[(g_enter_idx - i) & (1024 - 1)]);
    }
    fprintf(stderr, "guest stack at %08X:", g_esp);
    for (int k = 0; k < 64; k++) fprintf(stderr, "%s%08X", k % 8 ? " " : "\n  ", MEM32(g_esp + 4 * k));
    fprintf(stderr, "\n  below esp (the callee frames):\n");
    for (int k = 0; k < 24; k++) fprintf(stderr, "%s%08X", k % 8 ? " " : "\n  ", MEM32(g_esp - 0x10 - 4 * k));
    fprintf(stderr, "\n");
}

static void on_fault(int sig, siginfo_t *si, void *uc) {
    static volatile int once;
    (void)uc;
    if (__sync_lock_test_and_set(&once, 1)) _exit(3);
    char why[96];
    snprintf(why, sizeof why, "fault: signal %d, address %p", sig, si->si_addr);
    report(why);
    if (s_calltrace) fflush(s_calltrace);    /* the calltrace keeps the run's last steps */
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

/* ---- the pump ---------------------------------------------------------- */

static long g_shown;
static uint32_t checksum(const uint8_t *px, int w, int h, int pitch, int bpp) {
    uint32_t sum = 0;
    for (int y = 0; y < h; y += 4)
        for (int x = 0; x < w * bpp / 8; x += 16) sum = sum * 31 + px[(size_t)y * pitch + x];
    return sum;
}

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
    hle_screen_pump();
    uint32_t now = hle_ticks_ms();
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
#define GTA2_EXE_STAMP 0x408EC2ACu   /* the freeware build lifted here */

int main(int argc, char **argv) {
    const char *game = "gta2-game/extracted";
    const char *scale = NULL;
    int run = 0;
    setvbuf(stderr, NULL, _IONBF, 0);

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--calltrace") && i + 1 < argc) { calltrace_open(argv[++i]); continue; }
        if (!strcmp(argv[i], "--run")) run = 1;
        else if (!strcmp(argv[i], "--headless")) { g_headless = 1; g_msg_no = 1; }
        else if (!strcmp(argv[i], "--fullscreen")) g_fullscreen = 1;
        else if (!strcmp(argv[i], "--mute")) hle_dsound_set_master(0.0f);
        else if (!strcmp(argv[i], "--scale") && i + 1 < argc) scale = argv[++i];
        else if (!strcmp(argv[i], "--game") && i + 1 < argc) game = argv[++i];
        else if (!strcmp(argv[i], "--watchdog") && i + 1 < argc) g_watchdog_s = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--autotap") && i + 1 < argc) g_autotap = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--trace")) win32hle_trace = 1;
        else {
            printf("usage: gta2 [--run] [--headless | --fullscreen] [--scale sharp|smooth|crt|nearest|integer]\n"
                   "            [--game DIR] [--mute] [--watchdog S] [--trace]\n"
                   "\n"
                   "--game DIR is the game's install folder (default ./gta2-game/extracted).\n");
            return !strcmp(argv[i], "--help") || !strcmp(argv[i], "-h") ? 0 : 1;
        }
    }

    char game_full[PATH_MAX], exe_host[PATH_MAX + 16];
    if (!realpath(game, game_full)) { fprintf(stderr, "no game folder at %s\n", game); return 1; }
    hle_set_drive('C', game_full);
    if (!hle_host_path("C:\\" GTA2_EXE_NAME, exe_host, sizeof exe_host)) {
        fprintf(stderr, "no %s in %s\n", GTA2_EXE_NAME, game_full);
        return 1;
    }
    uint32_t stamp = exe_stamp(exe_host);
    if (stamp != GTA2_EXE_STAMP) {
        fprintf(stderr, "%s is not the build this host was lifted from (PE timestamp 0x%08X, wanted 0x%08X).\n",
                exe_host, stamp, GTA2_EXE_STAMP);
        return 1;
    }

    signal(SIGPIPE, SIG_IGN);
    {
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

    win32hle_register(g_gta2_shims);     /* first: the game's own answers win */
    g_win32hle_LoadLibraryA = hle_fn(win32hle_module, "LoadLibraryA");
    g_win32hle_GetProcAddress = hle_fn(win32hle_module, "GetProcAddress");
    {   /* where each lifted DLL's file is, on the host. hle_host_path fills
         * the path whether or not it exists; the return is existence, not
         * success. */
        for (int i = 0; i < NLIFTEDDLL; i++) {
            hle_host_path(g_lifted_dlls[i].name, g_lifted_dlls[i].host, sizeof g_lifted_dlls[i].host);
            if (!g_lifted_dlls[i].host[0])
                fprintf(stderr, "[host] no %s beside the game\n", g_lifted_dlls[i].name);
        }
    }
    win32hle_register(gta_mss_shims);    /* GTA1's Miles answers: the shared names */
    win32hle_register(g_gta2_mss3d_shims); /* GTA2's Miles 3D, as "no provider" */
    win32hle_register(gta_net_shims);    /* DirectPlayCreate (ordinal 1) */
    hle_com_register_class(CLSID_DirectMusic, dmusic_create);   /* the version check's last gate */
    gta2_registry_seed();                                       /* the software renderer, until Direct3D's menu bring-up */
    recomp_host_init();
    printf("Grand Theft Auto 2 recomp host (native macOS)\n  lifted functions in dispatch: %u\n", recomp_dispatch_count);

    pe_image img;
    if (recomp_pe_map(exe_host, &img) != 0 || img.base != GTA2_IMAGE_BASE) {
        fprintf(stderr, "cannot map %s at 0x%08X\n", exe_host, GTA2_IMAGE_BASE);
        return 1;
    }
    hle_module_add("C:\\" GTA2_EXE_NAME, img.base, img.resource_rva, img.resource_size, 1);
    int unresolved = recomp_pe_bind(&img, hle_resolve_or_stub);
    printf("  mapped %s: 0x%08X-0x%08X, %d imports not implemented yet\n",
           exe_host, img.base, img.base + img.span, unresolved);
    hle_set_command_line("\"C:\\" GTA2_EXE_NAME "\"");

    uint32_t pe = GTA2_IMAGE_BASE + MEM32(GTA2_IMAGE_BASE + 0x3C);
    uint32_t entry_va = GTA2_IMAGE_BASE + MEM32(pe + 0x28);
    if (!run) {
        printf("\n(dry run: image mapped and bound; --run enters 0x%08X)\n", entry_va);
        return 0;
    }

    if (chdir(game_full) != 0) { fprintf(stderr, "cannot enter %s\n", game_full); return 1; }

    if (scale && !hle_screen_scale(scale))
        fprintf(stderr, "[host] no scaling \"%s\": sharp, smooth, crt, nearest or integer\n", scale);
    int full = g_fullscreen > 0;
    if (hle_screen_open("Grand Theft Auto 2", full, g_headless) != 0) return 1;
    hle_set_pump_hook(frame_pump);
    hle_dd_surface_qi_hook = surface_qi_hook;   /* dmavideo's gamma on the primary */

    if (g_watchdog_s) {
        pthread_t t;
        pthread_create(&t, NULL, watchdog, NULL);
        pthread_detach(t);
    }
    gta_keys_start(g_autotap);
    printf("  entering 0x%08X\n\n", entry_va);
    fflush(stdout);
    uint32_t rc = hle_call_guest(entry_va, 0, NULL);
    printf("\nentry returned eax=%08X\n", rc);
    hle_exit((int)rc);
    return 0;
}
