#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "enemies.h"
#include "tirs.h"


extern bool test;

void Keyboard(unsigned char key, int x, int y);
void game(int *maxX, int *maxY, player p, listeEn e, listetirsP  t);


#endif
