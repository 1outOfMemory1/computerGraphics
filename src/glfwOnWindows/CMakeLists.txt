cmake_minimum_required(VERSION 3.19)
project(glfwOpengl)

include_directories("C:/Program Files (x86)/Eigen3/include")
set(OpenCV_DIR "G:/environment/c++Env/opencv")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_CXX_STANDARD 14)



find_package(OpenCV REQUIRED)

include_directories(G:/environment/c++Env/opengl/glfw/include)
include_directories(G:/environment/c++Env/opengl/glad/include)
include_directories(G:/environment/c++Env/opengl/glad/src)
include_directories(G:/environment/c++Env/opengl/glew/include)
include_directories(G:/environment/c++Env/opengl/glm)
link_directories(G:/environment/c++Env/opengl/glfw/lib-mingw-w64)
link_directories(G:/environment/c++Env/opengl/glew/lib/Release/x64)



add_executable(static_diamond static_diamond.cpp G:/environment/c++Env/opengl/glad/src/glad.c)
add_executable(dynamic_diamond dynamic_diamond.cpp G:/environment/c++Env/opengl/glad/src/glad.c )
add_executable(sixEdgeFigure sixEdgeFigure.cpp G:/environment/c++Env/opengl/glad/src/glad.c)
add_executable(colorCube colorCube.cpp utilClass/stb_image.h utilClass/stb_image.cpp G:/environment/c++Env/opengl/glad/src/glad.c)
add_executable(ballLight ball.cpp utilClass/stb_image.h utilClass/stb_image.cpp G:/environment/c++Env/opengl/glad/src/glad.c)
add_executable(cubeLight cubeLight.cpp utilClass/stb_image.h utilClass/stb_image.cpp G:/environment/c++Env/opengl/glad/src/glad.c)
add_executable(skybox cubemaps_skybox.cpp utilClass/stb_image.h utilClass/stb_image.cpp G:/environment/c++Env/opengl/glad/src/glad.c)
add_executable(besaier besaier.cpp)
add_executable(lineCut lineCut.cpp)


target_link_libraries(static_diamond glfw3.dll  )
target_link_libraries(dynamic_diamond glfw3.dll )
target_link_libraries(sixEdgeFigure glfw3.dll glew32.lib opengl32.dll)
target_link_libraries(colorCube glfw3.dll glew32.lib opengl32.dll )
target_link_libraries(ballLight glfw3.dll glew32.lib opengl32.dll )
target_link_libraries(cubeLight glfw3.dll glew32.lib opengl32.dll )
target_link_libraries(skybox glfw3.dll glew32.lib opengl32.dll )
target_link_libraries(besaier  ${OpenCV_LIBS})
target_link_libraries(lineCut glfw3.dll glew32.lib opengl32.dll)
