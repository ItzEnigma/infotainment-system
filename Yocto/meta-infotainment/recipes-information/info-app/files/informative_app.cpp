#include "informative_app.h"
#include "ui_informative_app.h"
#include<QWidget>
#include<QProcess>
#include<QFileInfo>
#include<QDateTime>
#include<QPixmap>



Informative_APP::Informative_APP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Informative_APP)
{
    ui->setupUi(this);

    // Initializing process
    process = new QProcess(this);

    // connect the information button to add_label and kernel_info functions
    // add_label and kernel_info functions invoked when information button pressed
    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::add_info);
    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::Kernel_info);
    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::settings_img);

    // connect dateTime button to remove_label function
    connect(ui->dateTime, &QPushButton::clicked,this,&Informative_APP::remove_info);
}

Informative_APP::~Informative_APP()
{
    delete ui;
}


void Informative_APP::add_info()
{

    // intializing a pointer points to frame layout  so added labels will have the same layout
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());


    // to clear the screen every time the buttton pressed
    // de-allocate pointers
    delete Name;
    delete VIN;
    delete year;
    delete line;
    delete line2;
    delete line3;

    // reintiallize the pointer to access the frame that the labels and lines will be inserted
    Name = new QLabel(ui->frame);
    VIN = new QLabel(ui->frame);
    year = new QLabel(ui->frame);
    line = new QFrame(ui->frame);
    line2 = new QFrame(ui->frame);
    line3 = new QFrame(ui->frame);




    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
    Name->setStyleSheet("padding-bottom: 10px;");
    Name->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
                        font-size: 24pt;font-stretch:ultra-condensed;'>Name</span><br>\
                    <span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                         font-size: 16pt;'>Sudo Team</span>");

    // set frame shape to Horizontal line
    line->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line->setFixedHeight(2);
    // Set line color
    line->setStyleSheet("background-color: #302A43");

    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
    VIN->setStyleSheet("padding-bottom: 10px;");    
    VIN->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
                        font-size: 24pt;font-stretch:ultra-condensed;'>Vehicle Identification Number</span><br>\
                    <span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                         font-size: 16pt;'>123456789</span>");

    // set frame shape to Horizontal line
    line2->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line2->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line2->setFixedHeight(2);
    // Set line color
    line2->setStyleSheet("background-color: #302A43");

    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
    year->setStyleSheet("padding-bottom: 10px;");    
    year->setText("<span style='color: rgb(246, 245, 244); font-family:  Times New Roman, Times, serif; font-weight:bold; \
                        font-size: 24pt;font-stretch:ultra-condensed;'>Year</span><br>\
                    <span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                         font-size: 16pt;'>2024</span>");

    // set frame shape to Horizontal line
    line3->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line3->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line3->setFixedHeight(2);
    // Set line color
    line3->setStyleSheet("background-color: #302A43");


    // shows the label on the window
    layout->insertWidget(0,Name);
    layout->insertWidget(1,line);

    layout->insertWidget(2,VIN);
    layout->insertWidget(3,line2);
    layout->insertWidget(4,year);
    layout->insertWidget(5,line3);

}


void Informative_APP::Kernel_info()
{

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());

    // to clear the screen every time the buttton pressed
    // de-allocate pointers
    delete kernel_version;
    delete kernel_update;
    delete line4;
    delete line5;

    // reintiallize the pointers to access the frame that the labels and lines will be inserted
    kernel_version = new QLabel(ui->frame);
    kernel_update = new QLabel(ui->frame);
    line4 = new QFrame(ui->frame);
    line5 = new QFrame(ui->frame);

    // retrieve the kernel version
    process->start("uname", QStringList() << "-r");
    process->waitForFinished();

    // Read the output of the command
    QString kernelVersion = process->readAllStandardOutput();
    // remove leading and trailing spaces
    kernelVersion = kernelVersion.trimmed();

    // Get the path of the kernel image file
    QString kernelPath = "/boot/vmlinuz-" + kernelVersion;

    // extract kernel information from the current kernel version
    QFileInfo kernelInfo(kernelPath);
    // extract the last time kernel have been updated
    QDateTime modificationDate = kernelInfo.lastModified();
    // convert date extracted to a string
    QString dateModified = modificationDate.toString();

    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
    // + kernelVersion  + --> used to print content of the variable "kernel version"
    kernel_version->setStyleSheet("padding-bottom: 10px;");
    kernel_version->setText("<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times, serif; font-weight:bold; \
                            font-size: 24pt;'>Version</span><br> "\
                        "<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                         font-size: 16pt;'>"+ kernelVersion +"</span>");

    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
    // + dateModified  + --> used to print content of the variable "last update time"
    kernel_update->setStyleSheet("padding-bottom: 10px;");
    kernel_update->setText("<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times, serif; font-weight:bold; \
            font-size: 24pt;'>Last Update</span><br>"\
        "<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                         font-size: 16pt;'>"+ dateModified +"</span>");

    // set frame shape to Horizontal line
    line4->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line4->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line4->setFixedHeight(2);
    // Set line color
    line4->setStyleSheet("background-color: #302A43");

    // set frame shape to Horizontal line
    line5->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line5->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line5->setFixedHeight(2);
    // Set line color
    line5->setStyleSheet("background-color: #302A43");


    // shows the label on the window
    layout->insertWidget(6,kernel_version);
    layout->insertWidget(7,line4);
    layout->insertWidget(8,kernel_update);
    layout->insertWidget(9,line5);


}

void Informative_APP::settings_img()
{

    // Intializes a vertical layout to the temperature frame
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->settings->layout());

    /*delete the image when the function starts to save memory */
    delete settings;
    // creating new label in the temperature frame...so the image set in it
    settings = new QLabel(ui->settings);
    // Align the label content to the center
    settings->setAlignment(Qt::AlignCenter);
    // set the size of the label to the size  of the temerature frame
    settings->setSizeIncrement(ui->settings->width()-50, ui->settings->height()-50);

    // set the path of the red image to temp variable
    QPixmap temp(":/img/img/settings.png");
    int w = ui->settings->width()-20;
    int h = ui->settings->height()-20;
    // set the the hieght and width of the image to the hieght and width of the frame
    // KeepAspectRation -->  to show the full  image
    settings->setPixmap(temp.scaled(w, h, Qt::KeepAspectRatio));

    // dispaly the label with the red temperature indicator to the temperature frame
    layout->addWidget(settings);

    // delete the layout...so it can be remade

}


void Informative_APP::remove_info()
{
    // hide the labels and lines when another screen is pressed
    Name->hide();
    VIN->hide();
    year->hide();
    kernel_version->hide();
    kernel_update->hide();
    line->hide();
    line2->hide();
    line3->hide();
    line4->hide();
    line5->hide();
    settings->hide();
}


