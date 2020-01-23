#include <glad/glad.h>
#include "GLFWWindow.hpp"

using namespace ETT::Core;

void GLFWWindow::init(const int width, const int height, const std::string& title){
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

void GLFWWindow::update(){
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void GLFWWindow::clear(float r, float g, float b, float a){
    static const GLfloat color[] = {r, g, b, a};
    glClearBufferfv(GL_COLOR, 0, color);
}

void GLFWWindow::destroy(){
    glfwTerminate();
}

bool GLFWWindow::wasCloseButtonClicked(){
    return glfwWindowShouldClose(this->window);
}
