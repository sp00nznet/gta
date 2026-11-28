"""GTA2's post-lift patches to the generated C (tools/patch_gen.py's shape,
GTA2's own -- never run GTA1's patch_gen on this lift: its patches are by
GTA1 address and would land here as corruption).

    py -3 tools/patch_gen_gta2.py [src/recomp/gen_gta2]

Hooks, at a function's top, written model-agnostically (g_eax/g_esp: at the
top of a body the globals still hold the entry state in both register
models). None today.

(sub_004C3910, the startup timing logger, was answered as a no-op here
while its popped esi came back garbage. The cause was the lifter's: the
TSC reader at 0x004C3850 brackets rdtsc with pushaw/popaw, which it
dropped, so the two stores meant for its own frame landed 16 bytes up on
the caller's saved esi and ebx. pcrecomp lifts the pair now.)
"""
import glob, os, sys

HOOKS = {}

out = sys.argv[1] if len(sys.argv) > 1 else os.path.join('src', 'recomp', 'gen_gta2')
done = 0
for p in sorted(glob.glob(os.path.join(out, 'recomp_0*.c'))):
    s = open(p, encoding='utf-8', newline='').read()
    orig = s
    for fn, line in HOOKS.items():
        needle = 'void %s(void) {' % fn
        mark = line.split(';')[0]
        if needle in s and mark not in s:
            i = s.index(needle) + len(needle)
            s = s[:i] + '\n    ' + line + s[i:]
            done += 1
    if s != orig:
        open(p, 'w', encoding='utf-8', newline='').write(s)
print('gta2 patches applied:', done)
