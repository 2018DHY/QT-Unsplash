#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QDir>
#include <QString>
#include "MyWidget.h"
#include "MyThread.h"
#include <QScrollBar>

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
    void Nature_bar();
    void People_bar();
    void Wallpaper_bar();
    void Spirituality_bar();
    void on_Nature_toggled(bool checked);


    void on_People_toggled(bool checked);

    void on_Wallpaper_toggled(bool checked);

    void on_Spirituality_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    //线程量
    int thread_num;
    MyThread thread[16];
    //小窗口缓存量
    MyWidget *Nature_PICTURE[200];
    MyWidget *People_PICTURE[200];
    MyWidget *Wallpaper_PICTURE[200];
    MyWidget *Spirituality_PICTURE[200];
    //照片分类
    QString site;
    //四大分类滑动窗口以及内容窗口
    QScrollArea *Scroll_Nature;
    QScrollArea *Scroll_People;
    QScrollArea *Scroll_Wallpaper;
    QScrollArea *Scroll_Spirituality;
    QWidget scrollAreaWidgetContents_Nature;
    QWidget scrollAreaWidgetContents_People;
    QWidget scrollAreaWidgetContents_Wallpaper;
    QWidget scrollAreaWidgetContents_Spirituality;
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
    int People_row;
    int People_colum;
    int Wallpaper_row;
    int Wallpaper_colum;
    int Spirituality_row;
    int Spirituality_colum;
    //滑动条
    QScrollBar *Scroll_Nature_bar;
    QScrollBar *Scroll_People_bar;
    QScrollBar *Scroll_Wallpaper_bar;
    QScrollBar *Scroll_Spirituality_bar;
    //瀑布流变量以及滑动窗口内容窗口高度变量；
    int Nature_falls;
    int People_falls;
    int Wallpaper_falls;
    int Spirituality_falls;
    int scrollAreaWidgetContents_Nature_H;
    int scrollAreaWidgetContents_People_H;
    int scrollAreaWidgetContents_Wallpaper_H;
    int scrollAreaWidgetContents_Spirituality_H;




















};
#endif // MAINWINDOW_H
