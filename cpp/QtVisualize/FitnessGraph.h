#ifndef FITNESSGRAPH_H
#define FITNESSGRAPH_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

class FitnessGraph : public QWidget
{
    Q_OBJECT
public:
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // FITNESSGRAPH_H
