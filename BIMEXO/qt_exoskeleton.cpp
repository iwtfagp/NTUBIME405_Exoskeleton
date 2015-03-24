#include "qt_exoskeleton.h"
#include "ui_qt_exoskeleton.h"

qt_exoskeleton::qt_exoskeleton(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qt_exoskeleton)
{
    ui->setupUi(this);
}

qt_exoskeleton::~qt_exoskeleton()
{
    delete ui;
}
