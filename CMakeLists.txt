# ROOT CMakeLists.txt
cmake_minimum_required(VERSION 3.14.0)
project(OpenGLPractice VERSION 1.0.0 LANGUAGES C CXX)

## CMake and Compiler Setup
set(CMAKE_CXX_STANDARD 17)              # Minimum C++ Version
set(CMAKE_CXX_EXTENSIONS OFF)           # True if compiler extensions are necessary. (Changes -std flag)
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # True to require minimum C++ version to compile

# Project Build Targets
add_executable(OpenGLPractice)

## Includes
target_include_directories(OpenGLPractice PRIVATE src)

## Load libraries
add_subdirectory(libs)

## Linking
target_link_libraries(OpenGLPractice glad)
target_link_libraries(OpenGLPractice glfw)
target_link_libraries(OpenGLPractice glm::glm)
target_link_libraries(OpenGLPractice ${LIBRARY_OPENGL})

## Compile Definitions
if(APPLE)
    target_compile_definitions(OpenGLPractice PRIVATE GL_SILENCE_DEPRECATION=1)
endif()

## Source
add_subdirectory(src)
