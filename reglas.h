#ifndef REGLAS_H
#define REGLAS_H

#include <QDialog>

namespace Ui {
class reglas;
}

class reglas : public QDialog
{
    Q_OBJECT

public:
    explicit reglas(QWidget *parent = 0);
    ~reglas();

private slots:
    void on_pushButton_clicked();

private:
    Ui::reglas *ui;
};

#endif // REGLAS_H
