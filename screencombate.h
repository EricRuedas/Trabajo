#ifndef SCREENCOMBATE_H
#define SCREENCOMBATE_H

#include <QDialog>

namespace Ui {
class ScreenCombate;
}

class ScreenCombate : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenCombate(QWidget *parent = 0);
    ~ScreenCombate();

private slots:

    void on_Salir_clicked();

private:
    Ui::ScreenCombate *ui;
};

#endif // SCREENCOMBATE_H
