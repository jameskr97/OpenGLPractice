#include <OpenGL/gl3.h>

#include "Core/GL/GLFWWindow.hpp"
#include "Core/GL/GLShader.hpp"

int main(int argc, char** argv){

    ETT::Core::GLFWWindow window;
    window.init(854, 480,  "OpenGLPractice");

    ETT::Core::GLShader shader{"../Data/test"};

    GLuint vertex_array_object;
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    while(!window.wasCloseButtonClicked()){
        window.clear();

        shader.activate();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }

    window.destroy();

	return 0;
}
