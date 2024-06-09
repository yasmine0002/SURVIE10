#ifndef SINGE_H_INCLUDED
#define SINGE_H_INCLUDED

#include <cassert>
#include <iostream>
#include "time.h"

#include "Plateau.h"
#include "Plante.h"


using namespace std;

class Singe
{
private:
    int posX,posY; // position x et y
    int q_vie;     // quantite de vie
    int leau;      // litres d'eau en possession
    int niv_san;   // niveau sante

public:
    Singe(); //constructeur par default
    Singe(int x, int y, int qv, int eau, int ns); //constructeur par default

    int getPosX() const;  //recupere la position du singe sur l'axe des x
    int getPosY() const;  //recupere la position du singe sur l'axe des y
    int getQ_vie() const; //recupere la quantité de vie du singe
    int getLeau() const;  //recupere la quantité d eau prise par singe
    int getNiv_San() const;  //recupere le niveau sante

    void modifierLeau(const int l); //augmente ou diminue leau de l
    void modifierVie (const int q); //augmente ou diminue la quantite de vie de q
    void modifierNiv_San (const int q); //augmente ou diminue le niveau sante de q

    void gauche(const Plateau &p); //deplace Singe a gauche
    void droite(const Plateau &p); //deplace Singe a droite
    void haut(const Plateau &p);   //deplace Singe en haut
    void bas(const Plateau &p);    //deplace Singe en bas

    bool boitterie(); //renvoie un bool aleatoir qui empechera la fluidite des mvt de Singe

    void mangePlante(const Plateau p, const Plante a, const int t); //mange une plante et gagne de la vie

    bool estPosAtk(const int x, const int y); //renvoie vrai si Singe est proche de l'objet

};
#endif //SINGE_H_INCLUDED
