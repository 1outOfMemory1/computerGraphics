#include <QMessageBox>
#include <QInputDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTimer"
#include "iostream"
#include "QPushButton"
#include "QLabel"
#include "Diamond.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->d = nullptr;
    parentWindow = this;
    ui->setupUi(this);
    menubar = menuBar();
    QMenu *file = menubar->addMenu("文件");
    QAction *exit  = file->addAction("退出");
    QMenu *draw = menubar->addMenu("绘图");
    QAction *diamond  = draw->addAction("绘制金刚石");
    QAction *line  = draw->addAction("绘制任意斜率的线段");
    QMenu *help = menubar->addMenu("帮助");
    QAction *about  = help->addAction("关于");

    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    connect(diamond, SIGNAL(triggered())  ,this, SLOT(drawDiamond()));

    connect(about, SIGNAL(triggered()), this, SLOT(showAbout()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(resizeOpenGLWindow()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::resizeOpenGLWindow() {
    windowsHeight = parentWindow->height();
    windowsWidth = parentWindow->width();
//    std::cout<<windowsHeight<<std::endl;
//    std::cout<<windowsWidth<<std::endl;
    if(d != nullptr)
        d->resize(windowsWidth,windowsHeight-menubarHeight);
}

void MainWindow::drawDiamond() {

    QDialog dialog(this);
    dialog.setWindowTitle("绘制金刚石");
    QFormLayout form(&dialog);
    form.addRow(new QLabel("请输入圆半径(0-1)和等分点个数"));
    // Value1
    QString value1 = QString("圆半径: ");
    QLineEdit *spinbox1 = new QLineEdit(&dialog);
    form.addRow(value1, spinbox1);




    // Value2
    QString value2 = QString("等分点个数: ");
    QLineEdit *spinbox2 = new QLineEdit(&dialog);
    form.addRow(value2, spinbox2);
    // Add Cancel and OK button
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));






    // Process when OK button is clicked
    if (dialog.exec() == QDialog::Accepted) {

        std::cout<<spinbox1->text().toStdString()<<std::endl;
        std::cout<<spinbox2->text().toStdString()<<std::endl;

        float  radius = atof(spinbox1->text().toStdString().c_str());
        int  total = atoi(spinbox2->text().toStdString().c_str());

        d = new Diamond(nullptr,radius,total);
        d->setParent(this);
        menubarHeight =  menubar->height();
        windowsHeight = parentWindow->height();
        windowsWidth = parentWindow->width();
        d->move(0,menubarHeight);
        d->show();
    }


}

void MainWindow::showAbout(){
    QMessageBox *qm = new  QMessageBox();
    qm->setWindowTitle("关于");
    qm->setText("本程序基于qt与glfw开发,开发者尹浩男") ;
    qm->show();
}

