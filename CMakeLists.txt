cmake_minimum_required(VERSION 3.16)
project(Hubble)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar dependências
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW)

# Incluir diretório de headers
include_directories(include)

# Arquivos fonte (ANTES de append GLAD)
set(SOURCES
    src/main.cpp
    src/Renderer.cpp
    src/World.cpp
    src/Camera.cpp
    src/Player.cpp
    src/Block.cpp
    src/Shader.cpp
    src/Cube.cpp
    src/InputManager.cpp
    src/Raycaster.cpp
    src/GameState.cpp
)

# Adicionar GLAD (se presente em third_party)
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/third_party/glad/src/glad.c)
if(EXISTS ${GLAD_SRC})
    list(APPEND SOURCES ${GLAD_SRC})
    include_directories(${CMAKE_SOURCE_DIR}/third_party/glad/include)
    set(USE_GLAD ON)
else()
    set(USE_GLAD OFF)
endif()

# Criar executável
add_executable(hubble ${SOURCES})

# Linkar bibliotecas
if(TARGET OpenGL::OpenGL)
    set(OPENGL_LIB_TARGET OpenGL::OpenGL)
else()
    # Fallback for MinGW / Windows: link to opengl32
    set(OPENGL_LIB_TARGET opengl32)
endif()

target_link_libraries(hubble 
    PRIVATE 
    ${OPENGL_LIB_TARGET}
    glfw 
    glm::glm
)

if(NOT USE_GLAD)
    if(GLEW_FOUND)
        target_link_libraries(hubble PRIVATE GLEW::GLEW)
    else()
        message(WARNING "GLEW not found and GLAD not provided; build may fail")
    endif()
endif()

# Copiar assets
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

