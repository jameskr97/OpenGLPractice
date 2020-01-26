list(APPEND SRC
        main.cxx
        Core/Window.cpp
        Core/Window.hpp
        Core/Shader.cpp
        Core/Shader.hpp
        Core/Interface/ICoreWindow.hpp
        Core/GameLoop.cpp
        Core/GameLoop.hpp

        Game/NanoGame.cpp
        Game/NanoGame.hpp)

target_sources(OpenGLPractice PUBLIC ${SRC})
