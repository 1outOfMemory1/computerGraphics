#include <GL/freeglut.h>
#include <cmath>

using namespace  std;

int height = 512;
int width = 512;
// k>1 (0, 0) (265, 300)
// 0<=k<=1 (0, 0) (512, 512)
// -1<=k<0 (256, 0) (0, 256)
// k<-1 (256, 0) (0, 300)
// 起点
double xx1 = 300;
double yy1 = 300;
// 终点
double xx2 = 100;
double yy2 = 300;

void drawPoint(double x, double y) {
    glColor3f(0, 1, 0);
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

double transformX(double x) {
    double ww = width / 2.0;
    return x / ww - 1.0;
}

double transformY(double y) {
    double hh = height / 2.0;
    if (y >= hh) {
        return -(y / hh - 1.0);
    } else {
        return 1.0 - y / hh;
    }
}

// Bresenham算法
void bresenham() {
    // k为无穷
    if (xx1 == xx2) {
        double start, end;
        if (yy1 >= yy2) {
            start = yy2;
            end = yy1;
        } else {
            start = yy1;
            end = yy2;
        }
        for (int i = lround(start); i <= lround(end); i++) {
            drawPoint(transformX(xx1), transformY(i));
        }
    } else {
        double k = (yy2 - yy1) / (xx2 - xx1);
        // 根据斜率分情况讨论
        // 当k > 1时
        if (k > 1) {
            double x_s, y_s, y_e;
            if (yy1 >= yy2) {
                y_s = yy2;
                y_e = yy1;
                x_s = xx2;
            } else {
                y_s = yy1;
                y_e = yy2;
                x_s = xx1;
            }
            double d = 1 - 0.5 * k;
            double x = x_s;
            for (int i = lround(y_s); i <= lround(y_e); i++) {
                drawPoint(transformX(x), transformY(i));
                if (d >= 0) {
                    d = d + 1 -k;
                    x = x + 1;
                } else {
                    d = d + 1;
                }
            }
        } else if (k >= 0 && k <= 1) { // 0<=k<=1
            double d = 0.5 - k;
            double x_s, x_e, y_s;
            if (xx1 >= xx2) {
                x_s = xx2;
                x_e = xx1;
                y_s = yy2;
            } else {
                x_s = xx1;
                x_e = xx2;
                y_s = yy1;
            }
            double y = y_s;
            for (int i = lround(x_s); i <= lround(x_e); i++) {
                drawPoint(transformX(i), transformY(y));
                if (d >= 0) {
                    d = d -k;
                } else {
                    d = d + 1 - k;
                    y = y + 1;
                }
            }
        } else if (k >= -1 && k < 0) { // -1<=k<0
            double d = -0.5 - k;
            double x_s, x_e, y_s;
            if (xx1 >= xx2) {
                x_s = xx2;
                x_e = xx1;
                y_s = yy2;
            } else {
                x_s = xx1;
                x_e = xx2;
                y_s = yy1;
            }
            double y = y_s;
            for (int i = lround(x_s); i <= lround(x_e); i++) {
                drawPoint(transformX(i), transformY(y));
                if (d <= 0) {
                    d = d - k;
                } else {
                    y = y - 1;
                    d = d - 1 - k;
                }
            }
        } else if (k < -1) { // k<-1
            double d = -1 - 0.5 * k;
            double x_s, y_s, y_e;
            if (yy1 >= yy2) {
                y_s = yy2;
                y_e = yy1;
                x_s = xx2;
            } else {
                y_s = yy1;
                y_e = yy2;
                x_s = xx1;
            }
            double x = x_s;
            for (int i = lround(y_s); i <= lround(y_e); i++) {
                drawPoint(transformX(x), transformY(i));
                if (d >= 0) {
                    d = d - 1;
                } else {
                    d = d - 1 -k;
                    x = x - 1;
                }
            }
        }
    }
    glFlush();
}

void display() {
    // 清空缓存
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Bresenham算法画直线
    bresenham();
    // 绘制直线的端点
    glColor3f(1, 0, 0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(transformX(xx1), transformY(yy1));
    glVertex2f(transformX(xx2), transformY(yy2));
    glEnd();
    glFlush();
}

void reshape(int w, int h) {
    width = w;
    height = h;
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow("Line");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}