#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QtWidgets>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QtDebug>
class MyWidget :public QWidget
{


    Q_OBJECT
    public:
    QLabel picture;//显示图片的小部件
    MyWidget();
    void initi(int _Pnum,QString _Folder);
    QPushButton setpicture;//设置图片的按钮

private slots:
    void OnButton();


    private:
    int Pnum;
    QString Folder;//图片文件夹
    QString num;//图片编号转化为文字
    QString file;//图片文件位置
    QString osascript;//用于设置桌面背景的命令







};

#endif // MYWIDGET_H
