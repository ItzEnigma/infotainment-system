#ifndef CARSTATUS_APP_H
#define CARSTATUS_APP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class carStatus_App; }
QT_END_NAMESPACE

class carStatus_App : public QMainWindow
{
    Q_OBJECT

public:
    carStatus_App(QWidget *parent = nullptr);
    ~carStatus_App();

private:
    Ui::carStatus_App *ui;
};
#endif // CARSTATUS_APP_H
