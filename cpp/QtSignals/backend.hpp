#ifndef EXTERNALCLASS_HPP
#define EXTERNALCLASS_HPP

#include <QObject>
#include <QCoreApplication>
#include <QString>
#include <QThread>

class Backend : public QThread
{
    Q_OBJECT

   public:
    void run();
   signals:
    void contentChanged(QString content);
};

#endif /* EXTERNALCLASS_HPP */
