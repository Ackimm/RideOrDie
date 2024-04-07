#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "enemies.h"
#include "tirs.h"
#include "player.h"
#include "constantes.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>



// void checkCollision(listeEn e, listetirsP t, player p) { // save

void checkCollision(int valeur) {
    tirsP currentTir = t->starList;
    enemy currentEnemy = e->starList;
    
    // player p;

/*
    if (currentEnemy == NULL || currentTir == NULL || p == NULL) {
        printf("currentEnemy == NULL || currentTir == NULL || p == NULL"); 
        fflush(stdout);
        return;
    }
*/


    if (e->starList != NULL && t->starList != NULL)
	{
        printf("debut du premier if\n"); 
        fflush(stdout);
        while (currentTir != NULL) {
            while (currentEnemy != NULL) {
                printf("rentré dans le double while\n"); 
                fflush(stdout);
                //if (currentTir->pos.y == currentEnemy->pos.y + 2 * Square_size  && 
                  //  (currentTir->pos.x >= currentEnemy->pos.x - 2 * Square_size || currentTir->pos.x <= currentEnemy->pos.x + 2 * Square_size)) {
                    //currentEnemy->vie--;


                
                if (currentTir->pos.y == currentEnemy->pos.y + 2  && 
                    (currentTir->pos.x >= currentEnemy->pos.x - 2  && 
                    currentTir->pos.x <= currentEnemy->pos.x + 2 )) {

                    currentEnemy->vie--;    
                    printf("Ennemi touché. Position X de l'ennemi : %i\n", currentEnemy->pos.x); 
                    printf("Ennemi touché. Position X du tir : %i\n", currentTir->pos.x); 
                    printf("Ennemi touché. Position Y de l'ennemi : %i\n", currentEnemy->pos.y); 
                    printf("Ennemi touché. Position Y du tir : %i\n", currentTir->pos.y); 
                    printf("Ennemi touché. Vie de l'ennemi : %i\n", currentEnemy->vie); 
                    fflush(stdout);
                    currentTir->pos.y = 0;
                    printf("Ennemi touché. Nouvelle position Y du tir : %i\n", currentTir->pos.y); 


                }
                printf("Ennemi SUIVANT\n"); 
                fflush(stdout);
                currentEnemy = currentEnemy->nextptr;
            }
            
            printf("TIR SUIVANT\n"); 
            fflush(stdout);
            currentTir = currentTir->nextptr;
        }

        currentEnemy = e->starList; 
    }

    if (e->starList != NULL)
	{
        printf("Démarrage de la 2ieme if\n");              
        fflush(stdout);
        while (currentEnemy != NULL) {
            printf("Boucle While 2 et lancement de la détection de la collision entre joueur et ennemi \n");              
            fflush(stdout);

            //if (p->pos.y == currentEnemy->pos.y + 2 * Square_size && 
              //  (p->pos.x -2.5 * alternate_player_size >= currentEnemy->pos.x - 2 * Square_size && 
               // p->pos.x + 3.5 * alternate_player_size  <= currentEnemy->pos.x + 2 * Square_size )) {
            
                printf("--------------\n"); 
                printf("Recherche position joueur et ennemi. Position X de l'ennemi : %i\n", currentEnemy->pos.x); 
                printf("Recherche position joueur et ennemi. Position X du joueur : %i\n", p->pos.x); 
                printf("Recherche position joueur et ennemi. Position Y de l'ennemi : %i\n", currentEnemy->pos.y); 
                printf("Recherche position joueur et ennemi. Position Y du joueur : %i\n", p->pos.y); 
                printf("Recherche position joueur et ennemi. Vie du joueur : %i\n", p->vie);    

            if (
                //p->pos.y  == currentEnemy->pos.y  
                
                (
                ((p->pos.y   >= currentEnemy->pos.y - 2)  && (p->pos.y   <= currentEnemy->pos.y + 2 )) 
                || 
                ((p->pos.y >= currentEnemy->pos.y - 2)  && (p->pos.y  <= currentEnemy->pos.y + 2 )) 
               )

                &&             
               (
                ((p->pos.x -2.5  >= currentEnemy->pos.x - 2)  && (p->pos.x -2.5  <= currentEnemy->pos.x + 2 )) 
                || 
                ((p->pos.x +2.5  >= currentEnemy->pos.x - 2)  && (p->pos.x +2.5  <= currentEnemy->pos.x + 2 )) 
               )
               )

               
                {        

              // formule à retravailler. Fonctionne apparemment que lorsque c'est le dernier ennemi qui est visible à l'écran (et encore que peut-être pas dans tous les cas)   

                p->vie--;
                printf("--------------\n"); 
                printf("Joueur touché. Position X de l'ennemi : %i\n", currentEnemy->pos.x); 
                printf("Joueur touché. Position X du joueur : %i\n", p->pos.x); 
                printf("Joueur touché. Position Y de l'ennemi : %i\n", currentEnemy->pos.y); 
                printf("Joueur touché. Position Y du joueur : %i\n", p->pos.y); 
                printf("Joueur touché. Vie du joueur : %i\n", p->vie);              

                fflush(stdout);

                currentEnemy->vie--;
            }
            currentEnemy = currentEnemy->nextptr;
        }


    }

        

   // glutPostRedisplay();    // utile ?  
    printf("NOUVELLE INSTANCE DE LA FONCTION\n"); 
    fflush(stdout);
    glutTimerFunc(updateFrequency, checkCollision, 0);
}

