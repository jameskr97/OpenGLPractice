list(APPEND SRC
        ICoreWindow.hpp
        main.cxx
        GLFWWindow.hpp GLFWWindow.cpp)

target_sources(OpenGLPractice PUBLIC ${SRC})
