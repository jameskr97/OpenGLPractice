#include "InputHandler.hpp"

using namespace Core::Input;

// Static variables
glm::vec2 InputHandler::cursorPosition = glm::vec2(0,0);

void InputHandler::initCallbacks(GLFWwindow *window) {
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
}

glm::vec2 InputHandler::getCursorPosition() {
    return cursorPosition;
}

void InputHandler::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

void InputHandler::cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
    cursorPosition = glm::vec2(xpos, ypos);
}

