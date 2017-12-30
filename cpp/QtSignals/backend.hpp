#ifndef EXTERNALCLASS_HPP
#define EXTERNALCLASS_HPP

#include <QObject>
#include <QCoreApplication>
#include <QString>

class Backend : public QObject
{
    Q_OBJECT

   public:
    void generateRandom();
   signals:
    void contentChanged(QString content);
};

#endif /* EXTERNALCLASS_HPP */
