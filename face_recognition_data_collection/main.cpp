#include "mainwindow.h"
#include "process_model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ProcessModel pm(&w);
    w.show();
    return a.exec();
}
