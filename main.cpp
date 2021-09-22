#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTranslator translator;
//    QTranslator apptranslator;
//    QString filespec=QString("qt_ru");
//    QString directory=QLibraryInfo::location(QLibraryInfo::TranslationsPath);
//    apptranslator.load(filespec,directory);
//    QApplication::installTranslator(&apptranslator);
//    translator.load("main_ru.qm",".");
//    QApplication::installTranslator(&translator);
    MainWindow w;
    QApplication::setOrganizationName("HSE SpbSTU");
    QApplication::setApplicationName("AudioFuzzy");
    w.ConnectAll();
    w.show();
    return a.exec();
}
