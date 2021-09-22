#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <QWidget>
#include<QtMultimedia>
#include<QtMultimediaWidgets>

class SoundPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit SoundPlayer(QWidget *parent = nullptr);

protected:
    QMediaPlayer* m_Player;
private:
    QVBoxLayout* m_Layout;
    QPushButton* m_ButtonPlay;
    QPushButton* m_ButtonStop;
    QSlider* m_Position;
    QLabel* m_Current;
    QLabel* m_Remain;
    QString msecsToString(qint64 n);


private slots:
//    void slotOpen();
    void slotPlay();
    void slotSetSliderPosition(qint64);
    void slotSetMediaPosition(int);
    void slotSetDuration(qint64);
    void slotStatusChanged(QMediaPlayer::State);
    void slotGetAudio(QString);



signals:

};

#endif // SOUNDPLAYER_H
