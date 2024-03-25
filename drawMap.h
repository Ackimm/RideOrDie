#ifndef _DRAWMAP_H_
#define _DRAWMAP_H_

#include "loadMap.h"
#include "player.h"
#include "enemies.h"

extern player p;
extern int mX;
extern int mY;
extern enemy q;
extern listeEn e;

// void drawWall(char map[mX][mY]);
void drawWall(int mX, int mY); //sub for trying
void drawPlayer(player p);
void drawEnemy(enemy e);
void drawAllEnnemis(listeEn e);


#endif
