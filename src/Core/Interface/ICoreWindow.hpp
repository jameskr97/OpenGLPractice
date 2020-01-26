#ifndef OPENGLPRACTICE_ICOREWINDOW_HPP
#define OPENGLPRACTICE_ICOREWINDOW_HPP

#include <string>

/**
 * Methods which must be implemented by render window/context backend in order to show a window.
 */
namespace Engine::Core {
class ICoreWindow {
public:
    ICoreWindow() = default;
    virtual void init(int width, int height, const std::string& title) = 0;
    virtual void update() = 0;
    virtual void clear(float r, float g, float b, float a) = 0;
    virtual void destroy() = 0;

    virtual bool wasCloseButtonClicked() = 0;
};
}

#endif //OPENGLPRACTICE_ICOREWINDOW_HPP
