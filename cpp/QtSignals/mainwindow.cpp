#include "mainwindow.h"
#include <QString>
#include <QTextBrowser>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QThread>
#include <thread>
#include "backend.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePentagonInfo(QString content)
{
    /**
     * This method updates information about the pentagon in the text
     * browser on the top right of the main program window. Appending
     * whatever is given as the argument
     */
    ui->browser->append(content);
}

void MainWindow::on_start_clicked()
{
    QThread* worker_thread = new QThread;
    Backend* test = new Backend();
    test->moveToThread(worker_thread);
    connect(test, &Backend::contentChanged, this, &MainWindow::updatePentagonInfo);
    connect(worker_thread, SIGNAL(started()), test, SLOT(process()));
    connect(test, SIGNAL(finished()), worker_thread, SLOT(quit()));
    connect(test, SIGNAL(finished()), test, SLOT(deleteLater()));
    connect(worker_thread, SIGNAL(finished()), worker_thread, SLOT(deleteLater()));
    // Add other needed signals from here https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
    qDebug("Threads created and signals connected");
    worker_thread->start();
    qDebug("Thead started");
}
