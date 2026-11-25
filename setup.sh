#!/bin/bash
# macOS setup: the same pipeline as Setup.cmd (tools/setup.ps1), for the
# native macOS host (docs/macos.md). It checks for what the build needs and
# installs the rest with Homebrew, extracts the game from Rockstar's
# freeware installer, lifts, patches, builds, and leaves a "Grand Theft Auto
# (recomp)" launcher here -- and, with GTA2 ticked, "GTA2 (recomp)" too.
#
#   ./setup.sh --game-dir ~/Downloads/GTA           # GTA1
#   ./setup.sh --game-dir ~/Downloads/GTA --targets gta2   # and GTA2
#   ./setup.sh --yes     # install what is missing without asking
#   ./setup.sh --force   # redo every step
#
# --game-dir is GTAINSTALLER.zip, a folder holding it or its data1.cab, or
# an installed copy (the folder with WINO/Grand Theft Auto.exe and
# GTADATA). For GTA2, Rockstar's GTA2.exe installer (or an installed
# gta2.exe) in that folder or one inside it. Finished steps are skipped;
# everything goes to setup.log. recomp-launcher runs it with --yes.
set -e
cd "$(dirname "$0")"
ROOT=$PWD
FORCE=0; YES=0; GAME_ARG=""; TARGETS=""
while [ $# -gt 0 ]; do
  case "$1" in
    --force) FORCE=1 ;;
    --yes) YES=1 ;;
    --game-dir) GAME_ARG=$2; shift ;;
    --targets) TARGETS=$2; shift ;;
    *) echo "usage: ./setup.sh [--game-dir DIR] [--targets gta2] [--yes] [--force]" >&2; exit 2 ;;
  esac
  shift
done
GTA2=0; case ",$TARGETS," in *,gta2,*) GTA2=1 ;; esac
LOG=$ROOT/setup.log
printf '==== setup %s\n' "$(date '+%Y-%m-%dT%H:%M:%S')" >> "$LOG"

STEP=0; STEPS=$((6 + 2 * GTA2))
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

say "Grand Theft Auto: static recompilation setup (macOS)"
[ "$(uname)" = Darwin ] || fail "this is the macOS setup; on Windows run Setup.cmd."

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
if ! fresh "$EXE"; then
  say "  Already extracted in game/extracted_full (skipping)."
else
  g=${GAME_ARG%/}
  [ -n "$g" ] || fail "no game given: choose GTAINSTALLER.zip, a folder with data1.cab, or the installed game (--game-dir)."
  [ -e "$g" ] || fail "$g does not exist."
  mkdir -p "$ROOT/game"
  installed=""
  [ -f "$g/WINO/Grand Theft Auto.exe" ] && installed=$g
  [ -z "$installed" ] && [ -d "$g" ] && installed=$(find "$g" -maxdepth 3 -path '*/WINO/Grand Theft Auto.exe' -print -quit 2>/dev/null | sed 's|/WINO/Grand Theft Auto.exe$||')
  if [ -n "$installed" ]; then
    say "  Copying the installed game from $installed"
    rm -rf "$GAME"; mkdir -p "$GAME"
    run "Copying" cp -R "$installed/." "$GAME/"
  else
    zip=""
    case "$g" in *.zip|*.ZIP) zip=$g ;; esac
    [ -z "$zip" ] && [ -d "$g" ] && zip=$(find "$g" -maxdepth 2 -iname 'GTAINSTALLER*.zip' -print -quit 2>/dev/null)
    cabs=$g
    if [ -n "$zip" ]; then
      cabs=$ROOT/game/installer
      rm -rf "$cabs"; mkdir -p "$cabs"
      run "Unzipping $zip" unzip -q -o "$zip" -d "$cabs"
    fi
    cab=$(find "$cabs" -maxdepth 3 -iname data1.cab -print -quit 2>/dev/null)
    [ -n "$cab" ] || fail "no GTA1 found in $g: choose GTAINSTALLER.zip, a folder with data1.cab, or an installed copy."
    hdr=$(find "$(dirname "$cab")" -maxdepth 1 -iname data1.hdr -print -quit)
    run "Extracting the installer's cabinets" "$PY" "$PCRECOMP/tools/assets/isextract.py" "${hdr:-$cab}" "$cab" -o "$GAME"
  fi
  [ -f "$EXE" ] || fail "the extracted game has no WINO/Grand Theft Auto.exe."
fi

step "Translating the game's code to C (about 12 minutes, once)"
if ! fresh src/recomp/gen/recomp_dispatch.c; then say "  Already done (skipping)."
else run "Lifting" "$PY" tools/lift.py "$EXE"; fi

step "Applying the remaster's patches"
run "Patching" "$PY" tools/patch_gen.py

# ---------------------------------------------------------------- GTA2
GTA2_DIR=$ROOT/gta2-game/extracted
if [ "$GTA2" = 1 ]; then
  step "Extracting GTA2"
  if ! fresh "$GTA2_DIR/gta2.exe"; then
    say "  Already extracted in gta2-game/extracted (skipping)."
  else
    from=${GAME_ARG%/}; [ -d "$from" ] || from=$(dirname "$from")
    found=""; installer=""
    while IFS= read -r f; do
      d=$(dirname "$f")
      if [ -d "$d/data" ] && [ -f "$d/d3ddll.dll" ]; then found=$d; break; fi
      [ -z "$installer" ] && installer=$f
    done < <(find "$from" -maxdepth 3 -iname gta2.exe 2>/dev/null)
    rm -rf "$GTA2_DIR"; mkdir -p "$GTA2_DIR"
    if [ -n "$found" ]; then
      run "Copying the installed GTA2 from $found" cp -R "$found/." "$GTA2_DIR/"
    elif [ -n "$installer" ]; then
      run "Extracting $installer" "$PY" tools/extract_gta2.py "$installer" -o "$GTA2_DIR"
    else
      fail "GTA2 was ticked but no GTA2.exe (Rockstar's installer) or installed gta2.exe is in $from. Put GTA2.exe in that folder, or build without GTA2."
    fi
    [ -f "$GTA2_DIR/gta2.exe" ] || fail "the extracted GTA2 has no gta2.exe."
  fi
  # The save slots' folder, which GTA2's installer makes and its cabinets do
  # not hold: without it the game stops at "Unable to open file :
  # player\plyslot0.dat". The game writes the slots itself.
  mkdir -p "$GTA2_DIR/player"

  step "Translating GTA2's code to C"
  if ! fresh src/recomp/gen_gta2/recomp_dispatch.c; then say "  Already done (skipping)."
  else
    run "Lifting gta2.exe" "$PY" tools/lift.py "$GTA2_DIR/gta2.exe" src/recomp/gen_gta2
    dma=$(find "$GTA2_DIR" -maxdepth 1 -iname dmavideo.dll -print -quit)
    run "Lifting dmavideo.dll" "$PY" tools/lift.py "$dma" src/recomp/gen_dmavideo
    run "Lifting d3ddll.dll" "$PY" tools/lift.py "$GTA2_DIR/d3ddll.dll" src/recomp/gen_d3ddll
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
