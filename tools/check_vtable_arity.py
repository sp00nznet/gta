#!/usr/bin/env python3
"""
Verify COM vtable arities in the shims against how the game actually calls them.

A wrong arity in a shim's dispatcher is silent. The call returns, the simulated
stack stays short by four bytes for the rest of the run, and the next `pop`
restores a register from the wrong slot. That is how three off-by-one entries in
the DirectPlay table turned into "edi is mysteriously zero" plus an
eight-byte-per-frame stack leak, and neither symptom pointed anywhere near the
table.

The game tells us the right answer. Every vtable call in the lifted code looks
like

    RECOMP_ICALL(MEM32(reg + 0xNN));   /* 0xADDR: call dword ptr [reg + 0xNN] */

and the pushes immediately before it are the arguments, including `this`. Count
them and compare with the table the shim declares.

Usage:
    python tools/check_vtable_arity.py
"""

import glob
import os
import re
import sys

GEN = 'src/recomp/gen/recomp_0*.c'

# Shim tables to check: (source file, C identifier, slots, VA range of the
# module that drives this interface). The range matters: the same vtable offset
# is used by every COM object in the game, so without it a DirectPlay table gets
# checked against DirectDraw and MGL call sites and every line is a false
# positive.
TABLES = [
    ('src/engine/iat_bridge.c', 'k_dp_argc', 32, (0x00486800, 0x00487700)),
]

CALL = re.compile(
    r'RECOMP_ICALL\(MEM32\((?:eax|ebx|ecx|edx|esi|edi|ebp) \+ (0x[0-9A-F]+)\)\);'
    r'\s*/\* (0x[0-9A-F]{8}):')
PUSH = re.compile(r'PUSH32\(esp, [^;]*\); /\* 0x[0-9A-F]{8}: push')
ESPADD = re.compile(r'esp = esp [-+]')
LABEL = re.compile(r'^L_[0-9A-F]{8}:')


def read_table(path, name, slots):
    """Pull the integer initialisers out of a `static const unsigned char N[] = {...}`."""
    src = open(path, encoding='utf-8', errors='replace').read()
    m = re.search(re.escape(name) + r'\[[^\]]*\]\s*=\s*\{(.*?)\};', src, re.S)
    if not m:
        return None
    body = re.sub(r'/\*.*?\*/', '', m.group(1), flags=re.S)
    vals = [int(v) for v in re.findall(r'\b(\d+)\b', body)]
    return vals[:slots]


def count_pushes_before(lines, idx):
    """Arguments pushed for the call on line idx.

    Walks backwards over the pushes that immediately precede it. Stops at a
    label, at any other esp arithmetic, or at a previous call -- anything that
    means the run of pushes has ended.
    """
    n = 0
    for j in range(idx - 1, max(0, idx - 40), -1):
        line = lines[j].strip()
        if not line or line.startswith('_flag') or line.startswith('/*'):
            continue
        if PUSH.search(line):
            n += 1
            continue
        if LABEL.match(line) or ESPADD.search(line) or 'RECOMP_' in line:
            break
        # a plain data move between pushes is normal MSVC scheduling
        if re.match(r'^(eax|ebx|ecx|edx|esi|edi|ebp) =', line) or 'MEM32(' in line:
            continue
        break
    return n


def main():
    gen = sorted(glob.glob(GEN))
    if not gen:
        print('no generated sources; run the lift first', file=sys.stderr)
        return 1

    observed = {}          # slot offset -> {arg count: [call sites]}
    for f in gen:
        lines = open(f, encoding='utf-8', errors='replace').read().split('\n')
        for i, line in enumerate(lines):
            m = CALL.search(line)
            if not m:
                continue
            off, addr = int(m.group(1), 16), m.group(2)
            n = count_pushes_before(lines, i)
            observed.setdefault(off, {}).setdefault(n, []).append(addr)

    problems = 0
    for path, name, slots, (lo, hi) in TABLES:
        table = read_table(path, name, slots)
        if table is None:
            print('could not read %s from %s' % (name, path))
            continue
        print('%s (%d slots), call sites in 0x%06X-0x%06X'
              % (name, len(table), lo, hi))
        for slot, declared in enumerate(table):
            off = slot * 4
            if off not in observed:
                continue
            for count, all_sites in sorted(observed[off].items()):
                sites = [a for a in all_sites if lo <= int(a, 16) < hi]
                if count == 0 or not sites:
                    continue          # other interface, or pushes unreadable
                if count != declared:
                    print('  slot %2d (+0x%02X): table says %d, %d call site(s) push %d'
                          % (slot, off, declared, len(sites), count))
                    print('      e.g. %s' % ', '.join(sites[:4]))
                    problems += 1
    print('mismatches:', problems)
    return 1 if problems else 0


if __name__ == '__main__':
    os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
    sys.exit(main())
