"""Post-lift patches to the generated C.

The lifted C is generated on the user's machine and never committed, so the
remaster's changes to the game's own code are applied here, after every lift,
instead of to any file of the game's. Two kinds:

  HOOKS   one line at the top of a function; the hook reads the function's
          arguments off the simulated stack (esp+4 is the first) and may
          change them.
  LINES   one lifted instruction, found by its address comment, replaced.
  TABLES  a table in the game's .data moved somewhere bigger.

Idempotent: re-run after every re-lift.

    py -3 tools/patch_gen.py [src/recomp/gen]
"""
import glob, os, re, sys

HOOKS = {   # function -> the line put at its top (GTA1 addresses)
    # FatalError: return instead of exiting under GTA_SOFT_FATAL.
    # g_esp/g_eax, not the esp/eax aliases: the hook runs at the very top of
    # the body, before RECOMP_REGS_LOCALS declares the l_* locals a
    # RECOMP_LOCAL_REGS build uses, and there the globals still hold the live
    # entry state in both register models.
    'sub_00422900': 'extern int recomp_fatal_soft(void); if (recomp_fatal_soft()) { g_esp += 4; return; }',
    # The remaster's resolutions (src/remaster/hires.c): MGL's mode sizes, as
    # the game's mode table sees them, and the in-game mode change.
    'sub_0048B770': 'extern int hires_mode_resolution(void); if (hires_mode_resolution()) { g_eax = 1; g_esp += 4; return; }',
    'sub_00414CC0': 'extern void hires_on_change_mode(void); hires_on_change_mode();',
    # set the mission number: --coop plays a network game on the campaign (src/net/coop.c)
    'sub_0044AB50': 'extern void coop_on_set_mission(void); coop_on_set_mission();',
}

LINES = {   # instruction address -> its replacement
    # The mode table keeps modes up to 1600 wide, 4:3 or 16:10: up to 3840
    # wide, any shape.
    '0x0041541E': 'if ((int32_t)ecx > 3840) goto L_004154B2;',
    '0x0041545A': '/* any shape (hires.c) */;',
    # The camera's projection scale is width * zoom / 320; Hor+ makes the
    # width the one a 4:3 frame of this height would have (hires.c).
    '0x0043BB10': 'extern uint32_t hires_view_width(uint32_t); edx = hires_view_width(ecx);',
    '0x0043C9A3': 'extern uint32_t hires_view_width(uint32_t); edx = hires_view_width(ecx);',
}

# A table the game keeps in .data, moved: the frame's row addresses, one per
# scanline, at 0x503228 with room for 1706 rows. 2160 rows ran over the mode
# table after it (0x504CD0). They live in hires.c's g_rows_va now.
TABLES = [
    (re.compile(r'\* 4 \+ 0x503228\b'), '* 4 + g_rows_va'),
    (re.compile(r'\* 4 \+ 0x503224\b'), '* 4 + (g_rows_va - 4)'),   # row[i - 1]
]
DECL = '#include "recomp_funcs.h"'

out = sys.argv[1] if len(sys.argv) > 1 else os.path.join('src', 'recomp', 'gen')
done = 0
for p in sorted(glob.glob(os.path.join(out, 'recomp_0*.c'))):
    s = open(p, encoding='utf-8', newline='').read()
    orig = s
    for rx, new in TABLES:
        s, n = rx.subn(new, s)
        done += n
    if 'g_rows_va' in s and 'extern uint32_t g_rows_va;' not in s:
        s = s.replace(DECL, DECL + '\nextern uint32_t g_rows_va;', 1)
    for fn, line in HOOKS.items():
        needle = 'void %s(void) {' % fn
        call = line.split(';')[1].strip()        # what marks it as already applied
        if needle in s and call not in s:
            i = s.index(needle) + len(needle)
            s = s[:i] + '\n    ' + line + s[i:]
            done += 1
    lines = s.split('\n')
    for k, l in enumerate(lines):
        for addr, new in LINES.items():
            tag = '/* %s:' % addr
            if tag in l and new not in l:
                indent = l[:len(l) - len(l.lstrip())]
                lines[k] = indent + new + ' ' + l[l.index(tag):]
                done += 1
    s = '\n'.join(lines)
    if s != orig:
        open(p, 'w', encoding='utf-8', newline='').write(s)
print('patches applied:', done)
