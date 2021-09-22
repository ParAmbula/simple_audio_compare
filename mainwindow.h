#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<compareclass.h>
#include<soundplayer.h>


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
    QString oldname;
    QTranslator translator;
    QTranslator apptranslator;
    QStringList lst;
    int FileCount=0;
    QTreeWidgetItem* ptwi=0;
    friend class SoundPlayer;
    QStringList AudioMask;
    QList<AudioFile*> ResultList;
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
    void OpenFile(QTreeWidgetItem *);
//    void Rename(QTreeWidgetItem *);
    SoundPlayer* PlayerBottom;
    QMenu* menuclass;
    QPoint menupos;
    QSettings *m_settings;


public slots:
    void slotLangRU();
    void slotLangEN();
    void slotBrowse();
    void slotFind();
    void slotCompare();
    void slotTimeUpdate();
    void slotAbort();
    void slotDeleteselected();
    void slotAbout();
    void slotInfo();
    void slotExit();
    void slotConMenu(const QPoint&pos);
    void slotRename();
    void slotOpenLocation();
    void slotRenameFile(QTreeWidgetItem *item, int column);

signals:
    void Rename(QTreeWidgetItem *,int);
    void StartThread(MainWindow*);
    void StartCompareThread(MainWindow*);
    void SendAudio(QString);

private slots:
    void on_CompareResult_itemClicked(QTreeWidgetItem *item, int column);
};
#endif // MAINWINDOW_H
