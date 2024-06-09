#include "Jeu.h"

const Plante& Jeu::getPlanteIJ(const int i, const int j) const
{
    return tab[i][j];
}

int Jeu::getPosXbyJ(const int j)
{
    return j+1;
}

int Jeu::getPosYbyI(const int i)
{
    return i+1;
}

Jeu::Jeu () : p(), s(), x(), y(), z()
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
        {
            tab[i][j] = Plante(getPosXbyJ(j), getPosYbyI(i), false);
        }
    for(int i=0; i<2; i++)
        for(int j=2; j<4; j++)
        {
            tab[i][j] = Plante(getPosXbyJ(j), getPosYbyI(i), false);
        }

    t=0;
}

void Jeu::setTime(int a)
{
    t = a;
}

int Jeu::compteSeconde(int &s)
{
    s++;
    return s;
}

int Jeu::getJbyPosX(const int x) const
{
    return x-1;
}

int Jeu::getIbyPosY(const int y) const
{
    return y-1;
}

void Jeu::renaissancePlante()
{
    int i = s.getPosY()-1;
    int j = s.getPosX()-2;

    if(i>=0 && i<2 && j>=0 && j<4 && tab[i][j].getViv()==false)
    {
        tab[i][j].setViv(true);
    }
}

//void Jeu::niv_sanSinge()
//{
//    for(int i=1;i<=100;i++)
//    {
//        if((s.getNiv_San()>=0))
//        {
//            s.modifierNiv_San(-1);
//        }
//    }
//}

void Jeu::attaquerP()
{
    if(s.estPosAtk(x.getPosX(), x.getPosY()) && x.getViv()==true && s.getLeau()>0)
    {
        x.modifierVie(-1);
        if(x.getQ_Vie()==0)
            x.setViv(false);
        s.modifierLeau(-1);
    }

    if(s.estPosAtk(y.getPosX(), y.getPosY()) && y.getViv()==true && s.getLeau()>0)
    {
        y.modifierVie(-1);
        if(y.getQ_Vie()==0)
            y.setViv(false);
        s.modifierLeau(-1);
    }

    if(s.estPosAtk(z.getPosX(), z.getPosY()) && z.getViv()==true && s.getLeau()>0)
    {
        z.modifierVie(-1);
        if(z.getQ_Vie()==0)
            z.setViv(false);
        s.modifierLeau(-1);
    }
}

bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'g' :
				s.gauche(p);
				return true;
				break;
		case 'd' :
				s.droite(p);
				return true;
				break;
		case 'h' :
				s.haut(p);
				return true;
				break;
		case 'b' :
				s.bas(p);
				return true;
				break;
        case 'j' :
                for(int i=0; i<2; i++)
                    for(int j=0; j<4; j++)
                {

                    if(p.estPositionManger(s.getPosX(), s.getPosY(), tab[i][j]))
                    {s.mangePlante(p, tab[i][j], t);
                        tab[i][j].setViv(false);
                    }
                }
                return true;
                break;
        case 'x' :
                p.recuillirEau(s.getPosX(), s.getPosY());
                if(p.estPosEau(s.getPosX(),s.getPosY()))
                    s.modifierLeau(1);
                return true;
                break;
         case 'y' :
                for(int i=0; i<2; i++)
                    for(int j=0; j<4; j++)
                {
                    if(p.estPositionManger(s.getPosX(), s.getPosY(), tab[i][j]) && s.getLeau()>0 && tab[i][j].getViv()==false)
                    {
                        renaissancePlante();
                        s.modifierLeau(-1);
                    }
                }

                return true;
                break;
         case 'a' :
                attaquerP();
	}
	return false;
}

int &Jeu::timerJeu()
{
    t = compteSeconde(t);
    setTime(t);
    return t;
}

bool Jeu::finJeu()
{
    if (s.getQ_vie()<=0)
        return false;
    else return true;
}


void Jeu::mvtPoulet(const char touche)
{
    if(s.getPosY()>5)//||s.getPosY()<=5&&s.getPosX()<21
    {
        x.versSinge(p,s);
        y.versSinge(p,s);
        z.versSinge(p,s);
    }
    else
    {
        x.bouger(p);
        y.bouger(p);
        z.bouger(p);
    }
}

void Jeu::attaquerS()
{
    if((x.getViv()==true && x.estPosAtk(s,p))||(y.getViv()==true && y.estPosAtk(s,p))||(z.getViv()==true && z.estPosAtk(s,p)))
    {
        s.modifierVie(-1);
    }
}

//void Jeu::attaquerS()
//{
//    if(x.estPosAtk(s,p)||y.estPosAtk(s,p)||z.estPosAtk(s,p))
//    {
//        s.modifierVie(-1);
//    }
//}


void Jeu::vieSinge()
{
    for(int i=1;i<=100;i++)
    {
        if(t==i*20)
        {
            s.modifierVie(-1);
        }
    }
    attaquerS();
}


//void Jeu::viePlanteIJ(const int i, const int j)
//{
//    tab[i][j].malade(t);
//}


void Jeu::arretP(int x)
{

}

bool Jeu::affToucheH()
{
    if(p.estPosEau(s.getPosX(), s.getPosY()))
        return true;
    else return false;
}

void Jeu::tutoJeu()
{
    p = Plateau();
    x = Poulet();
    y = Poulet();
    z = Poulet();

    for(int i=0; i<2; i++)
        for(int j=0; j<4; j++)
        {
            tab[i][j] = Plante(getPosXbyJ(j), getPosYbyI(i), false);
        }
   s = Singe(30,1,20,0, 10);
}

