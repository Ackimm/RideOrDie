#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


#include "loadMap.h"
#include "drawMap.h"
#include "player.h"




void drawWall(int mX, int mY)			// fonction qui affiche les murs et les plateformes

{

/* 
Attention, en C les tableaux à deux dimensions ont le format tableau[y][x]
Du coup, quand je voudrais faire le changement plus tard, il faut juste intervertir les i & j dans l'affichage et dans les map[i][j]
Pour l'affichage de la map du moins
*/

	
	for (int i = 0; i < mX; ++i)
	{
		for (int j = 0; j < mY; ++j)
		{ 
			//drawSky();
			if(map[i][j] == '!')
			{
			
                glColor3f(1.0f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			    glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				
				glBegin(GL_QUADS);
					glColor3f(1.0,1.0,1.0);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
				
			}
			
			
			if (map[i][j]  == 'o')
			{
				glColor3f(0.6f,1.0f,1.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			
			if (map[i][j]  == 'i')
			{
				glColor3f(1.0f,0.0f,0.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(i*Square_size,j*Square_size,0.0f);
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			
			

			
			
		}
	}
}

void drawPlayer(player p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	
	
	glColor3f(0.0f,1.0f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);

	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(Square_size, 0.0f, 0.0f);
	glVertex3f(Square_size,Square_size, 0.0f);
	glVertex3f(0.0f,Square_size, 0.0f);

	glEnd();


	
	
}

