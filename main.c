#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "player.h"
#include "enemies.h"

// DANS LA VERSION FINALE, LE MAIN NE DOIT CONTENIR QUE LA FONCTION MAIN 



// test de modification depuis la console pour un 2ième commit
// 2ieme modificaion


char map[MaxX][MaxY]; // nécessaire au chargement
extern player p;


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
	
	gluOrtho2D(0, MaxY * Square_size * aspectRatio, MaxX * Square_size * aspectRatio, 0);
	
	//gluOrtho2D(0, ratio*width, ratio*height, 0);
		
}


void Display()
{
	
	//glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	printf("display");
    game(MaxX, MaxY, p, e); // l'ajout du e a fonctionné mais ça plante :'( 


	// drawWall(map);
	// drawPlayer(p);
	glutSwapBuffers() ;
	//glFlush();
}




int main(int argc, char *argv[])
{

	printf("lancement\n");


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize((MaxX)*Square_size, (MaxY)*Square_size);

	glutCreateWindow("Ride or Die! A VvV story");
	srand(time(NULL));
	loadMap(map);     //Charge la carte
	p = createPlayer(mX, mY);
	printf("map chargé, player créé");


	initRendering();

	glutDisplayFunc(Display);


	glutReshapeFunc(handleResize);
	glutTimerFunc(10, updateEnemies, 1);
	glutTimerFunc(30, updateNewEnemies, 3);
	glutTimerFunc(20, updateDeleateEnemies, 4);

	glutIdleFunc(Display);
	


	glutMainLoop();

	return 0;
}
