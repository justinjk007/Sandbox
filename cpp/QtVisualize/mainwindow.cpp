#include "mainwindow.h"
#include <QString>
#include <QTextBrowser>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePentagonInfo(const QString& content)
{
    /**
     * This method updates information about the pentagon in the text
     * browser on the top right of the main program window. Appending
     * whatever is given as the argument
     */
    ui->pentagon_info->append(content);
}

void MainWindow::updateFitnessGraph()
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
    chart->setTitle("Simple line chart example");

    QChartView* fitness_graph = new QChartView(ui->fitness_graph);
    fitness_graph->setRenderHint(QPainter::Antialiasing);
    fitness_graph->setChart(chart);
}

void MainWindow::updatePentagonGeneration()
{
    /**
     * Updates information on the bottom right widget where pentagon
     * is generated line by line
     */
}

void MainWindow::updatePrimitiveTileGeneration()
{
    /**
     * Updates information on the top left widget where Primitive tile
     * is drawn after tiling everrything so that the gaps outputted
     * makes sense
     */
}

void PentagonGen::paintEvent(QPaintEvent *e)
{
    /**
     * Updates information on the bottom right widget where pentagon
     * is generated line by line
     */
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
    QWidget::paintEvent(e);
}

