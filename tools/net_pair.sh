#!/bin/bash
# A network game between two copies on this machine, each on its own hidden
# desktop: the host gathers, the joiner finds its session over TCP and joins.
# Keys, timings and extra arguments come from the environment (HK, CK, DELAY,
# HSECS, CSECS, HSHOTS, CSHOTS, HARGS, CARGS: CARGS="--join 192.168.1.5" tests
# over the LAN). Logs and frames go to work/net/{host,cli}. docs/multiplayer.md.
cd "$(dirname "$0")/.."
for r in host cli; do mkdir -p work/net/$r; rm -f work/net/$r/*; done
HK=${HK:-"7:0x28,+1500,0x0D,11:0x0D,8:0x0D,18:0x0D,0:0x0D,16:0x0D,+80000,3:0x0D,+25000,0x26*5000"}
CK=${CK:-"7:0x28,+1500,0x28,+1500,0x0D,11:0x0D,0:0x0D,15:0x0D,+55000,0x26*5000"}
timeout 300 python tools/run.py --secs ${HSECS:-200} --env "GTA_KEYS=$HK" --env "GTA_SHOTS=${HSHOTS:-90,115,130,150,170,195}" --env "GTA_SHOT_DIR=$(cygpath -w $PWD/work/net/host)" --env "GTA_WATCH_MEM=5101d0" $XH --log work/net/host/run.log -- build/bin/Release/gta1.exe "Grand Theft Auto.exe" $HARGS >/dev/null &
sleep ${DELAY:-55}
timeout 300 python tools/run.py --secs ${CSECS:-145} --env "GTA_KEYS=$CK" --env "GTA_SHOTS=${CSHOTS:-30,60,75,95,115,140}" --env "GTA_SHOT_DIR=$(cygpath -w $PWD/work/net/cli)" --env "GTA_WATCH_MEM=5101d0" $XC --log work/net/cli/run.log -- build/bin/Release/gta1.exe "Grand Theft Auto.exe" $CARGS >/dev/null
wait
for r in host cli; do echo == $r; grep -a "dplay\|MEM 0x\|CRASH: exception 0xC" work/net/$r/run.log | grep -v "\] Receive\|\] Send" | head -40
 (cd work/net/$r && python -c "
from PIL import Image
import glob
ims=[Image.open(f).convert('RGB') for f in sorted(glob.glob('shot_*.bmp'))]
W=Image.new('RGB',(640*3,480*2))
for i,im in enumerate(ims[:6]): W.paste(im.resize((640,480)),((i%3)*640,(i//3)*480))
W.thumbnail((1500,600)); W.save('grid.png')"); done
