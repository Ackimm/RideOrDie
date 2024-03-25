#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "player.h"
#include "enemies.h"
#include "time.h"

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}


void handleResize(int width,int height)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (height == 0)
		height = 1;
	//float ratio =  width * 1.0 / height;
  	  float aspectRatio = (float)width / (float)height;



	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the correct perspective.
	//gluPerspective(45,ratio,1,100);
	
	gluOrtho2D(0, mX * Square_size * aspectRatio, mY * Square_size * aspectRatio, 0);
	
	//gluOrtho2D(0, ratio*width, ratio*height, 0);
		
}


void Display()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        game(&mX, &mY, p, e);
	//drawWall(mX, mY);
	glFlush();
}

int main(int argc, char *argv[])
{
	
// en vrai 124*125 pour le fichier 120*140 horizontal (à creuse...)
// en vrai 124*126 pour le fichier 124*124 réseau de routes (à creuse...)
// valeurs origine pour map 1 : 30 * 41 

	mX = 124; // valeur réelle 124 pour le verti 
	mY = 124; // valeur réelle 124 pour le verti 

	srand(time(NULL));
	loadMap(&mX, &mY);
	p = createPlayer(&mX, &mY);
	e = initialListEnemies();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((mX)*Square_size, mY*Square_size);

	glutCreateWindow("Test");

	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);
	glutTimerFunc(10, updateEnemies, 1);
	glutTimerFunc(30, updateNewEnemies, 3);
	glutTimerFunc(20, updateDeleateEnemies, 4);
	
	

	glEnable(GL_DEPTH_TEST);
	

	glutMainLoop();

	return 0;
}
