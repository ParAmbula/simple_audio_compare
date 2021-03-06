// язык, мелочи имена иконки, коммент по участкам

// оформление "реферат" с пояснениями и алгоритмами

// язык через настройки

// без выбора директории работет сравнение проверка НЕ ДОЛЖНА РАБОТАТЬ

// слоты сигналы посмотреть в предупреждениях

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
#include<QSettings>


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
