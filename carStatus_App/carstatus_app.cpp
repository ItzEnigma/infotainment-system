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
    // invokes read_temp function when the timer timees out
    connect(timer,&QTimer::timeout,this,&carStatus_App::read_temp);
    // timer times out every 100ms
    timer->start(100);
}

carStatus_App::~carStatus_App()
{
    delete ui;
}


/* function that creates a new label and add the BLUE temperature indictor to the screen*/
void carStatus_App::add_Gimg()
{
    // Intializes a vertical layout to the temperature frame
    QVBoxLayout *layout = new QVBoxLayout(ui->temp_frame);

   /*delete the image when the function starts to save memory */
    green_temp->hide();
    delete green_temp;
    // creating new label in the temperature frame...so the image set in it
    green_temp = new QLabel(ui->temp_frame);
    //Align the label content to the center
    green_temp->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the temerature frame
    green_temp->setSizeIncrement(ui->temp_frame->width(),ui->temp_frame->height());

    // set the path of the blue image to temp variable
    QPixmap temp(":/img/img/blue_temp.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->temp_frame->width()-20;
    int h = ui->temp_frame->height()-20;
    green_temp->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    // dispaly the label with the blue temperature indicator to the temperature frame
    layout->addWidget(green_temp);

    // delete the layout...so it can be remade
    delete layout;
}

/* function that creates a new label and add the RED temperature indictor to the screen*/
void carStatus_App::add_Rimg()
{

    // Intializes a vertical layout to the temperature frame
    QVBoxLayout *layout = new QVBoxLayout(ui->temp_frame);

    /*delete the image when the function starts to save memory */
    red_temp->hide();
    delete red_temp;
    // creating new label in the temperature frame...so the image set in it
    red_temp = new QLabel(ui->temp_frame);
    //Align the label content to the center
    red_temp->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the temerature frame
    red_temp->setSizeIncrement(ui->temp_frame->width(),ui->temp_frame->height());

    // set the path of the red image to temp variable
    QPixmap temp(":/img/img/red_temp.png");
    int w = ui->temp_frame->width()-20;
    int h = ui->temp_frame->height()-20;
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    red_temp->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    // dispaly the label with the red temperature indicator to the temperature frame
    layout->addWidget(red_temp);

    // delete the layout...so it can be remade
    delete layout;
}


/* function that removes the temerature indicators */
void carStatus_App::remove_img()
{
    green_temp->hide();
    red_temp->hide();
}


/* funtction that adds the blue led */
void carStatus_App::add_Bled_on()
{

    // Intializes a vertical layout to the blue led frame
    QVBoxLayout *layout = new QVBoxLayout(ui->blue_led_frame);

    /*delete the image when the function starts to save memory */
    blue_led->hide();
    delete blue_led;

    // creating new label in the red led frame...so the image set in it
    blue_led = new QLabel(ui->blue_led_frame);
    //Align the label content to the center
    blue_led->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the blue led frame
    blue_led->setSizeIncrement(ui->blue_led_frame->width(),ui->blue_led_frame->height());
	
    // dispaly the label with the blue led to the blue led frame
    layout->addWidget(blue_led);

    // set the path of the blue image to blue led variable
    QPixmap temp(":/img/img/blue led.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->blue_led_frame->width();
    int h = ui->blue_led_frame->height();
    blue_led->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));


    delete layout;
}

void carStatus_App::add_Rled_on()
{

    // Intializes a vertical layout to the red led frame
    QVBoxLayout *layout = new QVBoxLayout(ui->red_led_frame);

    /*delete the image when the function starts to save memory */
    red_led->hide();
    delete red_led;

    // creating new label in the red led frame...so the image set in it
    red_led = new QLabel(ui->red_led_frame);
    //Align the label content to the center
    red_led->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the red led frame
    red_led->setSizeIncrement(ui->red_led_frame->width(),ui->red_led_frame->height());

    // dispaly the label with the red temperature indicator to the temperature frame
    layout->addWidget(red_led);

    // set the path of the blue image to red led variable
    QPixmap temp(":/img/img/red led.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->red_led_frame->width();
    int h = ui->red_led_frame->height();
    red_led->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));


    // delete the layout...so it can be remade
    delete layout;
}


void carStatus_App::add_Bled_off()
{

    // Intializes a vertical layout to the blue led frame
    QVBoxLayout *layout = new QVBoxLayout(ui->blue_led_frame);

    /*delete the image when the function starts to save memory */
    blue_led_off->hide();
    delete blue_led_off;

    // creating new label in the red led frame...so the image set in it
    blue_led_off = new QLabel(ui->blue_led_frame);
    //Align the label content to the center
    blue_led_off->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the blue led frame
    blue_led_off->setSizeIncrement(ui->blue_led_frame->width(),ui->blue_led_frame->height());

    // dispaly the label with the blue led to the blue led frame
    layout->addWidget(blue_led_off);
    
    // set the path of the blue image to blue led variable
    QPixmap temp(":/img/img/blue led off.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->blue_led_frame->width();
    int h = ui->blue_led_frame->height();
    blue_led_off->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));

    // dispaly the label with the blue led to the blue led frame
    layout->addWidget(blue_led_off);

    delete layout;
}

void carStatus_App::add_Rled_off()
{

    // Intializes a vertical layout to the red led frame
    QVBoxLayout *layout = new QVBoxLayout(ui->red_led_frame);

    /*delete the image when the function starts to save memory */
    red_led_off->hide();
    delete red_led_off;

    // creating new label in the red led frame...so the image set in it
    red_led_off = new QLabel(ui->red_led_frame);
    //Align the label content to the center
    red_led_off->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the red led frame
    red_led_off->setSizeIncrement(ui->red_led_frame->width(),ui->red_led_frame->height());

    // dispaly the label with the red temperature indicator to the temperature frame
    layout->addWidget(red_led_off);

    // set the path of the blue image to red led variable
    QPixmap temp(":/img/img/red ledoff.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->red_led_frame->width();
    int h = ui->red_led_frame->height();
    red_led_off->setPixmap(temp.scaled(w,h,Qt::KeepAspectRatio));


    // delete the layout...so it can be remade
    delete layout;
}

void carStatus_App::remove_leds()
{
    red_led->hide();
    red_led_off->hide();
    blue_led->hide();
    blue_led_off->hide();
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
                       font-size: 36pt;font-stretch:ultra-condensed;'>"+ text +QChar( 0x00B0) +"C" );
    // closing the file
    file.close();


    //  convert  the readint into integer value
    temp = text.toInt();





    /* CHECK IF THE TEMPERATURE IS HIGH OR LOW*/
    if (temp == 0)
    {
        remove_img();
        remove_leds();
        add_Gimg();
        add_Bled_on();
        add_Rled_off();
    }
    else
    {
        remove_img();
        remove_leds();
        add_Rimg();
        add_Bled_off();
        add_Rled_on();
    }
}


