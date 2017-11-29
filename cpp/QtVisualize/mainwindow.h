#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets>

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
    void updatePentagonGeneration();
    void updatePrimitiveTileGeneration();
    void updateFitnessGraph();

   private:
    Ui::MainWindow* ui;
   public slots:
    void updatePentagonInfo(QString);
};

#endif  // MAINWINDOW_H
