#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

#include "loadMap.h"
#include "game.h"
#include "player.h"
#include "enemies.h"
#include "tirs.h"
#include "constantes.h"
#include "collision.h" 
#include "menu.h" 
#include "gameInitAndTimers.h" 



   

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
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




void DisplayMenu()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawMenu();

	glutSwapBuffers();
}


void DisplayNewGame()
{
	//glutMouseFunc(mouseClick);//pour tenter de pouvoir cliquer sur les boutons du gameOver menu mais ne fonctionne pas

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
	game(&mX, &mY, scrolling_value, p, e, t); // save
	displayHUD(); 

	//displayGameOver(); 

	glutSwapBuffers();
	
}

void DisplayGameOverMenu()
{
	
	//glutMouseFunc(mouseClick);pour tenter de pouvoir cliquer sur les boutons du gameOver menu mais ne fonctionne pas

	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	game(&mX, &mY, scrolling_value, p, e, t); // save
	displayHUD(); 
	displayGameOver(); 

	glutSwapBuffers();
	
}

void DisplayPauseMenu()
{

	//glutMouseFunc(mouseClick);pour tenter de pouvoir cliquer sur les boutons du gameOver menu mais ne fonctionne pas

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
	//	startTimer();
	//	initGameParametres();
	//	gameTimers();

			// introduire une nouvelle fonction destroy all qui détruit toutes le slistes chaines + remise à zero du timer, de la vie, position etc... 


//	glutReshapeFunc(handleResize);

		DisplayNewGame();
		
	break;

	case continuerPartie:
		//startTimer(); // ne fonctionne pas
		//initGameParametres();
		//gameTimers();
		//	glutReshapeFunc(handleResize);


		DisplayNewGame();
		
	break;

	case highScores:
		glutReshapeFunc(handleResize);
		DisplayScores();
	break;

	case parametres:
		glutReshapeFunc(handleResize);
		DisplayParametres();
	break;

	case menuAccueil:
		glutReshapeFunc(handleResize);
		DisplayMenu();
	break;		

	case gameOverMenu:
		glutReshapeFunc(handleResize);
		DisplayGameOverMenu();
	break;		

	case pauseMenu:
		glutReshapeFunc(handleResize);
		DisplayPauseMenu();
	break;	

	case quitter:
		exit(0);		
	break;	

	default:
		glutReshapeFunc(handleResize);
		DisplayMenu();
	break;
	}

	
}




int main(int argc, char *argv[])
{

	
	mX = 124;  
	mY = 124; 

	loadMap(&mX, &mY);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(900,600); 

	glutCreateWindow("Ride Or Die! A VvV Story");

	initRendering();


	


	glutDisplayFunc(Display);



	glutReshapeFunc(handleResize);



	//test de replacement de ces éléments 


		startTimer();
		initGameParametres();
		gameTimers();



	//fin de test


	glEnable(GL_DEPTH_TEST);
	

	glutMainLoop();

	return 0;
}
