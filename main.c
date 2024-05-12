#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

#include "time.h"
#include "SOIL.h"
#include "loadMap.h"
#include "game.h"
#include "player.h"
#include "enemies.h"
#include "tirs.h"
#include "constantes.h"
#include "collision.h" 
#include "menu.h" 
#include "gameInitAndTimers.h" 
#include "textures.h" 
#include "displays.h" 

int main(int argc, char *argv[])
{

	mX = 124;  
	mY = 124; 

	loadMap(&mX, &mY);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(900,600); 

	glutCreateWindow("Ride Or Die! A VvV Story");
	initTextures();

	glutDisplayFunc(Display);

	glutReshapeFunc(handleResize);

	initGameParametres();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return 0;
}
