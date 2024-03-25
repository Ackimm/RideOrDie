#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "tirs.h"
#include "game.h"
#include "player.h"


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


tirsP r;
listetirsP t;

listetirsP  initialListeTirs()
{
	listetirsP t = malloc(sizeof(listeTirs));
	if (t == NULL)
	{
		exit(EXIT_FAILURE);
	}
	t->starList = NULL;
	t->endList = NULL;
	t->quantite = 0;
	return t;
}


tirsP createTirs(player p)
{
	int x = (p->pos.x);
	int y = ((p->pos.y));
	tirsP new = malloc(sizeof(tirs));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->pos.x = x;
	new->pos.y = y;
	new->nextptr = NULL;
	new->prevptr = NULL;
	new->active = true;
	return new;
}

void insertionTirs(listetirsP t, tirsP base)
{
	tirsP new = malloc(sizeof(tirs));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new = base;
	if (t->starList == NULL || t->endList == NULL)
	{
		t->endList = new;
		t->starList = new;
	}
	else
	{
		new->nextptr = t->starList;
		t->starList->prevptr = new;
		t->starList = new;
	}
	t->quantite += 1;
}

void suppressionTirs(listetirsP t, bool test)
{
	test = false;
	if (t->starList != NULL)
	{
		tirsP base = malloc(sizeof(tirs));
		base = t->starList;
		while (base != NULL)
		{
			if (base->active == test)
			{
				tirsP deleate = malloc(sizeof(tirs));
				deleate = base;
				base = base->nextptr;
				if (t->starList == deleate && t->endList == deleate)
				{
					t->endList = NULL;
					t->starList = NULL;
				}
				else if (t->starList != deleate && t->endList == deleate)
				{
					t->endList = deleate->prevptr;
					t->endList->nextptr = NULL;
				}
				else if (t->starList == deleate && t->endList != deleate)
				{
					t->starList = deleate->nextptr;
					t->starList->prevptr = NULL;
				}
				else
				{
					deleate->nextptr->prevptr = deleate->prevptr;
					deleate->prevptr->nextptr = deleate->nextptr;
				}
				free(deleate);
				t->quantite--;
			}
			else
			{
				base = base->nextptr;
			}
		}
	}
}




void tirer(player p, listetirsP t)
{
	tirsP new = createTirs(p);
	insertionTirs(t, new);
}

// TIRS de main


void updateTirs(int valeur)
{
	r = t->starList;
	if (t->starList != NULL)
	{
		r->pos.y -= 1;
		if (r->pos.y < 1)
		{
			r->pos.y = 0;
			r->active = false;
		}
		while (r->nextptr != NULL)
		{
			r = r->nextptr;
			r->pos.y -= 1;
			if (r->pos.y < 1)
			{
				r->pos.y = 0;
				r->active = false;
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(5, updateTirs, 2);
}


void updateDeleteTirs(int valeur)
{
	if (t->starList != NULL || t->endList != NULL)
	{
		suppressionTirs(t, test);
	}
	glutPostRedisplay();
	glutTimerFunc(5, updateDeleteTirs, 5);
}



