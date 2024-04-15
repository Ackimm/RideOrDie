#ifndef _LOADMAP_H_
#define _LOADMAP_H_



#include <stdbool.h>




extern char **map;

extern int mX;
extern int mY;

bool loadMap(int *maxX, int *maxY);

#endif
