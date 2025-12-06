#include "Cube.h"
#include <glm/gtc/matrix_transform.hpp>

GLuint Cube::VAO = 0;
GLuint Cube::VBO = 0;
GLuint Cube::EBO = 0;
std::vector<Vertex> Cube::vertices;
std::vector<unsigned int> Cube::indices;
bool Cube::initialized = false;

Cube::Cube() {}
Cube::~Cube() {}

void Cube::initCubeData() {
    if (initialized) return;
    
    // Vértices de um cubo 1x1x1 centralizado em (0,0,0)
    float size = 0.5f;
    vertices = {
        // Front face
        {{-size, -size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
        {{ size, -size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
        {{ size,  size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
        {{-size,  size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
        
        // Back face
        {{-size, -size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},
        {{ size, -size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},
        {{ size,  size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},
        {{-size,  size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}},
        
        // Top face
        {{-size,  size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
        {{ size,  size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
        {{ size,  size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
        {{-size,  size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
        
        // Bottom face
        {{-size, -size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
        {{ size, -size, -size}, {1.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
        {{ size, -size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
        {{-size, -size,  size}, {1.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
        
        // Right face
        {{ size, -size, -size}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
        {{ size,  size, -size}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
        {{ size,  size,  size}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
        {{ size, -size,  size}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
        
        // Left face
        {{-size, -size, -size}, {1.0f, 1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}},
        {{-size, -size,  size}, {1.0f, 1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}},
        {{-size,  size,  size}, {1.0f, 1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}},
        {{-size,  size, -size}, {1.0f, 1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}},
    };
    
    // Índices
    indices = {
        0, 1, 2, 2, 3, 0,       // Front
        4, 6, 5, 6, 4, 7,       // Back
        8, 9, 10, 10, 11, 8,    // Top
        12, 14, 13, 14, 12, 15, // Bottom
        16, 17, 18, 18, 19, 16, // Right
        20, 22, 21, 22, 20, 23  // Left
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    
    // Atributos de vértice
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    initialized = true;
}

void Cube::renderCube(glm::vec3 position, glm::vec3 color) {
    if (!initialized) initCubeData();
    
    glBindVertexArray(VAO);
    
    // Atualizar cor dos vértices
    for (auto& v : vertices) {
        v.color = color;
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());
    
    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    // Passar model matrix para shader (será feito no Renderer)
    
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

void Cube::cleanupCubeData() {
    if (initialized) {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        initialized = false;
    }
}
