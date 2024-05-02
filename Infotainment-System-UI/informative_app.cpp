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
    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::add_label);
    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::Kernel_info);
    // connect dateTime button to remove_label function
    connect(ui->dateTime, &QPushButton::clicked,this,&Informative_APP::remove_label);
}

Informative_APP::~Informative_APP()
{
    delete ui;
}


void Informative_APP::add_label()
{

    // intializing a pointer points to frame layout  so added labels will have the same layout
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());


    // to clear the screen every time the buttton pressed
    // de-allocate pointers
    delete Name;
    delete line;

    // reintiallize the pointer to access the frame that the labels and lines will be inserted
    Name = new QLabel(ui->frame);
    line = new QFrame(ui->frame);


    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
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


    // shows the label on the window
    layout->insertWidget(0,Name);
    layout->insertWidget(1,line);

}


void Informative_APP::Kernel_info()
{

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());

    // to clear the screen every time the buttton pressed
    // de-allocate pointers
    delete kernel_version;
    delete kernel_update;
    delete line2;
    delete line3;

    // reintiallize the pointers to access the frame that the labels and lines will be inserted
    kernel_version = new QLabel(ui->frame);
    kernel_update = new QLabel(ui->frame);
    line2 = new QFrame(ui->frame);
    line3 = new QFrame(ui->frame);

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
    kernel_version->setStyleSheet("padding-bottom: 20px;");
    kernel_version->setText("<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times, serif; font-weight:bold; \
                            font-size: 24pt;'>Version</span><br> "\
                        "<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:normal; \
                             font-size: 16pt;'>"+ kernelVersion +"</span>");

    // <span> tag --> used to give each line a different style
    //<span> dispalyed word </span>
    // + dateModified  + --> used to print content of the variable "last update time"
    kernel_update->setText("<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times, serif; font-weight:bold; \
            font-size: 24pt;'>Last Update</span><br>"\
        "<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:normal; \
             font-size: 16pt;'>"+ dateModified +"</span>");

    // set frame shape to Horizontal line
    line2->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line2->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line2->setFixedHeight(2);
    // Set line color
    line2->setStyleSheet("background-color: #302A43");

    // set frame shape to Horizontal line
    line3->setFrameShape(QFrame::HLine);
    // set the shadow to sunked"
    line3->setFrameShadow(QFrame::Sunken);
    // set frame hieght to 2pt
    line3->setFixedHeight(2);
    // Set line color
    line3->setStyleSheet("background-color: #302A43");


    // shows the label on the window
    layout->insertWidget(2,kernel_version);
    layout->insertWidget(3,line2);
    layout->insertWidget(4,kernel_update);
    layout->insertWidget(5,line3);


}

void Informative_APP::remove_label()
{
    // hide the labels and lines when another screen is pressed
    Name->hide();
    kernel_version->hide();
    kernel_update->hide();
    line->hide();
    line2->hide();
    line3->hide();
}


