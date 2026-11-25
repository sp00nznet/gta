#!/usr/bin/env python3
"""Extract GTA2 from Rockstar's freeware installer (GTA2.exe).

    python3 tools/extract_gta2.py GTA2INSTALLER/GTA2.exe -o gta2-game/extracted

The installer is an InstallShield PackageForTheWeb package, which no open
extractor reads. Past the end of its PE sections it is a plain manifest of
stored files, each one: its name, its path, a version and its size in
decimal ASCII, every one NUL-terminated, then the bytes. Those files are an
ordinary InstallShield setup (Disk1/data1.cab and friends), which
pcrecomp's tools/assets/isextract.py opens -- the same as GTA1's on Windows.
The setup's files go to <out>/payload, the game's to <out>.

PCRECOMP points at a pcrecomp checkout (default ../pcrecomp-gta, then
../pcrecomp, as tools/lift.py looks).
"""
import argparse, os, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def walk_manifest(data, off):
    """The stored files from off on, as (path with '/', bytes), up to the
    first record that is not one. A path that would climb out of the
    destination (absolute, or with '..') is skipped."""
    out = []
    end = len(data)

    def field(o):
        z = data.find(b"\0", o)
        if z < 0 or z - o > 260:
            raise ValueError
        return data[o:z].decode("latin-1"), z + 1

    while off < end:
        try:
            name, o = field(off)
            path, o = field(o)
            _ver, o = field(o)
            size_s, o = field(o)
            size = int(size_s)
        except (ValueError, UnicodeDecodeError):
            break
        if not name or not path or size <= 0 or o + size > end:
            break
        rel = path.replace("\\", "/")
        parts = rel.split("/")
        if not rel.startswith("/") and ":" not in parts[0] and ".." not in parts:
            out.append((rel, data[o:o + size]))
        off = o + size
    return out


def overlay_offset(exe):
    """Where the PE's sections end: the manifest starts there."""
    import pefile
    pe = pefile.PE(exe, fast_load=True)
    return max(s.PointerToRawData + s.SizeOfRawData for s in pe.sections)


def toolkit():
    env = os.environ.get("PCRECOMP")
    cands = [env] if env else [os.path.join(ROOT, "..", d) for d in ("pcrecomp-gta", "pcrecomp")]
    for c in cands:
        if c and os.path.isfile(os.path.join(c, "tools", "assets", "isextract.py")):
            return c
    sys.exit("pcrecomp not found (its tools/assets/isextract.py): set PCRECOMP or clone it beside this repo")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("installer", help="GTA2.exe, Rockstar's freeware installer")
    ap.add_argument("-o", "--out", required=True, help="the folder the game goes to")
    a = ap.parse_args()
    data = open(a.installer, "rb").read()
    files = walk_manifest(data, overlay_offset(a.installer))
    if not files:
        sys.exit("%s: not GTA2's PackageForTheWeb installer (no stored files after its sections)" % a.installer)
    payload = os.path.join(a.out, "payload")
    for rel, blob in files:
        dst = os.path.join(payload, rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as f:
            f.write(blob)
    print("%d files from the installer" % len(files))
    def stored(name):
        return next((os.path.join(payload, r) for r, _ in files if r.lower().endswith("/" + name)), None)
    hdr, cab = stored("data1.hdr"), stored("data1.cab")   # the directory, then the data (data2.cab is found beside it)
    if not hdr or not cab:
        sys.exit("no data1.hdr and data1.cab in the installer's files")
    r = subprocess.run([sys.executable, os.path.join(toolkit(), "tools", "assets", "isextract.py"), hdr, cab, "-o", a.out])
    if r.returncode:
        sys.exit("isextract.py failed on %s" % cab)
    if not any(f.lower() == "gta2.exe" for f in os.listdir(a.out)):
        sys.exit("extracted, but no gta2.exe in %s" % a.out)
    print("GTA2 extracted to %s" % a.out)


if __name__ == "__main__":
    main()
