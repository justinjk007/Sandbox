#include "mainwindow.h"
#include <QString>
#include <QTextBrowser>
#include <QWidget>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePentagonInfo(const QString& content)
{
    /**
     * This method updates information about the pentagon in the text
     * browser on the top right of the main program window
     */
    QWidget* pentagon_info = new QWidget;  // Initialize using name of widget from the form
    QTextBrowser::QTextBrowser(pentagon_info);
    ui->pentagon_info->append(content);
    delete pentagon_info;
}
