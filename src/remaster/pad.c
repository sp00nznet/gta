/* pad.c -- Xbox (XInput) controller support, mapped by controller.ini.
 * From Gunman Chronicles' recomp (src/runtime/pad.c), keys only.
 *
 * Nothing in the game changes: each pad input presses a KEY, posted to the
 * game window as WM_KEYDOWN/UP with the key's scan code -- which is how GTA1
 * reads its ten bindings (HKLM\...\Grand Theft Auto\Controls; the defaults
 * are in iat_bridge.c). So the pad does whatever that key does, in the menus
 * and on the street. The left stick and the d-pad are the arrow keys. The pad
 * only acts while the game window is in front.
 *
 * controller.ini sits beside the executable and is written with the defaults
 * on first run. controller=0 in the settings (or --no-pad) turns this off.
 */
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "remaster.h"

static char s_ini[MAX_PATH];

typedef struct { WORD wButtons; BYTE bLeftTrigger, bRightTrigger; SHORT sThumbLX, sThumbLY, sThumbRX, sThumbRY; } XPAD;
typedef struct { DWORD dwPacketNumber; XPAD Gamepad; } XSTATE;
typedef DWORD (WINAPI *xinput_get_state)(DWORD, XSTATE*);

enum { ACT_NONE, ACT_KEY };
typedef struct { int kind, code; } action_t;       /* KEY: a virtual key */

/* Pad inputs, in controller.ini's names. The first 14 are XInput button bits. */
static const struct { const char* name; WORD bit; } k_buttons[] = {
    { "dpad_up", 0x0001 }, { "dpad_down", 0x0002 }, { "dpad_left", 0x0004 }, { "dpad_right", 0x0008 },
    { "start", 0x0010 }, { "back", 0x0020 }, { "left_stick", 0x0040 }, { "right_stick", 0x0080 },
    { "lb", 0x0100 }, { "rb", 0x0200 }, { "a", 0x1000 }, { "b", 0x2000 }, { "x", 0x4000 }, { "y", 0x8000 },
};
#define NBUTTONS (sizeof k_buttons / sizeof k_buttons[0])
enum { IN_LT = NBUTTONS, IN_RT, IN_STICK_UP, IN_STICK_DOWN, IN_STICK_LEFT, IN_STICK_RIGHT, IN_COUNT };
static const char* const k_extra[] = { "lt", "rt", "stick_up", "stick_down", "stick_left", "stick_right" };

static action_t s_map[IN_COUNT];
static float s_dead = 0.30f;
static int   s_trigger = 60;        /* 0..255: how far a trigger counts as pressed */
static HWND  s_hwnd;

static const char k_default_ini[] =
"; Grand Theft Auto recompiled -- Xbox controller mapping.\r\n"
"; Each pad input presses a key, so it does whatever that key does in the game;\r\n"
"; the keys below are the game's own defaults. Delete this file to get these back.\r\n"
";\r\n"
"; Keys: a letter or digit, SPACE CTRL SHIFT ALT TAB ENTER ESCAPE BACKSPACE,\r\n"
"; UPARROW DOWNARROW LEFTARROW RIGHTARROW, F1-F12, INS DEL HOME END PGUP PGDN,\r\n"
"; [ ] SEMICOLON ' , . / - = `, or NONE.\r\n"
"\r\n"
"rt = CTRL              ; attack\r\n"
"lt = SPACE             ; brake, jump\r\n"
"a = ENTER              ; get in or out of a car; menus: select\r\n"
"b = SPACE              ; brake, jump\r\n"
"x = TAB                ; special (the horn)\r\n"
"y = ENTER              ; get in or out of a car\r\n"
"lb = Z                 ; previous weapon\r\n"
"rb = X                 ; next weapon\r\n"
"start = ESCAPE         ; the quit prompt; menus: back\r\n"
"back = ESCAPE\r\n"
"left_stick = NONE\r\n"
"right_stick = NONE\r\n"
"dpad_up = UPARROW      ; forwards, accelerate\r\n"
"dpad_down = DOWNARROW  ; backwards, reverse\r\n"
"dpad_left = LEFTARROW  ; turn left\r\n"
"dpad_right = RIGHTARROW ; turn right\r\n"
"\r\n"
"; the left stick\r\n"
"stick_up = UPARROW\r\n"
"stick_down = DOWNARROW\r\n"
"stick_left = LEFTARROW\r\n"
"stick_right = RIGHTARROW\r\n"
"\r\n"
"stick_deadzone = 0.30  ; 0..1 of the stick's travel that is ignored\r\n"
"trigger_press = 60     ; 0..255 of a trigger's travel that counts as pressed\r\n";

static int parse_key(const char* v, action_t* a) {
    static const struct { const char* n; int kind, code; } names[] = {
        { "NONE", ACT_NONE, 0 }, { "SPACE", ACT_KEY, VK_SPACE }, { "CTRL", ACT_KEY, VK_CONTROL },
        { "SHIFT", ACT_KEY, VK_SHIFT }, { "ALT", ACT_KEY, VK_MENU }, { "TAB", ACT_KEY, VK_TAB },
        { "ENTER", ACT_KEY, VK_RETURN }, { "ESCAPE", ACT_KEY, VK_ESCAPE }, { "BACKSPACE", ACT_KEY, VK_BACK },
        { "UPARROW", ACT_KEY, VK_UP }, { "DOWNARROW", ACT_KEY, VK_DOWN }, { "LEFTARROW", ACT_KEY, VK_LEFT },
        { "RIGHTARROW", ACT_KEY, VK_RIGHT }, { "INS", ACT_KEY, VK_INSERT }, { "DEL", ACT_KEY, VK_DELETE },
        { "HOME", ACT_KEY, VK_HOME }, { "END", ACT_KEY, VK_END }, { "PGUP", ACT_KEY, VK_PRIOR },
        { "PGDN", ACT_KEY, VK_NEXT }, { "[", ACT_KEY, VK_OEM_4 }, { "]", ACT_KEY, VK_OEM_6 },
        { "SEMICOLON", ACT_KEY, VK_OEM_1 }, { "'", ACT_KEY, VK_OEM_7 }, { ",", ACT_KEY, VK_OEM_COMMA },
        { ".", ACT_KEY, VK_OEM_PERIOD }, { "/", ACT_KEY, VK_OEM_2 }, { "-", ACT_KEY, VK_OEM_MINUS },
        { "=", ACT_KEY, VK_OEM_PLUS }, { "`", ACT_KEY, VK_OEM_3 },
    };
    for (size_t i = 0; i < sizeof names / sizeof names[0]; i++)
        if (!_stricmp(v, names[i].n)) { a->kind = names[i].kind; a->code = names[i].code; return 1; }
    if (v[0] && !v[1] && isalnum((unsigned char)v[0])) { a->kind = ACT_KEY; a->code = toupper((unsigned char)v[0]); return 1; }
    if ((v[0] == 'F' || v[0] == 'f') && atoi(v + 1) >= 1 && atoi(v + 1) <= 12) { a->kind = ACT_KEY; a->code = VK_F1 + atoi(v + 1) - 1; return 1; }
    return 0;
}

static void apply_line(char* line, int lineno) {
    char* c = strchr(line, ';');                    /* a comment (the ; key is SEMICOLON) */
    if (c) *c = 0;
    char* eq = strchr(line, '=');
    if (!eq) return;
    *eq = 0;
    char *k = line, *v = eq + 1;
    while (*k == ' ' || *k == '\t') k++;
    for (char* e = k + strlen(k); e > k && (e[-1] == ' ' || e[-1] == '\t'); ) *--e = 0;
    while (*v == ' ' || *v == '\t') v++;
    for (char* e = v + strlen(v); e > v && (e[-1] == ' ' || e[-1] == '\t' || e[-1] == '\r' || e[-1] == '\n'); ) *--e = 0;
    if (!*k) return;
    if (!_stricmp(k, "stick_deadzone")) { s_dead = (float)atof(v); return; }
    if (!_stricmp(k, "trigger_press")) { s_trigger = atoi(v); return; }
    for (int i = 0; i < IN_COUNT; i++) {
        const char* n = i < (int)NBUTTONS ? k_buttons[i].name : k_extra[i - NBUTTONS];
        if (_stricmp(k, n)) continue;
        if (!parse_key(v, &s_map[i]))
            fprintf(stderr, "[pad] controller.ini line %d: unknown key '%s'\n", lineno, v);
        return;
    }
    fprintf(stderr, "[pad] controller.ini line %d: unknown setting '%s'\n", lineno, k);
}

static void load_ini(void) {
    if (!s_ini[0]) {                                /* beside the executable */
        GetModuleFileNameA(NULL, s_ini, MAX_PATH);
        char* sl = strrchr(s_ini, '\\');
        strcpy(sl ? sl + 1 : s_ini, "controller.ini");
    }
    FILE* f = fopen(s_ini, "rb");
    if (!f) {                                       /* first run: write the defaults */
        f = fopen(s_ini, "wb");
        if (f) { fwrite(k_default_ini, 1, sizeof k_default_ini - 1, f); fclose(f); }
        f = fopen(s_ini, "rb");
    }
    char line[256];
    int n = 0;
    if (f) {
        while (fgets(line, sizeof line, f)) apply_line(line, ++n);
        fclose(f);
    } else {                                        /* read-only folder: defaults from memory */
        char buf[sizeof k_default_ini];
        memcpy(buf, k_default_ini, sizeof buf);
        for (char* l = strtok(buf, "\n"); l; l = strtok(NULL, "\n")) apply_line(l, ++n);
    }
}

static void press(int vk, int down) {
    UINT sc = MapVirtualKeyA(vk, MAPVK_VK_TO_VSC);
    LPARAM lp = 1 | (sc << 16) | (down ? 0 : (3u << 30));
    if (vk == VK_UP || vk == VK_DOWN || vk == VK_LEFT || vk == VK_RIGHT || vk == VK_INSERT ||
        vk == VK_DELETE || vk == VK_HOME || vk == VK_END || vk == VK_PRIOR || vk == VK_NEXT)
        lp |= 1 << 24;                              /* extended: GTA reads the scan code */
    if (s_hwnd) PostMessageA(s_hwnd, down ? WM_KEYDOWN : WM_KEYUP, vk, lp);
}

/* Several inputs can press one key (the stick and the d-pad are both the
 * arrows): the key goes down with the first and up with the last. */
static int s_key_count[256];

static void press_counted(const action_t* a, int down) {
    if (a->kind != ACT_KEY) return;
    int c = (s_key_count[a->code & 255] += down ? 1 : -1);
    if ((down && c == 1) || (!down && c == 0)) press(a->code, down);
}

/* One axis past a deadzone, rescaled to 0..1 beyond it. */
static float axis(SHORT raw, float dead) {
    float v = raw / 32767.0f;
    float m = fabsf(v);
    if (m < dead) return 0;
    return (v > 0 ? 1 : -1) * fminf(1.0f, (m - dead) / (1 - dead));
}

static DWORD WINAPI pad_thread(LPVOID unused) {
    (void)unused;
    HMODULE x = LoadLibraryA("xinput1_4.dll");
    if (!x) x = LoadLibraryA("xinput9_1_0.dll");
    xinput_get_state get = x ? (xinput_get_state)GetProcAddress(x, "XInputGetState") : NULL;
    if (!get) { fprintf(stderr, "[pad] no XInput on this system: controller support off\n"); return 0; }
    int held[IN_COUNT] = {0}, connected = -1;
    for (;;) {
        Sleep(8);
        XSTATE st;
        int ok = get(0, &st) == ERROR_SUCCESS;
        if (ok != connected) {
            fprintf(stderr, "[pad] controller %s\n", ok ? "connected" : "not connected");
            connected = ok;
        }
        int in[IN_COUNT] = {0};
        if (ok && g_rm.pad && GetForegroundWindow() == s_hwnd) {
            const XPAD* g = &st.Gamepad;
            for (size_t i = 0; i < NBUTTONS; i++) in[i] = (g->wButtons & k_buttons[i].bit) != 0;
            in[IN_LT] = g->bLeftTrigger > s_trigger;
            in[IN_RT] = g->bRightTrigger > s_trigger;
            float mx = axis(g->sThumbLX, s_dead), my = axis(g->sThumbLY, s_dead);
            in[IN_STICK_UP] = my > 0.35f; in[IN_STICK_DOWN] = my < -0.35f;
            in[IN_STICK_RIGHT] = mx > 0.35f; in[IN_STICK_LEFT] = mx < -0.35f;
        }
        for (int i = 0; i < IN_COUNT; i++)
            if (in[i] != held[i]) { press_counted(&s_map[i], in[i]); held[i] = in[i]; }
    }
}

void pad_start(void* hwnd) {
    static int started;
    s_hwnd = (HWND)hwnd;
    if (started || g_rm.classic) return;
    started = 1;
    load_ini();
    CreateThread(NULL, 0, pad_thread, NULL, 0, NULL);
    fprintf(stderr, "[pad] Xbox controller support %s (%s)\n", g_rm.pad ? "on" : "off", s_ini);
}

#ifdef PAD_SELFTEST
/* cl /nologo /DPAD_SELFTEST src\remaster\pad.c user32.lib && pad.exe */
remaster_t g_rm;
int main(void) {
    GetTempPathA(MAX_PATH, s_ini);
    strcat(s_ini, "controller.ini");
    DeleteFileA(s_ini);
    load_ini();                                     /* writes and reads the defaults */
    int ok = s_map[IN_RT].kind == ACT_KEY && s_map[IN_RT].code == VK_CONTROL
          && s_map[10].code == VK_RETURN                              /* a */
          && s_map[8].code == 'Z' && s_map[9].code == 'X'             /* lb, rb */
          && s_map[IN_STICK_UP].code == VK_UP && s_map[0].code == VK_UP
          && fabsf(s_dead - 0.30f) < 0.001f;
    char l1[] = "x = SEMICOLON   ; comment", l2[] = "b = nonsense";
    apply_line(l1, 1); apply_line(l2, 2);           /* the second prints a warning */
    ok = ok && s_map[12].kind == ACT_KEY && s_map[12].code == VK_OEM_1;
    action_t up = { ACT_KEY, VK_UP };               /* two inputs on one key */
    press_counted(&up, 1); press_counted(&up, 1); press_counted(&up, 0);
    ok = ok && s_key_count[VK_UP] == 1;
    DeleteFileA(s_ini);
    puts(ok ? "pad self-test OK" : "pad self-test FAILED");
    return !ok;
}
#endif
