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

#include "loadMap.h"
#include "drawMap.h"
#include "enemies.h"

bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;


void Keyboard(unsigned char key, int x, int y)  // fonction allant gérer les input
{
	switch(key)
	{
		case 27:
			exit(0);

		case'z':
			UP = true;
			break;

		case'q':
			LEFT = true;
			break;

		case'd':
			RIGHT = true;
			break;

		case's':
			DOWN = true;
			break;
	}	
}


void game(int *maxX, int *maxY, player p, listeEn e)
{


	drawWall(maxX, maxY);			//afficher la carte
	drawPlayer(p);
	if (e->starList != NULL || e->endList != NULL)
	{
		drawAllEnnemis(e);
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


	glutPostRedisplay();
}