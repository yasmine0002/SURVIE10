# SURVIE_10 
Survie 10 
ATRAOUI Yasmine p2029383
DUARTE Dâlya p1906846
ABDEL MOLA Fatimetou p2026385

Un singe nommé Singe échoue sur Mars lors de sa mission spéciale. Le jeu se déroule sur une planète déserte remplit de poussière, de cailloux et de monstres. Son objectif est de survivre, seul, dans des conditions très difficile et avec seulement quelques provisions en stock dans son vaisseau endommagé. Diverses missions et tâches quotidiennes sont à prévoir.
Le joueur va donc remplir les différentes missions et s’assurer de la survie de Singe pendant seulement 10 jours. Si les missions ne sont pas remplit, le niveau de vie de Singe diminue. Au contraire, si les missions sont un succès alors le niveau augmente et des récompenses.


Le code est écrit en C++ et les applications utilisées sont git, doxygen, codeblocks, ubuntu.

On peut le compiler sur Windows (Codecloks) et linux via un Makefile.

## Organisation des fichiers


- **SDL_S10/src/core**   : classe de survie 10
- **SDL_S10/src/txt**   : les classes s'occupant de faire tourner SURVIE10 et de l'afficher sur la console en texte, 
- **SDL_10/src/SDL2**  : les classes s'occupant de faire tourner un SURVIE10 et de l'afficher avec SDL2
- **SDL_S10/doc**       : le fichier doxygen qui permet de générer la documentation du code
- **SDL_10/data**      : les assets (image, sons, etc.)
- **SDL_S10/bin**       : répertoire où les executables seront compilés 
- **SDL_S10/obj**       : répertoire comportant les compilations intermédiaires (.o)

- **SDL_S10/SDL_S10.cbp** : fichier de projet pour compiler avec Codeblocks.


### Pour installer SDL2
Pour installer SDL2 sous Linux ou avec WSL/Windows
``` sudo apt install python3 valgrind doxygen libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick ```

Pour Windows, le répertoire extern contient une version précompilé de SDL2 pour CB.


### Version Texte/SDL2 sous Linux (Ubuntu ou Windows-WSL) avec Makefile :  bien testé, devrait marcher
``` make -f Makefile_txt_sdl ```


##  Documentation du code

Voir src/documentation.h
soit avec doxygen, soit avec un �diteur de texte



