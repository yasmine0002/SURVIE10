#ifndef TXTJEU_H_INCLUDED
#define TXTJEU_H_INCLUDED

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <stdio.h>
#include <unistd.h>

#include "../core/Jeu.h"
#include "winTxt.h"


void txtBoucle (Jeu & j);
void txtBoucleTuto (Jeu & jeuT);
int compteSeconde(int &s);
void affTemps(int &t);
void affVie(const Jeu &jeu);
void affInfo(const Jeu jeu);
//void txtAff(WinTXT & win, const Jeu & jeu);


#endif // TXTJEU_H_INCLUDED
