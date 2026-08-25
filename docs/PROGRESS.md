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

Five discovery rounds settle at **2,590 functions** for GTA1. Rounds 4 and 5
come entirely from the data scan and its follow-on -- 382 functions reachable
only through pointers in `.data`.

## Phase 2: Classification

- [x] IAT call analysis: 28 functions call imports, 1,869 are pure game logic
- [x] Identify Miles Sound System wrappers
- [x] Identify Smacker video wrappers
- [x] Identify GDI/rendering functions
- [x] Identify KERNEL32/CRT callers
- [ ] Deep classification (CRT vs custom, via pattern matching)
- [ ] Identify the SciTech MGL rendering functions (embedded, not via IAT)

## Phase 3: Code lifting

- [x] GTA1: **2,590 functions, 952,581 lines of C, 0 errors**
- [x] London 1969: 2,137 functions, 205,665 lines of C, 0 errors
- [x] Global register model (`eax`-`esp`, plus global `ebp`)
- [x] Memory access via VA translation (`ADDR()` / `MEM32()`)
- [x] Dispatch table for indirect calls
- [x] Import bridge stubs for all 166 imports
- [x] Correct function entry blocks
- [x] Flags evaluated correctly across basic blocks
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
- [ ] Starting the game (state 3 is skipped; see Known gaps)
- [ ] In-game rendering

## Phase 6: Playable

- [ ] Keyboard and joystick input through to the game
- [ ] City map and style loading through the game's own path
- [ ] Gameplay loop
- [x] Sound effects play (verified by mixer peak level)
- [ ] Music plays (blocked: the game never calls `AIL_start_stream`)
- [ ] Audio verified against the original
- [ ] Save games

## Known gaps

**The game loads Liberty City but cannot start it.** Driven with
`GTA_KEYS=0x0D,0x28,0x0D,0x28,0x0D` the front end walks 0 -> 7 -> 11 -> 8 -> 6
and opens `nyc.cmp` and `style001.g24`, reading both in full -- through its own
menu, no forcing. It then spins: state 3, which promotes the audio mode, is
skipped, so `sub_00412A90` returns -1 forever and the play state waits on it.
The port takes a "resume" arm of the menu branch where it should take "start".
See docs/BRINGUP.md.

**The quit path faults, and not where I thought.** `VK_ESCAPE` faults at
`0xB0000053`, a bridge cookie executed as code. The earlier write-up blamed CRT
teardown after `ExitProcess`; that is wrong -- `ExitProcess` is never reached,
its bridge never logs. Both `RECOMP_ICALL` and `RECOMP_ITAIL` resolve import
cookies correctly, so the transfer is coming from somewhere else. Unresolved.

`bridge_ExitProcess` now calls the real `ExitProcess` rather than the CRT's
`exit()`, which is what the game asked for and avoids running host atexit
handlers with a lifted window proc on the stack. It does not fix this crash.

**Rendering path.** Frames reach the screen through `StretchDIBits`, not the
OpenGL renderer the project is aiming at. Correct, and not fast.

**GTA2** is TAC-packed (The Anti-Cracker) in every available version, including
the official Rockstar freeware release. It needs a runtime dump or a dedicated
unpacker before any of this applies to it.
