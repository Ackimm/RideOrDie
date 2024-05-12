#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include "SOIL.h"

#include "textures.h"

// Menu: 
// Ecran démarrage : 
GLuint texture_ecran_depart;
// Ecran de jeu : HUD : 
GLuint texture_HUD;
// Ecran paramètres : 
GLuint texture_ecran_parametres;
// scores
GLuint texture_ecran_scores;
// pause et gameOver
GLuint texture_gameover;
GLuint texture_pause;

// Boutons
GLuint texture_bouton_facile;
GLuint texture_bouton_moyen;
GLuint texture_bouton_difficile;
GLuint texture_bouton_hardcore;

GLuint texture_bouton_revenir_menu;
GLuint texture_bouton_reprendre;

GLuint texture_bouton_nouvelle;
GLuint texture_bouton_continuer;
GLuint texture_bouton_hall_of_fame;
GLuint texture_bouton_parametres;
GLuint texture_bouton_quitter;

// terrain : 
GLuint texture_herbe_1;
GLuint texture_route_dirt;
GLuint texture_route_bande_centrale;
GLuint texture_bord_route_gauche;
GLuint texture_bord_route_droite;

// voitures
GLuint texture_voiture_1;
GLuint texture_voiture_2;
GLuint texture_voiture_3;
GLuint texture_voiture_4;
GLuint texture_voiture_5;

// joueur : 
GLuint texture_joueur_1;


// tir joueur : 
GLuint texture_tir_joueur;
GLuint texture_tir_ennemi;

// tir bubble : 
GLuint texture_tir_bubble;

// obstacle: 
GLuint texture_obstacle;
GLuint texture_obstacle_bubbled;
GLuint texture_obstacle_dollar;
GLuint texture_obstacle_coeur;
GLuint texture_obstacle_star;
GLuint texture_obstacle_rien;
GLuint texture_obstacle_recharge_bubble;



void initTextures() {
    // Charger les textures

    // Menu : 
    // Ecran de démarrage
    texture_ecran_depart = loadTexture("images/menu/demarrage.png");
    // Ecran de jeu : HUD : 
    texture_HUD  = loadTexture("images/menu/hud.png");
    // regles & parametres 
    texture_ecran_parametres = loadTexture("images/menu/fame_parametres/fond_regles.png");
    // scores
    texture_ecran_scores = loadTexture("images/menu/fame_parametres/fond_scores.png");

    // pause et gameOver
    texture_gameover = loadTexture("images/menu/pause_gameover/texture_gameover.png");
    texture_pause = loadTexture("images/menu/pause_gameover/texture_pause.png");

    // Boutons
    texture_bouton_facile = loadTexture("images/menu/boutons/bouton_facile.png");
    texture_bouton_moyen = loadTexture("images/menu/boutons/bouton_moyen.png");
    texture_bouton_difficile = loadTexture("images/menu/boutons/bouton_difficile.png");
    texture_bouton_hardcore = loadTexture("images/menu/boutons/bouton_hardcore.png");

    texture_bouton_revenir_menu = loadTexture("images/menu/boutons/bouton_revenir_menu.png");
    texture_bouton_reprendre = loadTexture("images/menu/boutons/bouton_reprendre.png");

    texture_bouton_nouvelle = loadTexture("images/menu/boutons/bouton_new_game3.png");
    texture_bouton_continuer = loadTexture("images/menu/boutons/bouton_continuer.png");
    texture_bouton_hall_of_fame = loadTexture("images/menu/boutons/bouton_hall_of_fame.png");
    texture_bouton_parametres = loadTexture("images/menu/boutons/bouton_parametres.png");
    texture_bouton_quitter= loadTexture("images/menu/boutons/bouton_quitter.png");



    // terrain : 
    texture_herbe_1 = loadTexture("images/terrain/land_grass.png");
    texture_route_dirt = loadTexture("images/terrain/land_dirt.png");
    texture_bord_route_gauche = loadTexture("images/terrain/land_grass_gauche.png");
    texture_bord_route_droite = loadTexture("images/terrain/land_grass_droite.png");
    texture_route_bande_centrale = loadTexture("images/terrain/land_dirt_bande_centrale.png");
  
    // voitures : 
    texture_voiture_1 = loadTexture("images/voitures/car_black_3.png");
    texture_voiture_2 = loadTexture("images/voitures/car_blue_3.png");
    texture_voiture_3 = loadTexture("images/voitures/car_green_3.png");
    texture_voiture_4 = loadTexture("images/voitures/car_red_3.png");
    texture_voiture_5 = loadTexture("images/voitures/car_yellow_3.png");
  
    // joueur : 
    texture_joueur_1 = loadTexture("images/joueur/biker_poke_mini.png");
  
    // tirs
    texture_tir_joueur = loadTexture("images/tir/tank_bullet3.png");
    texture_tir_ennemi = loadTexture("images/tir/ballBlack_10.png");
    

    // bubbles
    texture_tir_bubble = loadTexture("images/bubbles/planet00-b.png");
  
    // obstacles
    texture_obstacle = loadTexture("images/obstacles/crate133.png");
    texture_obstacle_bubbled = loadTexture("images/obstacles/crate_bubbled133.png");
    texture_obstacle_dollar = loadTexture("images/obstacles/coin_11.png");
    texture_obstacle_coeur = loadTexture("images/obstacles/coeur133-c.png");
    texture_obstacle_star = loadTexture("images/obstacles/star.png");
    texture_obstacle_rien = loadTexture("images/obstacles/rien.png");
    texture_obstacle_recharge_bubble = loadTexture("images/obstacles/bubble_planet.png");

}

GLuint loadTexture(const char* filename) {
    // Charger l'image PNG avec SOIL
    GLuint textureID = SOIL_load_OGL_texture(
        filename, // Chemin de l'image
        SOIL_LOAD_AUTO, // Chargement automatique de l'image
        SOIL_CREATE_NEW_ID, // Créer un nouvel identifiant de texture
        0 //SOIL_FLAG_INVERT_Y // Inverser l'image sur l'axe Y (optionnel)
    );

    if (textureID == 0) {
        printf("Erreur lors du chargement de l'image %s : %s\n", filename, SOIL_last_result());
    }


    

    return textureID;
}
