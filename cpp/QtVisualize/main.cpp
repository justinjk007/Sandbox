#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Pentagonal Tiling - Visulization");
    w.setWindowIcon(QIcon("favicon.ico"));
    w.setStyleSheet("QMainWindow {background: rgb(147,161,161);}"); // Set background color
    w.show();

    return a.exec();
}
