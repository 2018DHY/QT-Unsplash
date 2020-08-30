#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QDir>
#include <QString>
#include "MyWidget.h"
#include "MyThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_Nature_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    //线程量
    MyThread thread[10];
    //小窗口缓存量
    MyWidget *Nature_PICTURE[200];
    MyWidget *People_PICTURE[200];
    MyWidget *Wallpaper_PICTURE[200];
    MyWidget *Spirituality_PICTURE[200];
    //照片分类
    QString site;
    //四大分类滑动窗口
    QScrollArea *Scroll_Nature;
    QScrollArea *Scroll_People;
    QScrollArea *Scroll_Wallpaper;
    QScrollArea *Scroll_Spirituality;
    //主文件夹
    QDir Folder;
    QString HomeFolder;
    QString Natrue_Folder;
    QString People_Folder;
    QString Wallpaper_Folder;
    QString Spirituality_Folder;
    //照片数量-1变量
    int Nature_sum;
    int People_sum;
    int Wallpaper_sum;
    int Spirituality_sum;
    //布局行与列
    int Nature_row;
    int Nature_colum;
};
#endif // MAINWINDOW_H
