#ifndef OPENGLPRACTICE_GLFWWINDOW_HPP
#define OPENGLPRACTICE_GLFWWINDOW_HPP

#include "ICoreWindow.hpp"
#include <GLFW/glfw3.h>

namespace ETT::Core {
class GLFWWindow : public ETT::Core::ICoreWindow {
public:
    GLFWWindow(int width, int height, const std::string& title);
    void update() override;
    void clear() override;
    void destroy() override;

    bool wasCloseButtonClicked() override;
private:
    GLFWwindow *window{nullptr};
};
}



#endif //OPENGLPRACTICE_GLFWWINDOW_HPP
