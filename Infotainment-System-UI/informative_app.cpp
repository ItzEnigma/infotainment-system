#include "informative_app.h"
#include "ui_informative_app.h"
#include<QWidget>
#include<QProcess>
#include<QFileInfo>
#include<QDateTime>



Informative_APP::Informative_APP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Informative_APP)
{
    ui->setupUi(this);
    // Initializing process
    process = new QProcess(this);

    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::add_label);
    connect(ui->information, &QPushButton::clicked,this,&Informative_APP::Kernel_info);
    connect(ui->dateTime, &QPushButton::clicked,this,&Informative_APP::remove_label);
}

Informative_APP::~Informative_APP()
{
    delete ui;
}


void Informative_APP::add_label()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());

    delete Name;

    Name = new QLabel(ui->frame);
    Name->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //Name->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);
    Name->setText("<span style='color: rgb(246, 245, 244); font-family:  CCS Neue Rinjani, Times, serif; font-weight:bold; \
                        font-size: 24pt;font-stretch:ultra-condensed;'>Name</span><br>\
                    <span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                         font-size: 16pt;'>Sudo Team</span>");

    // shows the label on the window
    layout->insertWidget(0,Name);

}


void Informative_APP::Kernel_info()
{

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->frame->layout());

    delete kernel_version;
    delete kernel_update;

    kernel_version = new QLabel(ui->frame);
    kernel_update = new QLabel(ui->frame);


    // retrieve the kernel version
    process->start("uname", QStringList() << "-r");
    process->waitForFinished();

    // Read the output of the command
    QString kernelVersion = process->readAllStandardOutput();
    // remove leading and trailing spaces
    kernelVersion = kernelVersion.trimmed();

    // Get the path of the kernel image file
    QString kernelPath = "/boot/vmlinuz-" + kernelVersion;

    // Check if the kernel image file exists
    QFileInfo kernelInfo(kernelPath);
    QDateTime modificationDate = kernelInfo.lastModified();
    QString dateModified = modificationDate.toString();


    kernel_version->setText("<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times, serif; font-weight:bold; \
                            font-size: 24pt;'>Version</span><br>"\
                        "<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
                             font-size: 16pt;'>"+ kernelVersion +"</span>");

    kernel_update->setText("<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times, serif; font-weight:bold; \
            font-size: 24pt;'>Last Update</span><br>"\
        "<span style='color: rgb(246, 245, 244);font-family:  Times New Roman, Times,sans-serif; font-weight:bold; \
             font-size: 16pt;'>"+ dateModified +"</span>");


    // shows the label on the window
    layout->insertWidget(1,kernel_version);
    layout->insertWidget(2,kernel_update);

}


void Informative_APP::remove_label()
{
    Name->hide();
    kernel_version->hide();
    kernel_update->hide();
}
