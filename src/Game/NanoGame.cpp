#include "NanoGame.hpp"
#include <cmath>
#include <OpenGL/gl3.h>

void NanoGame::init() {
    window.init(854, 480,  "OpenGLPractice");
    shader.init("../Data/test");

    GLuint vertex_array_object;
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);
}

void NanoGame::shutdown() {
    window.destroy();
}

void NanoGame::update(double delta) {
    i += 0.01;

    if(window.wasCloseButtonClicked()){
        this->stop();
    }
}

void NanoGame::render() {
    window.clear();
    shader.activate();
    GLfloat attrib[] = { (float)sin(i) * 0.5f, (float)cos(i) * 0.5f, 0.0f, 0.0f };
    glVertexAttrib4fv(0, attrib);
    GLfloat color[] = {i,i,i,1.0f};
    glVertexAttrib4fv(1, color);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    window.update();
}


