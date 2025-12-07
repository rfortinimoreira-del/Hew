# Toolchain CMake para compilação cruzada Windows 64-bit
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Especificar compiladores
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /workspaces/Hew/mingw-g++-wrapper.sh)
set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

# Flags de compilação
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc -fPIC")

# Procurar bibliotecas e headers no ambiente MinGW
set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Use sysroot to redirect includes to MinGW (cleaner than -nostdinc + manual paths)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --sysroot=/usr/x86_64-w64-mingw32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --sysroot=/usr/x86_64-w64-mingw32")

# Prevent CMake from adding /usr/include as system include (which breaks cross-compilation)
set(CMAKE_SYSTEM_INCLUDE_PATH "")
set(CMAKE_SYSTEM_LIBRARY_PATH /usr/x86_64-w64-mingw32/lib)
