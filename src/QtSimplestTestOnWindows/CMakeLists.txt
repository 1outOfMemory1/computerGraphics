cmake_minimum_required(VERSION 3.10)
project(Qt-CMake-HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "F:/bigSoftware/qt/6.2.0/mingw81_64/lib/cmake")
find_package(Qt6Widgets  REQUIRED)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)
add_executable(helloworld main.cpp)
target_link_libraries(helloworld  Qt6::Widgets  )