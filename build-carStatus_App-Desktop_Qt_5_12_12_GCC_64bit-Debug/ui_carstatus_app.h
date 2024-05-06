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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_carStatus_App
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QFrame *frame;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *LED1_HorzLayout;
    QFrame *LED2_Icon;
    QSpacerItem *horizontalSpacer_4;
    QLabel *LED1_Status;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *LED2_HorzLayout;
    QFrame *LED1_Icon;
    QSpacerItem *horizontalSpacer_5;
    QLabel *LED2_Status;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *carStatus_App)
    {
        if (carStatus_App->objectName().isEmpty())
            carStatus_App->setObjectName(QString::fromUtf8("carStatus_App"));
        carStatus_App->resize(1295, 564);
        carStatus_App->setMinimumSize(QSize(960, 480));
        carStatus_App->setMaximumSize(QSize(1920, 1080));
        carStatus_App->setStyleSheet(QString::fromUtf8("background-color: #241F31;"));
        centralwidget = new QWidget(carStatus_App);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
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

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(40, 120, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(120, 50));
        label->setMaximumSize(QSize(16777215, 200));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 4, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(240, 240));
        frame->setStyleSheet(QString::fromUtf8("border:transparent;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_6 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        LED1_HorzLayout = new QHBoxLayout();
        LED1_HorzLayout->setObjectName(QString::fromUtf8("LED1_HorzLayout"));
        LED2_Icon = new QFrame(centralwidget);
        LED2_Icon->setObjectName(QString::fromUtf8("LED2_Icon"));
        LED2_Icon->setMinimumSize(QSize(160, 160));
        LED2_Icon->setFrameShape(QFrame::StyledPanel);
        LED2_Icon->setFrameShadow(QFrame::Raised);

        LED1_HorzLayout->addWidget(LED2_Icon);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        LED1_HorzLayout->addItem(horizontalSpacer_4);

        LED1_Status = new QLabel(centralwidget);
        LED1_Status->setObjectName(QString::fromUtf8("LED1_Status"));
        LED1_Status->setMinimumSize(QSize(80, 50));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        LED1_Status->setFont(font2);
        LED1_Status->setAlignment(Qt::AlignCenter);

        LED1_HorzLayout->addWidget(LED1_Status);


        verticalLayout->addLayout(LED1_HorzLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        LED2_HorzLayout = new QHBoxLayout();
        LED2_HorzLayout->setObjectName(QString::fromUtf8("LED2_HorzLayout"));
        LED1_Icon = new QFrame(centralwidget);
        LED1_Icon->setObjectName(QString::fromUtf8("LED1_Icon"));
        LED1_Icon->setMinimumSize(QSize(160, 160));
        LED1_Icon->setFrameShape(QFrame::StyledPanel);
        LED1_Icon->setFrameShadow(QFrame::Raised);

        LED2_HorzLayout->addWidget(LED1_Icon);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        LED2_HorzLayout->addItem(horizontalSpacer_5);

        LED2_Status = new QLabel(centralwidget);
        LED2_Status->setObjectName(QString::fromUtf8("LED2_Status"));
        LED2_Status->setMinimumSize(QSize(80, 50));
        LED2_Status->setFont(font2);
        LED2_Status->setAlignment(Qt::AlignCenter);

        LED2_HorzLayout->addWidget(LED2_Status);


        verticalLayout->addLayout(LED2_HorzLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout);

        carStatus_App->setCentralWidget(centralwidget);
        menubar = new QMenuBar(carStatus_App);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1295, 22));
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
        LED1_Status->setText(QApplication::translate("carStatus_App", "LED ON", nullptr));
        LED2_Status->setText(QApplication::translate("carStatus_App", "LED OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class carStatus_App: public Ui_carStatus_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARSTATUS_APP_H
