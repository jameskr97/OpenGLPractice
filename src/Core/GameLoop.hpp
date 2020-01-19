#ifndef OPENGLPRACTICE_GAMELOOP_HPP
#define OPENGLPRACTICE_GAMELOOP_HPP

#include <chrono>

/**
 * Articles used to help write this game loop
 *  - https://gafferongames.com/post/fix_your_timestep/
 *  - https://dewitters.com/dewitters-gameloop/
 *  - http://www.fabiensanglard.net/timer_and_framerate/index.php
 */

namespace ETT::Core {

class GameLoop {
public:
    void run();

private:
    // Constants
    std::chrono::milliseconds timestep{16}; // FPS CONSTANT

    // Variables
    std::chrono::duration<double, std::nano> updateTime{0};

    bool isRunning{false};

protected:
    virtual void init() = 0;
    virtual void update(double delta) = 0;
    virtual void render() = 0;
    virtual void shutdown() = 0;
};

}

#endif //OPENGLPRACTICE_GAMELOOP_HPP
