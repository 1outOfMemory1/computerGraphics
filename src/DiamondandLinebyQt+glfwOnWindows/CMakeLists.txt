cmake_minimum_required(VERSION 3.10)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "F:/bigSoftware/qt/6.2.0/mingw81_64/lib/cmake")
include_directories(G:/environment/c++Env/opengl/glm)
include_directories(G:/environment/c++Env/opengl/glad/include)
include_directories(G:/environment/c++Env/opengl/glad/src)
include_directories(G:/environment/c++Env/opengl/glfw/include)
link_directories(G:/environment/c++Env/opengl/glew/lib/Release/x64)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS OpenGL)
find_package(Qt6 COMPONENTS OpenGLWidgets)



set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
include_directories(G:/environment/c++Env/opengl/glm)
include_directories(D:/EnglishSoftware/c++Env/opengl/freeglut-msvc/include) # 添加include头文件目录
link_directories(G:/environment/c++Env/opengl/glfw/lib-mingw-w64)

add_executable(helloworld main.cpp mainwindow.h mainwindow.cpp Diamond.h Diamond.cpp
        Line.cpp Line.h PolygonMine.cpp PolygonMine.h PointMine.cpp PointMine.h
        ColorCube.cpp ColorCube.h G:/environment/c++Env/opengl/glad/src/glad.c )
target_link_libraries(helloworld
        Qt::Core
        Qt::Gui
        Qt::OpenGL
        Qt::OpenGLWidgets
        Qt::Widgets
        glfw3.dll)