//
// Created by yhn on 2021/6/8.
//

#ifndef QT_CMAKE_HELLOWORLD_LINE_H
#define QT_CMAKE_HELLOWORLD_LINE_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>


class Line :public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
Q_OBJECT
public:
    explicit Line(QWidget *parent);
    ~Line();

protected:
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL() ;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() ;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) ;
    void mousePressEvent(QMouseEvent *e) ;
    void mouseReleaseEvent(QMouseEvent *e) ;
private:
    QVector2D  mousePressPosition;
    QOpenGLShaderProgram _shaderProgram;
    GLuint _VAO;
    GLuint _VBO;

    void initShaders();

    void initTextures();
};


#endif //QT_CMAKE_HELLOWORLD_LINE_H
