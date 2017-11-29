#include "mainwindow.h"
#include "backend.hpp"
#include <QString>
#include <QTextBrowser>
#include <QWidget>
#include <QtCore>
#include <QtGui>
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
    Backend test;
    QObject::connect(&test, SIGNAL(contentChanged(content)), this, SLOT(updatePentagonInfo(content)));
    test.generateRandom();
}
