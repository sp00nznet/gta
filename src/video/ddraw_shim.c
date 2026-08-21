/*
 * A DirectDraw good enough for GTA1.
 *
 * The game LoadLibraryA's ddraw.dll and calls DirectDrawCreate through the
 * pointer GetProcAddress returns, then drives everything through COM vtables.
 * Handing it the real ddraw.dll gets as far as EnumDisplayModes and stops: no
 * modern driver offers a 640x480x8 palettized mode, and the enumeration
 * callback the game passes is an address in the ORIGINAL image, so Windows
 * would be calling unlifted machine code.
 *
 * So we are DirectDraw. The objects and their vtables live in the game's own
 * address space, and every vtable slot holds a bridge cookie -- the same
 * mechanism the IAT imports use -- so the lifted dispatcher resolves a COM call
 * with no extra machinery. Slots we have not implemented still know their
 * argument count, so they log and unwind the simulated stack correctly instead
 * of silently desynchronising it.
 *
 * The frame is honest 8-bit: the game locks a 640x480 buffer and writes palette
 * indices, and we StretchDIBits it to the window with a 256-entry colour table.
 * GDI does the lookup; there is no reason for us to.
 */

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#define RECOMP_GENERATED_CODE
#include "../engine/recomp_runtime.h"
#include <string.h>

#define DD_OK              0x00000000u
#define DDERR_UNSUPPORTED  0x80004001u
#define DDENUMRET_OK       1u

/* DDSURFACEDESC field offsets (dwSize 0x6C) */
#define SD_SIZE      0x00
#define SD_FLAGS     0x04
#define SD_HEIGHT    0x08
#define SD_WIDTH     0x0C
#define SD_PITCH     0x10
#define SD_BACKCOUNT 0x14
#define SD_SURFACE   0x24
#define SD_PIXFMT    0x48
#define SD_CAPS      0x68
#define SD_DESC_SIZE 0x6C

#define DDSD_CAPS            0x0001u
#define DDSD_HEIGHT          0x0002u
#define DDSD_WIDTH           0x0004u
#define DDSD_PITCH           0x0008u
#define DDSD_BACKBUFFERCOUNT 0x0020u
#define DDSD_LPSURFACE       0x0800u
#define DDSD_PIXELFORMAT     0x1000u

#define DDSCAPS_BACKBUFFER     0x0004u
#define DDSCAPS_PRIMARYSURFACE 0x0200u

#define DDPF_PALETTEINDEXED8 0x20u
#define DDPF_RGB             0x40u

#define SCREEN_W 640
#define SCREEN_H 480
/* GTA classifies enumerated modes by ddpfPixelFormat.dwRGBBitCount and only
 * recognises 16, 24 and 32 (sub_0048D4E0). An 8bpp mode is silently dropped,
 * which is why its 640x480 search found nothing. 16-bit 565 it is. */
#define SCREEN_BPP 16

enum { IF_DD, IF_SURFACE, IF_PALETTE, IF_CLIPPER, IF_COUNT };

/*
 * Arguments per vtable slot, `this` included. Unimplemented slots need this as
 * much as implemented ones: a stdcall callee owns its cleanup, and getting it
 * wrong desynchronises the simulated stack a long way from the cause.
 */
static const unsigned char k_argc[IF_COUNT][40] = {
    /* IDirectDraw: QI AddRef Release Compact | CreateClipper CreatePalette
     * CreateSurface DuplicateSurface | EnumDisplayModes EnumSurfaces
     * FlipToGDISurface GetCaps | GetDisplayMode GetFourCCCodes GetGDISurface
     * GetMonitorFrequency | GetScanLine GetVerticalBlankStatus Initialize
     * RestoreDisplayMode | SetCooperativeLevel SetDisplayMode
     * WaitForVerticalBlank */
    { 3,1,1,1, 4,5,4,3, 5,5,1,3, 2,3,2,2, 2,2,2,1, 3,4,3 },
    /* IDirectDrawSurface */
    { 3,1,1,2, 2,6,4,6, 3,3,4,3, 3,2,2,2, 3,2,2,3, 2,2,2,3, 1,5,2,1, 2,3,3,2, 2,6,2,3 },
    /* IDirectDrawPalette */
    { 3,1,1,2, 5,4,5 },
    /* IDirectDrawClipper */
    { 3,1,1,4, 2,3,2,3, 3 },
};
static const int k_slots[IF_COUNT] = { 23, 36, 7, 9 };
static const char *k_iface_name[IF_COUNT] = {
    "IDirectDraw", "IDirectDrawSurface", "IDirectDrawPalette", "IDirectDrawClipper"
};

/* bridge index -> the (interface, slot) it stands for */
static struct { unsigned char iface, slot; } g_method[512];
static u32 g_vtable[IF_COUNT];

static u32  g_dd_obj;
static u32  g_palette_obj;
static u32  g_clipper_obj;
static HWND g_hwnd;

#define MAX_SURFACES 8
static struct {
    u32 obj;            /* VA of the COM object handed to the game */
    u32 bits;           /* VA of its 8bpp pixels */
    u32 w, h, caps, bpp;
    int is_primary;
    int paired;         /* the surface this one flips with, or -1 */
} g_surf[MAX_SURFACES];
static int g_surf_count;

static PALETTEENTRY g_pal[256];

extern u32 g_bridge_hit;
extern u32 recomp_alloc_bridge(const char *name, void (*handler)(void));

/*
 * Call a game function pointer (an enumeration callback) through the lifted
 * dispatcher, so nothing ever jumps into the original image.
 */
static u32 call_game(u32 va, const u32 *args, int n) {
    recomp_func_t fn = recomp_lookup(va);
    u32 saved_esp = esp, result;
    int i;

    if (!fn) {
        fprintf(stderr, "  DDRAW: callback 0x%08X is not lifted\n", va);
        return 0;
    }
    for (i = n - 1; i >= 0; i--) PUSH32(esp, args[i]);
    PUSH32(esp, RECOMP_RETADDR);
    fn();
    result = eax;
    esp = saved_esp;
    return result;
}

static int surf_index(u32 obj) {
    int i;
    for (i = 0; i < g_surf_count; i++) if (g_surf[i].obj == obj) return i;
    return -1;
}

static void write_surface_desc(u32 p, u32 w, u32 h, u32 bits, u32 caps, u32 bpp) {
    u32 i;
    for (i = 0; i < SD_DESC_SIZE; i += 4) MEM32(p + i) = 0;
    MEM32(p + SD_SIZE)    = SD_DESC_SIZE;
    MEM32(p + SD_FLAGS)   = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH |
                            DDSD_PIXELFORMAT | (bits ? DDSD_LPSURFACE : 0u);
    MEM32(p + SD_HEIGHT)  = h;
    MEM32(p + SD_WIDTH)   = w;
    MEM32(p + SD_PITCH)   = w * (bpp / 8);
    MEM32(p + SD_SURFACE) = bits;
    MEM32(p + SD_CAPS)    = caps;
    MEM32(p + SD_PIXFMT + 0x00) = 0x20;                            /* dwSize */
    MEM32(p + SD_PIXFMT + 0x04) = (bpp == 8) ? (DDPF_RGB | DDPF_PALETTEINDEXED8)
                                             : DDPF_RGB;
    MEM32(p + SD_PIXFMT + 0x0C) = bpp;                             /* dwRGBBitCount */
    if (bpp == 16) {                                               /* 5-6-5 */
        MEM32(p + SD_PIXFMT + 0x10) = 0xF800u;                     /* dwRBitMask */
        MEM32(p + SD_PIXFMT + 0x14) = 0x07E0u;                     /* dwGBitMask */
        MEM32(p + SD_PIXFMT + 0x18) = 0x001Fu;                     /* dwBBitMask */
    } else if (bpp == 32) {
        MEM32(p + SD_PIXFMT + 0x10) = 0x00FF0000u;
        MEM32(p + SD_PIXFMT + 0x14) = 0x0000FF00u;
        MEM32(p + SD_PIXFMT + 0x18) = 0x000000FFu;
    }
}

/*
 * Put the surface on screen. GDI understands both formats directly: a 256-entry
 * colour table for 8bpp, or BI_BITFIELDS with 5-6-5 masks for 16bpp. Either way
 * the conversion is the display driver's job, not ours.
 */
static void present(int idx) {
    struct { BITMAPINFOHEADER h; DWORD c[256]; } bmi;   /* colour table or masks */
    HDC dc;
    RECT rc;
    int i;

    if (!g_hwnd || idx < 0 || !g_surf[idx].bits) return;

    memset(&bmi, 0, sizeof(bmi));
    bmi.h.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.h.biWidth       = (LONG)g_surf[idx].w;
    bmi.h.biHeight      = -(LONG)g_surf[idx].h;   /* top-down */
    bmi.h.biPlanes      = 1;
    bmi.h.biBitCount    = (WORD)g_surf[idx].bpp;

    if (g_surf[idx].bpp == 8) {
        RGBQUAD *pal = (RGBQUAD *)bmi.c;
        bmi.h.biCompression = BI_RGB;
        bmi.h.biClrUsed     = 256;
        for (i = 0; i < 256; i++) {
            pal[i].rgbRed   = g_pal[i].peRed;
            pal[i].rgbGreen = g_pal[i].peGreen;
            pal[i].rgbBlue  = g_pal[i].peBlue;
        }
    } else if (g_surf[idx].bpp == 16) {
        bmi.h.biCompression = BI_BITFIELDS;
        bmi.c[0] = 0xF800u;   /* red   */
        bmi.c[1] = 0x07E0u;   /* green */
        bmi.c[2] = 0x001Fu;   /* blue  */
    } else {
        bmi.h.biCompression = BI_RGB;
    }

    dc = GetDC(g_hwnd);
    if (!dc) return;
    GetClientRect(g_hwnd, &rc);
    if (rc.right <= 0)  rc.right  = (LONG)g_surf[idx].w;
    if (rc.bottom <= 0) rc.bottom = (LONG)g_surf[idx].h;
    SetStretchBltMode(dc, COLORONCOLOR);
    StretchDIBits(dc, 0, 0, rc.right, rc.bottom,
                  0, 0, (int)g_surf[idx].w, (int)g_surf[idx].h,
                  (void *)(uintptr_t)ADDR(g_surf[idx].bits),
                  (BITMAPINFO *)&bmi, DIB_RGB_COLORS, SRCCOPY);
    ReleaseDC(g_hwnd, dc);
}

static u32 make_object(int iface) {
    u32 obj = recomp_scratch_alloc(8);
    MEM32(obj) = g_vtable[iface];
    return obj;
}

static u32 create_surface(u32 desc_va) {
    u32 flags = MEM32(desc_va + SD_FLAGS);
    u32 caps  = MEM32(desc_va + SD_CAPS);
    u32 w     = (flags & DDSD_WIDTH)  ? MEM32(desc_va + SD_WIDTH)  : SCREEN_W;
    u32 h     = (flags & DDSD_HEIGHT) ? MEM32(desc_va + SD_HEIGHT) : SCREEN_H;
    u32 back  = (flags & DDSD_BACKBUFFERCOUNT) ? MEM32(desc_va + SD_BACKCOUNT) : 0;
    int i;

    /* Scratch is a bump allocator, so surfaces are never reclaimed: about a
     * dozen 640x480 buffers before it runs dry. Fine while the game creates
     * its surfaces once at startup; if it starts recreating them on every
     * mode change, give surfaces their own freelist. */
    if (g_surf_count >= MAX_SURFACES) return 0;
    i = g_surf_count++;
    g_surf[i].obj        = make_object(IF_SURFACE);
    g_surf[i].bpp        = SCREEN_BPP;
    g_surf[i].bits       = recomp_scratch_alloc(w * h * (SCREEN_BPP / 8));
    g_surf[i].w          = w;
    g_surf[i].h          = h;
    g_surf[i].caps       = caps;
    g_surf[i].is_primary = (caps & DDSCAPS_PRIMARYSURFACE) != 0;
    g_surf[i].paired     = -1;

    fprintf(stderr, "  DDRAW: CreateSurface %ux%u caps=0x%X%s -> obj 0x%08X bits 0x%08X\n",
            w, h, caps, g_surf[i].is_primary ? " PRIMARY" : "",
            g_surf[i].obj, g_surf[i].bits);

    /* A complex primary asks for its back buffer in the same call. */
    if (back && g_surf_count < MAX_SURFACES) {
        int b = g_surf_count++;
        g_surf[b].obj        = make_object(IF_SURFACE);
        g_surf[b].bpp        = SCREEN_BPP;
        g_surf[b].bits       = recomp_scratch_alloc(w * h * (SCREEN_BPP / 8));
        g_surf[b].w          = w;
        g_surf[b].h          = h;
        g_surf[b].caps       = DDSCAPS_BACKBUFFER;
        g_surf[b].is_primary = 0;
        g_surf[b].paired     = i;
        g_surf[i].paired     = b;
        fprintf(stderr, "  DDRAW:   + back buffer -> obj 0x%08X bits 0x%08X\n",
                g_surf[b].obj, g_surf[b].bits);
    }
    return g_surf[i].obj;
}

static void enum_display_modes(u32 ctx, u32 callback) {
    static const struct { u32 w, h; } modes[] = {
        { 320, 200 }, { 320, 240 }, { 640, 400 },
        { 640, 480 }, { 800, 600 }, { 1024, 768 },
    };
    const int n = (int)(sizeof(modes) / sizeof(modes[0]));
    u32 desc = recomp_scratch_alloc(SD_DESC_SIZE);
    int i;

    for (i = 0; i < n; i++) {
        u32 args[2];
        write_surface_desc(desc, modes[i].w, modes[i].h, 0, 0, SCREEN_BPP);
        args[0] = desc;
        args[1] = ctx;
        if (call_game(callback, args, 2) != DDENUMRET_OK) break;
    }
    fprintf(stderr, "  DDRAW: EnumDisplayModes offered %d %u-bit modes\n", i, SCREEN_BPP);
}

/* One handler behind every vtable slot; g_bridge_hit says which. */
static void shim_dispatch(void) {
    int iface = g_method[g_bridge_hit].iface;
    int slot  = g_method[g_bridge_hit].slot;
    u32 self  = ARG(1);
    int argc  = k_argc[iface][slot];
    u32 ret   = DD_OK;
    int si, i;

    switch (iface) {

    case IF_DD:
        switch (slot) {
        case 4:  /* CreateClipper(dwFlags, lplpDDClipper, pUnkOuter) */
            if (!g_clipper_obj) g_clipper_obj = make_object(IF_CLIPPER);
            MEM32(ARG(3)) = g_clipper_obj;
            break;
        case 5:  /* CreatePalette(dwFlags, lpColorTable, lplpDDPalette, pUnkOuter) */
            if (!g_palette_obj) g_palette_obj = make_object(IF_PALETTE);
            for (i = 0; i < 256; i++) {
                u32 e = ARG(3) + (u32)i * 4;
                g_pal[i].peRed   = MEM8(e);
                g_pal[i].peGreen = MEM8(e + 1);
                g_pal[i].peBlue  = MEM8(e + 2);
                g_pal[i].peFlags = 0;
            }
            MEM32(ARG(4)) = g_palette_obj;
            break;
        case 6:  /* CreateSurface(lpDDSurfaceDesc, lplpDDSurface, pUnkOuter) */
            {
                u32 s = create_surface(ARG(2));
                if (!s) ret = DDERR_UNSUPPORTED;
                else    MEM32(ARG(3)) = s;
            }
            break;
        case 8:  /* EnumDisplayModes(dwFlags, lpDDSurfaceDesc, ctx, callback) */
            enum_display_modes(ARG(4), ARG(5));
            break;
        case 11: /* GetCaps -- the game only sizes the struct; zeros are fine */
            break;
        case 20: /* SetCooperativeLevel(hWnd, dwFlags) */
            g_hwnd = (HWND)(uintptr_t)ARG(2);
            fprintf(stderr, "  DDRAW: SetCooperativeLevel hwnd=0x%08X flags=0x%X\n",
                    ARG(2), ARG(3));
            break;
        case 21: /* SetDisplayMode(dwWidth, dwHeight, dwBPP) */
            fprintf(stderr, "  DDRAW: SetDisplayMode %ux%ux%u\n", ARG(2), ARG(3), ARG(4));
            break;
        default:
            fprintf(stderr, "  DDRAW: %s slot %d (0x%02X) unimplemented -> DD_OK\n",
                    k_iface_name[iface], slot, slot * 4);
            break;
        }
        break;

    case IF_SURFACE:
        si = surf_index(self);
        switch (slot) {
        case 11: /* Flip(lpDDSurfaceTargetOverride, dwFlags) */
            if (si >= 0) {
                int b = g_surf[si].paired;
                present(b >= 0 ? b : si);
                if (b >= 0) {          /* swap buffers, as a real flip does */
                    u32 t = g_surf[si].bits;
                    g_surf[si].bits = g_surf[b].bits;
                    g_surf[b].bits  = t;
                }
            }
            break;
        case 12: /* GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface) */
            if (si >= 0 && g_surf[si].paired >= 0)
                MEM32(ARG(3)) = g_surf[g_surf[si].paired].obj;
            else
                ret = DDERR_UNSUPPORTED;
            break;
        case 22: /* GetSurfaceDesc(lpDDSurfaceDesc) */
            if (si >= 0)
                write_surface_desc(ARG(2), g_surf[si].w, g_surf[si].h,
                                   g_surf[si].bits, g_surf[si].caps, g_surf[si].bpp);
            break;
        case 24: /* IsLost -- never */
            break;
        case 25: /* Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent) */
            if (si >= 0)
                write_surface_desc(ARG(3), g_surf[si].w, g_surf[si].h,
                                   g_surf[si].bits, g_surf[si].caps, g_surf[si].bpp);
            else
                ret = DDERR_UNSUPPORTED;
            break;
        case 32: /* Unlock(lpSurfaceData) */
            if (si >= 0 && g_surf[si].is_primary) present(si);
            break;
        case 27: /* Restore    */
        case 28: /* SetClipper */
        case 31: /* SetPalette */
            break;
        default:
            fprintf(stderr, "  DDRAW: %s slot %d (0x%02X) unimplemented -> DD_OK\n",
                    k_iface_name[iface], slot, slot * 4);
            break;
        }
        break;

    case IF_PALETTE:
        if (slot == 6) {  /* SetEntries(dwFlags, dwStartingEntry, dwCount, lpEntries) */
            u32 start = ARG(3), count = ARG(4), src = ARG(5);
            for (i = 0; (u32)i < count && start + (u32)i < 256; i++) {
                u32 e = src + (u32)i * 4;
                g_pal[start + i].peRed   = MEM8(e);
                g_pal[start + i].peGreen = MEM8(e + 1);
                g_pal[start + i].peBlue  = MEM8(e + 2);
            }
        }
        break;

    default:
        break;
    }

    eax = ret;
    esp += 4 + 4u * (u32)argc;
}

/* DirectDrawCreate(lpGUID, lplpDD, pUnkOuter) */
static void shim_directdrawcreate(void) {
    if (!g_dd_obj) g_dd_obj = make_object(IF_DD);
    MEM32(ARG(2)) = g_dd_obj;
    fprintf(stderr, "  DDRAW: DirectDrawCreate -> obj 0x%08X\n", g_dd_obj);
    eax = DD_OK;
    esp += 4 + 12;
}

/* DirectDrawCreateClipper(dwFlags, lplpDDClipper, pUnkOuter) */
static void shim_directdrawcreateclipper(void) {
    if (!g_clipper_obj) g_clipper_obj = make_object(IF_CLIPPER);
    MEM32(ARG(3)) = g_clipper_obj;
    eax = DD_OK;
    esp += 4 + 12;
}

static u32 g_create_bridge, g_createclipper_bridge;

void ddraw_shim_init(void) {
    int iface, slot, i;

    for (iface = 0; iface < IF_COUNT; iface++) {
        u32 vt = recomp_scratch_alloc((u32)k_slots[iface] * 4);
        g_vtable[iface] = vt;
        for (slot = 0; slot < k_slots[iface]; slot++) {
            u32 cookie = recomp_alloc_bridge(k_iface_name[iface], shim_dispatch);
            u32 idx = cookie & 0xFFFFu;
            g_method[idx].iface = (unsigned char)iface;
            g_method[idx].slot  = (unsigned char)slot;
            MEM32(vt + (u32)slot * 4) = cookie;
        }
    }
    g_create_bridge = recomp_alloc_bridge("DirectDrawCreate", shim_directdrawcreate);
    g_createclipper_bridge =
        recomp_alloc_bridge("DirectDrawCreateClipper", shim_directdrawcreateclipper);

    /* A grey ramp, so a frame drawn before the game sets a palette is visible
     * rather than black-on-black. */
    for (i = 0; i < 256; i++)
        g_pal[i].peRed = g_pal[i].peGreen = g_pal[i].peBlue = (BYTE)i;

    fprintf(stderr, "DirectDraw shim ready (vtables 0x%08X 0x%08X 0x%08X 0x%08X)\n",
            g_vtable[0], g_vtable[1], g_vtable[2], g_vtable[3]);
}

/* Hand back our own entry points instead of the real ddraw.dll's. */
u32 ddraw_shim_getproc(const char *name) {
    if (!strcmp(name, "DirectDrawCreate"))        return g_create_bridge;
    if (!strcmp(name, "DirectDrawCreateClipper")) return g_createclipper_bridge;
    return 0;
}
