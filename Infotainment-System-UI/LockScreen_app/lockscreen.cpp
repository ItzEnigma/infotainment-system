#include "lockscreen.h"
#include "ui_lockscreen.h"
#include <QWidget>
#include <QPushButton>
#include<QMessageBox>
#include<QPainter>
#include <QPalette>
#include<QTextDocument>

lockScreen::lockScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lockScreen)
{
    ui->setupUi(this);
    /* ---------- Set up pins signals ---------- */
    /* Pin1 */
    ui->Pin0->setMaxLength(1);
    connect(ui->Pin0, &QLineEdit::textChanged, this,[=](const QString &text) {
    if (text.isEmpty() != true) {
        ui->Pin1->setFocus(Qt::TabFocusReason);
    }});

    /* Pin2 */
    ui->Pin1->setMaxLength(1);
    connect(ui->Pin1, &QLineEdit::textChanged, this,[=](const QString &text) {
        if (text.isEmpty() != true) {
            ui->Pin2->setFocus(Qt::TabFocusReason);
        }
    });

    /* Pin3 */
    ui->Pin2->setMaxLength(1);
    connect(ui->Pin2, &QLineEdit::textChanged, this,[=](const QString &text) {
        if (text.isEmpty() != true) {
            ui->Pin3->setFocus(Qt::TabFocusReason);
        }
    });

    /* Pin4 */
    ui->Pin3->setMaxLength(1);
    connect(ui->Pin3, &QLineEdit::textChanged, this,[=](const QString &text) {

        if (text.isEmpty()!= true) {
            QString str=ui->Pin0->text() + ui->Pin1->text() + ui->Pin2->text() + ui->Pin3->text();
            if(str=="1234")
                QMessageBox::information(this,"Correct","Welcome");
            else
                QMessageBox::information(this,"Wrong","Please,Try again");
        }
    });
}

lockScreen::~lockScreen()
{
    delete ui;
}

void lockScreen::on_Pin0_cursorPositionChanged()
{

}


void lockScreen::on_Pin1_cursorPositionChanged()
{
    
}


void lockScreen::on_Pin2_cursorPositionChanged()
{
    
}


void lockScreen::on_Pin3_cursorPositionChanged()
{
    
}

void lockScreen::on_pushButton_clicked()
{
    QString str=ui->Pin0->text() + ui->Pin1->text() + ui->Pin2->text() + ui->Pin3->text();
    if(str=="1234")
        QMessageBox::information(this,"Correct","Welcome");
    else
        QMessageBox::information(this,"Wrong","Please,Try again");
}

