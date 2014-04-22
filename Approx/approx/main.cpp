#include "approx.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Approx w;
    w.show();

    return a.exec();
}
