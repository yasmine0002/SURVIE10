#include "txtJeu.h"




void affVieS(const Jeu jeu)
{
    for(int i=0; i<jeu.getSinge().getQ_vie(); i++)
    {
        cout<<"\x03"; //symbole coeur
    }

    for(int i=jeu.getSinge().getQ_vie(); i<10; i++)
    {
        cout<<"                                                    ";
    }
}

void affNiv_SanS(const Jeu jeu)
{
    for(int i=0; i<jeu.getSinge().getNiv_San(); i++)
    {
        cout<<"I"; //symbole coeur
    }

    for(int i=jeu.getSinge().getNiv_San(); i<10; i++)
    {
        cout<<"                                                    ";
    }
}

void affVieP(const Poulet p)
{
    for(int i=0; i<p.getQ_Vie(); i++)
        cout<<"\x03"; //symbole coeur
    for(int i=p.getQ_Vie(); i<3; i++)
         cout<<"                                                    ";
}

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Plateau& p = jeu.getPlateau();
    const Singe& s = jeu.getSinge();
    const Poulet& x = jeu.getPouletX();
    const Poulet& y = jeu.getPouletY();
    const Poulet& z = jeu.getPouletZ();
    const int& t = jeu.getTemps();

	win.clear();

    //Affichage des murs
	for(int x=0;x<p.getXmax();++x)
		for(int y=0;y<p.getYmax();++y)
			win.print( x, y, p.getXYasChar(x,y));
    if(p.ouvrePorte(s.getPosX(), s.getPosY()))
    {
        win.print(40,5,' ');
        win.print(41,5,' ');
    }

    //Affichage des plantes
    for(int i=0; i<2; i++)
        for(int j=0; j<4; j++)
    {
        if(jeu.getPlanteIJ(i,j).estMalade(t))
        {
            win.print(jeu.getPlanteIJ(i,j).PosXbyJ(j),jeu.getPlanteIJ(i,j).PosYbyI(i), 'p');
        }

        else win.print(jeu.getPlanteIJ(i,j).PosXbyJ(j),jeu.getPlanteIJ(i,j).PosYbyI(i), 'P'); //trifeuille
        if(jeu.getPlanteIJ(i,j).getViv()==false)
        {
            win.print(jeu.getPlanteIJ(i,j).PosXbyJ(j),jeu.getPlanteIJ(i,j).PosYbyI(i), ' ');
        }
    }


    // Affichage de Singe
	win.print(s.getPosX(),s.getPosY(),'S'); // singe avec eau \x14  /x24

	// Affichage des 3 poulets
	if(x.getViv())
	{
        win.print(x.getPosX(),x.getPosY(),'X');
	}
	if(y.getViv())
    {
        win.print(y.getPosX(),y.getPosY(),'Y');
    }
	if(z.getViv())
    {
        win.print(z.getPosX(),z.getPosY(),'Z');
    }


//    for(int i=0; i<2; i++)
//    {
//        for(int j=0;j<4;j++)
//        {
//            cout<<"tab["<<i<<"]["<<j<<"] : "<<jeu.getPlanteIJ(i,j).getViv()<<endl;
//        }
//    }

	win.draw();
}

void affInfo(const Jeu jeu)
{
    // Affichge des vies
	cout<<"VIE S: ";
	affVieS(jeu);
    cout<<endl;
//    affNiv_SanS(jeu);
//    cout<<endl;

	cout<<"VIE X: ";
	affVieP(jeu.getPouletX());
	cout<<endl;

	cout<<"VIE Y: ";
	affVieP(jeu.getPouletY());
	cout<<endl;

	cout<<"VIE Z: ";
	affVieP(jeu.getPouletZ());
	cout<<endl;

    cout<<"litre eau :";
    cout<<jeu.getSinge().getLeau();
    cout<<endl;


}



void txtBoucleTuto (Jeu & jeuT) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)

	jeuT.tutoJeu();


    WinTXT win (jeuT.getPlateau().getXmax(),jeuT.getPlateau().getYmax());
    win.clear();
	bool ok = true;
	char c;
    int a = 0;
    bool f,g = true;
    Plante b;
  //  b.setViv(true);

	do {
        cout<<endl;

        jeuT.vieSinge();
        //jeu.niv_sanSinge();

	    txtAff(win,jeuT);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
        cout<<endl;

		a = jeuT.timerJeu();
        cout<<"Essaiez de survivre 10 jours sur Mars, temps ecoule : "<<a<<"f"<<endl;
        cout<<"Pour informatioin, 10 jours sur Mars equivauent a 300f"<<endl;

        if(g)
        {
            cout<<"Cliquez q si vous voulez sauter le tutorial"<<endl;
            cout<<"Utilisez les touches k l m o pour vous deplacer"<<endl;
            cout<<"L'eau a cote de vous vous permettra de faire grandir les plante qui sont dans la chambre a cote"<<endl;
            cout<<"Approchez-vous de l'eau"<<endl;
            g = false;
        }

        if(jeuT.affToucheH())
        {
            cout<<"Recuillez un litre d'eau avec la touche h                                                                      "<<endl;
            if(jeuT.getSinge().getLeau()>0)
            {
            cout<<"Allez dans le coin haut gauche de la chambre a cote pour arroser les plantes                                   "<<endl;
            cout<<"Prevoyez un peu d'espace sur votre gauche pour planter                                              "<<endl;
             cout<<"                                                                                                              "<<endl;
            }
            else
            {
                cout<<"                                                                                                               "<<endl;
                cout<<"                                                                                                               "<<endl;
            }
        }



        if(jeuT.getSinge().getPosY()>5)
        {
            cout<<"Attention ! Les poulets X Y Z esseyerons de vous attaquer, courez le plus vite possible dans la chambre a cote "<<endl;
            cout<<"ou cliquez ESPACE pour les attaquer, un coup equivaut a un litre d'eau                                         "<<endl;
            //cout<<"vie de Singe : ";
            cout<<"                                                                                                               "<<endl;

            affInfo(jeuT);
            cout<<"                                                                                                               "<<endl;

        }

        if(jeuT.getSinge().getPosY()<5 && jeuT.getSinge().getPosX()<21)
        {
            cout<<"Bien joue! maintenat approchez vous du coin et cliquez sur la touche g our planter. Avec la touche j vous pourrez les manger. ";
            cout<<"Vous pouvez planter jusqu'a que vous avez de l'eau                                            "<<endl;
        }

        for(int i=0; i<2; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(jeuT.getPlateau().estPositionManger(jeuT.getSinge().getPosX(),jeuT.getSinge().getPosY(), jeuT.getPlanteIJ(i,j)))
                {
                    b = jeuT.getPlanteIJ(i,j);
                }
            }
        }

        if(jeuT.getPlateau().estPositionManger(jeuT.getSinge().getPosX(),jeuT.getSinge().getPosY(),b) && c=='j')
        {
            cout<<"Tres bien ! Maintenant c'est a vous !                                                  "<<endl;
            sleep(3);
            ok = false;
        }



        cout<<endl;
        //affInfo(jeu);
        if(a==300)
        {
            ok = false;
        }
        usleep(100000);
		c = win.getCh();
		jeuT.mvtPoulet(c);
		switch (c) {
			case 'k':
				jeuT.actionClavier('g');
				break;
			case 'm':
				jeuT.actionClavier('d');
				break;
			case 'l':
				jeuT.actionClavier('h');
				break;
			case 'o':
				jeuT.actionClavier('b');
				break;
            case 'j':
				jeuT.actionClavier('j');
				break;
            case 'h':
				jeuT.actionClavier('x');
				break;
            case 'g':
				jeuT.actionClavier('y');
				break;
            case ' ':
				jeuT.actionClavier('a');
				break;
			case 'q':
				ok = false;
				break;
		}


	} while (ok&&jeuT.finJeu());

	cout<<endl;
	if(jeuT.finJeu()==false)
        cout<<"Vous n'aviez plus de vie, perdu :("<<endl;
    else cout<<"Gagne!"<<endl;

}




void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getPlateau().getXmax(),jeu.getPlateau().getYmax());

	bool ok = true;
	char c;
    int a = 0;
    bool f,g = true;

	do {
        cout<<endl;

        jeu.vieSinge();
        //jeu.niv_sanSinge();

	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
        cout<<endl;

		a = jeu.timerJeu();
        cout<<"Essaiez de survivre 10 jours sur Mars, temps ecoule : "<<a<<"f"<<endl;
        cout<<"Pour informatioin, 10 jours sur Mars equivauent a 300f"<<endl;
        affInfo(jeu);

        cout<<endl;
        //affInfo(jeu);
        if(a==300)
        {
            ok = false;
        }
        usleep(100000);
		c = win.getCh();
		jeu.mvtPoulet(c);
		switch (c) {
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;
			case 'o':
				jeu.actionClavier('b');
				break;
            case 'j':
				jeu.actionClavier('j');
				break;
            case 'h':
				jeu.actionClavier('x');
				break;
            case 'g':
				jeu.actionClavier('y');
				break;
            case ' ':
				jeu.actionClavier('a');
				break;
			case 'q':
				ok = false;
				break;
		}


	} while (ok&&jeu.finJeu());

	cout<<endl;
	if(jeu.finJeu()==false)
        cout<<"Vous n'aviez plus de vie, perdu :("<<endl;
    else cout<<"Gagne!"<<endl;

}



