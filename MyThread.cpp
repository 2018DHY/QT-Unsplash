#include "MyThread.h"





MyThread::MyThread()
{

}
void  MyThread::getMyWiget(MyWidget *_MyWidget)
{
    loadpicture=_MyWidget;
}
void MyThread::initi(int num, QString FilePath, QString _site)
{
    number=num;//线程编号同时也是照片编号
    Folder=FilePath;
    site=_site;
    link="https://source.unsplash.com/random/3840x2160/?";
    link.append(site);
    proxy=("export http_proxy=http://127.0.0.1:1087;export https_proxy=http://127.0.0.1:1087;");
    picnum=QString::number(number,10);
    file=(Folder+picnum);
    file.append(".jpg");
    cmd=(proxy+"wget "+link+" --output-document="+file);
}

void MyThread::run()
{
    system(proxy.toLatin1()+cmd.toLatin1());
    pixmap.load(file);
    pix=pixmap.scaled(300,200);
    loadpicture->picture.setGeometry(0,0,300,200);
    loadpicture->picture.setPixmap(pix);
    loadpicture->picture.setParent(loadpicture);
    loadpicture->picture.show();
}
