#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class InputManager {
public:
    InputManager();
    
    static void init(GLFWwindow* window);
    static void update();
    
    // Teclado
    static bool isKeyPressed(int key);
    static bool isKeyJustPressed(int key);
    
    // Mouse
    static glm::vec2 getMousePosition();
    static glm::vec2 getMouseDelta();
    static bool isMouseButtonPressed(int button);
    static bool isMouseButtonJustPressed(int button);
    
    static void setCursorMode(bool locked);
    
    // Atributos estáticos acessíveis
    static GLFWwindow* window;
    static bool keys[GLFW_KEY_LAST];
    static bool keysPressed[GLFW_KEY_LAST];
    static bool mouseButtons[GLFW_MOUSE_BUTTON_LAST];
    static bool mouseButtonsPressed[GLFW_MOUSE_BUTTON_LAST];
    static glm::vec2 mousePos;
    static glm::vec2 mouseDelta;
    static glm::vec2 lastMousePos;
};
