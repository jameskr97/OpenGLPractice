#ifndef OPENGLPRACTICE_WINDOW_HPP
#define OPENGLPRACTICE_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core/Interface/ICoreWindow.hpp"

namespace Engine::Core {
class Window : public Engine::Core::ICoreWindow {
public:
    void init(int width, int height, const std::string& title) override;
    void update() override;
    void clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f) override;
    void destroy() override;

    bool wasCloseButtonClicked() override;

    int getWidth();
    int getHeight();

private:
    GLFWwindow *window{nullptr};
};
}



#endif //OPENGLPRACTICE_WINDOW_HPP
