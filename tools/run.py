#!/usr/bin/env python3
"""Run the lifted build on a private hidden desktop, muted, and stop it by PID.

    py -3 tools/run.py --secs 60 [--env K=V ...] -- build/bin/Release/gta1.exe "Grand Theft Auto.exe"

The working directory is game/extracted_full/WINO (override with --cwd). Every
run gets its own desktop name, so nothing shows on the real screens and runs
never share one. GTA_AUDIO_MUTE=1 is always set. Output goes to --log.
"""
import argparse, ctypes, ctypes.wintypes as W, os, subprocess, time, uuid

k32, u32 = ctypes.windll.kernel32, ctypes.windll.user32
u32.CreateDesktopW.restype = W.HANDLE
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class SI(ctypes.Structure):
    _fields_ = [('cb', W.DWORD), ('r', W.LPWSTR), ('desk', W.LPWSTR), ('t', W.LPWSTR)] + \
               [(n, W.DWORD) for n in 'x y w h cx cy fill flags'.split()] + \
               [('show', W.WORD), ('r2', W.WORD), ('r3', ctypes.c_void_p),
                ('i', W.HANDLE), ('o', W.HANDLE), ('e', W.HANDLE)]


class PI(ctypes.Structure):
    _fields_ = [('hp', W.HANDLE), ('ht', W.HANDLE), ('pid', W.DWORD), ('tid', W.DWORD)]


def children(pid):
    out = subprocess.run(['powershell', '-NoProfile', '-Command',
                          f'(Get-CimInstance Win32_Process -Filter "ParentProcessId={pid}").ProcessId'],
                         capture_output=True, text=True).stdout.split()
    return [int(p) for p in out if p.isdigit()]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--secs', type=float, default=60)
    ap.add_argument('--env', action='append', default=[])
    ap.add_argument('--cwd', default=os.path.join(ROOT, 'game', 'extracted_full', 'WINO'))
    ap.add_argument('--log', default=os.path.join(ROOT, 'work', 'run.log'))
    ap.add_argument('cmd', nargs='+')
    a = ap.parse_args()
    name = 'gta-' + uuid.uuid4().hex[:12]
    desk = u32.CreateDesktopW(name, None, None, 0, 0x10000000, None)   # GENERIC_ALL
    env = dict(os.environ, GTA_AUDIO_MUTE='1')
    env.update(kv.split('=', 1) for kv in a.env)
    block = ''.join(f'{k}={v}\0' for k, v in env.items()) + '\0'
    class SA(ctypes.Structure):
        _fields_ = [('n', W.DWORD), ('p', ctypes.c_void_p), ('inh', W.BOOL)]
    sa = SA(ctypes.sizeof(SA), None, True)
    k32.CreateFileW.restype = W.HANDLE
    h = k32.CreateFileW(os.path.abspath(a.log), 0x40000000, 3, ctypes.byref(sa), 2, 0, None)
    si = SI(cb=ctypes.sizeof(SI), desk=name, flags=0x100, o=h, e=h)
    pi = PI()
    cmd = subprocess.list2cmdline([os.path.abspath(a.cmd[0])] + a.cmd[1:])
    if not k32.CreateProcessW(None, cmd, None, None, True, 0x400, ctypes.create_unicode_buffer(block),
                              a.cwd, ctypes.byref(si), ctypes.byref(pi)):
        raise SystemExit('CreateProcess failed %d' % k32.GetLastError())
    print('desktop', name, 'pid', pi.pid, flush=True)
    t0 = time.time()
    kids = []
    while time.time() - t0 < a.secs and k32.WaitForSingleObject(pi.hp, 500):
        kids = children(pi.pid) or kids
    for pid in kids + [pi.pid]:
        hp = k32.OpenProcess(1, False, pid)
        if hp:
            k32.TerminateProcess(hp, 1); k32.CloseHandle(hp)
    k32.CloseHandle(W.HANDLE(h))
    u32.CloseDesktop(W.HANDLE(desk))
    print('done after %.0fs' % (time.time() - t0))


if __name__ == '__main__':
    main()
