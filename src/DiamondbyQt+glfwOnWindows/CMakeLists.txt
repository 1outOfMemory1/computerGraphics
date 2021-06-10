cmake_minimum_required(VERSION 3.10)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "F:/bigSoftware/qt/6.2.0/mingw81_64/lib/cmake")

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS OpenGL)
find_package(Qt6 COMPONENTS OpenGLWidgets)



set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
link_directories(helloworld D:/EnglishSoftware/c++Env/opengl/glfw/lib-vc2019)
add_executable(helloworld main.cpp mainwindow.h mainwindow.cpp Diamond.h Diamond.cpp Line.cpp Line.h)
target_link_libraries(helloworld
        glfw3.dll

        Qt::Core
        Qt::Gui
        Qt::OpenGL
        Qt::OpenGLWidgets
        Qt::Widgets )