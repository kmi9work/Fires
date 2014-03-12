#include "fpworth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FPWorth w;
    w.show();

    return a.exec();
}
