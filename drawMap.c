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
#include "constantes.h"
#include "velo_jaune4.c"
#include "land_grass04.c"




/*------------------------

*(*(map + i) + j) représente la valeur du caractère à la position (i, j) du tableau à 2 dimensions 
en sachant que la position (i, j) est la position (y, x) et non (x, y)

------------------------*/


void drawWall(int *maxX, int *maxY, float scrolling_value)			// fonction qui affiche les murs et les plateformes
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
				glTranslatef(j*Square_size,i*Square_size,0.0f); // ici j et i sont inversés, il faudra encore un peu creuser pour comprendre pourquoi ça marche mieux ainsi
				
				
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
				glTranslatef(j*Square_size,i*Square_size+scrolling_value,0.0f);
//				glTranslatef(j*Square_size,i*Square_size,0.0f);


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
				
						
				/*--------------test image--------------------- (n'a pas fonctionné correctement, à revoir)
				int texture;

				

				glGenTextures(1,&texture);
				glBindTexture(GL_TEXTURE_2D,texture);
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
				gluBuild2DMipmaps(GL_TEXTURE_2D,grass.bytes_per_pixel, grass.width, grass.height,GL_RGB,GL_UNSIGNED_BYTE,grass.pixel_data);
				glEnable(GL_TEXTURE_2D);

				
				glDisable( GL_BLEND );// rajout pour tester la transparence

			----------------------test image-------------------------*/

				glTranslatef(j*Square_size,i*Square_size,0.0f);
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();

			//	glDisable(GL_TEXTURE_2D); // add

						
				// ancien code ci-dessous	
				/*	
					
					
					glBegin(GL_QUADS);
						glVertex3f(0.0f, 0.0f, 0.0f);
						glVertex3f(Square_size, 0.0f, 0.0f);
						glVertex3f(Square_size,Square_size, 0.0f);
						glVertex3f(0.0f,Square_size, 0.0f);

					glEnd();	

					*/
			}

			
		   }
		}
}

	

/*
alternative qui ne fonctionne pas mais que je trouve plus logique, plus directe


void drawWall(int *maxX, int *maxY, float scrolling_value) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int i = 0; i < *maxY; i++) {
        for (int j = 0; j < *maxX; j++) {
            char currentCell = *(*(map + i) + j);

            if (currentCell == '!') {
                glColor3f(1.0f, 1.0f, 1.0f);
            } else if (currentCell == 'o') {
                glColor3f(0.6f, 1.0f, 1.0f);
            } else if (currentCell == 'i') {
                glColor3f(1.0f, 0.0f, 0.0f);
            }

            glPushMatrix();
            glTranslatef(j * Square_size, i * Square_size + scrolling_value, 0.0f);
            glBegin(GL_QUADS);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(Square_size, 0.0f, 0.0f);
            glVertex3f(Square_size, Square_size, 0.0f);
            glVertex3f(0.0f, Square_size, 0.0f);
            glEnd();
            glPopMatrix();
        }
    }
}

*/



void drawPlayer(player p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	
	
//	glColor3f(0.0f,1.0f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


//test image
	int texture;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // rajout pour tester la transparence
	glEnable( GL_BLEND );// rajout pour tester la transparence

	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D,velo_jaune.bytes_per_pixel, velo_jaune.width, velo_jaune.height,GL_RGB,GL_UNSIGNED_BYTE,velo_jaune.pixel_data);
	glEnable(GL_TEXTURE_2D);

	
	glDisable( GL_BLEND );// rajout pour tester la transparence

//test image

	glTranslatef(i*Square_size,j*Square_size,0.0f);

	glBegin(GL_QUADS);



	glTexCoord2f(0.0,0.0); glVertex3f(-2.5 * alternate_player_size,12 * alternate_player_size, 0.0f); // sup gauche
	glTexCoord2f(1.0,0.0); glVertex3f(2.5 * alternate_player_size,12 * alternate_player_size, 0.0f); // sup droit
	glTexCoord2f(1.0,1.0); glVertex3f(2.5 * alternate_player_size, 0.0f, 0.0f); // inf droit
	glTexCoord2f(0.0,1.0); glVertex3f(-2.5 * alternate_player_size, 0.0f, 0.0f); // inf gauche




	glEnd();

	glDisable(GL_TEXTURE_2D); // add

	
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
	/*
	glVertex3f(0.0f,0.0f,0.0f); // coin supérieur gauche
	glVertex3f(Square_size,0.0f,0.0f); // coin supérieur droit
	glVertex3f(Square_size,Square_size,0.0f); // coin inférieur droit
	glVertex3f(0.0f,Square_size,0.0f); // coin inférieur gauche
	*/
// alternative : 

	glVertex3f(-2 * Square_size, 2 * Square_size,0.0f); // coin supérieur gauche
	glVertex3f(2 * Square_size, 2 * Square_size,0.0f); // coin supérieur droit
	glVertex3f(2 * Square_size,-2 * Square_size,0.0f); // coin inférieur droit
	glVertex3f(-2 * Square_size, -2 * Square_size,0.0f); // coin inférieur gauche

	glEnd();

}

void drawAllEnnemis(listeEn e)
{	
	//enemy first = malloc(sizeof(enemies)); // save
	//enemy next = malloc(sizeof(enemies)); //save
	enemy first; // tentative
	enemy next; // tentative
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
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	glBegin(GL_QUADS);// note pour plus tard : changer soit en ligne, soit en projectile avec image .c
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(Shoot_size,0.0f,0.0f); 
	glVertex3f(Shoot_size,Shoot_size*2,0.0f);
	glVertex3f(0.0f,Shoot_size*2,0.0f);
	glEnd();
}


void drawAllTirs(listetirsP t)
{
	//tirsP first = malloc(sizeof(tirs));//save
	//tirsP next = malloc(sizeof(tirs));//save
	tirsP first;//tentative
	tirsP next;//tentative
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
