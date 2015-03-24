/********************************************************************************
** Form generated from reading UI file 'qt_exoskeleton.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_EXOSKELETON_H
#define UI_QT_EXOSKELETON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_qt_exoskeleton
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_left_hip;
    QGridLayout *gridLayout;
    QLabel *label_left_hip_extension;
    QLineEdit *lineEdit_left_hip_extension;
    QLabel *label_left_hip_flexion;
    QLineEdit *lineEdit_left_hip_flexion;
    QGroupBox *groupBox_left_knee;
    QGridLayout *gridLayout_4;
    QLabel *label_left_hip_extension_4;
    QLineEdit *lineEdit_left_knee_extension;
    QLabel *label_left_hip_flexion_4;
    QLineEdit *lineEdit_left_knee_flexion;
    QGridLayout *gridLayout_8;
    QLabel *img_human_leg;
    QwtPlot *qwtPlot;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_right_hip;
    QGridLayout *gridLayout_3;
    QLabel *label_left_hip_extension_2;
    QLineEdit *lineEdit_right_hip_extension;
    QLabel *label_left_hip_flexion_2;
    QLineEdit *lineEdit_right_hip_flexion;
    QGroupBox *groupBox_right_knee;
    QGridLayout *gridLayout_5;
    QLabel *label_left_hip_extension_3;
    QLineEdit *lineEdit_right_knee_extension;
    QLabel *label_left_hip_flexion_3;
    QLineEdit *lineEdit_right_knee_flexion;
    QWidget *tab_2;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_16;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_calibration;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_enable;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_10;
    QLCDNumber *lcdNumber_right_knee_velocity;
    QLCDNumber *lcdNumber_left_hip_velocity;
    QLCDNumber *lcdNumber_left_hip_current;
    QLCDNumber *lcdNumber_right_hip_velocity;
    QLabel *label_left_hip_status;
    QLabel *label_left_hip_connection;
    QLabel *label_left_hip;
    QLabel *label_left_knee;
    QLabel *label_right_hip;
    QLabel *label_right_knee;
    QLCDNumber *lcdNumber_left_knee_velocity;
    QLabel *label_right_hip_connection;
    QLabel *label_right_hip_status;
    QLabel *label_left_knee_connection;
    QLabel *label_left_knee_status;
    QLabel *label_right_knee_connection;
    QLabel *label_right_knee_status;
    QLCDNumber *lcdNumber_left_knee_current;
    QLCDNumber *lcdNumber_right_knee_current;
    QLCDNumber *lcdNumber_left_hip_position;
    QLCDNumber *lcdNumber_right_hip_current;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_24;
    QLabel *label_15;
    QLabel *label_14;
    QLCDNumber *lcdNumber_right_hip_position;
    QLCDNumber *lcdNumber_left_knee_positio;
    QLCDNumber *lcdNumber_right_knee_position;
    QLabel *label_name;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_exoskeleton)
    {
        if (qt_exoskeleton->objectName().isEmpty())
            qt_exoskeleton->setObjectName(QStringLiteral("qt_exoskeleton"));
        qt_exoskeleton->resize(749, 703);
        centralWidget = new QWidget(qt_exoskeleton);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_9 = new QGridLayout(tab);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_left_hip = new QGroupBox(tab);
        groupBox_left_hip->setObjectName(QStringLiteral("groupBox_left_hip"));
        groupBox_left_hip->setMaximumSize(QSize(220, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(141, 255, 47, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(211, 255, 175, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(176, 255, 111, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(70, 127, 23, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(94, 170, 31, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(198, 255, 151, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        groupBox_left_hip->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        groupBox_left_hip->setFont(font);
        groupBox_left_hip->setFlat(false);
        groupBox_left_hip->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_left_hip);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_left_hip_extension = new QLabel(groupBox_left_hip);
        label_left_hip_extension->setObjectName(QStringLiteral("label_left_hip_extension"));
        label_left_hip_extension->setFont(font);

        gridLayout->addWidget(label_left_hip_extension, 0, 0, 1, 1);

        lineEdit_left_hip_extension = new QLineEdit(groupBox_left_hip);
        lineEdit_left_hip_extension->setObjectName(QStringLiteral("lineEdit_left_hip_extension"));
        lineEdit_left_hip_extension->setFont(font);

        gridLayout->addWidget(lineEdit_left_hip_extension, 1, 0, 1, 1);

        label_left_hip_flexion = new QLabel(groupBox_left_hip);
        label_left_hip_flexion->setObjectName(QStringLiteral("label_left_hip_flexion"));
        label_left_hip_flexion->setFont(font);

        gridLayout->addWidget(label_left_hip_flexion, 2, 0, 1, 1);

        lineEdit_left_hip_flexion = new QLineEdit(groupBox_left_hip);
        lineEdit_left_hip_flexion->setObjectName(QStringLiteral("lineEdit_left_hip_flexion"));
        lineEdit_left_hip_flexion->setFont(font);

        gridLayout->addWidget(lineEdit_left_hip_flexion, 3, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_left_hip, 0, 0, 1, 1);

        groupBox_left_knee = new QGroupBox(tab);
        groupBox_left_knee->setObjectName(QStringLiteral("groupBox_left_knee"));
        groupBox_left_knee->setMaximumSize(QSize(220, 16777215));
        groupBox_left_knee->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_left_knee);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_left_hip_extension_4 = new QLabel(groupBox_left_knee);
        label_left_hip_extension_4->setObjectName(QStringLiteral("label_left_hip_extension_4"));
        label_left_hip_extension_4->setFont(font);

        gridLayout_4->addWidget(label_left_hip_extension_4, 0, 0, 1, 1);

        lineEdit_left_knee_extension = new QLineEdit(groupBox_left_knee);
        lineEdit_left_knee_extension->setObjectName(QStringLiteral("lineEdit_left_knee_extension"));
        lineEdit_left_knee_extension->setFont(font);

        gridLayout_4->addWidget(lineEdit_left_knee_extension, 1, 0, 1, 1);

        label_left_hip_flexion_4 = new QLabel(groupBox_left_knee);
        label_left_hip_flexion_4->setObjectName(QStringLiteral("label_left_hip_flexion_4"));
        label_left_hip_flexion_4->setFont(font);

        gridLayout_4->addWidget(label_left_hip_flexion_4, 2, 0, 1, 1);

        lineEdit_left_knee_flexion = new QLineEdit(groupBox_left_knee);
        lineEdit_left_knee_flexion->setObjectName(QStringLiteral("lineEdit_left_knee_flexion"));
        lineEdit_left_knee_flexion->setFont(font);

        gridLayout_4->addWidget(lineEdit_left_knee_flexion, 3, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_left_knee, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        img_human_leg = new QLabel(tab);
        img_human_leg->setObjectName(QStringLiteral("img_human_leg"));
        img_human_leg->setPixmap(QPixmap(QString::fromUtf8("humanleg.jpg")));
        img_human_leg->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(img_human_leg, 0, 0, 1, 1);

        qwtPlot = new QwtPlot(tab);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));

        gridLayout_8->addWidget(qwtPlot, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 1, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_right_hip = new QGroupBox(tab);
        groupBox_right_hip->setObjectName(QStringLiteral("groupBox_right_hip"));
        groupBox_right_hip->setMaximumSize(QSize(220, 16777215));
        groupBox_right_hip->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_right_hip);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_left_hip_extension_2 = new QLabel(groupBox_right_hip);
        label_left_hip_extension_2->setObjectName(QStringLiteral("label_left_hip_extension_2"));
        label_left_hip_extension_2->setMaximumSize(QSize(225, 16777215));
        label_left_hip_extension_2->setFont(font);

        gridLayout_3->addWidget(label_left_hip_extension_2, 0, 0, 1, 1);

        lineEdit_right_hip_extension = new QLineEdit(groupBox_right_hip);
        lineEdit_right_hip_extension->setObjectName(QStringLiteral("lineEdit_right_hip_extension"));
        lineEdit_right_hip_extension->setFont(font);

        gridLayout_3->addWidget(lineEdit_right_hip_extension, 1, 0, 1, 1);

        label_left_hip_flexion_2 = new QLabel(groupBox_right_hip);
        label_left_hip_flexion_2->setObjectName(QStringLiteral("label_left_hip_flexion_2"));
        label_left_hip_flexion_2->setFont(font);

        gridLayout_3->addWidget(label_left_hip_flexion_2, 2, 0, 1, 1);

        lineEdit_right_hip_flexion = new QLineEdit(groupBox_right_hip);
        lineEdit_right_hip_flexion->setObjectName(QStringLiteral("lineEdit_right_hip_flexion"));
        lineEdit_right_hip_flexion->setFont(font);

        gridLayout_3->addWidget(lineEdit_right_hip_flexion, 3, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_right_hip, 0, 0, 1, 1);

        groupBox_right_knee = new QGroupBox(tab);
        groupBox_right_knee->setObjectName(QStringLiteral("groupBox_right_knee"));
        groupBox_right_knee->setMaximumSize(QSize(220, 16777215));
        groupBox_right_knee->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_right_knee);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_left_hip_extension_3 = new QLabel(groupBox_right_knee);
        label_left_hip_extension_3->setObjectName(QStringLiteral("label_left_hip_extension_3"));
        label_left_hip_extension_3->setFont(font);

        gridLayout_5->addWidget(label_left_hip_extension_3, 0, 0, 1, 1);

        lineEdit_right_knee_extension = new QLineEdit(groupBox_right_knee);
        lineEdit_right_knee_extension->setObjectName(QStringLiteral("lineEdit_right_knee_extension"));
        lineEdit_right_knee_extension->setFont(font);

        gridLayout_5->addWidget(lineEdit_right_knee_extension, 1, 0, 1, 1);

        label_left_hip_flexion_3 = new QLabel(groupBox_right_knee);
        label_left_hip_flexion_3->setObjectName(QStringLiteral("label_left_hip_flexion_3"));
        label_left_hip_flexion_3->setFont(font);

        gridLayout_5->addWidget(label_left_hip_flexion_3, 2, 0, 1, 1);

        lineEdit_right_knee_flexion = new QLineEdit(groupBox_right_knee);
        lineEdit_right_knee_flexion->setObjectName(QStringLiteral("lineEdit_right_knee_flexion"));
        lineEdit_right_knee_flexion->setFont(font);

        gridLayout_5->addWidget(lineEdit_right_knee_flexion, 3, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_right_knee, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        groupBox_left_hip->raise();
        groupBox_left_hip->raise();
        img_human_leg->raise();
        groupBox_right_hip->raise();
        groupBox_left_knee->raise();
        groupBox_right_knee->raise();
        qwtPlot->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_11 = new QGridLayout(tab_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        gridLayout_16 = new QGridLayout(groupBox);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_13 = new QGridLayout(groupBox_2);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        pushButton_calibration = new QPushButton(groupBox_2);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        pushButton_calibration->setFont(font);

        gridLayout_13->addWidget(pushButton_calibration, 0, 2, 1, 1);

        pushButton_connect = new QPushButton(groupBox_2);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setFont(font);

        gridLayout_13->addWidget(pushButton_connect, 0, 0, 1, 1);

        pushButton_enable = new QPushButton(groupBox_2);
        pushButton_enable->setObjectName(QStringLiteral("pushButton_enable"));
        pushButton_enable->setFont(font);

        gridLayout_13->addWidget(pushButton_enable, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_13->addWidget(textBrowser, 1, 0, 1, 3);


        gridLayout_16->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_15 = new QGridLayout(groupBox_3);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        lcdNumber_right_knee_velocity = new QLCDNumber(groupBox_3);
        lcdNumber_right_knee_velocity->setObjectName(QStringLiteral("lcdNumber_right_knee_velocity"));

        gridLayout_10->addWidget(lcdNumber_right_knee_velocity, 6, 4, 1, 1);

        lcdNumber_left_hip_velocity = new QLCDNumber(groupBox_3);
        lcdNumber_left_hip_velocity->setObjectName(QStringLiteral("lcdNumber_left_hip_velocity"));

        gridLayout_10->addWidget(lcdNumber_left_hip_velocity, 6, 1, 1, 1);

        lcdNumber_left_hip_current = new QLCDNumber(groupBox_3);
        lcdNumber_left_hip_current->setObjectName(QStringLiteral("lcdNumber_left_hip_current"));

        gridLayout_10->addWidget(lcdNumber_left_hip_current, 7, 1, 1, 1);

        lcdNumber_right_hip_velocity = new QLCDNumber(groupBox_3);
        lcdNumber_right_hip_velocity->setObjectName(QStringLiteral("lcdNumber_right_hip_velocity"));

        gridLayout_10->addWidget(lcdNumber_right_hip_velocity, 6, 2, 1, 1);

        label_left_hip_status = new QLabel(groupBox_3);
        label_left_hip_status->setObjectName(QStringLiteral("label_left_hip_status"));
        label_left_hip_status->setFont(font);

        gridLayout_10->addWidget(label_left_hip_status, 4, 1, 1, 1);

        label_left_hip_connection = new QLabel(groupBox_3);
        label_left_hip_connection->setObjectName(QStringLiteral("label_left_hip_connection"));
        label_left_hip_connection->setFont(font);

        gridLayout_10->addWidget(label_left_hip_connection, 3, 1, 1, 1);

        label_left_hip = new QLabel(groupBox_3);
        label_left_hip->setObjectName(QStringLiteral("label_left_hip"));
        label_left_hip->setFont(font);

        gridLayout_10->addWidget(label_left_hip, 2, 1, 1, 1);

        label_left_knee = new QLabel(groupBox_3);
        label_left_knee->setObjectName(QStringLiteral("label_left_knee"));
        label_left_knee->setFont(font);

        gridLayout_10->addWidget(label_left_knee, 2, 3, 1, 1);

        label_right_hip = new QLabel(groupBox_3);
        label_right_hip->setObjectName(QStringLiteral("label_right_hip"));
        label_right_hip->setFont(font);

        gridLayout_10->addWidget(label_right_hip, 2, 2, 1, 1);

        label_right_knee = new QLabel(groupBox_3);
        label_right_knee->setObjectName(QStringLiteral("label_right_knee"));
        label_right_knee->setFont(font);

        gridLayout_10->addWidget(label_right_knee, 2, 4, 1, 1);

        lcdNumber_left_knee_velocity = new QLCDNumber(groupBox_3);
        lcdNumber_left_knee_velocity->setObjectName(QStringLiteral("lcdNumber_left_knee_velocity"));

        gridLayout_10->addWidget(lcdNumber_left_knee_velocity, 6, 3, 1, 1);

        label_right_hip_connection = new QLabel(groupBox_3);
        label_right_hip_connection->setObjectName(QStringLiteral("label_right_hip_connection"));
        label_right_hip_connection->setFont(font);

        gridLayout_10->addWidget(label_right_hip_connection, 3, 2, 1, 1);

        label_right_hip_status = new QLabel(groupBox_3);
        label_right_hip_status->setObjectName(QStringLiteral("label_right_hip_status"));
        label_right_hip_status->setFont(font);

        gridLayout_10->addWidget(label_right_hip_status, 4, 2, 1, 1);

        label_left_knee_connection = new QLabel(groupBox_3);
        label_left_knee_connection->setObjectName(QStringLiteral("label_left_knee_connection"));
        label_left_knee_connection->setFont(font);

        gridLayout_10->addWidget(label_left_knee_connection, 3, 3, 1, 1);

        label_left_knee_status = new QLabel(groupBox_3);
        label_left_knee_status->setObjectName(QStringLiteral("label_left_knee_status"));
        label_left_knee_status->setFont(font);

        gridLayout_10->addWidget(label_left_knee_status, 4, 3, 1, 1);

        label_right_knee_connection = new QLabel(groupBox_3);
        label_right_knee_connection->setObjectName(QStringLiteral("label_right_knee_connection"));
        label_right_knee_connection->setFont(font);

        gridLayout_10->addWidget(label_right_knee_connection, 3, 4, 1, 1);

        label_right_knee_status = new QLabel(groupBox_3);
        label_right_knee_status->setObjectName(QStringLiteral("label_right_knee_status"));
        label_right_knee_status->setFont(font);

        gridLayout_10->addWidget(label_right_knee_status, 4, 4, 1, 1);

        lcdNumber_left_knee_current = new QLCDNumber(groupBox_3);
        lcdNumber_left_knee_current->setObjectName(QStringLiteral("lcdNumber_left_knee_current"));

        gridLayout_10->addWidget(lcdNumber_left_knee_current, 7, 3, 1, 1);

        lcdNumber_right_knee_current = new QLCDNumber(groupBox_3);
        lcdNumber_right_knee_current->setObjectName(QStringLiteral("lcdNumber_right_knee_current"));

        gridLayout_10->addWidget(lcdNumber_right_knee_current, 7, 4, 1, 1);

        lcdNumber_left_hip_position = new QLCDNumber(groupBox_3);
        lcdNumber_left_hip_position->setObjectName(QStringLiteral("lcdNumber_left_hip_position"));

        gridLayout_10->addWidget(lcdNumber_left_hip_position, 5, 1, 1, 1);

        lcdNumber_right_hip_current = new QLCDNumber(groupBox_3);
        lcdNumber_right_hip_current->setObjectName(QStringLiteral("lcdNumber_right_hip_current"));

        gridLayout_10->addWidget(lcdNumber_right_hip_current, 7, 2, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        gridLayout_10->addWidget(label_21, 6, 0, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        gridLayout_10->addWidget(label_19, 4, 0, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        gridLayout_10->addWidget(label_24, 5, 0, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout_10->addWidget(label_15, 7, 0, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        gridLayout_10->addWidget(label_14, 3, 0, 1, 1);

        lcdNumber_right_hip_position = new QLCDNumber(groupBox_3);
        lcdNumber_right_hip_position->setObjectName(QStringLiteral("lcdNumber_right_hip_position"));

        gridLayout_10->addWidget(lcdNumber_right_hip_position, 5, 2, 1, 1);

        lcdNumber_left_knee_positio = new QLCDNumber(groupBox_3);
        lcdNumber_left_knee_positio->setObjectName(QStringLiteral("lcdNumber_left_knee_positio"));

        gridLayout_10->addWidget(lcdNumber_left_knee_positio, 5, 3, 1, 1);

        lcdNumber_right_knee_position = new QLCDNumber(groupBox_3);
        lcdNumber_right_knee_position->setObjectName(QStringLiteral("lcdNumber_right_knee_position"));

        gridLayout_10->addWidget(lcdNumber_right_knee_position, 5, 4, 1, 1);

        label_name = new QLabel(groupBox_3);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setFont(font);

        gridLayout_10->addWidget(label_name, 2, 0, 1, 1);


        gridLayout_15->addLayout(gridLayout_10, 0, 1, 1, 1);


        gridLayout_16->addWidget(groupBox_3, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        qt_exoskeleton->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_exoskeleton);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 749, 22));
        qt_exoskeleton->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_exoskeleton);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_exoskeleton->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_exoskeleton);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_exoskeleton->setStatusBar(statusBar);

        retranslateUi(qt_exoskeleton);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(qt_exoskeleton);
    } // setupUi

    void retranslateUi(QMainWindow *qt_exoskeleton)
    {
        qt_exoskeleton->setWindowTitle(QApplication::translate("qt_exoskeleton", "qt_exoskeleton", 0));
        groupBox_left_hip->setTitle(QApplication::translate("qt_exoskeleton", "\345\267\246\351\253\226\351\227\234\347\257\200", 0));
        label_left_hip_extension->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_left_hip_extension->setText(QApplication::translate("qt_exoskeleton", "-10", 0));
        label_left_hip_flexion->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        lineEdit_left_hip_flexion->setText(QApplication::translate("qt_exoskeleton", "90", 0));
        groupBox_left_knee->setTitle(QApplication::translate("qt_exoskeleton", "\345\267\246\350\206\235\351\227\234\347\257\200", 0));
        label_left_hip_extension_4->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_left_knee_extension->setText(QApplication::translate("qt_exoskeleton", "0", 0));
        label_left_hip_flexion_4->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        lineEdit_left_knee_flexion->setText(QApplication::translate("qt_exoskeleton", "90", 0));
        img_human_leg->setText(QString());
        groupBox_right_hip->setTitle(QApplication::translate("qt_exoskeleton", "\345\217\263\351\253\226\351\227\234\347\257\200", 0));
        label_left_hip_extension_2->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_right_hip_extension->setText(QApplication::translate("qt_exoskeleton", "-10", 0));
        label_left_hip_flexion_2->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        lineEdit_right_hip_flexion->setText(QApplication::translate("qt_exoskeleton", "90", 0));
        groupBox_right_knee->setTitle(QApplication::translate("qt_exoskeleton", "\345\217\263\350\206\235\351\227\234\347\257\200", 0));
        label_left_hip_extension_3->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_right_knee_extension->setText(QApplication::translate("qt_exoskeleton", "0", 0));
        label_left_hip_flexion_3->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        lineEdit_right_knee_flexion->setText(QApplication::translate("qt_exoskeleton", "90", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("qt_exoskeleton", "\344\272\272\351\253\224\345\237\272\346\234\254\345\217\203\346\225\270\350\250\255\345\256\232", 0));
        groupBox->setTitle(QApplication::translate("qt_exoskeleton", "\351\200\243\347\267\232\347\213\200\346\205\213", 0));
        groupBox_2->setTitle(QApplication::translate("qt_exoskeleton", "GroupBox", 0));
        pushButton_calibration->setText(QApplication::translate("qt_exoskeleton", "Calibration", 0));
        pushButton_connect->setText(QApplication::translate("qt_exoskeleton", "Connect", 0));
        pushButton_enable->setText(QApplication::translate("qt_exoskeleton", "Enable", 0));
        groupBox_3->setTitle(QApplication::translate("qt_exoskeleton", "GroupBox", 0));
        label_left_hip_status->setText(QApplication::translate("qt_exoskeleton", "TextLabel", 0));
        label_left_hip_connection->setText(QApplication::translate("qt_exoskeleton", "TextLabel", 0));
        label_left_hip->setText(QApplication::translate("qt_exoskeleton", "Left Hip", 0));
        label_left_knee->setText(QApplication::translate("qt_exoskeleton", "Left Knee", 0));
        label_right_hip->setText(QApplication::translate("qt_exoskeleton", "Right Hip", 0));
        label_right_knee->setText(QApplication::translate("qt_exoskeleton", "Right Knee", 0));
        label_right_hip_connection->setText(QApplication::translate("qt_exoskeleton", "Right Hip", 0));
        label_right_hip_status->setText(QApplication::translate("qt_exoskeleton", "Right Hip", 0));
        label_left_knee_connection->setText(QApplication::translate("qt_exoskeleton", "Left Knee", 0));
        label_left_knee_status->setText(QApplication::translate("qt_exoskeleton", "Left Knee", 0));
        label_right_knee_connection->setText(QApplication::translate("qt_exoskeleton", "Right Knee", 0));
        label_right_knee_status->setText(QApplication::translate("qt_exoskeleton", "Right Knee", 0));
        label_21->setText(QApplication::translate("qt_exoskeleton", "\351\200\237\345\272\246", 0));
        label_19->setText(QApplication::translate("qt_exoskeleton", "\344\275\277\347\224\250\347\213\200\346\205\213", 0));
        label_24->setText(QApplication::translate("qt_exoskeleton", "\344\275\215\347\275\256", 0));
        label_15->setText(QApplication::translate("qt_exoskeleton", "\351\233\273\346\265\201", 0));
        label_14->setText(QApplication::translate("qt_exoskeleton", "\351\200\243\347\267\232\347\213\200\346\205\213", 0));
        label_name->setText(QApplication::translate("qt_exoskeleton", "\351\203\250\344\275\215", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("qt_exoskeleton", "\346\251\237\345\231\250\344\272\272\350\250\255\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_exoskeleton: public Ui_qt_exoskeleton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_EXOSKELETON_H
