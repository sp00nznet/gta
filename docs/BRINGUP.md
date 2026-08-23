# Runtime Bringup

Notes on getting the recompiled GTA1 from "it links" to "it draws its title
screen". These are the problems that were not obvious, and how each one
announced itself.

## How it gets 0x400000

The lifted code reads the original executable's `.rdata` and `.data` at their
real virtual addresses, so the image has to land at `0x00400000`. Nothing
running inside the process can claim that range in time.

An 8 MB `/STACK` reserve puts the host's own main-thread stack there. With that
reduced, kernel32 maps `C_437.NLS`, `l_intl.nls` and the first CRT heap segments
through the range before a TLS callback gets a chance to run.

So `gta1.exe` launches itself. The parent creates the child `CREATE_SUSPENDED` --
at that point only ntdll, the image and the stack exist -- reserves the range
with `VirtualAllocEx`, and resumes it. The child's loader then places NLS and the
heap elsewhere, and the image is *committed into* that reservation rather than
released first, because releasing leaves a hole that the loader's own `malloc`
falls straight into.

`premap_report()` walks low memory and names whatever is sitting in the range,
which is how each of those occupants was identified in the first place.

## Diagnostics

The bugs in a recompilation surface a long way from their cause, so the runtime
carries its own instruments.

| Variable | What it does |
|---|---|
| `GTA_TRACE` (CMake `-DGTA_TRACE=ON`) | ring of the last 1024 functions entered, with esp and ecx, dumped on a crash |
| `GTA_WATCHDOG_MS=n` | dumps the trace and exits after n ms -- a hang is otherwise indistinguishable from success |
| `GTA_WATCH=0x48dd40,...` | prints esp, ecx and the first four stack arguments on entry to the named functions |
| `GTA_BRIDGE_ESP=1` | reports what each IAT bridge actually moved esp by (it should be exactly `4*argc`) |
| `GTA_DDRAW_TRACE=1` | names every DirectDraw method the game calls, not just the interface |
| `GTA_DUMP_FRAMES=n` | writes the first n presented frames to `frameNNN.bmp`, with a count of non-zero bytes |
| `GTA_FORCE_MODE=0x13` | forces an MGL mode index instead of letting the game pick |
| `GTA_KEYS=0x0D,0x28` | posts these virtual-key codes to the game window in order, so an unattended run can drive the front end |
| `GTA_KEY_MS=n` | milliseconds between scripted keys (default 2000) |
| `GTA_KEY_DELAY_MS=n` | wait before the first scripted key (default 3000) |
| `GTA_FILE_TRACE=1` | names every file the game opens, and flags the ones it fails to get |
| `GTA_MISSION=n` | holds the mission-number global at n, bypassing the front end's choice |
| `GTA_AUDIO_TRACE=1` | mixer voice count and peak level once a second, plus every sample start |
| `GTA_AUDIO_MUTE=1` | mix as normal but output silence -- headless runs should not blast the machine |
| `GTA_AUDIO_DUMP=mix.wav` | write the mixed output to a WAV, so it can be measured or listened to later |

The runtime also prints the game's own error buffer and decodes its
`FatalError(msgId, line, ...)` calls, whose line number names the failing check.
`tools/soften_fatal.py` patches that function to return instead of exiting, so a
single failed check does not hide everything behind it.

## Fix log

| # | Fix | How it showed up |
|---|-----|------------------|
| 1 | Self-relaunching launcher to reserve `0x400000` | image loaded at an offset; every absolute address in the lifted code was wrong |
| 2 | `PUSH32` evaluates its operand before moving esp | `push dword ptr [esp+N]` read one slot low, so callees saw the return address as an argument; the CRT died in `_ioinit` |
| 3 | Bind IAT bridges by name from the image's import table | 30 of 167 bridges sat on the wrong slot -- `GetDC` was being serviced by the `SetTimer` bridge, 12 bytes over-popped |
| 4 | `ebp` promoted to a global | `__EH_prolog` sets the *caller's* ebp; a per-function local cannot express that |
| 5 | `neg` sets CF | the `neg/sbb/and/add` branchless null check inverted |
| 6 | `fcom` handled in the flag-consumer path | a two-argument macro was being fed one argument |
| 7 | Jump-table arms are blocks of the switching function, not functions | promoting them produced 721 million dispatches ping-ponging inside `_output` -- a hang, which reads as success |
| 8 | Computed jumps list only the function's own switch arms | listing every label took one generated file from 5 MB to 20 MB and crashed `CL.exe` outright |
| 9 | Pipeline deletes stale generated files | 12 files were being compiled for a 6-file lift |
| 10 | Multi-volume InstallShield extraction | the archive spans `data1.cab` and `data2.cab` with volume-relative offsets; 171 of 173 files had extracted as zero bytes |
| 11 | `precise_sbb`: `sbb r,r` takes the carry of the preceding compare | `cmp/sbb/neg` is how MGL returns success, so its display init reported failure at random |
| 12 | DirectDraw shim: our own COM vtables in game memory | the game drives IDirectDraw, Surface, Palette and Clipper through bridge cookies in each slot |
| 13 | Offer both 8- and 16-bit modes per resolution | MGL rejected the mode list and never created a surface |
| 14 | `Blt` and `BltFast` implemented | MGL renders offscreen and blits to the primary; stubbed, the pixels were drawn and then discarded |
| 15 | Functions enter at their real entry block | 295 of 2,590 functions (11%) began executing at their lowest-addressed block instead, running code that was never called |
| 16 | Flag state carried across a fallthrough edge | `test edx,edx / jg / jl` lost its flags at the second jcc, so the 64-bit sign test read a stale carry |
| 17 | Runtime flag kind for joins (`recomp_cond`) | 474 branches whose predecessors set flags with different instructions, including the `and/jns/dec/or/inc/je` signed-modulo idiom |
| 18 | `AIL_startup`, `AIL_shutdown`, `AIL_ms_count` are `@0`, not `@4` | the game busy-waits on `AIL_ms_count`, so 4 bytes over-popped per call walked esp off the top of the simulated stack after ~1M calls |

Fixes 15 through 17 are one story. All three left a conditional branch reading
whatever carry happened to be lying around, and together they accounted for 598
branches in GTA1 alone. The clearest symptom was `_output` printing `-00` for
`%03d` of zero: its sign test ran on a stale flag, so **every zero looked
negative**, and the game went looking for `LEVEL-00.RAW`.

## The bugs that were not bugs

Two dead ends worth recording, because both looked convincing.

**"The cabinets use one continuous deflate stream."** They do not. That theory
was implemented, hung, and produced 10,240 of 774,144 bytes. The real cause was
the second volume.

**"The failure is in `sub_0048B680`."** It is not; that function is never
entered. `g_cur_func` was reporting the last function entered rather than the
caller, which sent a whole session chasing a path-string helper. It now saves and
restores around `RECOMP_CALL`, and unresolved indirect calls name their caller.

## Input

The game takes input as window messages, not as polled key state: it imports
`GetKeyState` but never `GetAsyncKeyState`, and reads the keyboard only from
inside its own WndProc, reached through `PeekMessageA` / `TranslateMessage` /
`DispatchMessageA`. `RegisterClassA` swaps the game's `lpfnWndProc` -- an address
in the original image -- for a host thunk that calls the lifted function, so the
whole path is real Win32 with the game's own handler at the end of it.

That means a real keypress on the focused window already works, and always did.
What did not work was telling the difference between "waiting for input" and
"stuck", because an unattended run never presses anything. `GTA_KEYS` closes
that gap, and the control run is the proof:

| | With keys | No keys |
|---|---|---|
| distinct frames in 55s | 26 | 9 |
| `GetKeyState` calls | 2 per keypress | 0 |
| `DispatchMessageA` calls | 31 | 31 |

The dispatch count is identical because those are the window's own paint and
timer messages; only the key messages make the game read the keyboard.

### Known: the quit path faults

Sending `VK_ESCAPE` makes the game call `ExitProcess`, which is correct. The
process then faults at `0xB0000053` -- a bridge cookie being *executed* rather
than dispatched. Both `ExitProcess` and `CompareStringW` (cookie 0x53) are
registered bridges, so this is not a missing import.

Unconfirmed reading: the fault is one slot below the `ExitProcess` cookie sitting
in `esi`, and it happens with the WndProc thunk still on the host stack, having
switched to the simulated stack. `bridge_ExitProcess` calls the host CRT's
`exit()` and never returns, so that thunk never unwinds. Something in the
teardown then runs against a half-torn-down stack. Not yet diagnosed.

## Where the front end stops

Input reaches the game and the menu responds to it: watching `sub_0044AB50`,
the mission-number setter, shows it called with `0` at startup and then with
**`1`** after a navigation sequence. So the front end is running, reading keys,
and making a selection. It just never leaves the menu to start the game.

`GTA_FILE_TRACE` rules out missing data as the cause. The front end opens 35
files and **every one of them succeeds** -- the logo and menu-button graphics
(`f_logo0-7`, `f_play1-8`, `f_rstar`), all six fonts including the city-name
fonts `f_city1-4.fon`, the text table, and `LEVEL000.RAW` (which is also the
production confirmation that the `%03d` sign fix holds -- that file is exactly
the one the port used to ask for as `LEVEL-00.RAW`).

`GTA_MISSION` rules out the level name too. Forcing the global to 1 makes
`sub_0044AB90` parse `mission.ini` instead of falling back to the hardcoded
`level001.cmp`, and with that fallback file deleted the game no longer asks for
it and raises no error -- but it still sits on the map screen. Setting what
*would* load does not make the front end decide to load it.

So the remaining gap is narrower than "input" or "data": it is the transition
out of the front-end state machine. The map screen draws the map but no city
labels, despite `f_city1-4.fon` being loaded, which is the most promising thread
to pull -- either those labels are drawn somewhere the port does not present, or
the selection state that would draw them is never entered.

## The front-end state machine

`sub_00426A50` is the main loop, and it switches on `MEM32(0x5101D0)` -- 21
states through a jump table at `0x426F74`. `GTA_WATCH_MEM` polls that global and
reports every change, which turns the front end from a black box into something
you can drive and read.

The observed path, with `GTA_KEYS=0x0D,0x28,0x0D,0x28,0x0D`:

```
0 -> 7 -> 11 -> 8 -> 6
     title  menu  select  play
```

Two states matter:

| State | Handler | What it does |
|---|---|---|
| 3 | `sub_00428680` | starts the game proper: promotes the audio mode via `sub_00412B20`, then `sub_00487000`, `sub_0042D8E0` |
| 6 | `sub_00428BF0` | the play state -- this is what loads the city |

**Reaching state 6 works.** The game opens `..\gtadata\nyc.cmp` and
`..\gtadata\style001.g24` and reads them in full -- 1.8 MB, 1.1 MB and 1.28 MB
of tile and sprite data -- through its own menu, with no forcing. Liberty City
loads.

**State 3 is skipped, and that is where it stops.** `sub_00428680` promotes
`MEM32(0x501D7C)` from 1 to 2. Nothing else does. `sub_00412A90` opens with
`cmp dword ptr [0x501D7C], 2` and returns -1 when it does not match, and its
caller loops on that answer forever: the crash-trace ring comes back with all
1024 entries being that one function. So the game sits in the play state having
loaded the city, spinning on a request that can never succeed.

The two states are reached from different arms of the same branch in the menu
code, on `MEM32(0x511104)`. The arm we take pushes the literal `6` to
`sub_00427030`; the other arm sets `0x5110EC` -- exactly the global
`sub_00428680` reads -- and pushes a computed state. Which is to say the port is
taking a "resume" path where it should take a "start" one.

### AIL_ms_count returned zero forever

Getting that far needed one real fix. `AIL_ms_count` was implemented as
`SDL_GetTicks()`, and this build has no SDL2 -- so it used the stub at the top
of `miles_shim.c`, which returns a constant `0`. The game paces itself on that
counter, so it would load the city and then spin, which looks exactly like a
hang in the level loader.

It now reads the host clock (`GetTickCount()` since `AIL_startup`). A
millisecond counter has no business depending on whether the audio library is
available. With it, the game gets past pacing and into level audio setup:
`AIL_allocate_sample_handle`, `AIL_init_sample` and `AIL_set_sample_type`
seventeen times each, and `AIL_open_stream` on `..//music//track1.wav`.

`SDL_AddTimer` is stubbed the same way, so Miles timers never fire -- but that
turns out not to matter here: `AIL_register_timer` and `AIL_start_timer` are
never called on this path.

## Audio

The Miles shim had all the bookkeeping and none of the output: every entry point
updated a struct and returned, with `/* TODO: actually start SDL2 audio
playback */` where the sound should have been. And SDL2 is not present in this
build, so even the parts that did call SDL fell through to the stubs at the top
of `miles_shim.c` -- which is how `AIL_ms_count` came to return a constant zero
and hang the level loader.

Rather than take the SDL2 dependency (the vcpkg copy on this machine is x64;
this target is Win32), output goes through **waveOut**. `winmm` is already
linked for joystick input, so it costs nothing and works for anyone who clones
the repo.

`src/sound/mixer.c` is a software mixer: 40 voices at 22050 Hz 16-bit stereo,
which is exactly the format of the game's music tracks, so those mix in without
resampling. Sound effects arrive at whatever rate Miles was told -- 24041 Hz
16-bit stereo is typical -- and are point-resampled through a 16.16 accumulator.

### The static

The first version of this played extremely loud noise, and the cause is worth
recording because the mixer was not at fault.

`bridge_AIL_set_sample_type` was a stub: `{ esp += 4+12; }`. It popped its
arguments and returned without calling the shim, so the sample format never
arrived and every voice kept its 8-bit default. The game's samples are 16-bit,
so the mixer read each sample one byte at a time -- which is noise by
construction, at full amplitude, regardless of anything else.

Two things made this harder to see than it should have been. The format is
carried by exactly the call that was stubbed, so nothing in the log contradicted
the wrong value. And a byte histogram of `LEVEL000.RAW` clusters hard at `0x00`
and `0xFF`, which reads as "signed 8-bit" if you have already assumed the data
is 8-bit -- they are the high bytes of small 16-bit samples. Measuring the data
without checking the format first produced a confident wrong answer.

Signedness is now taken from the flags the game passes rather than assumed:
`AIL_set_sample_type`'s `flags` carries `DIG_PCM_SIGN`, and GTA1 sets it
(`format=3 flags=0x1` -- 16-bit stereo, signed). Miles can carry either
convention, so the mixer handles both.

What is wired through:

| Miles | Mixer |
|---|---|
| `AIL_set_sample_address` | voice PCM (borrowed from game memory, not copied) |
| `AIL_set_sample_type` | `DIG_F_` format to bits and channels |
| `AIL_set_sample_playback_rate` | resample step |
| `AIL_set_sample_volume` / `_pan` / `_loop_count` | per-voice gain, pan, loop |
| `AIL_start_sample` / `_stop_` / `_end_` | voice start and stop |
| `AIL_sample_status` | **derived from the mixer** -- see below |
| `AIL_open_stream` | RIFF/WAVE load, chunk-walked |
| `AIL_start_stream` / `_pause_` / `_close_` | voice start, stop, free |
| `AIL_stream_position` | bytes consumed |
| `AIL_set_digital_master_volume` | master gain |

`AIL_sample_status` mattering is not obvious. It used to return whatever status
was last stored, so a sample that finished playing still reported `SMP_PLAYING`
forever -- the game could allocate a voice and never learn it was free again. It
now asks the mixer whether the voice is still running.

`GTA_AUDIO_TRACE=1` reports voice count and peak level about once a second, plus
the parameters of every `AIL_start_sample`. On a headless run that is the only
way to tell "mixing silence" from "mixing nothing":

```
MSS shim: start_sample voice=1 data=04381170 len=135136 24041Hz 8bit 1ch vol=73
  AUDIO: 1 voice(s) playing, peak 7884
```

**Music does not play yet, and that is not an audio bug.** `AIL_open_stream`
loads `track1.wav` (12,083,400 bytes, 22050 Hz 16-bit stereo) and hands it a
voice, but the game never calls `AIL_start_stream` -- it is stuck in the same
state-3 gap described above, so it never gets as far as starting the music.

Verifying audio headlessly is what `GTA_AUDIO_DUMP` is for. Peak level alone
does not distinguish sound from noise; the dumped mix does:

| | broken (8-bit read of 16-bit data) | fixed |
|---|---|---|
| zero-crossing rate | noise-like | **0.086** (white noise is ~0.5) |
| peak / RMS | pinned | 7058 / 898, crest 7.9 |
| clipped samples | constant | **0.000%** |
