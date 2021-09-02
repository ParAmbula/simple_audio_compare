#include "treeresult.h"

TreeResult::TreeResult(QTreeWidget *parent) : QTreeWidget(parent)
{
    pparent=this->parent();

}

void TreeResult::StartSearch(const QDir& dir)
{
    //QApplication::processEvents();
    AudioMask<<"*.aac"<<"*.flac"<<"*.m4a"<<"*.mp3"<<"*.ogg"<<"*.wav"<<"*.wma"<<"*.mp4";
    QStringList FilterMask=dir.entryList(AudioMask,QDir::Files);
    foreach(QString file, FilterMask)
    {
        //QApplication::processEvents();
        file=dir.absoluteFilePath(file);
        AudioFile tmp(file);
        ResultList.append(tmp);
        //QApplication::processEvents();
        ptwi=new QTreeWidgetItem(this);
       // QApplication::processEvents();
        ptwi->setText(0,tmp.AudioName);
        //QApplication::processEvents();
        ptwi->setText(1,tmp.AudioSize);
        //this->pti= new QTableWidgetItem(QString("%1,%2").arg(tmp.AudioName).arg(tmp.AudioSize));
        //this->ui->TableResult->setItem(FileCount,0,pti);
        ++FileCount;
    }
    emit FileCountChanged();
    //QApplication::processEvents();
    //this->ui->Files->setText(QString::number(FileCount));
    //QApplication::processEvents();
    QStringList listDir=dir.entryList(QDir::Dirs| QDir::NoDotAndDotDot);
    foreach(QString subdir, listDir)
    {
        StartSearch(QDir(dir.absoluteFilePath(subdir)));
    }
    //this->ui->Files->setText(QString::number(FileCount));
}
