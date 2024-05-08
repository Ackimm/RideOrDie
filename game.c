

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
#include "enemies.h"
#include "tirs.h"


#include "menu.h"
#include "gameInitAndTimers.h"
#include "collision.h"
#include "bestScores.h"


//#include "obstacles.h"
//#include "bubbles.h"



bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;
bool BUBBLE_SHOT = false;
bool test;
bool enPause;
bool gameOver = false;
bool reInit = false;
bool hasReInit = false;

int start_pause_time;
int end_pause_time;

//ajout pour keystate
bool keyStates[256] = {false};  // Tableau pour suivre l'état des touches

//listeBub liste_bub; 

void Keyboard(unsigned char key, int x, int y)  // fonction allant gérer les input
{
	switch(key)
	{
		case 27: // ESC
			

			if (gameOver == false && (currentMenu==nouvellePartie || currentMenu == pauseMenu)){ 
				enPause = !enPause;
				printf("Bool enPause = %i\n", enPause);
				fflush(stdout);
				if (enPause == false){
					gameTimers();
					int end_pause_time = time(NULL);
					if (currentMenu==pauseMenu){
						changerMenu(nouvellePartie);

					}
				}		
				else{
					changerMenu(pauseMenu);
					int start_pause_time = time(NULL);
				}
			}
			break;

		case'z':
			if (enPause == false && gameOver == false) 
				UP = true;
			break;

		case'q':
			if (enPause == false && gameOver == false) 
				LEFT = true;
			break;

		case'd':
			if (enPause == false && gameOver == false) 
				RIGHT = true;
			break;

		case's':
			if (enPause == false && gameOver == false) 
				DOWN = true;
			break;

		case'r':
			if (enPause == false && gameOver == false) 
				reinitializeGame();
			break;


		case 32:
			if (enPause == false && gameOver == false) 
				SHOOT = true;
			break;	

			case'e':
		if (enPause == false && gameOver == false) 
			BUBBLE_SHOT = true;
		break;	
	}	
}



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
			shootBubble(p);
			keyStates['e'] = false;	
		}
	}




		if (keyStates[27]) {


			if (gameOver == false && (currentMenu==nouvellePartie || currentMenu == pauseMenu)){ 
				enPause = !enPause;
				printf("Bool enPause = %i\n", enPause);
				fflush(stdout);
				if (enPause == false){
					gameTimers();
					int end_pause_time = time(NULL);
					if (currentMenu==pauseMenu){
						changerMenu(nouvellePartie);

					}
				}		
				else{
					changerMenu(pauseMenu);
					int start_pause_time = time(NULL);
				}
			}
		keyStates[27] = false;	
		}

	

	


	if (gameOver == true)
		changerMenu(gameOverMenu);

	if (hasReInit == false){
		reinitializeGame();
		hasReInit = true;
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
