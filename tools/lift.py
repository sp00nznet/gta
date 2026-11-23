#!/usr/bin/env python3
"""Catalog and lift one GTA executable with pcrecomp (no IDA, no commercial tools).

    py -3 tools/lift.py "game/extracted_full/WINO/Grand Theft Auto.exe"            # -> src/recomp/gen
    py -3 tools/lift.py original/.../gta_uk.exe src/recomp/gen_london69

disasm32 writes the catalog to work/<exe>.functions.json (kept until the exe
or the seeds change), drive32 lifts it, and this writes the dispatch table.
PCRECOMP points at a pcrecomp checkout (default ../pcrecomp-gta, then ../pcrecomp).
"""
import json, os, subprocess, sys, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PCR = os.environ.get('PCRECOMP') or next(p for p in (os.path.join(ROOT, '..', d) for d in ('pcrecomp-gta', 'pcrecomp'))
                                         if os.path.isdir(os.path.join(p, 'tools', 'lift')))
TOOLS = os.path.join(PCR, 'tools')
sys.path[:0] = [os.path.join(TOOLS, 'lift'), os.path.join(TOOLS, 'pe')]
from drive32 import lift_image  # noqa: E402


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    exe = sys.argv[1]
    out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(ROOT, 'src', 'recomp', 'gen')
    os.makedirs(os.path.join(ROOT, 'work'), exist_ok=True)
    stem = os.path.basename(exe).lower().replace(' ', '_')
    cat = os.path.join(ROOT, 'work', stem + '.functions.json')
    seeds = os.path.join(ROOT, 'config', stem + '.seeds.json')   # addresses a run found unresolved
    seeds = seeds if os.path.exists(seeds) else None
    t0 = time.time()
    if not os.path.exists(cat) or (seeds and os.path.getmtime(seeds) > os.path.getmtime(cat)):
        if subprocess.run([sys.executable, os.path.join(TOOLS, 'disasm', 'disasm32.py'), exe, '-o', cat]
                          + (['--seed-functions', seeds] if seeds else [])).returncode:
            sys.exit('disasm32 failed')
    st, ent = lift_image(exe, cat, out)
    ent = sorted(set(ent))
    json.dump(st, open(os.path.join(ROOT, 'work', stem + '.lift_stats.json'), 'w'), indent=1, default=str)
    with open(os.path.join(out, 'recomp_funcs.h'), 'w', newline='\n') as f:
        f.write('#pragma once\n#include <stdint.h>\n' + ''.join('void sub_%08X(void);\n' % a for a in ent))
    with open(os.path.join(out, 'recomp_dispatch.c'), 'w', newline='\n') as f:
        f.write('#include "recomp_types.h"\n#include "recomp_funcs.h"\n\n'
                'const recomp_dispatch_entry_t recomp_dispatch_table[] = {\n'
                + ''.join('    { 0x%08Xu, sub_%08X },\n' % (a, a) for a in ent)
                + '};\nconst uint32_t recomp_dispatch_count = %d;\n' % len(ent))
    print('%d functions, %d errors, %.0fs' % (len(ent), st.get('errors', 0), time.time() - t0))


if __name__ == '__main__':
    main()
