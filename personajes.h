#ifndef PERSONAJES_H
#define PERSONAJES_H

//#include <QMainWindow>
#include <ui_screencombate.h>
#include <QVector>
#include <memory>
#include <QMediaPlayer>

//namespace Ui {
//class MainWindow;
//}

class Personaje{
public:
    Personaje();
    ~Personaje();
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>)=0;
    void Reajustar();
    int HP=1; // Vida actual del personaje
    int PP=1; // Puntos de poder actual del personaje
    int HP_max=1; // Vida máxima del personaje
    int PP_max=1; // Puntos de poder máximo del personaje
    int at_f=0; // Ataque físico actual del personaje
    int at_f_base=0; // Ataque físico base del personaje
    int at_m=0; // Ataque mágico actual del personaje
    int at_m_base=0; // Ataque mágico base del personaje
    int def_f=0; // Defensa física actual del personaje
    int def_m=0; // Defensa mágica actual del personaje
    int ID=0; // Identificador del personaje
    QComboBox hab; // ComboBox que contiene los posibles ataques del personaje
    QPixmap im_normal1; // Imagen correspondiente al personaje del jugador 1 sin atacar
    QPixmap im_normal2; // Imagen correspondiente al personaje del jugador 2 sin atacar
    QPixmap im_ataque1; // Imagen correspondiente al personaje del jugador 1 atacando
    QPixmap im_ataque2; // Imagen correspondiente al personaje del jugador 2 atacando
    QVector<int> costes; // Vector que contiene los puntos de poder que cuestan los ataques
    QString sonido_ataque; // String que contiene el path del sonido del ataque
};

class Guerrero : virtual public Personaje {
public:
    Guerrero();
    ~Guerrero();
    void Espadazo(Personaje*);
    void Aumento();
    void EspadazoFuerte(Personaje*);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class Mago:virtual public Personaje{
public:
    Mago();
    ~Mago();
    void Hechizo(Personaje*);
    void HechizoGordo(Personaje*);
    void PocionAumento();
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class Clerigo:virtual public Personaje{
public:
    Clerigo();
    ~Clerigo();
    void Bastonazo(Personaje*);
    void Curar(QVector<std::shared_ptr<Personaje>>);
    void RayoDivino(Personaje*);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class MagoCachas:public Guerrero, public Mago{
public:
    MagoCachas(Personaje*,Personaje*);
    ~MagoCachas();
    void GolpeDoble(Personaje*);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class Paladin:public Guerrero, public Clerigo{
public:
    Paladin(Personaje*,Personaje*);
    ~Paladin();
    void EspadaDrenaje(Personaje*);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class Obispo:public Mago, public Clerigo{
public:
    Obispo(Personaje*,Personaje*);
    ~Obispo();
    void HechizoSagrado(QVector<std::shared_ptr<Personaje>>);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

#endif // PERSONAJES_H

