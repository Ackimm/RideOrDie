#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>


#include "menu.h"
#include "game.h"
#include "constantes.h"
#include "loadMap.h"
#include "drawMap.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




void drawMenu() {

    glutMouseFunc(mouseClick);

    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	


    glColor4f(0.0, 1.0, 1.0, 0.0); 	// transparence ne marche pas pour le moment, à vérifier


	glBegin(GL_QUADS);
		glVertex2f(0.0, 0.0); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(1.0, 0.0); // coin sup droit
		glVertex2f(1.0, 1.0); // coin inf droit
		glVertex2f(0.0, 1.0); // coin inf gauche
    glEnd();


 	
     glColor4f(0.0, 0.0, 5.0, 5.0);
	glBegin(GL_QUADS);
		glVertex2f(0.350, 0.111); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.650, 0.111); // coin sup droit
		glVertex2f(0.650, 0.222); // coin inf droit
		glVertex2f(0.350, 0.222); // coin inf gauche
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte
    glRasterPos2f(0.5, 0.166); // Position du texte pour le score
    char label_jouer[50];
    sprintf(label_jouer, "Jouer!");
    for (int i = 0; label_jouer[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_jouer[i]);
    }
    
    
    glColor4f(0.0, 0.0, 5.0, 5.0);

	glBegin(GL_QUADS);
		glVertex2f(0.350, 0.333); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.650, 0.333); // coin sup droit
		glVertex2f(0.650, 0.444); // coin inf droit
		glVertex2f(0.350, 0.444); // coin inf gauche
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte
       glRasterPos2f(0.5, 0.388);// Position du texte pour la vie
    char label_lastgame[100];
    sprintf(label_lastgame, "Continue la dernière partie");
    for (int i = 0; label_lastgame[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_lastgame[i]);
    }
    
    
	    glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(0.350, 0.555); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.650, 0.555); // coin sup droit
		glVertex2f(0.650, 0.666); // coin inf droit
		glVertex2f(0.350, 0.666); // coin inf gauche
    glEnd();
    
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte

      glRasterPos2f(0.6, 0.611); // Position du texte pour le temps écoulé
    char label_regles[50];
    sprintf(label_regles, "Règles du jeu et commandes");
    for (int i = 0; label_regles[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_regles[i]);
    }



    	    glColor4f(0.0, 0.0, 5.0, 5.0);

	glBegin(GL_QUADS);
		glVertex2f(0.350, 0.777); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(0.650, 0.777); // coin sup droit
		glVertex2f(0.650, 0.888); // coin inf droit
		glVertex2f(0.350, 0.888); // coin inf gauche
    glEnd();
glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte    
      glRasterPos2f(0.6, 0.833); // Position du texte pour le temps écoulé
    char label_settings[50];
    sprintf(label_settings, "Paramètres");
    for (int i = 0; label_settings[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_settings[i]);
    }



	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}



void mouseClick(int button, int state, int x, int y) {

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float x_f = (float)x;
    float y_f = (float)y;
  

// pour normaliser les données de la souris entre 0 et 1 : 
    float xN =  x_f / windowWidth;
    float yN = y_f / windowHeight;
    
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
       

        // Vérification du clic sur les boutons
        if (xN >= 0.350 && xN <= 0.650) {
            if (yN >= 0.111 && yN <= 0.222) {
                // Clic sur le bouton "Jouer"
                printf("Bouton Jouer cliqué!\n");
                fflush(stdout);
                
            }
            else{
                printf("X : %f, Y = %f\n", xN, yN); // test en attendant de mettre des autres boutons 
                fflush(stdout);

            }    
        
            }
        }
    }


