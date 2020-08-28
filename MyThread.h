#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QString>
#include <QtWidgets>
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
    QWidget *loadpicture;
    QPixmap pixmap;
    QPixmap pix;







   protected:

        void run();





   public:
        MyThread(int num,QString FilePath,QString _site);
        void getMyWiget(QWidget *_MyWidget);







};
#endif // MYTHREAD_H
