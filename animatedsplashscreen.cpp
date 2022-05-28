#include "animatedsplashscreen.h"
#include "ui_animatedsplashscreen.h"

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QDebug>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define VIDEO_PATH "qrc:/splash.mp4"

AnimatedSplashScreen::AnimatedSplashScreen(QMainWindow* mw, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimatedSplashScreen)
{
    ui->setupUi(this);

    // Salviamo il puntatore alla QMainWindow
    mainWindow = mw;

    // Settiamo le flag della finestra affinchè venga mostrata nella maniera desiderata (senza bordi e in popup)
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Popup);

    // Centriamo la finestra con il QMediaPlayer
    this->move(((SCREEN_WIDTH/2) - (this->width() / 2)), ((SCREEN_HEIGHT/2) - (this->height() / 2)));

    // Inizializziamo QMediaPlayer e QVideoWidget
    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    // Impostiamo la sorgente video
    mediaPlayer->setSource(QUrl(VIDEO_PATH));
    // Impostiamo l'output video sulla finestra
    mediaPlayer->setVideoOutput(videoWidget);
    // Impostiamo le dimensioni del QVideoWidget uguali a quelle della finestra
    videoWidget->setFixedSize(this->width(), this->height());
    // Mostriamo il QVideoWidget
    videoWidget->show();
    // Facciamo partire il video
    mediaPlayer->play();

    // Connettiamo lo slot rilasciato al cambiamento dello stato del video con la funzione di chiusura della finestra
    connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &AnimatedSplashScreen::closeWindow);
}

AnimatedSplashScreen::~AnimatedSplashScreen()
{
    delete ui;
    delete mediaPlayer;
    delete videoWidget;
}

void AnimatedSplashScreen::closeWindow()
{
    // Se il video è finito chiudiamo la finestra
    if (mediaPlayer->mediaStatus() == QMediaPlayer::EndOfMedia)
    {
        // Assicuriamoci il puntatore alla QMainWindow non sia un nullptr, quindi mostriamo la QMainWindow
        if (mainWindow) {
            mainWindow->show();
        }
        // Chiudiamo la finestra con il video
        this->close();
    }
}
