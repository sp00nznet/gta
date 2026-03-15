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

# --- Collect generated recompiled sources ---
file(GLOB GTA1_RECOMP_SOURCES "src/recomp/gen/recomp_*.c")

# --- GTA1 target ---
add_executable(gta1
    # Engine core
    src/engine/main.c
    src/engine/recomp_runtime.c
    src/engine/iat_bridge.c

    # Shim layers
    src/sound/miles_shim.c
    src/video/smacker_shim.c

    # Generated recompiled code
    ${GTA1_RECOMP_SOURCES}

    # Generated stubs for undiscovered functions
    src/recomp/gen/recomp_stubs.c

    # Import stubs (TODO: fix @ character in MSS function names)
    # src/recomp/gen/import_stubs.c
)

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
    target_link_libraries(gta1 PRIVATE ws2_32 winmm)
endif()

# Critical linker settings for recompiled code
if(MSVC)
    target_link_options(gta1 PRIVATE
        /DYNAMICBASE:NO       # No ASLR (need fixed addresses for VA translation)
        /STACK:8388608        # 8MB stack
        /LARGEADDRESSAWARE:NO # Stay in 32-bit address space
        /BASE:0x10000000      # Move our exe out of the way so we can map at 0x400000
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
