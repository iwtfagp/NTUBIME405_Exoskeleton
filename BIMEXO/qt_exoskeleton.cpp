#include "qt_exoskeleton.h"
#include "ui_qt_exoskeleton.h"




qt_exoskeleton::qt_exoskeleton(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qt_exoskeleton)
{
    ui->setupUi(this);

    motor_left_hip = new my_maxon_motor();
    motor_right_hip = new my_maxon_motor();
    motor_left_knee = new my_maxon_motor();
    motor_right_knee = new my_maxon_motor();

    MaxProfileVelocity = 500;
    MaxFollowingError = 3000;
    MaxAcceleration = 200;

    ui->pushButton_enable->setDisabled(true);
    ui->pushButton_calibration->setDisabled(true);
    ui->pushButton_close->setDisabled(true);
    ui->pushButton_standing->setDisabled(true);
    ui->pushButton_sitting->setDisabled(true);
    ui->pushButton_extension->setDisabled(true);
    ui->pushButton_flexion->setDisabled(true);
    ui->pushButton_StartModel->setDisabled(true);

    ui->qwtPlot_motion_model->setTitle( "Model" );
    ui->qwtPlot_motion_model->setCanvasBackground( Qt::white );
    ui->qwtPlot_motion_model->setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
    ui->qwtPlot_motion_model->insertLegend( new QwtLegend() );
    curve_left_hip.setTitle( "Left Hip" );
    curve_right_hip.setTitle( "Right Hip" );
    curve_left_knee.setTitle( "Left Knee" );
    curve_right_knee.setTitle( "Right Knee" );


    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateView()));
    timer->setInterval(100);
    timer->start();
}

qt_exoskeleton::~qt_exoskeleton()
{
    this->on_pushButton_close_clicked();
    delete ui;
}


void qt_exoskeleton::on_pushButton_connect_clicked()
{
    //起動連結與訊息回報
    QString str_error;
    bool isopen = motor_left_hip->openDevice(&str_error) && motor_right_hip->openDevice(&str_error) &&
            motor_left_knee->openDevice(&str_error) && motor_right_knee->openDevice(&str_error);
    if(isopen == 0)
    {
        ui->textBrowser->append("connect failed");
        ui->label_connection->setText("failed");
        ui->label_connection->setStyleSheet("QLabel { background-color : red; color : white; }");
        return;
    }
    ui->textBrowser->append("connect OK");
    ui->label_connection->setText("OK");
    ui->label_connection->setStyleSheet("QLabel { background-color : green; color : black; }");





    //init the node ID
    motor_left_hip->init(1, MaxProfileVelocity, MaxFollowingError, MaxAcceleration);
    motor_right_hip->init(2, MaxProfileVelocity, MaxFollowingError, MaxAcceleration);
    motor_left_knee->init(3, MaxProfileVelocity, MaxFollowingError, MaxAcceleration);
    motor_right_knee->init(4, MaxProfileVelocity, MaxFollowingError, MaxAcceleration);


    //set Limit parameter
    left_hip_extension_limit = ui->lineEdit_left_hip_extension->text().toDouble();
    left_hip_flexion_limit = ui->lineEdit_left_hip_flexion->text().toDouble();
    ui->lineEdit_left_hip_extension->setDisabled(true);
    ui->lineEdit_left_hip_flexion->setDisabled(true);

    right_hip_extension_limit = ui->lineEdit_right_hip_extension->text().toDouble();
    right_hip_flexion_limit = ui->lineEdit_right_hip_flexion->text().toDouble();
    ui->lineEdit_right_hip_extension->setDisabled(true);
    ui->lineEdit_right_hip_flexion->setDisabled(true);

    left_knee_extension_limit = ui->lineEdit_left_knee_extension->text().toDouble();
    left_knee_flexion_limit = ui->lineEdit_left_knee_flexion->text().toDouble();
    ui->lineEdit_left_knee_extension->setDisabled(true);
    ui->lineEdit_left_knee_flexion->setDisabled(true);

    right_knee_extension_limit = ui->lineEdit_right_knee_extension->text().toDouble();
    right_knee_flexion_limit = ui->lineEdit_right_knee_flexion->text().toDouble();
    ui->lineEdit_right_knee_extension->setDisabled(true);
    ui->lineEdit_right_knee_flexion->setDisabled(true);

    //開起按鈕介面
    ui->pushButton_enable->setEnabled(true);
    ui->pushButton_close->setEnabled(true);


}
void qt_exoskeleton::on_pushButton_enable_clicked()
{
    QString str_ErrorCode;






    if(ui->pushButton_enable->isChecked())
    {
        ui->pushButton_enable->setText("Disable");
        ui->pushButton_calibration->setEnabled(true);
        ui->pushButton_standing->setEnabled(true);
        ui->pushButton_sitting->setEnabled(true);
        ui->pushButton_extension->setEnabled(true);
        ui->pushButton_flexion->setEnabled(true);




        motor_left_hip->setEnabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
        motor_right_hip->setEnabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
        motor_left_knee->setEnabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
        motor_right_knee->setEnabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);

    }
    else
    {
        ui->pushButton_enable->setText("Enable");
        ui->pushButton_calibration->setDisabled(true);
        ui->pushButton_standing->setDisabled(true);
        ui->pushButton_sitting->setDisabled(true);
        ui->pushButton_extension->setDisabled(true);
        ui->pushButton_flexion->setDisabled(true);



        motor_left_hip->setDisabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
        motor_right_hip->setDisabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
        motor_left_knee->setDisabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
        motor_right_knee->setDisabled(&str_ErrorCode);ui->textBrowser->append(str_ErrorCode);
    }

}
void qt_exoskeleton::on_pushButton_close_clicked()
{
    ui->pushButton_enable->setChecked(false);
    motor_right_knee->closeALLDevice();
    this->on_pushButton_enable_clicked();

    ui->lineEdit_left_hip_extension->setEnabled(true);
    ui->lineEdit_left_hip_flexion->setEnabled(true);

    ui->lineEdit_right_hip_extension->setEnabled(true);
    ui->lineEdit_right_hip_flexion->setEnabled(true);

    ui->lineEdit_left_knee_extension->setEnabled(true);
    ui->lineEdit_left_knee_flexion->setEnabled(true);

    ui->lineEdit_right_knee_extension->setEnabled(true);
    ui->lineEdit_right_knee_flexion->setEnabled(true);

}


void qt_exoskeleton::updateView()
{
    QString str_ErrorCode;

    //display P,V,C
    ui->lcdNumber_left_hip_position->display(motor_left_hip->getPosition(&str_ErrorCode));
    ui->lcdNumber_left_hip_velocity->display(motor_left_hip->getVelocity(&str_ErrorCode));
    ui->lcdNumber_left_hip_current->display( motor_left_hip->getCurrent(&str_ErrorCode));

    ui->lcdNumber_right_hip_position->display(motor_right_hip->getPosition(&str_ErrorCode));
    ui->lcdNumber_right_hip_velocity->display(motor_right_hip->getVelocity(&str_ErrorCode));
    ui->lcdNumber_right_hip_current->display( motor_right_hip->getCurrent(&str_ErrorCode));

    ui->lcdNumber_left_knee_position->display(motor_left_knee->getPosition(&str_ErrorCode));
    ui->lcdNumber_left_knee_velocity->display(motor_left_knee->getVelocity(&str_ErrorCode));
    ui->lcdNumber_left_knee_current->display( motor_left_knee->getCurrent(&str_ErrorCode));

    ui->lcdNumber_right_knee_position->display(motor_right_knee->getPosition(&str_ErrorCode));
    ui->lcdNumber_right_knee_velocity->display(motor_right_knee->getVelocity(&str_ErrorCode));
    ui->lcdNumber_right_knee_current->display( motor_right_knee->getCurrent(&str_ErrorCode));


    if(     motor_left_hip->getEnableState(&str_ErrorCode)){
        ui->label_left_hip_status->setStyleSheet("QLabel { background-color : green; color : black; }");
        ui->label_left_hip_status->setText("Enable");}else{
        ui->label_left_hip_status->setStyleSheet("QLabel { background-color : red; color : white; }");
        ui->label_left_hip_status->setText("Disable");
    }

    if(     motor_right_hip->getEnableState(&str_ErrorCode)){
        ui->label_right_hip_status->setStyleSheet("QLabel { background-color : green; color : black; }");
        ui->label_right_hip_status->setText("Enable");}else{
        ui->label_right_hip_status->setStyleSheet("QLabel { background-color : red; color : white; }");
        ui->label_right_hip_status->setText("Disable");
    }
    if(     motor_left_knee->getEnableState(&str_ErrorCode)){
        ui->label_left_knee_status->setStyleSheet("QLabel { background-color : green; color : black; }");
        ui->label_left_knee_status->setText("Enable");}else{
        ui->label_left_knee_status->setStyleSheet("QLabel { background-color : red; color : white; }");
        ui->label_left_knee_status->setText("Disable");
    }
    if(     motor_right_knee->getEnableState(&str_ErrorCode)){
        ui->label_right_knee_status->setStyleSheet("QLabel { background-color : green; color : black; }");
        ui->label_right_knee_status->setText("Enable");}else{
        ui->label_right_knee_status->setStyleSheet("QLabel { background-color : red; color : white; }");
        ui->label_right_knee_status->setText("Disable");
    }





}
void qt_exoskeleton::on_pushButton_calibration_clicked()
{
    QString str_ErrorCode;
    motor_left_hip ->calibration(85335, HM_POSITIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_right_hip->calibration(85335, HM_NEGATIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_left_hip ->WaitForHomingAttained(&str_ErrorCode);
    motor_right_hip->WaitForHomingAttained(&str_ErrorCode);

    motor_left_knee->calibration(0, HM_POSITIVE_LIMIT_SWITCH, &str_ErrorCode);
    motor_right_knee->calibration(0, HM_NEGATIVE_LIMIT_SWITCH, &str_ErrorCode);
}


void qt_exoskeleton::on_pushButton_standing_clicked()
{
    QString str_ErrorCode;
    motor_left_hip  ->MoveToPosition(0, true, &str_ErrorCode);
    motor_right_hip ->MoveToPosition(0, true, &str_ErrorCode);
    motor_left_knee ->MoveToPosition(-5, true, &str_ErrorCode);
    motor_right_knee->MoveToPosition(5, true, &str_ErrorCode);

}

void qt_exoskeleton::on_pushButton_sitting_clicked()
{
    QString str_ErrorCode;
    //左腳全部要負號
    motor_left_hip  ->MoveToPosition(-90, true, &str_ErrorCode);
    motor_right_hip ->MoveToPosition(90, true, &str_ErrorCode);
    motor_left_knee ->MoveToPosition(-90, true, &str_ErrorCode);
    motor_right_knee->MoveToPosition(90, true, &str_ErrorCode);
}

void qt_exoskeleton::on_pushButton_extension_clicked()
{
    QString str_ErrorCode;
    //左腳全部要負號
    motor_left_hip  ->MoveToPosition(-1*  left_hip_extension_limit, true, &str_ErrorCode);
    motor_right_hip ->MoveToPosition(    right_hip_extension_limit, true, &str_ErrorCode);
    motor_left_knee ->MoveToPosition(-1* left_knee_extension_limit, true, &str_ErrorCode);
    motor_right_knee->MoveToPosition(   right_knee_extension_limit, true, &str_ErrorCode);
}

void qt_exoskeleton::on_pushButton_flexion_clicked()
{
    QString str_ErrorCode;
    //左腳全部要負號
    motor_left_hip  ->MoveToPosition(-1*  left_hip_flexion_limit, true, &str_ErrorCode);
    motor_right_hip ->MoveToPosition(    right_hip_flexion_limit, true, &str_ErrorCode);
    motor_left_knee ->MoveToPosition(-1* left_knee_flexion_limit, true, &str_ErrorCode);
    motor_right_knee->MoveToPosition(   right_knee_flexion_limit, true, &str_ErrorCode);
}


void qt_exoskeleton::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_W)
    {
        ui->textBrowser->append("Key W Pressed");
    }
    if(event->key() == Qt::Key_PageUp)
    {
        ui->textBrowser->append("Key PageUp Pressed & Start Walking");
        this->on_pushButton_StartModel_clicked();
    }
}

void qt_exoskeleton::on_pushButton_StartModel_clicked()
{
    QString str_ErrorCode;
    static int step = 0;
    if(step >= model_left_hip_angle_mean.size())
        step = 0;

    if(motor_left_hip->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_left_hip_angle_mean.at(step) > left_hip_flexion_limit-5){
            target_position = left_hip_flexion_limit-5;
        }else if(model_left_hip_angle_mean.at(step) < left_hip_extension_limit+5){
            target_position = left_hip_extension_limit+5;
        }else{
            target_position = model_left_hip_angle_mean.at(step);
        }
        target_position *= -1.0; //if this is left
        ui->textBrowser->append("left_hip = " + QString::number(model_left_hip_angle_mean.at(step)));
        motor_left_hip->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        ui->textBrowser->append("motor_left_hip FAIL!!!!!");}

    if(motor_right_hip->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_right_hip_angle_mean.at(step) > right_hip_flexion_limit-5){
            target_position = right_hip_flexion_limit-5;
        }else if(model_right_hip_angle_mean.at(step) < right_hip_extension_limit+5){
            target_position = right_hip_extension_limit+5;
        }else{
            target_position = model_right_hip_angle_mean.at(step);
        }
        ui->textBrowser->append("right_hip = " + QString::number(model_right_hip_angle_mean.at(step)));
        motor_right_hip->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        ui->textBrowser->append("motor_right_hip FAIL!!!!!");}

    if(motor_left_knee->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_left_knee_angle_mean.at(step) > left_knee_flexion_limit-5){
            target_position = left_knee_flexion_limit-5;
        }else if(model_left_knee_angle_mean.at(step) < left_knee_extension_limit+5){
            target_position = left_knee_extension_limit+5;
        }else{
            target_position = model_left_knee_angle_mean.at(step);
        }
        target_position *= -1.0; //if this is left
        ui->textBrowser->append("left_knee = " + QString::number(model_left_knee_angle_mean.at(step)));
        motor_left_knee->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        ui->textBrowser->append("motor_left_knee FAIL!!!!!");}

        if(motor_right_knee->getEnableState(&str_ErrorCode)){
        double target_position;
        if(model_right_knee_angle_mean.at(step) > right_knee_flexion_limit-5){
            target_position = right_knee_flexion_limit-5;
        }else if(model_right_knee_angle_mean.at(step) < right_knee_extension_limit+5){
            target_position = right_knee_extension_limit+5;
        }else{
            target_position = model_right_knee_angle_mean.at(step);
        }
        ui->textBrowser->append("right_knee = " + QString::number(model_right_knee_angle_mean.at(step)));
        motor_right_knee->MoveToPosition(target_position, true, &str_ErrorCode);}
    else{
        ui->textBrowser->append("motor_right_knee FAIL!!!!!");}


    ui->textBrowser->append("step = " + QString::number(step));
    step += 100;

}

void qt_exoskeleton::on_pushButton_loadModel_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"/",tr("Model (*.model)"));

    if(filename.isEmpty())
    {
        ui->textBrowser->append("No File");
        return;
    }

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->textBrowser->append("open file fail");
        return;
    }else{
        ui->textBrowser->append("open file OK");
    }
    model_left_hip_angle_mean.clear();
    model_right_hip_angle_mean.clear();
    model_left_knee_angle_mean.clear();
    model_right_knee_angle_mean.clear();
    model_left_hip_angle_std.clear();
    model_right_hip_angle_std.clear();
    model_left_knee_angle_std.clear();
    model_right_knee_angle_std.clear();

    while (!file.atEnd()) {
        QString line = file.readLine();
        QStringList qs_list = line.split(',');

        model_left_hip_angle_mean.push_back(qs_list.at(0).toDouble());
        model_left_hip_angle_std.push_back(qs_list.at(1).toDouble());
        model_right_hip_angle_mean.push_back(qs_list.at(2).toDouble());
        model_right_hip_angle_std.push_back(qs_list.at(3).toDouble());
        model_left_knee_angle_mean.push_back(qs_list.at(4).toDouble());
        model_left_knee_angle_std.push_back(qs_list.at(5).toDouble());
        model_right_knee_angle_mean.push_back(qs_list.at(6).toDouble());
        model_right_knee_angle_std.push_back(qs_list.at(7).toDouble());
    }




    std::vector<double> time;
    for(int i = 0; i<model_left_hip_angle_mean.size(); i++){time.push_back(i);}

    curve_left_hip.setSamples(time.data(), model_left_hip_angle_mean.data(), model_left_hip_angle_mean  .size());
    curve_left_hip.setPen( Qt::blue, 2 );
    curve_left_hip.attach( ui->qwtPlot_motion_model );

    curve_right_hip.setSamples(time.data(), model_right_hip_angle_mean.data(), model_right_hip_angle_mean .size());
    curve_right_hip.setPen( Qt::red, 2 ),
            curve_right_hip.attach( ui->qwtPlot_motion_model );


    curve_left_knee.setSamples(time.data(), model_left_knee_angle_mean.data(), model_left_knee_angle_mean.size());
    curve_left_knee.setPen( Qt::green, 2 );
    curve_left_knee.attach( ui->qwtPlot_motion_model );

    curve_right_knee.setSamples(time.data(), model_right_knee_angle_mean.data(), model_right_knee_angle_mean.size());
    curve_right_knee.setPen( Qt::darkYellow, 2 );
    curve_right_knee.attach( ui->qwtPlot_motion_model );


    for ( int axis = 0; axis < QwtPlot::axisCnt; axis++ )
        ui->qwtPlot_motion_model->setAxisAutoScale(axis);



    //    ui->textBrowser->append(QString::number(model_left_hip_angle_mean.size()));
    ui->qwtPlot_motion_model->replot();

    ui->textBrowser->append("Load Model OK");


    ui->pushButton_StartModel->setEnabled(true);

}
