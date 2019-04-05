#ifndef SCREENPERSONAJES_H
#define SCREENPERSONAJES_H

#include <QDialog>

namespace Ui {
class screenpersonajes;
}

class screenpersonajes : public QDialog
{
    Q_OBJECT

public:
    explicit screenpersonajes(QWidget *parent = 0);
    ~screenpersonajes();

private slots:
    void on_startcombatbutton_clicked();

    void on_volvermenubutton_clicked();

private:
    Ui::screenpersonajes *ui;
};

#endif // SCREENPERSONAJES_H
