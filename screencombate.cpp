#include "screencombate.h"
#include "ui_screencombate.h"
#include "personajes.h"
#include "screenpersonajes.h"

#include "QMediaPlayer"
#include <QVector>
#include <QDebug>
#include <QApplication>
#include <QThread>

QString porcentaje, formatobarravida, formatobarrapoder,nequi1[3],nequi2[3];
int pj1=0,pj2=0,turno=1,contador=0, contador2=0, fus=0, fus2=0, sonido;

ScreenCombate::ScreenCombate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenCombate)
{
    ui->setupUi(this);

    // Música épica de fondo:
    mediaplayer = new QMediaPlayer(this);
    mediaplayer->setMedia(QUrl("qrc:/mini/Path.mp3"));
    mediaplayer->setVolume(60);
    mediaplayer->play();

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
    contador=0; contador2=0;
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

            if (equipo1[pj1]->ID==1){
                mediaplayer2 = new QMediaPlayer(this);
                mediaplayer2->setMedia(QUrl("qrc:/mini/sword.mp3"));
                mediaplayer2->setVolume(100);
                mediaplayer2->play();
            }
            else if (equipo1[pj1]->ID==2){
                mediaplayer2 = new QMediaPlayer(this);
                mediaplayer2->setMedia(QUrl("qrc:/mini/magic.mp3"));
                mediaplayer2->setVolume(100);
                mediaplayer2->play();
            }
            else if (equipo1[pj1]->ID==3){
                mediaplayer2 = new QMediaPlayer(this);
                mediaplayer2->setMedia(QUrl("qrc:/mini/poo.mp3"));
                mediaplayer2->setVolume(100);
                mediaplayer2->play();
            }
            else {
                mediaplayer2 = new QMediaPlayer(this);
                mediaplayer2->setMedia(QUrl("qrc:/mini/laugh.mp3"));
                mediaplayer2->setVolume(100);
                mediaplayer2->play();
            }

            qApp->processEvents();

            //Aquí va el delay
            QThread Q;
            Q.msleep(1500);
            //Fin del delay

            ui->picpersonaje1->setPixmap(equipo1[pj1]->im_normal1);
            contador=contador+1;

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
                contador2=0;
                mediaplayer2 = new QMediaPlayer(this);
                mediaplayer2->setMedia(QUrl("qrc:/mini/ouch.mp3"));
                mediaplayer2->setVolume(100);
                mediaplayer2->play();
            }else{
                turno=2;
                ui->mensaje1->setText("Turno del jugador 2");
            }
        }
        else{ui->mensaje1->setText("Jugador 1, no tienes suficientes PH para usar eso");}
    }

    ActualizarPantalla();
}

void ScreenCombate::on_usar2_clicked()
{
    if (turno==2){
        if (equipo2[pj2]->PP>=equipo2[pj2]->costes[ui->comboBoxu2->currentIndex()]){
            equipo2[pj2]->Habilidad(ui->comboBoxu2->currentIndex(), equipo1[pj1].get(),equipo2);

            //La animación de combate
            ui->picpersonaje2->setPixmap(equipo2[pj2]->im_ataque2);
            ui->mensaje1->setText(nequi2[pj2]+" usó "+ui->comboBoxu2->currentText());

            if (equipo2[pj2]->ID==1){
                mediaplayer3 = new QMediaPlayer(this);
                mediaplayer3->setMedia(QUrl("qrc:/mini/sword.mp3"));
                mediaplayer3->setVolume(100);
                mediaplayer3->play();
            }
            else if (equipo2[pj2]->ID==2){
                mediaplayer3 = new QMediaPlayer(this);
                mediaplayer3->setMedia(QUrl("qrc:/mini/magic.mp3"));
                mediaplayer3->setVolume(100);
                mediaplayer3->play();
            }
            else if (equipo2[pj2]->ID==3){
                mediaplayer3 = new QMediaPlayer(this);
                mediaplayer3->setMedia(QUrl("qrc:/mini/poo.mp3"));
                mediaplayer3->setVolume(100);
                mediaplayer3->play();
            }
            else {
                mediaplayer3 = new QMediaPlayer(this);
                mediaplayer3->setMedia(QUrl("qrc:/mini/laugh.mp3"));
                mediaplayer3->setVolume(100);
                mediaplayer3->play();
            }

            qApp->processEvents(); //Actualizar las imágenes

            //Aquí va el delay
            QThread Q;
            Q.msleep(1500);
            //Fin del delay

            ui->picpersonaje2->setPixmap(equipo2[pj2]->im_normal2);
            contador2=contador2+1;

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
                contador=0;
                mediaplayer2 = new QMediaPlayer(this);
                mediaplayer2->setMedia(QUrl("qrc:/mini/ouch.mp3"));
                mediaplayer2->setVolume(100);
                mediaplayer2->play();
            }else{
                turno=1;
                ui->mensaje1->setText("Turno del jugador 1");
            }
        }
        else{ui->mensaje1->setText("Jugador 2, no tienes suficientes PH para usar eso");}
    }

    ActualizarPantalla();
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

    // Actualización de la barra y botón de fusión:

    if (contador==0 || fus==1){
        ui->fusionbarra->setValue(0);
        ui->fusiontext1->setText("");
        ui->fusion1->setEnabled(false);
    }
    else if (contador==1 && fus==0){
        QString st3 = QString ("QProgressBar::chunk {""background-color: #ff33dd;""}");
        st3.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
        ui->fusionbarra->setStyleSheet(st3);
        ui->fusionbarra->setValue(1);
    }
    else if (contador==2 && fus==0){
        QString st4 = QString ("QProgressBar::chunk {""background-color: #ff336B;""}");
        st4.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
        ui->fusionbarra->setStyleSheet(st4);
        ui->fusionbarra->setValue(2);
    }
    else {
        QString st5 = QString ("QProgressBar::chunk {""background-color: #ff3333;""}");
        st5.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
        ui->fusionbarra->setStyleSheet(st5);
        ui->fusionbarra->setValue(3);
        ui->fusiontext1->setText("¡¡FUSIÓN DISPONIBLE!!");
        ui->fusion1->setEnabled(true);
    }

    if (contador2==0 || fus2==1){
        ui->fusionbarra2->setValue(0);
        ui->fusiontext2->setText("");
        ui->fusion2->setEnabled(false);

    }
    else if (contador2==1 && fus2==0){
        QString st3 = QString ("QProgressBar::chunk {""background-color: #ff33dd;""}");
        st3.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
        ui->fusionbarra2->setStyleSheet(st3);
        ui->fusionbarra2->setValue(1);
    }
    else if (contador2==2 && fus2==0){
        QString st4 = QString ("QProgressBar::chunk {""background-color: #ff336B;""}");
        st4.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
        ui->fusionbarra2->setStyleSheet(st4);
        ui->fusionbarra2->setValue(2);
    }
    else {
        QString st5 = QString ("QProgressBar::chunk {""background-color: #ff3333;""}");
        st5.append("QProgressBar {""border: 1px solid grey;""border-radius: 2px;""text-align: center;""background: #eeeeee;""}");
        ui->fusionbarra2->setStyleSheet(st5);
        ui->fusionbarra2->setValue(3);
        ui->fusiontext2->setText("¡¡FUSIÓN DISPONIBLE!!");
        ui->fusion2->setEnabled(true);
    }
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
    ui->comboBoxf1->clear();
    for(int i=0;i<equipo1.size();i++){
        ui->comboBoxc1->addItem(nequi1[i]);
        ui->comboBoxf1->addItem(nequi1[i]);
    }

    ui->comboBoxc2->clear();
    ui->comboBoxf2->clear();
    for(int i=0;i<equipo2.size();i++){
        ui->comboBoxc2->addItem(nequi2[i]);
        ui->comboBoxf2->addItem(nequi2[i]);
    }

    ui->comboBoxc1->setCurrentIndex(pj1);
    ui->comboBoxc2->setCurrentIndex(pj2);
}

void ScreenCombate::on_cambiar1_clicked()
{
    if (turno==1 || turno==3){
        int i=ui->comboBoxc1->currentIndex();
        if(i!=pj1 && equipo1[i]->HP>0){
            pj1=i;
            if(turno==1){
                turno=2;
                contador=0;
                ActualizarMenu();
                ActualizarPantalla();
                ui->mensaje1->setText("Turno del jugador 2");
            }
            else{
                turno=1;
                ActualizarPantalla();
                ActualizarMenu();
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
            if(turno==2){
                turno=1;
                contador2=0;
                ActualizarMenu();
                ActualizarPantalla();
                ui->mensaje1->setText("Turno del jugador 1");
            }
            else{
                turno=2;
                ActualizarMenu();
                ActualizarPantalla();
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

void ScreenCombate::on_fusion1_clicked()
{
    if (turno==1 && equipo1[pj1]->HP>0 && equipo1[ui->comboBoxf1->currentIndex()]->HP>0){
        fus=0;
        if((equipo1[pj1]->ID==1 && equipo1[ui->comboBoxf1->currentIndex()]->ID==2)||(equipo1[pj1]->ID==2 && equipo1[ui->comboBoxf1->currentIndex()]->ID==1)){
            fus=1;
            equipo1.push_back(std::make_shared<MagoCachas>(equipo1[pj1].get(),equipo1[ui->comboBoxf1->currentIndex()].get()));
        } else if((equipo1[pj1]->ID==1 && equipo1[ui->comboBoxf1->currentIndex()]->ID==3)||(equipo1[pj1]->ID==3 && equipo1[ui->comboBoxf1->currentIndex()]->ID==1)){
            fus=1;
            equipo1.push_back(std::make_shared<Paladin>(equipo1[pj1].get(),equipo1[ui->comboBoxf1->currentIndex()].get()));
        } else if((equipo1[pj1]->ID==3 && equipo1[ui->comboBoxf1->currentIndex()]->ID==2)||(equipo1[pj1]->ID==2 && equipo1[ui->comboBoxf1->currentIndex()]->ID==3)){
            fus=1;
            equipo1.push_back(std::make_shared<Obispo>(equipo1[pj1].get(),equipo1[ui->comboBoxf1->currentIndex()].get()));
        }
        if(fus==1){
            if(pj1<ui->comboBoxf1->currentIndex()){
                equipo1.remove(ui->comboBoxf1->currentIndex());
                equipo1.remove(pj1);
            } else{
                equipo1.remove(pj1);
                equipo1.remove(ui->comboBoxf1->currentIndex());
            }
            ActualizarNombres(1);
            pj1=1;
            ui->mensaje1->setText("¡FUUUUUSIÓOON!");
            mediaplayer4 = new QMediaPlayer(this);
            mediaplayer4->setMedia(QUrl("qrc:/mini/fusion.mpeg"));
            mediaplayer4->setVolume(100);
            mediaplayer4->play();
            qApp->processEvents();
            QThread Q;
            Q.msleep(2000);
            ui->mensaje1->setText("Turno del jugador 2");
            ActualizarMenu();
            ActualizarPantalla();
            turno=2;
        }
    }
}

void ScreenCombate::on_fusion2_clicked()
{
    if (turno==2 && equipo2[pj2]->HP>0 && equipo2[ui->comboBoxf2->currentIndex()]->HP>0){
        fus2=0;
        if((equipo2[pj2]->ID==1 && equipo2[ui->comboBoxf2->currentIndex()]->ID==2)||(equipo2[pj2]->ID==2 && equipo2[ui->comboBoxf2->currentIndex()]->ID==1)){
            fus2=1;
            equipo2.push_back(std::make_shared<MagoCachas>(equipo2[pj2].get(),equipo2[ui->comboBoxf2->currentIndex()].get()));
        } else if((equipo2[pj2]->ID==1 && equipo2[ui->comboBoxf2->currentIndex()]->ID==3)||(equipo2[pj2]->ID==3 && equipo2[ui->comboBoxf2->currentIndex()]->ID==1)){
            fus2=1;
            equipo2.push_back(std::make_shared<Paladin>(equipo2[pj2].get(),equipo2[ui->comboBoxf2->currentIndex()].get()));
        } else if((equipo2[pj2]->ID==3 && equipo2[ui->comboBoxf2->currentIndex()]->ID==2)||(equipo2[pj2]->ID==2 && equipo2[ui->comboBoxf2->currentIndex()]->ID==3)){
            fus2=1;
            equipo2.push_back(std::make_shared<Obispo>(equipo2[pj2].get(),equipo2[ui->comboBoxf2->currentIndex()].get()));
        }
        if(fus2==1){
            if(pj2<ui->comboBoxf2->currentIndex()){
                equipo2.remove(ui->comboBoxf2->currentIndex());
                equipo2.remove(pj2);
            } else{
                equipo2.remove(pj2);
                equipo2.remove(ui->comboBoxf2->currentIndex());
            }
            ActualizarNombres(2);
            pj2=1;
            ui->mensaje1->setText("¡FUUUUUSIÓOON!");
            mediaplayer4 = new QMediaPlayer(this);
            mediaplayer4->setMedia(QUrl("qrc:/mini/fusion.mpeg"));
            mediaplayer4->setVolume(100);
            mediaplayer4->play();
            qApp->processEvents();
            QThread Q;
            Q.msleep(2000);
            ui->mensaje1->setText("Turno del jugador 1");
            ActualizarMenu();
            ActualizarPantalla();
            turno=1;
        }
    }
}

void ScreenCombate::ActualizarNombres(int eq){
    if (eq==1){
        for (int i=0; i<3; i++){
            if((i!=pj1)&&(i!=ui->comboBoxf1->currentIndex())){
                nequi1[0]=nequi1[i];
            }
        }
        if(equipo1[1]->ID==4){nequi1[1]="Mago cachas";}
        else if(equipo1[1]->ID==5){nequi1[1]="Paladín";}
        else if(equipo1[1]->ID==6){nequi1[1]="Obispo";}
    }
    else{
        for (int i=0; i<3; i++){
            if((i!=pj2)&&(i!=ui->comboBoxf2->currentIndex())){
                nequi2[0]=nequi2[i];
            }
        }
        if(equipo2[1]->ID==4){nequi2[1]="Mago cachas";}
        else if(equipo2[1]->ID==5){nequi2[1]="Paladín";}
        else if(equipo2[1]->ID==6){nequi2[1]="Obispo";}
    }
}
