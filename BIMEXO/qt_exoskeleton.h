#ifndef QT_EXOSKELETON_H
#define QT_EXOSKELETON_H

#include <QMainWindow>
#include "my_maxon_motor.h"
#include <QTimer>
#include <QKeyEvent>

#include <QFileDialog>

#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <QDateTime>

#include <iostream>
#include <random>
#include <ctime>



namespace Ui {
class qt_exoskeleton;
}

class qt_exoskeleton : public QMainWindow
{
    Q_OBJECT

public:
    explicit qt_exoskeleton(QWidget *parent = 0);
    ~qt_exoskeleton();

private slots:
    void updateView();
    void updateModel();
    void on_pushButton_calibration_clicked();
    void on_pushButton_enable_clicked();
    void on_pushButton_connect_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_standing_clicked();
    void on_pushButton_sitting_clicked();
    void on_pushButton_extension_clicked();
    void on_pushButton_flexion_clicked();
    void keyPressEvent(QKeyEvent* event);
    void on_pushButton_StartModel_clicked();
    void on_pushButton_loadModel_clicked();
    void on_pushButton_record_clicked();
    void on_pushButton_period_clicked();

private:
    Ui::qt_exoskeleton *ui;
    QTimer* timer;
    QTimer* timer_model;

    QFile *file_new_model;
    QString filename;
    my_maxon_motor *motor_left_hip, *motor_right_hip, *motor_left_knee, *motor_right_knee;
    double MaxProfileVelocity, MaxFollowingError, MaxAcceleration;

    double left_hip_extension_limit;
    double left_hip_flexion_limit;
    double right_hip_extension_limit;
    double right_hip_flexion_limit;
    double left_knee_extension_limit;
    double left_knee_flexion_limit;
    double right_knee_extension_limit;
    double right_knee_flexion_limit;

    std::vector<double> model_left_hip_angle_mean;
    std::vector<double> model_right_hip_angle_mean;
    std::vector<double> model_left_knee_angle_mean;
    std::vector<double> model_right_knee_angle_mean;
    std::vector<double> model_left_hip_angle_std;
    std::vector<double> model_right_hip_angle_std;
    std::vector<double> model_left_knee_angle_std;
    std::vector<double> model_right_knee_angle_std;

    QwtPlotCurve curve_left_hip, curve_right_hip, curve_left_knee, curve_right_knee;
    QString dir_path;

    static const int data_number = 10000;
    int ML_lable[data_number];


};

#endif // QT_EXOSKELETON_H
