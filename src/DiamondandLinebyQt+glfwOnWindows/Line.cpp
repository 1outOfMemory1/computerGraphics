//
// Created by yhn on 2021/6/8.
//

#include "Line.h"
#include <QMouseEvent>
#include <iostream>
Line::Line(QWidget *parent) {
    linesVector = new vector<QPoint>();
    width = parent->width();
    height = parent->height();

}



Line::~Line() {

}

void Line::initializeGL() {

    initializeOpenGLFunctions();

//    glClearColor(32/255.0,158/255.0,40/255.0, 1);
    glClearColor(1,1,1, 1);

    initShaders();
    initTextures();
}

void Line::paintGL() {



//    delete vertices;
    vertices = new float[linesVector->size()*3*2];

    cout<<linesVector->size()<<endl;
    for(int i =0 ;i<linesVector->size()/2;i++){

        float p1x = linesVector->at(2*i).x() / (this->width/2)  -1;
        float p1y = linesVector->at(2*i).y()  / (this->height/2)  -1;
        vertices[i * 6] = p1x ;
        vertices[i * 6 + 1] = - p1y;
        vertices[i * 6 + 2] = 0;

        float p2x = linesVector->at(2*i+1).x()  / (this->width/2)  -1;
        float p2y = linesVector->at(2*i+1).y()  / (this->height/2)  -1;

        vertices[i * 6 + 3] = p2x;
        vertices[i * 6 + 4] = - p2y;
        vertices[i * 6 + 5] = 0;
        cout<<p1x<<","<<p1y<<"$$$$"<<p2x<<","<<p2y<<endl;

    }

    int linesVectorSize = linesVector->size();

    //从LearnOpenGL移植过来

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float )*linesVectorSize*3*2, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);





    glClear(GL_COLOR_BUFFER_BIT);

    _shaderProgram.bind();
    //传递值
//    _shaderProgram.setUniformValue("myColor", QVector3D(0.0f,1.0f,0.0f));
    //绘制三角
    glBindVertexArray(_VAO);
    glDrawArrays(GL_LINES, 0, linesVectorSize);

    _shaderProgram.release();

}

void Line::resizeGL(int width, int height) {
    this->width = width;
    this->height  = height;
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
    mousePressPosition = e->pos();
}

void Line::mouseReleaseEvent(QMouseEvent *e) {
    // Mouse release position - mouse press position


    QVector2D diff = QVector2D(e->pos()) - QVector2D(mousePressPosition);
    std::cout<<"length"<<diff.length()<<std::endl;


    linesVector->push_back(mousePressPosition);
    linesVector->push_back( e->pos());


//    cout<<mousePressPosition.toPointF().x() <<","<<mousePressPosition.toPointF().y() <<endl;
//    cout<<mousePressPosition.toPointF().x() / (this->width/2)  -1<<","<<mousePressPosition.toPointF().y() / (this->height/2) -1<<endl;
//    cout<<e->pos().rx()<<","<<e->pos().ry()<<endl;
//    cout<<e->pos().rx()/ (this->width/2)  -1<<","<<e->pos().ry()/ (this->height/2)  -1<<endl;


    int linesVectorLength = linesVector->size();
    cout<<linesVectorLength<<endl;



//    paintGL();
    update();


}





