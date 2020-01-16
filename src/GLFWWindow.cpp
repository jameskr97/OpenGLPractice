//
// Created by James on 1/16/20.
//

#include "GLFWWindow.hpp"

using namespace ETT::Core;

void GLFWWindow::init(int width, int height, std::string title){
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
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLFWWindow::destroy(){
    glfwTerminate();
}

bool GLFWWindow::wasCloseButtonClicked(){
    return glfwWindowShouldClose(this->window);
}
