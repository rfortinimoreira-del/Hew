#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <GL/glew.h>

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
};

class Cube {
public:
    Cube();
    ~Cube();
    
    static void initCubeData();
    static void renderCube(glm::vec3 position, glm::vec3 color);
    static void cleanupCubeData();
    
private:
    static GLuint VAO, VBO, EBO;
    static std::vector<Vertex> vertices;
    static std::vector<unsigned int> indices;
    static bool initialized;
};
