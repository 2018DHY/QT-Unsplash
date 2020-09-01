#include "MyWidget.h"
MyWidget::MyWidget()
{
    osascript=("osascript -e \'tell application \"Finder\" to set desktop picture to POSIX file");
    picture.setGeometry(0,0,300,200);
    hasMouseTracking();
    setpicture.setText("设置壁纸");
    setpicture.setGeometry(100,90,100,20);
    setpicture.setStyleSheet("QPushButton{background-color:rgba(80,80,80,0);border-radius:10px;border-color:rgb(0,0,0);border:0px groove gray;border-style: outset;}""QPushButton:hover{background-color:rgb(19,75,211);}");
    setpicture.setParent(this);

    setpicture.show();
    connect(&setpicture,SIGNAL(clicked()),this,SLOT(OnButton()));




}
void MyWidget::initi(int _Pnum, QString _Folder)
{
    Pnum=_Pnum;
    Folder=_Folder;
    num=QString::number(Pnum,10);
    num.append(".jpg");
    file=(Folder+num);

}

void MyWidget::OnButton()
{
    osascript.append("\"").append(file).append("\"").append("\'");
    system(osascript.toLatin1());
}
