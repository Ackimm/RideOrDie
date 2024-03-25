#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"


int mX = MaxX;
int mY = MaxY;

bool loadMap(char map[MaxX][MaxY])		//fonction qui ouvre le fichier txt et charge la carte dans le tableau
{
    FILE *f = NULL;
//  f = fopen("map120x140.txt", "r");
    f = fopen("map124x124.txt", "r");

    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    char c;
	int i,j;
	
	for(i = 0; i < MaxX; i++)
		{
			for(j = 0; j < MaxY; j++)
			{		
				c = fgetc(f);
				map[i][j] = c;
			}
			fgetc(f);
		}

	    fclose(f);
		
	    printf("\n");

		for(i = 0; i < MaxX; i++)
		{
			for(j = 0; j < MaxY; j++)
			{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
				
		
 return true;
 }		

