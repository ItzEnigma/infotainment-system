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
}

lockScreen::~lockScreen()
{
    delete ui;
}

void lockScreen::on_lineEdit_cursorPositionChanged()
{
    ui->lineEdit->setMaxLength(1);
   connect(ui->lineEdit, &QLineEdit::textChanged, this,[=](const QString text) {
        if (text.isEmpty() != true) {
            ui->lineEdit_2->setFocusPolicy(Qt::TabFocus);
        }
    });
}


void lockScreen::on_lineEdit_2_cursorPositionChanged()
{
    ui->lineEdit_2->setMaxLength(1);
   connect(ui->lineEdit_2, &QLineEdit::textChanged, this,[=](const QString text) {
        if (text.isEmpty() != true) {
            ui->lineEdit_3->setFocusPolicy(Qt::TabFocus);
        }
    });
}


void lockScreen::on_lineEdit_3_cursorPositionChanged()
{
    ui->lineEdit_3->setMaxLength(1);
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this,[=](const QString text) {
        if (text.isEmpty() != true) {
            ui->lineEdit_4->setFocusPolicy(Qt::TabFocus);
        }
    });
}


void lockScreen::on_lineEdit_4_cursorPositionChanged()
{
    ui->lineEdit_4->setMaxLength(1);
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this,[=](const QString text) {

        if (text.isEmpty()!= true) {
            ui->pushButton->setFocusPolicy(Qt::TabFocus);
        }
    });
}

void lockScreen::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text() + ui->lineEdit_2->text() + ui->lineEdit_3->text() + ui->lineEdit_4->text();
    if(str=="1234")
        QMessageBox::information(this,"Correct","Welcome");
    else
        QMessageBox::information(this,"Wrong","Please,Try again");
}

