/* present.c -- our presenter: the game's frame in a Direct3D 11 window.
 *
 * From Gunman Chronicles' recomp (src/runtime/present.c, present_d3d.c), fed
 * from the DirectDraw shim instead of a GDI DIB. The game still draws into the
 * shim's surfaces exactly as it did; each flip hands the frame here, and a
 * pixel shader scales it into the window:
 *
 *   window       resizable and maximizable, per-monitor DPI aware; the frame is
 *                letterboxed to its own aspect ratio
 *   F11, Alt+Enter  borderless fullscreen on the window's monitor, and back
 *   F12          scaling: sharp (sharp-bilinear), smooth, crt, nearest, integer
 *   F10          the settings menu (also right-click)
 *
 * 16-bit frames (in game) go up as B5G6R5 textures, sampled natively; 8-bit
 * frames (the front end) are looked up through the palette first. Any Direct3D
 * failure returns 0 and the shim draws with GDI as before. --classic skips all
 * of it.
 */
#define COBJMACROS
#include <windows.h>
#include <shellapi.h>
#include <d3d11.h>
#include <dxgi.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "remaster.h"

static const char *const k_scale_label[SCALE_COUNT] = {
    "Sharp (sharp-bilinear)", "Smooth (bilinear)", "CRT", "Nearest", "Integer multiples" };
static const char *const k_scale_name[SCALE_COUNT] = { "sharp", "smooth", "crt", "nearest", "integer" };

/* ---------------------------------------------------------------- D3D11 --- */

typedef HRESULT (WINAPI *compile_fn)(LPCVOID, SIZE_T, LPCSTR, const void*, void*, LPCSTR, LPCSTR,
                                     UINT, UINT, ID3DBlob**, ID3DBlob**);

static const char k_hlsl[] =
"Texture2D t0 : register(t0);\n"
"SamplerState s_lin : register(s0);\n"
"SamplerState s_pt : register(s1);\n"
"cbuffer C : register(b0) { float2 src; float2 dst; int mode; int p0; int p1; int p2; };\n"
"struct V { float4 pos : SV_Position; float2 uv : TEXCOORD0; };\n"
"V vs(uint id : SV_VertexID) {\n"
"  V o; float2 p = float2((id << 1) & 2, id & 2);\n"
"  o.pos = float4(p * float2(2, -2) + float2(-1, 1), 0, 1); o.uv = p; return o;\n"
"}\n"
"float3 sharp(float2 uv) {\n"
"  float2 scale = max(dst / src, 1.0);\n"
"  float2 texel = uv * src, fl = floor(texel), c = frac(texel) - 0.5;\n"
"  float2 range = 0.5 - 0.5 / scale;\n"
"  float2 f = (c - clamp(c, -range, range)) * scale + 0.5;\n"
"  return t0.Sample(s_lin, (fl + f) / src).rgb;\n"
"}\n"
"float3 crt(float2 uv, float2 px) {\n"
"  float k = saturate((dst.y / src.y - 1.5) / 1.5);\n"
"  float3 col = sharp(uv);\n"
"  float d = frac(uv.y * src.y) - 0.5;\n"
"  float beam = lerp(1.0, exp(-d * d * 8.0) * 1.6, k);\n"
"  uint m = (uint)px.x % 3u;\n"
"  float3 mask = m == 0u ? float3(1.25, 0.87, 0.87) : m == 1u ? float3(0.87, 1.25, 0.87)\n"
"                                                  : float3(0.87, 0.87, 1.25);\n"
"  return col * beam * lerp(float3(1, 1, 1), mask, k);\n"
"}\n"
"float4 ps(V i) : SV_Target {\n"
"  float3 c;\n"
"  if (mode == 0) c = sharp(i.uv);\n"
"  else if (mode == 1) c = t0.Sample(s_lin, i.uv).rgb;\n"
"  else if (mode == 2) c = crt(i.uv, i.pos.xy);\n"
"  else c = t0.Sample(s_pt, i.uv).rgb;\n"
"  return float4(saturate(c), 1);\n"
"}\n";

static struct {
    int failed;
    HWND hwnd;
    ID3D11Device* dev;
    ID3D11DeviceContext* ctx;
    IDXGISwapChain* sc;
    ID3D11RenderTargetView* rtv;
    ID3D11VertexShader* vs;
    ID3D11PixelShader* ps;
    ID3D11SamplerState* samp[2];
    ID3D11Buffer* cb;
    ID3D11Texture2D* tex;
    ID3D11ShaderResourceView* srv;
    int tw, th, no565;
    DXGI_FORMAT tfmt;
    int cw, ch;
} d;

static int fail(const char* what, HRESULT hr) {
    fprintf(stderr, "[present] Direct3D 11 unavailable (%s, 0x%08lX): using GDI\n", what, (unsigned long)hr);
    d.failed = 1;
    return 0;
}

static int d3d_init(HWND hw) {
    DXGI_SWAP_CHAIN_DESC sd = {0};
    sd.BufferCount = 2;
    sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hw;
    sd.SampleDesc.Count = 1;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    D3D_FEATURE_LEVEL fl = D3D_FEATURE_LEVEL_10_0;
    HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, &fl, 1,
                                               D3D11_SDK_VERSION, &sd, &d.sc, &d.dev, NULL, &d.ctx);
    if (FAILED(hr)) {   /* no GPU (or a session without one): WARP is still a GPU pipeline */
        hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_WARP, NULL, 0, &fl, 1,
                                           D3D11_SDK_VERSION, &sd, &d.sc, &d.dev, NULL, &d.ctx);
        if (FAILED(hr)) return fail("device", hr);
    }
    IDXGIFactory* f = NULL;   /* Alt+Enter is ours (borderless), not DXGI's exclusive mode */
    if (SUCCEEDED(IDXGISwapChain_GetParent(d.sc, &IID_IDXGIFactory, (void**)&f))) {
        IDXGIFactory_MakeWindowAssociation(f, hw, DXGI_MWA_NO_ALT_ENTER | DXGI_MWA_NO_WINDOW_CHANGES);
        IDXGIFactory_Release(f);
    }
    HMODULE dc = LoadLibraryA("d3dcompiler_47.dll");
    compile_fn compile = dc ? (compile_fn)GetProcAddress(dc, "D3DCompile") : NULL;
    if (!compile) return fail("d3dcompiler_47.dll", 0);
    ID3DBlob *vb = NULL, *pb = NULL, *err = NULL;
    hr = compile(k_hlsl, sizeof k_hlsl - 1, "present", NULL, NULL, "vs", "vs_4_0", 0, 0, &vb, &err);
    if (SUCCEEDED(hr))
        hr = compile(k_hlsl, sizeof k_hlsl - 1, "present", NULL, NULL, "ps", "ps_4_0", 0, 0, &pb, &err);
    if (FAILED(hr)) {
        if (err) fprintf(stderr, "[present] %s\n", (const char*)ID3D10Blob_GetBufferPointer(err));
        return fail("shader", hr);
    }
    ID3D11Device_CreateVertexShader(d.dev, ID3D10Blob_GetBufferPointer(vb), ID3D10Blob_GetBufferSize(vb), NULL, &d.vs);
    ID3D11Device_CreatePixelShader(d.dev, ID3D10Blob_GetBufferPointer(pb), ID3D10Blob_GetBufferSize(pb), NULL, &d.ps);
    ID3D10Blob_Release(vb); ID3D10Blob_Release(pb);

    D3D11_SAMPLER_DESC s = {0};
    s.AddressU = s.AddressV = s.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    s.MaxLOD = D3D11_FLOAT32_MAX;
    s.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    ID3D11Device_CreateSamplerState(d.dev, &s, &d.samp[0]);
    s.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    ID3D11Device_CreateSamplerState(d.dev, &s, &d.samp[1]);

    D3D11_BUFFER_DESC b = {0};
    b.ByteWidth = 32;
    b.Usage = D3D11_USAGE_DEFAULT;
    b.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    ID3D11Device_CreateBuffer(d.dev, &b, NULL, &d.cb);
    d.hwnd = hw;
    fprintf(stderr, "[present] Direct3D 11 presenter\n");
    return 1;
}

static int make_texture(int w, int h, DXGI_FORMAT fmt) {
    if (d.srv) { ID3D11ShaderResourceView_Release(d.srv); d.srv = NULL; }
    if (d.tex) { ID3D11Texture2D_Release(d.tex); d.tex = NULL; }
    D3D11_TEXTURE2D_DESC td = {0};
    td.Width = w; td.Height = h; td.MipLevels = 1; td.ArraySize = 1;
    td.Format = fmt; td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_DEFAULT; td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    if (FAILED(ID3D11Device_CreateTexture2D(d.dev, &td, NULL, &d.tex))) return 0;
    ID3D11Device_CreateShaderResourceView(d.dev, (ID3D11Resource*)d.tex, NULL, &d.srv);
    d.tw = w; d.th = h; d.tfmt = fmt;
    fprintf(stderr, "[present] frame %dx%d (%s)\n", w, h, fmt == DXGI_FORMAT_B5G6R5_UNORM ? "565" : "32");
    return 1;
}

/* Frame pixels into the texture: 565 as is, anything else as 32-bit. */
static int upload(const void* bits, int w, int h, int bpp, const DWORD* pal) {
    static DWORD* conv;
    static size_t conv_n;
    DXGI_FORMAT fmt = (bpp == 16 && !d.no565) ? DXGI_FORMAT_B5G6R5_UNORM : DXGI_FORMAT_B8G8R8X8_UNORM;
    if (!d.tex || d.tw != w || d.th != h || d.tfmt != fmt) {
        if (!make_texture(w, h, fmt)) {
            if (fmt != DXGI_FORMAT_B5G6R5_UNORM) return fail("texture", 0);
            d.no565 = 1;                              /* convert instead */
            return upload(bits, w, h, bpp, pal);
        }
    }
    if (fmt == DXGI_FORMAT_B5G6R5_UNORM) {
        ID3D11DeviceContext_UpdateSubresource(d.ctx, (ID3D11Resource*)d.tex, 0, NULL, bits, w * 2, 0);
        return 1;
    }
    if (conv_n < (size_t)w * h) { free(conv); conv_n = (size_t)w * h; conv = malloc(conv_n * 4); }
    if (!conv) return 0;
    size_t n = (size_t)w * h, i;
    if (bpp == 8) {
        const uint8_t* s = bits;
        for (i = 0; i < n; i++) conv[i] = pal[s[i]];
    } else if (bpp == 16) {
        const uint16_t* s = bits;
        for (i = 0; i < n; i++) {
            uint32_t v = s[i];
            conv[i] = ((v >> 11) << 19) | (((v >> 5) & 63) << 10) | ((v & 31) << 3);
        }
    } else {
        memcpy(conv, bits, n * 4);
    }
    ID3D11DeviceContext_UpdateSubresource(d.ctx, (ID3D11Resource*)d.tex, 0, NULL, conv, w * 4, 0);
    return 1;
}

static void write_backbuffer_bmp(const char* path);

static int d3d_draw(HWND hw, const RECT* r, int cw, int ch, int mode, int w, int h) {
    if (!d.rtv || cw != d.cw || ch != d.ch) {
        if (d.rtv) { ID3D11RenderTargetView_Release(d.rtv); d.rtv = NULL; }
        ID3D11DeviceContext_OMSetRenderTargets(d.ctx, 0, NULL, NULL);
        if (FAILED(IDXGISwapChain_ResizeBuffers(d.sc, 0, cw, ch, DXGI_FORMAT_UNKNOWN, 0))) return 0;
        ID3D11Texture2D* back = NULL;
        IDXGISwapChain_GetBuffer(d.sc, 0, &IID_ID3D11Texture2D, (void**)&back);
        ID3D11Device_CreateRenderTargetView(d.dev, (ID3D11Resource*)back, NULL, &d.rtv);
        ID3D11Texture2D_Release(back);
        d.cw = cw; d.ch = ch;
    }
    struct { float src[2], dst[2]; int mode, p0, p1, p2; } c = {
        { (float)w, (float)h }, { (float)(r->right - r->left), (float)(r->bottom - r->top) }, mode, 0, 0, 0 };
    ID3D11DeviceContext_UpdateSubresource(d.ctx, (ID3D11Resource*)d.cb, 0, NULL, &c, 0, 0);
    static const float black[4] = { 0, 0, 0, 1 };
    ID3D11DeviceContext_ClearRenderTargetView(d.ctx, d.rtv, black);
    D3D11_VIEWPORT vp = { (float)r->left, (float)r->top, (float)(r->right - r->left),
                          (float)(r->bottom - r->top), 0, 1 };
    ID3D11DeviceContext_RSSetViewports(d.ctx, 1, &vp);
    ID3D11DeviceContext_OMSetRenderTargets(d.ctx, 1, &d.rtv, NULL);
    ID3D11DeviceContext_IASetPrimitiveTopology(d.ctx, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    ID3D11DeviceContext_VSSetShader(d.ctx, d.vs, NULL, 0);
    ID3D11DeviceContext_PSSetShader(d.ctx, d.ps, NULL, 0);
    ID3D11DeviceContext_PSSetShaderResources(d.ctx, 0, 1, &d.srv);
    ID3D11DeviceContext_PSSetSamplers(d.ctx, 0, 2, d.samp);
    ID3D11DeviceContext_PSSetConstantBuffers(d.ctx, 0, 1, &d.cb);
    ID3D11DeviceContext_Draw(d.ctx, 3, 0);
    {   /* GTA_PRESENT_SHOT=path: the window's picture, once, after the frame named by GTA_PRESENT_SHOT_AT (s) */
        static int done;
        static DWORD t0;
        char path[MAX_PATH], at[16];
        if (!t0) t0 = GetTickCount();
        if (!done && GetEnvironmentVariableA("GTA_PRESENT_SHOT", path, sizeof path)) {
            int secs = GetEnvironmentVariableA("GTA_PRESENT_SHOT_AT", at, sizeof at) ? atoi(at) : 30;
            if ((int)(GetTickCount() - t0) >= secs * 1000) { write_backbuffer_bmp(path); done = 1; }
        }
    }
    IDXGISwapChain_Present(d.sc, 1, 0);
    (void)hw;
    return 1;
}

static void write_backbuffer_bmp(const char* path) {
    ID3D11Texture2D *back = NULL, *st = NULL;
    D3D11_TEXTURE2D_DESC td;
    D3D11_MAPPED_SUBRESOURCE m;
    IDXGISwapChain_GetBuffer(d.sc, 0, &IID_ID3D11Texture2D, (void**)&back);
    if (!back) return;
    ID3D11Texture2D_GetDesc(back, &td);
    td.Usage = D3D11_USAGE_STAGING; td.BindFlags = 0; td.CPUAccessFlags = D3D11_CPU_ACCESS_READ; td.MiscFlags = 0;
    if (SUCCEEDED(ID3D11Device_CreateTexture2D(d.dev, &td, NULL, &st))) {
        ID3D11DeviceContext_CopyResource(d.ctx, (ID3D11Resource*)st, (ID3D11Resource*)back);
        if (SUCCEEDED(ID3D11DeviceContext_Map(d.ctx, (ID3D11Resource*)st, 0, D3D11_MAP_READ, 0, &m))) {
            FILE* f = fopen(path, "wb");
            if (f) {
                BITMAPFILEHEADER fh = { 0x4D42 };
                BITMAPINFOHEADER ih = { sizeof ih };
                ih.biWidth = td.Width; ih.biHeight = -(LONG)td.Height; ih.biPlanes = 1; ih.biBitCount = 32;
                fh.bfOffBits = sizeof fh + sizeof ih;
                fh.bfSize = fh.bfOffBits + td.Width * td.Height * 4;
                fwrite(&fh, sizeof fh, 1, f); fwrite(&ih, sizeof ih, 1, f);
                for (UINT y = 0; y < td.Height; y++) fwrite((char*)m.pData + y * m.RowPitch, 4, td.Width, f);
                fclose(f);
                fprintf(stderr, "[present] wrote %s (%ux%u)\n", path, td.Width, td.Height);
            }
            ID3D11DeviceContext_Unmap(d.ctx, (ID3D11Resource*)st, 0);
        }
        ID3D11Texture2D_Release(st);
    }
    ID3D11Texture2D_Release(back);
}

/* --------------------------------------------------------------- window --- */

static HWND    s_hwnd;
static WNDPROC s_game_proc;
static int     s_is_full;
static LONG    s_saved_style;
static RECT    s_saved_rect;
int            g_present_owns_window;   /* iat_bridge.c: the game's own moves and resizes are ignored */

static void set_fullscreen(int on) {
    if (on == s_is_full || !s_hwnd) return;
    if (on) {
        GetWindowRect(s_hwnd, &s_saved_rect);
        MONITORINFO mi = { sizeof mi };
        GetMonitorInfoA(MonitorFromWindow(s_hwnd, MONITOR_DEFAULTTONEAREST), &mi);
        SetWindowLongA(s_hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
        SetWindowPos(s_hwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top,
                     mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top,
                     SWP_FRAMECHANGED | SWP_NOOWNERZORDER);
    } else {
        SetWindowLongA(s_hwnd, GWL_STYLE, s_saved_style);
        SetWindowPos(s_hwnd, NULL, s_saved_rect.left, s_saved_rect.top,
                     s_saved_rect.right - s_saved_rect.left, s_saved_rect.bottom - s_saved_rect.top,
                     SWP_FRAMECHANGED | SWP_NOZORDER | SWP_NOOWNERZORDER);
    }
    s_is_full = on;
    g_rm.fullscreen = on;
    fprintf(stderr, "[present] %s\n", on ? "borderless fullscreen" : "windowed");
}

static void remember_window(void) {
    RECT r;
    if (s_is_full || IsIconic(s_hwnd) || IsZoomed(s_hwnd) || !GetWindowRect(s_hwnd, &r)) return;
    g_rm.win_x = r.left; g_rm.win_y = r.top; g_rm.win_w = r.right - r.left; g_rm.win_h = r.bottom - r.top;
}

enum { ID_SCALE = 100, ID_RES = 200, ID_FULL = 300, ID_PAD = 301, ID_PADINI = 302 };

static void settings_menu(HWND hw) {
    HMENU m = CreatePopupMenu(), sc = CreatePopupMenu(), res = CreatePopupMenu();
    POINT p;
    int i, n = hires_mode_count(), cmd;
    char label[64];
    for (i = 0; i < SCALE_COUNT; i++)
        AppendMenuA(sc, MF_STRING | (i == g_rm.scale ? MF_CHECKED : 0), ID_SCALE + i, k_scale_label[i]);
    for (i = 0; i < n; i++) {
        uint32_t w, h;
        hires_mode(i, &w, &h);
        sprintf(label, "%ux%u%s", w, h, w * 3 == h * 4 ? "" : "  widescreen");
        AppendMenuA(res, MF_STRING | ((int)w == g_rm.res_w && (int)h == g_rm.res_h ? MF_CHECKED : 0),
                    ID_RES + i, label);
    }
    AppendMenuA(m, MF_POPUP, (UINT_PTR)res, "Resolution in game (from the next game)");
    AppendMenuA(m, MF_POPUP, (UINT_PTR)sc, "Scaling\tF12");
    AppendMenuA(m, MF_STRING | (s_is_full ? MF_CHECKED : 0), ID_FULL, "Fullscreen\tF11");
    AppendMenuA(m, MF_SEPARATOR, 0, NULL);
    AppendMenuA(m, MF_STRING | (g_rm.pad ? MF_CHECKED : 0), ID_PAD, "Xbox controller");
    AppendMenuA(m, MF_STRING, ID_PADINI, "Edit controller.ini...");
    {   /* at the mouse if it is over the window (right-click), else its corner (F10) */
        RECT r;
        GetCursorPos(&p);
        GetWindowRect(hw, &r);
        if (!PtInRect(&r, p)) { p.x = r.left + 40; p.y = r.top + 40; }
    }
    cmd = TrackPopupMenu(m, TPM_RETURNCMD | TPM_NONOTIFY, p.x, p.y, 0, hw, NULL);
    DestroyMenu(m);
    if (cmd >= ID_SCALE && cmd < ID_SCALE + SCALE_COUNT) g_rm.scale = cmd - ID_SCALE;
    else if (cmd >= ID_RES && cmd < ID_RES + n) {
        uint32_t w, h;
        hires_mode(cmd - ID_RES, &w, &h);
        g_rm.res_w = (int)w; g_rm.res_h = (int)h;
    } else if (cmd == ID_FULL) set_fullscreen(!s_is_full);
    else if (cmd == ID_PAD) g_rm.pad = !g_rm.pad;
    else if (cmd == ID_PADINI) {
        char path[MAX_PATH], *sl;
        GetModuleFileNameA(NULL, path, MAX_PATH);
        sl = strrchr(path, '\\');
        strcpy(sl ? sl + 1 : path, "controller.ini");
        ShellExecuteA(NULL, "open", "notepad.exe", path, NULL, SW_SHOWNORMAL);
    }
    if (cmd) { remember_window(); remaster_save(); }
}

/* iat_bridge.c's PeekMessageA: a message that is the presenter's alone. */
int present_takes_message(const MSG* m) {
    if (!s_hwnd || m->hwnd != s_hwnd) return 0;
    if (m->message == WM_KEYDOWN || m->message == WM_KEYUP ||
        m->message == WM_SYSKEYDOWN || m->message == WM_SYSKEYUP)
        return m->wParam == VK_F10 || m->wParam == VK_F11 || m->wParam == VK_F12 ||
               (m->wParam == VK_RETURN && (m->lParam & (1 << 29)));
    return m->message == WM_RBUTTONUP || m->message == WM_RBUTTONDOWN;
}

/* Ahead of the game's own window procedure: our keys, and sizing. */
static LRESULT CALLBACK present_proc(HWND h, UINT msg, WPARAM wp, LPARAM lp) {
    int alt_enter = wp == VK_RETURN && (lp & (1 << 29));
    int ours = wp == VK_F10 || wp == VK_F11 || wp == VK_F12 || alt_enter;
    switch (msg) {
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        if (!ours) break;
        if (!(lp & (1 << 30))) {                                        /* not auto-repeat */
            if (wp == VK_F11 || alt_enter) { set_fullscreen(!s_is_full); remaster_save(); }
            if (wp == VK_F12) {
                g_rm.scale = (g_rm.scale + 1) % SCALE_COUNT;
                fprintf(stderr, "[present] scaling: %s\n", k_scale_name[g_rm.scale]);
                remaster_save();
            }
            if (wp == VK_F10) settings_menu(h);
        }
        return 0;
    case WM_KEYUP:
    case WM_SYSKEYUP:
        if (ours) return 0;
        break;
    case WM_SYSCHAR:
        if (wp == VK_RETURN) return 0;                                  /* no beep on Alt+Enter */
        break;
    case WM_RBUTTONUP:
        settings_menu(h);
        return 0;
    case WM_EXITSIZEMOVE:
        remember_window();
        remaster_save();
        break;
    }
    return CallWindowProcA(s_game_proc, h, msg, wp, lp);
}

/* iat_bridge.c: the game subclassing its window (MGL does, at each mode
 * change) goes under the presenter, not over it; the old proc it gets back is
 * the one it would have had. */
WNDPROC present_swap_game_proc(WNDPROC p) {
    WNDPROC old = s_game_proc;
    s_game_proc = p;
    return old;
}

static void adopt_window(HWND h) {
    MONITORINFO mi = { sizeof mi };
    int x, y, w, ht;
    s_hwnd = h;
    g_present_owns_window = 1;
    s_saved_style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
    SetWindowLongA(h, GWL_EXSTYLE, GetWindowLongA(h, GWL_EXSTYLE) & ~WS_EX_TOPMOST);
    SetWindowLongA(h, GWL_STYLE, s_saved_style);
    GetMonitorInfoA(MonitorFromWindow(h, MONITOR_DEFAULTTONEAREST), &mi);
    if (g_rm.win_w > 200 && g_rm.win_h > 150) {
        x = g_rm.win_x; y = g_rm.win_y; w = g_rm.win_w; ht = g_rm.win_h;
    } else {                                        /* 85% of the work area's height, 16:9 */
        RECT r;
        ht = (mi.rcWork.bottom - mi.rcWork.top) * 85 / 100;
        r.left = 0; r.top = 0; r.right = ht * 16 / 9; r.bottom = ht;
        AdjustWindowRectEx(&r, WS_OVERLAPPEDWINDOW, FALSE, 0);
        w = r.right - r.left; ht = r.bottom - r.top;
        x = mi.rcWork.left + ((mi.rcWork.right - mi.rcWork.left) - w) / 2;
        y = mi.rcWork.top + ((mi.rcWork.bottom - mi.rcWork.top) - ht) / 2;
    }
    SetWindowPos(h, HWND_NOTOPMOST, x, y, w, ht, SWP_FRAMECHANGED | SWP_SHOWWINDOW);
    s_game_proc = (WNDPROC)SetWindowLongPtrA(h, GWLP_WNDPROC, (LONG_PTR)present_proc);
    SetWindowTextA(h, "Grand Theft Auto (recompiled)");
    fprintf(stderr, "[present] our window: scaling %s (F10 settings, F11 fullscreen, F12 scaling)\n",
            k_scale_name[g_rm.scale]);
    if (g_rm.fullscreen) set_fullscreen(1);
    pad_start(h);
}

/* The frame's rectangle inside a cw x ch client area. */
static RECT fit(int w, int h, int cw, int ch) {
    int dw, dh;
    if (g_rm.scale == SCALE_INTEGER && cw >= w && ch >= h) {
        int k = min(cw / w, ch / h);
        dw = w * k; dh = h * k;
    } else if ((long long)cw * h > (long long)ch * w) {
        dh = ch; dw = (int)((long long)ch * w / h);
    } else {
        dw = cw; dh = (int)((long long)cw * h / w);
    }
    RECT r = { (cw - dw) / 2, (ch - dh) / 2, (cw - dw) / 2 + dw, (ch - dh) / 2 + dh };
    return r;
}

int present_frame(void* hwnd, const void* bits, int w, int h, int bpp, const void* pal) {
    HWND hw = (HWND)hwnd;
    RECT cr, r;
    if (d.failed || g_rm.classic) return 0;
    if (hw != s_hwnd) adopt_window(hw);
    if (!d.dev && !d3d_init(hw)) return 0;
    if (hw != d.hwnd) return 0;
    if (!GetClientRect(hw, &cr) || cr.right <= 0 || cr.bottom <= 0) return 1;   /* minimized */
    if (!upload(bits, w, h, bpp, (const DWORD*)pal)) return 0;
    r = fit(w, h, cr.right, cr.bottom);
    return d3d_draw(hw, &r, cr.right, cr.bottom, g_rm.scale == SCALE_INTEGER ? SCALE_NEAREST : g_rm.scale, w, h);
}
