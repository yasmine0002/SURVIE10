#include "Plateau.h"


using namespace std ;

const char ouvert[15][60]
{
 "###########################################################",
 "#                                                         #",
 "#                                                         #",
 "#                                                         #",
 "#                                                         #",
 "#                                                         #",
 "#                                                         #",
 "#                                                         #",
 "#                                                         #",
 "#########  #############################__#################",
 "#                    #                                    #",
 "#                    #              OOOO                  #",
 "#                    #              OOOO                  #",
 "#                    #                                    #",
 "###########################################################"
};


Plateau::Plateau() {
	xMax = 60;
	yMax = 15;
	for(int x=0;x<xMax;++x)
		for(int y=0;y<yMax;++y)
		{
			switch(ouvert[yMax-1-y][x])
			{
				case '#': tab[x][y] = WALL; break;
				case ' ': tab[x][y] = SPACE; break;
				case '_': tab[x][y] = PORTE ; break;
				case '\x05': tab[x][y] = PLANTE; break;
				case 'p': tab[x][y] = PLANTEM; break; // plante malade
				case 'F': tab[x][y] = PLANTEF; break; // plante avec fraises
				case 'O': tab[x][y] = EAU; break; // un litre d eau
				case 'X': tab[x][y] = POULET; break; // un poulet

			}
		}
}

Plateau::Case Plateau::getCase(int x, int y) const
{
    return tab[x][y];
}

void Plateau::setCase(int x, int y, Case type)
{
    tab[x][y]=type;
}

bool Plateau::estPositionValide(const int x, const int y) const
{
    return ((x>=0) && (x<xMax) && (y>=0) && (y<yMax) && (tab[x][y]!='#'));
}

bool Plateau::estPositionValideP(const int x, const int y) const
{
    return ((x>=0) && (x<xMax) && (y>5) && (y<yMax) && (tab[x][y]!='#')&&(tab[x][y]!='_'));
}

bool Plateau::estPositionManger(const int x, const int y, const Plante a) const
{
    if((x>=0) && (x<xMax) && (y>=0) && (y<yMax) && (x==(a.getPosX()+1)) && (y==a.getPosY()))
        return true;
    else  return false;
}

bool Plateau::estDevantMur(const int x, const int y)
{
    if((tab[x+1][y-1]!='#')||(tab[x+1][y]!='#')||(tab[x+1][y+1]!='#')||(tab[x][y-1]!='#')||(tab[x][y+1]!='#')||(tab[x-1][y-1]!='#')||(tab[x-1][y]!='#')||
       (tab[x-1][y+1]!='#'))
        return true;
    else return false;
}

bool Plateau::estPosEau(const int x, const int y)
{
    if((x>=35&&x<39)&&(y>=2&&y<=3) )
        return true;
    else return false;
}

bool Plateau::ouvrePorte (const int x, const int y) const
{
    if((y>=5))
        return true;
    if((y<5)&&(x<21))
            return true;
    else return false;
}

int Plateau::getXmax() const
{
    return xMax;
}

int Plateau::getYmax() const
{
    return yMax;
}

void Plateau::recuillirEau(const int x, const int y)
{
    if(estPosEau(x,y))
        setCase(x+1, y, SPACE);
}

unsigned char Plateau::getXYasChar (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<xMax);
	assert(y<yMax);
    return (char)(tab[x][y]);     // ceci ne marche que dans notre cas particulier, car l'enum est initialisé avec les codes ascii
}


