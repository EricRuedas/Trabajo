#include "screencombate.h"
#include "ui_screencombate.h"

int vida1,poder1,maxvida1,maxpoder1,vida2,poder2,maxvida2,maxpoder2;
QString porcentaje, formatobarravida, formatobarrapoder;

ScreenCombate::ScreenCombate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenCombate)
{
    ui->setupUi(this);

    // Para las imagenes de los personajes:

    QPixmap pic1("C:/Users/ericr/Downloads/4ºGRADOUNIVERSIDAD/InformaticaAvanzada/TrabajoFinal/mago1_quieto.png");
    ui->picpersonaje1->setPixmap(pic1);

    QPixmap pic2("C:/Users/ericr/Downloads/4ºGRADOUNIVERSIDAD/InformaticaAvanzada/TrabajoFinal/mago2_ataque.png");
    ui->picpersonaje2->setPixmap(pic2);


    // Para cambiar los colores y diseños de los QProgressBar:

    QString st1 = QString ("QProgressBar::chunk {""background-color: #3299cc;""}");
    st1.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
    ui->barrapoder1->setStyleSheet(st1);
    ui->barrapoder2->setStyleSheet(st1);

    QString st2 = QString ("QProgressBar::chunk {""background-color: #00ff00;""}");
    st2.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
    ui->barravida1->setStyleSheet(st2);
    ui->barravida2->setStyleSheet(st2);


    // Para ajustar la barra de vida y poder:

    vida1=25; maxvida1=100; poder1=9; maxpoder1=10;
    vida2=15; maxvida2=100; poder2=2; maxpoder2=10;
    ui->barrapoder1->setValue(poder1);
    ui->barrapoder1->setMaximum(maxpoder1);
    ui->barravida1->setValue(vida1);
    ui->barravida1->setMaximum(maxvida1);
    ui->barrapoder2->setValue(poder2);
    ui->barrapoder2->setMaximum(maxpoder2);
    ui->barravida2->setValue(vida2);
    ui->barravida2->setMaximum(maxvida2);

    porcentaje = QString::number(maxvida1,'g',20);
    formatobarravida = "%v/"+porcentaje;
    ui->barravida1->setFormat(formatobarravida);
    porcentaje = QString::number(maxvida2,'g',20);
    formatobarravida = "%v/"+porcentaje;
    ui->barravida2->setFormat(formatobarravida);
    porcentaje = QString::number(maxpoder1,'g',20);
    formatobarrapoder = "%v/"+porcentaje;
    ui->barrapoder1->setFormat(formatobarrapoder);
    porcentaje = QString::number(maxpoder2,'g',20);
    formatobarrapoder = "%v/"+porcentaje;
    ui->barrapoder2->setFormat(formatobarrapoder);
}

ScreenCombate::~ScreenCombate()
{
    delete ui;
}

void ScreenCombate::on_Salir_clicked()
{
    close();
}
