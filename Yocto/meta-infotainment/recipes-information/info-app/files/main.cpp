#include "informative_app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Informative_APP w;
    w.showFullScreen();
    return a.exec();
}
