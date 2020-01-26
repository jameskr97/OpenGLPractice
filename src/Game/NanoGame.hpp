#ifndef OPENGLPRACTICE_NANOGAME_HPP
#define OPENGLPRACTICE_NANOGAME_HPP

#include "Core/GameLoop.hpp"
#include "Core/Window.hpp"
#include "Core/Shader.hpp"

class NanoGame : public Engine::Core::GameLoop {
private:
    // Engine Elements
    Engine::Core::Window window;
    Engine::Core::Shader shader;

    // Game Loop Methods
    void init() override;
    void update(double delta) override;
    void render() override;
    void shutdown() override;
};


#endif //OPENGLPRACTICE_NANOGAME_HPP
