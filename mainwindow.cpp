#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->setVisible(false);

    // 初始化缓存量
     for(int i=0;i<200;i++)
     {
         Nature_PICTURE[i]=new MyWidget;
         People_PICTURE[i]=new MyWidget;
         Wallpaper_PICTURE[i]=new MyWidget;
         Spirituality_PICTURE[i]=new MyWidget;
     }

    //初始化分类以及线程池
    thread_num=0;
    site="";
    //初始化照片数以及滑动窗口内容窗口高度和瀑布流变量
    Nature_sum=0;
    People_sum=0;
    Wallpaper_sum=0;
    Spirituality_sum=0;
    Nature_falls=0;
    People_falls=0;
    Wallpaper_falls=0;
    Spirituality_falls=0;
    scrollAreaWidgetContents_Nature_H=804;
    scrollAreaWidgetContents_People_H=804;
    scrollAreaWidgetContents_Wallpaper_H=804;
    scrollAreaWidgetContents_Spirituality_H=804;

    //滑动窗口初始化以及内容窗口和滑动条
    Scroll_Nature= new QScrollArea;
    Scroll_People= new QScrollArea;
    Scroll_Wallpaper= new QScrollArea;
    Scroll_Spirituality= new QScrollArea;
    Scroll_Nature_bar=Scroll_Nature->verticalScrollBar();
    Scroll_People_bar=Scroll_People->verticalScrollBar();
    Scroll_Wallpaper_bar=Scroll_Wallpaper->verticalScrollBar();
    Scroll_Spirituality_bar=Scroll_Spirituality->verticalScrollBar();

    Scroll_Nature->setParent(this);
    Scroll_Nature->setGeometry(35,0,1204,804);
    Scroll_Nature->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents_Nature.setParent(Scroll_Nature);
    scrollAreaWidgetContents_Nature.setGeometry(0,0,1204,805);
    Scroll_Nature->setWidget(&scrollAreaWidgetContents_Nature);

    Scroll_People->setParent(this);
    Scroll_People->setGeometry(35,0,1204,804);
    Scroll_People->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents_People.setParent(Scroll_People);
    scrollAreaWidgetContents_People.setGeometry(0,0,1204,805);
    Scroll_People->setWidget(&scrollAreaWidgetContents_People);

    Scroll_Wallpaper->setParent(this);
    Scroll_Wallpaper->setGeometry(35,0,1204,804);
    Scroll_Wallpaper->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents_Wallpaper.setParent(Scroll_Wallpaper);
    scrollAreaWidgetContents_Wallpaper.setGeometry(0,0,1204,805);
    Scroll_Wallpaper->setWidget(&scrollAreaWidgetContents_Wallpaper);

    Scroll_Spirituality->setParent(this);
    Scroll_Spirituality->setGeometry(35,0,1204,804);
    Scroll_Spirituality->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents_Spirituality.setParent(Scroll_Spirituality);
    scrollAreaWidgetContents_Spirituality.setGeometry(0,0,1204,805);
    Scroll_Spirituality->setWidget(&scrollAreaWidgetContents_Spirituality);

    Scroll_Wallpaper->hide();
    Scroll_Spirituality->hide();
    Scroll_Nature->hide();
    Scroll_People->hide();
    //初始化文件夹
    HomeFolder=QDir::homePath().append("/.config/unplash");
    Natrue_Folder=(HomeFolder+"/Nature/");
    People_Folder=(HomeFolder+"/People/");
    Wallpaper_Folder=(HomeFolder+"/Wallpaper/");
    Spirituality_Folder=(HomeFolder+"/Spirituality/");
    Folder.mkpath(Natrue_Folder);
    Folder.mkpath(People_Folder);
    Folder.mkpath(Wallpaper_Folder);
    Folder.mkpath(Spirituality_Folder);
    //连接信号
    connect(Scroll_Spirituality_bar,SIGNAL(valueChanged(int)),this,SLOT(Spirituality_bar()));
    connect(Scroll_Wallpaper_bar,SIGNAL(valueChanged(int)),this,SLOT(Wallpaper_bar()));
    connect(Scroll_People_bar,SIGNAL(valueChanged(int)),this,SLOT(People_bar()));
    connect(Scroll_Nature_bar,SIGNAL(valueChanged(int)),this,SLOT(Nature_bar()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Nature_toggled(bool checked)
{
    if(checked)
    {
        site="Nature";
        Scroll_People->hide();
        Scroll_Wallpaper->hide();
        Scroll_Spirituality->hide();
        Scroll_Nature->show();
        if(Nature_sum==0)
        {
            for(int i=0;i<4;i++)
            {
                Nature_row=Nature_sum/4;
                Nature_colum=Nature_sum%4;
                Nature_PICTURE[i]->setParent(&scrollAreaWidgetContents_Nature);
                Nature_PICTURE[i]->initi(Nature_sum,Natrue_Folder);
                Nature_PICTURE[i]->setStyleSheet("background-color:rgb(80,80,80)");
                Nature_PICTURE[i]->setGeometry(301*Nature_colum,201*Nature_row,300,200);
                Nature_PICTURE[i]->show();
                thread[thread_num].initi(Nature_sum,Natrue_Folder,site);
                thread[thread_num].getMyWiget(Nature_PICTURE[i]);//注意变量
                //thread[thread_num].moveToThread(&thread[i]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                Nature_sum++;
            }
        }
    }
}

void MainWindow::on_People_toggled(bool checked)
{
    if(checked)
    {
        site="People";
        Scroll_Wallpaper->hide();
        Scroll_Spirituality->hide();
        Scroll_Nature->hide();
        Scroll_People->show();
        if(People_sum==0)
        {
            for(int i=0;i<4;i++)
            {
                People_row=People_sum/4;
                People_colum=People_sum%4;
                People_PICTURE[i]->setParent(&scrollAreaWidgetContents_People);
                People_PICTURE[i]->initi(People_sum,People_Folder);
                People_PICTURE[i]->setStyleSheet("background-color:rgb(80,80,80)");
                People_PICTURE[i]->setGeometry(301*People_colum,201*People_row,300,200);
                People_PICTURE[i]->show();
                thread[thread_num].initi(People_sum,People_Folder,site);
                thread[thread_num].getMyWiget(People_PICTURE[i]);//注意变量
                //thread[i].moveToThread(&thread[i]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                People_sum++;
            }
        }
    }
}

void MainWindow::on_Wallpaper_toggled(bool checked)
{
    if(checked)
    {
        site="Wallpaper";
        Scroll_Spirituality->hide();
        Scroll_Nature->hide();
        Scroll_People->hide();
        Scroll_Wallpaper->show();
        if(Wallpaper_sum==0)
        {
            for(int i=0;i<4;i++)
            {
                Wallpaper_row=Wallpaper_sum/4;
                Wallpaper_colum=Wallpaper_sum%4;
                Wallpaper_PICTURE[i]->setParent(&scrollAreaWidgetContents_Wallpaper);
                Wallpaper_PICTURE[i]->initi(Wallpaper_sum,Wallpaper_Folder);
                Wallpaper_PICTURE[i]->setStyleSheet("background-color:rgb(80,80,80)");
                Wallpaper_PICTURE[i]->setGeometry(301*Wallpaper_colum,201*Wallpaper_row,300,200);
                Wallpaper_PICTURE[i]->show();
                thread[thread_num].initi(Wallpaper_sum,Wallpaper_Folder,site);
                thread[thread_num].getMyWiget(Wallpaper_PICTURE[i]);//注意变量
                //thread[i].moveToThread(&thread[i]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                Wallpaper_sum++;
            }
        }
    }
}

void MainWindow::on_Spirituality_toggled(bool checked)
{
    if(checked)
    {
        site="Spirituality";
        Scroll_Nature->hide();
        Scroll_People->hide();
        Scroll_Wallpaper->hide();
        Scroll_Spirituality->show();
        if(Spirituality_sum==0)
        {
            for(int i=0;i<4;i++)
            {
                Spirituality_row=Spirituality_sum/4;
                Spirituality_colum=Spirituality_sum%4;
                Spirituality_PICTURE[i]->setParent(&scrollAreaWidgetContents_Spirituality);
                Spirituality_PICTURE[i]->initi(Spirituality_sum,Spirituality_Folder);
                Spirituality_PICTURE[i]->setStyleSheet("background-color:rgb(80,80,80)");
                Spirituality_PICTURE[i]->setGeometry(301*Spirituality_colum,201*Spirituality_row,300,200);
                Spirituality_PICTURE[i]->show();
                thread[thread_num].initi(Spirituality_sum,Spirituality_Folder,site);
                thread[thread_num].getMyWiget(Spirituality_PICTURE[i]);//注意变量
                //thread[i].moveToThread(&thread[i]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                Spirituality_sum++;
            }
        }
    }
}

void MainWindow::Nature_bar()
{
    if(Scroll_Nature_bar->value()>=Nature_falls)
    {
        if(Nature_sum<200)
        {
            scrollAreaWidgetContents_Nature_H+=201;
            Nature_falls+=201;
            scrollAreaWidgetContents_Nature.resize(1204,scrollAreaWidgetContents_Nature_H);
            for(int i=0;i<4;i++)
            {
                Nature_row=Nature_sum/4;
                Nature_colum=Nature_sum%4;
                Nature_PICTURE[Nature_sum]->setParent(&scrollAreaWidgetContents_Nature);
                Nature_PICTURE[Nature_sum]->setGeometry(301*Nature_colum,201*Nature_row,300,200);
                Nature_PICTURE[Nature_sum]->show();
                thread[thread_num].initi(Nature_sum,Natrue_Folder,site);
                thread[thread_num].getMyWiget(Nature_PICTURE[Nature_sum]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                Nature_sum++;
            }
        }
    }
}

void MainWindow::People_bar()
{
    if(Scroll_People_bar->value()>=People_falls)
    {
        if(People_sum<200)
        {
            scrollAreaWidgetContents_People_H+=201;
            People_falls+=201;
            scrollAreaWidgetContents_People.resize(1204,scrollAreaWidgetContents_People_H);
            for(int i=0;i<4;i++)
            {
                People_row=People_sum/4;
                People_colum=People_sum%4;
                People_PICTURE[People_sum]->setParent(&scrollAreaWidgetContents_People);
                People_PICTURE[People_sum]->setGeometry(301*People_colum,201*People_row,300,200);
                People_PICTURE[People_sum]->show();
                thread[thread_num].initi(People_sum,People_Folder,site);
                thread[thread_num].getMyWiget(People_PICTURE[People_sum]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                People_sum++;
            }
        }
    }

}

void MainWindow::Wallpaper_bar()
{
    if(Scroll_Wallpaper_bar->value()>=Wallpaper_falls)
    {
        if(Wallpaper_sum<200)
        {
            scrollAreaWidgetContents_Wallpaper_H+=201;
            Wallpaper_falls+=201;
            scrollAreaWidgetContents_Wallpaper.resize(1204,scrollAreaWidgetContents_Wallpaper_H);
            for(int i=0;i<4;i++)
            {
                Wallpaper_row=Wallpaper_sum/4;
                Wallpaper_colum=Wallpaper_sum%4;
                Wallpaper_PICTURE[Wallpaper_sum]->setParent(&scrollAreaWidgetContents_Wallpaper);
                Wallpaper_PICTURE[Wallpaper_sum]->setGeometry(301*Wallpaper_colum,201*Wallpaper_row,300,200);
                Wallpaper_PICTURE[Wallpaper_sum]->show();
                thread[thread_num].initi(Wallpaper_sum,Wallpaper_Folder,site);
                thread[thread_num].getMyWiget(Wallpaper_PICTURE[Wallpaper_sum]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                Wallpaper_sum++;
            }
        }
    }
}

void MainWindow::Spirituality_bar()
{
    if(Scroll_Spirituality_bar->value()>=Spirituality_falls)
    {
        if(Spirituality_sum<200)
        {
            scrollAreaWidgetContents_Spirituality_H+=201;
            Spirituality_falls+=201;
            scrollAreaWidgetContents_Spirituality.resize(1204,scrollAreaWidgetContents_Spirituality_H);
            for(int i=0;i<4;i++)
            {
                Spirituality_row=Spirituality_sum/4;
                Spirituality_colum=Spirituality_sum%4;
                Spirituality_PICTURE[Spirituality_sum]->setParent(&scrollAreaWidgetContents_Spirituality);
                Spirituality_PICTURE[Spirituality_sum]->setGeometry(301*Spirituality_colum,201*Spirituality_row,300,200);
                Spirituality_PICTURE[Spirituality_sum]->show();
                thread[thread_num].initi(Spirituality_sum,Spirituality_Folder,site);
                thread[thread_num].getMyWiget(Spirituality_PICTURE[Spirituality_sum]);
                //thread[thread_num].start();
                thread_num=(thread_num+1)%16;
                Spirituality_sum++;
            }
        }
    }
}


















