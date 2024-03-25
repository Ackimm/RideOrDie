#ifndef _DRAWMAP_H_
#define _DRAWMAP_H_

#include "loadMap.h"
#include "player.h"

extern player p;
extern int mX;
extern int mY;

// void drawWall(char map[mX][mY]);
void drawWall(int mX, int mY); //sub for trying
void drawPlayer(player p);

#endif
