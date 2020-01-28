#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "NanoGame.hpp"


void NanoGame::init() {
    window.init(854, 480,  "OpenGLPractice");
    shader.init("../Data/test");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    GLuint vertex_array_object;
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    // VERTEX DATA
    glm::vec3 triangle[] = {glm::vec3(-2.0,3.0,0.0),
            glm::vec3(2.0,3.0,0.0),
            glm::vec3(0.0,2.0,0.0)};
    glm::vec3 cube[] = {glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),
            glm::vec3(1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(1.0f,-1.0f,-1.0f),
            glm::vec3(1.0f, 1.0f,-1.0f),
            glm::vec3(1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),
            glm::vec3(1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f,-1.0f, 1.0f),
            glm::vec3(1.0f,-1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f,-1.0f,-1.0f),
            glm::vec3(1.0f, 1.0f,-1.0f),
            glm::vec3(1.0f,-1.0f,-1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f,-1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f,-1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f),
            glm::vec3(1.0f,-1.0f, 1.0f)};
    glm::vec3 colors[] = {glm::vec3{0.583f, 0.771f, 0.014f},
            glm::vec3{0.609f, 0.115f, 0.436f},
            glm::vec3{0.327f, 0.483f, 0.844f},
            glm::vec3{0.822f, 0.569f, 0.201f},
            glm::vec3{0.435f, 0.602f, 0.223f},
            glm::vec3{0.310f, 0.747f, 0.185f},
            glm::vec3{0.597f, 0.770f, 0.761f},
            glm::vec3{0.559f, 0.436f, 0.730f},
            glm::vec3{0.359f, 0.583f, 0.152f},
            glm::vec3{0.483f, 0.596f, 0.789f},
            glm::vec3{0.559f, 0.861f, 0.639f},
            glm::vec3{0.195f, 0.548f, 0.859f},
            glm::vec3{0.014f, 0.184f, 0.576f},
            glm::vec3{0.771f, 0.328f, 0.970f},
            glm::vec3{0.406f, 0.615f, 0.116f},
            glm::vec3{0.676f, 0.977f, 0.133f},
            glm::vec3{0.971f, 0.572f, 0.833f},
            glm::vec3{0.140f, 0.616f, 0.489f},
            glm::vec3{0.997f, 0.513f, 0.064f},
            glm::vec3{0.945f, 0.719f, 0.592f},
            glm::vec3{0.543f, 0.021f, 0.978f},
            glm::vec3{0.279f, 0.317f, 0.505f},
            glm::vec3{0.167f, 0.620f, 0.077f},
            glm::vec3{0.347f, 0.857f, 0.137f},
            glm::vec3{0.055f, 0.953f, 0.042f},
            glm::vec3{0.714f, 0.505f, 0.345f},
            glm::vec3{0.783f, 0.290f, 0.734f},
            glm::vec3{0.722f, 0.645f, 0.174f},
            glm::vec3{0.302f, 0.455f, 0.848f},
            glm::vec3{0.225f, 0.587f, 0.040f},
            glm::vec3{0.517f, 0.713f, 0.338f},
            glm::vec3{0.053f, 0.959f, 0.120f},
            glm::vec3{0.393f, 0.621f, 0.362f},
            glm::vec3{0.673f, 0.211f, 0.457f},
            glm::vec3{0.820f, 0.883f, 0.371f},
            glm::vec3{0.982f,  0.099f,  0.879f}};

    glGenBuffers(1, &triangleBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    glGenBuffers(1, &cubeBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, cubeBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);

    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // CAMERA
    glm::mat4 projMatrix = glm::perspective(glm::radians(60.0f), (float)  window.getWidth() / (float)window.getHeight(), 0.1f, 100.0f);
    glm::mat4 viewMatrix = glm::lookAt(
            glm::vec3{0, 5, -10},
            glm::vec3{0,0,0},
            glm::vec3{0,1,0});
    mvpMatrix = projMatrix * viewMatrix;
    MatrixID = glGetUniformLocation(shader.shaderProgramID, "mvp");

}

void NanoGame::shutdown() {
    shader.destroy();
    window.destroy();
}

void NanoGame::update(double delta) {
    window.update();

    if(window.wasCloseButtonClicked()){
        this->stop();
    }
}

void NanoGame::render() {
    window.clear();
    shader.activate();

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvpMatrix[0][0]);

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, cubeBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}


