#ifndef OPENGLPRACTICE_SHADER_HPP
#define OPENGLPRACTICE_SHADER_HPP

#include <string>

namespace Engine::Core {
class Shader {
public:
    void init(const std::string& shader_path = nullptr);
    void destroy();
    void activate();

private:
    static std::string loadFile(std::string file); // TODO: FACTOR OUT TO REUSABLE FILE LOADER
    int shaderProgramID{0};
};
}

#endif //OPENGLPRACTICE_SHADER_HPP
