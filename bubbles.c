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

bubble bub; 
listeBub liste_bub; 


// initialisation de la liste chainée bubbles vide avec allocation de mémoire pour la structure de liste
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

// création d'un éléménent bubble avec allocation de mémoire pour l'élément
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

// insertion d'un éléménent bubble dans la liste chainée
void insertionBubble(listeBub liste_bub, bubble nouveau)
{

    if (liste_bub == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
   

// dans le cas où la liste est vide
    if (liste_bub->premier == NULL){
        liste_bub->premier = nouveau;
    }

// dans le cas où la liste est n'est pas vide, 
//création d'un élément temporaire qui stock le début de la liste

    else{
        bubble temp = liste_bub->premier;
// on parcourt ensuite la liste jusqu'à trouver le dernier élément
// de la liste 	et on y insére l'élément nouveau en paramètre de la fonction d'insertion

        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }

	liste_bub->quantite += 1;

}


void suppressionBubbles(listeBub liste_bub) {
    bool test = false;
	// on s'assure que la liste contient bien un élément
    if (liste_bub->premier != NULL) {

	// on créé un élément qui sera testé et qui commence au premier élément de la liste
	// on créé un élément temporaire qui nous permettra de relier la chaine suite à une suppression d'élément	
        bubble tested = liste_bub->premier;
        bubble previous = NULL;


        while (tested != NULL) {
            bubble next = tested->suivant; // Sauvegarde du prochain élément avant de supprimer celui-ci

            if (tested->active == test) {
                if (previous == NULL) {
                    // si le premier élément doit être supprimé alors le premier devient son suivant
                    liste_bub->premier = tested->suivant;
                } else {
                    // si un élément au milieu de la liste doit être supprimé alors je le remplace par son élément suivant
                    previous->suivant = tested->suivant;
                }

                free(tested);
                liste_bub->quantite--;

/*---------- ici, quelques lignes permettant de vérifier le nombre d'éléments dans ma liste, 
-------------ça m'a surtout permis de vérifier que mon code fonctionnait bien

				printf("Suppression Bubble, nouvelle quantité : %i\n", liste_bub->quantite);
				listeBub liste_bubPRINT = liste_bub;
            	while (liste_bubPRINT->premier != NULL){
                    printf("while1 : adresse et pos x et y d'un élément de la liste chainee %p : %i - %i\n", (void*)liste_bubPRINT->premier, liste_bubPRINT->premier->pos.x, liste_bubPRINT->premier->pos.y);
                    liste_bubPRINT->premier = liste_bubPRINT->premier->suivant;
                }
				fflush(stdout);

---------*/

            } 

			else {
                // je mets à jour l'élément précédent uniquement si l'élément actuel n'est pas supprimé
                previous = tested;
            }
            tested = next; // je passe à l'élément suivant dans la liste
        }
    }
}

// fonction pour créer un nouvel élément de la liste et l'insérer directement dans la liste
void shootBubble(player p)
{
	bubble nouveau = createBubble(p);
	insertionBubble(liste_bub, nouveau);
}

// mise à jour des éléments de la liste pour les mouvements et le passage en active = false lorsque les conditions de suppressions sont rencontrées
void updateBubbles(int valeur)
{
	bub = liste_bub->premier;
	if (liste_bub->premier != NULL)
	{
		// le premier élément change de position
		bub->pos.y -= 1;
		// il est désactivé sous certaines conditions
		if (bub->pos.y < 2)  // avant : if (bub->pos.y < 2 || reInit == true)
		{
			bub->active = false;
	
		}

		// tant qu'il reste des éléments dans la liste, on refait le même traitement
		while (bub->suivant != NULL)
		{
			bub = bub->suivant;
			bub->pos.y -=1;

			if (bub->pos.y < 2 ) // avant : if (bub->pos.y < 2 || reInit == true)
			{
				bub->active = false;
			}
		}
	}

//	glutPostRedisplay();

	// on empêche de poursuivre la mise à jour des éléments si on est en pause ou gameover
	if (enPause == false && gameOver == false) 
		glutTimerFunc(tirsSpeed, updateBubbles, 0);
	

	/*-------------------------

	ça n'est plus utilisé mais avant de faire des fonctions qui détruise proprement toutes mes listes, 
	j'avais imaginé une solution moins efficace que je laisse ici pour montrer ce que j'avais initialllement prévu

	if (reInit==true)
		FinishedInitBubbles = true;

		
	if (FinishedInitTirs==true && FinishedInitEnnemis==true && FinishedInitObstacles==true && FinishedInitBubbles==true && FinishedInitTirsEnnemi==true)	
			reInit=false;

	--------------------------*/

}

 
void updateDeleteBubbles(int valeur)
{
	if (liste_bub->premier != NULL)
	{
		suppressionBubbles(liste_bub);
	}

	if (enPause == false && gameOver == false) 
		glutTimerFunc(updateFrequency, updateDeleteBubbles, 0);
}


