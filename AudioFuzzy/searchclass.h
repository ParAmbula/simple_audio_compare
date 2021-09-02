#ifndef SEARCHCLASS_H
#define SEARCHCLASS_H
#include<audiofile.h>
#include<mainwindow.h>
class MainWindow;
class SearchClass : public QObject
{
    Q_OBJECT
public:
    explicit SearchClass(QObject *parent = nullptr);
    void StartSearch(MainWindow *source,const QDir& dir);
signals:

public slots:
    void slotThread(MainWindow*src);

private:
    MainWindow*mainsource;
};

#endif // SEARCHCLASS_H
