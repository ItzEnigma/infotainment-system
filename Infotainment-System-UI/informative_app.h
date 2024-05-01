#ifndef INFORMATIVE_APP_H
#define INFORMATIVE_APP_H

#include <QMainWindow>
#include <QWidget>
#include <QProcess>
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Informative_APP; }
QT_END_NAMESPACE

class Informative_APP : public QMainWindow
{
    Q_OBJECT

public:
    Informative_APP(QWidget *parent = nullptr);
    ~Informative_APP();

    void add_label();
    void remove_label();
    void Kernel_info();

private:
    Ui::Informative_APP *ui;
    QProcess *process;
    QLabel *Name;
    QLabel *kernel_version;
    QLabel *kernel_update;


};
#endif // INFORMATIVE_APP_H
