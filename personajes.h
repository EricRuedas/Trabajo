#ifndef PERSONAJES_H
#define PERSONAJES_H

//#include <QMainWindow>
#include <ui_screencombate.h>
#include <QVector>
#include <memory>

//namespace Ui {
//class MainWindow;
//}

class Personaje{
public:
    Personaje();
    ~Personaje();
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>)=0;
    int HP=1;
    int PP=1;
    int HP_max=1;
    int PP_max=1;
    int at_f=0;
    int at_m=0;
    int def_f=0;
    int def_m=0;
    QComboBox hab;
    QPixmap im_normal1;
    QPixmap im_normal2;
    QPixmap im_ataque1;
    QPixmap im_ataque2;
    QVector<int> costes;
};

class Guerrero : virtual public Personaje {
public:
    Guerrero();
    ~Guerrero();
    void Espadazo(Personaje*);
    void Aumento();
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class Mago:virtual public Personaje{
public:
    Mago();
    ~Mago();
    void Hechizo(Personaje*);
    void HechizoGordo(Personaje*);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

class Clerigo:virtual public Personaje{
public:
    Clerigo();
    ~Clerigo();
    void Bastonazo(Personaje*);
    void Curar(QVector<std::shared_ptr<Personaje>>);
    virtual void Habilidad(int,Personaje*,QVector<std::shared_ptr<Personaje>>) override;
};

#endif // PERSONAJES_H

