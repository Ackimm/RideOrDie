#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "loadMap.h"
#include "enemies.h"
#include "game.h"


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
enemy q;
listeEn e;


// a mettre une limite d'ennemis actifs pour tester le lag


listeEn initialListEnemies()
{
	listeEn e = malloc(sizeof(listeEnemies));
	if (e == NULL)
	{
		exit(EXIT_FAILURE);
	}
	e->starList = NULL;
	e->endList = NULL;
	e->quantite = 0;
	return e;
}

enemy createEnemy(int *maxX)
{
	enemy new = malloc(sizeof(enemies));
	//int x = (rand() % (*maxX + 10) + 1); // ici faire en sorte d'avoir un nombre en 30 et 94
	int x = rand()%(94-30)+30;
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	} 
	new->vie = 1;
	new->pos.x = x;
	new->pos.y = 5;
	new->nextptr = NULL;
	new->prevptr = NULL;
	new->active = true;
	return new;
}

void insertionEnemies(listeEn e, enemy base)
{
	enemy new = malloc(sizeof(enemies));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new = base;
	if (e->starList == NULL || e->endList == NULL)
	{
		e->endList= new;
		e->starList = new;
	}
	else
	{
		new->nextptr = e->starList;
		e->starList->prevptr = new;
		e->starList = new;
	}
	e->quantite += 1;
}

void suppressionEnemies(listeEn e, bool test)
{
	//test = false;
	if (e->starList != NULL)
	{
		enemy base = malloc(sizeof(enemies));
		if (base == NULL)
		{
			exit(EXIT_FAILURE);
		}
		base = e->starList;
		while (base != NULL)
		{
			if (base->active == test)
			{
				enemy delete = malloc(sizeof(enemies));
				delete = base;
				base = base->nextptr;
				if (e->starList == delete && e->endList == delete)
				{
					e->starList = NULL;
					e->endList = NULL;
				}
				else if (e->starList != delete && e->endList == delete)
				{
					e->endList = delete->prevptr;
					e->endList->nextptr = NULL;
				}
				else if (e->starList == delete && e->endList != delete)
				{
					e->starList  = delete->nextptr;
					e->starList->prevptr = NULL;
				}
				else
				{
					delete->nextptr->prevptr = delete->prevptr;
					delete->prevptr->nextptr = delete->nextptr;
				}
				free(delete);
				e->quantite--;
			}
			else
			{
				base = base->nextptr;
			}
		}
	}
}



void updateEnemies(int valeur)
{
	q = e->starList;
	if (e->starList != NULL)
	{
		q->pos.y += 1;
		if (q->pos.y > 120)
		{
			q->pos.y = 2;
			q->active = false;
		}
		while (q->nextptr != NULL)
		{
			q = q->nextptr;
			q->pos.y +=1;
			if (q->pos.y > 120)
			{
				q->pos.y = 2;
				q->active = false;
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateEnemies, 1);
}

void updateNewEnemies(int valeur)
{
	enemy new = createEnemy((&mY));
	insertionEnemies(e, new);
	glutPostRedisplay();
	glutTimerFunc(1000, updateNewEnemies, 3);
}

void updateDeleteEnemies(int valeur)
{
	if (e->starList != NULL || e->endList != NULL)
	{
		suppressionEnemies(e, test);
	}
	glutPostRedisplay();
	glutTimerFunc(50, updateDeleteEnemies, 4);
}
