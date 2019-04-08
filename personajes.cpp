#include "personajes.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QVector>

int damage(int a,int d){
    int dam=a-d;
    if (dam<0){dam=0;}
    return dam;
}

Personaje::Personaje(){
}

Personaje::~Personaje(){}

/*void Personaje::Habilidad(int n,Personaje* en){
    //en->HP=en->HP-(this->at_f-en->def_f);
}*/

Guerrero::Guerrero():Personaje(){
    HP_max=100;
    HP=100;
    PP=50;
    PP_max=50;
    at_f=30;
    def_f=25;
    def_m=10;
    costes.push_back(0);
    costes.push_back(15);
    hab.addItem("Espadazo (0 PH)");
    hab.addItem("Aumento (15 PH)");
}

Guerrero::~Guerrero(){}

void Guerrero::Espadazo(Personaje *en){
    en->HP=en->HP-(this->at_f-en->def_f);
    if (this->at_f==60) {this->at_f=30;}
}

void Guerrero::Aumento(){
    this->at_f=60;
    this->PP=this->PP-15;
}

void Guerrero::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Espadazo(en);
        break;
    case 1:
        this->Aumento();
        break;
    default:
        break;
    }
}

Mago::Mago():Personaje(){
    HP_max=100;
    HP=100;
    PP_max=60;
    PP=60;
    at_m=40;
    def_f=5;
    def_m=15;
    costes.push_back(0);
    costes.push_back(20);
    hab.addItem("Hechizo (0 PH)");
    hab.addItem("Hechizo gordo(20 PH)");
}

Mago::~Mago(){}

void Mago::Hechizo(Personaje *en){
    en->HP=en->HP-(this->at_m-en->def_m);
}

void Mago::HechizoGordo(Personaje *en){
    en->HP=en->HP-((this->at_m*1.3)-en->def_m);
    this->PP=this->PP-20;
}

void Mago::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Hechizo(en);
        break;
    case 1:
        this->HechizoGordo(en);
        break;
    default:
        break;
    }
}

Clerigo::Clerigo():Personaje(){
    HP=100;
    HP_max=100;
    PP=75;
    PP_max=75;
    at_f=15;
    at_m=20;
    def_f=10;
    def_m=30;
    costes.push_back(0);
    costes.push_back(20);
    hab.addItem("Bastonazo (0 PH)");
    hab.addItem("Curar (20 PH)");
}

Clerigo::~Clerigo(){}

void Clerigo::Bastonazo(Personaje *en){
    int dam=damage(this->at_f,en->def_f);
    en->HP=en->HP-dam;
}

void Clerigo::Curar(QVector<std::shared_ptr<Personaje>> team){
    int n=team.size();
    this->HP=this->HP-20;
    for(int i=0;i<n;i++){
        if(team[i]->HP>0){
            team[i]->HP=team[i]->HP+20;
        }
        if((team[i]->HP)>(team[i]->HP_max)){
            team[i]->HP=team[i]->HP_max;
        }
    }
    this->PP=this->PP-20;
}

void Clerigo::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Bastonazo(en);
        break;
    case 1:
        this->Curar(team);
        break;
    default:
        break;
    }
}
