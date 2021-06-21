//
// Created by yhn on 2021/6/8.
//

#ifndef QT_CMAKE_HELLOWORLD_LINE_H
#define QT_CMAKE_HELLOWORLD_LINE_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include "vector"
using namespace std;

class Line :public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
Q_OBJECT


public:
    explicit  Line(QWidget *parent);

    ~Line();

protected:
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL() override ;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() override;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override ;
private:
    float width,height;
    QPoint  mousePressPosition;
    QOpenGLShaderProgram _shaderProgram;
    GLuint _VAO;
    GLuint _VBO;
    vector<QPoint> *linesVector;
    void initShaders();
    float *vertices;
    void initTextures();
};


#endif //QT_CMAKE_HELLOWORLD_LINE_H
