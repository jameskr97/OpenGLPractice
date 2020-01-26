#include <glad/glad.h>

#include "Window.hpp"

using namespace Engine::Core;

void Window::init(const int width, const int height, const std::string& title){
    glfwInit();

    #ifdef __APPLE__
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeLimits(window, 720, 405, GLFW_DONT_CARE, GLFW_DONT_CARE);
    glfwSetWindowAspectRatio(window, 16, 9);

    gladLoadGL();
}

void Window::update(){
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void Window::clear(float r, float g, float b, float a){
    static const GLfloat color[] = {r, g, b, a};
    glClearBufferfv(GL_COLOR, 0, color);
}

void Window::destroy(){
    glfwTerminate();
}

bool Window::wasCloseButtonClicked(){
    return glfwWindowShouldClose(this->window);
}
