#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "enemies.h"
#include "tirs.h"
#include "menu.h"



extern bool test;
extern bool enPause;
extern bool gameOver;
extern int start_pause_time;
extern int end_pause_time;



void Keyboard(unsigned char key, int x, int y);
void game(int *maxX, int *maxY, float scrolling_value, player p, listeEn e, listetirsP  t); 




#endif
