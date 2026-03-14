# Grand Theft Auto -- Static Recompilation

Static recompilation of the original **Grand Theft Auto** (1997), **GTA London 1969/1961**, and **Grand Theft Auto 2** (1999) for modern Windows (x86-64).

No emulation. The original x86 machine code is lifted to compilable C, linked against modern replacements for legacy APIs (SDL2 for windowing/input/audio, OpenGL 4.x for rendering), and compiled into a native executable.

## Supported Games

| Game | Year | Engine | Executable | Status |
|------|------|--------|-----------|--------|
| Grand Theft Auto | 1997 | Race'n'Chase v1 | `Grand Theft Auto.exe` (774 KB) | **In Progress** |
| GTA London 1969 | 1999 | Race'n'Chase v1 | `gta_uk.exe` | Planned |
| GTA London 1961 | 1999 | Race'n'Chase v1 | (shared w/ London 1969) | Planned |
| Grand Theft Auto 2 | 1999 | Race'n'Chase v2 | `gta2.exe` | Planned |

All three games share the **Race'n'Chase Game Engine** developed by Mike Dailly at DMA Design. GTA1 and GTA London use the identical engine (London is a mission pack). GTA2 is an evolution with upgraded rendering (DirectX 6/Direct3D) but very similar file formats and game logic.

## Architecture

The recompilation targets a shared engine core with game-specific modules:

```
src/
  common/       # Shared types, math, memory model
  engine/       # Core engine (main loop, game logic, filesystem, input)
  renderer/     # Modern OpenGL 4.x replacing SciTech MGL (GTA1) / DirectDraw (GTA2)
  sound/        # SDL2 audio replacing Miles Sound System (MSS32)
  video/        # Modern video playback replacing Smacker (smackw32)
  net/          # Network play replacing DirectPlay (DPLAYX)
  gta1/         # GTA1-specific code
  london/       # London-specific data/mission handling
  gta2/         # GTA2-specific code and DX6 renderer bridge
```

## Binary Analysis

### GTA1 (`Grand Theft Auto.exe`)

| Property | Value |
|----------|-------|
| Format | PE32 (i386) |
| Compiler | MSVC 6.0 (linker 6.00) |
| Compiled | 2002-11-11 |
| Image Base | 0x00400000 |
| Code Size | 676,825 bytes (.text) |
| Data Size | 3,052,184 bytes (.data) |
| Entry Point | 0x0049DC30 |

**Imports (166 functions from 8 DLLs):**

| DLL | Functions | Purpose |
|-----|-----------|---------|
| KERNEL32.dll | 63 | OS services, memory, file I/O |
| USER32.dll | 29 | Window management, input |
| GDI32.dll | 20 | GDI graphics (palette management) |
| mss32.dll | 38 | Miles Sound System (audio) |
| smackw32.dll | 8 | RAD Game Tools Smacker (video) |
| ADVAPI32.dll | 4 | Registry access |
| WINMM.dll | 2 | Joystick input |
| DPLAYX.dll | 2 | DirectPlay (multiplayer) |

**Exports:** 23 `glWindowPos*MESA` functions -- confirms embedded SciTech MGL/Mesa OpenGL renderer.

## Progress

### Phase 0: Reconnaissance
- [x] Obtain game installers (GTA1, GTA2)
- [x] Extract GTA1 Windows executable
- [x] PE analysis of GTA1 executable
- [ ] Obtain GTA London 1969/1961
- [ ] PE analysis of GTA London executable
- [ ] Extract and analyze GTA2 executable
- [ ] Compare executables across all 3 games

### Phase 1: Disassembly
- [x] Recursive-descent disassembly of GTA1 .text section (676 KB)
- [x] Function boundary detection -- **1,957 functions** discovered
- [x] Call graph generation
- [ ] Cross-reference analysis

### Phase 2: Classification
- [x] IAT call analysis: 28 functions call imports, **1,869 are pure game logic**
- [x] Identify Miles Sound System wrappers -- **4 functions**
- [x] Identify Smacker video wrappers -- **1 function**
- [x] Identify GDI/rendering functions -- **1 function**
- [x] Identify KERNEL32/CRT callers -- **25 functions**
- [ ] Deep classification (CRT vs custom via pattern matching)
- [ ] Identify SciTech MGL rendering functions (embedded, not via IAT)

### Phase 3: Code Lifting (x86 -> C)
- [x] Lift all 1,957 functions to C -- **238,119 lines**, 0 errors
- [x] Implement register model (globals for eax/ecx/etc.)
- [x] Implement memory access model (VA translation)
- [x] Generate dispatch table for indirect calls (1,957 entries)
- [x] Generate import bridge stubs (166 imports across 8 DLLs)

### Phase 4: Shimming
- [ ] Win32 API -> SDL2 compatibility layer
- [ ] SciTech MGL -> OpenGL 4.x renderer
- [ ] Miles Sound System -> SDL2 audio
- [ ] Smacker -> modern video decoder
- [ ] DirectPlay -> modern networking

### Phase 5: Build & Test
- [x] CMake build system
- [ ] Runtime memory mapping
- [ ] VEH crash handler
- [ ] ICALL dispatch debugging
- [ ] First successful launch

## Building

### Requirements

- CMake 3.20+
- Visual Studio 2022 (MSVC)
- SDL2
- Python 3.10+ (for analysis tools)
- [pcrecomp](https://github.com/sp00nznet/pcrecomp) toolkit

### Build

```bash
cmake -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release
```

## Legal

This project contains no copyrighted game assets. You must supply your own copy of the original game(s). The recompilation tools and runtime are MIT licensed.

## Credits

Built with [pcrecomp](https://github.com/sp00nznet/pcrecomp) -- the unified PC static recompilation toolkit.
