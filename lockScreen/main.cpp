#include "lockscreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lockScreen w;
    w.show();
    return a.exec();
}
