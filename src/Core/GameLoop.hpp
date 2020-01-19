#ifndef OPENGLPRACTICE_GAMELOOP_HPP
#define OPENGLPRACTICE_GAMELOOP_HPP

#include <chrono>

/**
 * Articles used to help write this game loop
 *  1. https://gafferongames.com/post/fix_your_timestep/
 *  2. https://dewitters.com/dewitters-gameloop/
 *  3. http://www.fabiensanglard.net/timer_and_framerate/index.php
 */


namespace ETT::Core {

class GameLoop {
public:
    void run();
    double getFPS();

private:
    // Constants
    std::chrono::milliseconds timestep{16}; // UPDATES PER SECOND CONSTANT

    // Variables
    std::chrono::duration<double, std::nano> updateTime{0}; // updateTime accumulation (view link #1 above)

    // FPS Tracking
    double frameCount{0}, fps{0};
    std::chrono::duration<double, std::nano> fpsTime{0};

    bool isRunning{false};

protected:
    virtual void init() = 0;
    virtual void update(double delta) = 0;
    virtual void render() = 0;
    virtual void shutdown() = 0;
};

}

#endif //OPENGLPRACTICE_GAMELOOP_HPP
