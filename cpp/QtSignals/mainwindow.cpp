#include "mainwindow.h"
#include <QString>
#include <QTextBrowser>
#include <QWidget>
#include <QtCore>
#include <QtGui>
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
    Backend test;
    connect(&test, &Backend::contentChanged, this, &MainWindow::updatePentagonInfo);
    test.generateRandom();
}
