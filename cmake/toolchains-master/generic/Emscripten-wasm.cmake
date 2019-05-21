#
# Toolchain for cross-compiling to JS using Emscripten with WebAssembly
#
# Modify EMSCRIPTEN_PREFIX to your liking; use EMSCRIPTEN environment variable
# to point to it or pass it explicitly via -DEMSCRIPTEN_PREFIX=<path>.
#
#  mkdir build-emscripten-wasm && cd build-emscripten-wasm
#  cmake .. -DCMAKE_TOOLCHAIN_FILE=../toolchains/generic/Emscripten-wasm.cmake
#

set(CMAKE_SYSTEM_NAME Emscripten)

# Help CMake find the platform file
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_LIST_DIR}/../modules)


if(NOT EMSCRIPTEN_PREFIX)
    if(DEFINED ENV{EMSCRIPTEN})
        file(TO_CMAKE_PATH "$ENV{EMSCRIPTEN}" EMSCRIPTEN_PREFIX)
    else()
        set(EMSCRIPTEN_PREFIX "/usr/lib/emscripten")
    endif()
endif()

set(EMSCRIPTEN_TOOLCHAIN_PATH "${EMSCRIPTEN_PREFIX}/system")

if(CMAKE_HOST_WIN32)
    set(EMCC_SUFFIX ".bat")
else()
    set(EMCC_SUFFIX "")
endif()
set(CMAKE_C_COMPILER "${EMSCRIPTEN_PREFIX}/emcc${EMCC_SUFFIX}")
set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_PREFIX}/em++${EMCC_SUFFIX}")
set(CMAKE_AR "${EMSCRIPTEN_PREFIX}/emar${EMCC_SUFFIX}" CACHE FILEPATH "Emscripten ar")
set(CMAKE_RANLIB "${EMSCRIPTEN_PREFIX}/emranlib${EMCC_SUFFIX}" CACHE FILEPATH "Emscripten ranlib")


set(CMAKE_FIND_ROOT_PATH 
     ${CMAKE_FIND_ROOT_PATH}
    "${EMSCRIPTEN_TOOLCHAIN_PATH}"
    "${EMSCRIPTEN_PREFIX}")

list(INSERT CMAKE_MODULE_PATH 0 "${EMSCRIPTEN_PREFIX}/cmake/Modules" "${EMSCRIPTEN_PREFIX}/tests/poppler/cmake/modules")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Otherwise FindCorrade fails to find _CORRADE_MODULE_DIR. Why the heck is this
# not implicit is beyond me.
#set(CMAKE_MODULE_PATH ${CMAKE_FIND_ROOT_PATH})

# Compared to the classic (asm.js) compilation, -s WASM=1 is added to both
# compiler and linker. The *_INIT variables are available since CMake 3.7, so
# it won't work in earlier versions. Sorry.
cmake_minimum_required(VERSION 3.7)

#include_directories(/home/jiang/Github/emsdk/emscripten/1.38.31/tests/poppler)

include_directories(
    /usr/include 
    /usr/include/x86_64-linux-gnu
)

message(STATUS "[EMSCRIPTEN] FIND_ROOT_PATH -> ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "[EMSCRIPTEN] MODULE_PATH    -> ${CMAKE_MODULE_PATH}")


set(CMAKE_CXX_FLAGS_INIT "-s WASM=1")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-s WASM=1")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG -O3")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT "-O3 --llvm-lto 1")
