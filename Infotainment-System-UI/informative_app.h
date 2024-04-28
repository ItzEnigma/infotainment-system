#ifndef INFORMATIVE_APP_H
#define INFORMATIVE_APP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Informative_APP;
}
QT_END_NAMESPACE

class Informative_APP : public QMainWindow
{
    Q_OBJECT

public:
    Informative_APP(QWidget *parent = nullptr);
    ~Informative_APP();

private:
    Ui::Informative_APP *ui;
};
#endif // INFORMATIVE_APP_H
