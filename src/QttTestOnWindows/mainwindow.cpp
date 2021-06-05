#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar * menubar = menuBar();
    QMenu *file = menubar->addMenu("文件");
    QAction *exit  = file->addAction("退出");
    QMenu *draw = menubar->addMenu("绘图");
    QAction *diamond  = draw->addAction("绘制金刚石");
    QAction *line  = draw->addAction("绘制任意斜率的线段");
    QMenu *help = menubar->addMenu("帮助");
    QAction *about  = help->addAction("关于");
}

MainWindow::~MainWindow()
{
    delete ui;
}

