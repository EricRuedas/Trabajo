#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screencombate.h"
#include "screenpersonajes.h"
#include "reglas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SkipButton_clicked()
{
    // Se cierra la ventana actual:
    close();
}

void MainWindow::on_BeginButton_clicked()
{
    // Se ejecuta la ventana de selección de personajes al pulsar el botón de "Elegir Personajes":
    screenpersonajes p;
    p.setModal(true);
    p.exec();
}

void MainWindow::on_RulesButton_clicked()
{
    // Se ejecuta la ventana de la explicación del juego al pulsar el botón de "Reglas del Juego":
    reglas r;
    r.setModal(true);
    r.exec();
}
