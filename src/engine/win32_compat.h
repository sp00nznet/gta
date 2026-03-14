#ifndef GTA_WIN32_COMPAT_H
#define GTA_WIN32_COMPAT_H

/*
 * Win32 API compatibility layer for GTA recompilation.
 *
 * Maps original Win32 API calls to modern equivalents:
 *   KEEP   - Use the real Win32 API (still available on modern Windows)
 *   SHIM   - Thin wrapper to adapt behavior
 *   SDL2   - Replaced by SDL2 equivalent
 *   STUB   - No-op placeholder
 *   CRT    - C runtime equivalent
 *
 * Based on the 166 imports from Grand Theft Auto.exe
 */

/* ===== KERNEL32.dll (63 functions) ===== */
/* Most KEEP -- standard OS services still available on modern Windows */
/* Key shims needed: */
/*   GetVersionExA -> SHIM (return Win98 to satisfy version checks) */
/*   VirtualAlloc  -> KEEP (critical for memory-mapped recomp) */

/* ===== USER32.dll (29 functions) ===== */
/*   CreateWindowExA   -> SDL2 (SDL_CreateWindow) */
/*   ShowWindow        -> SDL2 */
/*   SetTimer          -> SDL2 (SDL_AddTimer) */
/*   GetAsyncKeyState  -> SDL2 (SDL_GetKeyboardState) */
/*   GetCursorPos      -> SDL2 (SDL_GetMouseState) */
/*   PeekMessageA      -> SDL2 (SDL_PollEvent) */
/*   DispatchMessageA  -> SDL2 */
/*   MessageBoxA       -> SDL2 (SDL_ShowSimpleMessageBox) */

/* ===== GDI32.dll (20 functions) ===== */
/* All palette management -- replaced by modern renderer */
/*   CreatePalette      -> STUB (renderer handles color) */
/*   SelectPalette      -> STUB */
/*   RealizePalette     -> STUB */
/*   SetSystemPaletteUse -> STUB */
/*   CreateDIBSection   -> SDL2 (SDL_CreateTexture) */

/* ===== ADVAPI32.dll (4 functions) ===== */
/*   RegOpenKeyExA     -> SHIM (read from config file) */
/*   RegQueryValueExA  -> SHIM (read from config file) */
/*   RegSetValueExA    -> SHIM (write to config file) */
/*   RegCloseKey       -> STUB */

/* ===== WINMM.dll (2 functions) ===== */
/*   joyGetPosEx       -> SDL2 (SDL_GameControllerGetAxis) */
/*   joyGetDevCapsA    -> SDL2 (SDL_GameControllerGetStringForAxis) */

/* ===== DPLAYX.dll (2 functions) ===== */
/*   ordinal 1         -> STUB/SDL2_net (DirectPlayCreate) */
/*   ordinal 2         -> STUB/SDL2_net (DirectPlayEnumerate) */

/* ===== mss32.dll (38 functions) -- Miles Sound System ===== */
/* All replaced by SDL2_mixer shim layer (see src/sound/miles_shim.c) */

/* ===== smackw32.dll (8 functions) -- Smacker Video ===== */
/* All replaced by custom Smacker decoder (see src/video/smacker.c) */

#endif /* GTA_WIN32_COMPAT_H */
