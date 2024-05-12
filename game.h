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
extern bool reInit;
//extern bool hasReInit;
//extern int start_pause_time;
//extern int end_pause_time;




void Keyboard(unsigned char key, int x, int y);
void game(int *maxX, int *maxY, float scrolling_value, player p, listeEn e, listetirsP  t); 


//test keystate - ne fonciotnne pas pour le moment
void specialKeys(int key, int x, int y);
void updateFastMov(int value);
void keyboardDown(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);

#endif
