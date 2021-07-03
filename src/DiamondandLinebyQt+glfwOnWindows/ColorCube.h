//
// Created by yhn on 7/2/2021.
//

#ifndef QT_CMAKE_HELLOWORLD_COLORCUBE_H
#define QT_CMAKE_HELLOWORLD_COLORCUBE_H


#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <GLFW/glfw3.h>


class ColorCube : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
public:
    explicit  ColorCube(QWidget *parent);

    ~ColorCube();

protected:
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL() override ;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() override;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) override;

private:
    QOpenGLShaderProgram _shaderProgram;
    GLuint _VAO;
    GLuint _VBO;
    float width;
    float height;

    void initShaders();

    void initTextures();
};


#endif //QT_CMAKE_HELLOWORLD_COLORCUBE_H
