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
- [x] CMake build system (MSVC 2022, Win32)
- [x] Runtime rebuilt on the pcrecomp `recomp32` contract (global registers,
      `ADDR()`, `FS_BASE`, shared x87 stack, global `ebp`)
- [x] **Image maps at its original base 0x400000** -- via a self-relaunching
      launcher (see below); the offset-based fallback is gone
- [x] Entry through the lifted CRT startup: heap, stdio, locale/codepage
      tables, argv, environment, then WinMain
- [x] All 166 imports bound **by name** from the image's own import table
- [x] DirectDraw shim: the game drives our own COM vtables
- [x] Registry shim for `HKLM\SOFTWARE\DMA Design\Grand Theft Auto`
- [x] **Game opens and reads its own data files** (`..\gtadata\english.fxt`)
- [ ] First frame rendered

### How it gets 0x400000

Nothing running inside the process can claim the original image base. An 8 MB
`/STACK` reserve lands the host's own main-thread stack there; with that reduced,
kernel32 maps `C_437.NLS`, `l_intl.nls` and the first CRT heap segments through
the range before a TLS callback can run.

So `gta1.exe` launches itself. The parent creates the child `CREATE_SUSPENDED` --
at which point only ntdll, the image and the stack exist -- reserves the range
with `VirtualAllocEx`, and resumes. The child's loader then places NLS and the
heap elsewhere, and the image is *committed into* that reservation rather than
released first, because releasing leaves a hole the loader's own `malloc` falls
into.

### Diagnostics

The bugs in a recompilation surface a long way from their cause, so the runtime
carries its own instruments:

| Variable | What it does |
|---|---|
| `GTA_TRACE` (CMake `-DGTA_TRACE=ON`) | ring of the last 1024 functions entered, with esp and ecx, dumped on a crash |
| `GTA_WATCHDOG_MS=n` | dumps the trace and exits after n ms -- a hang is otherwise indistinguishable from success |
| `GTA_WATCH=0x48dd40,...` | prints esp, ecx and the first four stack arguments on entry to named functions |
| `GTA_BRIDGE_ESP=1` | reports what each IAT bridge actually moved esp by (it should be exactly `4*argc`) |

The runtime also prints the game's own error buffer and decodes its
`FatalError(msgId, line, ...)` calls, whose line number names the failing check.

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

### Game data

The recompiled executable needs the original game's data, and the copy in
`game/extracted/` is a stub -- 171 of its 173 files are zero bytes. Extract the
real data from the installer cabinets:

```bash
python ../tools/tools/assets/isextract.py game/data1.cab game/data1.cab -o game/extracted_full
```

The archive spans `data1.cab` and `data2.cab`; the extractor discovers both and
reports the split (`Volumes: data1.cab [0..17], data2.cab [17..194]`). All 195
files should extract with no errors.

### Run

```bash
cd game/extracted_full/WINO
/path/to/build/bin/Release/gta1.exe "Grand Theft Auto.exe"
```

Run from the directory holding the executable: the game resolves its data as
`..\gtadata\`, relative to its own location. The original executable is the
argument -- it is mapped at 0x400000 so the lifted code can read its `.rdata`
and `.data`.

## Statistics

| Metric | Value |
|--------|-------|
| Functions lifted (GTA1) | **2,590** |
| Lifting errors | **0** |
| Imports bound by name | **166 of 166** |
| DirectDraw methods served | 75 vtable slots |
| Game executables analyzed | 5 |

## Legal

This project contains no copyrighted game assets. You must supply your own copy of the original game(s). The recompilation tools and runtime are MIT licensed.

## Credits

Built with [pcrecomp](https://github.com/sp00nznet/pcrecomp) -- the unified PC static recompilation toolkit.
