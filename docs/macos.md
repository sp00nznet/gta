# macOS, native

The same lifted C as the Windows build, on pcrecomp's `runtime/win32hle`:
a 64-bit arm64 program, no Wine and no Rosetta. Every Win32 import the game
makes is answered by win32hle itself (files, windows and messages, GDI and
palettes, DirectDraw in software, Winsock, the registry), by our own Miles
mixer (`src/macos/gta_mixer.c`), our Smacker stub and our DirectPlay over
TCP (`src/macos/gta_net.c`).

A Mac runs only 64-bit programs, so the guest's 32-bit memory is one 4 GB
block of the host's (win32hle's `guest_mem.c`), at a fixed address
(`RECOMP_MEM_BASE`, 16 TB up), and the lifted code adds a constant to every
address. The drive32 lift takes the fast register model
(`RECOMP_LOCAL_REGS`, indirect-call caches, the x87 ring) redalert2-recomp's
native hosts use.

## The installer

recomp-launcher, as on Windows (`launcher/launcher.json`): the player opens
`GTA-Recomp-Installer.app`, chooses the folder holding Rockstar's freeware
`GTAINSTALLER.zip` (or its `data1.cab`, or an installed copy) and **Build**;
then **Play**. With GTA2's `GTA2.exe` in that folder too (or a folder inside
it), GTA2 is built as well. The app is not signed: the first time, open it
with right-click > Open (or Privacy & Security > Open Anyway). It runs
`setup.sh`, which is also the way by hand:

```
./setup.sh --game-dir ~/Downloads/GTA                  # GTA1, and GTA2 if its GTA2.exe is there
./setup.sh --game-dir ~/Downloads/GTA --targets gta2   # GTA2 required: stop if it is not found
```

It needs Xcode's command line tools and Homebrew, and installs CMake, Ninja,
SDL2, SDL2_ttf, ffmpeg and uv with brew (asking first, unless `--yes`), and
capstone and pefile in a `.venv`. Then it extracts, lifts, patches, builds,
and leaves `Grand Theft Auto (recomp).command` and `GTA2 (recomp).command`
here. Finished steps are skipped (`--force` redoes them); the log is
`setup.log`. GTA2's installer is opened by `tools/extract_gta2.py`.

The installer fetches pcrecomp at the ref `launcher.json` names; the macOS
host needs win32hle's pieces from sp00nznet/pcrecomp PR #200 there.

## Building

Prerequisites: Xcode's command line tools, Homebrew's `cmake ninja pkgconf
sdl2 sdl2_ttf ffmpeg` (ffmpeg plays GTA2's Bink movies; `CMAKE_ARGS=-DWITH_FFMPEG=OFF`
builds without them), Python 3 with `capstone` and `pefile`, a pcrecomp checkout
beside this repository, and your own copy of the game (the folder holding
`WINO` and `GTADATA`).

```
python3 tools/lift.py "<game>/WINO/Grand Theft Auto.exe"
python3 tools/patch_gen.py
./build-macos.sh
```

`game` (a folder or link to the game's install root) is the default place
the host looks, beside where it was invoked and beside the binary.

## Playing

```
build-macos/bin/gta1 --run                 # a window; F11 fullscreen
build-macos/bin/gta1 --run --fullscreen    # borderless
```

| | |
|---|---|
| `--res WxH` | the in-game resolution (the front end is always 640x480) |
| `--view 75` | zoom out: percent of the original camera scale |
| `--scale crt`, `--fullscreen` | the presenter's starting state |
| `--join 192.168.1.20` | where a network game's host is |
| `--port 2350` | where a network game's host listens |
| `--classic` | the original 640x480, no remaster |
| `--pacing frame` | how frames reach the screen: `frame` (the default) on the game's frame boundary, `even` at the flip, `all` every write |
| `--game DIR` | the game's install root, the folder with `WINO` and `GTADATA` (default `./game`) |

In the game: F10 settings (fn+F10, or Cmd+M on a Mac keyboard), F11
fullscreen, F12 scaling. The settings are remembered in `gta-macos.ini`
beside the program. A controller maps to the game's keys: the stick and
dpad steer, A is the vehicle, B attacks, X brakes, Y is special, the
shoulders change weapon, Start is Esc.

Frame pacing: the city runs at 23.3 frames a second and the front end at
~27, by the game's own design. Two limiters stack: `Sleep(35 - elapsed)`
from `_ftime` each frame (28.6 at most), and in the city a spin until a
70 Hz Miles timer has ticked three times (70 / 3 = 23.3). The host's timer
keeps time in microseconds; rounded up to whole milliseconds it ran at
66.7 Hz and the whole game 5% slow.

MGL flips by page: `Flip(page 1)`, then -- having drawn the next frame
straight into the front -- `Flip(page 0)`, the primary, which is already
showing. win32hle's Flip ignored the target and swapped every time, so
every other frame the page from two frames before came back on screen:
the picture stepping back and forth, the camera seeming slow and
flickering (frames captured from the game's memory went A, X, A, Y, A...).
Flip honours its target now. And in the city the host sleeps through the
limiter's spin (a core's worth of CPU) and presents the finished frame the
moment it ends -- complete, on the game's clock (`--pacing frame`, the
default; `even` presents at the flip or the next pump, `all` every write).
On a 60 Hz display a 23.3 fps frame lasts two or three refreshes, five or
six at 120 Hz -- the 1997 game's own cadence.

An overlay folder (`macos-overlay`, beside the game folder, written by the
host if there is none) answers the two file probes the game makes that the
host itself satisfies: MGL will not touch DirectDraw until it finds
`C:\WINDOWS\SYSTEM32\ddraw.dll`, which win32hle answers itself -- the stub
file is never read, only found.

## What is the same, what is this host's

| | Windows host | this host |
|---|---|---|
| Lifted C, remaster hooks, hi-res, widescreen | same | same |
| Presenter | Direct3D 11 | SDL2 (win32hle's screen.c) |
| Input | Win32 messages | the same messages, from SDL2 |
| Controller | XInput | SDL2 gamepad mapped to the keys |
| Sound | waveOut mixer | the same mixer on SDL2 audio |
| Cutscenes | Smacker shim | the same shim (skipped) |
| Network | DirectPlay over TCP | the same star, BSD sockets |
| Settings | F10, an INI | F10, `gta-macos.ini` |

Known gaps: the quit path can fault in MGL's teardown after the game has
already exited (exit code 3, cosmetic); a network game against a Windows
player is untried; GTA: London is not lifted here yet.

## GTA2

The freeware `gta2.exe` (1999) runs on the same host: its own lift
(`src/recomp/gen_gta2`) with its video layer `dmavideo.dll` and its renderer
`d3ddll.dll` lifted beside it and merged into one dispatch
(`tools/merge_dispatch_gta2.py`). It renders through Direct3D 6 -- win32hle's
`d3d.c`, on the GPU through `d3d_metal.m` (Metal; without a Metal device, or
with `GTA2_SOFTWARE_D3D=1`, it rasterises in software) -- at the game's own 30
frames a second. The resolution is the GTA2 Manager's, as on Windows: the
registry's `Screen\full_width` and `full_height`, seeded from `--res WxH`, else
F10's Resolution (remembered in `gta2-macos.ini`), else 1920x1080. The software
rasteriser fills 1080p at ~20 frames a second; the GPU holds the full 30.

```
python3 tools/lift.py gta2-game/extracted/gta2.exe src/recomp/gen_gta2
python3 tools/patch_gen_gta2.py
./build-macos.sh
build-macos/bin/gta2 --run                 # gta2-game/extracted by default
```

Intro (Bink, with sound), menu, and the city: walking, traffic, HUD, the
radio and the game's sounds through the Miles mixer. The radio stations and
the vocals are IMA ADPCM WAVs, decoded on load (bit-exact with Apple's
decoder; played raw they were a hiss). The world's sounds go through Miles
3D: the host offers the provider GTA2 ships and looks for by name
("Microsoft DirectSound3D hardware support"), in software -- volume by
distance as DirectSound3D does it, pan by side, no EAX -- and seeds
`Sound\do_3d_sound`, the GTA2 Manager's "3D Sound" box. What it took past
the intro:

- `IDirect3D3::EnumDevices` lists RGB Emulation before the HAL, as Windows
  does: d3ddll asks for "the second device its callback accepted", and
  with the HAL alone it never created its device.
- Miles' status values are its own bit flags (`SMP_DONE` 2, `SMP_PLAYING`
  4): GTA2 restarted its menu music every frame on reading "playing" as
  "done", and GTA1 never saw a sound as playing.
- The lifter's `pushaw`/`popaw`: GTA2 reads the TSC between the two, and
  without them its stores landed on the caller's saved registers -- the
  garbage pointer the level's object walk faulted on.

Controls: GTA2's own keys (arrows, Ctrl attack, Enter the vehicle, Space
jump and handbrake, Z/X weapons, Tab, Alt and right Shift the specials), and
a controller on them as GTA1's: the stick and dpad steer, A/cross the
vehicle, B/circle attacks, X/square jumps, Y/triangle special, the shoulders
change weapon, the triggers are Specials 2 and 3, Start/Options is Esc, a
DualSense's touchpad the menu. F10 (fn+F10, Cmd+M): scaling, fullscreen, the
resolution (taken as the game starts) and sound, remembered in
`gta2-macos.ini` beside the program.

Bring-up levers, both hosts: `GTA_KEYS="15:enter,19:enter,40:up*3"` plays a
key script (seconds from launch, `*S` holds a key S seconds; `--autotap S`
is one Enter), `GTA_SHOTS=DIR` writes each sampled frame as a PPM,
`HLE_D3DFPS=1` prints the Direct3D scene rate, `--calltrace FILE` every
function entered.

## Why MGL works here

Three things the Windows bringup found were fixed there by the host's own
shims, and are answered structurally here:

- MGL requires DirectDrawCreate **and** DirectDrawCreateClipper from
  ddraw.dll (win32hle now exports the second), or it never registers its
  window class -- and with no class, no WndProc, and no keyboard.
- MGL subclasses the game window with `SetWindowLongA`; in win32hle's
  window manager a WndProc is a guest address, so the 1997 code never runs
  raw as it did on Windows.
- The registry the game cannot start without is seeded by the host, as the
  Windows host's bridges answer it.
