# The remaster

Everything here sits around the game's own code. The lifted C is patched after
every lift by `tools/patch_gen.py` (a hook at the top of a function, one
instruction replaced, or a table moved), and nothing of the game's files is
ever edited. `--classic` turns all of it off: the original 640x480 window,
drawn with GDI, no controller.

```
build\bin\Release\gta1.exe "Grand Theft Auto.exe"                    # the remaster
build\bin\Release\gta1.exe "Grand Theft Auto.exe" --res 2560x1440     # another resolution
build\bin\Release\gta1.exe "Grand Theft Auto.exe" --view 75           # zoomed out
build\bin\Release\gta1.exe "Grand Theft Auto.exe" --classic           # the original
```

| Key | |
|---|---|
| F10, or right-click | the settings menu: resolution, scaling, fullscreen, controller |
| F11, Alt+Enter | borderless fullscreen on the window's monitor, and back |
| F12 | scaling: sharp-bilinear, smooth, CRT, nearest, integer |

## The presenter

`src/remaster/present.c` is Gunman Chronicles' Direct3D 11 presenter, fed
from the DirectDraw shim instead of a GDI DIB. The game still draws into the
shim's surfaces exactly as before; at each flip the frame goes up as a texture
(16-bit frames as B5G6R5, sampled natively; the 8-bit front end through its
palette) and a pixel shader scales it, letterboxed, into a resizable window.
The process is per-monitor DPI aware, so the window is drawn at its real
pixels and Windows does not blur the result. Any Direct3D failure falls back
to the shim's GDI path.

Three things the game does to its window had to be kept from undoing ours:

- **It sizes and styles the window for each display mode.** Once the presenter
  has the window, `SetWindowPos`, `ShowWindow`, `SetWindowPlacement` and
  style changes from the game are answered without being made.
- **MGL subclasses the window at every mode change.** The game's new window
  procedure goes under the presenter's, not over it (`present_swap_game_proc`);
  the first try re-subclassed on top each frame and the two procedures called
  each other until the stack ran out.
- **The game reads keys in its own message loop**, not only in its window
  procedure: F12 opened its in-game video mode menu as well as changing the
  scaling. F10-F12 and Alt+Enter are taken out of the queue in
  `PeekMessageA` and given to the presenter alone.

The settings live in `gta1.ini` beside the executable; a `--flag` on the
command line wins over the file.

```ini
[remaster]
resolution=1920x1080
scale=sharp
fullscreen=0
controller=1
view=100
window=100,100,1600,900
```

## High resolution and widescreen

1280x720, 1366x768, 1600x900, 1920x1080, 2560x1080, 2560x1440, 3440x1440 and
3840x2160, as well as the game's own 4:3 modes. GTA1 draws the city through a
perspective camera, and five things stood between it and a 16:9 screen:

1. **MGL only knows its own modes.** SciTech MGL (linked into the exe) keeps a
   compiled-in record per mode number (maxX, maxY, bits, pages, maxColor, ..,
   aspect) and matches what DirectDraw enumerates against them
   (`sub_00491B00`); nothing is wider than 4:3. Before MGL registers anything,
   eight 16-bit records the game has no use for (modes 0x29-0x30, 320x200 to
   640x400) become the widescreen modes, and the DirectDraw shim lists them.
2. **The game's mode table asks `MGL_modeResolution`**, which answers from
   constants in its code (`sub_0048B770`): hooked for the new modes. The table
   builder also kept only modes up to 1600 wide that are 4:3 or 16:10: both
   tests are lifted.
3. **A game starts in the mode its table index says** (`sub_00414CC0`): the
   index of the settings' resolution now, so the game's idea of its mode and
   the mode agree. (Swapping the mode number alone crashed at 4K: the game
   read the mode's record back by index.)
4. **The frame's row table held 1706 rows.** `sub_00497BFA` writes one address
   per scanline into `.data` at 0x503228, and 2160 rows ran over the mode
   table behind it. Its 110 uses in the lifted C now point at a table of
   4096 rows with room either side (clipped sprites read rows above the top).
5. **The camera was Vert-.** Its projection scale is `width * zoom / 320`
   (0x43BB10, 0x43C9A3), so 16:9 showed the 4:3 width and lost the top and
   bottom; and any frame not 4:3 was taken for 320x200's tall pixels and
   squashed to 5/6. The scale now follows the height (**Hor+**): every mode
   shows at least what 640x480 shows, and widescreen shows more of the city
   to the sides. 640x480 is exactly the original. `view=` below 100 zooms out
   further, at any size.

Known: the HUD (score, pager, the arrow) is drawn at one pixel per pixel, so
at 4K it is small. The front end stays the game's 640x480x8, letterboxed.

## The Xbox controller

`src/remaster/pad.c` is Gunman's XInput mapper, keys only: each pad input
presses a key, posted to the game window with its scan code, which is what
GTA1 reads its ten bindings by. So the pad does whatever that key does, in the
menus and on the street. `controller.ini` sits beside the executable and is
written with the game's own default keys on first run:

| Pad | Key | In game |
|---|---|---|
| left stick, d-pad | arrows | walk, drive |
| RT | Ctrl | attack |
| LT, B | Space | brake, jump |
| A, Y | Enter | get in or out of a car; menus: select |
| X | Tab | special (the horn) |
| LB, RB | Z, X | previous, next weapon |
| Start, Back | Esc | the quit prompt; menus: back |

`cl /DPAD_SELFTEST src\remaster\pad.c user32.lib && pad.exe` checks the
mapping file's parser.

## Setup and the installer

`Setup.cmd` (`tools/setup.ps1`, adapted from Gunman's) checks for Python with
pefile and capstone, pcrecomp beside the repo, and Visual Studio's C++ tools
with CMake, and asks before installing any of them. Then it extracts the game
from Rockstar's `GTAINSTALLER.zip` (or a folder holding `data1.cab`, or an
extracted copy), lifts, patches, builds, and makes a `Grand Theft Auto
(recomp)` shortcut. A rerun skips what is done. Tested from a fresh clone:
extract, lift (6,625 functions, 0 errors), 118 patches, build, shortcut.

The installer is recomp-launcher with `launcher/launcher.json`, built by
`.github/workflows/installer.yml`, as for RA2 and Gunman.
