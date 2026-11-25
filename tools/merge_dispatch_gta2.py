"""Merge GTA2's dispatch table: the exe's lift (src/recomp/gen_gta2, base
0x00400000) then dmavideo.dll's (src/recomp/gen_dmavideo, base 0x01000000),
already in address order, as recomp_lookup's binary search needs.

redalert2's host has one lift; Civilization III's (src/linux/dispatch.c) has
three, and this follows it: each module's recomp_dispatch.c holds only its
own rows, and the merged table concatenates them behind one symbol.

    py -3 tools/merge_dispatch_gta2.py
"""
import re, sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GENS = [("src/recomp/gen_gta2", "gta2.exe"),
        ("src/recomp/gen_d3ddll", "d3ddll.dll"),
        ("src/recomp/gen_dmavideo", "Dmavideo.dll")]
OUT = os.path.join(ROOT, "src", "macos", "gta2_dispatch.c")

row = re.compile(r"\{ 0x([0-9A-Fa-f]+)u, (sub_[0-9A-Fa-f]+) \}")
inc = []
for gen, what in GENS:
    src = os.path.join(ROOT, gen, "recomp_dispatch.c")
    if not os.path.exists(src):
        sys.exit("no %s -- lift it first (tools/lift.py %s)" % (src, what))
    rows = row.findall(open(src).read())
    inc.append((gen, rows))
    print("%s: %d rows from %s" % (what, len(rows), gen))

prev = 0
for _, rows in inc:
    for va, _fn in rows:
        va = int(va, 16)
        if va <= prev:
            sys.exit("not in address order: 0x%08X after 0x%08X" % (va, prev))
        prev = va

with open(OUT, "w", newline="\n") as f:
    f.write("/* The merged dispatch table (tools/merge_dispatch_gta2.py): the exe's\n"
            " * lift, then dmavideo.dll's, in address order. The per-module\n"
            " * recomp_dispatch.c are data for this merge and are not compiled.\n"
            " * Civilisation III's Linux host is the pattern (src/linux/dispatch.c). */\n"
            '#include "recomp_types.h"\n')
    for gen, _ in inc:
        f.write('#include "../recomp/%s/recomp_funcs.h"\n' % gen.split("recomp/")[-1])
    f.write("\nconst recomp_dispatch_entry_t recomp_dispatch_table[] = {\n")
    for gen, rows in inc:
        f.write("    /* %s */\n" % gen)
        for va, fn in rows:
            f.write("    { 0x%su, %s },\n" % (va.upper().ljust(8), fn))
    f.write("};\nconst uint32_t recomp_dispatch_count = sizeof recomp_dispatch_table / sizeof *recomp_dispatch_table;\n")
print("wrote %s (%d rows)" % (OUT, prev and sum(len(r) for _, r in inc)))
