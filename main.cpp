#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setOrganizationName("HSE SpbSTU");
    QApplication::setApplicationName("AudioFuzzy");
    w.ConnectAll();
    w.show();
    return a.exec();
}
