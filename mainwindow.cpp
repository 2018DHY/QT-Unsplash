#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化分类
    site="";
    //初始化照片数
    Nature_sum=0;
    People_sum=0;
    Wallpaper_sum=0;
    Spirituality_sum=0;
    //滑动窗口初始化
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
    //初始化文件夹
    HomeFolder=QDir::homePath().append("/.config/unplash");
    Natrue_Folder=(HomeFolder+"/Nature/");
    People_Folder=(HomeFolder+"/People/");
    Wallpaper_Folder=(HomeFolder+"/Wallpaper/");
    Spirituality_Folder=(HomeFolder+"/Spirituality/");
    Folder.mkpath(Natrue_Folder);
    Folder.mkpath(People_Folder);
    Folder.mkpath(Wallpaper_Folder);


}

MainWindow::~MainWindow()
{
    delete ui;
}

