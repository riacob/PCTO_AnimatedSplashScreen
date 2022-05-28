#ifndef ANIMATEDSPLASHSCREEN_H
#define ANIMATEDSPLASHSCREEN_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMainWindow>

namespace Ui {
class AnimatedSplashScreen;
}

class AnimatedSplashScreen : public QWidget
{
    Q_OBJECT

public:
    explicit AnimatedSplashScreen(QMainWindow* mw = nullptr, QWidget *parent = nullptr);
    ~AnimatedSplashScreen();

private:
    Ui::AnimatedSplashScreen *ui;
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
    QMainWindow* mainWindow;

private slots:
    void closeWindow();
};

#endif // ANIMATEDSPLASHSCREEN_H
