#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "plot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_makePlotButton_clicked();

private:
    Plot *plot;
    QHBoxLayout *layout;
    QVector< QVector<double> > data;
    Ui::MainWindow *ui;
    QStringList readFileToStringList(QString fileName);
};

#endif // MAINWINDOW_H
