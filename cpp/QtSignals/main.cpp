#include <QApplication>
#include <QString>
#include "backend.hpp"
#include "mainwindow.h"

using namespace std;

// This macro disables the extra cmd window popup when in Microsoft windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Window settings
    w.setWindowTitle("Sandman");

    w.show();
    return a.exec();
}
