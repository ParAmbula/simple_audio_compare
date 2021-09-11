#include "searchclass.h"

SearchClass::SearchClass(QObject *parent) : QObject(parent)
{

}

void SearchClass::StartSearch(MainWindow*source,const QDir& dir)
{
    QStringList FilterMask=dir.entryList(source->AudioMask,QDir::Files);
    foreach(QString file, FilterMask)
    {
        file=dir.absoluteFilePath(file);
//        AudioFile tmp(file);
//        source->ResultList.append(tmp);
        source->ResultList.append(new AudioFile(file));
        source->FileCount++;
    }
    QStringList listDir=dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QString subdir, listDir)
    {
        StartSearch(source,QDir(dir.absoluteFilePath(subdir)));
    }
}

void SearchClass::slotThread(MainWindow*src)
{
    mainsource=src;
    StartSearch(src,src->srcpath);
    src->tmpthread.quit();
}
