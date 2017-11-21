#include "pentagonGen.hpp"
#include <QPaintEvent>
#include <QPainter>

pentagonGen::pentagonGen(QWidget* parent) : QWidget(parent)
{
    ;
}

void pentagonGen::paintEvent(QPaintEvent* e)
{
    QLinearGradient gradient(e->rect().topLeft(), e->rect().bottomRight());
    gradient.setColorAt(0, QColor(212,175,55));
    gradient.setColorAt(1, QColor(212,175,55));
    QLineF line(10.0, 80.0, 90.0, 20.0);
    QPainter painter(this);
    painter.fillRect(e->rect(), gradient);
    // LinearGradientPattern
    painter.setPen(Qt::blue);
    painter.drawLine(line);
}
