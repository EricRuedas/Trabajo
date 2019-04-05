#include "screenpersonajes.h"
#include "ui_screenpersonajes.h"
#include "screencombate.h"

screenpersonajes::screenpersonajes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::screenpersonajes)
{
    ui->setupUi(this);

    // Creación de las opciones del comboBox y incorporación de iconos del personaje:

    ui->seleccion1->setIconSize(QSize(50,50));
    ui->seleccion2->setIconSize(QSize(50,50));
    ui->seleccion3->setIconSize(QSize(50,50));
    ui->seleccion4->setIconSize(QSize(50,50));
    ui->seleccion5->setIconSize(QSize(50,50));
    ui->seleccion6->setIconSize(QSize(50,50));

    ui->seleccion1->addItem(QIcon(":/mini/miniguerrero.png"),"Guerrero");
    ui->seleccion1->addItem(QIcon(":/mini/minimago.png"),"Mago");
    ui->seleccion1->addItem(QIcon(":/mini/minimago.png"),"Clérigo");
    ui->seleccion2->addItem(QIcon(":/mini/miniguerrero.png"),"Guerrero");
    ui->seleccion2->addItem(QIcon(":/mini/minimago.png"),"Mago");
    ui->seleccion2->addItem(QIcon(":/mini/minimago.png"),"Clérigo");
    ui->seleccion3->addItem(QIcon(":/mini/miniguerrero.png"),"Guerrero");
    ui->seleccion3->addItem(QIcon(":/mini/minimago.png"),"Mago");
    ui->seleccion3->addItem(QIcon(":/mini/minimago.png"),"Clérigo");
    ui->seleccion4->addItem(QIcon(":/mini/miniguerrero.png"),"Guerrero");
    ui->seleccion4->addItem(QIcon(":/mini/minimago.png"),"Mago");
    ui->seleccion4->addItem(QIcon(":/mini/minimago.png"),"Clérigo");
    ui->seleccion5->addItem(QIcon(":/mini/miniguerrero.png"),"Guerrero");
    ui->seleccion5->addItem(QIcon(":/mini/minimago.png"),"Mago");
    ui->seleccion5->addItem(QIcon(":/mini/minimago.png"),"Clérigo");
    ui->seleccion6->addItem(QIcon(":/mini/miniguerrero.png"),"Guerrero");
    ui->seleccion6->addItem(QIcon(":/mini/minimago.png"),"Mago");
    ui->seleccion6->addItem(QIcon(":/mini/minimago.png"),"Clérigo");


    // Para cambiar el tamaño de la letra de las opciones del comboBox:

    QFont font;
    font.setPointSize(font.pointSize() + 10);
    ui->seleccion1->setFont(font);
    ui->seleccion2->setFont(font);
    ui->seleccion3->setFont(font);
    ui->seleccion4->setFont(font);
    ui->seleccion5->setFont(font);
    ui->seleccion6->setFont(font);
}

screenpersonajes::~screenpersonajes()
{
    delete ui;
}

void screenpersonajes::on_startcombatbutton_clicked()
{
    ScreenCombate c;
    c.setModal(true);
    c.exec();
}

void screenpersonajes::on_volvermenubutton_clicked()
{
    close();
}
