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



bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;
bool SHOOT = false;
bool test;
bool enPause;
bool gameOver = false;
bool reInit = false;
bool hasReInit = false;

int start_pause_time;
int end_pause_time;


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
	}	
}



void game(int *maxX, int *maxY, float scrolling_value, player p, listeEn e, listetirsP  t) //save 
//void game(int *maxX, int *maxY, float scrolling_value, player p)
//void game(int *maxX, int *maxY, float scrolling_value, player p, listeEn e)

{

	glutMouseFunc(mouseClick);//pour tenter de pouvoir cliquer sur les boutons du gameOver menu mais ne fonctionne pas


	drawWall(maxX, maxY, scrolling_value);			//afficher la carte
	drawPlayer(p);
	if (e->starList != NULL || e->endList != NULL)
	{
		drawAllEnnemis(e);
	}		

	
	if (t->starList != NULL || t->endList != NULL)
	{
		drawAllTirs(t);
	}
	

	glutKeyboardFunc(Keyboard);		//fonction de glut gérant le clavier
	
	
	if (LEFT == true)
	{
		
		moveLeft(p);		//va se déplacer vers la gauche si on appuie sur q
		LEFT = false;
		
	}
	if (RIGHT == true)
	{
		
		moveRight(p);		//va se déplacer vers la droite si on apppuie sur d
		RIGHT = false;
	}
	if (UP == true)
	{
		moveUp(p);
		UP = false;
	}
	
	if (DOWN == true)
	{
		moveDown(p);
		DOWN = false;
	}

	if (SHOOT == true)
	{
		tirer(p, t);
		SHOOT=false;
	}

	if (gameOver == true)
		changerMenu(gameOverMenu);

	if (hasReInit == false){
		reinitializeGame();
		hasReInit = true;
	}

		
	glutPostRedisplay();
}