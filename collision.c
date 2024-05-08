#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "enemies.h"
#include "tirs.h"
#include "player.h"
#include "obstacles.h"

#include "bubbles.h"

#include "constantes.h"
#include "drawMap.h"
#include "game.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int score = 0;


void checkCollisionTirVSennemi(int valeur) {
    tirsP currentTir = t->starList;
    enemy currentEnemy = e->starList;

    // entre tir joueur et ennemi

    if (e->starList != NULL && t->starList != NULL) {
     
        while (currentEnemy != NULL) {
                   
            while (currentTir != NULL) {

                int distanceX = abs(currentTir->pos.x - currentEnemy->pos.x);
                int distanceY = abs(currentTir->pos.y - currentEnemy->pos.y);

                if ((distanceY <= ((currentTir->hauteur / 2) + (currentEnemy->hauteur / 2))) &&
                    (distanceX <= ((currentTir->largeur / 2) + (currentEnemy->largeur / 2)))) 
                {

                        currentEnemy->vie--;
                        if (currentEnemy->vie == 0){
                            score++;
                        }   

                        currentTir->pos.y = 0;
                    }

                    currentTir = currentTir->nextptr;
            }

            currentTir = t->starList; 
            currentEnemy = currentEnemy->nextptr;
        }

        currentEnemy = e->starList; 
    }

    if (enPause == false && gameOver == false) 
        glutTimerFunc(updateFrequency, checkCollisionTirVSennemi, 0);
        
}

void checkCollisionJoueurVSennemi(int valeur) {
  
// Entre ennemi et joueur
    enemy currentEnemy = e->starList;

    while (currentEnemy != NULL) {
           
                



                int distanceX = abs(p->pos.x - currentEnemy->pos.x);
                int distanceY = abs(p->pos.y - currentEnemy->pos.y);

                if ((distanceY <= ((p->hauteur / 2) + (currentEnemy->hauteur / 2))) &&
                    (distanceX <= ((p->largeur / 2) + (currentEnemy->largeur / 2))))  {


                    p->vie--;
                    currentEnemy->vie--;
                    if (p->vie == 0){
                        gameOver = true;
                        displayGameOver();
                    }
                }
            

            currentEnemy = currentEnemy->nextptr;
    }

	if (enPause == false && gameOver == false) 
        glutTimerFunc(updateFrequency, checkCollisionJoueurVSennemi, 0);
        
}


void checkCollisionJoueurVSobstacle(int valeur) {
  

    obstacle currentObstacle = liste_obs->premier;

    while (currentObstacle != NULL) {
           
                  int distanceX = abs(p->pos.x - currentObstacle->pos.x);
                int distanceY = abs(p->pos.y - currentObstacle->pos.y);

                if ((distanceY <= ((p->hauteur / 2) + (currentObstacle->hauteur / 2))) &&
                    (distanceX <= ((p->largeur / 2) + (currentObstacle->largeur / 2))))  {
                
                    p->vie--;
                    currentObstacle->vie--;
                    if (p->vie == 0){
                        gameOver = true;
                        displayGameOver();
                    }
                }
            

            currentObstacle = currentObstacle->suivant;
    }

	if (enPause == false && gameOver == false) 
        glutTimerFunc(updateFrequency, checkCollisionJoueurVSobstacle, 0);
        
}



void checkCollisionEnnemiVSobstacle(int valeur) {
  
    // cette vérification faisait tout foirer..
  //  if (e->starList == NULL || liste_obs->premier == NULL) {
   //     return;
   // } 

    enemy currentEnemy = e->starList;

    while (currentEnemy != NULL) {
        obstacle currentObstacle = liste_obs->premier;

        while (currentObstacle != NULL) {

            int distanceX = abs(currentObstacle->pos.x - currentEnemy->pos.x);
            int distanceY = abs(currentObstacle->pos.y - currentEnemy->pos.y);

            if ((distanceY <= ((currentObstacle->hauteur / 2) + (currentEnemy->hauteur / 2))) &&
                (distanceX <= ((currentObstacle->largeur / 2) + (currentEnemy->largeur / 2)))) 
                {
                currentEnemy->vie--;
                currentObstacle->vie--;
            }

            currentObstacle = currentObstacle->suivant;
        }

        currentEnemy = currentEnemy->nextptr;
    }

    if (!enPause && !gameOver) {
        glutTimerFunc(updateFrequency, checkCollisionEnnemiVSobstacle, 0);
    }
}


void checkCollisionTirVSobstacle(int valeur) {
    tirsP currentTir = t->starList;
    obstacle currentObstacle = liste_obs->premier;


    if (liste_obs->premier != NULL && t->starList != NULL) {
     
        while (currentObstacle != NULL) {

            if (currentObstacle->bubbled == true){

                while (currentTir != NULL) {

                int distanceX = abs(currentTir->pos.x - currentObstacle->pos.x);
                int distanceY = abs(currentTir->pos.y - currentObstacle->pos.y);

                if ((distanceY <= ((currentTir->hauteur / 2) + (currentObstacle->hauteur / 2))) &&
                    (distanceX <= ((currentTir->largeur / 2) + (currentObstacle->largeur / 2)))) 
                {

                        currentObstacle->vie--;
                        currentTir->pos.y = 0;

                    }

                    currentTir = currentTir->nextptr;
                }

            }
                
            currentTir = t->starList; 
            currentObstacle = currentObstacle->suivant;
        }

        currentObstacle = liste_obs->premier; 
    }

    if (enPause == false && gameOver == false) 
        glutTimerFunc(updateFrequency, checkCollisionTirVSobstacle, 0);
        
}


void checkCollisionBubbleVSobstacle(int valeur) {
    bubble currentBubble = liste_bub->premier;
    obstacle currentObstacle = liste_obs->premier;


    if (liste_obs->premier != NULL && liste_bub->premier != NULL) {
     
        while (currentObstacle != NULL) {

        
                while (currentBubble != NULL) {

                int distanceX = abs(currentBubble->pos.x - currentObstacle->pos.x);
                int distanceY = abs(currentBubble->pos.y - currentObstacle->pos.y);

                if ((distanceY <= ((currentBubble->hauteur / 2) + (currentObstacle->hauteur / 2))) &&
                    (distanceX <= ((currentBubble->largeur / 2) + (currentObstacle->largeur / 2)))) 
                {

                        currentObstacle->bubbled = true;
                        currentBubble->pos.y = 0;

                    }

                    currentBubble = currentBubble->suivant;
                }
                
            currentBubble = liste_bub->premier; 
            currentObstacle = currentObstacle->suivant;
        }

        currentObstacle = liste_obs->premier; 
    }

    if (enPause == false && gameOver == false) 
        glutTimerFunc(updateFrequency, checkCollisionBubbleVSobstacle, 0);
        
}
