#!/bin/sh
# Configure and build the native macOS host: the lifted C on pcrecomp's
# runtime/win32hle, a 64-bit program (arm64) with no Wine and no Rosetta.
# The guest's 4 GB is one block of the host's memory (win32hle's guest_mem.c).
#
#   ./build-macos.sh
#   build-macos/bin/gta1                  # dry run: map and bind the image
#   build-macos/bin/gta1 --run            # play
#
# Needs a lift (tools/lift.py + tools/patch_gen.py), Xcode's command line
# tools, and Homebrew's cmake, ninja, pkgconf, sdl2 and sdl2_ttf.
set -e
cd "$(dirname "$0")"
BUILD_DIR=${BUILD_DIR:-build-macos}
# The toolkit: PCRECOMP, else ../pcrecomp (tools/lift.py's own search order).
if [ -z "$PCRECOMP" ]; then
  PCRECOMP=$(cd .. && pwd)/pcrecomp
fi
if [ ! -f "$PCRECOMP/runtime/win32hle/host.c" ]; then
  echo "pcrecomp not found at $PCRECOMP -- git clone https://github.com/sp00nznet/pcrecomp beside this repo" >&2
  exit 1
fi
if [ ! -f "$BUILD_DIR/build.ninja" ]; then
  # shellcheck disable=SC2086  # CMAKE_ARGS is a list of flags
  cmake -S . -B "$BUILD_DIR" -G Ninja -DPCRECOMP_HOME="$PCRECOMP" $CMAKE_ARGS
fi
cmake --build "$BUILD_DIR" "$@"
