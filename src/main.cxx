#include "GLFWWindow.hpp"

int main(int argc, char** argv){

    ETT::Core::GLFWWindow window;
    window.init(854, 480, "OpenGLPractice");

    while(!window.wasCloseButtonClicked()){


        window.update();
        window.clear();
    }

    window.destroy();

	return 0;
}
