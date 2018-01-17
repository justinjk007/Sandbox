#ifndef TEXTWIDGET_HPP
#define TEXTWIDGET_HPP

#include <QWidget>

class textWidget : public QWidget
{
    Q_OBJECT

   public:
    explicit textWidget(QWidget* parent = 0);

   protected:
    void paintEvent(QPaintEvent* e) override;
};

#endif /* TEXTWIDGET_HPP */
