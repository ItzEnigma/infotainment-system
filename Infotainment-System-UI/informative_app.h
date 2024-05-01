#ifndef INFORMATIVE_APP_H
#define INFORMATIVE_APP_H

#include <QMainWindow>
#include <QWidget>
#include <QProcess>
#include<QLabel>
#include<QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class Informative_APP; }
QT_END_NAMESPACE

class Informative_APP : public QMainWindow
{
    Q_OBJECT

public:
    Informative_APP(QWidget *parent = nullptr);
    ~Informative_APP();

    // function to add labels when button pressed
    void add_label();
    // function to remove labels when button pressed
    void remove_label();
    // function to get kernel information
    // display these information in a label when button pressed
    void Kernel_info();

private:
    Ui::Informative_APP *ui;

    // intializing a pointer to process to start a new process
    QProcess *process;

    // allocating pointers make labels
    QLabel *Name = new QLabel();
    QLabel *kernel_version = new QLabel();
    QLabel *kernel_update = new QLabel();

    // allocating pointers make lines
    QFrame *line = new QFrame();
    QFrame *line2 = new QFrame();
    QFrame *line3 = new QFrame();


};
#endif // INFORMATIVE_APP_H
