#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lst<<"Name"<<"Size";
    this->ui->TreeResult->setHeaderLabels(lst);
    lst.clear();
    lst<<"Name"<<"Match"<<"Path";
    this->ui->CompareResult->setHeaderLabels(lst);
    this->ui->TreeResult->setSortingEnabled(true);
    this->ui->ProgressBar->hide();
    tmpsearch=nullptr;
    tmpcompare=nullptr;
    worktime=new QTimer(this);
    AudioMask<<"*.aac"<<"*.flac"<<"*.m4a"<<"*.mp3"<<"*.ogg"<<"*.wav"<<"*.wma"<<"*.mp4";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ConnectAll()
{
    connect(this->ui->DirectoryButton,SIGNAL(clicked()),SLOT(slotBrowse()));
    connect(this->ui->SearchButton,SIGNAL(clicked()),SLOT(slotFind()));
    connect(this->ui->CompareButton,SIGNAL(clicked()),SLOT(slotCompare()));
    connect(this->ui->StopButton,SIGNAL(clicked()),SLOT(slotAbort()));
    connect(this->worktime,SIGNAL(timeout()),this,SLOT(slotTimeUpdate()));
}

void MainWindow::DeleteFiles()
{
    QTreeWidgetItemIterator it(this->ui->CompareResult);
    while(*it)
    {
        if((*it)->childCount()>=1)
        {
            QTreeWidgetItemIterator init(it);
            ++init;
            int i=(*it)->childCount();
            while(i!=0)
            {
                if((*init)->checkState(0)==Qt::Checked)
                {
                    QFile filetodelete((*init)->text(2));
                    filetodelete.remove();
                    if(!filetodelete.exists())
                        qDebug()<<(*init)->text(2)+" WAS DELETED!";
                }
                ++init;
                --i;
            }
        }
        else if((*it)->checkState(0)==Qt::Checked)
        {
            QFile filetodelete((*it)->text(2));
            filetodelete.remove();
            if(!filetodelete.exists())
                qDebug()<<(*it)->text(2)+" WAS DELETED!";
        }
        ++it;
    }

//    foreach(QTreeWidgetItem* topitem, this->ui->CompareResult)
//    {
//        if(topitem->childCount()>=1)
//        {
//            foreach(QTreeWidgetItem* item, topitem)
//            {
//                if(item->checkState(0)==Qt::Checked)
//                {
//                    QFile filetodelete(item->text(2));
//                    filetodelete.remove();
//                    qDebug()<<item->text(2)+" WAS DELETED!";
//                }
//            }
//        }
//        if(topitem->checkState(0)==Qt::Checked)
//        {
//            QFile topfiletodelete(topitem->text(2));
//            topfiletodelete.remove();
//            qDebug()<<topitem->text(2)+" WAS DELETED!";
//        }
//    }
}

void MainWindow::slotBrowse()
{
    QString SourceDir = QFileDialog::getExistingDirectory(0,"Select a Directory",this->ui->SourceFolder->text());
    if(!SourceDir.isEmpty())
        this->ui->SourceFolder->setText(SourceDir);
    else
        this->ui->SourceFolder->setText("Invalid Directory");
}

void MainWindow::slotFind()
{
    if(worktime->isActive())
        return;
    FileCount=0;
    this->ui->Files->setText(QString("Counting"));
    ResultList.clear();
    ui->TreeResult->clear();
    this->ui->ProgressBar->show();
    ui->statusbar->showMessage("Work in progress.");
    functime.setHMS(0,0,0);
    worktime->start(1000);
    tmpsearch=new SearchClass(0);
    tmpsearch->moveToThread(&tmpthread);
    srcpath=QDir(this->ui->SourceFolder->text());
    connect(this,SIGNAL(StartThread(MainWindow*)),tmpsearch,SLOT(slotThread(MainWindow*)));
    tmpthread.start();
    emit StartThread(this);
    while(!(tmpthread.isFinished()||tmpthread.isInterruptionRequested()))
        QApplication::processEvents();
    delete tmpsearch;
    tmpsearch=nullptr;
    ui->statusbar->showMessage("Job`s done.");
    this->ui->ProgressBar->hide();
    worktime->stop();
    this->ui->Files->setText(QString::number(FileCount));
    for(auto& lswd:ResultList )
    {
        ptwi=new QTreeWidgetItem(this->ui->TreeResult);
        ptwi->setText(0,lswd.AudioName);
        ptwi->setText(1,lswd.AudioSize);
    }
    qDebug()<<"Stop find";
}

void MainWindow::slotTimeUpdate()
{
    QApplication::processEvents();
    functime=functime.addSecs(1);
    this->ui->Duration->setText(functime.toString("hh::mm::ss"));
    QApplication::processEvents();
}

void MainWindow::slotAbort()
{
        tmpthread.terminate();
        tmpthread.wait();
        return;
}

void MainWindow::slotCompare()
{
    if(worktime->isActive())
        return;
    tmpcompare=new CompareClass;
    tmpcompare->moveToThread(&tmpthread);
    ui->statusbar->showMessage("Checking files.");
    this->ui->ProgressBar->show();
    tmpthread.start();
    connect(this,SIGNAL(StartCompareThread(MainWindow*)),tmpcompare,SLOT(slotCompare(MainWindow*)));
    emit StartCompareThread(this);
    while(!(tmpthread.isFinished() || tmpthread.isInterruptionRequested()))
        QApplication::processEvents();
    ui->statusbar->showMessage("Job`s done.");
    delete tmpcompare;
    tmpcompare=nullptr;
    this->ui->ProgressBar->hide();
    this->ui->CompareResult->clear();
    for(auto& audfile:ResultList)
    {
        if(!audfile.TreeAdded)
        {
            audfile.TreeAdded=true;
            ptwi=new QTreeWidgetItem(this->ui->CompareResult);
            ptwi->setFlags(ptwi->flags()|Qt::ItemIsUserCheckable);
            ptwi->setCheckState(0,Qt::Unchecked);
            ptwi->setText(0,audfile.AudioName);
            for(auto&files:audfile.CompareResult.keys())
            {
                if(!files->TreeAdded)
                {
                files->TreeAdded=true;
                QTreeWidgetItem* childitem=new QTreeWidgetItem(ptwi);
                childitem->setFlags(childitem->flags()|Qt::ItemIsUserCheckable);
                childitem->setCheckState(0,Qt::Unchecked);
                childitem->setText(0,files->AudioName);
                childitem->setText(1,QString::number(audfile.CompareResult.value(files))+" %");
                childitem->setText(2,files->AudioPath);
                }
            }
        }
    }
    this->ui->CompareResult->dumpObjectTree();
    qDebug()<<"Stop compare";
}

void MainWindow::slotDeleteselected()
{
    DeleteFiles();
}

void MainWindow::slotAbout()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::slotInfo()
{
    QMessageBox::about(this,"About","This is a simple program to compare audio files.");
}

void MainWindow::slotExit()
{
    tmpthread.terminate();
    tmpthread.wait();
    if(tmpsearch!=nullptr)
        delete tmpsearch;
    if(tmpcompare!=nullptr)
        delete tmpcompare;
    this->close();
}
