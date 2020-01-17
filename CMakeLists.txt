cmake_minimum_required(VERSION 3.14.0)
project(OpenGLPractice VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenGLPractice)
target_include_directories(OpenGLPractice PRIVATE src)
add_subdirectory(src)
add_subdirectory(libs)

find_package(OpenGL REQUIRED)
target_link_libraries(OpenGLPractice ${OPENGL_LIBRARIES})

target_link_libraries(OpenGLPractice glfw)
target_link_libraries(OpenGLPractice glm::glm)
target_link_libraries(OpenGLPractice ${LIBRARY_OPENGL})
target_compile_definitions(OpenGLPractice PRIVATE GL_SILENCE_DEPRECATION=1)