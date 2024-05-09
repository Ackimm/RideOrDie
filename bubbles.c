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


#include "bubbles.h"
#include "game.h"
#include "player.h"
#include "constantes.h"
#include "gameInitAndTimers.h"
#include "fireEnnemi.h"

bubble bub; // pour que d'autres fichiers puissent l'utiliser
listeBub liste_bub; // pour que d'autres fichiers puissent l'utiliser
bool FinishedInitBubbles;



listeBub initialListBubbles(){
	listeBub liste_bub = malloc(sizeof(listeBubbles));
	if (liste_bub == NULL)
	{
		exit(EXIT_FAILURE);
	}
	liste_bub->premier = NULL;
	liste_bub->quantite = 0;
	return liste_bub;
}

bubble createBubble(player p){
    
	int x = (p->pos.x);
	int y = (p->pos.y);
	
	bubble nouveau = malloc(sizeof(bubbles));
	
	if (nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	} 

	nouveau->active = true;
	nouveau->pos.x = x;
	nouveau->pos.y = y;
	nouveau->hauteur = 10;
	nouveau->largeur = 10;
    nouveau->suivant = NULL;
	return nouveau;

  }

void insertionBubble(listeBub liste_bub, bubble nouveau)
{

    if (liste_bub == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
   
    /* Insertion de l'élément au début de la liste */
   
    if (liste_bub->premier == NULL){
        liste_bub->premier = nouveau;
    }
    else{
        bubble temp = liste_bub->premier;
        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }

	liste_bub->quantite += 1;
   // printf("Ajout bubble, nouvelle quantité : %i\n",liste_bub->quantite); // vérification de la quantité d'ennemis dans la chaine
   // fflush(stdout);
}

/*
void suppressionBubbles(listeBub liste_bub){
    bool test = false;
    if (liste_bub->premier != NULL)
    {
        bubble tested = liste_bub->premier;
       	bubble next = tested->suivant; 

		while (tested != NULL)
        {
			if (tested->active == test)
			{
				
					liste_bub->premier = tested->suivant;
				if (tested->suivant->suivant != NULL)
					liste_bub->premier->suivant = tested->suivant->suivant;
				else 
					liste_bub->premier->suivant = NULL;
				
				free(tested);
				liste_bub->quantite--;
				printf("Suppression Bubb, nouvelle quantité : %i\n",liste_bub->quantite); // vérification de la quantité d'ennemis dans la chaine
				fflush(stdout);
			}
		
		tested = next;
    	}    
    }
}
*/

void suppressionBubbles(listeBub liste_bub) {
    bool test = false;
    if (liste_bub->premier != NULL) {
        bubble tested = liste_bub->premier;
        bubble previous = NULL;

        while (tested != NULL) {
            bubble next = tested->suivant; // Sauvegarde du prochain élément avant de supprimer celui-ci

            if (tested->active == test) {
                if (previous == NULL) {
                    // Si le premier élément doit être supprimé
                    liste_bub->premier = tested->suivant;
                } else {
                    // Si un élément au milieu de la liste doit être supprimé
                    previous->suivant = tested->suivant;
                }

                free(tested);
                liste_bub->quantite--;

              //  printf("Suppression Bubble, nouvelle quantité : %i\n", liste_bub->quantite);

			// listeBub liste_bubPRINT = liste_bub;
             //   while (liste_bubPRINT->premier != NULL) {
             //       printf("while1 : adresse et pos x et y d'un élément de la liste chainee %p : %i - %i\n", (void*)liste_bubPRINT->premier, liste_bubPRINT->premier->pos.x, liste_bubPRINT->premier->pos.y);
              //      liste_bubPRINT->premier = liste_bubPRINT->premier->suivant;
              //  }


               // fflush(stdout);
            } else {
                // Mise à jour de l'élément précédent uniquement si l'élément actuel n'est pas supprimé
                previous = tested;
            }

            tested = next; // Passage à l'élément suivant dans la liste
        }
    }
}


void shootBubble(player p)
{
	bubble nouveau = createBubble(p);
	insertionBubble(liste_bub, nouveau);
}


void updateBubbles(int valeur)
{
	bub = liste_bub->premier;
	if (liste_bub->premier != NULL)
	{
		bub->pos.y -= 1;
	//	printf("1. Bubble position y = %i\n", bub->pos.y);
	//	fflush;

		if (bub->pos.y < 2 || reInit == true) 
		{
			//bub->pos.y = 0;
			bub->active = false;
	//		printf("1. Bubble desactive\n");
	//	fflush;
		}

		while (bub->suivant != NULL)
		{
			bub = bub->suivant;
			bub->pos.y -=1;
	//		printf("2. Bubble position y = %i\n", bub->pos.y);
	//	fflush;

			if (bub->pos.y < 2 || reInit == true) 
			{
				//bub->pos.y = 0;
				bub->active = false;
		//			printf("2. Bubble desactive\n");
		//fflush;
			}
		}
	}

	glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(tirsSpeed, updateBubbles, 0);
	
	if (reInit==true)
		FinishedInitBubbles = true;

		
//if (FinishedInitTirs==true && FinishedInitEnnemis==true && FinishedInitObstacles==true && FinishedInitBubbles==true && FinishedInitTirsEnnemi==true)	
	if (FinishedInitTirs==true && FinishedInitEnnemis==true)	
	//if (FinishedInitTirs==true && FinishedInitEnnemis==true && FinishedInitObstacles==true && FinishedInitBubbles==true)
			reInit=false;


}


void updateDeleteBubbles(int valeur)
{
	if (liste_bub->premier != NULL)
	{
		suppressionBubbles(liste_bub);
	}
	glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(updateFrequency, updateDeleteBubbles, 0);
}
