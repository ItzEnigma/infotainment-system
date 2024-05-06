#include "carstatus_app.h"
#include "ui_carstatus_app.h"
#include<QWidget>
#include<QBoxLayout>
#include<QFile>
#include<QTimer>




carStatus_App::carStatus_App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::carStatus_App)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&carStatus_App::read_temp);
    timer->start(100);
}

carStatus_App::~carStatus_App()
{
    delete ui;
}

void carStatus_App::add_Gimg()
{

    QVBoxLayout *layout = new QVBoxLayout(ui->frame);

    green_temp->hide();
    delete green_temp;
    green_temp = new QLabel(ui->frame);
    green_temp->setAlignment(Qt::AlignCenter);
    green_temp->setSizeIncrement(ui->frame->width(),ui->frame->height());
    layout->addWidget(green_temp);

    QPixmap temp(":/img/img/blue_temp.png");
    int w = ui->frame->width()-20;
    int h = ui->frame->height()-20;
    green_temp->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    delete layout;
}

void carStatus_App::add_Rimg()
{

    QVBoxLayout *layout = new QVBoxLayout(ui->frame);

    red_temp->hide();
    delete red_temp;
    red_temp = new QLabel(ui->frame);
    red_temp->setAlignment(Qt::AlignCenter);
    red_temp->setSizeIncrement(ui->frame->width(),ui->frame->height());
    layout->addWidget(red_temp);

    QPixmap temp(":/img/img/red_temp.png");
    int w = ui->frame->width()-20;
    int h = ui->frame->height()-20;
    red_temp->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    delete layout;
}

void carStatus_App::remove_img()
{
    green_temp->hide();
    red_temp->hide();
}



void carStatus_App::add_Bled()
{

    QVBoxLayout *layout = new QVBoxLayout(ui->LED1_Icon);

    blue_led->hide();
    delete blue_led;
    blue_led = new QLabel(ui->LED1_Icon);
    blue_led->setAlignment(Qt::AlignCenter);
    blue_led->setSizeIncrement(ui->LED1_Icon->width(),ui->LED1_Icon->height());
    layout->addWidget(blue_led);

    QPixmap temp(":/img/img/blue led.png");
    int w = ui->LED1_Icon->width();
    int h = ui->LED1_Icon->height();
    blue_led->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    delete layout;
}

void carStatus_App::add_Rled()
{

    QVBoxLayout *layout = new QVBoxLayout(ui->LED2_Icon);

    red_led->hide();
    delete red_led;
    red_led = new QLabel(ui->LED2_Icon);
    red_led->setAlignment(Qt::AlignCenter);
    red_led->setSizeIncrement(ui->LED2_Icon->width(),ui->LED2_Icon->height());
    layout->addWidget(red_led);

    QPixmap temp(":/img/img/red led.png");
    int w = ui->LED2_Icon->width();
    int h = ui->LED2_Icon->height();
    red_led->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    delete layout;
}

void carStatus_App::remove_leds()
{
    blue_led->hide();
    red_led->hide();

}


void carStatus_App::read_temp()
{
   // variable to store the temperature
    int temp;

    //set the path to the file
    QFile file("/sys/class/leds/input2::capslock/brightness");

    // open tthe file to read
    file.open(QIODevice::ReadOnly);

    // Read the contents of the file
    QByteArray data = file.readAll();

    // Convert data to string
    QString text = QString::fromUtf8(data);
    // removes the "\n" from the end of the string
    text.replace("\n"," ");




    // display the output on the plainText
    // QChar( 0x00B0) --> to display the temerature degree
    ui->label->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
                       font-size: 28pt;font-stretch:ultra-condensed;'>"+ text +QChar( 0x00B0) +"C" );
    // closing the file
    file.close();


    //  convert  the readint into integer value
    temp = text.toInt();


    add_Bled();
    add_Rled();
    if (temp == 0)
    {
        carStatus_App::remove_img();
        carStatus_App::add_Gimg();
    }
    else
    {
        carStatus_App::remove_img();
        carStatus_App::add_Rimg();
    }
}



