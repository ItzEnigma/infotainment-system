#include "carstatus_app.h"
#include "ui_carstatus_app.h"
#include <QWidget>
#include <QBoxLayout>
#include <QFile>
#include <QTimer>
#include <QTextStream>

carStatus_App::carStatus_App(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::carStatus_App)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    // invokes read_temp function when the timer timees out
    connect(timer, &QTimer::timeout, this, &carStatus_App::read_status);
    // timer times out every 100ms
    timer->start(1000);
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
    // Align the label content to the center
    green_temp->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the temerature frame
    green_temp->setSizeIncrement(ui->temp_frame->width(), ui->temp_frame->height());

    // set the path of the blue image to temp variable
    QPixmap temp(":/img/blue_temp.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->temp_frame->width() - 20;
    int h = ui->temp_frame->height() - 20;
    green_temp->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));

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
    // Align the label content to the center
    red_temp->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the temerature frame
    red_temp->setSizeIncrement(ui->temp_frame->width(), ui->temp_frame->height());

    // set the path of the red image to temp variable
    QPixmap temp(":/img/red_temp.png");
    int w = ui->temp_frame->width() - 20;
    int h = ui->temp_frame->height() - 20;
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    red_temp->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));

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
    // Align the label content to the center
    blue_led->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the blue led frame
    blue_led->setSizeIncrement(ui->blue_led_frame->width(), ui->blue_led_frame->height());

    // dispaly the label with the blue led to the blue led frame
    layout->addWidget(blue_led);

    // set the path of the blue image to blue led variable
    QPixmap temp(":/img/blue_led.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->blue_led_frame->width();
    int h = ui->blue_led_frame->height();
    blue_led->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));

    ui->LED2_Status->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
               font-size: 28pt;font-stretch:ultra-condensed;'>" 
                   "LED ON");

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
    // Align the label content to the center
    red_led->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the red led frame
    red_led->setSizeIncrement(ui->red_led_frame->width(), ui->red_led_frame->height());

    // dispaly the label with the red temperature indicator to the temperature frame
    layout->addWidget(red_led);

    // set the path of the blue image to red led variable
    QPixmap temp(":/img/red_led.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->red_led_frame->width();
    int h = ui->red_led_frame->height();
    red_led->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));
    ui->LED1_Status->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
               font-size: 28pt;font-stretch:ultra-condensed;'>" "LED ON");
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
    // Align the label content to the center
    blue_led_off->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the blue led frame
    blue_led_off->setSizeIncrement(ui->blue_led_frame->width(), ui->blue_led_frame->height());

    // dispaly the label with the blue led to the blue led frame
    layout->addWidget(blue_led_off);

    // set the path of the blue image to blue led variable
    QPixmap temp(":/img/blue_led_off.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->blue_led_frame->width();
    int h = ui->blue_led_frame->height();
    blue_led_off->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));

    // dispaly the label with the blue led to the blue led frame
    layout->addWidget(blue_led_off);
    ui->LED2_Status->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
               font-size: 28pt;font-stretch:ultra-condensed;'>" "LED OFF");
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
    // Align the label content to the center
    red_led_off->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the red led frame
    red_led_off->setSizeIncrement(ui->red_led_frame->width(), ui->red_led_frame->height());

    // dispaly the label with the red temperature indicator to the temperature frame
    layout->addWidget(red_led_off);

    // set the path of the blue image to red led variable
    QPixmap temp(":/img/red_led_off.png");
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    int w = ui->red_led_frame->width();
    int h = ui->red_led_frame->height();
    red_led_off->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));
    ui->LED1_Status->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
               font-size: 28pt;font-stretch:ultra-condensed;'>" "LED OFF");
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

void carStatus_App::read_status()
{
    // variable to store the line that have been read from the file
    QString line;
    // variable to store the temperature until it converted to float
    QString temp_data;
    // variable to store the temperature
    float temp;

    /* set the path to the file */
    /* ----- MODIFY THE PATH TO THE TEMPERATURE FILE ----- */
    QString temp_path = "/dev/dio2";

    // set the path to the red and blue leds files
    QString blueLed_path = "/dev/dio0";
    QString redLed_path = "/dev/dio1";
    /* -------------------------------------------------- */

    try
    {
        // check if the file exists
        if (!QFile::exists(temp_path))
        {
            throw 1;
        }

        // open the file
        QFile file(temp_path);

        // open the file to read
        file.open(QIODevice::ReadOnly);

        // Read the file line by line
        QTextStream in(&file);
        line = in.readLine();

        //  convert  the reading into float value
        temp = line.toFloat() / 1000;
        // reconvert the temperature into string for printing
        temp_data = QString::number(temp);

        // display the output on the plainText
        // QChar( 0x00B0) --> to display the temerature degree
        ui->label->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
                       font-size: 36pt;font-stretch:ultra-condensed;'>" +
                           temp_data + ' ' + QChar(0x00B0) + "C");
        // closing the file
        file.close();

        // check if the temperature is high or low
        if (temp < 30)
        {
            remove_img();
            add_Gimg();
        }
        else
        {
            remove_leds();
            add_Rimg();
        }
    }
    catch (int e) // if the file does not exist
    {
        temp = 0;
    }

    /* CHECK IF THE TEMPERATURE IS HIGH OR LOW*/

    try
    {
        if (!QFile::exists(blueLed_path) || !QFile::exists(redLed_path))
        {
            throw 1;
        }

        QFile blueLed_file(blueLed_path);
        QFile redLed_file(redLed_path);

        // Check ownership and permissions
        if (!blueLed_file.open(QIODevice::ReadOnly) || !redLed_file.open(QIODevice::ReadOnly))
        {
            throw 1;
        }

        // check ownership
        if (!blueLed_file.setPermissions(QFileDevice::ReadOwner) || !redLed_file.setPermissions(QFileDevice::ReadOwner))
        {
            throw 1;
        }

        // open the file to read
        // blueLed_file.open(QIODevice::ReadOnly);
        // redLed_file.open(QIODevice::ReadOnly);

        // Read the contents of the file
        QByteArray blueLed_data = blueLed_file.readAll();
        QByteArray redLed_data = redLed_file.readAll();

        // Convert data to string
        QString blueLed_state = QString::fromUtf8(blueLed_data).at(0);
        QString redLed_state = QString::fromUtf8(redLed_data).at(0);

        // removes the "\n" from the end of the string
        // blueLed_state.remove("\n");
        // redLed_state.remove("\n");

        // closing the file files
        blueLed_file.close();
        redLed_file.close();

        if (blueLed_state == "1" && redLed_state == "1")
        {
            remove_leds();
            add_Bled_on();
            add_Rled_on();
        }
        else if (blueLed_state == "0" && redLed_state == "0")
        {
            remove_leds();
            add_Bled_off();
            add_Rled_off();
        }

        else if (blueLed_state == "1" && redLed_state == "0")
        {
            remove_leds();
            add_Rled_off();
            add_Bled_on();
        }
        else if (blueLed_state == "0" && redLed_state == "1")
        {
            remove_leds();
            add_Rled_on();
            add_Bled_off();
        }
    }
    catch (int e)
    {
        remove_leds();
        add_Bled_off();
        add_Rled_off();
    }
}

