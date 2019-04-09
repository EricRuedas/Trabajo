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
    close();
}

void MainWindow::on_BeginButton_clicked()
{
    screenpersonajes p;
    p.setModal(true);
    p.exec();
}

void MainWindow::on_RulesButton_clicked()
{
    reglas r;
    r.setModal(true);
    r.exec();
}
