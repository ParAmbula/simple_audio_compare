// mediaplayer в новой версии есть, здесь нет   ! 2 !  другую версию

// выпадающее контекстное меню по правой кнопке(вызывать windows api стандартную правую кнопку,
// через комбоящик, или отдельно в верхнем меню?) ! 3 !   menu слот-сигнал в ui_mainwindow вызывать

// в мультихеш указатели на мой класс, qHash нужен? через что глянуть память ! 1 !

// язык, мелочи имена иконки, коммент по участкам

// оформление "реферат" с пояснениями и алгоритмами

#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include<QObject>
#include<QFile>
#include<QFileInfo>
#include<QCryptographicHash>
#include<QMessageBox>
#include<QDebug>
#include<QDir>
#include<QThread>
#include<QByteArray>
#include<QMultiMap>


class MainWindow;
class CompareClass;

class AudioFile
{
public:
    AudioFile(const QString& file);
    bool operator==(const AudioFile& other) const;
    AudioFile();
    bool DataEqual(AudioFile*other) const;
    bool PathEqual(AudioFile*other) const;
    bool HashEqual(AudioFile*other) const;
    bool SizeEqual(AudioFile*other) const;
    bool NameEqual(AudioFile*other) const;
private:
    QString AudioName;
    QString AudioSize;
    QString AudioHash;
    QString AudioPath;
    QString AudioData;
    QMultiMap<AudioFile*,char> CompareResult;
    bool TreeAdded;
    friend class MainWindow;
    friend class TreeResult;
    friend class CompareClass;
};

#endif // AUDIOFILE_H
