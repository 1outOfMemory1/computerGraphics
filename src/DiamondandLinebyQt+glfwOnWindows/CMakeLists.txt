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

include_directories(D:/EnglishSoftware/c++Env/opengl/freeglut-msvc/include) # 添加include头文件目录
link_directories(D:/EnglishSoftware/c++Env/opengl/freeglut-msvc/lib/x64) # 添加lib库目录
add_executable(helloworld main.cpp mainwindow.h mainwindow.cpp Diamond.h Diamond.cpp Line.cpp Line.h)
target_link_libraries(helloworld
        Qt::Core
        Qt::Gui
        Qt::OpenGL
        Qt::OpenGLWidgets
        Qt::Widgets )