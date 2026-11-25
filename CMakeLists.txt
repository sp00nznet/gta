cmake_minimum_required(VERSION 3.20)
project(gta-recomp C)

set(CMAKE_C_STANDARD 17)

# --- Platform ---
if(WIN32)
    add_definitions(-DPLATFORM_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS)
endif()

# --- Dependencies ---
# SDL2 is optional for now -- stub out if not found
find_package(SDL2 QUIET)
find_package(OpenGL QUIET)

# pcrecomp supplies the lifted code's CPU contract (runtime/recomp32/recomp_types.h).
set(PCRECOMP_HOME "$ENV{PCRECOMP}" CACHE PATH "pcrecomp checkout")
if(NOT PCRECOMP_HOME)
    foreach(cand ../pcrecomp-gta ../pcrecomp)
        if(EXISTS "${CMAKE_SOURCE_DIR}/${cand}/runtime/recomp32/recomp_types.h")
            get_filename_component(PCRECOMP_HOME "${CMAKE_SOURCE_DIR}/${cand}" ABSOLUTE)
            break()
        endif()
    endforeach()
endif()
if(NOT EXISTS "${PCRECOMP_HOME}/runtime/recomp32/recomp_types.h")
    message(FATAL_ERROR "pcrecomp not found: set PCRECOMP to a checkout of https://github.com/sp00nznet/pcrecomp")
endif()
include_directories(BEFORE "${PCRECOMP_HOME}/runtime/recomp32")

# --- Collect generated recompiled sources ---
file(GLOB GTA1_RECOMP_SOURCES "src/recomp/gen/recomp_*.c")

if(NOT GTA1_RECOMP_SOURCES)
    message(FATAL_ERROR
        "No lifted sources in src/recomp/gen/.\n"
        "The lifted C is generated from your own copy of the game, not shipped "
        "with this repository. Generate it first:\n"
        "  python tools/lift.py \"<path to>/Grand Theft Auto.exe\"\n"
        "  python tools/patch_gen.py")
endif()

# --- GTA1 target ---
if(APPLE)
    # Native macOS: the lifted C on pcrecomp's runtime/win32hle, a 64-bit
    # arm64 host (RECOMP_MEM_BASE: the guest's 4 GB is one block of the
    # host's memory). Every Win32 import is answered by win32hle itself.
    # build-macos.sh builds this.
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)
    pkg_check_modules(SDL2_TTF REQUIRED IMPORTED_TARGET SDL2_ttf)
    set(HLE "${PCRECOMP_HOME}/runtime/win32hle")
    file(GLOB HLE_SOURCES CONFIGURE_DEPENDS "${HLE}/*.c")
    list(FILTER HLE_SOURCES EXCLUDE REGEX "_selftest\\.c$|/[.]_[^/]*$")
    # recomp_part.c is drive32's MSVC part-DLL artifact (__declspec); the
    # single-binary host uses recomp_dispatch.c instead.
    list(FILTER GTA1_RECOMP_SOURCES EXCLUDE REGEX "recomp_part\\.c$")
    add_executable(gta1
        src/macos/main.c
        src/macos/gta_hooks.c
        src/macos/gta_menu.c
        src/macos/gta_mixer.c
        src/macos/gta_mss.c
        src/macos/gta_net.c
        src/macos/gta_pad.c
        src/macos/gta_smack.c
        ${HLE_SOURCES}
        ${GTA1_RECOMP_SOURCES})
    target_include_directories(gta1 PRIVATE src/macos src/remaster ${HLE})
    # The fast set redalert2-recomp's native host uses (#65, #66): local
    # registers (the globals are reloaded after every store the compiler
    # cannot prove misses guest memory), indirect-call targets cached per
    # site and in one table (safe: win32hle's machine lock runs one guest
    # thread at a time), no icall trace ring, and the x87 stack as a ring
    # with a function's own pushes in locals. The drive32 lift emits
    # RECOMP_REGS_LOCALS/OUT and _ST(i), so it takes all of these.
    # GTA_FAST_ICALLS=OFF brings the indirect-call trace ring back, for a
    # crash report that names the call chain (a debug build).
    option(GTA_FAST_ICALLS "Cache indirect-call targets, x87 ring, drop the icall trace ring" ON)
    if(GTA_FAST_ICALLS)
        target_compile_definitions(gta1 PRIVATE
            RECOMP_RESOLVE_CACHE=16384 RECOMP_ICALL_SITE_CACHE RECOMP_NO_ICALL_TRACE
            RECOMP_X87_RING RECOMP_X87_LOCAL)
    endif()
    set_source_files_properties(${GTA1_RECOMP_SOURCES} PROPERTIES
        COMPILE_OPTIONS "-O2;-w;-fno-strict-aliasing;-fwrapv")
    target_compile_options(gta1 PRIVATE -fno-strict-aliasing -fwrapv)
    target_link_libraries(gta1 PRIVATE PkgConfig::SDL2 PkgConfig::SDL2_TTF pthread m)
    set_target_properties(gta1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        OUTPUT_NAME gta1)
    return()
endif()

add_executable(gta1
    # Engine core
    src/engine/main.c
    src/engine/recomp_runtime.c
    src/engine/image_loader.c
    src/engine/hybrid.c
    src/engine/iat_bridge.c
    src/engine/premap.c

    # Shim layers
    src/sound/miles_shim.c
    src/sound/mixer.c
    src/video/smacker_shim.c
    src/video/ddraw_shim.c

    # The remaster: presenter, resolution, pad, settings
    src/remaster/settings.c
    src/remaster/present.c
    src/remaster/hires.c
    src/remaster/pad.c

    # Network play: DirectPlay over TCP
    src/net/dplay.c
    src/net/coop.c

    # Generated recompiled code
    ${GTA1_RECOMP_SOURCES}
)

# Record the last 1024 lifted functions entered, dumped on a crash or a
# stack imbalance. Costs a store and a call per function, so it is opt-in.
option(GTA_TRACE "Function-entry ring tracer" OFF)
if(GTA_TRACE)
    target_compile_definitions(gta1 PRIVATE RECOMP_TRACE=1)
endif()

target_include_directories(gta1 PRIVATE
    src/
    src/common/
    src/engine/
    src/recomp/gen/
)

# Link libraries
if(SDL2_FOUND)
    target_link_libraries(gta1 PRIVATE SDL2::SDL2)
    target_compile_definitions(gta1 PRIVATE HAS_SDL2=1)
else()
    message(WARNING "SDL2 not found -- audio/video shims will be stubbed")
    target_compile_definitions(gta1 PRIVATE HAS_SDL2=0)
endif()

if(OpenGL_FOUND)
    target_link_libraries(gta1 PRIVATE OpenGL::GL)
endif()

if(WIN32)
    target_link_libraries(gta1 PRIVATE ws2_32 winmm d3d11 dxgi dxguid shell32)
endif()

# Critical linker settings for recompiled code
if(MSVC)
    target_link_options(gta1 PRIVATE
        /DYNAMICBASE:NO       # No ASLR (need fixed addresses for VA translation)
        /STACK:1048576        # host stack: the game runs on the simulated stack.
                              # 8MB reserved AT 0x400000, right on the image base.
        /LARGEADDRESSAWARE:NO # Stay in 32-bit address space
        /BASE:0x10000000      # Move our exe out of the way so we can map at 0x400000
        /HEAP:4096,4096       # Tiny heap to prevent CRT from reserving 0x400000 range
    )
    target_compile_options(gta1 PRIVATE
        /W3
        /wd4244 /wd4018 /wd4267 /wd4146  # Suppress conversion warnings from lifted code
        /wd4305 /wd4309 /wd4028 /wd4113   # More lifted code warnings
        /bigobj                            # Large object files from 500-function chunks
    )
endif()

set_target_properties(gta1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    OUTPUT_NAME "gta1"
)

# --- GTA2 target (placeholder) ---
# add_executable(gta2 ...)

# --- GTA London 1969 ---
#
# The same Race'n'Chase engine and the same shims; only the lifted code is
# different. Built when that lift is present, skipped quietly when it is not,
# because most people will only ever generate GTA1.
file(GLOB LONDON_RECOMP_SOURCES "src/recomp/gen_london69/*.c")
if(LONDON_RECOMP_SOURCES)
    add_executable(london
        src/engine/main.c
        src/engine/recomp_runtime.c
        src/engine/image_loader.c
        src/engine/hybrid.c
        src/engine/iat_bridge.c
        src/engine/premap.c
        src/sound/miles_shim.c
        src/sound/mixer.c
        src/video/smacker_shim.c
        src/video/ddraw_shim.c
        src/remaster/settings.c
        src/remaster/present.c
        src/remaster/hires.c
        src/remaster/pad.c
        src/net/dplay.c
        src/net/coop.c
        ${LONDON_RECOMP_SOURCES}
    )
    target_include_directories(london PRIVATE
        src/ src/common/ src/engine/ src/recomp/gen_london69/)
    if(GTA_TRACE)
        target_compile_definitions(london PRIVATE RECOMP_TRACE=1)
    endif()
    if(SDL2_FOUND)
        target_link_libraries(london PRIVATE SDL2::SDL2)
        target_compile_definitions(london PRIVATE HAS_SDL2=1)
    else()
        target_compile_definitions(london PRIVATE HAS_SDL2=0)
    endif()
    if(WIN32)
        target_link_libraries(london PRIVATE ws2_32 winmm d3d11 dxgi dxguid shell32)
    endif()
    if(MSVC)
        # Identical to gta1: the image has to land at its original base, so the
        # same constraints apply -- no ASLR, our exe moved out of the way, and a
        # small host stack and heap so neither claims 0x400000.
        target_link_options(london PRIVATE
            /DYNAMICBASE:NO /STACK:1048576 /LARGEADDRESSAWARE:NO
            /BASE:0x10000000 /HEAP:4096,4096)
        target_compile_options(london PRIVATE
            /W3 /wd4244 /wd4018 /wd4267 /wd4146
            /wd4305 /wd4309 /wd4028 /wd4113 /bigobj)
    endif()
    message(STATUS "London 1969 target enabled")
endif()
