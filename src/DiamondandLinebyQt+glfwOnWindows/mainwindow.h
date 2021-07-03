#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Diamond_dynamic.h"
#include "Diamond.h"
#include "PolygonMine.h"
#include "Line.h"
#include "PointMine.h"
#include "ColorCube.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMenuBar * menubar;
    MainWindow * parentWindow;
    int menubarHeight;
    int windowsHeight;
    int windowsWidth;
//    Diamond_dynamic *dd;
    Diamond *d;
    Line *l;
    PolygonMine *p;
    PointMine *poin;
    ColorCube * cc;
private slots:
    void resizeOpenGLWindow();
    void drawDiamond();
    void showAbout();


    void drawLines();
    void drawPolygon();
    void drawPoint();
    void drawColorCube();
};
#endif // MAINWINDOW_H
