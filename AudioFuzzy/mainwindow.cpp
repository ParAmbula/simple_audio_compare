#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_settings("HSE SpbSTU","AudioFuzzy")
{
    QString filespec=m_settings.value("/Settings/qtLanSpec","qt_en").toString();
    QString directory=QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    apptranslator.load(filespec,directory);
//    apptranslator.load(settings.value("/Settings/qtLanSpec","qt_en").toString(),QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&apptranslator);
    QString lang=m_settings.value("/Settings/Tran","main_en.qm").toString();
    translator.load(lang,".");
//    translator.load(settings.value("/Setting/Tran","main_en.qm").toString(),".");
    QApplication::installTranslator(&translator);

    ui->setupUi(this);
    menuclass=nullptr;
    this->setWindowTitle("AudioFuzzy");
    this->setWindowIcon((style()->standardIcon(QStyle::SP_MediaVolume)));
    lst<<tr("Name")<<tr("Size");
    this->ui->TreeResult->setHeaderLabels(lst);
    this->ui->TreeResult->setFixedWidth(400);
    this->ui->TreeResult->setSortingEnabled(true);
    this->ui->TreeResult->setColumnWidth(0,200);
    lst<<tr("Name")<<tr("Size");
    lst.clear();
    lst<<tr("Name")<<tr("Match")<<tr("Path");
    this->ui->CompareResult->setHeaderLabels(lst);
    this->ui->CompareResult->setColumnWidth(0,200);
    this->ui->CompareResult->setColumnWidth(1,80);
    this->ui->ProgressBar->hide();
    tmpsearch=nullptr;
    tmpcompare=nullptr;
    worktime=new QTimer(this);
    AudioMask<<"*.aac"<<"*.flac"<<"*.m4a"<<"*.mp3"<<"*.ogg"<<"*.wav"<<"*.wma"<<"*.mp4";
    PlayerBottom=new SoundPlayer(this);
    this->ui->PlayerLayout->addWidget(PlayerBottom);
    this->ui->SearchButton->setDisabled(true);
    this->ui->CompareButton->setDisabled(true);
    this->ui->StopButton->setDisabled(true);
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
    connect(this,SIGNAL(SendAudio(QString)),PlayerBottom,SLOT(slotGetAudio(QString)));
    connect(this->ui->CompareResult,SIGNAL(itemClicked()),this,SLOT(on_CompareResult_itemClicked()));
    connect(this->ui->CompareResult,SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(slotConMenu(const QPoint &)));
    connect(this->ui->CompareResult,SIGNAL(itemChanged(QTreeWidgetItem *item, int column)),this,SLOT(slotRenameFile(QTreeWidgetItem *item, int column)));
}

void MainWindow::DeleteFiles()
{
    QTreeWidgetItemIterator it(this->ui->CompareResult);
    while(*it)
    {
        if((*it)->checkState(0)==Qt::Checked)
        {
            QFile filetodelete((*it)->text(2));
            filetodelete.remove();
            if(!filetodelete.exists())
            {
                QString newname=(*it)->text(0);
                (*it)->setText(0,tr("DELETED ")+newname);
            }
        }
        ++it;
    }
}

void MainWindow::OpenFile(QTreeWidgetItem *item)
{
    QStringList args;
    args << "/select," << QDir::toNativeSeparators(item->text(2));
    QProcess::startDetached("explorer", args);
}

void MainWindow::Rename(QTreeWidgetItem *item)
{
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
}

void MainWindow::slotLangRU()
{
    m_settings.setValue("/Settings/qtLanSpec","qt_ru");
    m_settings.setValue("/Setting/Tran","main_ru.qm");
    QMessageBox::about(this,"Settings saved.","Restart application.");

//    settings.setValue("/Settings/qtLanDir",QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//    QCoreApplication::removeTranslator(&translator);
//    QCoreApplication::removeTranslator(&apptranslator);
//    QString filespec=QString("qt_ru");
//    QString directory=QLibraryInfo::location(QLibraryInfo::TranslationsPath);
//    apptranslator.load(filespec,directory);
//    QApplication::installTranslator(&apptranslator);
//    translator.load("main_ru.qm",".");
//    QApplication::installTranslator(&translator);
//    QCoreApplication::installTranslator(&translator);
//    QCoreApplication::installTranslator(&apptranslator);
}

void MainWindow::slotLangEN()
{
    m_settings.setValue("/Settings/qtLanSpec","qt_en");
    m_settings.setValue("/Setting/Tran","main_en.qm");
    QMessageBox::about(this,tr("Settings saved."),tr("Restart application."));
}

void MainWindow::slotBrowse()
{
    QString SourceDir = QFileDialog::getExistingDirectory(0,tr("Select a Directory"),this->ui->SourceFolder->text());
    if(!SourceDir.isEmpty())
        this->ui->SourceFolder->setText(SourceDir);
    else
        this->ui->SourceFolder->setText(tr("Invalid Directory"));
    this->ui->SearchButton->setDisabled(false);
}

void MainWindow::slotFind()
{
    if(worktime->isActive())
        return;
    this->ui->StopButton->setDisabled(false);
    FileCount=0;
    this->ui->Files->setText(QString(tr("Counting")));
    ResultList.clear();
    ui->TreeResult->clear();
    this->ui->ProgressBar->show();
    ui->statusbar->showMessage(tr("Work in progress."));
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
    ui->statusbar->showMessage(tr("Job`s done."));
    this->ui->ProgressBar->hide();
    worktime->stop();
    this->ui->Files->setText(QString::number(FileCount));
    for(auto& lswd:ResultList )
    {
        ptwi=new QTreeWidgetItem(this->ui->TreeResult);
        ptwi->setText(0,lswd->AudioName);
        ptwi->setText(1,lswd->AudioSize+" MB");
    }
    this->ui->CompareButton->setDisabled(false);

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
    ui->statusbar->showMessage(tr("Checking files."));
    this->ui->ProgressBar->show();
    tmpthread.start();
    connect(this,SIGNAL(StartCompareThread(MainWindow*)),tmpcompare,SLOT(slotCompare(MainWindow*)));
    emit StartCompareThread(this);
    while(!(tmpthread.isFinished() || tmpthread.isInterruptionRequested()))
        QApplication::processEvents();
    ui->statusbar->showMessage(tr("Job`s done."));
    delete tmpcompare;
    tmpcompare=nullptr;
    this->ui->ProgressBar->hide();
    this->ui->CompareResult->clear();
    for(auto& audfile:ResultList)
    {
        if(!audfile->TreeAdded)
        {
            audfile->TreeAdded=true;
            ptwi=new QTreeWidgetItem(this->ui->CompareResult);
            ptwi->setFlags(ptwi->flags()|Qt::ItemIsUserCheckable);
            ptwi->setCheckState(0,Qt::Unchecked);
            ptwi->setText(0,audfile->AudioName);
            ptwi->setText(1,QString(tr("Sample")));
            ptwi->setText(2,audfile->AudioPath);
            for(auto&files:audfile->CompareResult.keys())
            {
                if(!files->TreeAdded)
                {
                    files->TreeAdded=true;
                    QTreeWidgetItem* childitem=new QTreeWidgetItem(ptwi);
                    childitem->setFlags(childitem->flags()|Qt::ItemIsUserCheckable);
                    childitem->setCheckState(0,Qt::Unchecked);
                    childitem->setText(0,files->AudioName);
                    childitem->setText(1,QString::number(audfile->CompareResult.value(files))+" %");
                    childitem->setText(2,files->AudioPath);
                }
            }
        }
    }
    this->ui->CompareResult->setContextMenuPolicy(Qt::CustomContextMenu);
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
    QMessageBox::about(this,tr("About"),tr("This is a simple program to compare audio files."));
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

void MainWindow::slotConMenu(const QPoint&pos)
{
    QTreeWidgetItem *item = this->ui->CompareResult->itemAt(pos);
    if (!item)
       return;
    menupos=pos;
    if(menuclass==nullptr)
    {
    menuclass=new QMenu(tr("Built in Menu"),this->ui->CompareResult);
    menuclass->addAction(tr("Delete selected"),this,SLOT(slotDeleteselected()));
    menuclass->addAction(tr("Open file location"),this,SLOT(slotOpenLocation()));
    menuclass->addAction(tr("Rename"),this,SLOT(slotRename()));
    }
    menuclass->exec(this->ui->CompareResult->viewport()->mapToGlobal(pos));
}

void MainWindow::slotRename()
{
    QTreeWidgetItem *item = this->ui->CompareResult->itemAt(menupos);
    Rename(item);
}

void MainWindow::slotOpenLocation()
{
    QTreeWidgetItem *item = this->ui->CompareResult->itemAt(menupos);
    OpenFile(item);
}

void MainWindow::slotRenameFile(QTreeWidgetItem *item, int column)
{
    QFile file(item->text(2));
    file.open(QFile::Unbuffered|QFile::ReadWrite);
    file.rename(item->text(0));
    file.flush();
    file.close();
//    file.fileName()=item->text(0);
}

void MainWindow::on_CompareResult_itemClicked(QTreeWidgetItem *item, int column)
{
    QString file=item->text(2);
    emit SendAudio(file);
}

