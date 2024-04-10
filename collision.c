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

int score = 0;


void checkCollision(int valeur) {
    tirsP currentTir = t->starList;
    enemy currentEnemy = e->starList;

    if (e->starList != NULL && t->starList != NULL) {
     
        while (currentEnemy != NULL) {
                   
            while (currentTir != NULL) {
                          
                int distanceX = abs(currentTir->pos.x - currentEnemy->pos.x);
                int distanceY = abs(currentTir->pos.y - currentEnemy->pos.y);

                if (distanceY <= 2 && distanceX <= 2) {

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

    while (currentEnemy != NULL) {
           
                int distanceX = abs(p->pos.x - currentEnemy->pos.x);
                int distanceY = abs(p->pos.y - currentEnemy->pos.y);

                if (distanceY <= 3 && distanceX <= 3) {
                
                    p->vie--;
                    currentEnemy->vie--;
                }
            

            currentEnemy = currentEnemy->nextptr;
    }


    glutTimerFunc(updateFrequency, checkCollision, 0);
}

