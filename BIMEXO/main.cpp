#include "qt_exoskeleton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_exoskeleton w;
    w.show();

    return a.exec();
}
