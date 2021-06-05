//#include "Diamond_dynamic.h"
//#define  PI 3.1415926535
//#include "math.h"
//#include "iostream"
//#include "QTimer"
//#include <GLFW/glfw3.h>
//Diamond_dynamic::Diamond_dynamic(QWidget *parent,float radius,int pointNum)
//        : QOpenGLWidget(parent)
//{
//    total = pointNum;
//}
//
//Diamond_dynamic::~Diamond_dynamic()
//{
//    glDeleteVertexArrays(1, &_VAO);
//    glDeleteBuffers(1, &_VBO);
//}
//
//void Diamond_dynamic::initializeGL()
//{
//
//
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
//    timer->start(10);
//    count = 0;
//
//
//    //为当前上下文初始化OpenGL函数解析
//    initializeOpenGLFunctions();
//
//    //着色器代码
//    //in输入，out输出,uniform从cpu向gpu发送
//    const char *vertexShaderSource ="#version 330 core\n"
//                                    "layout (location = 0) in vec3 aPos;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    "   gl_Position = vec4(aPos, 1.0);\n"
//                                    "}\0";
//
//    const char *fragmentShaderSource = "#version 330 core\n"
//                                       "out vec4 FragColor;\n"
//                                       "uniform vec4 ourColor;\n"
//                                       "void main()\n"
//                                       "{\n"
//                                       "   FragColor = ourColor;\n"
//                                       "}\n\0";
//
//    //将source编译为指定类型的着色器，并添加到此着色器程序
//    if(!_shaderProgram.addCacheableShaderFromSourceCode(
//            QOpenGLShader::Vertex,vertexShaderSource)){
//        qDebug()<<"compiler vertex error"<<_shaderProgram.log();
//    }
//    if(!_shaderProgram.addCacheableShaderFromSourceCode(
//            QOpenGLShader::Fragment,fragmentShaderSource)){
//        qDebug()<<"compiler fragment error"<<_shaderProgram.log();
//    }
//    //使用addShader()将添加到该程序的着色器链接在一起。
//    if(!_shaderProgram.link()){
//        qDebug()<<"link shaderprogram error"<<_shaderProgram.log();
//    }
//
//    //从LearnOpenGL移植过来
//    int i = 0;
//
//    float  *vertices = new float [3 * total ];
//    double piece = (2*PI)/total;
//
//    for(int m=0;m<total;m++){
//        vertices[3*m] = cos(piece * m);
//        vertices[3*m + 1] = sin(piece * m);
//        vertices[3*m + 2] = 0;
//    }
//
//    unsigned int *indices = new unsigned int[2 * total * total];
//    for(int n=0;n<total;n++){
//        for(int k=0;k<total;k++){
//            indices[2*(n+k*total)] = k;
//            indices[2*(n + k*total) + 1] = n;
//        }
//    }
//
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float) * total, vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * sizeof(unsigned  int)* total *total, indices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
//    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    glBindVertexArray(0);
//
//
//
//
//    // bind the VAO (it was already bound, but just to demonstrate): seeing as we only have a single VAO we can
//    // just bind it beforehand before rendering the respective triangle; this is another approach.
//    glBindVertexArray(VAO);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//}
//
//void Diamond_dynamic::paintGL()
//{
//    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // be sure to activate the shader before any calls to glUniform
//    _shaderProgram.bind();
//
//    // update shader uniform
//
//
//    count = count + 0.01;
//    float timeValue =count;
//    //printf("%f\n",timeValue);
//    float greenValue = sin(timeValue) / 2.0f + 0.5f;
//    float redValue = cos(timeValue) / 2.0f + 0.5f;
//    float blueValue =( sin(timeValue) + cos(timeValue) )/ 2.0f + 0.5f;
//
//
//    _shaderProgram.setUniformValue("ourColor", QVector4D(redValue, greenValue, blueValue, 1.0f));
//
//
//    glBindVertexArray(_VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//    glDrawElements(GL_LINES,total*2*total, GL_UNSIGNED_INT, 0);
//
//    _shaderProgram.release();
//}
//
//void Diamond_dynamic::resizeGL(int width, int height)
//{
//    glViewport(0,0,width,height);
//}
//
//
//
//
//
