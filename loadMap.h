#ifndef _LOADMAP_H_
#define _LOADMAP_H_

#include <stdbool.h>

// en vrai 124*125 pour le fichier 120*140 horizontal (à creuse...)
// en vrai 124*126 pour le fichier 124*124 réseau de routes (à creuse...)

#define MaxX 124 // 124 ici c'est x-2 mais ça marche
#define MaxY 125 // 126 nécessaire de mettre à +2 pour éviter le bug graphique de la diagonale

// #define MaxX 118 // x-2 
// #define MaxY 100 // y+2

#define Square_size 10.0




bool loadMap(char map[MaxX][MaxY]);

#endif
