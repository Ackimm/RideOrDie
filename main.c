#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

#include "loadMap.h"
//#include "drawMap.h"
#include "game.h"
#include "player.h"
#include "enemies.h"
#include "tirs.h"

/*---------------------test du HUD-----------------------
---------------------test du HUD-----------------------*/


int score = 0;
int life = 100;
int time_elapsed = 0;
time_t start_time;

void startTimer(){
	start_time = time(NULL);

}

// Fonction de rappel pour mettre à jour le chronomètre
void updateTimer(int value) {
    time_elapsed = time(NULL) - start_time ; // Afficher le temps écoulé
    glutTimerFunc(1000, updateTimer, 0); // Rappeler cette fonction dans 1000 millisecondes (1 seconde)
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
		glVertex2f(1.0, 0.0); //coin sup droit
		glVertex2f(1.0, 0.05); // coin inf droit
		glVertex2f(0.0, 0.05); // coin inf gauche
    glEnd();



	



 	// Afficher le score
    glColor3f(1.0f, 1.0f, 1.0f); // Couleur blanche pour le texte
    glRasterPos2f(0.2, 0.025); // Position du texte pour le score
    char score_text[50];
    sprintf(score_text, "Score: %d", score);
    for (int i = 0; score_text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score_text[i]);
    }
    
    // Afficher la vie
       glRasterPos2f(0.4, 0.025);// Position du texte pour la vie
    char life_text[100];
    sprintf(life_text, "Life: %d", life);
    for (int i = 0; life_text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, life_text[i]);
    }
    
    // Afficher le temps écoulé
      glRasterPos2f(0.6, 0.025); // Position du texte pour le temps écoulé
    char time_text[50];
	glutTimerFunc(1000, updateTimer, 0);
    sprintf(time_text, "Time: %d", time_elapsed);
    for (int i = 0; time_text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, time_text[i]);
    }






	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}


void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}


void handleResize(int width,int height)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (height == 0)
		height = 1;
	//float ratio =  width * 1.0 / height;
  	  float aspectRatio = (float)width / (float)height;



	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the correct perspective.
	//gluPerspective(45,ratio,1,100);
	
	gluOrtho2D(0, mX * Square_size * aspectRatio, mY * Square_size * aspectRatio, 0);
	
	//gluOrtho2D(0, ratio*width, ratio*height, 0);
		
}


void Display()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	game(&mX, &mY, p, e, t);
	


	
	//drawWall(mX, mY);
 	displayHUD(); // associe le HUD au premier ennemi de la listeEn au lieu de le fixer en haut de l'écran
	glutSwapBuffers();
	//glFlush();
}



int main(int argc, char *argv[])
{
	
// en vrai 124*125 pour le fichier 120*140 horizontal (à creuse...)
// en vrai 124*126 pour le fichier 124*124 réseau de routes (à creuse...)
// valeurs origine pour map 1 : 30 * 41 

	mX = 124; // valeur réelle 124 pour le verti 
	mY = 124; // valeur réelle 124 pour le verti 

	srand(time(NULL));
	loadMap(&mX, &mY);
	p = createPlayer(&mX, &mY);
	e = initialListEnemies();
	t = initialListeTirs();

	startTimer();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize((mX-23.2)*Square_size, mY*Square_size); // le -23 ne fait pas vraiment sens pour moi. je l'ai trouvé en chipotant. A creuser

	glutCreateWindow("Ride Or Die! A VvV Story");

	initRendering();

	glutDisplayFunc(Display);



	glutReshapeFunc(handleResize);

	glutTimerFunc(10, updateEnemies, 1);
	glutTimerFunc(10, updateNewEnemies, 3);
	glutTimerFunc(10, updateDeleateEnemies, 4);
	// tirs:  
	glutTimerFunc(10, updateTirs, 2);
	glutTimerFunc(10, updateDeleteTirs, 5);
	
	

	glEnable(GL_DEPTH_TEST);
	

	glutMainLoop();

	return 0;
}
