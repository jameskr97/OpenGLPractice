#ifndef OPENGLPRACTICE_WINDOW_HPP
#define OPENGLPRACTICE_WINDOW_HPP

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine::Core {
class Window {
public:
    void init(int width, int height, const std::string& title);
    void update();
    void clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
    void destroy();

    bool wasCloseButtonClicked();

    int getWidth();
    int getHeight();

private:
    GLFWwindow *window{nullptr};
};
}



#endif //OPENGLPRACTICE_WINDOW_HPP
