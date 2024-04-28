#ifndef _BESTSCORES_H_
#define _BESTSCORES_H_


extern int bestScores[nbBestScores];

int min(int tableau[], int taille);
void tri_bulle(int tableau[], int taille);
void lireFichierScores(const char *nom_fichier, int bestScores[]);
void sauvegardeFichierScores(const char *nom_fichier, int entiers[], int taille);
void updateBestScores(int score);









#endif
