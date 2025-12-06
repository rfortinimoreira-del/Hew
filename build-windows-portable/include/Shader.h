#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    
    void use();
    void setMat4(const std::string& name, const glm::mat4& mat);
    void setVec3(const std::string& name, const glm::vec3& vec);
    void setFloat(const std::string& name, float value);
    
private:
    unsigned int ID;
    
    std::string readFile(const std::string& path);
    unsigned int compileShader(const std::string& source, unsigned int type);
    void linkProgram(unsigned int vertex, unsigned int fragment);
};
