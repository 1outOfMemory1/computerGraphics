#cmake_minimum_required(VERSION 3.19)
project(gl_demo)
#
#set(CMAKE_CXX_STANDARD 14)
#
#include_directories(D:/EnglishSoftware/c++Env/opengl/glfw/include)
#include_directories(D:/EnglishSoftware/c++Env/opengl/glad/include)
#include_directories(D:/EnglishSoftware/c++Env/opengl/glad/src)
#include_directories(D:/EnglishSoftware/c++Env/opengl/freeglut/include)
#link_directories(F:/freeGlutmingw/bin)
#link_directories(F:/freeGlutmingw/lib)
#link_directories(D:/EnglishSoftware/c++Env/opengl/freeglut/lib/x64)
#link_directories(F:/bigSoftware/qt/Tools/mingw810_64/x86_64-w64-mingw32/lib)
#link_directories(C:/MinGW/x86_64-w64-mingw32/lib)
#
#
#
#add_executable(test test.cpp   )
#target_link_libraries(test libfreeglut.a opengl32.dll libglu32.a)


cmake_minimum_required(VERSION 3.17)
project(gl_demo)

set(CMAKE_CXX_STANDARD 14)
include_directories(D:/EnglishSoftware/c++Env/opengl/freeglut-msvc/include) # 添加include头文件目录
link_directories(D:/EnglishSoftware/c++Env/opengl/freeglut-msvc/lib/x64) # 添加lib库目录


add_executable(star star.cpp)
target_link_libraries(star  libfreeglut.a  libglu32.a  libopengl32.a libfreeglut.a)


add_executable(line line.cpp)
target_link_libraries(line  libfreeglut libglu32  libopengl32 libfreeglut)
