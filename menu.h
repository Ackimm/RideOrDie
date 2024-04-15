#ifndef _MENU_H_
#define _MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "loadMap.h"
#include "drawMap.h"


enum{
    menu_0,
    menu_1,
    menu_2,
    menu_3,
    menu_4
};

void drawMenu();
void mouseClick(int button, int state, int x, int y);

#endif
