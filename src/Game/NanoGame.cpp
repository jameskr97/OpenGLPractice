#include <cmath>
#include <glad/glad.h>

#include "NanoGame.hpp"


void NanoGame::init() {
    window.init(854, 480,  "OpenGLPractice");
    shader.init("../Data/test");

    GLuint vertex_array_object;
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);
}

void NanoGame::shutdown() {
    shader.destroy();
    window.destroy();
}

void NanoGame::update(double delta) {

    if(window.wasCloseButtonClicked()){
        this->stop();
    }
}

void NanoGame::render() {
    window.clear();
    shader.activate();

    glDrawArrays(GL_TRIANGLES, 0, 3);

    window.update();
}


