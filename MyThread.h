#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QString>
#include "MyWidget.h"
class MyThread :public QThread
{




   private:
    int number;//图片编号
    QString proxy;//代理设置
    QString picnum;//将int类转化为Qstring存储
    QString Folder;//文件夹位置
    QString cmd;//下载命令
    QString link;//下载地址
    QString site;//分类标签
    QString file;//记录文件位置
    MyWidget *loadpicture;//展示壁纸的窗口
    QPixmap pixmap;//加载图片
    QPixmap pix;//图片副本







   protected:

        void run();





   public:
        MyThread();
        void initi(int num,QString FilePath,QString _site);
        void getMyWiget(MyWidget *_MyWidget);







};
#endif // MYTHREAD_H
