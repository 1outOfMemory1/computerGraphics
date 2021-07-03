//
// Created by yhn on 6/21/2021.
//

#include "PolygonMine.h"

PolygonMine::PolygonMine(QWidget *parent) {
    width = parent->width();
    height = parent->height();
    linesVector = new vector<QPoint>;
}


PolygonMine::~PolygonMine() {

}

void PolygonMine::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(32/255.0,158/255.0,40/255.0, 1);

    initShaders();
    initTextures();

}


void PolygonMine::paintGL() {

//    if(diff.length() <10){
//        glDrawElements(GL_LINES, (linesVectorLength-1) * 2, GL_UNSIGNED_INT, 0);
//    }


    int linesVectorLength = linesVector->size();
    cout<<linesVectorLength<<endl;

    if(linesVectorLength <= 1){
        return;
    }
    QVector2D diff = QVector2D(linesVector->at(0)) - QVector2D(linesVector->at(linesVectorLength-1));

    //从LearnOpenGL移植过来
    int i = 0;

    double piece = (2*3.1415926)/30;
    float * vertices = new float[linesVectorLength * 3];



    for(int m=0;m<linesVectorLength;m++){
        float p1x =  linesVector->at(m).x()  / (this->width/2)  -1;
        float p1y =   linesVector->at(m).y()  / (this->height/2)  -1;

        vertices[3*m] =  p1x;
        vertices[3*m + 1] = -p1y;
        vertices[3*m + 2] = 0;
        cout<<p1x<<","<<p1y<<endl;
    }

    GLuint *indices = new GLuint[(linesVectorLength-1)*2];

    for(int m=0;m<linesVectorLength;m++){
        if(m < linesVectorLength -1){
            indices[2*m ] = m ;
            indices[2*m +1] = m+1;
        }else{
            indices[2*m ] = m ;
            indices[2*m +1] = 0;
        }
    }

    for(int k= 0;k<(linesVectorLength-1)*3;k++){
        cout<<indices[k]<<" ";
    }
    cout<<endl;




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
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* linesVectorLength *3 , vertices, GL_STATIC_DRAW);
    // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*2 *linesVectorLength, indices, GL_STATIC_DRAW);
    //3.设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    //不再对当前target使用任何缓存对象
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //4.解绑VAO
    glBindVertexArray(0);






    glClear(GL_COLOR_BUFFER_BIT);
    //填充颜色
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //**程序对象
    glBindVertexArray(VAO);
    //画图
    //glDrawArrays(GL_TRIANGLES, 0, 6);

    if(diff.length() > 30) {
        glDrawElements(GL_LINES, (linesVectorLength-1) * 2, GL_UNSIGNED_INT, 0);
    }else{
        GLuint *indices = new GLuint[linesVectorLength*3];

        for(int m=0;m<linesVectorLength;m++){
            if(m < linesVectorLength -1){
                indices[3*m ] = 0 ;
                indices[3*m +1] = m;
                indices[3*m +2] = m+1;
            }else{
                indices[3*m ] = 0 ;
                indices[3*m + 1] = m;
                indices[3*m +2] = 0;
            }
        }
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*3 *linesVectorLength, indices, GL_STATIC_DRAW);

        glDrawElements(GL_TRIANGLES, linesVectorLength, GL_UNSIGNED_INT, 0);
    }
    //用线框模式绘制
    glBindVertexArray(0);






}

void PolygonMine::resizeGL(int width, int height) {
    this->width = width;
    this->height  = height;
}


void PolygonMine::initShaders() {
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

void PolygonMine::initTextures() {

}





void PolygonMine::mouseReleaseEvent(QMouseEvent *e) {

    linesVector->push_back( e->pos());


//    paintGL();
    update();


}