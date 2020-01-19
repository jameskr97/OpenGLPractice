#ifndef OPENGLPRACTICE_GAMELOOP_HPP
#define OPENGLPRACTICE_GAMELOOP_HPP

#include <chrono>

namespace ETT::Core {

class GameLoop {
private:
    // Constants
    std::chrono::nanoseconds timestep{16}; // FPS CONSTANT

    // Variables
    std::chrono::duration<double, std::nano> updateTime{0};

    bool isRunning{false};
    void run();

protected:
    virtual void init() = 0;
    virtual void shutdown() = 0;
    virtual void update(double delta) = 0;
    virtual void render() = 0;
};

}

#endif //OPENGLPRACTICE_GAMELOOP_HPP
