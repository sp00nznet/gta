cmake_minimum_required(VERSION 3.20)
project(gta-recomp C)

set(CMAKE_C_STANDARD 17)

# --- Platform ---
if(WIN32)
    add_definitions(-DPLATFORM_WINDOWS -DWIN32_LEAN_AND_MEAN -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS)
endif()

# --- Dependencies ---
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# --- Common engine sources (shared across GTA1/London/GTA2) ---
set(COMMON_SOURCES
    # src/common/types.h
    # src/common/memory.c
    # src/common/math.c
)

set(ENGINE_SOURCES
    # src/engine/main.c
    # src/engine/win32_compat.h
    # src/engine/filesystem.c
    # src/engine/input.c
)

set(RENDERER_SOURCES
    # src/renderer/renderer.c
    # src/renderer/tiles.c
    # src/renderer/sprites.c
)

set(SOUND_SOURCES
    # src/sound/sound.c
    # src/sound/miles_shim.c
)

set(VIDEO_SOURCES
    # src/video/smacker.c
)

set(NET_SOURCES
    # src/net/dplay_shim.c
)

# --- GTA1 target ---
set(GTA1_SOURCES
    # src/gta1/game.c
    # Lifted code will go here:
    # src/recomp/gen/gta1_funcs_0001.c
    # src/recomp/gen/gta1_funcs_0002.c
    # ...
)

add_executable(gta1
    ${COMMON_SOURCES}
    ${ENGINE_SOURCES}
    ${RENDERER_SOURCES}
    ${SOUND_SOURCES}
    ${VIDEO_SOURCES}
    ${NET_SOURCES}
    ${GTA1_SOURCES}
)

target_include_directories(gta1 PRIVATE
    src/
    src/common/
    src/engine/
)

target_link_libraries(gta1 PRIVATE
    SDL2::SDL2
    OpenGL::GL
    ws2_32
    winmm
)

# Critical linker settings for recompiled code
if(MSVC)
    target_link_options(gta1 PRIVATE
        /DYNAMICBASE:NO       # No ASLR (need fixed addresses for VA translation)
        /STACK:8388608        # 8MB stack
    )
    target_compile_options(gta1 PRIVATE
        /W3
        /wd4244 /wd4018 /wd4267  # Suppress conversion warnings from lifted code
    )
endif()

set_target_properties(gta1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    OUTPUT_NAME "gta1"
)

# --- GTA2 target (placeholder) ---
# add_executable(gta2 ...)
