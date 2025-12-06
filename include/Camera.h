#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 pos = glm::vec3(0, 20, 30));
    
    void update();
    void handleInput();
    
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    
    glm::vec3 getPosition() const;
    glm::vec3 getDirection() const;
    
    void setPosition(glm::vec3 pos);
    
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    
    float yaw;
    float pitch;
    float speed;
    float sensitivity;
    
    void updateVectors();
};
