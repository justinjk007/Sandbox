#include "textWidget.hpp"
#include <QTextBrowser>

textWidget::textWidget(QWidget* parent) : QWidget(parent)
{
    ;
}

void textWidget::paintEvent(QPaintEvent* e)
{
    QTextBrowser* textDisplay = new QTextBrowser();
    // ui->pentagon_info->append(content);
    textDisplay->append("This is a test");
}
