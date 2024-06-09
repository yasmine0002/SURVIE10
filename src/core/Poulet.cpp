#include "Poulet.h"



using namespace std;

Poulet::Poulet()
{
    posX=30;
    posY=10;
    q_vie=3;
    vitesse=0;
    dir=0;
    viv=true;
}

Poulet::Poulet(int x, int y, int q, int v, int d, bool z)
{
    posX = x;
    posY = y;
    q_vie = q;
    vitesse = v;
    dir = d;
    viv = z;
}

int Poulet::getPosX() const
{
    return posX;
}

int Poulet::getPosY() const
{
    return posY;
}

int Poulet::getVitesse() const
{
    return vitesse;
}

int Poulet::getQ_Vie() const
{
    return q_vie;
}

bool Poulet::getViv() const
{
    return viv;
}

void Poulet::setPosX(int x)
{
    posX = x;
}

void Poulet::setPosY(int y)
{
    posY = y;
}

void Poulet::setVitesse(int v)
{
    vitesse = v;
}

void Poulet::setQ_Vie(int q)
{
    q_vie = q;
}

void Poulet::setViv(bool z)
{
    viv = z;
}

void Poulet::modifierVie(const int q)
{
    q_vie = q_vie + q;
}

void Poulet::gauche(const Plateau &p)
{
    if(p.estPositionValideP(posX-1,posY)) posX--;
}

void Poulet::droite(const Plateau &p)
{
    if(p.estPositionValideP(posX+1,posY)) posX++;
}

void Poulet::haut(const Plateau &p)
{
    if(p.estPositionValideP(posX,posY+1)) posY++;
}

void Poulet::bas(const Plateau &p)
{
    if(p.estPositionValideP(posX,posY-1)) posY--;
}

void Poulet::versSinge(const Plateau &p, const Singe &s)
{
    int dx = s.getPosX()-posX;
    int dy = s.getPosY()-posY;
    if (dx>0) dx=1;
    if (dx<0) dx=-1;
    if (dy>0) dy=1;
    if (dy<0) dy=-1;
    if (p.estPositionValideP(posX+dx,posY+dy))
    {
        posX = posX+dx;
        posY = posY+dy;
    }
    else
    {
        if(p.estPositionValideP(posX-1,posY))
        {
            posX = posX-1;
        }
        else if(p.estPositionValideP(posX,posY-1))
        {
            posY = posY-1;
        }

        else
        {
            posX = posX-dx;
            posY = posY-dy;
        }

    }
}


void Poulet::echapper(const Plateau &p, const Singe &s, int n)
{
    int dx = s.getPosX()-posX;
    int dy = s.getPosY()-posY;
    if (dx>0) dx=1;
    if (dx<0) dx=-1;
    if (dy>0) dy=1;
    if (dy<0) dy=-1;
    if (p.estPositionValideP(posX+dx,posY+dy)&&n==1)
    {
        posX = posX-dx;
        posY = posY-dy;
    }
}

//void Poulet::bouger(const Plateau &p)
//{
//    int dx [4] = { -1, 0, 1, 0};
//    int dy [4] = { 0, 1, 0, -1};
//    int xtmp,ytmp;
//    xtmp = posX + dx[dir];
//    ytmp = posY + dy[dir];
//    if (p.estPositionValide(xtmp,ytmp)) {
//        posX = xtmp;
//        posY = ytmp;
//    }
//    else dir = rand()%4;
//    cout<<dir<<endl;
//}


void Poulet::bouger(const Plateau &p)
{
    int dx [4] = { -1, 0, 1, 0};
    int dy [4] = { 0, 1, 0, -1};
    int xtmp,ytmp;

    xtmp = posX + dx[dir];
    ytmp = posY + dy[dir];
    if (p.estPositionValideP(xtmp,ytmp)) {
        posX = posX + dx[dir];
        posY = posY + dy[dir];
        dir = rand()%4;
    }
    else
    {
        dir = rand()%4;
    }
   // cout<<dir<<endl;
}


bool Poulet::estPosAtk(const Singe s, const Plateau p)
{
    int i = rand()%20;
    if(p.estPositionValideP(posX, posY) && s.getPosX()<=posX+1 && s.getPosX()>=posX-1 && s.getPosY()<=posY+1 && s.getPosY()>=posY-1 && i==2){
        //cout<<i<<endl;
        return true;}
    else {
            //cout<<i<<endl;
    return false;}
}




//void Poulet::attaquer(Singe &s)
//{
//    if((s.getPosX()<=getPosX())||(s.getPosY()<=getPosY()))
//    {
//        s.setQ_Vie(-20.);
//        //sdl pour mvt poulet, frequence de l'attaque
//    }
//
//}





