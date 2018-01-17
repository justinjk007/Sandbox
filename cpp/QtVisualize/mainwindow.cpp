#include "mainwindow.h"
#include <QString>
#include <QTextBrowser>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
