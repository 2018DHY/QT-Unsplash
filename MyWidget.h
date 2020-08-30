#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QtWidgets>
#include <QPushButton>
#include <QLabel>
#include <QString>
class MyWidget :public QWidget
{
    public:
    QLabel picture;
    MyWidget();






    private:

    QPushButton setpicture;

    signals:
    void download();



};

#endif // MYWIDGET_H
