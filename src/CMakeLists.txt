list(APPEND SRC
        ICoreWindow.hpp
        main.cxx
        GLFWWindow.hpp GLFWWindow.cpp
        GLShader.hpp GLShader.cpp)

target_sources(OpenGLPractice PUBLIC ${SRC})
