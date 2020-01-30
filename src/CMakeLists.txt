list(APPEND SRC
        main.cxx
        engine/core/Window.cpp
        engine/core/Window.hpp
        engine/core/Shader.cpp
        engine/core/Shader.hpp
        engine/core/GameLoop.cpp
        engine/core/GameLoop.hpp
        engine/core/InputHandler.cpp
        engine/core/InputHandler.hpp

        Game/NanoGame.cpp
        Game/NanoGame.hpp)

target_sources(OpenGLPractice PUBLIC ${SRC})
