#ifndef EXTERNALCLASS_HPP
#define EXTERNALCLASS_HPP

#include <QObject>
#include <QString>

class Backend : public QObject
{
    Q_OBJECT

   public:
    void generateRandom();
   public slots:
    void setContent(QString content);
   signals:
    void contentChanged(QString content);
};

#endif /* EXTERNALCLASS_HPP */
