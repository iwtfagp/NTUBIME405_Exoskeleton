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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_16;
    QTextBrowser *textBrowser;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_left_hip;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_left_hip_flexion;
    QLabel *label_left_hip_flexion;
    QLabel *label_left_hip_extension;
    QLineEdit *lineEdit_left_hip_extension;
    QGroupBox *groupBox_left_knee;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_left_knee_flexion;
    QLineEdit *lineEdit_left_knee_extension;
    QLabel *label_left_hip_extension_4;
    QLabel *label_left_hip_flexion_4;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_right_knee;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_right_knee_flexion;
    QLabel *label_left_hip_flexion_3;
    QLabel *label_left_hip_extension_3;
    QLineEdit *lineEdit_right_knee_extension;
    QGroupBox *groupBox_right_hip;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_right_hip_flexion;
    QLabel *label_left_hip_flexion_2;
    QLabel *label_left_hip_extension_2;
    QLineEdit *lineEdit_right_hip_extension;
    QGridLayout *gridLayout_8;
    QLabel *img_human_leg;
    QwtPlot *qwtPlot;
    QWidget *tab_2;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QLabel *label_name;
    QLabel *label_left_hip;
    QLabel *label_right_hip;
    QLabel *label_left_knee;
    QLabel *label_right_knee;
    QLabel *label_19;
    QLabel *label_left_hip_status;
    QLabel *label_right_hip_status;
    QLabel *label_left_knee_status;
    QLabel *label_right_knee_status;
    QLineEdit *lineEdit_left_hip_set_position;
    QLineEdit *lineEdit_right_hip_set_position;
    QLineEdit *lineEdit_left_knee_set_position;
    QLineEdit *lineEdit_right_knee_set_position;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_24;
    QLCDNumber *lcdNumber_left_hip_position;
    QLCDNumber *lcdNumber_right_hip_position;
    QLCDNumber *lcdNumber_left_knee_position;
    QLCDNumber *lcdNumber_right_knee_position;
    QLabel *label_21;
    QLCDNumber *lcdNumber_left_hip_velocity;
    QLCDNumber *lcdNumber_right_hip_velocity;
    QLCDNumber *lcdNumber_left_knee_velocity;
    QLCDNumber *lcdNumber_right_knee_velocity;
    QLabel *label_15;
    QLCDNumber *lcdNumber_left_hip_current;
    QLCDNumber *lcdNumber_right_hip_current;
    QLCDNumber *lcdNumber_left_knee_current;
    QLCDNumber *lcdNumber_right_knee_current;
    QWidget *tab_5;
    QGridLayout *gridLayout_12;
    QLineEdit *lineEdit_username;
    QDoubleSpinBox *doubleSpinBox_speed;
    QPushButton *pushButton_StartModel;
    QPushButton *pushButton_loadModel;
    QLabel *label;
    QwtPlot *qwtPlot_motion_model;
    QLabel *label_2;
    QCheckBox *checkBox_RNG;
    QCheckBox *checkBox_continue;
    QCheckBox *checkBox_motor_enable;
    QWidget *tab_3;
    QGridLayout *gridLayout_26;
    QGridLayout *gridLayout_25;
    QPushButton *pushButton_parameter_model;
    QGridLayout *gridLayout_21;
    QLabel *label_state_mode;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_state_right;
    QSpinBox *spinBox_parameter_mode_speed;
    QGridLayout *gridLayout_24;
    QGridLayout *gridLayout_22;
    QPushButton *pushButton_parameter_IMU;
    QPushButton *pushButton_parameter_IMU_init;
    QGridLayout *gridLayout_20;
    QLabel *label_4;
    QSpinBox *spinBox;
    QGridLayout *gridLayout_23;
    QLCDNumber *lcdNumber_mpu_roll;
    QLCDNumber *lcdNumber_mpu_yaw;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_15;
    QwtPlot *qwtPlot_motion_model_parameter_stand;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QwtPlot *qwtPlot_motion_model_parameter_sit;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_18;
    QwtPlot *qwtPlot_motion_model_parameter_walk;
    QPushButton *pushButton_loadModel_Stand_sit;
    QLCDNumber *lcdNumber_mode_number;
    QLCDNumber *lcdNumber_mode_number_now;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_13;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_enable;
    QPushButton *pushButton_standing;
    QPushButton *pushButton_extension;
    QPushButton *pushButton_connect;
    QLabel *label_connection;
    QPushButton *pushButton_close;
    QPushButton *pushButton_period;
    QPushButton *pushButton_record;
    QPushButton *pushButton_sitting;
    QPushButton *pushButton_flexion;
    QPushButton *pushButton_calibration;
    QLineEdit *lineEdit;
    QPushButton *pushButton_current;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_exoskeleton)
    {
        if (qt_exoskeleton->objectName().isEmpty())
            qt_exoskeleton->setObjectName(QStringLiteral("qt_exoskeleton"));
        qt_exoskeleton->resize(1037, 683);
        qt_exoskeleton->setMaximumSize(QSize(16777215, 873));
        centralWidget = new QWidget(qt_exoskeleton);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_19 = new QGridLayout(centralWidget);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));

        gridLayout_19->addLayout(gridLayout_16, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        textBrowser->setFont(font);

        gridLayout_19->addWidget(textBrowser, 2, 2, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(800, 600));
        tabWidget->setFont(font);
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
        groupBox_left_hip->setMaximumSize(QSize(250, 250));
        groupBox_left_hip->setFont(font);
        groupBox_left_hip->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_left_hip);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_left_hip_flexion = new QLineEdit(groupBox_left_hip);
        lineEdit_left_hip_flexion->setObjectName(QStringLiteral("lineEdit_left_hip_flexion"));
        lineEdit_left_hip_flexion->setFont(font);

        gridLayout->addWidget(lineEdit_left_hip_flexion, 3, 0, 1, 1);

        label_left_hip_flexion = new QLabel(groupBox_left_hip);
        label_left_hip_flexion->setObjectName(QStringLiteral("label_left_hip_flexion"));
        label_left_hip_flexion->setFont(font);

        gridLayout->addWidget(label_left_hip_flexion, 2, 0, 1, 1);

        label_left_hip_extension = new QLabel(groupBox_left_hip);
        label_left_hip_extension->setObjectName(QStringLiteral("label_left_hip_extension"));
        label_left_hip_extension->setFont(font);

        gridLayout->addWidget(label_left_hip_extension, 0, 0, 1, 1);

        lineEdit_left_hip_extension = new QLineEdit(groupBox_left_hip);
        lineEdit_left_hip_extension->setObjectName(QStringLiteral("lineEdit_left_hip_extension"));
        lineEdit_left_hip_extension->setFont(font);

        gridLayout->addWidget(lineEdit_left_hip_extension, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_left_hip, 0, 0, 1, 1);

        groupBox_left_knee = new QGroupBox(tab);
        groupBox_left_knee->setObjectName(QStringLiteral("groupBox_left_knee"));
        groupBox_left_knee->setMaximumSize(QSize(250, 250));
        groupBox_left_knee->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_left_knee);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_left_knee_flexion = new QLineEdit(groupBox_left_knee);
        lineEdit_left_knee_flexion->setObjectName(QStringLiteral("lineEdit_left_knee_flexion"));
        lineEdit_left_knee_flexion->setFont(font);

        gridLayout_4->addWidget(lineEdit_left_knee_flexion, 3, 0, 1, 1);

        lineEdit_left_knee_extension = new QLineEdit(groupBox_left_knee);
        lineEdit_left_knee_extension->setObjectName(QStringLiteral("lineEdit_left_knee_extension"));
        lineEdit_left_knee_extension->setFont(font);

        gridLayout_4->addWidget(lineEdit_left_knee_extension, 1, 0, 1, 1);

        label_left_hip_extension_4 = new QLabel(groupBox_left_knee);
        label_left_hip_extension_4->setObjectName(QStringLiteral("label_left_hip_extension_4"));
        label_left_hip_extension_4->setFont(font);

        gridLayout_4->addWidget(label_left_hip_extension_4, 0, 0, 1, 1);

        label_left_hip_flexion_4 = new QLabel(groupBox_left_knee);
        label_left_hip_flexion_4->setObjectName(QStringLiteral("label_left_hip_flexion_4"));
        label_left_hip_flexion_4->setFont(font);

        gridLayout_4->addWidget(label_left_hip_flexion_4, 2, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_left_knee, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_right_knee = new QGroupBox(tab);
        groupBox_right_knee->setObjectName(QStringLiteral("groupBox_right_knee"));
        groupBox_right_knee->setMaximumSize(QSize(250, 250));
        groupBox_right_knee->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_right_knee);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lineEdit_right_knee_flexion = new QLineEdit(groupBox_right_knee);
        lineEdit_right_knee_flexion->setObjectName(QStringLiteral("lineEdit_right_knee_flexion"));
        lineEdit_right_knee_flexion->setFont(font);

        gridLayout_5->addWidget(lineEdit_right_knee_flexion, 3, 0, 1, 1);

        label_left_hip_flexion_3 = new QLabel(groupBox_right_knee);
        label_left_hip_flexion_3->setObjectName(QStringLiteral("label_left_hip_flexion_3"));
        label_left_hip_flexion_3->setFont(font);

        gridLayout_5->addWidget(label_left_hip_flexion_3, 2, 0, 1, 1);

        label_left_hip_extension_3 = new QLabel(groupBox_right_knee);
        label_left_hip_extension_3->setObjectName(QStringLiteral("label_left_hip_extension_3"));
        label_left_hip_extension_3->setFont(font);

        gridLayout_5->addWidget(label_left_hip_extension_3, 0, 0, 1, 1);

        lineEdit_right_knee_extension = new QLineEdit(groupBox_right_knee);
        lineEdit_right_knee_extension->setObjectName(QStringLiteral("lineEdit_right_knee_extension"));
        lineEdit_right_knee_extension->setFont(font);

        gridLayout_5->addWidget(lineEdit_right_knee_extension, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_right_knee, 1, 0, 1, 1);

        groupBox_right_hip = new QGroupBox(tab);
        groupBox_right_hip->setObjectName(QStringLiteral("groupBox_right_hip"));
        groupBox_right_hip->setMaximumSize(QSize(250, 250));
        groupBox_right_hip->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_right_hip);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_right_hip_flexion = new QLineEdit(groupBox_right_hip);
        lineEdit_right_hip_flexion->setObjectName(QStringLiteral("lineEdit_right_hip_flexion"));
        lineEdit_right_hip_flexion->setFont(font);

        gridLayout_3->addWidget(lineEdit_right_hip_flexion, 3, 0, 1, 1);

        label_left_hip_flexion_2 = new QLabel(groupBox_right_hip);
        label_left_hip_flexion_2->setObjectName(QStringLiteral("label_left_hip_flexion_2"));
        label_left_hip_flexion_2->setFont(font);

        gridLayout_3->addWidget(label_left_hip_flexion_2, 2, 0, 1, 1);

        label_left_hip_extension_2 = new QLabel(groupBox_right_hip);
        label_left_hip_extension_2->setObjectName(QStringLiteral("label_left_hip_extension_2"));
        label_left_hip_extension_2->setMaximumSize(QSize(225, 16777215));
        label_left_hip_extension_2->setFont(font);

        gridLayout_3->addWidget(label_left_hip_extension_2, 0, 0, 1, 1);

        lineEdit_right_hip_extension = new QLineEdit(groupBox_right_hip);
        lineEdit_right_hip_extension->setObjectName(QStringLiteral("lineEdit_right_hip_extension"));
        lineEdit_right_hip_extension->setFont(font);

        gridLayout_3->addWidget(lineEdit_right_hip_extension, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_right_hip, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 2, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        img_human_leg = new QLabel(tab);
        img_human_leg->setObjectName(QStringLiteral("img_human_leg"));
        img_human_leg->setFont(font);
        img_human_leg->setPixmap(QPixmap(QString::fromUtf8("human.jpg")));
        img_human_leg->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(img_human_leg, 1, 0, 1, 1);

        qwtPlot = new QwtPlot(tab);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setFont(font);

        gridLayout_8->addWidget(qwtPlot, 2, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_11 = new QGridLayout(tab_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setFont(font);

        gridLayout_10->addWidget(label_name, 0, 0, 1, 1);

        label_left_hip = new QLabel(groupBox);
        label_left_hip->setObjectName(QStringLiteral("label_left_hip"));
        label_left_hip->setFont(font);

        gridLayout_10->addWidget(label_left_hip, 0, 1, 1, 1);

        label_right_hip = new QLabel(groupBox);
        label_right_hip->setObjectName(QStringLiteral("label_right_hip"));
        label_right_hip->setFont(font);

        gridLayout_10->addWidget(label_right_hip, 0, 2, 1, 1);

        label_left_knee = new QLabel(groupBox);
        label_left_knee->setObjectName(QStringLiteral("label_left_knee"));
        label_left_knee->setFont(font);

        gridLayout_10->addWidget(label_left_knee, 0, 3, 1, 1);

        label_right_knee = new QLabel(groupBox);
        label_right_knee->setObjectName(QStringLiteral("label_right_knee"));
        label_right_knee->setFont(font);

        gridLayout_10->addWidget(label_right_knee, 0, 4, 1, 1);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        gridLayout_10->addWidget(label_19, 1, 0, 1, 1);

        label_left_hip_status = new QLabel(groupBox);
        label_left_hip_status->setObjectName(QStringLiteral("label_left_hip_status"));
        label_left_hip_status->setFont(font);

        gridLayout_10->addWidget(label_left_hip_status, 1, 1, 1, 1);

        label_right_hip_status = new QLabel(groupBox);
        label_right_hip_status->setObjectName(QStringLiteral("label_right_hip_status"));
        label_right_hip_status->setFont(font);

        gridLayout_10->addWidget(label_right_hip_status, 1, 2, 1, 1);

        label_left_knee_status = new QLabel(groupBox);
        label_left_knee_status->setObjectName(QStringLiteral("label_left_knee_status"));
        label_left_knee_status->setFont(font);

        gridLayout_10->addWidget(label_left_knee_status, 1, 3, 1, 1);

        label_right_knee_status = new QLabel(groupBox);
        label_right_knee_status->setObjectName(QStringLiteral("label_right_knee_status"));
        label_right_knee_status->setFont(font);

        gridLayout_10->addWidget(label_right_knee_status, 1, 4, 1, 1);

        lineEdit_left_hip_set_position = new QLineEdit(groupBox);
        lineEdit_left_hip_set_position->setObjectName(QStringLiteral("lineEdit_left_hip_set_position"));
        lineEdit_left_hip_set_position->setFont(font);

        gridLayout_10->addWidget(lineEdit_left_hip_set_position, 2, 1, 1, 1);

        lineEdit_right_hip_set_position = new QLineEdit(groupBox);
        lineEdit_right_hip_set_position->setObjectName(QStringLiteral("lineEdit_right_hip_set_position"));
        lineEdit_right_hip_set_position->setFont(font);

        gridLayout_10->addWidget(lineEdit_right_hip_set_position, 2, 2, 1, 1);

        lineEdit_left_knee_set_position = new QLineEdit(groupBox);
        lineEdit_left_knee_set_position->setObjectName(QStringLiteral("lineEdit_left_knee_set_position"));
        lineEdit_left_knee_set_position->setFont(font);

        gridLayout_10->addWidget(lineEdit_left_knee_set_position, 2, 3, 1, 1);

        lineEdit_right_knee_set_position = new QLineEdit(groupBox);
        lineEdit_right_knee_set_position->setObjectName(QStringLiteral("lineEdit_right_knee_set_position"));
        lineEdit_right_knee_set_position->setFont(font);

        gridLayout_10->addWidget(lineEdit_right_knee_set_position, 2, 4, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        gridLayout_10->addWidget(pushButton, 3, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout_10->addWidget(pushButton_2, 3, 2, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout_10->addWidget(pushButton_3, 3, 3, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFont(font);

        gridLayout_10->addWidget(pushButton_4, 3, 4, 1, 1);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        gridLayout_10->addWidget(label_24, 4, 0, 1, 1);

        lcdNumber_left_hip_position = new QLCDNumber(groupBox);
        lcdNumber_left_hip_position->setObjectName(QStringLiteral("lcdNumber_left_hip_position"));
        lcdNumber_left_hip_position->setFont(font);

        gridLayout_10->addWidget(lcdNumber_left_hip_position, 4, 1, 1, 1);

        lcdNumber_right_hip_position = new QLCDNumber(groupBox);
        lcdNumber_right_hip_position->setObjectName(QStringLiteral("lcdNumber_right_hip_position"));
        lcdNumber_right_hip_position->setFont(font);

        gridLayout_10->addWidget(lcdNumber_right_hip_position, 4, 2, 1, 1);

        lcdNumber_left_knee_position = new QLCDNumber(groupBox);
        lcdNumber_left_knee_position->setObjectName(QStringLiteral("lcdNumber_left_knee_position"));
        lcdNumber_left_knee_position->setFont(font);

        gridLayout_10->addWidget(lcdNumber_left_knee_position, 4, 3, 1, 1);

        lcdNumber_right_knee_position = new QLCDNumber(groupBox);
        lcdNumber_right_knee_position->setObjectName(QStringLiteral("lcdNumber_right_knee_position"));
        lcdNumber_right_knee_position->setFont(font);

        gridLayout_10->addWidget(lcdNumber_right_knee_position, 4, 4, 1, 1);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        gridLayout_10->addWidget(label_21, 5, 0, 1, 1);

        lcdNumber_left_hip_velocity = new QLCDNumber(groupBox);
        lcdNumber_left_hip_velocity->setObjectName(QStringLiteral("lcdNumber_left_hip_velocity"));
        lcdNumber_left_hip_velocity->setFont(font);

        gridLayout_10->addWidget(lcdNumber_left_hip_velocity, 5, 1, 1, 1);

        lcdNumber_right_hip_velocity = new QLCDNumber(groupBox);
        lcdNumber_right_hip_velocity->setObjectName(QStringLiteral("lcdNumber_right_hip_velocity"));
        lcdNumber_right_hip_velocity->setFont(font);

        gridLayout_10->addWidget(lcdNumber_right_hip_velocity, 5, 2, 1, 1);

        lcdNumber_left_knee_velocity = new QLCDNumber(groupBox);
        lcdNumber_left_knee_velocity->setObjectName(QStringLiteral("lcdNumber_left_knee_velocity"));
        lcdNumber_left_knee_velocity->setFont(font);

        gridLayout_10->addWidget(lcdNumber_left_knee_velocity, 5, 3, 1, 1);

        lcdNumber_right_knee_velocity = new QLCDNumber(groupBox);
        lcdNumber_right_knee_velocity->setObjectName(QStringLiteral("lcdNumber_right_knee_velocity"));
        lcdNumber_right_knee_velocity->setFont(font);

        gridLayout_10->addWidget(lcdNumber_right_knee_velocity, 5, 4, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        gridLayout_10->addWidget(label_15, 6, 0, 1, 1);

        lcdNumber_left_hip_current = new QLCDNumber(groupBox);
        lcdNumber_left_hip_current->setObjectName(QStringLiteral("lcdNumber_left_hip_current"));
        lcdNumber_left_hip_current->setFont(font);

        gridLayout_10->addWidget(lcdNumber_left_hip_current, 6, 1, 1, 1);

        lcdNumber_right_hip_current = new QLCDNumber(groupBox);
        lcdNumber_right_hip_current->setObjectName(QStringLiteral("lcdNumber_right_hip_current"));
        lcdNumber_right_hip_current->setFont(font);

        gridLayout_10->addWidget(lcdNumber_right_hip_current, 6, 2, 1, 1);

        lcdNumber_left_knee_current = new QLCDNumber(groupBox);
        lcdNumber_left_knee_current->setObjectName(QStringLiteral("lcdNumber_left_knee_current"));
        lcdNumber_left_knee_current->setFont(font);

        gridLayout_10->addWidget(lcdNumber_left_knee_current, 6, 3, 1, 1);

        lcdNumber_right_knee_current = new QLCDNumber(groupBox);
        lcdNumber_right_knee_current->setObjectName(QStringLiteral("lcdNumber_right_knee_current"));
        lcdNumber_right_knee_current->setFont(font);

        gridLayout_10->addWidget(lcdNumber_right_knee_current, 6, 4, 1, 1);


        gridLayout_11->addWidget(groupBox, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_12 = new QGridLayout(tab_5);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        lineEdit_username = new QLineEdit(tab_5);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_username->sizePolicy().hasHeightForWidth());
        lineEdit_username->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(lineEdit_username, 5, 1, 1, 1);

        doubleSpinBox_speed = new QDoubleSpinBox(tab_5);
        doubleSpinBox_speed->setObjectName(QStringLiteral("doubleSpinBox_speed"));
        doubleSpinBox_speed->setDecimals(0);
        doubleSpinBox_speed->setMinimum(10);
        doubleSpinBox_speed->setMaximum(10000);
        doubleSpinBox_speed->setSingleStep(10);
        doubleSpinBox_speed->setValue(100);

        gridLayout_12->addWidget(doubleSpinBox_speed, 4, 1, 1, 1);

        pushButton_StartModel = new QPushButton(tab_5);
        pushButton_StartModel->setObjectName(QStringLiteral("pushButton_StartModel"));

        gridLayout_12->addWidget(pushButton_StartModel, 1, 1, 1, 1);

        pushButton_loadModel = new QPushButton(tab_5);
        pushButton_loadModel->setObjectName(QStringLiteral("pushButton_loadModel"));

        gridLayout_12->addWidget(pushButton_loadModel, 1, 0, 1, 1);

        label = new QLabel(tab_5);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_12->addWidget(label, 5, 0, 1, 1);

        qwtPlot_motion_model = new QwtPlot(tab_5);
        qwtPlot_motion_model->setObjectName(QStringLiteral("qwtPlot_motion_model"));

        gridLayout_12->addWidget(qwtPlot_motion_model, 6, 0, 1, 2);

        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_12->addWidget(label_2, 4, 0, 1, 1);

        checkBox_RNG = new QCheckBox(tab_5);
        checkBox_RNG->setObjectName(QStringLiteral("checkBox_RNG"));
        checkBox_RNG->setChecked(true);

        gridLayout_12->addWidget(checkBox_RNG, 0, 0, 1, 1);

        checkBox_continue = new QCheckBox(tab_5);
        checkBox_continue->setObjectName(QStringLiteral("checkBox_continue"));
        checkBox_continue->setChecked(false);

        gridLayout_12->addWidget(checkBox_continue, 2, 0, 1, 1);

        checkBox_motor_enable = new QCheckBox(tab_5);
        checkBox_motor_enable->setObjectName(QStringLiteral("checkBox_motor_enable"));
        checkBox_motor_enable->setChecked(false);

        gridLayout_12->addWidget(checkBox_motor_enable, 0, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_26 = new QGridLayout(tab_3);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        gridLayout_25 = new QGridLayout();
        gridLayout_25->setSpacing(6);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        pushButton_parameter_model = new QPushButton(tab_3);
        pushButton_parameter_model->setObjectName(QStringLiteral("pushButton_parameter_model"));

        gridLayout_25->addWidget(pushButton_parameter_model, 0, 0, 1, 1);

        gridLayout_21 = new QGridLayout();
        gridLayout_21->setSpacing(6);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        label_state_mode = new QLabel(tab_3);
        label_state_mode->setObjectName(QStringLiteral("label_state_mode"));

        gridLayout_21->addWidget(label_state_mode, 0, 2, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_21->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_21->addWidget(label_5, 1, 0, 1, 1);

        label_state_right = new QLabel(tab_3);
        label_state_right->setObjectName(QStringLiteral("label_state_right"));

        gridLayout_21->addWidget(label_state_right, 1, 2, 1, 1);


        gridLayout_25->addLayout(gridLayout_21, 2, 0, 1, 1);

        spinBox_parameter_mode_speed = new QSpinBox(tab_3);
        spinBox_parameter_mode_speed->setObjectName(QStringLiteral("spinBox_parameter_mode_speed"));
        spinBox_parameter_mode_speed->setMinimum(10);
        spinBox_parameter_mode_speed->setMaximum(9999);
        spinBox_parameter_mode_speed->setValue(500);

        gridLayout_25->addWidget(spinBox_parameter_mode_speed, 1, 0, 1, 1);


        gridLayout_26->addLayout(gridLayout_25, 0, 0, 1, 1);

        gridLayout_24 = new QGridLayout();
        gridLayout_24->setSpacing(6);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        gridLayout_22 = new QGridLayout();
        gridLayout_22->setSpacing(6);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        pushButton_parameter_IMU = new QPushButton(tab_3);
        pushButton_parameter_IMU->setObjectName(QStringLiteral("pushButton_parameter_IMU"));

        gridLayout_22->addWidget(pushButton_parameter_IMU, 0, 0, 1, 1);

        pushButton_parameter_IMU_init = new QPushButton(tab_3);
        pushButton_parameter_IMU_init->setObjectName(QStringLiteral("pushButton_parameter_IMU_init"));

        gridLayout_22->addWidget(pushButton_parameter_IMU_init, 1, 0, 1, 1);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setSpacing(6);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_20->addWidget(label_4, 0, 0, 1, 1);

        spinBox = new QSpinBox(tab_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setValue(5);

        gridLayout_20->addWidget(spinBox, 0, 1, 1, 1);


        gridLayout_22->addLayout(gridLayout_20, 2, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_22, 0, 0, 1, 1);

        gridLayout_23 = new QGridLayout();
        gridLayout_23->setSpacing(6);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        lcdNumber_mpu_roll = new QLCDNumber(tab_3);
        lcdNumber_mpu_roll->setObjectName(QStringLiteral("lcdNumber_mpu_roll"));

        gridLayout_23->addWidget(lcdNumber_mpu_roll, 0, 0, 1, 1);

        lcdNumber_mpu_yaw = new QLCDNumber(tab_3);
        lcdNumber_mpu_yaw->setObjectName(QStringLiteral("lcdNumber_mpu_yaw"));

        gridLayout_23->addWidget(lcdNumber_mpu_yaw, 1, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_23, 0, 1, 1, 1);


        gridLayout_26->addLayout(gridLayout_24, 0, 3, 1, 1);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(6);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_15 = new QGridLayout(groupBox_3);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        qwtPlot_motion_model_parameter_stand = new QwtPlot(groupBox_3);
        qwtPlot_motion_model_parameter_stand->setObjectName(QStringLiteral("qwtPlot_motion_model_parameter_stand"));

        gridLayout_15->addWidget(qwtPlot_motion_model_parameter_stand, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        qwtPlot_motion_model_parameter_sit = new QwtPlot(groupBox_4);
        qwtPlot_motion_model_parameter_sit->setObjectName(QStringLiteral("qwtPlot_motion_model_parameter_sit"));

        gridLayout_2->addWidget(qwtPlot_motion_model_parameter_sit, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_4, 0, 1, 1, 1);


        gridLayout_17->addLayout(gridLayout_14, 2, 0, 1, 1);

        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_18 = new QGridLayout(groupBox_5);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        qwtPlot_motion_model_parameter_walk = new QwtPlot(groupBox_5);
        qwtPlot_motion_model_parameter_walk->setObjectName(QStringLiteral("qwtPlot_motion_model_parameter_walk"));

        gridLayout_18->addWidget(qwtPlot_motion_model_parameter_walk, 0, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_5, 0, 0, 1, 1);

        pushButton_loadModel_Stand_sit = new QPushButton(tab_3);
        pushButton_loadModel_Stand_sit->setObjectName(QStringLiteral("pushButton_loadModel_Stand_sit"));

        gridLayout_17->addWidget(pushButton_loadModel_Stand_sit, 1, 0, 1, 1);


        gridLayout_26->addLayout(gridLayout_17, 1, 0, 1, 4);

        lcdNumber_mode_number = new QLCDNumber(tab_3);
        lcdNumber_mode_number->setObjectName(QStringLiteral("lcdNumber_mode_number"));

        gridLayout_26->addWidget(lcdNumber_mode_number, 0, 2, 1, 1);

        lcdNumber_mode_number_now = new QLCDNumber(tab_3);
        lcdNumber_mode_number_now->setObjectName(QStringLiteral("lcdNumber_mode_number_now"));

        gridLayout_26->addWidget(lcdNumber_mode_number_now, 0, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_19->addWidget(tabWidget, 0, 1, 3, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        groupBox_2->setFont(font);
        gridLayout_13 = new QGridLayout(groupBox_2);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 10, 0, 1, 1);

        pushButton_enable = new QPushButton(groupBox_2);
        pushButton_enable->setObjectName(QStringLiteral("pushButton_enable"));
        pushButton_enable->setFont(font);
        pushButton_enable->setCheckable(true);
        pushButton_enable->setChecked(false);
        pushButton_enable->setAutoRepeat(false);
        pushButton_enable->setDefault(false);
        pushButton_enable->setFlat(false);

        gridLayout_13->addWidget(pushButton_enable, 2, 0, 1, 1);

        pushButton_standing = new QPushButton(groupBox_2);
        pushButton_standing->setObjectName(QStringLiteral("pushButton_standing"));
        pushButton_standing->setFont(font);

        gridLayout_13->addWidget(pushButton_standing, 4, 0, 1, 1);

        pushButton_extension = new QPushButton(groupBox_2);
        pushButton_extension->setObjectName(QStringLiteral("pushButton_extension"));
        pushButton_extension->setFont(font);

        gridLayout_13->addWidget(pushButton_extension, 6, 0, 1, 1);

        pushButton_connect = new QPushButton(groupBox_2);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setFont(font);
        pushButton_connect->setAutoDefault(false);

        gridLayout_13->addWidget(pushButton_connect, 0, 0, 1, 1);

        label_connection = new QLabel(groupBox_2);
        label_connection->setObjectName(QStringLiteral("label_connection"));
        label_connection->setFont(font);
        label_connection->setTextFormat(Qt::PlainText);
        label_connection->setAlignment(Qt::AlignCenter);

        gridLayout_13->addWidget(label_connection, 1, 0, 1, 1);

        pushButton_close = new QPushButton(groupBox_2);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setFont(font);

        gridLayout_13->addWidget(pushButton_close, 8, 0, 1, 1);

        pushButton_period = new QPushButton(groupBox_2);
        pushButton_period->setObjectName(QStringLiteral("pushButton_period"));

        gridLayout_13->addWidget(pushButton_period, 12, 0, 1, 1);

        pushButton_record = new QPushButton(groupBox_2);
        pushButton_record->setObjectName(QStringLiteral("pushButton_record"));

        gridLayout_13->addWidget(pushButton_record, 13, 0, 1, 1);

        pushButton_sitting = new QPushButton(groupBox_2);
        pushButton_sitting->setObjectName(QStringLiteral("pushButton_sitting"));
        pushButton_sitting->setFont(font);

        gridLayout_13->addWidget(pushButton_sitting, 5, 0, 1, 1);

        pushButton_flexion = new QPushButton(groupBox_2);
        pushButton_flexion->setObjectName(QStringLiteral("pushButton_flexion"));
        pushButton_flexion->setFont(font);

        gridLayout_13->addWidget(pushButton_flexion, 7, 0, 1, 1);

        pushButton_calibration = new QPushButton(groupBox_2);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        pushButton_calibration->setFont(font);

        gridLayout_13->addWidget(pushButton_calibration, 3, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_13->addWidget(lineEdit, 11, 0, 1, 1);

        pushButton_current = new QPushButton(groupBox_2);
        pushButton_current->setObjectName(QStringLiteral("pushButton_current"));

        gridLayout_13->addWidget(pushButton_current, 14, 0, 1, 1);


        gridLayout_19->addWidget(groupBox_2, 1, 2, 1, 1);

        qt_exoskeleton->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_exoskeleton);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1037, 22));
        qt_exoskeleton->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_exoskeleton);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_exoskeleton->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_exoskeleton);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_exoskeleton->setStatusBar(statusBar);

        retranslateUi(qt_exoskeleton);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(qt_exoskeleton);
    } // setupUi

    void retranslateUi(QMainWindow *qt_exoskeleton)
    {
        qt_exoskeleton->setWindowTitle(QApplication::translate("qt_exoskeleton", "qt_exoskeleton", 0));
        groupBox_left_hip->setTitle(QApplication::translate("qt_exoskeleton", "\345\267\246\351\253\226\351\227\234\347\257\200", 0));
        lineEdit_left_hip_flexion->setText(QApplication::translate("qt_exoskeleton", "120", 0));
        label_left_hip_flexion->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        label_left_hip_extension->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_left_hip_extension->setText(QApplication::translate("qt_exoskeleton", "-10", 0));
        groupBox_left_knee->setTitle(QApplication::translate("qt_exoskeleton", "\345\267\246\350\206\235\351\227\234\347\257\200", 0));
        lineEdit_left_knee_flexion->setText(QApplication::translate("qt_exoskeleton", "120", 0));
        lineEdit_left_knee_extension->setText(QApplication::translate("qt_exoskeleton", "0", 0));
        label_left_hip_extension_4->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        label_left_hip_flexion_4->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        groupBox_right_knee->setTitle(QApplication::translate("qt_exoskeleton", "\345\217\263\350\206\235\351\227\234\347\257\200", 0));
        lineEdit_right_knee_flexion->setText(QApplication::translate("qt_exoskeleton", "120", 0));
        label_left_hip_flexion_3->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        label_left_hip_extension_3->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_right_knee_extension->setText(QApplication::translate("qt_exoskeleton", "0", 0));
        groupBox_right_hip->setTitle(QApplication::translate("qt_exoskeleton", "\345\217\263\351\253\226\351\227\234\347\257\200", 0));
        lineEdit_right_hip_flexion->setText(QApplication::translate("qt_exoskeleton", "120", 0));
        label_left_hip_flexion_2->setText(QApplication::translate("qt_exoskeleton", "\345\275\216\346\233\262\346\245\265\351\231\220(drgee)", 0));
        label_left_hip_extension_2->setText(QApplication::translate("qt_exoskeleton", "\344\274\270\345\261\225\346\245\265\351\231\220(drgee)", 0));
        lineEdit_right_hip_extension->setText(QApplication::translate("qt_exoskeleton", "-10", 0));
        img_human_leg->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("qt_exoskeleton", "\344\272\272\351\253\224\345\237\272\346\234\254\345\217\203\346\225\270\350\250\255\345\256\232", 0));
        groupBox->setTitle(QApplication::translate("qt_exoskeleton", "\351\200\243\347\267\232\347\213\200\346\205\213", 0));
        label_name->setText(QApplication::translate("qt_exoskeleton", "\351\203\250\344\275\215", 0));
        label_left_hip->setText(QApplication::translate("qt_exoskeleton", "Left Hip", 0));
        label_right_hip->setText(QApplication::translate("qt_exoskeleton", "Right Hip", 0));
        label_left_knee->setText(QApplication::translate("qt_exoskeleton", "Left Knee", 0));
        label_right_knee->setText(QApplication::translate("qt_exoskeleton", "Right Knee", 0));
        label_19->setText(QApplication::translate("qt_exoskeleton", "\344\275\277\347\224\250\347\213\200\346\205\213", 0));
        label_left_hip_status->setText(QApplication::translate("qt_exoskeleton", "TextLabel", 0));
        label_right_hip_status->setText(QApplication::translate("qt_exoskeleton", "Right Hip", 0));
        label_left_knee_status->setText(QApplication::translate("qt_exoskeleton", "Left Knee", 0));
        label_right_knee_status->setText(QApplication::translate("qt_exoskeleton", "Right Knee", 0));
        pushButton->setText(QApplication::translate("qt_exoskeleton", "OK", 0));
        pushButton_2->setText(QApplication::translate("qt_exoskeleton", "OK", 0));
        pushButton_3->setText(QApplication::translate("qt_exoskeleton", "OK", 0));
        pushButton_4->setText(QApplication::translate("qt_exoskeleton", "OK", 0));
        label_24->setText(QApplication::translate("qt_exoskeleton", "\344\275\215\347\275\256(degree)", 0));
        label_21->setText(QApplication::translate("qt_exoskeleton", "\351\200\237\345\272\246(qc)", 0));
        label_15->setText(QApplication::translate("qt_exoskeleton", "\351\233\273\346\265\201", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("qt_exoskeleton", "\346\251\237\345\231\250\344\272\272\350\250\255\345\256\232", 0));
        lineEdit_username->setText(QApplication::translate("qt_exoskeleton", "William", 0));
        pushButton_StartModel->setText(QApplication::translate("qt_exoskeleton", "Start Model", 0));
        pushButton_loadModel->setText(QApplication::translate("qt_exoskeleton", "Load Model", 0));
        label->setText(QApplication::translate("qt_exoskeleton", "UserName", 0));
        label_2->setText(QApplication::translate("qt_exoskeleton", "Step(Min:10, Max:10000)", 0));
        checkBox_RNG->setText(QApplication::translate("qt_exoskeleton", "Random Number Generator", 0));
        checkBox_continue->setText(QApplication::translate("qt_exoskeleton", "Continue Mode", 0));
        checkBox_motor_enable->setText(QApplication::translate("qt_exoskeleton", "Enable the motor", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("qt_exoskeleton", "\350\265\260\350\267\257", 0));
        pushButton_parameter_model->setText(QApplication::translate("qt_exoskeleton", "GO", 0));
        label_state_mode->setText(QApplication::translate("qt_exoskeleton", "central", 0));
        label_3->setText(QApplication::translate("qt_exoskeleton", "\347\213\200\346\205\213\346\251\237", 0));
        label_5->setText(QApplication::translate("qt_exoskeleton", "\345\267\246\345\217\263\347\213\200\346\205\213", 0));
        label_state_right->setText(QApplication::translate("qt_exoskeleton", "central", 0));
        pushButton_parameter_IMU->setText(QApplication::translate("qt_exoskeleton", "IMU_Start", 0));
        pushButton_parameter_IMU_init->setText(QApplication::translate("qt_exoskeleton", "IMU_init", 0));
        label_4->setText(QApplication::translate("qt_exoskeleton", "IMU PORT", 0));
        groupBox_3->setTitle(QApplication::translate("qt_exoskeleton", "\347\253\231\347\253\213", 0));
        groupBox_4->setTitle(QApplication::translate("qt_exoskeleton", "\345\235\220\344\270\213", 0));
        groupBox_5->setTitle(QApplication::translate("qt_exoskeleton", "\350\265\260\350\267\257", 0));
        pushButton_loadModel_Stand_sit->setText(QApplication::translate("qt_exoskeleton", "LOAD model", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("qt_exoskeleton", "\345\217\203\346\225\270\345\214\226\346\250\241\347\265\204", 0));
        groupBox_2->setTitle(QApplication::translate("qt_exoskeleton", "Panel", 0));
        pushButton_enable->setText(QApplication::translate("qt_exoskeleton", "Enable", 0));
        pushButton_standing->setText(QApplication::translate("qt_exoskeleton", "Standing", 0));
        pushButton_extension->setText(QApplication::translate("qt_exoskeleton", "Extension Limit", 0));
        pushButton_connect->setText(QApplication::translate("qt_exoskeleton", "Connect", 0));
        label_connection->setText(QApplication::translate("qt_exoskeleton", "\345\260\232\346\234\252\351\200\243\347\267\232", 0));
        pushButton_close->setText(QApplication::translate("qt_exoskeleton", "Close", 0));
        pushButton_period->setText(QApplication::translate("qt_exoskeleton", "ONE", 0));
        pushButton_record->setText(QApplication::translate("qt_exoskeleton", "Period", 0));
        pushButton_sitting->setText(QApplication::translate("qt_exoskeleton", "Sitting", 0));
        pushButton_flexion->setText(QApplication::translate("qt_exoskeleton", "Flexion Limit", 0));
        pushButton_calibration->setText(QApplication::translate("qt_exoskeleton", "Calibration", 0));
        lineEdit->setText(QApplication::translate("qt_exoskeleton", "PRESS", 0));
        pushButton_current->setText(QApplication::translate("qt_exoskeleton", "current record?", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_exoskeleton: public Ui_qt_exoskeleton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_EXOSKELETON_H
