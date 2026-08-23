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
