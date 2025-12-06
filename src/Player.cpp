#include "Player.h"
#include "InputManager.h"
#include <GLFW/glfw3.h>

Player::Player() 
    : position(32, 40, 32),
      velocity(0),
      camera(position),
      speed(0.15f),
      jumpForce(0.5f),
      isGrounded(true) {
}

void Player::update() {
    camera.update();
    
    // Atualizar posição da câmera para seguir jogador
    position = camera.getPosition();
}

void Player::render() {
    // Renderizar personagem (simplificado por enquanto)
}

glm::vec3 Player::getPosition() const {
    return position;
}

Camera& Player::getCamera() {
    return camera;
}
