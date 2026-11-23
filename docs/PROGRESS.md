# Progress Detail

Phase-by-phase checklist. The README carries the summary; this is the long form.

## Phase 0: Reconnaissance

- [x] Obtain game files (GTA1, GTA2, London 1969, London 1961)
- [x] Extract the GTA1 Windows executable from its InstallShield installer
- [x] PE analysis of all five executables
- [x] Download the official Rockstar freeware releases from archive.org
- [x] Compare executables across all games

## Phase 1: Disassembly

- [x] GTA1: recursive-descent disassembly of the 676 KB `.text` section
- [x] London 1969: disassembly of the 989 KB `.text` section -- 2,137 functions
- [x] Call graph generation
- [x] Jump-table recovery, including biased and padded table starts
- [x] Unaligned data scan for code pointers (GTA1's handler table starts at 0x4B4AD1)
- [x] Immediate-operand seeding for callbacks named only by `push 0x48d4e0`
- [ ] London 1961 disassembly
- [ ] GTA2 (blocked: TAC-packed)

**Relifted on pcrecomp main (November).** `tools/lift.py` runs pcrecomp's own
`disasm32` catalog and `drive32` lifter -- no IDA, no hand-run discovery rounds.
GTA1: **6,625 entries** (2,203 lifted bodies, 4,422 alias stubs for entries
inside another body), 95.7% of `.text` covered, 0 errors, 12 minutes.

The August lift had 2,590 functions from five hand-run discovery rounds and
took about an hour. All but 176 of them are in the new catalog; those 176 start
in the middle of another instruction (0x401921 is inside the `mov` at
0x40191F), so dropping them is a fix.

## Phase 2: Classification

- [x] IAT call analysis: 28 functions call imports, 1,869 are pure game logic
- [x] Identify Miles Sound System wrappers
- [x] Identify Smacker video wrappers
- [x] Identify GDI/rendering functions
- [x] Identify KERNEL32/CRT callers
- [ ] Deep classification (CRT vs custom, via pattern matching)
- [ ] Identify the SciTech MGL rendering functions (embedded, not via IAT)

## Phase 3: Code lifting

- [x] GTA1: **6,625 entries, 449,254 lines of C, 0 errors** (August: 2,590 functions, 952,581 lines)
- [x] London 1969: 3,813 functions, 0 errors (2,137 before the discovery fixes)
- [x] Global register model (`eax`-`esp`, plus global `ebp`)
- [x] Memory access via VA translation (`ADDR()` / `MEM32()`)
- [x] Dispatch table for indirect calls
- [x] Import bridge stubs for all 166 imports
- [x] Correct function entry blocks
- [x] Flags evaluated correctly across basic blocks
- [x] London 1969 re-lifted on the current toolkit: **3,813 functions**, 0 errors
- [x] London 1969 on pcrecomp main: **9,954 entries** (5,150 bodies), 75.8% of `.text`, 0 errors, 4 minutes
- [x] London 1969 in game: its menu, `uk.cmp`, driving through West City
- [ ] London 1961 lifting
- [ ] GTA2 lifting (blocked)

## Phase 4: Shimming

- [x] IAT bridge system -- all imports bridged with the correct stdcall convention
- [x] Miles Sound System to a waveOut software mixer (38 `AIL_` functions)
- [x] Sound effects audibly play; sample status derived from the mixer
- [x] Smacker shim (8 ordinals)
- [x] KERNEL32/USER32/GDI32/ADVAPI32 to real Win32 pass-through
- [x] WINMM to real Win32 joystick pass-through
- [x] DPLAYX stub (returns `E_FAIL`)
- [x] DirectDraw shim: our own COM vtables, 75 slots
- [x] Registry shim for `HKLM\SOFTWARE\DMA Design\Grand Theft Auto`
- [ ] SciTech MGL to OpenGL 4.x renderer
- [ ] Cross-platform SDL2 windowing and input

## Phase 5: Build and run

- [x] CMake build system (MSVC 2022, Win32)
- [x] Runtime on the pcrecomp `recomp32` contract
- [x] Image maps at its original base `0x400000`
- [x] Entry through the lifted CRT startup: heap, stdio, locale and codepage
      tables, argv, environment, then WinMain
- [x] All 166 imports bound by name from the image's own import table
- [x] Game opens and reads its own data files
- [x] Window creation, cooperative level, display mode, primary surface
- [x] Palette creation and entries
- [x] Intro movie path
- [x] **First frames rendered -- the title screen**
- [x] Input delivered to the front end -- keys reach the game's WndProc and
      advance it from the title screen to the city-select map
- [x] Mission selection -- the menu sets the mission number and
      `sub_0044AB90` parses `mission.ini`
- [x] The city loads: `nyc.cmp` and `style001.g24` read in full
- [x] Starting the game
- [x] In-game rendering: the city at 320x200, through a primary and seven back buffers

## Phase 6: Playable

- [x] Keyboard input through to the game (default bindings from GTA Settings)
- [x] City map and style loading through the game's own path
- [x] Gameplay loop: walking, stealing a car, driving, traffic, the score
- [x] Quit prompt, results screen, back to the menu, clean exit
- [ ] Joystick
- [x] Sound effects play (verified by mixer peak level)
- [x] Music plays: front-end theme and car radio (verified against the track files, correlation 1.000)
- [ ] Audio verified against the original
- [ ] Save games

## Known gaps

**DirectDraw surfaces are never freed.** The shim's surface table and its
scratch memory are bump-allocated: fine for one game and back to the menu, not
for many. A freelist when it matters.

**Miles timers** fire only when the callback is the plain counter GTA1 uses
(`mov eax,[g] / inc eax / mov [g],eax / ret`); any other is reported and does
not run, since lifted code cannot run on a second thread.

**Rendering path.** Frames reach the screen through `StretchDIBits`, not the
OpenGL renderer the project is aiming at. Correct, and not fast.

**GTA2** is TAC-packed (The Anti-Cracker) in every available version, including
the official Rockstar freeware release. It needs a runtime dump or a dedicated
unpacker before any of this applies to it.
