/********************************************************************************
** Form generated from reading UI file 'carstatus_app.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARSTATUS_APP_H
#define UI_CARSTATUS_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_carStatus_App
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *carStatus_App)
    {
        if (carStatus_App->objectName().isEmpty())
            carStatus_App->setObjectName(QString::fromUtf8("carStatus_App"));
        carStatus_App->resize(763, 455);
        carStatus_App->setStyleSheet(QString::fromUtf8("background-color: #241F31;"));
        centralwidget = new QWidget(carStatus_App);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(210, 210, 71, 71));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("border:transparent;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 9, 751, 65));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font-family: Times New Roman;\n"
"font-weight:bold;\n"
"color: rgb(222, 221, 218);\n"
"margin-top:5px;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 210, 371, 51));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        carStatus_App->setCentralWidget(centralwidget);
        menubar = new QMenuBar(carStatus_App);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 763, 22));
        carStatus_App->setMenuBar(menubar);
        statusbar = new QStatusBar(carStatus_App);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        carStatus_App->setStatusBar(statusbar);

        retranslateUi(carStatus_App);

        QMetaObject::connectSlotsByName(carStatus_App);
    } // setupUi

    void retranslateUi(QMainWindow *carStatus_App)
    {
        carStatus_App->setWindowTitle(QApplication::translate("carStatus_App", "carStatus_App", nullptr));
        label_2->setText(QApplication::translate("carStatus_App", "Temperature Panel", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class carStatus_App: public Ui_carStatus_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSTATUS_APP_H
