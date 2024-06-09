#ifndef POULET_H_INCLUDED
#define POULET_H_INCLUDED

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <stdio.h>
#include <unistd.h>

#include "Singe.h"
#include "Plateau.h"


/** \brief code gerant un poulet correspondant aux ennemis qui utilise les classes Plateau et Singe
 *
 * \param on a comme parametre la position "posX", "posY", la vitesse du poulet "vitesse", la direction "dir" ainsi que la vie "q_vie"
 *
 */
class Poulet
{
private :
    int posX, posY, q_vie, vitesse, dir;
    bool viv;

public:
    Poulet();
    Poulet(int x, int y, int q, int v, int d, bool z);

    int getPosX() const;
    int getPosY() const;
    int getVitesse() const;
    int getQ_Vie() const;
    bool getViv() const;

    void gauche(const Plateau &p);
    void droite(const Plateau &p);
    void haut(const Plateau &p);
    void bas(const Plateau &p);

    void setPosX(int x);
    void setPosY(int y);
    void setVitesse(int v);
    void setQ_Vie(int q);
    void setViv(bool z);

    void modifierVie (const int q); //augmente ou diminue la quantite de vie de q

    void versSinge(const Plateau &p, const Singe &s);
    void echapper(const Plateau &p, const Singe &s, int n);
    void bouger(const Plateau &p);

    bool estPosAtk(const Singe s, const Plateau p);
    void attaquer(const Singe &s);
   // void diminuerVie(bool attaque);  //inutile, procedure deja presente dans Singe.h, attaquer
};
#endif // POULET_H_INCLUDED
