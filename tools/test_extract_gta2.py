"""tools/extract_gta2.py's manifest walk.

    python3 -m unittest tools/test_extract_gta2.py
"""
import os, sys, unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from extract_gta2 import walk_manifest  # noqa: E402


def entry(name, path, data, ver=b"1.0"):
    return name + b"\0" + path + b"\0" + ver + b"\0" + str(len(data)).encode() + b"\0" + data


class WalkManifest(unittest.TestCase):
    def test_walk_manifest_two_entries(self):
        blob = b"MZ-stub" + entry(b"a.txt", b"Disk1\\a.txt", b"abc") + entry(b"b.bin", b"Disk1\\b.bin", b"xy")
        self.assertEqual(walk_manifest(blob, 7), [("Disk1/a.txt", b"abc"), ("Disk1/b.bin", b"xy")])

    def test_walk_stops_at_garbage(self):
        blob = entry(b"a.txt", b"a.txt", b"abc") + b"\xff" * 20
        self.assertEqual(walk_manifest(blob, 0), [("a.txt", b"abc")])

    def test_size_past_end_stops(self):
        blob = entry(b"a.txt", b"a.txt", b"abc") + b"b\0b\0" + b"1\0" + b"999\0" + b"xyz"
        self.assertEqual(walk_manifest(blob, 0), [("a.txt", b"abc")])

    def test_path_cannot_climb_out(self):
        blob = entry(b"evil", b"..\\..\\evil", b"x") + entry(b"ok", b"Disk1\\ok", b"y")
        self.assertEqual(walk_manifest(blob, 0), [("Disk1/ok", b"y")])


if __name__ == "__main__":
    unittest.main()
