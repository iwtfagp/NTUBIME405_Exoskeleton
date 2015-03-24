#ifndef QT_EXOSKELETON_H
#define QT_EXOSKELETON_H

#include <QMainWindow>

namespace Ui {
class qt_exoskeleton;
}

class qt_exoskeleton : public QMainWindow
{
    Q_OBJECT

public:
    explicit qt_exoskeleton(QWidget *parent = 0);
    ~qt_exoskeleton();

private:
    Ui::qt_exoskeleton *ui;
};

#endif // QT_EXOSKELETON_H
