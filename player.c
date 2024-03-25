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

player createPlayer(int mX, int mY)
{
	player p;

	int x = 0, y = 0;

	for (int i = 0; i < mX; ++i)
	{
		for (int j = 0; j < mY; ++j)
		{
//			if(*(*(map + i) + j) == 'X')
			if(map[i][j] == 'X')

			{
				x = i;
				y = j;
			}
		}
	}

	p = malloc(sizeof(player));
	p->vie = 3;
	p->pos.x = x;
	p->pos.y = y;
	p->facing.faceUp=true;

	return p;
}

void moveLeft(player p)		//la fonction va vérifier si on peut se déplacer vers la gauche et le faire le cas échéant
{
	int x = 0, y = 0;

	x = p->pos.x-1;
	y = p->pos.y;

	p->facing.faceLeft = true;
	p->facing.faceRight = false;
	p->facing.faceUp = false;
	p->facing.faceDown = false;
	

//	if (*(*(map + x) + y)!='i')
	if (map[x][y]!='i')

	{
		p->pos.x = x;
	}

}

void moveRight(player p)		//la fonction va vérifier si on peut se déplacer vers la droite et le faire le cas échéant
{
	int x = 0, y = 0;


	x = p->pos.x+1;
	y = p->pos.y;

	p->facing.faceLeft = false;
	p->facing.faceRight = true;
	p->facing.faceUp = false;
	p->facing.faceDown = false;

	if (map[x][y]!='i')
	{
		p->pos.x = x;
	}

}



void moveUp(player p)
{
	int  x = 0, y = 0;
      
	x = p->pos.x;
	y = p->pos.y-1;

	p->facing.faceLeft = false;
	p->facing.faceRight = false;
	p->facing.faceUp = true;
	p->facing.faceDown = false;

	if (map[x][y]!='i')
 	{
		p->pos.y = y;
  	}     

}

void moveDown(player p)
{
	int  x = 0, y = 0;
	
	x = p->pos.x;
	y = p->pos.y+1;

	p->facing.faceLeft = false;
	p->facing.faceRight = false;
	p->facing.faceUp = false;
	p->facing.faceDown = true;

	if (map[x][y]!='i')
	{
		p->pos.y = y;
	}
}
