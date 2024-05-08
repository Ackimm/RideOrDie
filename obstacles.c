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


#include "obstacles.h"
#include "game.h"
#include "constantes.h"
#include "gameInitAndTimers.h"

obstacle obs; // pour que d'autres fichiers puissent l'utiliser
listeObs liste_obs; // pour que d'autres fichiers puissent l'utiliser
bool FinishedInitObstacles;



listeObs initialListObstacles(){
	listeObs liste_obs = malloc(sizeof(listeObstacles));
	if (liste_obs == NULL)
	{
		exit(EXIT_FAILURE);
	}
	liste_obs->premier = NULL;
	liste_obs->quantite = 0;
	return liste_obs;
}

obstacle createObstacle(){
    obstacle nouveau = malloc(sizeof(obstacles));
	int x = rand()%(94-30)+30;
	if (nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	} 
	nouveau->vie = 1;
	nouveau->pos.x = x;
	nouveau->pos.y = 5;
	nouveau->active = true;
	nouveau->bubbled = false;
	nouveau->hauteur = 12;
	nouveau->largeur = 9;
    nouveau->suivant = NULL;
	return nouveau;

  }

void insertionObstacles(listeObs liste_obs, obstacle nouveau)
{

    if (liste_obs == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
   
    /* Insertion de l'élément au début de la liste */
   
    if (liste_obs->premier == NULL){
        liste_obs->premier = nouveau;
    }
    else{
        obstacle temp = liste_obs->premier;
        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }

	liste_obs->quantite += 1;
//    printf("Ajout Obs, nouvelle quantité : %i\n",liste_obs->quantite); // vérification de la quantité d'ennemis dans la chaine
 //   fflush(stdout);
}


void suppressionObstacles(listeObs liste_obs){
    bool test = false;
    if (liste_obs->premier != NULL)
    {
        obstacle tested = liste_obs->premier;
        obstacle prevObs = NULL;
        while (tested != NULL)
        {
            obstacle obs_suivant = tested->suivant; 
            if (tested->active == test)
            {
                if (prevObs == NULL)
                {
                    liste_obs->premier = tested->suivant;
                }
                else
                {
                    prevObs->suivant = tested->suivant;
                }
              	free(tested);
				liste_obs->quantite--;
            //    printf("Suppression Obs, nouvelle quantité : %i\n",liste_obs->quantite); // vérification de la quantité d'ennemis dans la chaine
             //   fflush(stdout);
            }
            else
            {
                prevObs = tested;
            }
            tested = obs_suivant;
        }
    }
}




void updateObstacles(int valeur)
{
	obs = liste_obs->premier;
	if (liste_obs->premier != NULL)
	{
		obs->pos.y += 1;

		if (obs->pos.y > 120 || obs->vie == 0 || reInit == true) 
		{
			obs->pos.y = 2;
			obs->active = false;
		}
		while (obs->suivant != NULL)
		{
			obs = obs->suivant;
			obs->pos.y +=1;

			if (obs->pos.y > 120 || obs->vie == 0 || reInit == true) 
			{
				obs->pos.y = 2;
				obs->active = false;
			}
		}
	}
	glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(FreqUpdateObstacles, updateObstacles, 0);
	
	if (reInit==true)
		FinishedInitObstacles = true;

		
	if (FinishedInitTirs==true && FinishedInitEnnemis==true && FinishedInitObstacles==true && FinishedInitBubbles==true)
		reInit=false;


}

void updateNewObstacles(int valeur)
{
	if (reInit == false && enPause == false ){
		obstacle new = createObstacle();
		insertionObstacles(liste_obs, new);
		glutPostRedisplay();
	}
	if (enPause == false && gameOver == false  && reInit == false) 
		glutTimerFunc(FreqUpdateNewObstacles, updateNewObstacles, 0);
}

void updateDeleteObstacles(int valeur)
{
	if (liste_obs->premier != NULL)
	{
		suppressionObstacles(liste_obs);
	}
	glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(updateFrequency, updateDeleteObstacles, 0);
}
