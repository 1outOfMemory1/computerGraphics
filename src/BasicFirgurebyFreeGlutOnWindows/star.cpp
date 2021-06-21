#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>

#define PI 3.1415926

GLenum errorCheck(){
    GLenum  code;
    const GLubyte* string;
    code = glGetError();
    if(code != GL_NO_ERROR){
        string = gluErrorString(code);
        fprintf(stderr , "OpenGL error:%s\n", string);
    }
    return code;
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,400.0);
}

void Five_Pointed_Star(void){
    glClear(GL_COLOR_BUFFER_BIT);

    double r = 200 ;

    double pointA[] = {r*(1-cos(18*PI/180)) ,r*(1+sin(18*PI/180))};
    double pointB[] = {200 ,400};
    double pointC[] = {r*(1+cos(18*PI/180)),r*(1+sin(18*PI/180))};
    double pointD[] = {r*(1+cos(54*PI/180)),r*(1-sin(54*PI/180))};
    double pointE[] = {r*(1-cos(54*PI/180)),r*(1-sin(54*PI/180))};


    glColor3f(0.0,0.4,0.2);
    glBegin(GL_LINE_LOOP);//GL_LINE_LOOP:给定点形成的封闭图形 GL_LINE_STRIP:直接连接点不一定封闭
    glVertex2dv(pointA);
    glVertex2dv(pointC);
    glVertex2dv(pointE);
    glVertex2dv(pointB);
    glVertex2dv(pointD);
    glEnd();

    glFlush();
}

int main(int argc ,char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(75,50);
    glutInitWindowSize(400,400);
    glutCreateWindow("An Example OpenGL Program");

    init();
    glutDisplayFunc(Five_Pointed_Star);
    glutMainLoop();
    return 0;
}

