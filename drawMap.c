#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


#include "drawMap.h"
#include "game.h"
#include "collision.h"
#include "gameInitAndTimers.h"


#include "constantes.h"
#include "velo_jaune4.c"

#include "obstacles.h"
#include "bubbles.h"
#include "fireEnnemi.h"


#include "textures.h"



float scrolling_value = 0.0;

/*------------------------

*(*(map + i) + j) représente la valeur du caractère à la position (i, j) du tableau à 2 dimensions 
en sachant que la position (i, j) est la position (y, x) et non (x, y)

------------------------*/


void drawWall(int *maxX, int *maxY, float scrolling_value){			// fonction qui affiche les murs et les plateformes	

	for (int i = 0; i < (*maxY); i++)
	{
		for (int j = 0; j < (*maxX); j++)
		{
			if(*(*(map + i) + j) == '!')
			{
                glColor3f(1.0f,1.0f,1.0f);
				glMatrixMode(GL_MODELVIEW);
				
			    glLoadIdentity();
				glTranslatef(j*Square_size,i*Square_size,0.0f); // ici j et i sont inversés, il faudra encore un peu creuser pour comprendre pourquoi ça marche mieux ainsi
				
				
				glBegin(GL_QUADS);
					glVertex3f(0.0f, 0.0f, 0.0f);
					glVertex3f(Square_size, 0.0f, 0.0f);
					glVertex3f(Square_size,Square_size, 0.0f);
					glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();	
			}
			

			if(*(*(map + i) + j) == 'b'){

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(j*Square_size,i*Square_size+scrolling_value,0.0f);
			
			glBindTexture(GL_TEXTURE_2D, texture_route_bande_centrale); 
				
			
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
			glDisable( GL_BLEND );// rajout pour tester la transparence
			glEnable(GL_TEXTURE_2D); // aj

			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex2f(Square_size, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex2f(Square_size, Square_size);
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, Square_size);
			glEnd();


			glDisable(GL_TEXTURE_2D); // add
			}



			if(*(*(map + i) + j) == 'r'){

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(j*Square_size,i*Square_size+scrolling_value,0.0f);
			
			glBindTexture(GL_TEXTURE_2D, texture_route_dirt); 
				
			
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
			glDisable( GL_BLEND );// rajout pour tester la transparence
			glEnable(GL_TEXTURE_2D); // aj

			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex2f(Square_size, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex2f(Square_size, Square_size);
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, Square_size);
			glEnd();


			glDisable(GL_TEXTURE_2D); // add
			}






			if(*(*(map + i) + j) == 'h'){

			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(j*Square_size,i*Square_size+scrolling_value,0.0f);
			

					glBindTexture(GL_TEXTURE_2D, texture_herbe_1); 
				
			
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
			glDisable( GL_BLEND );// rajout pour tester la transparence
			glEnable(GL_TEXTURE_2D); // aj

			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex2f(Square_size, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex2f(Square_size, Square_size);
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, Square_size);
			glEnd();


			glDisable(GL_TEXTURE_2D); // add
			
			}


			if(*(*(map + i) + j) == 'g'){

			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(j*Square_size,i*Square_size+scrolling_value,0.0f);
			

					glBindTexture(GL_TEXTURE_2D, texture_bord_route_gauche); 
				
			
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
			glDisable( GL_BLEND );// rajout pour tester la transparence
			glEnable(GL_TEXTURE_2D); // aj

			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex2f(Square_size, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex2f(Square_size, Square_size);
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, Square_size);
			glEnd();


			glDisable(GL_TEXTURE_2D); // add

 			}


			if(*(*(map + i) + j) == 'd'){

			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(j*Square_size,i*Square_size+scrolling_value,0.0f);
			

					glBindTexture(GL_TEXTURE_2D, texture_bord_route_droite); 
				
			
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
			glDisable( GL_BLEND );// rajout pour tester la transparence
			glEnable(GL_TEXTURE_2D); // aj

			glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex2f(Square_size, 0.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex2f(Square_size, Square_size);
				glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, Square_size);
			glEnd();


			glDisable(GL_TEXTURE_2D); // add
			}
		}
	}
}	

void updateScrolling(){
	scrolling_value += 5.15;
	if (scrolling_value >=92 ){
		scrolling_value = 0.0;			
	}
	
	if (enPause == false && gameOver == false) 
		glutTimerFunc(updateFrequencyScrolling, updateScrolling, 0);

}



void drawPlayer(player p)
{

	int i, j, l, h;
	i = p->pos.x;
	j = p->pos.y;
	l = p->largeur;
	h = p->hauteur;



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	

	glBindTexture(GL_TEXTURE_2D, texture_joueur_1); 
			

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-(l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 0.0f); glVertex2f((l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 1.0f); glVertex2f((l/2) * Square_size,-(h/2) * Square_size);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-(l/2) * Square_size, -(h/2) * Square_size);
    glEnd();

	glDisable( GL_BLEND );

	glDisable(GL_TEXTURE_2D); // add


}

void drawEnemy(enemy e)	
{
	int i, j, l, h, c;
	i = e->pos.x;
	j = e->pos.y;
	l = e->largeur;
	h = e->hauteur;
	c = e->couleur;
	//glColor3f(1.0f,0.0F,0.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	

	switch (c) {
		case 1:
			glBindTexture(GL_TEXTURE_2D, texture_voiture_1); 
			break;
		case 2:
			glBindTexture(GL_TEXTURE_2D, texture_voiture_2); 
			break;
		case 3:
			glBindTexture(GL_TEXTURE_2D, texture_voiture_3); 
			break;
		case 4:
			glBindTexture(GL_TEXTURE_2D, texture_voiture_4); 
			break;
		default:
			glBindTexture(GL_TEXTURE_2D, texture_voiture_5); 
			break;
	}

	//glBindTexture(GL_TEXTURE_2D, textureID1); // Utiliser la texture 1 pour l'ennemi


	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D); // aj

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-(l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 0.0f); glVertex2f((l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 1.0f); glVertex2f((l/2) * Square_size,-(h/2) * Square_size);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-(l/2) * Square_size, -(h/2) * Square_size);
    glEnd();

	glDisable( GL_BLEND );// rajout pour tester la transparence
	glDisable(GL_TEXTURE_2D); // add

}

void drawAllEnnemis(listeEn e)
{	

	enemy first; 
	enemy next; 
	first = e->starList;
	next = e->starList->nextptr;
	if (e->starList != NULL || e->endList != NULL)
	{
		drawEnemy(first);
		if (e->starList->nextptr != NULL)
		{
			drawEnemy(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawEnemy(next);
			}
		}
	}
}

void drawTirs(tirsP p)
{
	int i, j, l, h;
	i = p->pos.x;
	j = p->pos.y;
	l = p->largeur;
	h = p->hauteur;



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	

	glBindTexture(GL_TEXTURE_2D, texture_tir_joueur); 
			

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-(l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 0.0f); glVertex2f((l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 1.0f); glVertex2f((l/2) * Square_size,-(h/2) * Square_size);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-(l/2) * Square_size, -(h/2) * Square_size);
    glEnd();

	glDisable( GL_BLEND );

	glDisable(GL_TEXTURE_2D); 







}


void drawAllTirs(listetirsP t)
{
	//tirsP first = malloc(sizeof(tirs));//save
	//tirsP next = malloc(sizeof(tirs));//save
	tirsP first;//tentative
	tirsP next;//tentative
	first = t->starList;
	if (t->starList != NULL && t->starList->nextptr != NULL)
	{
	next = t->starList->nextptr;
	}
	if (t->starList != NULL || t->endList != NULL)
	{
		drawTirs(first);
		if (t->starList->nextptr != NULL)
		{
			drawTirs(next);
			while (next->nextptr != NULL)
			{
				next = next->nextptr;
				drawTirs(next);
			}
		}
	}
}








void drawBubble(bubble bub)
{
	int i, j, l, h;
	i = bub->pos.x;
	j = bub->pos.y;
	l = bub->largeur;
	h = bub->hauteur;



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	

	glBindTexture(GL_TEXTURE_2D, texture_tir_bubble); 
			

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-(l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 0.0f); glVertex2f((l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 1.0f); glVertex2f((l/2) * Square_size,-(h/2) * Square_size);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-(l/2) * Square_size, -(h/2) * Square_size);
    glEnd();

	glDisable( GL_BLEND );

	glDisable(GL_TEXTURE_2D); // add


}


void drawAllBubbles(listeBub liste_bub)
{
	
	bubble first;
	bubble next;
	first = liste_bub->premier;
	if (liste_bub->premier != NULL && liste_bub->premier->suivant != NULL)
	{
	next = liste_bub->premier->suivant;
	}
	if (liste_bub->premier != NULL)
	{
		drawBubble(first);
		if (liste_bub->premier->suivant != NULL)
		{
			drawBubble(next);
			while (next->suivant != NULL)
			{
				next = next->suivant;
				drawBubble(next);
			}
		}
	}
}












void drawTirsEnnemi(tirEnn tir_enn)  ///
{
	int i, j, l, h;
	i = tir_enn->pos.x;
	j = tir_enn->pos.y;
	l = tir_enn->largeur;
	h = tir_enn->hauteur;



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	

	glBindTexture(GL_TEXTURE_2D, texture_tir_ennemi); 
			

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-(l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 0.0f); glVertex2f((l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 1.0f); glVertex2f((l/2) * Square_size,-(h/2) * Square_size);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-(l/2) * Square_size, -(h/2) * Square_size);
    glEnd();

	glDisable( GL_BLEND );

	glDisable(GL_TEXTURE_2D); // add


}


void drawAllTirsEnnemi(listeTirEnn liste_tir_enn)
{
	
	tirEnn first;
	tirEnn next;
	first = liste_tir_enn->premier;
	if (liste_tir_enn->premier != NULL && liste_tir_enn->premier->suivant != NULL)
	{
	next = liste_tir_enn->premier->suivant;
	}
	if (liste_tir_enn->premier != NULL)
	{
		drawTirsEnnemi(first);
		if (liste_tir_enn->premier->suivant != NULL)
		{
			drawTirsEnnemi(next);
			while (next->suivant != NULL)
			{
				next = next->suivant;
				drawTirsEnnemi(next);
			}
		}
	}
}
































void drawObstacle(obstacle obs)
{
	int i, j, l, h;
	i = obs->pos.x;
	j = obs->pos.y;
	l = obs->largeur;
	h = obs->hauteur;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(i*Square_size,j*Square_size,0.0f);
	
	if (obs->bubbled == true)
		glBindTexture(GL_TEXTURE_2D, texture_obstacle_bubbled); 
	else if (obs->bonus == true){
		if (obs->bonusType == 1){
			glBindTexture(GL_TEXTURE_2D, texture_obstacle_rien); 
	
		}
		if (obs->bonusType == 2){
			glBindTexture(GL_TEXTURE_2D, texture_obstacle_coeur); 
	
		}
		else if (obs->bonusType == 3){
			glBindTexture(GL_TEXTURE_2D, texture_obstacle_dollar); 

		}
		else if (obs->bonusType == 4){
			glBindTexture(GL_TEXTURE_2D, texture_obstacle_star); 

		}
		else if (obs->bonusType == 5){
			glBindTexture(GL_TEXTURE_2D, texture_obstacle_recharge_bubble); 

		}
	}	
	else 
		glBindTexture(GL_TEXTURE_2D, texture_obstacle); 

	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); 
	
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D); 

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-(l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 0.0f); glVertex2f((l/2) * Square_size, (h/2) * Square_size);
		glTexCoord2f(1.0f, 1.0f); glVertex2f((l/2) * Square_size,-(h/2) * Square_size);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-(l/2) * Square_size, -(h/2) * Square_size);
    glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D); 

}


void drawAllObstacles(listeObs liste_obs)
{	

	obstacle first; 
	obstacle next; 
	first = liste_obs->premier;
	next = liste_obs->premier->suivant;
	if (liste_obs->premier != NULL)
	{
		drawObstacle(first);
		if (liste_obs->premier->suivant != NULL)
		{
			drawObstacle(next);
			while (next->suivant != NULL)
			{
				next = next->suivant;
				drawObstacle(next);
			}
		}
	}
}





















void displayHUD() {

    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

    glColor4f(0.0, 1.0, 1.0, 0.0); 	// transparence ne marche pas pour le moment, à vérifier


	glBegin(GL_QUADS);
		glVertex2f(0.0, 0.0); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(1.0, 0.0); // coin sup droit
		glVertex2f(1.0, 0.085); // coin inf droit
		glVertex2f(0.0, 0.085); // coin inf gauche
    glEnd();




    glColor3f(1.0f, 1.0f, 1.0f); 
	


    
    // Afficher la vie
       glRasterPos2f(0.1, 0.025);
    char life_text[100];
    sprintf(life_text, "Vie: %d", p->vie);
    for (int i = 0; life_text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, life_text[i]);
    }
    
	   // Affiche le nombre de MagicBubbles
       glRasterPos2f(0.3, 0.025);
    char bubbles_text[100];
    sprintf(bubbles_text, "Magic Bubbles: %d", p->bubbles);
    for (int i = 0; bubbles_text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bubbles_text[i]);
    }



	   // Afficher le statut de pause
	if (enPause == true){
		glRasterPos2f(0.5, 0.025);
		char pause_text[100];
		sprintf(pause_text, "Pause !");
		for (int i = 0; pause_text[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pause_text[i]);
		}
	}


 /*
//TIMER abandonné car pas capable de gérer les temps de pause 

    // Afficher le temps écoulé
      glRasterPos2f(0.7, 0.025); 
    char time_text[50];

	int last_paused_time = end_pause_time - start_pause_time;
	int total_paused_time =+ last_paused_time;

	if (enPause != true && gameOver != true){
		time_elapsed = time(NULL) - start_time - total_paused_time;

		sprintf(time_text, "Time: %d", time_elapsed);
		for (int i = 0; time_text[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, time_text[i]);
		}
	}
	else{
		clock_t time_at_pause = time(NULL);
		time_elapsed = time_at_pause - start_time - total_paused_time;
		sprintf(time_text, "Time: %d", time_elapsed);
		for (int i = 0; time_text[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, time_text[i]);
		}
	}	
    */

	


 	// Afficher le score
    glRasterPos2f(0.82, 0.025); 
    char score_text[50];
    sprintf(score_text, "Score: %d", score);
    for (int i = 0; score_text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score_text[i]);
    }

	


	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}




void displayGameOver() {


    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

    glColor4f(0.5, 0.5, 0.5, 0.0); 	// transparence ne marche pas pour le moment, à vérifier

	glBegin(GL_QUADS);
		glVertex2f(0.35, 0.15); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.65, 0.15); // coin sup droit
		glVertex2f(0.65, 0.25); // coin inf droit
		glVertex2f(0.35, 0.25); // coin inf gauche
    glEnd();


	glBegin(GL_QUADS);
		glVertex2f(0.35, 0.65); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.65, 0.65); // coin sup droit
		glVertex2f(0.65, 0.55); // coin inf droit
		glVertex2f(0.35, 0.55); // coin inf gauche
    glEnd();

glBegin(GL_QUADS);
		glVertex2f(0.35, 0.45); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.65, 0.45); // coin sup droit
		glVertex2f(0.65, 0.35); // coin inf droit
		glVertex2f(0.35, 0.35); // coin inf gauche
    glEnd();


   glColor3f(1.0f, 0.0f, 0.0f); 


   	// Game OVER
    glRasterPos2f(0.45, 0.20); 
    char game_over_text[50];
    sprintf(game_over_text, "GAME OVER !");
    for (int i = 0; game_over_text[i] != '\0'; i++) { 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, game_over_text[i]);
    }

	glColor3f(1.0f, 1.0f, 1.0f); 
	// Reprendre la partie
    glRasterPos2f(0.45, 0.40); 
    char nouvelle_partie_text[50];
    sprintf(nouvelle_partie_text, "Lancer une nouvelle partie");
    for (int i = 0; nouvelle_partie_text[i] != '\0'; i++) { 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, nouvelle_partie_text[i]);
    }


	// Retourner au menu principal
    glRasterPos2f(0.45, 0.60); 
    char revenir_menu_texte[50];
    sprintf(revenir_menu_texte, "Revenir au menu principal");
    for (int i = 0; revenir_menu_texte[i] != '\0'; i++) { 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, revenir_menu_texte[i]);
    }


 

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}




void displayPauseButtons() {


    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

    glColor4f(0.5, 0.5, 0.5, 0.0); 	// transparence ne marche pas pour le moment, à vérifier


	glBegin(GL_QUADS);
		glVertex2f(0.35, 0.15); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.65, 0.15); // coin sup droit
		glVertex2f(0.65, 0.25); // coin inf droit
		glVertex2f(0.35, 0.25); // coin inf gauche
    glEnd();

	glBegin(GL_QUADS);
		glVertex2f(0.35, 0.65); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.65, 0.65); // coin sup droit
		glVertex2f(0.65, 0.55); // coin inf droit
		glVertex2f(0.35, 0.55); // coin inf gauche
    glEnd();

glBegin(GL_QUADS);
		glVertex2f(0.35, 0.45); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.65, 0.45); // coin sup droit
		glVertex2f(0.65, 0.35); // coin inf droit
		glVertex2f(0.35, 0.35); // coin inf gauche
    glEnd();


   glColor3f(1.0f, 1.0f, 1.0f); 


     	// Game OVER
    glRasterPos2f(0.45, 0.20); 
    char game_over_text[50];
    sprintf(game_over_text, "Pause !");
    for (int i = 0; game_over_text[i] != '\0'; i++) { 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, game_over_text[i]);
    }
	
	// Reprendre la partie
    glRasterPos2f(0.45, 0.40); 
    char reprendre_text[50];
    sprintf(reprendre_text, "Reprendre la partie (p)");
    for (int i = 0; reprendre_text[i] != '\0'; i++) { 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, reprendre_text[i]);
    }


	// Retourner au menu principal
    glRasterPos2f(0.45, 0.60); 
    char revenir_menu_texte[50];
    sprintf(revenir_menu_texte, "Revenir au menu principal");
    for (int i = 0; revenir_menu_texte[i] != '\0'; i++) { 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, revenir_menu_texte[i]);
    }


 

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}


