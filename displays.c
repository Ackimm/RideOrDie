#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>


#include "menu.h"
#include "game.h"
#include "constantes.h"
#include "loadMap.h"
#include "drawMap.h"
#include "gameInitAndTimers.h"
#include "bestScores.h"
#include "collision.h"
#include "textures.h"



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void DisplayMenu()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	
	drawMenu();

	glutSwapBuffers();
}


void DisplayNewGame()
{

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	game(&mX, &mY, scrolling_value, p, e, t); // save
	
	displayHUD(); 
	
	glutSwapBuffers();
	
}

void DisplayGameOverMenu()
{
	

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gameOver=true;
	game(&mX, &mY, scrolling_value, p, e, t); // save
	displayHUD(); 
	displayGameOver(); 

	glutSwapBuffers();
	
}

void DisplayPauseMenu()
{


	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	game(&mX, &mY, scrolling_value, p, e, t); // save
	displayHUD(); 
	displayPauseButtons(); 

	glutSwapBuffers();
	
}

void DisplayContinueGame()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
	game(&mX, &mY, scrolling_value, p, e, t); // save
	displayHUD(); 
	glutSwapBuffers();
	
}

void DisplayParametres()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	drawParametres();
	glutSwapBuffers();
}

void DisplayScores()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	drawScores();
	glutSwapBuffers();
}



void Display()
{

	switch (currentMenu)
	{
	case nouvellePartie:
		DisplayNewGame();
	break;

	case continuerPartie:
		DisplayNewGame();
	break;

	case highScores:
		DisplayScores();
	break;

	case parametres:
		DisplayParametres();
	break;

	case menuAccueil:
		DisplayMenu();
	break;		

	case gameOverMenu:
		DisplayGameOverMenu();
	break;		

	case pauseMenu:
		DisplayPauseMenu();
	break;	

	case quitter:
		exit(0);		
	break;	

	default:
		DisplayMenu();
	break;
	}
}


void handleResize(int width,int height)
{
	if (height == 0)
		height = 1;

	float aspectRatio = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (mX-1) * Square_size , mY * Square_size , 0);

}