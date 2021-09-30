#ifndef COMPARECLASS_H
#define COMPARECLASS_H
#include<searchclass.h>

class MainWindow;
class CompareClass : public QObject
{
    Q_OBJECT
public:
    explicit CompareClass(QObject *parent = nullptr);

private:
    MainWindow*mainsource;
    QList<AudioFile*>::iterator first;
    QList<AudioFile*>::iterator second;
    char result;
    void StartCompare();
    void FuzzyCompare(AudioFile* one,AudioFile*two);
    void ResultMap(AudioFile* left,AudioFile*right);
signals:
public slots:
    void slotCompare(MainWindow*src);

};

#endif // COMPARECLASS_H
