#include "Renderer.h"
#include "Cube.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Renderer::Renderer() : window(nullptr), shader(nullptr) {
}

Renderer::~Renderer() {
    if (shader) delete shader;
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void Renderer::init() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(1920, 1080, "Hubble - Magical Voxel World", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadfunc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GL loader (glad)" << std::endl;
        return;
    }
    
    glViewport(0, 0, 1920, 1080);
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Céu azul
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    setupShaders();
    setupBuffers();
}

void Renderer::setupBuffers() {
    Cube::initCubeData();
}

void Renderer::setupShaders() {
    shader = new Shader("assets/vertex.glsl", "assets/fragment.glsl");
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(World* world, glm::mat4 view, glm::mat4 projection) {
    if (!shader) return;
    
    shader->use();
    shader->setMat4("view", view);
    shader->setMat4("projection", projection);
    
    // Renderizar todos os blocos
    for (int x = 0; x < World::WORLD_WIDTH; x++) {
        for (int y = 0; y < World::WORLD_HEIGHT; y++) {
            for (int z = 0; z < World::WORLD_DEPTH; z++) {
                Block* block = world->getBlock(x, y, z);
                if (block && block->type != BlockType::EMPTY) {
                    glm::vec3 pos = glm::vec3(x, y, z);
                    glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
                    
                    shader->setMat4("model", model);
                    shader->setVec3("blockColor", block->color);
                    
                    Cube::renderCube(pos, block->color);
                }
            }
        }
    }
}

void Renderer::swapBuffers() {
    glfwSwapBuffers(window);
}

bool Renderer::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Renderer::setWindowShouldClose(bool value) {
    glfwSetWindowShouldClose(window, value);
}
