#ifndef _BUBBLES_H_
#define _BUBBLES_H_


#include <stdlib.h>
#include <stdbool.h>

#include "player.h"

struct positionB
{
	int x;
	int y;
};

struct bubbles
{
	bool active;
	struct positionB pos;
	int hauteur;
	int largeur;
	struct bubbles *suivant;
};
typedef struct bubbles bubbles;

struct listeBubbles
{
	
	int quantite;
	struct bubbles *premier;
	
};
typedef struct listeBubbles listeBubbles;


typedef struct bubbles *bubble; 
typedef struct listeBubbles *listeBub;

listeBub initialListBubbles();
bubble createBubble();
void shootBubble(player p);

void insertionBubbles(listeBub liste_bub, bubble bub);
void suppressionBubbles(listeBub liste_bub);

extern bubble bub; 
extern listeBub liste_bub; 


void updateBubbles(int valeur);
void updateDeleteBubbles(int valeur);


#endif
