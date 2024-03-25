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
    game(MaxX, MaxY, p);


	// drawWall(map);
	// drawPlayer(p);
	glutSwapBuffers() ;
	//glFlush();
}




int main(int argc, char *argv[])
{
		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize((MaxX)*Square_size, (MaxY)*Square_size);

	glutCreateWindow("Ride or Die! A VvV story");
	loadMap(map);     //Charge la carte
	p = createPlayer(mX, mY);

	initRendering();

	glutDisplayFunc(Display);


	glutReshapeFunc(handleResize);
	glutIdleFunc(Display);
	


	glutMainLoop();

	return 0;
}
