#include "qt_exoskeleton.h"
#include "ui_qt_exoskeleton.h"

#define PI 3.14159265


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




    //parameter mode++


    //    ui->qwtPlot_motion_model_parameter_sit->setTitle( "Sit" );
    ui->qwtPlot_motion_model_parameter_sit->setCanvasBackground( Qt::white );
    //    ui->qwtPlot_motion_model_parameter_sit->setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
    ui->qwtPlot_motion_model_parameter_sit->insertLegend( new QwtLegend() );
    //    sit.curve_left_hip.setTitle("Left Hip");
    //    sit.curve_right_hip.setTitle("Right Hip");
    //    sit.curve_left_knee.setTitle("Left Knee");
    //    sit.curve_right_knee.setTitle("Right Knee");

    //    ui->qwtPlot_motion_model_parameter_stand->setTitle( "Down" );
    ui->qwtPlot_motion_model_parameter_stand->setCanvasBackground( Qt::white );
    //    ui->qwtPlot_motion_model_parameter_stand->setAxisScale( QwtPlot::yLeft, 0.0, 100.0 );
    ui->qwtPlot_motion_model_parameter_stand->insertLegend( new QwtLegend() );
    //    stand.curve_left_hip.setTitle("Left Hip");
    //    stand.curve_right_hip.setTitle("Right Hip");
    //    stand.curve_left_knee.setTitle("Left Knee");
    //    stand.curve_right_knee.setTitle("Right Knee");

    //    ui->qwtPlot_motion_model_parameter_walk->setTitle( "Down" );
    ui->qwtPlot_motion_model_parameter_walk->setCanvasBackground( Qt::white );
    //    ui->qwtPlot_motion_model_parameter_walk->setAxisScale( QwtPlot::yLeft, 0.0, 10.0 );
    ui->qwtPlot_motion_model_parameter_walk->insertLegend( new QwtLegend() );
    //    walk.curve_left_hip.setTitle("Left Hip");
    //    walk.curve_right_hip.setTitle("Right Hip");
    //    walk.curve_left_knee.setTitle("Left Knee");
    //    walk.curve_right_knee.setTitle("Right Knee");
    //parameter mode--


    //Set Timer
    timer_mpu = new QTimer(this);
    timer_mpu->stop();
    timer_mpu->setInterval(20);
    QObject::connect(timer_mpu, SIGNAL(timeout()), this, SLOT(updateMpuView()));


    timer = new QTimer(this);
    timer_model = new QTimer(this);

    QObject::connect(timer_model, SIGNAL(timeout()), this, SLOT(updateModel()));
    timer_model->setInterval(50);

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
    motor_left_knee ->WaitForHomingAttained(&str_ErrorCode);
    motor_right_knee->WaitForHomingAttained(&str_ErrorCode);
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
    //    if(ui->pushButton_StartModel->isEnabled()){
    if(event->key() == Qt::Key_Down)
    {
        ui->textBrowser->append("Feel Bad");
        this->on_pushButton_record_clicked();
    }
    if(event->key() == Qt::Key_Up)
    {
        ui->textBrowser->append("Period");
        this->on_pushButton_period_clicked();
    }
    //    }
}

void qt_exoskeleton::on_pushButton_StartModel_clicked()
{
    QString str_ErrorCode;
    static int step = 0;
    if(step >= model_left_hip_angle_mean.size())
        step = 0;
    if(ui->checkBox_motor_enable->isChecked())
    {
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
    }

    ui->textBrowser->append("step = " + QString::number(step));
    step += 100;

}

void qt_exoskeleton::on_pushButton_loadModel_clicked()
{

    if(!ui->checkBox_continue->isChecked())
    {
        filename = QFileDialog::getOpenFileName(this, tr("Open File"),"/",tr("Model (*.model)"));

        dir_path = filename.mid(0,filename.lastIndexOf('/')+1);

        ui->checkBox_continue->setChecked(true);
    }


    if(filename.isEmpty())
    {
        ui->textBrowser->append("No File");
        ui->checkBox_continue->setChecked(false);
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

        model_left_hip_angle_mean.push_back(qs_list.at(1).toDouble());
        model_left_hip_angle_std.push_back(qs_list.at(2).toDouble());
        model_right_hip_angle_mean.push_back(qs_list.at(3).toDouble());
        model_right_hip_angle_std.push_back(qs_list.at(4).toDouble());
        model_left_knee_angle_mean.push_back(qs_list.at(5).toDouble());
        model_left_knee_angle_std.push_back(qs_list.at(6).toDouble());
        model_right_knee_angle_mean.push_back(qs_list.at(7).toDouble());
        model_right_knee_angle_std.push_back(qs_list.at(8).toDouble());
    }
    if(ui->checkBox_RNG->isChecked())
    {
        for(int i = 0; i < model_left_hip_angle_mean.size(); i++){
            std::default_random_engine generator_left_hip((unsigned int)time(0));
            std::normal_distribution<double> distribution_left_hip(model_left_hip_angle_mean.at(i),model_left_hip_angle_std.at(i));
            double model_left_hip_angle_mean_new = distribution_left_hip(generator_left_hip);
            model_left_hip_angle_mean.at(i) = model_left_hip_angle_mean_new;

            std::default_random_engine generator_left_knee((unsigned int)time(0));
            std::normal_distribution<double> distribution_left_knee(model_left_knee_angle_mean.at(i),model_left_knee_angle_std.at(i));
            double model_left_knee_angle_mean_new = distribution_left_knee(generator_left_knee);
            model_left_knee_angle_mean.at(i) = model_left_knee_angle_mean_new;

            std::default_random_engine generator_right_hip((unsigned int)time(0));
            std::normal_distribution<double> distribution_right_hip(model_right_hip_angle_mean.at(i),model_right_hip_angle_std.at(i));
            double model_right_hip_angle_mean_new = distribution_right_hip(generator_right_hip);
            model_right_hip_angle_mean.at(i) = model_right_hip_angle_mean_new;

            std::default_random_engine generator_right_knee((unsigned int)time(0));
            std::normal_distribution<double> distribution_right_knee(model_right_knee_angle_mean.at(i),model_right_knee_angle_std.at(i));
            double model_right_knee_angle_mean_new = distribution_right_knee(generator_right_knee);
            model_right_knee_angle_mean.at(i) = model_right_knee_angle_mean_new;

        }
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

void qt_exoskeleton::on_pushButton_record_clicked()
{
    ui->pushButton_record->setDown(true);
}
void qt_exoskeleton::on_pushButton_period_clicked()
{
    if(!timer_model->isActive()){
        timer_model->start();

        if(!dir_path.isEmpty())
        {
            //    get current date
            QLocale locale  = QLocale(QLocale::English);
            QDate date = QDate::currentDate();
            QString dateString = locale.toString(date, "yyyyMMdd");
            QTime time = QTime::currentTime();
            QString timeString = locale.toString(time, "hhmmss");
            QString username = ui->lineEdit_username->text();
            QString filepath = dir_path + username + "_" + dateString + "_" + timeString + "_forML" +".model";

            ui->textBrowser->append("open a new filepath");
            ui->textBrowser->append(filepath);

            file_new_model = new QFile(filepath);
            file_new_model->open(QIODevice::WriteOnly | QIODevice::Text);

            for(int i = 0; i < data_number; i++)
            {
                ML_lable[i] = 0;
            }
        }
    }

}
void qt_exoskeleton::updateModel()
{
    static int step = 0;

    int check = ui->pushButton_record->isDown();
    ui->pushButton_record->setDown(false);
    ui->textBrowser->append(QString::number(step) + "\t = " + QString::number(check));
    ML_lable[step] = check;


    QString str_ErrorCode;
    //enable the motor
    //限制動作部分
    if(ui->checkBox_motor_enable->isChecked())
    {
        //左腳髖關節的角度限制
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

    }

    step += ui->doubleSpinBox_speed->value();
    if(step >= model_left_hip_angle_mean.size())
    {
        step = 0;
        timer_model->stop();
        if(!dir_path.isEmpty())
        {
            QTextStream out(file_new_model);
            for(int i = 0; i<model_left_hip_angle_mean.size(); i++)
            {
                out << ML_lable[i] << ",";
                out << model_left_hip_angle_mean.at(i) << ","
                    << model_left_hip_angle_std.at(i) << ","
                    << model_right_hip_angle_mean.at(i) << ","
                    << model_right_hip_angle_std.at(i) << ","
                    << model_left_knee_angle_mean.at(i) << ","
                    << model_left_knee_angle_std.at(i) << ","
                    << model_right_knee_angle_mean.at(i) << ","
                    << model_right_knee_angle_std.at(i) <<endl;
            }
            ui->textBrowser->append("ML_model save");
            file_new_model->close();
        }
        this->on_pushButton_loadModel_clicked();
    }

    //    count += 5000;
}

void qt_exoskeleton::on_pushButton_parameter_model_clicked()
{

    const int gait_number = 1000;



    //walking
    const int phase = 50;
    walk.hip_sin_x = 0;
    walk.hip_sin_y = 10;
    walk.hip_sin_amp = 30;

    walk.knee_sin_x = 80;
    walk.knee_sin_y = 10;
    walk.knee_sin_amp = 65;
    walk.knee_gaussian_x = 20;
    walk.knee_gaussian_y = 0;
    walk.knee_gaussian_amp = 10;
    walk.knee_gaussian_sigma = 20;

    sin_wave(&walk.left_hip_angle,
             walk.hip_sin_amp,
             walk.hip_sin_x,
             walk.hip_sin_y,
             gait_number);

    sin_wave(&walk.left_knee_angle,
             walk.knee_sin_amp,
             walk.knee_sin_x,
             walk.knee_sin_y,
             gait_number);

    gaussian_wave(&walk.left_knee_angle_gauss,
                  walk.knee_gaussian_amp,
                  walk.knee_gaussian_x,
                  walk.knee_gaussian_y,
                  walk.knee_gaussian_sigma,
                  gait_number);

    wave_max(&walk.left_knee_angle, &walk.left_knee_angle_gauss);

    sin_wave(&walk.right_hip_angle,
             walk.hip_sin_amp,
             walk.hip_sin_x+phase,
             walk.hip_sin_y,
             gait_number);

    sin_wave(&walk.right_knee_angle,
             walk.knee_sin_amp,
             walk.knee_sin_x+phase,
             walk.knee_sin_y,
             gait_number);

    gaussian_wave(&walk.right_knee_angle_gauss,
                  walk.knee_gaussian_amp,
                  walk.knee_gaussian_x+phase,
                  walk.knee_gaussian_y,
                  walk.knee_gaussian_sigma,
                  gait_number);

    wave_max(&walk.right_knee_angle, &walk.right_knee_angle_gauss);

    wave_display(&walk, gait_number);



}

void qt_exoskeleton::sin_wave(std::vector<double>* data, double amp, double x, double y, int total)
{
    data->clear();

    for(int i = 0; i<total; i++)
    {
        data->push_back((amp-y)*sin(((double(i)/total-(x+75)/100.0)*360.0)*PI/180)+y);
    }
}
void qt_exoskeleton::gaussian_wave(std::vector<double>* data, double amp, double u, double y, double sigma, int total)
{
    data->clear();
    u = u/100*total;
    for(int x = 0; x<total; x++)
    {
        double dd = x - u;
        if(dd > total/2)
        {
            dd -= total;
        }else if(dd<total/(-2))
        {
            dd +=total;
        }

        data->push_back((amp-y)*exp(-0.5*(pow((dd)/(sigma*total/100),2))));

        //        data->push_back((1.0/(sig*(pow (2*PI, 0.5))))*exp(-0.5*(pow((x-u)/(sig),2))));
    }
}

void qt_exoskeleton::wave_max(std::vector<double>* data1, std::vector<double>* data2)
{
    for(int i = 0; i<data1->size(); i++)
        if(data1->at(i)<data2->at(i))
        {
            data1->at(i) = data2->at(i);
        }
}

void qt_exoskeleton::wave_display(parameter_model* pp_model, int total)
{
    std::vector<double> time;
    for(int i = 0; i<total; i++)
    {
        time.push_back(double(i));

    }
    pp_model->curve_left_hip.setSamples(time.data(), pp_model->left_hip_angle.data(), pp_model->left_hip_angle.size());
    pp_model->curve_left_hip.setPen( Qt::red, 2 );
    pp_model->curve_left_hip.attach( ui->qwtPlot_motion_model_parameter_walk );
    ui->qwtPlot_motion_model_parameter_walk->replot();

    pp_model->curve_left_knee.setSamples(time.data(), pp_model->left_knee_angle.data(), pp_model->left_knee_angle.size());
    pp_model->curve_left_knee.setPen( Qt::darkYellow, 2 );
    pp_model->curve_left_knee.attach( ui->qwtPlot_motion_model_parameter_walk );
    ui->qwtPlot_motion_model_parameter_walk->replot();

    pp_model->curve_right_hip.setSamples(time.data(), pp_model->right_hip_angle.data(), pp_model->right_hip_angle.size());
    pp_model->curve_right_hip.setPen( Qt::blue, 2 );
    pp_model->curve_right_hip.attach( ui->qwtPlot_motion_model_parameter_walk );
    ui->qwtPlot_motion_model_parameter_walk->replot();

    pp_model->curve_right_knee.setSamples(time.data(), pp_model->right_knee_angle.data(), pp_model->right_knee_angle.size());
    pp_model->curve_right_knee.setPen( Qt::darkGreen, 2 );
    pp_model->curve_right_knee.attach( ui->qwtPlot_motion_model_parameter_walk );
    ui->qwtPlot_motion_model_parameter_walk->replot();
}

void qt_exoskeleton::on_pushButton_parameter_IMU_clicked()
{
    mpu = new MPU_9150();
    mpu->open(ui->spinBox->value(), "MPU9150-1.dll");
    timer_mpu->start();
    ui->spinBox->setDisabled(true);
}
void qt_exoskeleton::updateMpuView()
{


    mpu->getAngle();
    Roll_angle = mpu->get_roll();
    Yaw_angle = mpu->get_yaw();



    Roll_angle_temp = Roll_angle - Roll_angle_init;
    Yaw_angle_temp = Yaw_angle - Yaw_angle_init;



    //    if(Roll_angle_temp<0)
    //        Roll_angle_temp += 360;
    //    if(Yaw_angle_temp<0)
    //        Yaw_angle_temp += 360;

    std::cout<<Roll_angle<<", "<<Yaw_angle<<std::endl;


    //    ui->Dial_1->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    //    ui->Dial_1->setValue(Roll_angle_temp);
    //    ui->Dial_2->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    //    ui->Dial_2->setValue(Yaw_angle_temp);

    ui->lcdNumber_mpu_roll->display(Roll_angle_temp);
    ui->lcdNumber_mpu_yaw->display(Yaw_angle_temp);


    QString str_state_mode;
    if(Roll_angle_temp < -5)
    {
        str_state_mode = "sitting";
    }
    else if(Roll_angle_temp < 15 && Roll_angle_temp>-5)
    {
        str_state_mode = "down";
    }
    else if(Roll_angle_temp < 40 && Roll_angle_temp>15)
    {
        str_state_mode = "up";
    }
    else if(Roll_angle_temp>40)
    {
        str_state_mode = "walking";
    }
    ui->label_state_mode->setText(str_state_mode);

    QString str_state_right;
    if(Yaw_angle_temp > 5)
    {
        str_state_right = "left";
    }
    else if(Yaw_angle_temp < -5)
    {
        str_state_right = "right";
    }
    else
    {
        str_state_right = "central";
    }
    ui->label_state_right->setText(str_state_right);



}

void qt_exoskeleton::on_pushButton_parameter_IMU_init_clicked()
{
    Roll_angle_init = Roll_angle;
    Yaw_angle_init = Yaw_angle;
}
