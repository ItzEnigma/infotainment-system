#include "carstatus_app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    carStatus_App w;
    w.showFullScreen();
    w.show();
    return a.exec();
}
