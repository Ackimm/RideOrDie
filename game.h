#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>




extern int mX;
extern int mY;
// extern char map[mX][mY];


extern player p;
void Keyboard(unsigned char key, int x, int y);
void game(int mX, int mY, player p);


#endif
