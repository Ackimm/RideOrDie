#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


//#include "loadMap.h"
#include "drawMap.h"
//#include "game.h"
//#include "enemies.h"
//#include "player.h"
//#include "tirs.h"


/*
void drawSky()
{
        glBegin(GL_POLYGON); 
            glColor3f(0.196078,0.6,0.8);
	
            glVertex3f(Square_size, 30*Square_size, 1);
            glVertex3f(Square_size, Square_size, 1);
            glVertex3f(30*Square_size, 0, 1);
            glVertex3f(30*Square_size, 30*Square_size, 1);
        glEnd();
}
*/


/*------------------------

*(*(map + i) + j) représente la valeur du caractère à la position (i, j) du tableau à 2 dimensions 
en sachant que la position (i, j) est la position (y, x) et non (x, y)

------------------------*/


void drawWall(int *maxX, int *maxY)			// fonction qui affiche les murs et les plateformes
{	

	for (int i = 0; i < (*maxY); i++)
	{
		for (int j = 0; j < (*maxX); j++)
		{
			//drawSky();
			if(*(*(map + i) + j) == '!')
			{
                glColor3f(1.0f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			    glLoadIdentity();
				glTranslatef(j*Square_size,i*Square_size,0.0f); // sur une map carré, la seule chose qui change pour le drawmap c'est ces variables i et j. Il y a aussi quand même les ennemis, les tirs, etc..
				
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();	
			}
			
			if(*(*(map + i) + j)  == 'o')
			{
				glColor3f(0.6f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			    glLoadIdentity();
				glTranslatef(j*Square_size,i*Square_size,0.0f);
				
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);


				glEnd();	
			}
		
			if(*(*(map + i) + j) == 'i')
			{
				glColor3f(1.0f,0.0f,0.0f);
				glMatrixMode(GL_MODELVIEW);
				
			    glLoadIdentity();
				glTranslatef(j*Square_size,i*Square_size,0.0f);
				
				
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

void drawEnemy(enemy e)	
{
	int i, j;
	i = e->pos.x;
	j = e->pos.y;
	glColor3f(1.0f,0.0F,0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Square_size,0.0f,0.0f);
	glVertex3f(Square_size,Square_size,0.0f);
	glVertex3f(0.0f,Square_size,0.0f);
	glEnd();
}

void drawAllEnnemis(listeEn e)
{	
	enemy first = malloc(sizeof(enemies));
	enemy next = malloc(sizeof(enemies));
	first = e->starList;
	next = e->starList->nextptr;
	if (e->starList != NULL || e->endList != NULL)
	{
		drawEnemy(first);
		if (e->starList->nextptr != NULL)
		{
			drawEnemy(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawEnemy(next);
			}
		}
	}
}

void drawTirs(tirsP p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	glColor3f(0.0f, 1.0f, 0.5f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Shoot_size,j*Shoot_size,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Shoot_size,0.0f,0.0f);
	glVertex3f(Shoot_size,Shoot_size,0.0f);
	glVertex3f(0.0f,Shoot_size,0.0f);
	glEnd();
}


void drawAllTirs(listetirsP t)
{
	tirsP first = malloc(sizeof(tirs));
	tirsP next = malloc(sizeof(tirs));
	first = t->starList;
	if (t->starList != NULL && t->starList->nextptr != NULL)
	{
	next = t->starList->nextptr;
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		drawTirs(first);
		if (t->starList->nextptr != NULL)
		{
			drawTirs(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawTirs(next);
			}
		}
	}
}
