#include "InputManager.h"
#include <cstring>

GLFWwindow* InputManager::window = nullptr;
bool InputManager::keys[GLFW_KEY_LAST] = {};
bool InputManager::keysPressed[GLFW_KEY_LAST] = {};
bool InputManager::mouseButtons[GLFW_MOUSE_BUTTON_LAST] = {};
bool InputManager::mouseButtonsPressed[GLFW_MOUSE_BUTTON_LAST] = {};
glm::vec2 InputManager::mousePos = glm::vec2(0);
glm::vec2 InputManager::mouseDelta = glm::vec2(0);
glm::vec2 InputManager::lastMousePos = glm::vec2(0);

// Callbacks globais
void key_callback_global(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        InputManager::keysPressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        InputManager::keysPressed[key] = false;
    }
}

void mouse_button_callback_global(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        InputManager::mouseButtonsPressed[button] = true;
    } else if (action == GLFW_RELEASE) {
        InputManager::mouseButtonsPressed[button] = false;
    }
}

void cursor_position_callback_global(GLFWwindow* window, double xpos, double ypos) {
    InputManager::mousePos = glm::vec2(xpos, ypos);
}

void InputManager::init(GLFWwindow* win) {
    window = win;
    
    glfwSetKeyCallback(window, key_callback_global);
    glfwSetMouseButtonCallback(window, mouse_button_callback_global);
    glfwSetCursorPosCallback(window, cursor_position_callback_global);
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    lastMousePos = glm::vec2(x, y);
    mousePos = glm::vec2(x, y);
}

void InputManager::update() {
    // Atualizar mouse delta
    mouseDelta = mousePos - lastMousePos;
    lastMousePos = mousePos;
    
    // Copiar keysPressed para keys
    std::memcpy(keys, keysPressed, sizeof(keys));
    std::memcpy(mouseButtons, mouseButtonsPressed, sizeof(mouseButtons));
}

bool InputManager::isKeyPressed(int key) {
    if (key < 0 || key >= GLFW_KEY_LAST) return false;
    return keys[key];
}

bool InputManager::isKeyJustPressed(int key) {
    if (key < 0 || key >= GLFW_KEY_LAST) return false;
    return keysPressed[key];
}

glm::vec2 InputManager::getMousePosition() {
    return mousePos;
}

glm::vec2 InputManager::getMouseDelta() {
    return mouseDelta;
}

bool InputManager::isMouseButtonPressed(int button) {
    if (button < 0 || button >= GLFW_MOUSE_BUTTON_LAST) return false;
    return mouseButtons[button];
}

bool InputManager::isMouseButtonJustPressed(int button) {
    if (button < 0 || button >= GLFW_MOUSE_BUTTON_LAST) return false;
    return mouseButtonsPressed[button];
}

void InputManager::setCursorMode(bool locked) {
    if (window) {
        glfwSetInputMode(window, GLFW_CURSOR, locked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    }
}
