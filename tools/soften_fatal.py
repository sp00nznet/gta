"""Make GTA's FatalError (sub_00422900) obey GTA_SOFT_FATAL.

The lifter emits it as an ordinary function, and its callers clean up their own
arguments (cdecl), so an early return only has to pop the dummy return address
that RECOMP_CALL pushed. Re-run this after a re-lift; it is idempotent.
"""
import glob, sys
NEEDLE = 'void sub_00422900(void) {'
GUARD  = 'if (recomp_fatal_soft()) { esp += 4; return; }'
patched = 0
for p in sorted(glob.glob('src/recomp/gen/recomp_0*.c')):
    s = open(p, encoding='utf-8', newline='').read()
    if NEEDLE not in s or GUARD in s:
        continue
    i = s.index(NEEDLE) + len(NEEDLE)
    s = s[:i] + ('\n    extern int recomp_fatal_soft(void);\n    ' + GUARD) + s[i:]
    open(p, 'w', encoding='utf-8', newline='').write(s)
    patched += 1
print('patched files:', patched)
