//
// Created by yhn on 6/21/2021.
//

#ifndef QT_CMAKE_HELLOWORLD_POLYGONMINE_H
#define QT_CMAKE_HELLOWORLD_POLYGONMINE_H


#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <vector>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
using namespace std;

class PolygonMine : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core{
Q_OBJECT

public:
    explicit PolygonMine(QWidget *parent);
    ~PolygonMine();


protected:
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL()  override;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() override;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
private:
    QOpenGLShaderProgram _shaderProgram;
    GLuint _VAO;
    GLuint _VBO;
    float width;
    float height;
    void initShaders();

    void initTextures();
    QPoint  mousePressPosition;
    vector<QPoint> *linesVector;


};


#endif //QT_CMAKE_HELLOWORLD_POLYGONMINE_H
