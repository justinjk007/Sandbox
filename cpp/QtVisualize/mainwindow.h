#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
    void updatePentagonInfo(const QString&);
    void updateFitnessGraph();
    void updatePentagonGeneration();
    void updatePrimitiveTileGeneration();

 private:
	Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
