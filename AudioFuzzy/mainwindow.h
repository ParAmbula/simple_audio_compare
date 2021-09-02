#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QFileDialog>
#include<QTreeWidgetItem>
#include<QTreeWidgetItemIterator>
#include<QTimer>
#include<QTime>
#include<compareclass.h>

class SearchClass;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ConnectAll();
private:    
    QStringList lst;
    int FileCount=0;
    QTreeWidgetItem* ptwi=0;
    QStringList AudioMask;
    QList<AudioFile> ResultList;
    Ui::MainWindow *ui;
    QTimer* worktime;
    QTime functime;
    friend class SearchClass;
    SearchClass* tmpsearch;
    friend class CompareClass;
    CompareClass* tmpcompare;
    QThread tmpthread;
    QDir srcpath;
    void DeleteFiles();

public slots:
    void slotBrowse();
    void slotFind();
    void slotCompare();
    void slotTimeUpdate();
    void slotAbort();
    void slotDeleteselected();
    void slotAbout();
    void slotInfo();
    void slotExit();

signals:
    void StartThread(MainWindow*);
    void StartCompareThread(MainWindow*);

};
#endif // MAINWINDOW_H