#include "mainwindow.h"
#include "animatedsplashscreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Creiamo un oggetto di classe AnimatedSplashScreen
    AnimatedSplashScreen splash(&w);
    // Impostiamo le dimensioni dello schermo (default: 1920x1080 pixel)
    splash.setScreenSize(1920, 1080);
    // Mostriamo lo splash screen, che, al termine della sua esecuzione, mostrerà la QMainWindow
    splash.show();

    return a.exec();
}
