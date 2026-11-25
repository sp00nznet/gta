/* gta_pad.c -- an SDL2 gamepad mapped to the game's own keys, for the native
 * macOS host.
 *
 * The Windows remaster maps an Xbox controller through XInput onto the
 * game's key bindings (controller.ini, src/remaster/pad.c); here an
 * SDL_GameController is mapped onto the same bindings, synthesized as the
 * keyboard the game reads: win32hle's hle_input_key posts the WM_KEYDOWN /
 * WM_KEYUP a real keypress gives, with the binding's scan code, and the
 * game's WndProc cannot tell it from the keyboard.
 *
 * The bindings are GTA Settings' "Default Keys": the scan codes seeded into
 * the registry (main.c k_controls):
 *   turn left/right/forwards/backwards  arrows
 *   brake                              space
 *   enter/exit vehicle                 enter
 *   attack                             left ctrl
 *   next/previous weapon               X / Z
 *   special                            tab
 * The pad: the stick and the dpad steer, A is the vehicle, B attacks, X
 * brakes, Y is special, the shoulders change weapon, Start is Esc.
 */
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>

#include "win32hle.h"

/* The game's bindings: scan codes, and the virtual keys Windows pairs with
 * them (the game's WndProc reads both out of the message). */
typedef struct { uint32_t vk, scan; } gta_key_t;
static const gta_key_t k_up    = { 0x26, 0xC8 };
static const gta_key_t k_down  = { 0x28, 0xD0 };
static const gta_key_t k_left  = { 0x25, 0xCB };
static const gta_key_t k_right = { 0x27, 0xCD };
static const gta_key_t k_brake = { 0x20, 0x39 };
static const gta_key_t k_enter = { 0x0D, 0x1C };
static const gta_key_t k_atk   = { 0x11, 0x1D };
static const gta_key_t k_nextw = { 0x58, 0x2D };
static const gta_key_t k_prevw = { 0x5A, 0x2C };
static const gta_key_t k_spec  = { 0x09, 0x0F };
static const gta_key_t k_esc   = { 0x1B, 0x01 };

static SDL_GameController *g_pad;

/* A button's state last pump: only the changes post messages, as a key does. */
enum { BTN_A, BTN_B, BTN_X, BTN_Y, BTN_LB, BTN_RB, BTN_START, BTN_STICK_UP, BTN_STICK_DOWN,
       BTN_STICK_LEFT, BTN_STICK_RIGHT, BTN_DPAD_UP, BTN_DPAD_DOWN, BTN_DPAD_LEFT, BTN_DPAD_RIGHT,
       BTN_COUNT };
static const gta_key_t *const k_map[BTN_COUNT] = {
    [BTN_A] = &k_enter, [BTN_B] = &k_atk, [BTN_X] = &k_brake, [BTN_Y] = &k_spec,
    [BTN_LB] = &k_prevw, [BTN_RB] = &k_nextw, [BTN_START] = &k_esc,
    [BTN_STICK_UP] = &k_up, [BTN_STICK_DOWN] = &k_down, [BTN_STICK_LEFT] = &k_left, [BTN_STICK_RIGHT] = &k_right,
    [BTN_DPAD_UP] = &k_up, [BTN_DPAD_DOWN] = &k_down, [BTN_DPAD_LEFT] = &k_left, [BTN_DPAD_RIGHT] = &k_right,
};
static int g_held[BTN_COUNT];

static void set_key(const gta_key_t *k, int down) { hle_input_key(down, k->vk, k->scan); }

static void pad_button(int idx, int down) {
    if (idx < 0 || idx >= BTN_COUNT || !k_map[idx] || g_held[idx] == down) return;
    g_held[idx] = down;
    set_key(k_map[idx], down);
}

/* The stick is two keys, one per axis, with hysteresis: a stick that leans
 * a little must not chatter between left and right. */
static void pad_axis(int axis, int16_t v, int neg_idx, int pos_idx) {
    enum { OFF = 8000, ON = 12000 };
    int neg = g_held[neg_idx], pos = g_held[pos_idx];
    if (axis == SDL_CONTROLLER_AXIS_LEFTX || axis == SDL_CONTROLLER_AXIS_LEFTY) {
        if (v <= -ON && !neg) { pad_button(neg_idx, 1); if (pos) pad_button(pos_idx, 0); }
        else if (v >= ON && !pos) { pad_button(pos_idx, 1); if (neg) pad_button(neg_idx, 0); }
        else if (neg && v > -OFF) pad_button(neg_idx, 0);
        else if (pos && v < OFF) pad_button(pos_idx, 0);
    }
}

/* Open the first pad (and say which), if SDL has one. */
static void pad_connect(void) {
    if (g_pad || SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0) return;
    for (int i = 0; i < SDL_NumJoysticks() && !g_pad; i++)
        if (SDL_IsGameController(i)) {
            g_pad = SDL_GameControllerOpen(i);
            if (g_pad) {
                const char *name = SDL_GameControllerName(g_pad);
                fprintf(stderr, "[pad] %s connected: stick/dpad steer, A vehicle, B attack, X brake, Y special, shoulders weapons, Start Esc\n",
                        name ? name : "a controller");
            }
        }
}

void gta_pad_start(void) { pad_connect(); }

/* Called from the pump: the game is not polling SDL, so the pad is read here,
 * once per frame's message loop. */
void gta_pad_pump(void) {
    if (!g_pad) { pad_connect(); return; }
    pad_axis(SDL_CONTROLLER_AXIS_LEFTX, SDL_GameControllerGetAxis(g_pad, SDL_CONTROLLER_AXIS_LEFTX),
             BTN_STICK_LEFT, BTN_STICK_RIGHT);
    pad_axis(SDL_CONTROLLER_AXIS_LEFTY, SDL_GameControllerGetAxis(g_pad, SDL_CONTROLLER_AXIS_LEFTY),
             BTN_STICK_UP, BTN_STICK_DOWN);
    pad_button(BTN_A, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_A));
    pad_button(BTN_B, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_B));
    pad_button(BTN_X, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_X));
    pad_button(BTN_Y, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_Y));
    pad_button(BTN_LB, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_LEFTSHOULDER));
    pad_button(BTN_RB, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER));
    pad_button(BTN_START, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_START));
    pad_button(BTN_DPAD_UP, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_DPAD_UP));
    pad_button(BTN_DPAD_DOWN, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_DPAD_DOWN));
    pad_button(BTN_DPAD_LEFT, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_DPAD_LEFT));
    pad_button(BTN_DPAD_RIGHT, SDL_GameControllerGetButton(g_pad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT));
}
