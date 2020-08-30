#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QString>
#include "MyWidget.h"
class MyThread :public QThread
{




   private:
    int number;
    QString proxy;
    QString picnum;
    QString Folder;
    QString cmd;
    QString link;
    QString site;
    QString file;
    MyWidget *loadpicture;
    QPixmap pixmap;
    QPixmap pix;







   protected:

        void run();





   public:
        MyThread();
        void initi(int num,QString FilePath,QString _site);
        void getMyWiget(MyWidget *_MyWidget);







};
#endif // MYTHREAD_H
