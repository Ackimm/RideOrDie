#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "player.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
player p;

player createPlayer(int *maxX, int *maxY)
{
	
//	player p;

//	int x = 0, y = 0;
//
//	for (int i = 0; i < *maxX; ++i)
//	{
//		for (int j = 0; j < *maxY; ++j)
//		{
//			if(*(*(map + i) + j) == 'X')
//			{
//				x = i;
//				y = j;
//			}
//		}
//	}
player p = malloc(sizeof(player));

	p->vie = 1000;
//	p->pos.x = x;
//	p->pos.y = y;
	p->pos.x = 1;
	p->pos.y = 1;

	p->largeur = 4;
	p->hauteur = 12;
	p->bubbles = 666;
	return p;
}


void moveLeft(player p)		
{
	int x = 0, y = 0;

	x = p->pos.x-1;
	y = p->pos.y;
     
	if (*(*(map + y) + x)!='g') // toujours la même chose ici, c'est (*(*(map + y) + x) renvoie au pointeur de l'élément map[y][x] et non map[x]][y]
	{
		p->pos.x = x;
	}

}

void moveRight(player p)		
{
	int x = 0, y = 0;
	
	x = p->pos.x+1;
	y = p->pos.y;

   	if (*(*(map + y) + x)!='d' ) // toujours la même chose ici, c'est (*(*(map + y) + x) renvoie au pointeur de l'élément map[y][x] et non map[x]][y]
	{
		p->pos.x = x;
	}
	
}



void moveUp(player p)
{
 int  x = 0, y = 0;
      
x = p->pos.x;
y = p->pos.y-1;


if (*(*(map + y) + x)!='!') // toujours la même chose ici, c'est (*(*(map + y) + x) renvoie au pointeur de l'élément map[y][x] et non map[x]][y]
{
	p->pos.y = y;
}     

}

void moveDown(player p)
{
 int  x = 0, y = 0;

   x = p->pos.x;
   y = p->pos.y+1;
  
   
if (*(*(map + y) + x)!='!') // toujours la même chose ici, c'est (*(*(map + y) + x) renvoie au pointeur de l'élément map[y][x] et non map[x]][y]
{
	p->pos.y = y;
}
}
