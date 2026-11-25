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

## Building

Prerequisites: Xcode's command line tools, Homebrew's `cmake ninja pkgconf
sdl2 sdl2_ttf`, Python 3 with `capstone` and `pefile`, a pcrecomp checkout
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
66.7 Hz and the whole game 5% slow. The game draws a frame into the
primary in more than one pass (the city, then the HUD), so presenting each
write showed half-drawn frames as a flicker; the default `--pacing even`
shows one complete frame per game frame (measured: every 42-43 ms in the
city), and `--pacing all` shows every write the moment it lands. On a
60 Hz display a 23.3 fps frame lasts two or three refreshes -- the 1997
game's own cadence, the Windows build's as well.

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
`d3d.c`, rasterised in software -- at the game's own 30 frames a second.

```
python3 tools/lift.py gta2-game/extracted/gta2.exe src/recomp/gen_gta2
python3 tools/patch_gen_gta2.py
./build-macos.sh
build-macos/bin/gta2 --run                 # gta2-game/extracted by default
```

Intro (Bink, with sound), menu, and the city: walking, traffic, HUD, the
menu music and the game's sounds through the Miles mixer (Miles 3D answers
"no provider", so the game mixes in stereo). What it took past the intro:

- `IDirect3D3::EnumDevices` lists RGB Emulation before the HAL, as Windows
  does: d3ddll asks for "the second device its callback accepted", and
  with the HAL alone it never created its device.
- Miles' status values are its own bit flags (`SMP_DONE` 2, `SMP_PLAYING`
  4): GTA2 restarted its menu music every frame on reading "playing" as
  "done", and GTA1 never saw a sound as playing.
- The lifter's `pushaw`/`popaw`: GTA2 reads the TSC between the two, and
  without them its stores landed on the caller's saved registers -- the
  garbage pointer the level's object walk faulted on.

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
