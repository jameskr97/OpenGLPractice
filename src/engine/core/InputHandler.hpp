#ifndef OPENGLPRACTICE_INPUTHANDLER_HPP
#define OPENGLPRACTICE_INPUTHANDLER_HPP

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

namespace Core::Input {
class InputHandler {
    static void initCallbacks(GLFWwindow *window);

    // Accessor Functions
    static glm::vec2 getCursorPosition();

private:
    // GLFW Callbacks
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

    // Input Related
    static glm::vec2 cursorPosition;


};
}



#endif //OPENGLPRACTICE_INPUTHANDLER_HPP
