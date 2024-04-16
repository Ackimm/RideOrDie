#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constantes.h"


// #include "loadMap.h"

char **map;
int mX;
int mY;
bool loadMap(int *maxX, int *maxY)		//fonction qui ouvre le fichier txt et charge la carte dans le tableau
{
    map = malloc(sizeof(char *) * (*maxY));	
  
    	
    FILE *f = NULL;
    // f = fopen("map1.txt", "r");
	// f = fopen("map124x124.txt", "r");
	f = fopen("map120x140.txt", "r");
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    char c;
    int i= 0;
    int j= 0;
    
/*------------------------
*(*(map + i) + j) représente la valeur du caractère à la position (i, j) du tableau à 2 dimensions 
en sachant que la position (i, j) est la position (y, x) et non (x, y)
------------------------*/
	
	
	for(i = 0; i < (*maxY); i++)
	{
	*(map + i) = malloc(sizeof(char *) * (*maxX));	
			for(j = 0; j < (*maxX); j++)
			{		
				c = fgetc(f);
				*(*(map + i) + j) = c;
			}
			fgetc(f);
	}

	    fclose(f);

	printf("\n");
    for (i = 0; i < (*maxY); i++) {
        for (j = 0; j < (*maxX); j++) {
            printf("%c", *(*(map + i) + j));
        }
        printf("\n");
    }
				
		
 return true;
 }		

