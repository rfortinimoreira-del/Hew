#include "Camera.h"
#include "InputManager.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

Camera::Camera(glm::vec3 pos)
    : position(pos), 
      front(0, 0, -1), 
      up(0, 1, 0),
      yaw(-90.0f),
      pitch(0.0f),
      speed(0.15f),
      sensitivity(0.1f) {
    updateVectors();
}

void Camera::update() {
    handleInput();
}

void Camera::handleInput() {
    // Movimento WASD
    if (InputManager::isKeyPressed(GLFW_KEY_W)) {
        position += front * speed;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_S)) {
        position -= front * speed;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_A)) {
        position -= right * speed;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_D)) {
        position += right * speed;
    }
    
    // Movimento vertical
    if (InputManager::isKeyPressed(GLFW_KEY_SPACE)) {
        position.y += speed;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_LEFT_SHIFT)) {
        position.y -= speed;
    }
    
    // Movimento do mouse
    glm::vec2 mouseDelta = InputManager::getMouseDelta();
    yaw += mouseDelta.x * sensitivity;
    pitch -= mouseDelta.y * sensitivity;
    
    // Limitar pitch
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;
    
    updateVectors();
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 1000.0f);
}

glm::vec3 Camera::getPosition() const {
    return position;
}

glm::vec3 Camera::getDirection() const {
    return front;
}

void Camera::setPosition(glm::vec3 pos) {
    position = pos;
}

void Camera::updateVectors() {
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);
    
    right = glm::normalize(glm::cross(front, glm::vec3(0, 1, 0)));
    up = glm::normalize(glm::cross(right, front));
}
