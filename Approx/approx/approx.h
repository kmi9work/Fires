#ifndef APPROX_H
#define APPROX_H

#include <QMainWindow>

namespace Ui {
class Approx;
}

class Approx : public QMainWindow
{
    Q_OBJECT

public:
    explicit Approx(QWidget *parent = 0);
    ~Approx();

private slots:
    void on_openButton_clicked();

private:
    Ui::Approx *ui;
};

#endif // APPROX_H
