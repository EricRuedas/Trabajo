#include "personajes.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QVector>
#include "QDebug"

// Fórmula de daño, teniendo en cuenta el ataque y defensa de los personajes y un porcentaje de variación del daño:
int damage(int a,int d){
    int dam=round(0.01*(rand()%20+80)*(200*a/(25*d)+2));
    if (dam<=0){dam=1;}
    return dam;
}

Personaje::Personaje(){
}

Personaje::~Personaje(){}

/*void Personaje::Habilidad(int n,Personaje* en){
    //en->HP=en->HP-(this->at_f-en->def_f);
}*/

// Para eliminar los cambios de características (si los ha habido, ya que los aumentos sólo sirven para la realización de un ataque):
void Personaje::Reajustar(){
    this->at_f=this->at_f_base;
    this->at_m=this->at_m_base;
}

// Clase Guerrero heredada de Personaje:
Guerrero::Guerrero():Personaje(){
    ID=1;
    HP_max=100;
    HP=100;
    PP=50;
    PP_max=50;
    at_f=15;
    at_f_base=15;
    def_f=10;
    def_m=6;
    costes.push_back(0);
    costes.push_back(15);
    costes.push_back(20);
    hab.addItem("Espadazo (0 PH)");
    hab.addItem("Aumento (15 PH)");
    hab.addItem("Espadazo fuerte (20 PH)");
    QPixmap pic1(":/mini/guerrero1_quieto.png");
    im_normal1=pic1;
    QPixmap pic2(":/mini/guerrero1_ataque.png");
    im_ataque1=pic2;
    QPixmap pic3(":/mini/guerrero2_quieto.png");
    im_normal2=pic3;
    QPixmap pic4(":/mini/guerrero2_ataque.png");
    im_ataque2=pic4;
    sonido_ataque="qrc:/mini/sword.mp3";
}

Guerrero::~Guerrero(){}

void Guerrero::Espadazo(Personaje *en){
    int dam=damage(this->at_f,en->def_f);
    en->HP=en->HP-dam;
}

void Guerrero::Aumento(){
    this->at_f=this->at_f_base*2;
    this->PP=this->PP-15;
}

void Guerrero::EspadazoFuerte(Personaje *en){
    int dam=damage(this->at_f*1.5,en->def_f);
    en->HP=en->HP-dam;
    this->PP=this->PP-20;
}

void Guerrero::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Espadazo(en);
        this->Reajustar();
        break;
    case 1:
        this->Aumento();
        break;
    case 2:
        this->EspadazoFuerte(en);
        this->Reajustar();
        break;
    default:
        break;
    }
}

// Clase Mago heredada de Personaje:
Mago::Mago():Personaje(){
    ID=2;
    HP_max=100;
    HP=100;
    PP_max=60;
    PP=60;
    at_m=20;
    at_m_base=20;
    def_f=5;
    def_m=10;
    costes.push_back(0);
    costes.push_back(20);
    costes.push_back(25);
    hab.addItem("Hechizo (0 PH)");
    hab.addItem("Hechizo gordo(20 PH)");
    hab.addItem("Poción de aumento (25 PH)");
    QPixmap pic1(":/mini/mago1_quieto.png");
    im_normal1=pic1;
    QPixmap pic2(":/mini/mago1_ataque.png");
    im_ataque1=pic2;
    QPixmap pic3(":/mini/mago2_quieto.png");
    im_normal2=pic3;
    QPixmap pic4(":/mini/mago2_ataque.png");
    im_ataque2=pic4;
    sonido_ataque="qrc:/mini/magic.mp3";
}

Mago::~Mago(){}

void Mago::Hechizo(Personaje *en){
    int dam=damage(this->at_m,en->def_m);
    en->HP=en->HP-dam;
}

void Mago::HechizoGordo(Personaje *en){
    int dam=damage(this->at_m*1.5,en->def_m);
    en->HP=en->HP-dam;
    this->PP=this->PP-20;
}

void Mago::PocionAumento(){
    this->at_m=this->at_m_base*2;
    this->PP=this->PP-25;
}

void Mago::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Hechizo(en);
        this->Reajustar();
        break;
    case 1:
        this->HechizoGordo(en);
        this->Reajustar();
        break;
    case 2:
        this->PocionAumento();
        break;
    default:
        break;
    }
}

// Clase Clerigo heredada de Personaje:
Clerigo::Clerigo():Personaje(){
    ID=3;
    HP=100;
    HP_max=100;
    PP=75;
    PP_max=75;
    at_f=6;
    at_f_base=6;
    at_m_base=10;
    at_m=10;
    def_f=8;
    def_m=15;
    costes.push_back(0);
    costes.push_back(10);
    costes.push_back(20);
    hab.addItem("Bastonazo (0 PH)");
    hab.addItem("Rayo divino (10 PH)");
    hab.addItem("Curar (20 PH)");
    QPixmap pic1(":/mini/clerigo1_quieto.png");
    im_normal1=pic1;
    QPixmap pic2(":/mini/clerigo1_ataque.png");
    im_ataque1=pic2;
    QPixmap pic3(":/mini/clerigo2_quieto.png");
    im_normal2=pic3;
    QPixmap pic4(":/mini/clerigo2_ataque.png");
    im_ataque2=pic4;
    sonido_ataque="qrc:/mini/poo.mp3";
}

Clerigo::~Clerigo(){}

void Clerigo::Bastonazo(Personaje *en){
    int dam=damage(this->at_f,en->def_f);
    en->HP=en->HP-dam;
}

void Clerigo::Curar(QVector<std::shared_ptr<Personaje>> team){
    int n=team.size();
    for(int i=0;i<n;i++){
        if(team[i]->HP>0){
            team[i]->HP=team[i]->HP+20;
        }
    }
    this->HP=this->HP-20;
    for(int i=0;i<n;i++){
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
        this->RayoDivino(en);
        break;
    case 2:
        this ->Curar(team);
        break;
    default:
        break;
    }
}

void Clerigo::RayoDivino(Personaje *en){
    int dam=damage(this->at_m,en->def_m);
    en->HP=en->HP-dam;
    this->PP=this->PP-10;
}

// Clase MagoCachas heredada de Guerrero, Mago y Personaje:
MagoCachas::MagoCachas(Personaje* g,Personaje* m):Personaje(),Guerrero(),Mago(){
    ID=4;
    HP=g->HP+m->HP;
    HP_max=200;
    PP=g->PP+m->PP;
    PP_max=g->PP_max+m->PP_max;
    at_f=g->at_f_base+m->at_f_base;
    at_m=m->at_m_base+g->at_m_base;
    at_f_base=at_f;
    at_m_base=at_m;
    def_f=(g->def_f+m->def_f)*0.5;
    def_m=(g->def_m+m->def_m)*0.5;
    costes.push_back(50);
    hab.addItem("Golpe doble (50 PH)");
    QPixmap pic1(":/mini/MagoCachas1_quieto.png");
    im_normal1=pic1;
    QPixmap pic2(":/mini/MagoCachas1_ataque.png");
    im_ataque1=pic2;
    QPixmap pic3(":/mini/MagoCachas2_quieto.png");
    im_normal2=pic3;
    QPixmap pic4(":/mini/MagoCachas2_ataque.png");
    im_ataque2=pic4;
    sonido_ataque="qrc:/mini/laugh.mp3";
}

MagoCachas::~MagoCachas(){}

void MagoCachas::GolpeDoble(Personaje* en){
    int dam=damage(this->at_f,en->def_f);
    en->HP=en->HP-dam;
    dam=damage(this->at_m,en->def_m);
    en->HP=en->HP-dam;
    this->PP=this->PP-50;
}

void MagoCachas::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Espadazo(en);
        this->Reajustar();
        break;
    case 1:
        this->Aumento();
        this->at_m=this->at_m_base;
        break;
    case 2:
        this->EspadazoFuerte(en);
        this->Reajustar();
        break;
    case 3:
        this->Hechizo(en);
        this->Reajustar();
        break;
    case 4:
        this->HechizoGordo(en);
        this->Reajustar();
        break;
    case 5:
        this->PocionAumento();
        this->at_f=this->at_f_base;
        break;
    case 6:
        this->GolpeDoble(en);
        this->Reajustar();
        break;
    default:
        break;
    }
}

// Clase Paladin heredada de Guerrero, Clerigo y Personaje:
Paladin::Paladin(Personaje* g,Personaje* m):Personaje(),Guerrero(),Clerigo(){
    ID=5;
    HP=g->HP+m->HP;
    HP_max=200;
    PP=g->PP+m->PP;
    PP_max=g->PP_max+m->PP_max;
    at_f=g->at_f_base+m->at_f_base;
    at_m=m->at_m_base+g->at_m_base;
    at_f_base=at_f;
    at_m_base=at_m;
    def_f=(g->def_f+m->def_f)*0.5;
    def_m=(g->def_m+m->def_m)*0.5;
    costes.push_back(55);
    hab.addItem("Espada drenaje (55 PH)");
    QPixmap pic1(":/mini/PPaladin1_quieto.png");
    im_normal1=pic1;
    QPixmap pic2(":/mini/PPaladin1_ataque.png");
    im_ataque1=pic2;
    QPixmap pic3(":/mini/PPaladin2_quieto.png");
    im_normal2=pic3;
    QPixmap pic4(":/mini/PPaladin2_ataque.png");
    im_ataque2=pic4;
    sonido_ataque="qrc:/mini/laugh.mp3";
}

Paladin::~Paladin(){}

void Paladin::EspadaDrenaje(Personaje *en){
    int dam=damage(this->at_f,en->def_f);
    en->HP=en->HP-dam;
    this->HP=this->HP+round(dam/2);
    this->PP=this->PP-55;
    if((this->HP)>(this->HP_max)){
        this->HP=this->HP_max;
    }

}

void Paladin::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Espadazo(en);
        this->Reajustar();
        break;
    case 1:
        this->Aumento();
        this->at_m=this->at_m_base;
        break;
    case 2:
        this->EspadazoFuerte(en);
        this->Reajustar();
        break;
    case 3:
        this->Bastonazo(en);
        this->Reajustar();
        break;
    case 4:
        this->RayoDivino(en);
        this->Reajustar();
        break;
    case 5:
        this->Curar(team);
        this->Reajustar();
        break;
    case 6:
        this->EspadaDrenaje(en);
        this->Reajustar();
        break;
    default:
        break;
    }
}

// Clase Obispo heredada de Clerigo, Mago y Personaje:
Obispo::Obispo(Personaje* g,Personaje* m):Personaje(),Mago(),Clerigo(){
    ID=6;
    HP=g->HP+m->HP;
    HP_max=200;
    PP=g->PP+m->PP;
    PP_max=g->PP_max+m->PP_max;
    at_f=g->at_f_base+m->at_f_base;
    at_m=m->at_m_base+g->at_m_base;
    at_f_base=at_f;
    at_m_base=at_m;
    def_f=(g->def_f+m->def_f)*0.5;
    def_m=(g->def_m+m->def_m)*0.5;
    costes.push_back(100);
    hab.addItem("Hechizo sagrado (100 PH)");
    QPixmap pic1(":/mini/Obispo1_quieto.png");
    im_normal1=pic1;
    QPixmap pic2(":/mini/Obispo1_ataque.png");
    im_ataque1=pic2;
    QPixmap pic3(":/mini/Obispo2_quieto.png");
    im_normal2=pic3;
    QPixmap pic4(":/mini/Obispo2_ataque.png");
    im_ataque2=pic4;
    sonido_ataque="qrc:/mini/laugh.mp3";
}

Obispo::~Obispo(){}

void Obispo::HechizoSagrado(QVector<std::shared_ptr<Personaje>> team){
    int n=team.size();
    for(int i=0;i<n;i++){
        if(team[i]->HP>0){
            team[i]->HP=team[i]->HP+50;
            team[i]->PP=team[i]->PP+50;
        }
    }
    this->PP=this->PP-50;
    for(int i=0;i<n;i++){
        if((team[i]->HP)>(team[i]->HP_max)){
            team[i]->HP=team[i]->HP_max;
        }
        if((team[i]->PP)>(team[i]->PP_max)){
            team[i]->PP=team[i]->PP_max;
        }
    }
    this->PP=this->PP-100;
}

void Obispo::Habilidad(int n,Personaje *en,QVector<std::shared_ptr<Personaje>> team){
    switch (n) {
    case 0:
        this->Hechizo(en);
        this->Reajustar();
        break;
    case 1:
        this->HechizoGordo(en);
        this->Reajustar();
        break;
    case 2:
        this->PocionAumento();
        break;
    case 3:
        this->Bastonazo(en);
        this->Reajustar();
        break;
    case 4:
        this->RayoDivino(en);
        this->Reajustar();
        break;
    case 5:
        this->Curar(team);
        this->Reajustar();
        break;
    case 6:
        this->HechizoSagrado(team);
        this->Reajustar();
        break;
    default:
        break;
    }
}
