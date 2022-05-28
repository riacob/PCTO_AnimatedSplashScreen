#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animatedsplashscreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    AnimatedSplashScreen* splash = new AnimatedSplashScreen();
    splash->show();
}

