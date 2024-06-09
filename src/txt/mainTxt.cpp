#include <iostream>
#include "winTxt.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "txtJeu.h"


using namespace std;

    int main ( int argc, char** argv ) {
    termClear();
	Jeu jeuT, jeu;
	txtBoucleTuto(jeuT);
	termClear();
	txtBoucle(jeu);
   // termClear();
	return 0;}

