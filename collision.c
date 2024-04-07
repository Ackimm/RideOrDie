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
                if (currentTir->pos.y == currentEnemy->pos.y + 2 * Square_size  && 
                    (currentTir->pos.x >= currentEnemy->pos.x - 2 * Square_size || currentTir->pos.x <= currentEnemy->pos.x + 2 * Square_size)) {
                    currentEnemy->vie--;
                    printf("Ennemi touché. Vie de l'ennemi : %i\n", currentEnemy->vie); 
                    fflush(stdout);

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
        while (currentEnemy != NULL) {
            if (p->pos.y == currentEnemy->pos.y + 2 * Square_size && 
                (p->pos.x -2.5 * alternate_player_size >= currentEnemy->pos.x - 2 * Square_size || p->pos.x + 3.5 * alternate_player_size  <= currentEnemy->pos.x + 2 * Square_size )) {
            
                p->vie--;
                printf("Vie du joueur : %i\n", p->vie); 
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

