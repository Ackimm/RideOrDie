#ifndef _OBSTACLES_H_
#define _OBSTACLES_H_


#include <stdlib.h>
#include <stdbool.h>


struct positionO
{
	int x;
	int y;
};

struct obstacles
{
	int vie;
	struct positionO pos;
	bool active;
	bool bubbled;
	int hauteur;
	int largeur;
	struct obstacles *suivant;
};
typedef struct obstacles obstacles;

struct listeObstacles
{
	
	int quantite;
	struct obstacles *premier;
	
};
typedef struct listeObstacles listeObstacles;


typedef struct obstacles *obstacle; 
typedef struct listeObstacles *listeObs;


listeObs initialListObstacles();
obstacle createObstacle();

void insertionObstacles(listeObs liste_obs, obstacle obs);
void suppressionObstacles(listeObs liste_obs);

extern obstacle obs; 
extern listeObs liste_obs; 
extern bool FinishedInitObstacles;

void updateObstacles(int valeur);
void updateNewObstacles(int valeur);
void updateDeleteObstacles(int valeur);


#endif
