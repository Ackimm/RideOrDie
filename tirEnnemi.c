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


#include "tirEnnemi.h"
#include "game.h"
#include "player.h"
#include "enemies.h"
#include "constantes.h"
#include "gameInitAndTimers.h"


tirEnn tir_enn; 
listeTirEnn liste_tir_enn; 
bool FinishedInitTirsEnnemi;



listeTirEnn initialListTirsEnnemi(){
	listeTirEnn liste_tir_enn = malloc(sizeof(listeTirsEnnemi));
	if (liste_tir_enn == NULL)
	{
		exit(EXIT_FAILURE);
	}
	liste_tir_enn->premier = NULL;
	liste_tir_enn->quantite = 0;
	return liste_tir_enn;
}

tirEnn createTirEnnemi(int ex, int ey, int px, int py){	
	int dx = px - ex;
	int dy = ey - py;
    double ddx = (double)dx;
    double ddy = (double)dy;
	tirEnn nouveau = malloc(sizeof(tirEnnemi));
	if (nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	} 

    double distance = sqrt(ddx * ddx + ddy * ddy);
    
    nouveau->active = true;
    nouveau->pos.x = ex;
    nouveau->pos.y = ey;
    nouveau->direction_x = ddx;
    nouveau->direction_y = ddy;
    nouveau->ratio_hypothenuse = (1 / distance);
    nouveau->hauteur = 5;
    nouveau->largeur = 5;
    nouveau->suivant = NULL;

    /*
    printf("Création du tirEnn, pos joueur x, y : %i, %i\n",px, py); //
    printf("Création du tirEnn, pos ennemi x, y : %i, %i\n",ex, ey); //
    printf("Création du tirEnn, distance calculé par racine carré %f\n", distance); // 
    printf("Création du tirEnn, direction ddx et ddy x, y : %f, %f\n",nouveau->direction_x, nouveau->direction_y); // 
    printf("Création du tirEnn, ratio hypothènuse : %f\n",nouveau->ratio_hypothenuse); // 
    printf("Création du tirEnn, nouvelle pos x, y : %f, %f\n",nouveau->pos.x, nouveau->pos.y); // 
    fflush(stdout);*/
    
    return nouveau;
  }

void insertionTirsEnnemi(listeTirEnn liste_tir_enn, tirEnn nouveau){

    if (liste_tir_enn == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
   
    /* Insertion de l'élément au début de la liste */
   
    if (liste_tir_enn->premier == NULL){
        liste_tir_enn->premier = nouveau;
    }
    else{
        tirEnn temp = liste_tir_enn->premier;
        while (temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }

	liste_tir_enn->quantite += 1;
 //   printf("Ajout tirEnn, nouvelle quantité : %i\n",liste_tir_enn->quantite); // vérification de la quantité d'ennemis dans la chaine
//    fflush(stdout);
  
}


void suppressionTirsEnnemi(listeTirEnn liste_tir_enn){
    bool test = false;
    if (liste_tir_enn->premier != NULL)
    {
        tirEnn tested = liste_tir_enn->premier;
        tirEnn prevTirEn = NULL;
        while (tested != NULL)
        {
            tirEnn TirEn_suivant = tested->suivant; 
            if (tested->active == test)
            {
                if (prevTirEn == NULL)
                {
                    liste_tir_enn->premier = tested->suivant;
                }
                else
                {
                    prevTirEn->suivant = tested->suivant;
                }
              	free(tested);
				liste_tir_enn->quantite--;
             //   printf("Suppression TirEn, nouvelle quantité : %i\n",liste_tir_enn->quantite); // vérification de la quantité d'ennemis dans la chaine
               // fflush(stdout);
            }
            else
            {
                prevTirEn = tested;
            }
            tested = TirEn_suivant;
        }
    }
}





void updateTirsEnnemi(int valeur) {

    if (liste_tir_enn != NULL) {
        tirEnn tir_enn = liste_tir_enn->premier;

        if (tir_enn != NULL) {

            tir_enn->pos.y = tir_enn->pos.y - tir_enn->direction_y * tir_enn->ratio_hypothenuse;
            tir_enn->pos.x = tir_enn->pos.x + tir_enn->direction_x * tir_enn->ratio_hypothenuse;

         //   printf("1. Update du tirEnn, nouvelle pos x, y : %f, %f\n",tir_enn->pos.x, tir_enn->pos.y); // vérification de la quantité d'ennemis dans la chaine
          //  fflush(stdout);
          
            if (tir_enn->pos.y > 120 ) {
                tir_enn->pos.y = 0;
                tir_enn->active = false;
            }
            
            
            while (tir_enn->suivant != NULL) {
                tir_enn = tir_enn->suivant;
                tir_enn->pos.y = tir_enn->pos.y - tir_enn->direction_y * tir_enn->ratio_hypothenuse;
                tir_enn->pos.x = tir_enn->pos.x + tir_enn->direction_x * tir_enn->ratio_hypothenuse;

            //    listeTirEnn listePrint0 = liste_tir_enn;
            //    while (listePrint0->premier != NULL) {
             //       printf("while0 : adresse et pos x et y d'un élément de la liste chainee %p : %f - %f\n", (void*)listePrint0->premier, listePrint0->premier->pos.x, listePrint0->premier->pos.y);
              //      listePrint0->premier = listePrint0->premier->suivant;
             //   }

              //   printf("2. Update du tirEnn, nouvelle pos x, y : %f, %f\n",tir_enn->pos.x, tir_enn->pos.y); // vérification de la quantité d'ennemis dans la chaine
               // fflush(stdout);
                
                
                if (tir_enn->pos.y > 120 ) {
                    tir_enn->pos.y = 0;
                    tir_enn->active = false;
                }
            }
        }
    }

  

    if (enPause == false && gameOver == false) {
        glutTimerFunc(tirsEnnemiSpeed, updateTirsEnnemi, 0);
    }

}


void updateDeleteTirsEnnemi(int valeur)
{
	
    if (liste_tir_enn->premier != NULL)
	{
     //   printf("test réussi  list_tir_enn->premier pour savoir si non null et lancer la suprresion des ennemi\n");
      //  fflush(stdout);
		suppressionTirsEnnemi(liste_tir_enn);
	}
	//glutPostRedisplay();

	if (enPause == false && gameOver == false) 
		glutTimerFunc(updateFrequency, updateDeleteTirsEnnemi, 0);
}





