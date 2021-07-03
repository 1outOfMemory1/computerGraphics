//
// Created by yhn on 7/2/2021.
//

#include "ColorCube.h"

ColorCube::ColorCube(QWidget *parent) {
    width = parent->width();
    height = parent->height();
}

ColorCube::~ColorCube() {

}

void ColorCube::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(32/255.0,158/255.0,40/255.0, 1);

    initShaders();
    initTextures();
}

void ColorCube::paintGL() {

    int width, height, nrChannels;
//    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    width = 100;
    height = 100;
    unsigned char *data = new unsigned char [width* height*3];

    for(int i= 0;i< height ;i++){
        for(int j = 0;j<width;j++){
            data[i*3*width +j * 3] = int(((float)i / height)* 255) ;
            data[i*3*width +j * 3 +1] = 255 - int(((float)i / height)* 255) ;
            data[i*3*width +j * 3 +2] =0 ;
        }
    }
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
    // activate shader
    //ourShader.use();
    glUseProgram(_shaderProgram.programId());
    // create transformations
    glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);
    model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)this->width / (float)this->height, 0.1f, 100.0f);
    // retrieve the matrix uniform locations
    unsigned int modelLoc = glGetUniformLocation(_shaderProgram.programId(), "model");
    unsigned int viewLoc  = glGetUniformLocation(_shaderProgram.programId(), "view");
    // pass them to the shaders (3 different ways)
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    //ourShader.setMat4("projection", projection);
    glUniform4fv(glGetUniformLocation(_shaderProgram.programId(), "projection"), 1,
                 reinterpret_cast<const GLfloat *>(&projection[0]));

    // render box
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);



}

void ColorCube::resizeGL(int width, int height) {
    this->width = width;;
    this->height = height;;
}

void ColorCube::initShaders() {
    //着色器代码
    //in输入，out输出,uniform从cpu向gpu发送
    const char *vertex_str=R"(#version 330 core
                           layout (location = 0) in vec3 aPos;
                           layout (location = 1) in vec2 aTexCoord;
                           out vec2 TexCoord;
                           uniform mat4 model;
                            uniform mat4 view;
                            uniform mat4 projection;
                            void main()
                            {
                                gl_Position = projection * view * model * vec4(aPos, 1.0);
                                TexCoord = vec2(aTexCoord.x, aTexCoord.y);
                            }
                            }
                           })";
    const char *fragment_str=R"(#version 330 core
                           in vec2 TexCoord;
                           uniform sampler2D texture1;
                           uniform sampler2D texture2;
                            uniform vec4 abc;
                            void main()
                            {
                                // linearly interpolate between both textures (80% container, 20% awesomeface)
                                FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
                            // 	FragColor = vec4(0,0,1.0,1.0);
                            }
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

void ColorCube::initTextures() {
    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    unsigned int _VBO, _VAO;
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // load and create a texture
    // -------------------------
    unsigned int texture1, texture2;
    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
}
