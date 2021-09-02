#ifndef TREERESULT_H
#define TREERESULT_H

#include <QWidget>
#include<QTreeWidget>
#include<QDir>
#include<audiofile.h>
#include<QTreeWidgetItem>
#include<QMainWindow>

class TreeResult : public QTreeWidget
{
    Q_OBJECT
public:
    explicit TreeResult(QTreeWidget *parent = nullptr);
private:
    int FileCount=0;
    QObject *pparent;
    QTreeWidgetItem* ptwi=0;
    QStringList AudioMask;
    QList<AudioFile> ResultList;
    void StartSearch(const QDir& dir);
    friend class QMainWindow;
    friend class AudioFile;

signals:
    int FileCountChanged(int);
};

#endif // TREERESULT_H
