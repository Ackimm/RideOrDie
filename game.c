

#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


//#include "loadMap.h"
#include "drawMap.h"
#include "player.h"
//#include "enemies.h"
#include "tirs.h"


#include "menu.h"
#include "gameInitAndTimers.h"
#include "collision.h"
#include "bestScores.h"


//#include "obstacles.h"
//#include "bubbles.h"
#include "tirEnnemi.h" // pourquoi il est nécessaire de le garder en include alors que ce n'est pas nécessaire pour bubble et obstacles ? 



bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;
bool BUBBLE_SHOT = false;

bool test;
bool enPause;
bool gameOver = false;

//bool reInit = false;

//int start_pause_time;
//int end_pause_time;


bool keyStates[256] = {false};  // tableau pour suivre l'état des touches




void game(int *maxX, int *maxY, float scrolling_value, player p, listeEn e, listetirsP t) {
	glutMouseFunc(mouseClick);


	drawWall(maxX, maxY, scrolling_value);			
	drawPlayer(p);
	if (e->starList != NULL || e->endList != NULL)
	{
		drawAllEnnemis(e);
	}		

	
	if (t->starList != NULL || t->endList != NULL)
	{
		drawAllTirs(t);
	}
	
	if (liste_obs->premier != NULL)
	{
		drawAllObstacles(liste_obs);
	}

	if (liste_bub->premier != NULL)
	{
		drawAllBubbles(liste_bub);
	}

    if (liste_tir_enn->premier != NULL)
	{
		drawAllTirsEnnemi(liste_tir_enn);
	}
    
	glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);

  
	glutPostRedisplay();
	
	}

void updateFastMov(int value) {
  
    if (enPause == false && gameOver == false) {
					
					
		if (keyStates['z']) {
			moveUp(p);
		}

		if (keyStates['s']) {
			moveDown(p);
		}
	
		if (keyStates['q']) {
			moveLeft(p);
		}
		if (keyStates['d']) {
			moveRight(p);
		}

		
		if (keyStates['r']) {
			reinitializeGame();
			keyStates['r'] = false;	
		}

		if (keyStates[' ']) {
			tirer(p, t);
			keyStates[' '] = false;	
		}

		if (keyStates['e']) {
			if (p->bubbles > 0){
				shootBubble(p);
				p->bubbles--;
			}
			
			keyStates['e'] = false;	
		}
	}

		if (keyStates[27]) {


			if (gameOver == false && (currentMenu==nouvellePartie || currentMenu == pauseMenu)){ 
				enPause = !enPause;
				
				if (enPause == false){ // si vient de désactiver la pause 
					gameTimers();
				//	int end_pause_time = time(NULL);
					if (currentMenu==pauseMenu){
						changerMenu(nouvellePartie);

					}
				}		
				else{ /// si vient d'activer la pause 
					changerMenu(pauseMenu);
					//int start_pause_time = time(NULL);
				}
			}
		keyStates[27] = false;	
		}

	

	

if (enPause == false && gameOver == false) 

   glutTimerFunc(updateFrequency, updateFastMov, 0);  


}


void keyboardDown(unsigned char key, int x, int y) {
	keyStates[key] = true;
}


void keyboardUp(unsigned char key, int x, int y) {
    keyStates[key] = false;
}
