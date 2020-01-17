//
// Created by James on 1/16/20.
//

#include "GLShader.hpp"
#include <fstream>
#include <iostream>


using namespace ETT::Core;

/**
 * GLShader will assume there are vertex and fragment shaders o
 *
 * @param shader_name The path to the vertex/fragment shader file without extension
 */
GLShader::GLShader(const std::string& shader_path) {
    // TODO: Check of .vert or .frag exist before loading.
    std::string vShaderSource = GLShader::loadFile(shader_path + ".vert");
    std::string fShaderSource = GLShader::loadFile(shader_path + ".frag");

    const auto *source = (const GLchar *)vShaderSource.c_str(); // Middleman for std::string to GLchar

    // Vertex Shader - Add Source, Compile shader...
    int vShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShaderID, 1, &source, nullptr);
    glCompileShader(vShaderID);

    // Fragment Shader - Add Source, Compile shader...
    int fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    source = (const GLchar *)fShaderSource.c_str();
    glShaderSource(fShaderID, 1, &source, nullptr);
    glCompileShader(fShaderID);

    // Create program and attach shaders, and complete program
    this->shaderProgramID = glCreateProgram();
    glAttachShader(this->shaderProgramID, vShaderID);
    glAttachShader(this->shaderProgramID, fShaderID);
    glLinkProgram(this->shaderProgramID);
    glValidateProgram(this->shaderProgramID);

    // Delete these references to the shader. (They won't be deleted as long as they're apart of the shader program).
    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);
}

void GLShader::activate() {
    glUseProgram(this->shaderProgramID);
}

std::string GLShader::loadFile(std::string file) {
    std::ifstream inputFile{file};
    std::string res, line;

    while(!inputFile.eof()){
        std::getline(inputFile, line);
        res += line + "\n";
    }

    inputFile.close();
    return res;
}