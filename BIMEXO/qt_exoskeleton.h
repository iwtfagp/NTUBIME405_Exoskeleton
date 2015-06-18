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

#include "mpu_9150.h"
#include <qwt_dial_needle.h>

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
    void updateCurrentView();
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

    void on_pushButton_parameter_model_clicked();

    void on_pushButton_parameter_IMU_clicked();

    void updateMpuView();
    void on_pushButton_parameter_IMU_init_clicked();

    void on_pushButton_loadModel_Stand_sit_clicked();

    void on_pushButton_current_clicked();

private:

    void file_current_save();
    void file_current_open();
    QFile *file_current;
    double Roll_angle = 0, Yaw_angle = 0, Pitch_angle = 0;
    double Roll_angle_init = 0, Yaw_angle_init = 0, Pitch_angle_init = 0;
    double Roll_angle_temp = 0, Yaw_angle_temp = 0, Pitch_angle_temp = 0;


    int FSM_state_number_will = 0;

    Ui::qt_exoskeleton *ui;
    QTimer* timer;
    QTimer* timer_model;
    QTimer *timer_mpu, *timer_current;
    MPU_9150 *mpu;



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
    QwtPlotCurve curve_stand_LH, curve_stand_RH, curve_stand_LK, curve_stand_RK;
    QwtPlotCurve curve_sit_LH, curve_sit_RH, curve_sit_LK, curve_sit_RK;

    //parameter model
    struct parameter_model
    {

        int phase;
        int hip_sin_amp, hip_sin_x, hip_sin_y;


        int knee_sin_amp, knee_sin_x, knee_sin_y;
        int knee_gaussian_amp, knee_gaussian_x, knee_gaussian_y, knee_gaussian_sigma;


        std::vector<double> left_hip_angle, right_hip_angle, left_knee_angle, right_knee_angle,
        left_knee_angle_gauss, right_knee_angle_gauss;
        QwtPlotCurve     curve_left_hip,curve_right_hip,curve_left_knee,curve_right_knee;


    }walk, stand, sit, up, down;


    int state_right = 0; // right = 1; central = 0; left = -1;
    int state_mode = 0;
    // stand and sitting = 0;
    // normal walking = 1
    // go up = 2
    // go down = 3


    //parameter model--


    void gaussian_wave(std::vector<double>* data, double amp, double x, double y, double sigma, int total);
    void sin_wave(std::vector<double>* , double , double , double , int );
    void wave_max(std::vector<double>*, std::vector<double>*);
    void wave_display(parameter_model *pp_model);
    void model_input(parameter_model *pp_model, int gait_number);


    QString dir_path;

    static const int data_number = 10000;
    int ML_lable[data_number];


};

#endif // QT_EXOSKELETON_H
