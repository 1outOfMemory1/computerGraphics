# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\EnglishSoftware\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\EnglishSoftware\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\project\github\unfinished\computerGraphics\src\glfwOpengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/glfwOpengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glfwOpengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glfwOpengl.dir/flags.make

CMakeFiles/glfwOpengl.dir/main.cpp.obj: CMakeFiles/glfwOpengl.dir/flags.make
CMakeFiles/glfwOpengl.dir/main.cpp.obj: CMakeFiles/glfwOpengl.dir/includes_CXX.rsp
CMakeFiles/glfwOpengl.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/glfwOpengl.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\glfwOpengl.dir\main.cpp.obj -c F:\project\github\unfinished\computerGraphics\src\glfwOpengl\main.cpp

CMakeFiles/glfwOpengl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwOpengl.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\project\github\unfinished\computerGraphics\src\glfwOpengl\main.cpp > CMakeFiles\glfwOpengl.dir\main.cpp.i

CMakeFiles/glfwOpengl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwOpengl.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\project\github\unfinished\computerGraphics\src\glfwOpengl\main.cpp -o CMakeFiles\glfwOpengl.dir\main.cpp.s

CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.obj: CMakeFiles/glfwOpengl.dir/flags.make
CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.obj: CMakeFiles/glfwOpengl.dir/includes_C.rsp
CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.obj: D:/EnglishSoftware/c++Env/opengl/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glfwOpengl.dir\D_\EnglishSoftware\c++Env\opengl\glad\src\glad.c.obj -c D:\EnglishSoftware\c++Env\opengl\glad\src\glad.c

CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\EnglishSoftware\c++Env\opengl\glad\src\glad.c > CMakeFiles\glfwOpengl.dir\D_\EnglishSoftware\c++Env\opengl\glad\src\glad.c.i

CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\EnglishSoftware\c++Env\opengl\glad\src\glad.c -o CMakeFiles\glfwOpengl.dir\D_\EnglishSoftware\c++Env\opengl\glad\src\glad.c.s

# Object files for target glfwOpengl
glfwOpengl_OBJECTS = \
"CMakeFiles/glfwOpengl.dir/main.cpp.obj" \
"CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.obj"

# External object files for target glfwOpengl
glfwOpengl_EXTERNAL_OBJECTS =

glfwOpengl.exe: CMakeFiles/glfwOpengl.dir/main.cpp.obj
glfwOpengl.exe: CMakeFiles/glfwOpengl.dir/D_/EnglishSoftware/c++Env/opengl/glad/src/glad.c.obj
glfwOpengl.exe: CMakeFiles/glfwOpengl.dir/build.make
glfwOpengl.exe: CMakeFiles/glfwOpengl.dir/linklibs.rsp
glfwOpengl.exe: CMakeFiles/glfwOpengl.dir/objects1.rsp
glfwOpengl.exe: CMakeFiles/glfwOpengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable glfwOpengl.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glfwOpengl.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glfwOpengl.dir/build: glfwOpengl.exe

.PHONY : CMakeFiles/glfwOpengl.dir/build

CMakeFiles/glfwOpengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\glfwOpengl.dir\cmake_clean.cmake
.PHONY : CMakeFiles/glfwOpengl.dir/clean

CMakeFiles/glfwOpengl.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\project\github\unfinished\computerGraphics\src\glfwOpengl F:\project\github\unfinished\computerGraphics\src\glfwOpengl F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug F:\project\github\unfinished\computerGraphics\src\glfwOpengl\cmake-build-debug\CMakeFiles\glfwOpengl.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glfwOpengl.dir/depend
