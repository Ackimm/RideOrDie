#ifndef TEXTURES_H
#define TEXTURES_H

// Ecran démarrage : 
extern GLuint texture_ecran_depart;

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
