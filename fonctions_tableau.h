#ifndef FONCTION_TABLEAU
#define FONCTION_TABLEAU

int alloue_tableau(int** T, int n);

int desalloue_tableau(int*t);

void remplir_tableau(int* tab, int taille, int V);

void remplir_tableau_avec(int* tab, int taille, int V);

void afficher_tableau(int* tab, int taille);

int somme_v1(int* tab, int taille);

int somme_v2(int*tab, int taille);

#endif
