#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QScrollArea *Scroll_Nature;
    QScrollArea *Scroll_People;
    QScrollArea *Scroll_Wallpaper;
    QScrollArea *Scroll_Spirituality;
};
#endif // MAINWINDOW_H
