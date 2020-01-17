#include <OpenGL/gl3.h>
#include "GLFWWindow.hpp"

using namespace ETT::Core;

GLFWWindow::GLFWWindow(const int width, const int height, const std::string& title){
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
}

void GLFWWindow::update(){
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void GLFWWindow::clear(){
    static const GLfloat color[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, color);
}

void GLFWWindow::destroy(){
    glfwTerminate();
}

bool GLFWWindow::wasCloseButtonClicked(){
    return glfwWindowShouldClose(this->window);
}
