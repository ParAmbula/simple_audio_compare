// оформление "реферат" с пояснениями и алгоритмами

#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include<QObject>
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
