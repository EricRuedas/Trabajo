#ifndef SCREENCOMBATE_H
#define SCREENCOMBATE_H

#include <QDialog>
#include "personajes.h"
#include <QVector>
#include <memory>
//Se incluyen para hacer vectores con punteros inteligentes

namespace Ui {
class ScreenCombate;
}

class ScreenCombate : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenCombate(QWidget *parent = 0);
    ~ScreenCombate();
    QVector<std::shared_ptr<Personaje>> equipo1;
    QVector<std::shared_ptr<Personaje>> equipo2;

private slots:

    void on_Salir_clicked();

    void on_usar1_clicked();

    void on_usar2_clicked();

    void ActualizarPantalla();

    void ActualizarMenu();

    void on_cambiar1_clicked();

    void on_cambiar2_clicked();

    int ComprobarEquipo(QVector<std::shared_ptr<Personaje>>);

private:
    Ui::ScreenCombate *ui;
};

#endif // SCREENCOMBATE_H
