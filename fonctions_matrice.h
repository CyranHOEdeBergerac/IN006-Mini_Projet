#ifndef FONCTIONS_MATRICE_H
#define FONCTIONS_MATRICE__H

int alloue_matrice(int***M, int taille);

int desalloue_matrice(int**mat, int taille);

void remplir_matrice(int** mat, int taille, int V);

void affiche_matrice(int** mat, int taille);

#endif