#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Diamond_dynamic.h"
#include "Diamond.h"
#include "Line.h"

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
private slots:
    void resizeOpenGLWindow();
    void drawDiamond();
    void showAbout();

    void drawLines();

};
#endif // MAINWINDOW_H
