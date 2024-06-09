#include "Plante.h"

using namespace std ;

Plante::Plante()
{
    posX=0;
    posY=0;
    viv =true;
}

Plante::Plante(const int x, const int y, const bool v)
{
    posX = x;
    posY = y;
    viv = v;
}

int Plante::getPosX() const
{
    return posX;
}

int Plante::getPosY() const
{
    return posY;
}

bool Plante::getViv() const
{
    return viv;
}

void Plante::setPosX(const int x)
{
    posX = x;
}

void Plante::setPosY(const int y)
{
    posY = y;
}

void Plante::setViv(const bool z)
{
    viv = z;
}

int Plante::getJbyPosX(const int x) const
{
    return posX-1;
}

int Plante::getIbyPosY(const int y) const
{
    return posY-1;
}

int Plante::PosXbyJ(const int j) const
{
    return j+1;
}

int Plante::PosYbyI(const int i) const
{
    return i+1;
}

bool Plante::estMalade(const int t) const
{
    if(t>60)
        return true;
    else return false;
}

