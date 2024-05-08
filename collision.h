#ifndef _COLLISION_H_
#define _COLLISION_H_

#include <stdlib.h>
#include <stdbool.h>

#include "player.h"
#include "enemies.h"
#include "tirs.h"
#include "constantes.h"

extern int score;

void checkCollisionJoueurVSennemi(int valeur);
void checkCollisionJoueurVSobstacle(int valeur);
//void checkCollisionJoueurVStirEnnemi(int valeur);

void checkCollisionEnnemiVSobstacle(int valeur);


void checkCollisionBubbleVSobstacle(int valeur);

void checkCollisionTirVSennemi(int valeur);
void checkCollisionTirVSobstacle(int valeur);

#endif

