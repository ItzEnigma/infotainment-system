/********************************************************************************
** Form generated from reading UI file 'lockscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCKSCREEN_H
#define UI_LOCKSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lockScreen
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *lockScreen)
    {
        if (lockScreen->objectName().isEmpty())
            lockScreen->setObjectName(QString::fromUtf8("lockScreen"));
        lockScreen->resize(894, 550);
        lockScreen->setStyleSheet(QString::fromUtf8("background-color: #241F31;"));
        centralwidget = new QWidget(lockScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(296, 48, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 5, 1, 2);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(false);
        lineEdit_3->setFont(font);
        lineEdit_3->setEchoMode(QLineEdit::Password);
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_3, 2, 4, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit, 2, 1, 1, 1);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFont(font);
        lineEdit_4->setEchoMode(QLineEdit::Password);
        lineEdit_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_4, 2, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(297, 48, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 4, 0, 1, 2);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setStyleSheet(QString::fromUtf8("border:transparent;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(858, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout_2->addWidget(frame_3, 1, 0, 1, 7);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setStyleSheet(QString::fromUtf8("border:transparent;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(858, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout_2->addWidget(frame_4, 3, 0, 1, 7);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font-family: Times New Roman;\n"
"font-weight:bold;\n"
"color: rgb(222, 221, 218);\n"
"\n"
"\n"
""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 7);

        horizontalSpacer_5 = new QSpacerItem(165, 88, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setStyleSheet(QString::fromUtf8("border:transparent;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(847, 90, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addWidget(frame_2, 5, 0, 1, 7);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("font-family: Times New Roman;\n"
"font-weight:bold;\n"
"color: rgb(222, 221, 218);\n"
"\n"
"\n"
""));

        gridLayout_2->addWidget(pushButton, 4, 2, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(165, 88, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 6, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_2, 2, 3, 1, 1);

        lockScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(lockScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 894, 22));
        lockScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(lockScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        lockScreen->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton);

        retranslateUi(lockScreen);

        QMetaObject::connectSlotsByName(lockScreen);
    } // setupUi

    void retranslateUi(QMainWindow *lockScreen)
    {
        lockScreen->setWindowTitle(QApplication::translate("lockScreen", "lockScreen", nullptr));
        label->setText(QApplication::translate("lockScreen", "Enter Your Password", nullptr));
        pushButton->setText(QApplication::translate("lockScreen", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lockScreen: public Ui_lockScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCKSCREEN_H
