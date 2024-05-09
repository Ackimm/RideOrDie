#ifndef _GAMEINITANDTIMERS_H_
#define _GAMEINITANDTIMERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "time.h"



extern time_t start_time;

extern int time_elapsed;

void initGameParametres();
void gameTimers();
void startTimer();
void reinitializeGame();



#endif
