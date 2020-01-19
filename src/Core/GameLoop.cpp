#include "GameLoop.hpp"

using namespace ETT::Core;


void GameLoop::run() {
    this->init();
    this->isRunning = true;

    using clock = std::chrono::steady_clock;

    // Get a starting time
    auto currentTime = clock::now();
    while(this->isRunning){
        auto newTime = clock::now(); // Get time after last frame was processed
        auto frameTime = newTime - currentTime; // Get difference (delta) of frame. (how long the frame took).
        currentTime = newTime; // Now that we have delta, change the starting time to the newTime.
        updateTime += frameTime; // Add (how long the frame took) to (the amount of time we have to update before we need to render again).

        // As long as we have the time (in timestep [aka updates per second) increments, keep updating.
        // This allows us to update at a constant timestep, which letting the render function run as fast as it would like to.
        if(updateTime >= timestep){
            this->update((double)timestep.count() / std::chrono::nanoseconds::period::den);
            updateTime -= timestep; // decrement by timestep
        }

        render();
    }
    this->shutdown();
}