# Technical Analysis

## Race'n'Chase Game Engine

The Race'n'Chase engine was developed by Mike Dailly at DMA Design (later Rockstar North) circa 1995. It powers all three target games:

- **GTA1** (1997): Original engine, DirectDraw/SciTech MGL rendering
- **GTA London 1969/1961** (1999): Identical engine to GTA1, different assets
- **GTA2** (1999): Evolved engine, DirectX 6/Direct3D rendering

### Engine Characteristics

- Top-down 2.5D perspective with textured polygon sprites
- Tile-based city maps (.CMP format)
- Style files (.G24/.GRY) for textures and sprite graphics
- Mission scripting system
- Multi-player support via DirectPlay

## GTA1 Binary Analysis

### PE Structure

```
Image Base:    0x00400000
Entry Point:   0x0049DC30
Code:          0x00401000 - 0x004A63D9 (676,825 bytes)
.rdata:        0x004A7000 - 0x004AAABA (15,034 bytes)
.data:         0x004AB000 - 0x00790298 (3,052,184 bytes)
.rsrc:         0x00791000 - 0x007918B0 (2,224 bytes)
```

### Key Subsystems

#### Rendering (SciTech MGL / Mesa)
The executable exports 23 `glWindowPos*MESA` functions, confirming it embeds a SciTech MGL/Mesa OpenGL software renderer. The game creates a "MGL Fullscreen Application" window and renders via DirectDraw surface blitting.

The renderer handles:
- Tile-based city rendering from .CMP map data
- Sprite rendering from .G24 (24-bit) and .GRY (8-bit) style files
- Palette management (GDI32 palette functions imported)
- Software rasterization blitted to DirectDraw surfaces

**Recomp strategy:** Replace MGL/Mesa with modern OpenGL 4.x. The top-down rendering model maps well to a simple 2D sprite/tile renderer using textured quads.

#### Audio (Miles Sound System)
38 imported functions from `mss32.dll` (Miles Sound System by RAD Game Tools):
- `AIL_startup/shutdown` - initialization
- `AIL_open_stream/close_stream` - music streaming (.WAV tracks)
- `AIL_allocate_sample_handle/release_sample_handle` - sound effects
- `AIL_set_digital_master_volume` - volume control
- `AIL_set_sample_*` - sample playback parameters

**Recomp strategy:** Replace with SDL2_mixer. Map each AIL_ function to equivalent SDL2 audio calls.

#### Video (Smacker)
8 imported ordinals from `smackw32.dll` (RAD Game Tools Smacker):
- Used for intro/cutscene video playback
- Ordinal-based imports (14, 18, 19, 21, 23, 28, 32, 33)

**Recomp strategy:** Replace with modern video decoder (FFmpeg or custom Smacker decoder).

#### Input
- Keyboard/mouse via USER32.dll (GetAsyncKeyState, etc.)
- Joystick via WINMM.dll (joyGetPosEx, joyGetDevCapsA)

**Recomp strategy:** Replace with SDL2 input subsystem.

#### Networking
- DirectPlay via DPLAYX.dll (2 ordinal imports)
- Multiplayer support for LAN play

**Recomp strategy:** Replace with SDL2_net or modern networking library.

#### Registry
- ADVAPI32.dll registry functions for settings storage
- RegOpenKeyExA, RegQueryValueExA, RegSetValueExA, RegCloseKey

**Recomp strategy:** Replace with INI file or JSON config.

### Data Files

| File | Format | Purpose |
|------|--------|---------|
| *.CMP | CityScape Map | City map data (tile layout, heights, zones) |
| *.G24 | 24-bit Graphics | Tile and sprite textures (truecolor) |
| *.GRY | 8-bit Graphics | Tile and sprite textures (paletted) |
| *.FXT | Text | Game text strings (missions, UI) |
| *.FON | Font | Various game fonts |
| *.DAT | Data | Player/mission configuration |
| *.REP | Replay | Demo/replay recordings |
| *.ACT/.RAT/.RAW | Cutscene | Cutscene animation/audio data |
| AUDIO/*.RAW+.SDT | Sound | Level-specific sound effects |
| Music/*.wav | Audio | CD audio tracks (PCM WAV) |

## GTA2 Differences (Preliminary)

GTA2 upgrades the engine with:
- DirectX 6 rendering (DirectDraw + Direct3D)
- Dynamic lighting system
- Smooth camera zooming
- Enhanced 3D geometry for sprites
- Similar but evolved file formats

The rendering subsystem is substantially different and will require a separate implementation, but game logic, physics, and file I/O code should share significant structure with GTA1.

## Import Surface (GTA1)

166 functions from 8 DLLs.

| DLL | Functions | Purpose | Bridge |
|-----|-----------|---------|--------|
| KERNEL32.dll | 63 | OS services, memory, file I/O | Real Win32 pass-through |
| USER32.dll | 29 | Window management, input | Real Win32 pass-through |
| GDI32.dll | 20 | GDI graphics, palette management | Real Win32 pass-through |
| mss32.dll | 38 | Miles Sound System | SDL2 shim |
| smackw32.dll | 8 | RAD Game Tools Smacker | Shim |
| ADVAPI32.dll | 4 | Registry access | Synthetic registry |
| WINMM.dll | 2 | Joystick input | Real Win32 pass-through |
| DPLAYX.dll | 2 | DirectPlay multiplayer | Stub (`E_FAIL`) |

Bridges are bound **by name**, read from the image's own import table, which is
why the PE headers are mapped along with the sections. Binding by index put 30
of them on the wrong slot.

`mss32.dll` imports are decorated stdcall names carrying their byte count
(`_AIL_ms_count@0`), which makes the exe itself the authority on each bridge's
arity -- worth using, since an over-popping bridge in a busy-wait loop walks the
stack pointer off the top of the stack.

## Executables Analyzed

| Game | Year | Executable | Code Size | Compiler | Build Date |
|------|------|-----------|----------|----------|------------|
| Grand Theft Auto | 1997 | `Grand Theft Auto.exe` | 677 KB | MSVC 6.0 | 2002-11-11 |
| Grand Theft Auto | 1997 | `gtawin.exe` (original) | 748 KB | MSVC 4.2 | 1997-10-10 |
| GTA London 1969 | 1999 | `gta_uk.exe` | 989 KB | MSVC 5.1 | 1999-03-12 |
| GTA London 1961 | 1999 | `GTA_61.exe` | 992 KB | MSVC 5.1 | 1999-06-25 |
| Grand Theft Auto 2 | 1999 | `gta2.exe` | 609 KB (TAC packed) | MSVC 5.1 | 1999-12-13 |

Every Windows executable exports the same 23 `glWindowPos*MESA` functions,
confirming the embedded SciTech MGL/Mesa renderer -- except GTA2, which moved to
DirectX.

## MGL Notes

The MGL drivers (`DDRAW8.DRV` and friends) are linked into the executable rather
than loaded, so none of the renderer is visible through the IAT. The mode table
lives at `0x7878C0`: 87 entries of two bytes each, `0xFF` marking a mode as
unavailable. The runtime prints the surviving list on a fault, which is how the
mode negotiation was worked out.

MGL asks for both 8- and 16-bit surfaces at each resolution and will refuse a
mode list offering only one of them.
