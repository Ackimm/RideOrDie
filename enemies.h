#ifndef _ENEMIES_H_
#define _ENEMIES_H_


#include <stdlib.h>
#include <stdbool.h>


typedef enum {
    black = 1,
    blue = 2,
    green = 3,
    red = 4,
	yellow = 5,
    
} couleurV;

struct positionE
{
	int x;
	int y;
};

struct enemies
{
	int vie;
	struct positionE pos;
	bool active;
	int speed; // inutile pour le moment
	int hauteur;
	int largeur;
	couleurV couleur;
	struct enemies *prevptr;
	struct enemies *nextptr;
};
typedef struct enemies enemies;

struct listeEnemies
{
	
	int quantite;
	struct enemies *starList;
	struct enemies *endList;
	
};
typedef struct listeEnemies listeEnemies;


typedef struct enemies *enemy; 
typedef struct listeEnemies *listeEn;

enemy createEnemy();
listeEn  initialListEnemies();
void insertionEnemies(listeEn e, enemy q);
void suppressionEnemies(listeEn e, bool test);
extern enemy q; // pour que d'autres fichiers puissent l'utiliser
extern listeEn e; // pour que d'autres fichiers puissent l'utiliser

extern bool FinishedInitEnnemis;

void updateEnemies(int valeur);
void updateNewEnemies(int valeur);
void updateDeleteEnemies(int valeur);


#endif
