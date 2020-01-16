#ifndef OPENGLPRACTICE_ICOREWINDOW_HPP
#define OPENGLPRACTICE_ICOREWINDOW_HPP

#include <string>

/**
 * Methods which must be implemented by OpenGL window/context backend in order to show a window.
 */
namespace ETT::Core {
class ICoreWindow {
public:
    virtual void init(int width, int height, std::string title) = 0;
    virtual void update() = 0;
    virtual void clear() = 0;
    virtual void destroy() = 0;

    virtual bool wasCloseButtonClicked() = 0;
};
}

#endif //OPENGLPRACTICE_ICOREWINDOW_HPP
