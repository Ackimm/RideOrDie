#ifndef TEXTURES_H
#define TEXTURES_H


// Menu: 
// Ecran démarrage : 
extern GLuint texture_ecran_depart;
// Ecran de jeu : HUD : 
extern GLuint texture_HUD;
// Ecran paramètres : 
extern GLuint texture_ecran_parametres;
// scores
extern GLuint texture_ecran_scores;
// pause et gameOver
extern GLuint texture_gameover;
extern GLuint texture_pause;

// Boutons
extern GLuint texture_bouton_facile;
extern GLuint texture_bouton_moyen;
extern GLuint texture_bouton_difficile;
extern GLuint texture_bouton_hardcore;

extern GLuint texture_bouton_revenir_menu;
extern GLuint texture_bouton_reprendre;

extern GLuint texture_bouton_nouvelle;
extern GLuint texture_bouton_continuer;
extern GLuint texture_bouton_hall_of_fame;
extern GLuint texture_bouton_parametres;
extern GLuint texture_bouton_quitter;

// voitures
extern GLuint texture_voiture_1;
extern GLuint texture_voiture_2;
extern GLuint texture_voiture_3;
extern GLuint texture_voiture_4;
extern GLuint texture_voiture_5;

// joueur : 
extern GLuint texture_joueur_1;

// terrain : 
extern GLuint texture_herbe_1;
extern GLuint texture_route_dirt;
extern GLuint texture_route_bande_centrale;

extern GLuint texture_bord_route_gauche;
extern GLuint texture_bord_route_droite;


// tir joueur : 
extern GLuint texture_tir_joueur;
extern GLuint texture_tir_ennemi;



// tir bubble : 
extern GLuint texture_tir_bubble;


// obstacle: 
extern GLuint texture_obstacle;
extern GLuint texture_obstacle_bubbled;
extern GLuint texture_obstacle_dollar;
extern GLuint texture_obstacle_coeur;
extern GLuint texture_obstacle_star;
extern GLuint texture_obstacle_rien;
extern GLuint texture_obstacle_recharge_bubble;




// Fonction pour initialiser les textures
void initTextures();

// Fonction pour charger une texture à partir d'un fichier PNG avec SOIL
GLuint loadTexture(const char* filename);

#endif 
