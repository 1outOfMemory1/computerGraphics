cmake_minimum_required(VERSION 3.19)
project(glfwOpengl)

set(CMAKE_CXX_STANDARD 14)

include_directories(D:/EnglishSoftware/c++Env/opengl/glfw/include)
include_directories(D:/EnglishSoftware/c++Env/opengl/glad/include)
include_directories(D:/EnglishSoftware/c++Env/opengl/glad/src)
link_directories(D:/EnglishSoftware/c++Env/opengl/glfw/lib-mingw-w64)

add_executable(glfwOpengl main.cpp D:/EnglishSoftware/c++Env/opengl/glad/src/glad.c)
add_executable(test test.cpp D:/EnglishSoftware/c++Env/opengl/glad/src/glad.c)
target_link_libraries(glfwOpengl glfw3.dll )
target_link_libraries(test glfw3.dll )