#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


#include "loadMap.h"
#include "enemies.h"
#include "game.h"
#include "constantes.h"
#include "gameInitAndTimers.h"




enemy q;
listeEn e;
bool FinishedInitEnnemis;



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

enemy createEnemy()
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
	new->speed = 100;
	new->largeur = 6;
	new->hauteur = 18;

	new->couleur = (1+rand()%5);

	new->nextptr = NULL;
	new->prevptr = NULL;
	new->active = true;
	return new;
}

void insertionEnemies(listeEn e, enemy base)
{
	// enemy new = malloc(sizeof(enemies)); // save
	enemy new; // tentaive
	/*if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}*/
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
    test = false;
    if (e->starList != NULL)
    {
        enemy base = e->starList;
        while (base != NULL)
        {
            enemy nextEnemy = base->nextptr; // Sauvegarde du prochain ennemi avant de supprimer celui-ci
            if (base->active == test)
            {
                if (e->starList == base && e->endList == base)
                {
                    e->starList = NULL;
                    e->endList = NULL;
                }
                else if (e->starList == base)
                {
                    e->starList = base->nextptr;
                    e->starList->prevptr = NULL;
                }
                else if (e->endList == base)
                {
                    e->endList = base->prevptr;
                    e->endList->nextptr = NULL;
                }
                else
                {
                    base->prevptr->nextptr = base->nextptr;
                    base->nextptr->prevptr = base->prevptr;
                }
              	free(base); // Libération de la mémoire relatif à une unité enemy
				e->quantite--;
				// printf("Quantité : %i\n",e->quantite); // vérification de la quantité d'ennemis dans la chaine
            }
            base = nextEnemy; // Passage à l'ennemi suivant dans la liste
        }
    }
}



void updateEnemies(int valeur)
{
	q = e->starList;
	if (e->starList != NULL)
	{
		q->pos.y += 1;

/*-----------Tentative de ciblage du joueur mais problème ---------*/

//		if (p->pos.x > q->pos.x)
//			q->pos.x += 0.0000001;
//		else if (p->pos.x < q->pos.x) 	
//			q->pos.x -= 0.0000001;

/*-----------Tentative de ciblage du joueur mais problème ---------*/


		if (q->pos.y > 120 || q->vie == 0 || reInit == true) 
		{
			q->pos.y = 2;
			q->active = false;
		}
		while (q->nextptr != NULL)
		{
			q = q->nextptr;
			q->pos.y +=1;

/*-----------Tentative de ciblage du joueur mais problème ---------*/

//			if (p->pos.x > q->pos.x)
//				q->pos.x += 0.0000001;
//			else if (p->pos.x < q->pos.x) 	
//				q->pos.x -= 0.0000001;

/*-----------Tentative de ciblage du joueur mais problème ---------*/


			if (q->pos.y > 120 || q->vie == 0 || reInit == true) 
			{
				q->pos.y = 2;
				q->active = false;
			}
		}
	}
	glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(enemySpeed, updateEnemies, 0);
	
	if (reInit==true)
		FinishedInitEnnemis = true;

		
	if (FinishedInitTirs==true && FinishedInitEnnemis==true)
		reInit=false;


}

void updateNewEnemies(int valeur)
{
	if (reInit == false && enPause == false ){
		enemy new = createEnemy();
		insertionEnemies(e, new);
		glutPostRedisplay();
	}
	if (enPause == false && gameOver == false  && reInit == false) 
		glutTimerFunc(updateNewEnemy, updateNewEnemies, 0);
}

void updateDeleteEnemies(int valeur)
{
	if (e->starList != NULL || e->endList != NULL)
	{
		suppressionEnemies(e, test);
	}
	glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(updateFrequency, updateDeleteEnemies, 0);
}
