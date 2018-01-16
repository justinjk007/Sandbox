#ifndef GRAPHWIDGET_HPP
#define GRAPHWIDGET_HPP

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

class graphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit graphWidget(QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent* e) override;
};

#endif /* GRAPHWIDGET_HPP */
