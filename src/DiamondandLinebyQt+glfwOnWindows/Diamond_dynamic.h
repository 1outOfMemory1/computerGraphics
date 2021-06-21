//
//#ifndef GLTRIANGLE_H
//#define GLTRIANGLE_H
//
//#include <QOpenGLWidget>
//#include <QOpenGLFunctions_3_3_Core>
//#include <QOpenGLShaderProgram>
//
////绘制三角形
//class Diamond_dynamic : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
//{
//Q_OBJECT
//public:
//    explicit Diamond_dynamic(QWidget *parent,float radius,int pointNum);
//    ~Diamond_dynamic();
//
//protected:
//    //设置OpenGL资源和状态。在第一次调用resizeGL或paintGL之前被调用一次
//    void initializeGL() override;
//    //渲染OpenGL场景，每当需要更新小部件时使用
//    //设置OpenGL视口、投影等，每当尺寸大小改变时调用
//    void resizeGL(int width, int height) override;
//
//    void paintGL() override;
//
//
//private:
//    QOpenGLShaderProgram _shaderProgram;
//    GLuint _VAO;
//    GLuint _VBO;
//    int total = 0;
//    float count;
//};
//
//#endif // GLTRIANGLE_H
//
