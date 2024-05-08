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
#include "obstacles.h"
#include "bubbles.h"



time_t start_time;

int time_elapsed = 0;



void startTimer(){
	start_time = time(NULL);

}

void initGameParametres(){
    
		
		p= createPlayer(&mX, &mY);
		e = initialListEnemies();
		t = initialListeTirs();
		liste_obs = initialListObstacles();
		liste_bub = initialListBubbles();
}


void gameTimers(){
	

		// Timers relatifs aux ennemis
		glutTimerFunc(enemySpeed, updateEnemies, 0);
		glutTimerFunc(updateNewEnemy, updateNewEnemies, 0);
		glutTimerFunc(updateFrequency, updateDeleteEnemies, 0);

		// Timers relatifs aux obstacles
		glutTimerFunc(FreqUpdateObstacles, updateObstacles, 0);
		glutTimerFunc(updateFrequency, updateNewObstacles, 0);
		glutTimerFunc(updateFrequency, updateDeleteObstacles, 0);

		// Timers relatifs aux tirs normaux
		glutTimerFunc(tirsSpeed, updateTirs, 0);
		glutTimerFunc(updateFrequency, updateDeleteTirs, 0);

		// Timers relatifs aux tirs normaux
		glutTimerFunc(tirsSpeed, updateBubbles, 0);
		glutTimerFunc(updateFrequency, updateDeleteBubbles, 0);

		// Autres timers
		glutTimerFunc(updateFrequency, updateScrolling, 0);

		// Collisions
			// concernant le joueur : 
				glutTimerFunc(updateFrequency, checkCollisionJoueurVSennemi, 0);
				glutTimerFunc(updateFrequency, checkCollisionJoueurVSobstacle, 0);
				//glutTimerFunc(updateFrequency, checkCollisionJoueurVStirEnnemi, 0);

			// concernant la bubble : 
				glutTimerFunc(updateFrequency, checkCollisionBubbleVSobstacle, 0);
			
			// concernant les tirs : 
				glutTimerFunc(updateFrequency, checkCollisionTirVSobstacle, 0);
				glutTimerFunc(updateFrequency, checkCollisionTirVSennemi, 0);

			// concernant les obstacles et ennemis : 
				glutTimerFunc(updateFrequency, checkCollisionEnnemiVSobstacle, 0);
							

		// ajout pour les touches keystates
		glutTimerFunc(1000, updateFastMov, 0);  // Appel récursif pour mettre à jour à intervalles réguliers

	
}





void reinitializeGame(){
	
	// réinit du joueur
	p->vie = 1000;
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




