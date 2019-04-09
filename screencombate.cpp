#include "screencombate.h"
#include "ui_screencombate.h"
#include "personajes.h"
#include "screenpersonajes.h"

#include <QVector>
#include <QDebug>
#include <QApplication>
#include <QThread>

QString porcentaje, formatobarravida, formatobarrapoder,nequi1[3],nequi2[3];
int pj1=0,pj2=0,turno=1;

ScreenCombate::ScreenCombate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenCombate)
{
    ui->setupUi(this);

    // Para el fondo de batalla:

    QPixmap fondo(":/mini/fondo.jpeg");
    ui->picfondo->setPixmap(fondo);


    // Para cambiar los colores y diseños de los QProgressBar:

    QString st1 = QString ("QProgressBar::chunk {""background-color: #3299cc;""}");
    st1.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
    ui->barrapoder1->setStyleSheet(st1);
    ui->barrapoder2->setStyleSheet(st1);

    QString st2 = QString ("QProgressBar::chunk {""background-color: #00ff00;""}");
    st2.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
    ui->barravida1->setStyleSheet(st2);
    ui->barravida2->setStyleSheet(st2);


    // Creamos a los personajes

    equipo1.push_back(std::make_shared<Guerrero>());
    equipo1.push_back(std::make_shared<Mago>());
    equipo1.push_back(std::make_shared<Clerigo>());
    equipo2.push_back(std::make_shared<Guerrero>());
    equipo2.push_back(std::make_shared<Mago>());
    equipo2.push_back(std::make_shared<Clerigo>());

    nequi1[0]="Guerrero 1";
    nequi1[1]="Mago 1";
    nequi1[2]="Clerigo 1";
    nequi2[0]="Guerrero 2";
    nequi2[1]="Mago 2";
    nequi2[2]="Clerigo 2";


    //qDebug("Barra:%d\n",ui->barrapoder1->value());
    // Para ajustar la barra de vida y poder:
    ActualizarPantalla();


    //Configuramos el combate
    ActualizarMenu();
    ui->mensaje1->setText("Turno del jugador 1");
}

ScreenCombate::~ScreenCombate()
{
    delete ui;
}

void ScreenCombate::on_Salir_clicked()
{
    close();
}

void ScreenCombate::on_usar1_clicked()
{
    if (turno==1){
        if (equipo1[pj1]->PP>=equipo1[pj1]->costes[ui->comboBoxu1->currentIndex()]){
            equipo1[pj1]->Habilidad(ui->comboBoxu1->currentIndex(), equipo2[pj2].get(),equipo1);
            //La animación de combate
            ui->picpersonaje1->setPixmap(equipo1[pj1]->im_ataque1);
            ui->mensaje1->setText(nequi1[pj1]+" usó "+ui->comboBoxu1->currentText());
            qApp->processEvents();

            //Aquí va el delay
            QThread Q;
            Q.msleep(1500);
            //Fin del delay

            ui->picpersonaje1->setPixmap(equipo1[pj1]->im_normal1);
            if (equipo2[pj2]->HP<=0){
                equipo2[pj2]->HP=0;
                nequi2[pj2]=ui->comboBoxc2->itemText(pj2)+" (D)";
                ui->comboBoxc2->setItemText(pj2,nequi2[pj2]);
            }
            ui->barrapoder1->setValue(equipo1[pj1]->PP);
            ui->barravida2->setValue(equipo2[pj2]->HP);
            int v=ComprobarEquipo(equipo2);
            if(v==0){
                turno=5;
                ui->mensaje1->setText("¡Gana el jugador 1!");
            }
            else if(equipo2[pj2]->HP==0){
                turno=4;
                ui->mensaje1->setText("Jugador 2, cambie a otro personaje");
            }else{
                turno=2;
                ui->mensaje1->setText("Turno del jugador 2");
            }
        }
        else{ui->mensaje1->setText("Jugador 1, no tienes suficientes PH para usar eso");}
    }
}

void ScreenCombate::on_usar2_clicked()
{
    if (turno==2){
        if (equipo2[pj2]->PP>=equipo2[pj2]->costes[ui->comboBoxu2->currentIndex()]){
            equipo2[pj2]->Habilidad(ui->comboBoxu2->currentIndex(), equipo1[pj1].get(),equipo2);

            //La animación de combate
            ui->picpersonaje2->setPixmap(equipo2[pj2]->im_ataque2);
            ui->mensaje1->setText(nequi2[pj2]+" usó "+ui->comboBoxu2->currentText());
            qApp->processEvents(); //Actualizar las imágenes

            //Aquí va el delay
            QThread Q;
            Q.msleep(1500);
            //Fin del delay

            ui->picpersonaje2->setPixmap(equipo2[pj2]->im_normal2);

            if (equipo1[pj1]->HP<=0){
                equipo1[pj1]->HP=0;
                nequi1[pj1]=ui->comboBoxc1->itemText(pj1)+" (D)";
                ui->comboBoxc1->setItemText(pj1,nequi1[pj1]);
            }
            ui->barrapoder2->setValue(equipo2[pj2]->PP);
            ui->barravida1->setValue(equipo1[pj1]->HP);
            int v=ComprobarEquipo(equipo1);
            if(v==0){
                turno=5;
                ui->mensaje1->setText("¡Gana el jugador 2!");
            }
            else if(equipo1[pj1]->HP==0){
                turno=3;
                ui->mensaje1->setText("Jugador 1, cambie a otro personaje");
            }else{
                turno=1;
                ui->mensaje1->setText("Turno del jugador 1");
            }
        }
        else{ui->mensaje1->setText("Jugador 2, no tienes suficientes PH para usar eso");}
    }
}

void ScreenCombate::ActualizarPantalla(){
    ui->barrapoder1->setMaximum(equipo1[pj1]->PP_max);
    ui->barrapoder1->setValue(equipo1[pj1]->PP);
    ui->barravida1->setMaximum(equipo1[pj1]->HP_max);
    ui->barravida1->setValue(equipo1[pj1]->HP);
    ui->barrapoder2->setMaximum(equipo2[pj2]->PP_max);
    ui->barrapoder2->setValue(equipo2[pj2]->PP);
    ui->barravida2->setMaximum(equipo2[pj2]->HP_max);
    ui->barravida2->setValue(equipo2[pj2]->HP);

    porcentaje = QString::number(equipo1[pj1]->HP_max,'g',20);
    formatobarravida = "%v/"+porcentaje;
    ui->barravida1->setFormat(formatobarravida);
    porcentaje = QString::number(equipo2[pj2]->HP_max,'g',20);
    formatobarravida = "%v/"+porcentaje;
    ui->barravida2->setFormat(formatobarravida);
    porcentaje = QString::number(equipo1[pj1]->PP_max,'g',20);
    formatobarrapoder = "%v/"+porcentaje;
    ui->barrapoder1->setFormat(formatobarrapoder);
    porcentaje = QString::number(equipo2[pj2]->PP_max,'g',20);
    formatobarrapoder = "%v/"+porcentaje;
    ui->barrapoder2->setFormat(formatobarrapoder);

    ui->picpersonaje1->setPixmap(equipo1[pj1]->im_normal1);
    ui->picpersonaje2->setPixmap(equipo2[pj2]->im_normal2);
}

void ScreenCombate::ActualizarMenu(){
    ui->comboBoxu1->clear();
    for(int i=0;i<equipo1[pj1]->hab.count();i++){
        ui->comboBoxu1->addItem(equipo1[pj1]->hab.itemText(i));
    }

    ui->comboBoxu2->clear();
    for(int i=0;i<equipo2[pj2]->hab.count();i++){
        ui->comboBoxu2->addItem(equipo2[pj2]->hab.itemText(i));
    }

    ui->comboBoxc1->clear();
    for(int i=0;i<3;i++){
        ui->comboBoxc1->addItem(nequi1[i]);
    }

    ui->comboBoxc2->clear();
    for(int i=0;i<3;i++){
        ui->comboBoxc2->addItem(nequi2[i]);
    }
}

void ScreenCombate::on_cambiar1_clicked()
{
    if (turno==1 || turno==3){
        int i=ui->comboBoxc1->currentIndex();
        if(i!=pj1 && equipo1[i]->HP>0){
            pj1=i;
            ActualizarMenu();
            ActualizarPantalla();
            if(turno==1){
                turno=2;
                ui->mensaje1->setText("Turno del jugador 2");
            }
            else{
                turno=1;
                ui->mensaje1->setText("Turno del jugador 1");
            }
        }
    }
}


void ScreenCombate::on_cambiar2_clicked()
{
    if (turno==2 || turno==4){
        int i=ui->comboBoxc2->currentIndex();
        if(i!=pj2 && equipo2[i]->HP>0){
            pj2=i;
            ActualizarMenu();
            ActualizarPantalla();
            if(turno==2){
                turno=1;
                ui->mensaje1->setText("Turno del jugador 1");
            }
            else{
                turno=2;
                ui->mensaje1->setText("Turno del jugador 2");
            }
        }
    }
}

int ScreenCombate::ComprobarEquipo(QVector<std::shared_ptr<Personaje>> team){
    int n=team.size(),v=0;
    for(int i=0;i<n;i++){
        if(team[i]->HP>0){v=1;}
    }
    return v;
}

void ScreenCombate::ActualizarEquipo(QVector<int> pjs){
    equipo1.clear();
    equipo2.clear();
    int g=1,m=1,c=1;
    for (int i=0; i<3; i++){
        if (pjs[i]==0){
            equipo1.push_back(std::make_shared<Guerrero>());
            nequi1[i]="Guerrero "+QString::number(g);
            g++;
        }
        else if (pjs[i]==1){
            equipo1.push_back(std::make_shared<Mago>());
            nequi1[i]="Mago "+QString::number(m);
            m++;
        }
        else {
            equipo1.push_back(std::make_shared<Clerigo>());
            nequi1[i]="Clérigo "+QString::number(c);
            c++;
        }

    }

    for (int i=3; i<6; i++){
        if (pjs[i]==0){
            equipo2.push_back(std::make_shared<Guerrero>());
            nequi2[i-3]="Guerrero "+QString::number(g);
            g++;
        }
        else if (pjs[i]==1){
            equipo2.push_back(std::make_shared<Mago>());
            nequi2[i-3]="Mago "+QString::number(m);
            m++;
        }
        else {
            equipo2.push_back(std::make_shared<Clerigo>());
            nequi2[i-3]="Clérigo "+QString::number(c);
            c++;
        }
    }

    ActualizarPantalla();
    ActualizarMenu();
}
