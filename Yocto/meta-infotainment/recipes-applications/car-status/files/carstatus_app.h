#ifndef CARSTATUS_APP_H
#define CARSTATUS_APP_H

#include <QMainWindow>
#include<QWidget>
#include<QLabel>
#include<QFrame>


QT_BEGIN_NAMESPACE
namespace Ui { class carStatus_App; }
QT_END_NAMESPACE

class carStatus_App : public QMainWindow
{
    Q_OBJECT

public:
    carStatus_App(QWidget *parent = nullptr);
    ~carStatus_App();

    void add_Gimg();
    void add_Rimg();
    void remove_img();

    void add_Bled_on();
    void add_Rled_on();
    void add_Bled_off();
    void add_Rled_off();
    void remove_leds();

    void read_status();


private:
    Ui::carStatus_App *ui;
    QLabel *green_temp = new QLabel();
    QLabel *red_temp = new QLabel();

    QLabel *blue_led = new QLabel();
    QLabel *red_led = new QLabel();
    QLabel *blue_led_off = new QLabel();
    QLabel *red_led_off = new QLabel();
};
#endif // CARSTATUS_APP_H
