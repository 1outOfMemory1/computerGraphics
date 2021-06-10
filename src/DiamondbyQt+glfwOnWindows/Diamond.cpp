//
// Created by yhn on 6/5/21.
//

#include "Diamond.h"
#include "math.h"
#define PI 3.1415926
#include "iostream"
Diamond::Diamond(QWidget *parent,float scale,int pointNum) {
    total = pointNum;
    this->scale = scale;
}

Diamond::~Diamond() {

}

void Diamond::initializeGL() {
    //为当前上下文初始化OpenGL函数解析
    initializeOpenGLFunctions();

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

    //从LearnOpenGL移植过来
    int i = 0;

    float  *point = new float [3 * total ];
    double piece = (2*PI)/total;

    for(int m=0;m<total;m++){
        point[3*m] = scale *  cos(piece * m) ;
        point[3*m + 1] = scale *  sin(piece * m) ;
        point[3*m + 2] = 0;
    }

    unsigned int *indices = new unsigned int[2 * total * total];
    float  *vertices = new float [3 * total *total *2];


    for(int n=0;n<total;n++){
        for(int k=0;k<total;k++){
            vertices[n*total*3*2 +k*6] =  point[3*n] ;
            vertices[n*total*3*2 +k*6 + 1] =   point[3*n+1];
            vertices[n*total*3*2 +k*6 + 2] = 0;

            vertices[n*total*3*2 +k*6 + 3] =    point[3*k];
            vertices[n*total*3*2 +k*6 + 4] =    point[3*k+1];
            vertices[n*total*3*2 +k*6 + 5] = 0;
        }
    }





//    float vertices[] = {
//            -0.5f, -0.5f, 0.0f, // left bottom
//            0.5f, -0.5f, 0.0f, // right  bottom
//            -0.5f,  0.5f, 0.0f,  // left top
//            0.5f,  0.5f, 0.0f  // right top
//    };
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float )* total*total*3*2, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void Diamond::paintGL() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    _shaderProgram.bind();
    //传递值
    _shaderProgram.setUniformValue("myColor", QVector3D(0.0f,1.0f,0.0f));
    //绘制三角
    glBindVertexArray(_VAO);
    glDrawArrays(GL_LINES, 0, 2*total*total);

    _shaderProgram.release();
}

void Diamond::resizeGL(int width, int height) {
    glViewport(0,0,width,height);
}

