# Grand Theft Auto -- Static Recompilation

Static recompilation of the original **Grand Theft Auto** (1997), **GTA London 1969/1961**, and **Grand Theft Auto 2** (1999) for modern Windows (x86-64).

No emulation. The original x86 machine code is lifted to compilable C, linked against modern replacements for legacy APIs (SDL2 for windowing/input/audio, OpenGL 4.x for rendering), and compiled into a native executable.

## Supported Games

| Game | Year | Executable | Code Size | Compiler | Date | Status |
|------|------|-----------|----------|----------|------|--------|
| Grand Theft Auto | 1997 | `Grand Theft Auto.exe` | 677 KB | MSVC 6.0 | 2002-11-11 | **Builds & runs** |
| Grand Theft Auto | 1997 | `gtawin.exe` (original) | 748 KB | MSVC 4.2 | 1997-10-10 | Analyzed |
| GTA London 1969 | 1999 | `gta_uk.exe` | 989 KB | MSVC 5.1 | 1999-03-12 | **Lifted** |
| GTA London 1961 | 1999 | `GTA_61.exe` | 992 KB | MSVC 5.1 | 1999-06-25 | Analyzed |
| Grand Theft Auto 2 | 1999 | `gta2.exe` | 609 KB (TAC packed) | MSVC 5.1 | 1999-12-13 | Blocked (packed) |

All games share the **Race'n'Chase Game Engine** developed by Mike Dailly at DMA Design. GTA1 and GTA London use the identical engine (London is a mission pack). GTA2 is an evolution with upgraded rendering (DirectX 6/Direct3D) but very similar file formats and game logic. All Windows executables export the same 23 `glWindowPos*MESA` functions (embedded SciTech MGL/Mesa renderer) except GTA2 which uses DirectX.

**Note:** GTA2 is TAC-packed (The Anti-Cracker) in all available versions including the official Rockstar freeware release. Runtime dump or dedicated unpacking needed.

## Architecture

The recompilation targets a shared engine core with game-specific modules:

```
src/
  common/       # Shared types, math, memory model
  engine/       # Recomp runtime, IAT bridges, main entry point
  renderer/     # Modern OpenGL 4.x replacing SciTech MGL (GTA1) / DirectDraw (GTA2)
  sound/        # SDL2 audio replacing Miles Sound System (MSS32)
  video/        # Modern video playback replacing Smacker (smackw32)
  net/          # Network play replacing DirectPlay (DPLAYX)
  recomp/gen/   # Auto-generated lifted C code (GTA1: 238K lines)
  recomp/gen_london69/  # Auto-generated lifted C code (London: 206K lines)
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
| Entry Point | 0x0049DC30 (CRT startup) |
| WinMain | 0x00437230 |

**Imports (166 functions from 8 DLLs):**

| DLL | Functions | Purpose | Bridge Status |
|-----|-----------|---------|---------------|
| KERNEL32.dll | 63 | OS services, memory, file I/O | All bridged |
| USER32.dll | 29 | Window management, input | All bridged |
| GDI32.dll | 20 | GDI graphics (palette management) | All bridged |
| mss32.dll | 38 | Miles Sound System (audio) | SDL2 shim |
| smackw32.dll | 8 | RAD Game Tools Smacker (video) | Stub (skip) |
| ADVAPI32.dll | 4 | Registry access | All bridged |
| WINMM.dll | 2 | Joystick input | All bridged |
| DPLAYX.dll | 2 | DirectPlay (multiplayer) | Stub |

**Exports:** 23 `glWindowPos*MESA` functions -- confirms embedded SciTech MGL/Mesa OpenGL renderer.

## Progress

### Phase 0: Reconnaissance
- [x] Obtain game files (GTA1, GTA2, London 1969, London 1961)
- [x] Extract GTA1 Windows executable from InstallShield installer
- [x] PE analysis of all 5 executables
- [x] Download official Rockstar freeware releases from archive.org
- [x] Compare executables across all games

### Phase 1: Disassembly
- [x] GTA1: Recursive-descent disassembly of 676 KB .text section -- **1,957 functions**
- [x] London 1969: Disassembly of 989 KB .text section -- **2,137 functions**
- [x] Call graph generation
- [ ] Cross-reference analysis
- [ ] London 1961 disassembly
- [ ] GTA2 (blocked: TAC-packed)

### Phase 2: Classification
- [x] IAT call analysis: 28 functions call imports, **1,869 are pure game logic**
- [x] Identify Miles Sound System wrappers -- **4 functions**
- [x] Identify Smacker video wrappers -- **1 function**
- [x] Identify GDI/rendering functions -- **1 function**
- [x] Identify KERNEL32/CRT callers -- **25 functions**
- [ ] Deep classification (CRT vs custom via pattern matching)
- [ ] Identify SciTech MGL rendering functions (embedded, not via IAT)

### Phase 3: Code Lifting (x86 -> C)
- [x] GTA1: **1,957 functions -> 238,119 lines of C, 0 errors**
- [x] London 1969: **2,137 functions -> 205,665 lines of C, 0 errors**
- [x] Global register model (eax-esp as C globals)
- [x] Memory access via VA translation (MEM32 macros)
- [x] Dispatch table for indirect calls
- [x] Import bridge stubs for all 166 imports
- [ ] London 1961 lifting
- [ ] GTA2 lifting (blocked)

### Phase 4: Shimming
- [x] **IAT bridge system** -- all 167 imports bridged with correct stdcall convention
- [x] Miles Sound System -> SDL2 audio shim (38 AIL_ functions)
- [x] Smacker -> stub decoder (8 ordinals, skips videos)
- [x] KERNEL32/USER32/GDI32/ADVAPI32 -> real Win32 API pass-through
- [x] WINMM -> real Win32 joystick API pass-through
- [x] DPLAYX -> stub (returns E_FAIL)
- [ ] SciTech MGL -> OpenGL 4.x renderer
- [ ] Cross-platform SDL2 windowing/input layer

### Phase 5: Build & Test
- [x] CMake build system (MSVC 2022, Win32, /BASE:0x10000000)
- [x] Runtime: VirtualAlloc memory mapping, VEH crash handler, ICALL trace
- [x] **First successful build** -- 1.7 MB native Win32 executable
- [x] **First test launch** -- game executes WinMain, passes mutex check
- [x] Game reaches CreateMutexA("Grand Theft Auto"), RegOpenKeyExA
- [ ] Fix memory mapping (0x400000 conflict with CRT heap reservation)
- [ ] Get past renderer initialization
- [ ] First frame rendered

### Current Blocker

VirtualAlloc at the original image base (0x400000) fails because the CRT heap
reserves that range before `main()`. The fallback offset-based mapping works for
data reads but breaks pointer arithmetic in the recompiled code. Options:
1. TLS callback to pre-reserve 0x400000 (implemented, not yet working)
2. Launcher process that maps memory before starting the recomp exe
3. Fix pointer translation in generated code

## Building

### Requirements

- CMake 3.20+
- Visual Studio 2022 (MSVC)
- SDL2 (optional -- stubs used when not found)
- Python 3.10+ (for analysis tools)
- [pcrecomp](https://github.com/sp00nznet/pcrecomp) toolkit

### Build

```bash
cmake -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Release
```

### Run

```bash
build/bin/Release/gta1.exe path/to/Grand Theft Auto.exe
```

The original executable is needed for loading .data/.rdata sections into
the memory-mapped address space.

## Statistics

| Metric | Value |
|--------|-------|
| Total functions lifted | **4,094** |
| Total lines of C | **443,784** |
| Lifting errors | **0** |
| IAT bridges | **167** |
| Build output | 1.7 MB native Win32 exe |
| Game executables analyzed | 5 |

## Legal

This project contains no copyrighted game assets. You must supply your own copy of the original game(s). The recompilation tools and runtime are MIT licensed.

## Credits

Built with [pcrecomp](https://github.com/sp00nznet/pcrecomp) -- the unified PC static recompilation toolkit.
