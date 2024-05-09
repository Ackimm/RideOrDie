#ifndef _MENU_H_
#define _MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "loadMap.h"
#include "drawMap.h"


typedef enum {menuAccueil = 1, nouvellePartie = 2, continuerPartie = 3, highScores = 4, parametres = 5, quitter = 6, gameOverMenu = 7, pauseMenu = 8} menu; // eventuelluellement bouger pause et gameOver dans une autre enum gameState par la suite
extern menu currentMenu;

typedef enum {facile = 1, moyen = 2, difficile = 3, hardcore = 4} difficulte; 

extern difficulte currentDifficulte;


void drawMenu();
void drawScores();
void drawParametres();
void mouseClick(int button, int state, int x, int y);
void changerMenu(menu nouveauMenuCourrant);


#endif
