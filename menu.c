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
#include "gameInitAndTimers.h"
#include "bestScores.h"
#include "collision.h"
#include "textures.h"



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


float longueur_bouton = 0.3333f;
float hauteur_bouton = 0.0909f;

menu currentMenu = menuAccueil;

difficulte currentDifficulte;


void drawMenu() {

    glutMouseFunc(mouseClick);



    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	


/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture_ecran_depart); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0,0);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(1,0);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(1,1);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0,1);
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 

/*TEST TEXTURE*/
/*SAVE---------

	glPushMatrix();
	glLoadIdentity();
 glColor4f(0.0, 1.0, 1.0, 0.0); 	// transparence ne marche pas pour le moment, à vérifier
	glBegin(GL_QUADS);
		glVertex2f(0.0, 0.0); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f(1.0, 0.0); // coin sup droit
		glVertex2f(1.0, 1.0); // coin inf droit
		glVertex2f(0.0, 1.0); // coin inf gauche
    glEnd();
------------SAVE*/


/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_nouvelle); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (2*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (2*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 


/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_continuer); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, 3*hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), 3*hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (4*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (4*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 

/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_hall_of_fame); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, 5*hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), 5*hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (6*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (6*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 



/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_parametres); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, 7*hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), 7*hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (8*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (8*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 



/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_quitter); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, 9*hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), 9*hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (10*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (10*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 


/*

     glColor4f(0.0, 0.0, 5.0, 5.0);
	glBegin(GL_QUADS);
		glVertex2f(longueur_bouton, hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2*longueur_bouton), hauteur_bouton); // coin sup droit
		glVertex2f((2*longueur_bouton), (2*hauteur_bouton)); // coin inf droit
		glVertex2f(longueur_bouton, (2*hauteur_bouton)); // coin inf gauche
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte
    float position_texte_bouton = ((2)*hauteur_bouton);
    glRasterPos2f(0.43, 0.1363636); // Position du texte pour le score
    char label_jouer[50];
    sprintf(label_jouer, "Nouvelle partie!");
    for (int i = 0; label_jouer[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_jouer[i]);
    }
    
    
    glColor4f(0.0, 0.0, 5.0, 5.0);

	glBegin(GL_QUADS);
		glVertex2f(longueur_bouton, 3*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2*longueur_bouton), 3*hauteur_bouton); // coin sup droit
		glVertex2f((2*longueur_bouton), (4*hauteur_bouton)); // coin inf droit
		glVertex2f(longueur_bouton, (4*hauteur_bouton)); // coin inf gauche
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte
       glRasterPos2f(0.38, 0.3181818);// Position du texte pour la vie
    char label_lastgame[100];
    sprintf(label_lastgame, "Continue la partie en cours");
    for (int i = 0; label_lastgame[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_lastgame[i]);
    }
    
    
	    glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(longueur_bouton, 5*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2*longueur_bouton), 5*hauteur_bouton); // coin sup droit
		glVertex2f((2*longueur_bouton), (6*hauteur_bouton)); // coin inf droit
		glVertex2f(longueur_bouton, (6*hauteur_bouton)); // coin inf gauche
    glEnd();
    
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte

      glRasterPos2f(0.45, 0.5); // Position du texte pour le temps écoulé
    char label_scores[50];
    sprintf(label_scores, "Hall of fame");
    for (int i = 0; label_scores[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_scores[i]);
    }


    
	    glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(longueur_bouton, 7*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2*longueur_bouton), 7*hauteur_bouton); // coin sup droit
		glVertex2f((2*longueur_bouton), (8*hauteur_bouton)); // coin inf droit
		glVertex2f(longueur_bouton, (8*hauteur_bouton)); // coin inf gauche
    glEnd();
    
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte

      glRasterPos2f(0.42, 0.68181818); // Position du texte pour le temps écoulé
    char label_parametres[50];
    sprintf(label_parametres, "Regles et parametres");
    for (int i = 0; label_parametres[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_parametres[i]);
    }


    
	    glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(longueur_bouton, 9*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2*longueur_bouton), 9*hauteur_bouton); // coin sup droit
		glVertex2f((2*longueur_bouton), (10*hauteur_bouton)); // coin inf droit
		glVertex2f(longueur_bouton, (10*hauteur_bouton)); // coin inf gauche
    glEnd();
    
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte

      glRasterPos2f(0.47, 0.86363636); // Position du texte pour le temps écoulé
    char label_quitter[50];
    sprintf(label_quitter, "Quitter");
    for (int i = 0; label_quitter[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_quitter[i]);
    }
*/
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

// TEST ---------------
  //  glutPostRedisplay();

}




void drawScores() {

    glutMouseFunc(mouseClick);

    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);

//-----------------



/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture_ecran_depart); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0,0);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(1,0);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(1,1);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0,1);
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 





    /*TEST TEXTURE*/
        glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
        glBindTexture(GL_TEXTURE_2D, texture_ecran_scores); 
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
        glEnable( GL_BLEND );// rajout pour tester la transparence
        glEnable(GL_TEXTURE_2D); // aj


        glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0); glVertex2f(0.33333, 0.12f);
            glTexCoord2f(1.0, 0.0); glVertex2f(0.66666, 0.12f);
            glTexCoord2f(1.0, 1.0); glVertex2f(0.66666, 0.70f);
            glTexCoord2f(0.0, 1.0); glVertex2f(0.33333, 0.70f);
        glEnd();

        glDisable( GL_BLEND );
        glDisable(GL_TEXTURE_2D); 



/*




 		

      glBegin(GL_QUADS);
		glVertex2f(0.5*longueur_bouton, hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2.5*longueur_bouton), hauteur_bouton); // coin sup droit
		glVertex2f((2.5*longueur_bouton), (8*hauteur_bouton)); // coin inf droit
		glVertex2f(0.5*longueur_bouton, (8*hauteur_bouton)); // coin inf gauche
    glEnd();

*/   

/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_revenir_menu); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, 9*hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), 9*hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (10*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (10*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 




/*

 glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(0.5*longueur_bouton, 9*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2.5*longueur_bouton), 9*hauteur_bouton); // coin sup droit
		glVertex2f((2.5*longueur_bouton), (10*hauteur_bouton)); // coin inf droit
		glVertex2f(0.5*longueur_bouton, (10*hauteur_bouton)); // coin inf gauche
    glEnd();
    */
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte


     glRasterPos2f(0.47, 0.2); 
    char best_score_1_label[50];
    sprintf(best_score_1_label, "%d", bestScores[4]);
    for (int i = 0; best_score_1_label[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, best_score_1_label[i]);
    }

       glRasterPos2f(0.47, 0.3); 
    char best_score_2_label[50];
    sprintf(best_score_2_label, "%d", bestScores[3]);
    for (int i = 0; best_score_2_label[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, best_score_2_label[i]);
    }

       glRasterPos2f(0.47, 0.4); 
    char best_score_3_label[50];
    sprintf(best_score_3_label, "%d", bestScores[2]);
    for (int i = 0; best_score_3_label[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, best_score_3_label[i]);
    }

       glRasterPos2f(0.47, 0.5); 
    char best_score_4_label[50];
    sprintf(best_score_4_label, "%d", bestScores[1]);
    for (int i = 0; best_score_4_label[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, best_score_4_label[i]);
    }

       glRasterPos2f(0.47, 0.6); 
    char best_score_5_label[50];
    sprintf(best_score_5_label, "%d", bestScores[0]);
    for (int i = 0; best_score_5_label[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, best_score_5_label[i]);
    }

/*

      glRasterPos2f(0.47, 0.86363636); 
    char label_retour_menu[50];
    sprintf(label_retour_menu, "Revenir au menu principal");
    for (int i = 0; label_retour_menu[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_retour_menu[i]);
    }*/

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}





void drawParametres() {

    glutMouseFunc(mouseClick);

    glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);

//-----------------



/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture_ecran_depart); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0,0);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(1,0);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(1,1);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0,1);
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 








/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, texture_ecran_parametres); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(0.161616f, 0.161616f);
		glTexCoord2f(1.0, 0.0); glVertex2f(0.833333f, 0.161616f);
		glTexCoord2f(1.0, 1.0); glVertex2f(0.833333f, 0.833333f);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.161616f, 0.833333f);
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 








/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

    switch(currentDifficulte)
	{
		case 1: 
	        glBindTexture(GL_TEXTURE_2D, texture_bouton_facile); 
		break;

		case 2: 
	        glBindTexture(GL_TEXTURE_2D, texture_bouton_moyen); 
		break;

        case 3: 
	        glBindTexture(GL_TEXTURE_2D, texture_bouton_difficile); 
		break;

        case 4: 
	        glBindTexture(GL_TEXTURE_2D, texture_bouton_hardcore); 
		break;

        default: 
	        glBindTexture(GL_TEXTURE_2D, texture_bouton_facile); 
		break;
    }


	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (2*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (2*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 

/*
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0.38888, 0.0375);
		glTexCoord2f(1.0, 0.0); glVertex2f(0.61111, 0.0375);
		glTexCoord2f(1.0, 1.0); glVertex2f(0.61111, 0.12916);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.38888, 0.12916);
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); */

/*
		    glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(0.5*longueur_bouton, 1*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2.5*longueur_bouton), 1*hauteur_bouton); // coin sup droit
		glVertex2f((2.5*longueur_bouton), (2*hauteur_bouton)); // coin inf droit
		glVertex2f(0.5*longueur_bouton, (2*hauteur_bouton)); // coin inf gauche
    glEnd();
    
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte

      glRasterPos2f(0.47, 1-0.86363636); // Position du texte pour le temps écoulé
    char label_changer_difficulte[50];


	switch(currentDifficulte)
	{
		case 1: 
			sprintf(label_changer_difficulte, "Trop facile");
		break;

		case 2: 
			sprintf(label_changer_difficulte, "Mouais");
		break;

        case 3: 
			sprintf(label_changer_difficulte, "La on parle");
		break;

        case 4: 
			sprintf(label_changer_difficulte, "RIDE OR DIE !");
		break;

        default: 
			sprintf(label_changer_difficulte, "Trop facile");
		break;
    }
  //  sprintf(label_changer_difficulte, "Changer la difficulte");
    for (int i = 0; label_changer_difficulte[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_changer_difficulte[i]);
    }
*/

/*TEST TEXTURE*/
    glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
glBindTexture(GL_TEXTURE_2D, texture_bouton_revenir_menu); 
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE); // ajout
	glEnable( GL_BLEND );// rajout pour tester la transparence
	glEnable(GL_TEXTURE_2D); // aj


	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(longueur_bouton, 9*hauteur_bouton);
		glTexCoord2f(1.0, 0.0); glVertex2f((2*longueur_bouton), 9*hauteur_bouton);
		glTexCoord2f(1.0, 1.0); glVertex2f((2*longueur_bouton), (10*hauteur_bouton));
		glTexCoord2f(0.0, 1.0); glVertex2f(longueur_bouton, (10*hauteur_bouton));
    glEnd();

    glDisable( GL_BLEND );
	glDisable(GL_TEXTURE_2D); 

/*

 		    glColor4f(0.0, 0.0, 5.0, 5.0);

    glBegin(GL_QUADS);
		glVertex2f(0.5*longueur_bouton, 9*hauteur_bouton); // coin sup gauche (puis dans le sens des aiguilles d'une montre)
		glVertex2f((2.5*longueur_bouton), 9*hauteur_bouton); // coin sup droit
		glVertex2f((2.5*longueur_bouton), (10*hauteur_bouton)); // coin inf droit
		glVertex2f(0.5*longueur_bouton, (10*hauteur_bouton)); // coin inf gauche
    glEnd();
    
        glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte

      glRasterPos2f(0.47, 0.86363636); // Position du texte pour le temps écoulé
    char label_retour_menu[50];
    sprintf(label_retour_menu, "Revenir au menu principal");
    for (int i = 0; label_retour_menu[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, label_retour_menu[i]);
    }*/

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}






void changerMenu(menu nouveauMenuCourrant) { 
    currentMenu = nouveauMenuCourrant;
    glutPostRedisplay();
}



void mouseClick(int button, int state, int x, int y) {

    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float x_f = (float)x;
    float y_f = (float)y;
  


// pour normaliser les données de la souris entre 0 et 1 : 
    float xN =  x_f / windowWidth;
    float yN = y_f / windowHeight;
    
    

    if (currentMenu == menuAccueil){


        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        

            // Vérification du clic sur les boutons
            if (xN >= longueur_bouton && xN <= 2*longueur_bouton) {
                if (yN >= hauteur_bouton && yN <= 2*hauteur_bouton) {
                               
                   enPause = false;
                   gameOver = true;  
                   // initGameParametres();
                    updateBestScores(score);
                    reinitializeGame();
                    gameTimers();

                   // reInit = false;

                    changerMenu(nouvellePartie); // ici il faudrait faire le lien avec le main où on déclare l'extern
            //        printf("Menu sélectionné : %d\n", currentMenu);
              //      fflush(stdout);
                
                    
                }
                else if (yN >= 3*hauteur_bouton && yN <= 4*hauteur_bouton) {

                //    printf("X : %f, Y = %f\n", xN, yN); // test en attendant de mettre des autres boutons 
                  //  if (gameOver != true && p->pos.x != 1)
                     //  gameTimers();
                    if (gameOver == true || p->pos.x == 1)
                        reinitializeGame();
                        
                    enPause = false;
                                           gameTimers();

                    changerMenu(nouvellePartie); // ici il faudrait faire le lien avec le main où on déclare l'extern
                 //   printf("Menu sélectionné : %d\n", currentMenu);
                   // fflush(stdout);

                }    
            
                else if (yN >= 5*hauteur_bouton && yN <= 6*hauteur_bouton) {
                   // printf("X : %f, Y = %f\n", xN, yN); // test en attendant de mettre des autres boutons 
                    changerMenu(highScores); // ici il faudrait faire le lien avec le main où on déclare l'extern
                    updateBestScores(0);
                 //   printf("Menu sélectionné : %d\n", currentMenu);
                  //  fflush(stdout);

                }    

                else if (yN >= 7*hauteur_bouton && yN <= 8*hauteur_bouton) {
              //      printf("X : %f, Y = %f\n", xN, yN); // test en attendant de mettre des autres boutons 
                    changerMenu(parametres); // ici il faudrait faire le lien avec le main où on déclare l'extern
               //     printf("Menu sélectionné : %d\n", currentMenu);
 //                   fflush(stdout);

                }    


                else if (yN >= 9*hauteur_bouton && yN <= 10*hauteur_bouton) {
              //      printf("X : %f, Y = %f\n", xN, yN); // test en attendant de mettre des autres boutons 
                  changerMenu(quitter); // ici il faudrait faire le lien avec le main où on déclare l'extern
                 //   printf("Menu sélectionné : %d\n", currentMenu);
                  //  fflush(stdout);

                }    

            }
        }

    }

    if (currentMenu == highScores){


        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        

            // Vérification du clic sur les boutons
            if (xN >= longueur_bouton && xN <= 2*longueur_bouton) {
                if (yN >= 9*hauteur_bouton && yN <= 10*hauteur_bouton) {
                  //  printf("Retour au menu!\n");

                    changerMenu(menuAccueil); // ici il faudrait faire le lien avec le main où on déclare l'extern
               //     printf("Menu sélectionne : %d\n", currentMenu);
                //    fflush(stdout);
            

                }
            }

        }

    }

 if (currentMenu == parametres){


        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        

            // Vérification du clic sur les boutons
         /*   if (xN >= 0.5*longueur_bouton && xN <= 2*5*longueur_bouton) {
                if (yN >= 1*hauteur_bouton && yN <= 2*hauteur_bouton) {*/
            if (xN >= longueur_bouton && xN <= 2*longueur_bouton) {
              //  if (yN >= 0.0375 && yN <= 0.12916) {
                if (yN >= hauteur_bouton && yN <= 2*hauteur_bouton) {

                    if (currentDifficulte != 4)
                        currentDifficulte++;
                    else
                        currentDifficulte=1;
         //       printf("Nouvelle difficulté : %i\n", currentDifficulte);
           //     fflush(stdout);
                glutPostRedisplay();


                }

                if (yN >= 9*hauteur_bouton && yN <= 10*hauteur_bouton) {
                    // Clic sur le bouton "Jouer"
             //       printf("Retour au menu!\n");

                    changerMenu(menuAccueil); // ici il faudrait faire le lien avec le main où on déclare l'extern
               //     printf("Menu sélectionné : %d\n", currentMenu);
                 //   fflush(stdout);
                }
            }

        }

    }

   // if (currentMenu == gameOverMenu || currentMenu == pauseMenu){
    if (currentMenu == pauseMenu){

        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        

            // Vérification du clic sur les boutons
            if (xN >= 0.35 && xN <= 0.65) {
               
               
                if (yN >= 0.35 && yN <= 0.45) { 

                    if (gameOver == false){ 
                        enPause = !enPause;
                     //   printf("Bool enPause = %i\n", enPause);
                       // fflush(stdout);

                        if (enPause == false){
                            gameTimers();
                        //    int end_pause_time = time(NULL);
                            if (currentMenu==pauseMenu){
                                changerMenu(nouvellePartie);

                            }
                        }		
                        else{
                            changerMenu(pauseMenu);
                          //  int start_pause_time = time(NULL);
                        }
                    }


                    fflush(stdout);
                }
               

                if (yN >= 0.55 && yN <= 0.65) {
             //       printf("Retourner au menu principal\n");
               //     fflush(stdout);
                    // ajouter la fonction de sauvegarde des scores
                    // ajotuer la fonction de réinitialisation
            		//updateBestScores(score);
                    enPause = 1;
                    changerMenu(menuAccueil); // ici il faudrait faire le lien avec le main où on déclare l'extern
                 
                    
            

                }

            }

        }

    }

    if (currentMenu == gameOverMenu){

        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        

            // Vérification du clic sur les boutons
            if (xN >= 0.35 && xN <= 0.65) {
               
               
                if (yN >= 0.35 && yN <= 0.45) { 
                            
                    

                    reinitializeGame();
                    gameTimers();

                    changerMenu(nouvellePartie);

                   // reinitializeGame();



                   
                }
               

                if (yN >= 0.55 && yN <= 0.65) {
               //     printf("Retourner au menu principal\n");
                 //   fflush(stdout);
                    // ajouter la fonction de sauvegarde des scores
                    // ajotuer la fonction de réinitialisation

                    changerMenu(menuAccueil); // ici il faudrait faire le lien avec le main où on déclare l'extern
                 
                    
            

                }

            }

        }

    }


}

