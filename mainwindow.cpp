#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Scroll_Nature= new QScrollArea;
    Scroll_People= new QScrollArea;
    Scroll_Wallpaper= new QScrollArea;
    Scroll_Spirituality= new QScrollArea;
    Scroll_Nature->setParent(this);
    Scroll_Nature->setGeometry(35,0,1204,804);
    Scroll_People->setParent(this);
    Scroll_People->setGeometry(35,0,1204,804);
    Scroll_Wallpaper->setParent(this);
    Scroll_Wallpaper->setGeometry(35,0,1204,804);
    Scroll_Spirituality->setParent(this);
    Scroll_Spirituality->setGeometry(35,0,1204,804);
}

MainWindow::~MainWindow()
{
    delete ui;
}

