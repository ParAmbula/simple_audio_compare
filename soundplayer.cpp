#include "soundplayer.h"
#include<QFileDialog>
#include<QTreeWidgetItem>
#include<QTreeWidgetItemIterator>
#include<QTimer>
#include<QTime>
#include<QAction>
#include<QSettings>
#include<QVariant>

SoundPlayer::SoundPlayer(QWidget *parent) : QWidget(parent)
{
    QDial* pdialVolume=new QDial;
    pdialVolume->setNotchesVisible(true);
    m_ButtonPlay =new QPushButton;
    m_ButtonStop =new QPushButton;
    m_Position =new QSlider;
    m_Current =new QLabel(msecsToString(0));
    m_Remain =new QLabel(msecsToString(0));
    m_Player =new QMediaPlayer;
    m_ButtonPlay->setEnabled(false);
    m_ButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    m_ButtonStop->setEnabled(false);
    m_ButtonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    m_Position->setRange(0, 0);
    m_Position->setOrientation(Qt::Horizontal);
    pdialVolume->setRange(0, 100);
    int nDefaultVolume = 20;
    m_Player->setVolume(nDefaultVolume);
    pdialVolume->setValue(nDefaultVolume);
    connect(m_ButtonPlay,SIGNAL(clicked()),SLOT(slotPlay()));
    connect(m_ButtonStop,SIGNAL(clicked()),m_Player,SLOT(stop()));
    connect(pdialVolume,SIGNAL(valueChanged(int)),m_Player,SLOT(setVolume(int)));
    connect(m_Position,SIGNAL(sliderMoved(int)),SLOT(slotSetMediaPosition(int)));
    connect(m_Player,SIGNAL(positionChanged(qint64)),SLOT(slotSetSliderPosition(qint64)));
    connect(m_Player,SIGNAL(durationChanged(qint64)),SLOT(slotSetDuration(qint64)));
    connect(m_Player,&QMediaPlayer::stateChanged,this,&SoundPlayer::slotStatusChanged);
    QHBoxLayout* phbxPlayControls = new QHBoxLayout;
    phbxPlayControls->addWidget(m_ButtonPlay);
    phbxPlayControls->addWidget(m_ButtonStop);
    phbxPlayControls->addWidget(pdialVolume);
    QHBoxLayout* phbxTimeControls = new QHBoxLayout;
    phbxTimeControls->addWidget(m_Current);
    phbxTimeControls->addWidget(m_Position);
    phbxTimeControls->addWidget(m_Remain);
    m_Layout = new QVBoxLayout;
    m_Layout->addLayout(phbxPlayControls);
    m_Layout->addLayout(phbxTimeControls);
    setLayout(m_Layout);
}

QString SoundPlayer::msecsToString(qint64 n)
{
    int nHours=(n/(60*60*1000));
    int nMinutes=((n%(60*60*1000)/(60*1000)));
    int nSeconds=((n%(60*1000))/1000);
    return QTime(nHours,nMinutes,nSeconds).toString("hh:mm:ss");
}

void SoundPlayer::slotPlay()
{
    switch(m_Player->state())
    {
    case QMediaPlayer::PlayingState:
        m_Player->pause();
        break;
    default:
        m_Player->play();
        break;
    }
}

void SoundPlayer::slotSetSliderPosition(qint64 n)
{
    m_Position->setValue(n);
    m_Current->setText(msecsToString(n));
    int nDuration=m_Position->maximum();
    m_Remain->setText(msecsToString(nDuration-n));
}

void SoundPlayer::slotSetMediaPosition(int n)
{
    m_Player->setPosition(n);
}

void SoundPlayer::slotSetDuration(qint64 n)
{
    m_Position->setRange(0,n);
    m_Current->setText(msecsToString(0));
    m_Remain->setText(msecsToString(n));
}

void SoundPlayer::slotStatusChanged(QMediaPlayer::State state)
{
    switch(state)
    {
    case QMediaPlayer::PlayingState:
        m_ButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        m_ButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

void SoundPlayer::slotGetAudio(QString filepath)
{
    if(filepath.isEmpty()||filepath.isNull())
        QMessageBox::warning(this,tr("Warning"),tr("Can`t play file. Check file path and installed audio codecs!"));
    m_Player->setMedia(QUrl::fromLocalFile(filepath));
    m_ButtonPlay->setEnabled(true);
    m_ButtonStop->setEnabled(true);
}
