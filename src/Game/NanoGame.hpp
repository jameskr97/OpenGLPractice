#ifndef OPENGLPRACTICE_NANOGAME_HPP
#define OPENGLPRACTICE_NANOGAME_HPP

#include "Core/GameLoop.hpp"
#include "Core/GL/GLFWWindow.hpp"
#include "Core/GL/GLShader.hpp"

class NanoGame : public ETT::Core::GameLoop {
private:
    // Engine Elements
    ETT::Core::GLFWWindow window;
    ETT::Core::GLShader shader;

    // Game Loop Methods
    void init() override;
    void update(double delta) override;
    void render() override;
    void shutdown() override;
};


#endif //OPENGLPRACTICE_NANOGAME_HPP
