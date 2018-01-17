#include "graphWidget.hpp"

using namespace QtCharts;

graphWidget::graphWidget(QWidget* parent) : QWidget(parent)
{
    ;
}

void graphWidget::paintEvent(QPaintEvent* e)
{
    /**
     * This method updates the content of Fitnessgraph
     */
    QLineSeries* series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3)
            << QPointF(20, 2);

    QChart* chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    // chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundRoundness(0);
    chart->setTitle("Fitness of generated samples");

    QChartView* fitness_graph = new QChartView(chart);
    fitness_graph->setRenderHint(QPainter::Antialiasing);
    fitness_graph->setMinimumSize(300, 100);
    // ui->left_side->addWidget(fitness_graph);
    fitness_graph->repaint();
}
