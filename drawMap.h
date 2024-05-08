#ifndef _DRAWMAP_H_
#define _DRAWMAP_H_

#include "loadMap.h"
#include "player.h"
#include "enemies.h"
#include "tirs.h"
#include "obstacles.h"
#include "bubbles.h"


extern float scrolling_value;



void drawWall(int *maxX, int *maxY, float scrolling_value);

void updateScrolling();


void drawPlayer(player p);

void drawEnemy(enemy e);
void drawAllEnnemis(listeEn e);	

void drawTirs(tirsP p);
void drawAllTirs(listetirsP t);

void drawObstacle(obstacle obs);
void drawAllObstacles(listeObs liste_obs);	

void drawBubble(bubble bub);
void drawAllBubbles(listeBub liste_bub);	


void displayHUD();
void displayGameOver();

void displayPauseButtons();






#endif
