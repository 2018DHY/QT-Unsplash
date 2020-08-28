#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QtWidgets>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <MyThread.h>
class MyWidget :public QWidget
{
    public:
    MyWidget();






    private:
    QLabel picture;
    QPushButton setpicture;
    MyThread *getpicture;




};

#endif // MYWIDGET_H
