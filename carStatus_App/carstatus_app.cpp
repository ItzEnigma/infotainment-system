#include "carstatus_app.h"
#include "ui_carstatus_app.h"
#include<QWidget>
#include<QBoxLayout>
#include<QFile>
#include<QTimer>
#include<QDebug>



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



    QPixmap temp(":/img/img/car.png");
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



    QPixmap temp(":/img/thermometer.png");
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


void carStatus_App::read_temp()
{
    QFile file("/sys/class/leds/input2::capslock/brightness");
    file.open(QIODevice::ReadOnly);


    // Read the contents of the file
    QByteArray data = file.readAll();

    // Convert data to string
    QString text = QString::fromUtf8(data);
    // removes the "\n" from the end of the string
    text.replace("\n"," ");
    // display the output on the plainText
    ui->label->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
                       font-size: 28pt;font-stretch:ultra-condensed;'>"+ text +QChar( 0x00B0) +"C" );
    file.close();
    text.remove(" ");
    if (text == "0")
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
