#include "pentagonGen.hpp"
#include <QPaintEvent>
#include <QPainter>

pentagonGen::pentagonGen(QWidget* parent) : QWidget(parent)
{
    ;
}

void pentagonGen::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Pentagon");
}
