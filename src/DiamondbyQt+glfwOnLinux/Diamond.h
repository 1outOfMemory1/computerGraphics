//
// Created by yhn on 6/5/21.
//

#ifndef TEST_DIAMOND_H
#define TEST_DIAMOND_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>

class Diamond  :public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core{
Q_OBJECT
public:
    explicit Diamond(QWidget *parent,float scale,int pointNum);
    ~Diamond();

protected:
    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
    void initializeGL() ;
    //渲染OpenGL场景，每当需要更新小部件时使用
    void paintGL() ;
    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
    void resizeGL(int width, int height) ;

private:
    QOpenGLShaderProgram _shaderProgram;
    GLuint _VAO;
    GLuint _VBO;
    int total;
    float scale;
};


#endif //TEST_DIAMOND_H
