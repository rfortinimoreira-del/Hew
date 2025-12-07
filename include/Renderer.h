#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"
#include "World.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    
    void init();
    void clear();
    void render(World* world, glm::mat4 view, glm::mat4 projection);
    void swapBuffers();
    
    bool shouldClose();
    void setWindowShouldClose(bool value);
    
    GLFWwindow* getWindow() const { return window; }
    Shader* getShader() const { return shader; }
    
private:
    void setupBuffers();
    void setupShaders();
    
    GLFWwindow* window;
    Shader* shader;
};
