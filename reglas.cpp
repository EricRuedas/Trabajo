#include "reglas.h"
#include "ui_reglas.h"

reglas::reglas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reglas)
{
    ui->setupUi(this);
}

reglas::~reglas()
{
    delete ui;
}

void reglas::on_pushButton_clicked()
{
    close();
}
