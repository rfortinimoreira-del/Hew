#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexCode = readFile(vertexPath);
    std::string fragmentCode = readFile(fragmentPath);
    
    unsigned int vertex = compileShader(vertexCode, GL_VERTEX_SHADER);
    unsigned int fragment = compileShader(fragmentCode, GL_FRAGMENT_SHADER);
    
    linkProgram(vertex, fragment);
}

Shader::~Shader() {
    glDeleteProgram(ID);
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) {
    GLint loc = glGetUniformLocation(ID, name.c_str());
    glUniformMatrix4fv(loc, 1, GL_FALSE, &mat[0][0]);
}

void Shader::setVec3(const std::string& name, const glm::vec3& vec) {
    GLint loc = glGetUniformLocation(ID, name.c_str());
    glUniform3f(loc, vec.x, vec.y, vec.z);
}

void Shader::setFloat(const std::string& name, float value) {
    GLint loc = glGetUniformLocation(ID, name.c_str());
    glUniform1f(loc, value);
}

std::string Shader::readFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

unsigned int Shader::compileShader(const std::string& source, unsigned int type) {
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;
    }
    
    return shader;
}

void Shader::linkProgram(unsigned int vertex, unsigned int fragment) {
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    
    int success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "Program linking failed: " << infoLog << std::endl;
    }
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
