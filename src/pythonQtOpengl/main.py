"""
glfw_FirstTriangle.py
Author: dalong10
Description: Draw a Triagle, learning OPENGL
"""
import glutils  # Common OpenGL utilities,see glutils.py
import sys, random, math
import OpenGL
from OpenGL.GL import *
from OpenGL.GL.shaders import *
import numpy
import numpy as np
import glfw

strVS = """
#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
void main(){
	gl_Position.xyz = vertexPosition_modelspace;
	gl_Position.w = 1.0;
	}
"""

strFS = """
#version 330 core
out vec3 color;
void main(){
	color = vec3(1,0,0);
	}
"""


class FirstTriangle:
    def __init__(self, side):
        self.side = side

        # load shaders
        self.program = glutils.loadShaders(strVS, strFS)
        glUseProgram(self.program)

        s = side / 1.0
        vertices = [
            -s, -s, 0,
            s, -s, 0,
            0, s, 0
        ]

        # set up vertex array object (VAO)
        self.vao = glGenVertexArrays(1)
        glBindVertexArray(self.vao)
        # set up VBOs
        vertexData = numpy.array(vertices, numpy.float32)
        self.vertexBuffer = glGenBuffers(1)
        glBindBuffer(GL_ARRAY_BUFFER, self.vertexBuffer)
        glBufferData(GL_ARRAY_BUFFER, 4 * len(vertexData), vertexData,
                     GL_STATIC_DRAW)
        # enable arrays
        self.vertIndex = 0
        glEnableVertexAttribArray(self.vertIndex)
        # set buffers
        glBindBuffer(GL_ARRAY_BUFFER, self.vertexBuffer)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, None)
        # unbind VAO
        glBindVertexArray(0)

    def render(self):
        # use shader
        glUseProgram(self.program)
        # bind VAO
        glBindVertexArray(self.vao)
        # draw
        glDrawArrays(GL_TRIANGLES, 0, 3)
        # unbind VAO
        glBindVertexArray(0)


if __name__ == '__main__':
    import sys
    import glfw
    import OpenGL.GL as gl


    def on_key(window, key, scancode, action, mods):
        if key == glfw.KEY_ESCAPE and action == glfw.PRESS:
            glfw.set_window_should_close(window, 1)


    # Initialize the library
    if not glfw.init():
        sys.exit()

    # Create a windowed mode window and its OpenGL context
    window = glfw.create_window(640, 480, "Hello World", None, None)
    if not window:
        glfw.terminate()
        sys.exit()

    # Make the window's context current
    glfw.make_context_current(window)
    # Install a key handler
    glfw.set_key_callback(window, on_key)

    # Loop until the user closes the window
    while not glfw.window_should_close(window):
        # Render here
        width, height = glfw.get_framebuffer_size(window)
        ratio = width / float(height)
        gl.glViewport(0, 0, width, height)
        gl.glClear(gl.GL_COLOR_BUFFER_BIT)

        gl.glClearColor(0.0, 0.0, 4.0, 0.0)
        firstTriangle0 = FirstTriangle(1.0)
        # render
        firstTriangle0.render()
        # Swap front and back buffers
        glfw.swap_buffers(window)
        # Poll for and process events
        glfw.poll_events()

    glfw.terminate()
