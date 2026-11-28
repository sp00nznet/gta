#!/bin/bash
# macOS setup: the same pipeline as Setup.cmd (tools/setup.ps1), for the
# native macOS host (docs/macos.md). It checks for what the build needs and
# installs the rest with Homebrew, extracts the game from Rockstar's
# freeware installer, lifts, patches, builds, and leaves a "Grand Theft Auto
# (recomp)" launcher here -- and, with GTA2 ticked, "GTA2 (recomp)" too.
#
#   ./setup.sh --game-dir ~/Downloads/GTA   # GTA1, and GTA2 if its GTA2.exe is there
#   ./setup.sh --targets gta2 ...           # GTA2 required: stop if it is not found
#   ./setup.sh --yes     # install what is missing without asking
#   ./setup.sh --force   # redo every step
#
# --game-dir is GTAINSTALLER.zip, a folder holding it or its data1.cab, or
# an installed copy (the folder with WINO/Grand Theft Auto.exe and
# GTADATA). GTA2 is built too when Rockstar's GTA2.exe installer (or an
# installed gta2.exe) is in that folder or one inside it, or was built
# before. Finished steps are skipped; everything goes to setup.log.
# recomp-launcher runs it with --yes.
set -e
cd "$(dirname "$0")"
ROOT=$PWD
FORCE=0; YES=0; GAME_ARG=""; TARGETS=""
while [ $# -gt 0 ]; do
  case "$1" in
    --force) FORCE=1 ;;
    --yes) YES=1 ;;
    --game-dir|--targets)
      [ $# -ge 2 ] || { echo "usage: ./setup.sh [--game-dir DIR] [--targets gta2] [--yes] [--force]: $1 needs a value" >&2; exit 2; }
      if [ "$1" = --game-dir ]; then GAME_ARG=$2; else TARGETS=$2; fi
      shift ;;
    *) echo "usage: ./setup.sh [--game-dir DIR] [--targets gta2] [--yes] [--force]" >&2; exit 2 ;;
  esac
  shift
done
LOG=$ROOT/setup.log
printf '==== setup %s\n' "$(date '+%Y-%m-%dT%H:%M:%S')" >> "$LOG"
# first: a file the pattern names under a folder (a folder find cannot read,
# an external disk's .Trashes, say, must not end the setup).
first() { find "$1" -maxdepth "$2" "${@:3}" 2>/dev/null | head -n 1; }

# GTA2: built when its installer or an installed copy is in the game folder,
# or it was built here before (its patches and dispatch then stay current);
# --targets gta2 requires it.
GTA2_DIR=$ROOT/gta2-game/extracted
GTA2_FROM=""; GTA2_INSTALLED=""
if [ -n "$GAME_ARG" ]; then
  from=${GAME_ARG%/}; [ -d "$from" ] || from=$(dirname "$from")
  while IFS= read -r f; do
    d=$(dirname "$f")
    if [ -d "$d/data" ] && [ -f "$d/d3ddll.dll" ]; then GTA2_INSTALLED=$d; break; fi
    [ -z "$GTA2_FROM" ] && GTA2_FROM=$f
  done < <(find "$from" -maxdepth 3 -iname gta2.exe 2>/dev/null)
fi
GTA2=0
{ [ -n "$GTA2_FROM$GTA2_INSTALLED" ] || [ -e "$GTA2_DIR/.extracted" ]; } && GTA2=1
case ",$TARGETS," in
  *,gta2,*) [ "$GTA2" = 1 ] || GTA2=required ;;
esac

STEP=0; STEPS=6; [ "$GTA2" = 0 ] || STEPS=8
say()  { printf '%s\n' "$*"; printf '%s\n' "$*" >> "$LOG"; }
# "[n/N] what": the installer's progress bar reads these, as Setup.cmd's.
step() { STEP=$((STEP + 1)); printf '\n\033[36m[%d/%d] %s\033[0m\n' "$STEP" "$STEPS" "$*"; printf '[%d/%d] %s\n' "$STEP" "$STEPS" "$*" >> "$LOG"; }
fail() {
  printf '\n\033[31mSetup stopped: %s\033[0m\n' "$*" >&2; printf 'Setup stopped: %s\n' "$*" >> "$LOG"
  say "The details are in $LOG. Fix that and run ./setup.sh again; finished steps are skipped."
  exit 1
}
ask()  { [ "$YES" = 1 ] && { say "$1 yes (--yes)"; return 0; }; read -r -p "$1 [Y/n] " r; [[ ! $r =~ ^[nN] ]]; }
# A command's output into the log; its failure stops the setup.
run()  { say "  $1..."; local what=$1; shift; "$@" >> "$LOG" 2>&1 || fail "$what failed (exit code $?)."; }
fresh() { [ "$FORCE" = 1 ] || [ ! -e "$1" ]; }   # this step's output is missing (or --force)
# real: a path with its links resolved, existing or not (its folder is made).
real() { mkdir -p "$(dirname "$1")" && printf '%s/%s' "$(cd "$(dirname "$1")" && pwd -P)" "$(basename "$1")"; }
# replacing: the folder $2 is about to be remade from what is in $1. The source
# inside it (--force with the game folder pointing at the build's own copy)
# would be deleted before it is read; with "copy", the copy inside the source
# would copy itself into itself.
replacing() {
  local src dst; src=$(cd "$1" 2>/dev/null && pwd -P || printf '%s' "$1"); dst=$(real "$2")
  case "$src/" in "$dst/"*) fail "the game folder $1 is inside this build's own copy ($2): choose the original folder." ;; esac
  if [ "$3" = copy ]; then
    case "$dst/" in "$src/"*) fail "this build's copy ($2) would be inside the game folder $1: build somewhere else." ;; esac
  fi
  rm -rf "$2"; mkdir -p "$2"
}

say "Grand Theft Auto: static recompilation setup (macOS)"
[ "$(uname)" = Darwin ] || fail "this is the macOS setup; on Windows run Setup.cmd."
[ "$GTA2" = required ] && fail "--targets gta2, but no GTA2.exe (Rockstar's installer) or installed gta2.exe is in ${GAME_ARG:-the game folder (no --game-dir given)}."
[ "$GTA2" = 1 ] && say "GTA2 too: ${GTA2_INSTALLED:-${GTA2_FROM:-built here before}}"

# ---------------------------------------------------------------- tools
step "Checking the tools the build needs"
xcode-select -p >/dev/null 2>&1 || fail "Xcode's command line tools are needed: xcode-select --install"
command -v brew >/dev/null || fail "Homebrew is needed: https://brew.sh"
need=()
for f in cmake ninja pkgconf sdl2 sdl2_ttf ffmpeg uv; do brew list --formula "$f" >/dev/null 2>&1 || need+=("$f"); done
if [ ${#need[@]} -gt 0 ]; then
  ask "  Install ${need[*]} with Homebrew?" || fail "${need[*]} are required."
  run "Installing ${need[*]}" brew install "${need[@]}"
fi
if [ ! -x .venv/bin/python ] || ! .venv/bin/python -c 'import capstone, pefile' 2>/dev/null; then
  run "Making a Python environment with capstone and pefile" uv venv --allow-existing .venv
  run "Installing capstone and pefile" uv pip install --python .venv/bin/python capstone pefile
fi
PY=$ROOT/.venv/bin/python
# pcrecomp: $PCRECOMP, else ../pcrecomp-gta, else ../pcrecomp (where the
# launcher puts it). tools/lift.py and build-macos.sh look in the same places.
if [ -z "$PCRECOMP" ]; then
  PCRECOMP=$(cd .. && pwd)/pcrecomp-gta
  [ -f "$PCRECOMP/tools/lift/drive32.py" ] || PCRECOMP=$(cd .. && pwd)/pcrecomp
fi
[ -f "$PCRECOMP/runtime/win32hle/host.c" ] || fail "pcrecomp is not beside this folder: git clone https://github.com/sp00nznet/pcrecomp ../pcrecomp"
export PCRECOMP
say "  Toolkit: $PCRECOMP"

# ---------------------------------------------------------------- GTA1
step "Extracting the game"
GAME=$ROOT/game/extracted_full
EXE=$GAME/WINO/Grand\ Theft\ Auto.exe
if ! fresh "$GAME/.extracted"; then
  say "  Already extracted in game/extracted_full (skipping)."
else
  g=${GAME_ARG%/}
  [ -n "$g" ] || fail "no game given: choose GTAINSTALLER.zip, a folder with data1.cab, or the installed game (--game-dir)."
  [ -e "$g" ] || fail "$g does not exist."
  mkdir -p "$ROOT/game"
  installed=""
  [ -f "$g/WINO/Grand Theft Auto.exe" ] && installed=$g
  [ -z "$installed" ] && [ -d "$g" ] && installed=$(first "$g" 3 -ipath '*/WINO/Grand Theft Auto.exe' | sed 's|/[^/]*/[^/]*$||')
  if [ -n "$installed" ]; then
    say "  Copying the installed game from $installed"
    replacing "$installed" "$GAME" copy
    run "Copying" cp -R "$installed/." "$GAME/"
  else
    zip=""
    case "$g" in *.zip|*.ZIP) zip=$g ;; esac
    [ -z "$zip" ] && [ -d "$g" ] && zip=$(first "$g" 2 -iname 'GTAINSTALLER*.zip')
    cabs=$g
    if [ -n "$zip" ]; then
      cabs=$ROOT/game/installer
      replacing "$(dirname "$zip")" "$cabs"
      run "Unzipping $zip" unzip -q -o "$zip" -d "$cabs"
    fi
    cab=$(first "$cabs" 3 -iname data1.cab)
    [ -n "$cab" ] || fail "no GTA1 found in $g: choose GTAINSTALLER.zip, a folder with data1.cab, or an installed copy."
    hdr=$(first "$(dirname "$cab")" 1 -iname data1.hdr)
    replacing "$cabs" "$GAME"
    run "Extracting the installer's cabinets" "$PY" "$PCRECOMP/tools/assets/isextract.py" "${hdr:-$cab}" "$cab" -o "$GAME"
    rm -rf "$ROOT/game/installer"                 # the unzipped installer: the zip still has it
  fi
  [ -f "$EXE" ] || fail "the extracted game has no WINO/Grand Theft Auto.exe."
  touch "$GAME/.extracted"                        # complete: a cancelled copy is redone
fi

step "Translating the game's code to C (about 12 minutes, once)"
if ! fresh src/recomp/gen/recomp_dispatch.c; then say "  Already done (skipping)."
else run "Lifting" "$PY" tools/lift.py "$EXE"; fi

step "Applying the remaster's patches"
run "Patching" "$PY" tools/patch_gen.py

# ---------------------------------------------------------------- GTA2
if [ "$GTA2" = 1 ]; then
  step "Extracting GTA2"
  if ! fresh "$GTA2_DIR/.extracted"; then
    say "  Already extracted in gta2-game/extracted (skipping)."
  else
    if [ -n "$GTA2_INSTALLED" ]; then
      replacing "$GTA2_INSTALLED" "$GTA2_DIR" copy
      run "Copying the installed GTA2 from $GTA2_INSTALLED" cp -R "$GTA2_INSTALLED/." "$GTA2_DIR/"
    elif [ -n "$GTA2_FROM" ]; then
      replacing "$(dirname "$GTA2_FROM")" "$GTA2_DIR"
      run "Extracting $GTA2_FROM" "$PY" tools/extract_gta2.py "$GTA2_FROM" -o "$GTA2_DIR"
    else
      fail "GTA2 was built here before but its extracted copy is gone: put GTA2.exe in the game folder."
    fi
    [ -f "$GTA2_DIR/gta2.exe" ] || fail "the extracted GTA2 has no gta2.exe."
    # The save slots' folder, which GTA2's installer makes and its cabinets do
    # not hold: without it the game stops at "Unable to open file :
    # player\plyslot0.dat". The game writes the slots itself.
    mkdir -p "$GTA2_DIR/player"
    touch "$GTA2_DIR/.extracted"
  fi

  step "Translating GTA2's code to C"
  # three lifts, each with its own dispatch rows: done only when all three are
  if ! fresh src/recomp/gen_gta2/recomp_dispatch.c && ! fresh src/recomp/gen_dmavideo/recomp_dispatch.c \
     && ! fresh src/recomp/gen_d3ddll/recomp_dispatch.c; then
    say "  Already done (skipping)."
  else
    dma=$(first "$GTA2_DIR" 1 -iname dmavideo.dll)
    d3d=$(first "$GTA2_DIR" 1 -iname d3ddll.dll)
    [ -n "$dma" ] && [ -n "$d3d" ] || fail "the extracted GTA2 has no dmavideo.dll or d3ddll.dll: extract it again (--force)."
    rm -rf src/recomp/gen_gta2 src/recomp/gen_dmavideo src/recomp/gen_d3ddll
    run "Lifting gta2.exe" "$PY" tools/lift.py "$GTA2_DIR/gta2.exe" src/recomp/gen_gta2
    run "Lifting dmavideo.dll" "$PY" tools/lift.py "$dma" src/recomp/gen_dmavideo
    run "Lifting d3ddll.dll" "$PY" tools/lift.py "$d3d" src/recomp/gen_d3ddll
  fi
  run "Patching" "$PY" tools/patch_gen_gta2.py
  run "Merging the three dispatch tables" "$PY" tools/merge_dispatch_gta2.py
fi

# ---------------------------------------------------------------- build
step "Compiling (10-20 minutes the first time)"
run "Building" ./build-macos.sh
[ -x build-macos/bin/gta1 ] || fail "the build did not produce build-macos/bin/gta1."
[ "$GTA2" = 0 ] || [ -x build-macos/bin/gta2 ] || fail "the build did not produce build-macos/bin/gta2."

# ---------------------------------------------------------------- launchers
step "Making the launchers"
launcher() {   # name, binary, game folder
  local f="$ROOT/$1 (recomp).command"
  printf '#!/bin/bash\n# %s, statically recompiled: the native macOS host (docs/macos.md).\ncd "$(dirname "$0")" || exit 1\nexec "build-macos/bin/%s" --run --game "%s" "$@"\n' "$1" "$2" "$3" > "$f"
  chmod +x "$f"
  say "  $f"
}
launcher "Grand Theft Auto" gta1 game/extracted_full
[ "$GTA2" = 0 ] || launcher "GTA2" gta2 gta2-game/extracted

say ""
say "Done. Double-click 'Grand Theft Auto (recomp)'$([ "$GTA2" = 1 ] && printf " or 'GTA2 (recomp)'") in this folder to play."
say "In game: F10 settings (resolution, scaling, controller), F11 fullscreen, F12 scaling."
