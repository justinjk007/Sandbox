#include <QApplication>
#include <QString>
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

    // Update the info about pentagons
    w.updatePentagonInfo("This is a test\n");  // Update data

    w.show();
    return a.exec();
}
