/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Deleteaction;
    QAction *Aboutaction;
    QAction *Exitaction;
    QAction *Infoaction;
    QAction *actionEN;
    QAction *actionRUS;
    QAction *actionOpen_File_Location;
    QAction *actionRename_File;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QTreeWidget *TreeResult;
    QTreeWidget *CompareResult;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *DirectoryButton;
    QPushButton *SearchButton;
    QPushButton *CompareButton;
    QPushButton *StopButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *FilesLabel;
    QLabel *DurationLabel;
    QProgressBar *ProgressBar;
    QLabel *SourceFolderLabel;
    QLabel *ProgressLabel;
    QLabel *SourceFolder;
    QLabel *Duration;
    QLabel *Files;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *PlayerLayout;
    QMenuBar *TopBar;
    QMenu *Menu;
    QMenu *menuLanguage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1014, 771);
        Deleteaction = new QAction(MainWindow);
        Deleteaction->setObjectName(QString::fromUtf8("Deleteaction"));
        Aboutaction = new QAction(MainWindow);
        Aboutaction->setObjectName(QString::fromUtf8("Aboutaction"));
        Exitaction = new QAction(MainWindow);
        Exitaction->setObjectName(QString::fromUtf8("Exitaction"));
        Infoaction = new QAction(MainWindow);
        Infoaction->setObjectName(QString::fromUtf8("Infoaction"));
        actionEN = new QAction(MainWindow);
        actionEN->setObjectName(QString::fromUtf8("actionEN"));
        actionRUS = new QAction(MainWindow);
        actionRUS->setObjectName(QString::fromUtf8("actionRUS"));
        actionOpen_File_Location = new QAction(MainWindow);
        actionOpen_File_Location->setObjectName(QString::fromUtf8("actionOpen_File_Location"));
        actionRename_File = new QAction(MainWindow);
        actionRename_File->setObjectName(QString::fromUtf8("actionRename_File"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, 109, 5123, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        TreeResult = new QTreeWidget(gridLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        TreeResult->setHeaderItem(__qtreewidgetitem);
        TreeResult->setObjectName(QString::fromUtf8("TreeResult"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TreeResult->sizePolicy().hasHeightForWidth());
        TreeResult->setSizePolicy(sizePolicy);
        TreeResult->setMinimumSize(QSize(400, 0));

        gridLayout->addWidget(TreeResult, 0, 0, 1, 1);

        CompareResult = new QTreeWidget(gridLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        CompareResult->setHeaderItem(__qtreewidgetitem1);
        CompareResult->setObjectName(QString::fromUtf8("CompareResult"));

        gridLayout->addWidget(CompareResult, 0, 2, 1, 1);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 401, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        DirectoryButton = new QPushButton(horizontalLayoutWidget);
        DirectoryButton->setObjectName(QString::fromUtf8("DirectoryButton"));

        horizontalLayout->addWidget(DirectoryButton);

        SearchButton = new QPushButton(horizontalLayoutWidget);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));

        horizontalLayout->addWidget(SearchButton);

        CompareButton = new QPushButton(horizontalLayoutWidget);
        CompareButton->setObjectName(QString::fromUtf8("CompareButton"));

        horizontalLayout->addWidget(CompareButton);

        StopButton = new QPushButton(horizontalLayoutWidget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));

        horizontalLayout->addWidget(StopButton);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(440, 0, 561, 111));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        FilesLabel = new QLabel(gridLayoutWidget_2);
        FilesLabel->setObjectName(QString::fromUtf8("FilesLabel"));

        gridLayout_2->addWidget(FilesLabel, 5, 0, 1, 1);

        DurationLabel = new QLabel(gridLayoutWidget_2);
        DurationLabel->setObjectName(QString::fromUtf8("DurationLabel"));

        gridLayout_2->addWidget(DurationLabel, 0, 0, 1, 1);

        ProgressBar = new QProgressBar(gridLayoutWidget_2);
        ProgressBar->setObjectName(QString::fromUtf8("ProgressBar"));
        ProgressBar->setEnabled(false);
        ProgressBar->setLayoutDirection(Qt::LeftToRight);
        ProgressBar->setMaximum(0);
        ProgressBar->setValue(0);
        ProgressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ProgressBar->setTextVisible(false);
        ProgressBar->setOrientation(Qt::Horizontal);
        ProgressBar->setInvertedAppearance(false);
        ProgressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_2->addWidget(ProgressBar, 3, 2, 1, 1);

        SourceFolderLabel = new QLabel(gridLayoutWidget_2);
        SourceFolderLabel->setObjectName(QString::fromUtf8("SourceFolderLabel"));

        gridLayout_2->addWidget(SourceFolderLabel, 4, 0, 1, 1);

        ProgressLabel = new QLabel(gridLayoutWidget_2);
        ProgressLabel->setObjectName(QString::fromUtf8("ProgressLabel"));

        gridLayout_2->addWidget(ProgressLabel, 3, 0, 1, 1);

        SourceFolder = new QLabel(gridLayoutWidget_2);
        SourceFolder->setObjectName(QString::fromUtf8("SourceFolder"));

        gridLayout_2->addWidget(SourceFolder, 4, 2, 1, 1);

        Duration = new QLabel(gridLayoutWidget_2);
        Duration->setObjectName(QString::fromUtf8("Duration"));

        gridLayout_2->addWidget(Duration, 0, 2, 1, 1);

        Files = new QLabel(gridLayoutWidget_2);
        Files->setObjectName(QString::fromUtf8("Files"));

        gridLayout_2->addWidget(Files, 5, 2, 1, 1);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 579, 991, 131));
        PlayerLayout = new QVBoxLayout(verticalLayoutWidget);
        PlayerLayout->setObjectName(QString::fromUtf8("PlayerLayout"));
        PlayerLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        TopBar = new QMenuBar(MainWindow);
        TopBar->setObjectName(QString::fromUtf8("TopBar"));
        TopBar->setGeometry(QRect(0, 0, 1014, 26));
        Menu = new QMenu(TopBar);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        menuLanguage = new QMenu(Menu);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(TopBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        TopBar->addAction(Menu->menuAction());
        Menu->addAction(menuLanguage->menuAction());
        Menu->addAction(Infoaction);
        Menu->addAction(Aboutaction);
        Menu->addAction(Exitaction);
        menuLanguage->addAction(actionEN);
        menuLanguage->addAction(actionRUS);

        retranslateUi(MainWindow);
        QObject::connect(Exitaction, SIGNAL(triggered()), MainWindow, SLOT(slotExit()));
        QObject::connect(Aboutaction, SIGNAL(triggered()), MainWindow, SLOT(slotAbout()));
        QObject::connect(Infoaction, SIGNAL(triggered()), MainWindow, SLOT(slotInfo()));
        QObject::connect(Deleteaction, SIGNAL(triggered()), MainWindow, SLOT(slotDeleteselected()));
        QObject::connect(actionRUS, SIGNAL(triggered()), MainWindow, SLOT(slotLangRU()));
        QObject::connect(actionEN, SIGNAL(triggered()), MainWindow, SLOT(slotLangEN()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Deleteaction->setText(QCoreApplication::translate("MainWindow", "Delete selected", nullptr));
        Aboutaction->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        Exitaction->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Infoaction->setText(QCoreApplication::translate("MainWindow", "Program info", nullptr));
        actionEN->setText(QCoreApplication::translate("MainWindow", "EN", nullptr));
        actionRUS->setText(QCoreApplication::translate("MainWindow", "RUS", nullptr));
        actionOpen_File_Location->setText(QCoreApplication::translate("MainWindow", "Open File Location", nullptr));
        actionRename_File->setText(QCoreApplication::translate("MainWindow", "Rename File", nullptr));
        DirectoryButton->setText(QCoreApplication::translate("MainWindow", "Directory", nullptr));
        SearchButton->setText(QCoreApplication::translate("MainWindow", "Start search", nullptr));
        CompareButton->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        StopButton->setText(QCoreApplication::translate("MainWindow", "Abort", nullptr));
        FilesLabel->setText(QCoreApplication::translate("MainWindow", "Files:", nullptr));
        DurationLabel->setText(QCoreApplication::translate("MainWindow", "Duration:", nullptr));
        SourceFolderLabel->setText(QCoreApplication::translate("MainWindow", "Source Folder:", nullptr));
        ProgressLabel->setText(QCoreApplication::translate("MainWindow", "Progress:", nullptr));
        SourceFolder->setText(QString());
        Duration->setText(QCoreApplication::translate("MainWindow", "00::00::00", nullptr));
        Files->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Menu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
