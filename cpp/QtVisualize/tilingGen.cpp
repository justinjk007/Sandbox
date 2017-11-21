#include "tilingGen.hpp"
#include <QPaintEvent>
#include <QPainter>

tilingGen::tilingGen(QWidget* parent) : QWidget(parent)
{
    ;
}

void tilingGen::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Tiling");
}
