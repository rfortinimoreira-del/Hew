#pragma once

#include <glm/glm.hpp>
#include "Camera.h"

class Player {
public:
    Player();
    
    void update();
    void render();
    
    glm::vec3 getPosition() const;
    Camera& getCamera();
    
private:
    glm::vec3 position;
    glm::vec3 velocity;
    Camera camera;
    
    float speed;
    float jumpForce;
    bool isGrounded;
};
