#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

 private:
    Ui::MainWindow* ui;
   public slots:
    void updatePentagonInfo(QString);

    public slots:
	void on_start_clicked();
};

#endif  // MAINWINDOW_H
