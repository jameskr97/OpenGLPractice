list(APPEND SRC
        main.cxx
        Core/GL/GLFWWindow.cpp
        Core/GL/GLFWWindow.hpp
        Core/GL/GLShader.cpp
        Core/GL/GLShader.hpp
        Core/Interface/ICoreWindow.hpp
        Core/GameLoop.cpp
        Core/GameLoop.hpp

        Game/NanoGame.cpp
        Game/NanoGame.hpp)

target_sources(OpenGLPractice PUBLIC ${SRC})
