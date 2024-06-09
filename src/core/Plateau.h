#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cassert>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "Plante.h"

/** \brief code gerant un Plateau qui correspond au terrain du jeu de survie qui utilise la classe Plante
 *
 * \param on a comme parametre le plateau "xMax" "yMax" qui est la taille du Plateau  ainsi que l enumeration des cases
 *
 */

class Plateau
{
    private:

    int xMax, yMax;
    enum  Case{SPACE=' ', WALL='#', PORTE='_', PLANTE='\x05', PLANTEM='p', PLANTEF='F', EAU='O',  POULET='X'};
    Case tab[100][100];

    public:

    Plateau();

    int getXmax() const;
    int getYmax() const;
    Case getCase(int x, int y) const;
    void setCase(int x, int y, Case type);
    void recuillirEau(const int x, const int y);
//    void afficherPlateau();
//    void afficheCase(int i);
//    void afficherSinge();

    bool estPositionValide(const int x, const int y) const;
    bool estPositionValideP(const int x, const int y) const;
    bool estPositionManger(const int x, const int y, const Plante a) const;
    bool estDevantMur(const int x, const int y);
    bool estPosEau(const int x, const int y);
    bool ouvrePorte(const int x, const int y) const;
    unsigned char getXYasChar (const int x, const int y) const ;
//    void actionClavier (const char touche);
//    void txtBoucle (Plateau &p);
};





#endif // PLATEAU_H_INCLUDED
