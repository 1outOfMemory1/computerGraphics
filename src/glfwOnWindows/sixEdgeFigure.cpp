//
// Created by yhn on 6/21/2021.
//

#include<iostream>
#define GLEW_STATIC//静态链接库
#include<GL/glew.h>
#include<GLFW/glfw3.h>

const GLchar* vertexShaderSource = "#version 330 core\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                   "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
                                     "out vec4 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                     "}\n\0";
const GLchar* fragmentShaderSource2 = "#version 330 core\n"
                                      "out vec4 color;\n"
                                      "void main()\n"
                                      "{\n"
                                      "color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                      "}\n\0";
const GLuint WIDTH = 800, HEIGHT = 600;
//按键回调函数接受一个 GLFWwindow 指针作为它的第一个参数； 第二个整形参数用来表示事件的按键；
//第三个整形参数描述用户是否有第二个键按下或释放； 第四个整形参数表示事件类型， 如按下或释放；
//最后一个参数是表示是否有Ctrl、 Shift、 Alt、 Super等按钮的操作
void key_callback(GLFWwindow* window, int key, int seconds, int action, int mode)
{
    std::cout << key << std::endl;
    //检测了键盘是否按下了Escape键
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main()
{
    glfwInit();//初始化
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//opengl版本为3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //GLFW我们使用的是核心模式(Core-profile)
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);//不允许用户调整窗口的大小
    GLFWwindow* window = glfwCreateWindow(800, 800, "Learnopnegl", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "fail to create glfw window" << std::endl;
        glfwTerminate();//释放glfw分配的内存
        return -1;
    }
    //设为当前
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    //GLEW知道使用现代方法检索函数指针和扩展
    glewExperimental = GL_TRUE;
    //初始化OpenGL的函数指针的
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    //当创建了一个OpenGL上下文之后，需要从重新获取framebuffersize设置给glViewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    //前两个参数控制窗口左下角的位置
    glViewport(0, 0, width, height);

    //创建顶点着色器
    GLuint vertexShader=glCreateShader(GL_VERTEX_SHADER);
    //把着色器附加到着色器对象上
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        //获取错误信息
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX_SHADER"<<std::endl;
    }
    //创建片段着色器
    GLuint fragmentShader;
    fragmentShader =glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //创建着色器程序对象
    GLuint shaderProgram=glCreateProgram();
    //把之前的着色器加到对象上，并链接它们；
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS,&success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "error:shaderprogram failed" << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLfloat vertices[] = {
            0.0f, 0.0f, 0.0f,
            -0.9f, 0.0f, 0.0f,
            -0.45f, 0.45f, 0.0f,
            0.45f, 0.45f, 0.0f,
            0.9f, 0.0f, 0.0f,
            0.45f, -0.45f, 0.0f,
            -0.45f,-0.45f,0.0f
    };
    GLuint indices[] = {
            0, 1, 2,
            0, 2, 3,
            0, 3, 4,
            0, 4, 5,
            0, 5, 6,
            0, 6, 1
    };
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    //3.设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    //不再对当前target使用任何缓存对象
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //4.解绑VAO
    glBindVertexArray(0);


    //游戏循环
    while (!glfwWindowShouldClose(window))
    {
        //把所有事件系统都取过来：键盘/鼠标等操作
        glfwPollEvents();
        //清空颜色缓冲
        glClear(GL_COLOR_BUFFER_BIT);
        //填充颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //**程序对象
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        //画图
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
        //用线框模式绘制
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBindVertexArray(0);
        //交换两个缓冲区指针，调用双面进行画,显示一个,另一个在画,画面更流畅
        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
    return 0;
}

