#include <fstream>
#include <iostream>
#include <filesystem>
#include <glad/glad.h>

#include "GLShader.hpp"

using namespace ETT::Core;

/**
 * GLShader will assume there are vertex and fragment shaders in the given path.
 *
 * File Extensions for shaders
 * .vert: Vertex Shader
 * .frag: Fragment Shader
 * .tcs:  Tessellation Control Shader
 * .tes:  Tessellation Evaluation Shader
 *
 * @param shader_name The path to the vertex/fragment shader file without extension
 */
void GLShader::init(const std::string& shader_path) {
    // TODO: Check of .vert or .frag exist before loading.
    std::string vertShaderSource = GLShader::loadFile(shader_path + ".vert");
    std::string fragShaderSource = GLShader::loadFile(shader_path + ".frag");
    std::string tescShaderSource = GLShader::loadFile(shader_path + ".tesc");
    std::string teseShaderSource = GLShader::loadFile(shader_path + ".tese");
    std::string geomShaderSource = GLShader::loadFile(shader_path + ".geom");

    const auto *source = (const GLchar *)vertShaderSource.c_str(); // Middleman for std::string to GLchar

    // Vertex Shader - Add Source, Compile shader...
    int vShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShaderID, 1, &source, nullptr);
    glCompileShader(vShaderID);

    // Fragment Shader - Add Source, Compile shader...
    int fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    source = (const GLchar *)fragShaderSource.c_str();
    glShaderSource(fShaderID, 1, &source, nullptr);
    glCompileShader(fShaderID);

    // Tessellation Control Shader - Add Source, Compile shader...
    int tescShaderID = glCreateShader(GL_TESS_CONTROL_SHADER);
    source = (const GLchar *)tescShaderSource.c_str();
    glShaderSource(tescShaderID, 1, &source, nullptr);
    glCompileShader(tescShaderID);

    // Tessellation Evaluation Shader - Add Source, Compile shader...
    int teseShaderID = glCreateShader(GL_TESS_EVALUATION_SHADER);
    source = (const GLchar *)teseShaderSource.c_str();
    glShaderSource(teseShaderID, 1, &source, nullptr);
    glCompileShader(teseShaderID);

    // Geometry Evaluation Shader - Add Source, Compile shader...
    int geomShaderID = glCreateShader(GL_GEOMETRY_SHADER);
    source = (const GLchar *)geomShaderSource.c_str();
    glShaderSource(geomShaderID, 1, &source, nullptr);
    glCompileShader(geomShaderID);

    // Create program and attach shaders, and complete program
    this->shaderProgramID = glCreateProgram();
    glAttachShader(this->shaderProgramID, vShaderID);
    glAttachShader(this->shaderProgramID, fShaderID);
    glAttachShader(this->shaderProgramID, tescShaderID);
    glAttachShader(this->shaderProgramID, teseShaderID);
    glAttachShader(this->shaderProgramID, geomShaderID);
    glLinkProgram(this->shaderProgramID);
    glValidateProgram(this->shaderProgramID);

    // Delete these references to the shader. (They won't be deleted as long as they're apart of the shader program).
    glDeleteShader(vShaderID);
    glDeleteShader(fShaderID);
    glDeleteShader(tescShaderID);
    glDeleteShader(teseShaderID);
    glDeleteShader(geomShaderID);
}

void GLShader::destroy() {
    glUseProgram(0);
    glDeleteProgram(this->shaderProgramID);
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
