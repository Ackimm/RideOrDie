#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "loadMap.h"
#include "game.h"
#include "player.h"
#include "enemies.h"
#include "loadMap.h"

#include "tirs.h"
#include "drawMap.h"
#include "time.h"
#include "collision.h"
#include "game.h"




time_t start_time;

int time_elapsed = 0;



void startTimer(){
	start_time = time(NULL);

}

void initGameParametres(){
    
		

		p= createPlayer(&mX, &mY);
		e = initialListEnemies();
		t = initialListeTirs();
}


void gameTimers(){
	


		glutTimerFunc(updateFrequency, updateEnemies, 0);
		glutTimerFunc(updateFrequency, updateNewEnemies, 0);
		glutTimerFunc(updateFrequency, updateDeleteEnemies, 0);
		glutTimerFunc(updateFrequency, updateTirs, 0);
		glutTimerFunc(updateFrequency, updateDeleteTirs, 0);
		glutTimerFunc(updateFrequency, updateScrolling, 0);
		glutTimerFunc(updateFrequency, checkCollision, 0); 
	
}





void reinitializeGame(){
	
	// réinit du joueur
	p->vie = 1;
	p->pos.x = 62;
	p->pos.y = 62 ;
	p->bubbles = 5;

	
	// réinit du score
	score = 0;

	// reinit du timer
	time_elapsed = 0; 



	// réinit des tirs et des ennemis
	reInit = true;



}




