#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "constantes.h"
#include "bestScores.h"

// Déclaration du tableau de meilleurs scores
int bestScores[nbBestScores];

// Fonction pour trouver le minimum dans un tableau
int min(int tableau[], int taille) {
    int min = tableau[0];

    for (int i = 1; i < taille; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
    }

    return min;
}

// Fonction pour effectuer le tri à bulle sur un tableau
void tri_bulle(int tableau[], int taille) {
    int i, j, temp;
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }
}

// Fonction pour lire les meilleurs scores depuis un fichier
void lireFichierScores(const char *nom_fichier, int bestScores[]) {
    FILE *fichier;
    int i;

    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (i = 0; i < nbBestScores; i++) {
        fscanf(fichier, "%d", &bestScores[i]);
    }

    fclose(fichier);
}

// Fonction pour sauvegarder les meilleurs scores dans un fichier
void sauvegardeFichierScores(const char *nom_fichier, int entiers[], int taille) {
    FILE *fichier;
    int i;

    fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (i = 0; i < taille; i++) {
        fprintf(fichier, "%d\n", entiers[i]);
    }

    fclose(fichier);
}

// Fonction qui permet de mettre à jour le fichier des scores si le score en paramètre est plus grand que le plus petit score du fichier
void updateBestScores(int score) {
    int i;


//    printf("Valeur à insérer : %d\n", score);

    lireFichierScores("meilleursScores.txt", bestScores);
 /*-----boucle de vérification----
    for (i = 0; i < nbBestScores; i++) {
        printf("Meilleur score %d : %d\n", i, bestScores[i]);
    }

    for (i = 0; i < nbBestScores; i++) {
        printf("Meilleur score %d : %d\n", i, bestScores[i]);
    }
-----boucle de vérification----*/

    // Vérification si la valeur est supérieure au plus petit score
    if (score > min(bestScores, nbBestScores)) {
        // Remplacement du plus petit score par la nouvelle valeur
        bestScores[0] = score;

        // Tri des meilleurs scores après insertion
        tri_bulle(bestScores, nbBestScores);
    }
/*
    printf("Après INSERTION et tri à bulle :\n");
    for (i = 0; i < nbBestScores; i++) {
        printf("Meilleur score %d : %d\n", i, bestScores[i]);
    }
*/
    // Sauvegarde des meilleurs scores dans le fichier
    sauvegardeFichierScores("meilleursScores.txt", bestScores, nbBestScores);
}


