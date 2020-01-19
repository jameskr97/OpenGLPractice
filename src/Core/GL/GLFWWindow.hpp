#ifndef OPENGLPRACTICE_GLFWWINDOW_HPP
#define OPENGLPRACTICE_GLFWWINDOW_HPP

#include "Core/Interface/ICoreWindow.hpp"
#include <GLFW/glfw3.h>

namespace ETT::Core {
class GLFWWindow : public ETT::Core::ICoreWindow {
public:
    void init(int width, int height, const std::string& title) override;
    void update() override;
    void clear() override;
    void destroy() override;

    bool wasCloseButtonClicked() override;
private:
    GLFWwindow *window{nullptr};
};
}



#endif //OPENGLPRACTICE_GLFWWINDOW_HPP
