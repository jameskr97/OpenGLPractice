#ifndef OPENGLPRACTICE_GLFWWINDOW_HPP
#define OPENGLPRACTICE_GLFWWINDOW_HPP

#include "Core/Interface/ICoreWindow.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ETT::Core {
class GLFWWindow : public ETT::Core::ICoreWindow {
public:
    void init(int width, int height, const std::string& title) override;
    void update() override;
    void clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f) override;
    void destroy() override;

    bool wasCloseButtonClicked() override;
private:
    GLFWwindow *window{nullptr};
};
}



#endif //OPENGLPRACTICE_GLFWWINDOW_HPP
