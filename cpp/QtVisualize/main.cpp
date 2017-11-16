#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Set background color of the main window
    w.setStyleSheet("QMainWindow {background: rgb(147,161,161);}");
    w.show();

    return a.exec();
}
