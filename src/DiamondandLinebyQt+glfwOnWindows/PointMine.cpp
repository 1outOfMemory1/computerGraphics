//
// Created by yhn on 6/22/2021.
//

#include "PointMine.h"


PointMine::PointMine(QWidget *parent) {
    width = parent->width();
    height = parent->height();
    pointsVector = new vector<QPoint>;
}


PointMine::~PointMine() {

}


void PointMine::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(32/255.0,158/255.0,40/255.0, 1);

}

void PointMine::paintGL() {

    int pointVectorLength = pointsVector->size();
    cout<<pointVectorLength<<endl;



    //从LearnOpenGL移植过来
    int i = 0;

    float * vertices = new float[pointVectorLength *3 ];



    for(int m=0;m<pointVectorLength;m++){
        float p1x =  pointsVector->at(m).x()  / (this->width/2)  -1;
        float p1y =   pointsVector->at(m).y()  / (this->height/2)  -1;

        vertices[3*m] =  p1x;
        vertices[3*m + 1] = -p1y;
        vertices[3*m + 2] = 0;
        cout<<p1x<<","<<p1y<<endl;
    }

    GLuint *indices = new GLuint[pointVectorLength];

    for(int m=0;m<pointVectorLength;m++){
        indices[m] = m;
    }

    //创建顶点数组对象
    GLuint VAO,VBO,EBO;
    glGenVertexArrays(1, &VAO);
    // 索引缓冲对象
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    //1.绑定VAO
    glBindVertexArray(VAO);
    // 2. 把顶点数组复制到缓冲中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* pointVectorLength *3 , vertices, GL_STATIC_DRAW);
    // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) *pointVectorLength, indices, GL_STATIC_DRAW);
    //3.设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    //不再对当前target使用任何缓存对象
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //4.解绑VAO
    glBindVertexArray(0);


    glClear(GL_COLOR_BUFFER_BIT);
    //填充颜色
    glPointSize(2.0f);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //**程序对象
    glBindVertexArray(VAO);
    glDrawElements(GL_POINTS, pointVectorLength , GL_UNSIGNED_INT, 0);


}

void PointMine::resizeGL(int width, int height) {
    this->width = width;
    this->height  = height;
}


void PointMine::mouseReleaseEvent(QMouseEvent *e) {

    pointsVector->push_back( e->pos());


//    paintGL();
    update();


}
