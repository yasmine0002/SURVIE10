#ifndef PLANTE_H_INCLUDED
#define PLANTE_H_INCLUDED

#include <iostream>
#include <cassert>


/** \brief code gerant la plante qui n'utilise aucune classe
 *
 * \param on a comme parametre la position 'posX' et 'posY' ainsi que le boolen 'viv' pour savoir si la plante est en vie
 *
 */


class Plante
{
private :
    int posX, posY;   // position x et y
    bool viv;           // plante vivante ou morte

public :
    Plante();   //constructeur par default
    Plante(const int x, const int y, const bool v); // constructeur avec parametres

    int getPosX() const; // recupere posX
    int getPosY() const; // recupere posY
    bool getViv() const; // recupere viv

    int getJbyPosX(const int x) const;  //retourne l'indice j colonne du tableau en connaissant la position x de la plante
    int getIbyPosY(const int y) const;  //retourne l'indice i colonne du tableau en connaissant la position y de la plante
    int PosXbyJ(const int j) const;  //retourne l'indice j colonne du tableau en connaissant la position x de la plante
    int PosYbyI(const int i) const;  //retourne l'indice i colonne du tableau en connaissant la position y de la plante

    void setPosX(const int x); //  change la posx avec x
    void setPosY(const int y); //  change la posy avec y
    void setViv(const bool z); //  change le viv avec z

    bool estMalade(const int t) const ; // renvoie si la plante est malade

};






#endif //PLANTE_H_INCLUDED
