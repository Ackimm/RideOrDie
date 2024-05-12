#ifndef _TIRENNEMI_H_
#define _TIRENNEMI_H_


#include <stdlib.h>
#include <stdbool.h>



struct positionTE
{
	double x;
	double y;
};

struct tirEnnemi
{
	bool active;
	struct positionTE pos;
	int hauteur;
	int largeur;
	double direction_x;
	double direction_y;
	double ratio_hypothenuse;
	struct tirEnnemi *suivant;
};
typedef struct tirEnnemi tirEnnemi;

struct listeTirsEnnemi
{
	
	int quantite;
	struct tirEnnemi *premier;
	
};
typedef struct listeTirsEnnemi listeTirsEnnemi;


typedef struct tirEnnemi *tirEnn; 
typedef struct listeTirsEnnemi *listeTirEnn;

listeTirEnn initialListTirsEnnemi();
tirEnn createTirEnnemi(int ex, int ey, int px, int py);

void insertionTirsEnnemi(listeTirEnn liste_tir_enn, tirEnn tir_enn);
void suppressionTirsEnnemi(listeTirEnn liste_tir_enn);

extern tirEnn tir_enn; 
extern listeTirEnn liste_tir_enn; 
extern bool FinishedInitTirsEnnemi;

void updateTirsEnnemi(int valeur);
void updateDeleteTirsEnnemi(int valeur);


#endif
