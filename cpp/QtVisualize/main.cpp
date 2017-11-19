#include <QApplication>
#include <QString>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "mainwindow.h"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Window settings
    w.setWindowTitle("Pentagonal Tiling - Visulization");
    w.setWindowIcon(QIcon("favicon.ico"));
    w.setStyleSheet("QMainWindow {background: rgb(147,161,161);}");  // Set background color
    w.show();

    // Update the info about pentagons
    QString side1 = QString::number(23);
    QString content =
        QString("<span style=\" font-size:18pt; font-weight:300; font-family:Hack,Arial;\"\\>") +
        "Sides: " + side1 + "</span>";
    w.updatePentagonInfo(content);

    return a.exec();
}
