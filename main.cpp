#include "mainwindow.h"
#include "animatedsplashscreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AnimatedSplashScreen splash(&w);
    splash.show();
    //w.show();
    return a.exec();
}
