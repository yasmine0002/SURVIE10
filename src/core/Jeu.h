#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "Singe.h"
#include "Plateau.h"
#include "Poulet.h"
#include "Plante.h"

/** \brief code gerant un jeu de survie qui utilise les classes Plateau Poulet et Plante
 *
 * \param on a comme parametre le plateau "p", le singe "s",et les 3 poulets "x,y,z"
 *
 */

class Jeu {

private :
	Plateau p;
	Singe s;
	Poulet x,y,z;
	Plante tab[2][4];
	int t;

public :

    Jeu ();
    const Plateau &getPlateau() const;
    const Singe &getSinge() const;
    const Poulet &getPouletX() const;
    const Poulet &getPouletY() const;
    const Poulet &getPouletZ() const;
    const Plante &getPlanteIJ(const int i, const int j) const;

    const int &getTemps() const;
    bool actionClavier(const char touche);
    void setTime(int a);
    int &timerJeu();
    int compteSeconde(int &s);
    void vieSinge();
    void niv_sanSinge();
    void viePlanteIJ(const int i, const int j);
    bool finJeu();
    void mvtPoulet(const char touche);
    void attaquerS();
    void attaquerP();
    int getPosXbyJ(const int j);
    int getPosYbyI(const int i);
    int getJbyPosX(const int x) const;
    int getIbyPosY(const int y) const;
    void renaissancePlante();
    void arretP(int x);
    bool affToucheH();
    void tutoJeu();

    //getTemps() const;
    //const Plante &getPlante() const;

};

inline const Plateau& Jeu::getPlateau () const { return p; }         // du code court comme ca doit être en inline
inline const Singe& Jeu::getSinge() const { return s; }
inline const Poulet& Jeu::getPouletX() const { return x; }
inline const Poulet& Jeu::getPouletY() const { return y; }
inline const Poulet& Jeu::getPouletZ() const { return z; }

//inline const Plante* Jeu::getTabPlante() const { return tab; }
inline const int& Jeu::getTemps() const { return t; }
//inline Jeu::getTemps() const { return t; }
//inline const Plante& Jeu::getPlante() const { return pl; }






#endif // JEU_H_INCLUDED
