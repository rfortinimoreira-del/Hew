cmake_minimum_required(VERSION 3.16)
project(Hubble)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar dependências
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW REQUIRED)

# Incluir diretório de headers
include_directories(include)

# Arquivos fonte
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

# Criar executável
add_executable(hubble ${SOURCES})

# Linkar bibliotecas
target_link_libraries(hubble 
    PRIVATE 
    OpenGL::OpenGL 
    glfw 
    glm::glm
    GLEW::GLEW
)

# Copiar assets
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

