#include "qduino.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qduino w;
    w.show();

    return a.exec();
}
