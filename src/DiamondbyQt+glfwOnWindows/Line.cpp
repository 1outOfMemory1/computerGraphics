//
// Created by yhn on 2021/6/8.
//

#include "Line.h"
#include <QMouseEvent>
#include <iostream>
Line::Line(QWidget *parent) {

}

Line::~Line() {

}

void Line::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(1, 0, 0, 1);

    initShaders();
    initTextures();
}

void Line::paintGL() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    _shaderProgram.bind();
    //传递值
    _shaderProgram.setUniformValue("myColor", QVector3D(0.0f,1.0f,0.0f));
    _shaderProgram.release();

}

void Line::resizeGL(int width, int height) {

}

void Line::initShaders() {
    //着色器代码
    //in输入，out输出,uniform从cpu向gpu发送
    const char *vertex_str=R"(#version 330 core
                           layout (location = 0) in vec3 vertices;
                           void main() {
                           gl_Position = vec4(vertices,1.0);
                           })";
    const char *fragment_str=R"(#version 330 core
                             uniform vec3 myColor;
                             void main() {
                             gl_FragColor = vec4(myColor,1.0);
                             })";
    //将source编译为指定类型的着色器，并添加到此着色器程序
    if(!_shaderProgram.addCacheableShaderFromSourceCode(
            QOpenGLShader::Vertex,vertex_str)){
        qDebug()<<"compiler vertex error"<<_shaderProgram.log();
    }
    if(!_shaderProgram.addCacheableShaderFromSourceCode(
            QOpenGLShader::Fragment,fragment_str)){
        qDebug()<<"compiler fragment error"<<_shaderProgram.log();
    }
    //使用addShader()将添加到该程序的着色器链接在一起。
    if(!_shaderProgram.link()){
        qDebug()<<"link shaderprogram error"<<_shaderProgram.log();
    }
}

void Line::initTextures() {

}

void Line::mousePressEvent(QMouseEvent *e) {
    // Save mouse press position
    mousePressPosition = QVector2D(e->position());
}

void Line::mouseReleaseEvent(QMouseEvent *e) {
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->position()) - mousePressPosition;
    std::cout<<diff.length()<<std::endl;
}



