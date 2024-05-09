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
#include "fireEnnemi.h"

#include "tirs.h"
#include "drawMap.h"
#include "time.h"
#include "collision.h"
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
		liste_tir_enn = initialListTirsEnnemi();
}


void gameTimers(){
	

		// Timers relatifs aux ennemis
		glutTimerFunc(enemySpeed, updateEnemies, 0);
		glutTimerFunc(updateNewEnemy, updateNewEnemies, 0);
		glutTimerFunc(updateFrequency, updateDeleteEnemies, 0);

		// Timers relatifs aux tirs ennemis
		glutTimerFunc(tirsEnnemiSpeed, updateTirsEnnemi, 0);
		glutTimerFunc(updateFrequency, updateDeleteTirsEnnemi, 0);

		// Timers relatifs aux obstacles
		glutTimerFunc(FreqUpdateObstacles, updateObstacles, 0);
		glutTimerFunc(updateFrequency, updateNewObstacles, 0);
		glutTimerFunc(updateFrequency, updateDeleteObstacles, 0);

		// Timers relatifs aux tirs normaux
		glutTimerFunc(tirsSpeed, updateTirs, 0);
		glutTimerFunc(updateFrequency, updateDeleteTirs, 0);

		// Timers relatifs aux bubbles
		glutTimerFunc(tirsSpeed, updateBubbles, 0);
		glutTimerFunc(updateFrequency, updateDeleteBubbles, 0);

		// Autres timers
		glutTimerFunc(updateFrequency, updateScrolling, 0);

		// Collisions
			// concernant le joueur : 
				glutTimerFunc(updateFrequency, checkCollisionJoueurVSennemi, 0);
				glutTimerFunc(100, checkCollisionJoueurVSobstacle, 0);
				glutTimerFunc(updateFrequency, checkCollisionJoueurVStirEnnemi, 0);


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
	p->vie = 10;
	p->pos.x = 62;
	p->pos.y = 110;
	p->bubbles = 10;

	
	// réinit du score
	score = 0;

	enPause = false;
	gameOver = false;

	if (currentDifficulte != 1 && currentDifficulte != 2 && currentDifficulte != 3 && currentDifficulte != 4 )
		currentDifficulte = 1;


	// reinit du timer
	time_elapsed = 0; 
	startTimer();
	
	



	// réinit des tirs et des ennemis // SYSTEME ABANONNE 
//	reInit = true;
	//gameTimers();


	
/*
	e->starList;
	t = initialListeTirs();
	liste_obs = initialListObstacles();
	liste_bub = initialListBubbles();
	liste_tir_enn = initialListTirsEnnemi();
*/

if (e->starList != NULL) {
    enemy asupprimer = e->starList;
    while (asupprimer != NULL) {
        enemy next = asupprimer->nextptr;
        free(asupprimer);
        asupprimer = next;
    }
    e->starList = NULL;
}
e = initialListEnemies();


if (t->starList != NULL) {
    tirsP asupprimer = t->starList;
    while (asupprimer != NULL) {
        tirsP next = asupprimer->nextptr;
        free(asupprimer);
        asupprimer = next;
    }
    t->starList = NULL;
}
t = initialListeTirs();


if (liste_obs->premier != NULL) {
    obstacle asupprimer = liste_obs->premier;
    while (asupprimer != NULL) {
        obstacle next = asupprimer->suivant;
        free(asupprimer);
        asupprimer = next;
    }
    liste_obs->premier = NULL;
}
		liste_obs = initialListObstacles();


		if (liste_bub->premier != NULL) {
    bubble asupprimer = liste_bub->premier;
    while (asupprimer != NULL) {
        bubble next = asupprimer->suivant;
        free(asupprimer);
        asupprimer = next;
    }
    liste_bub->premier = NULL;
}
		liste_bub = initialListBubbles();


		if (liste_tir_enn->premier != NULL) {
    tirEnn asupprimer = liste_tir_enn->premier;
    while (asupprimer != NULL) {
        tirEnn next = asupprimer->suivant;
        free(asupprimer);
        asupprimer = next;
    }
    liste_tir_enn->premier = NULL;
}
		liste_tir_enn = initialListTirsEnnemi();
/*

		if (liste_bub->premier !=NULL){
			obstacle asupprimer = liste_bub->premier;
			obstacle next = asupprimer->suivant;
			while (asupprimer != NULL){
				asupprimer = liste_bub->premier->suivant;
				free(asupprimer); 
				asupprimer = next;
			}
			liste_bub->premier = NULL;
		}
		//liste_bub = initialListBubbles();


		if (liste_tir_enn->premier !=NULL){
			obstacle asupprimer = liste_tir_enn->premier;
			obstacle next = asupprimer->suivant;
			while (asupprimer != NULL){
				asupprimer = liste_tir_enn->premier->suivant;
				free(asupprimer); 
				asupprimer = next;
			}
			liste_tir_enn->premier = NULL;
		}
		//liste_tir_enn = initialListTirsEnnemi();
		*/


	

}


