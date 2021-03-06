#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonctions_tableau.h"            //On va se servir des fonctions de la partie précédente pour remplir les lignes de la matrice
#include "fonctions_matrice.h"

/*Fonction permettant d'allouer un tableau à deux dimensions représentant une matrice de dimensions n×n en procédant par adresse
(la valeur de retour sert à tester la bonne exécution)*/

int alloue_matrice(int***M, int taille){
    int** mat_res = (int**) malloc( taille *sizeof(int*));
    if(mat_res == NULL){
        return 0;
    }
    int j;
    for(int i = 0 ; i < taille ; i++){
        int bonne_allocation = alloue_tableau(&mat_res[i],taille);
        if(!bonne_allocation){
            for( j = 0; j < i ; j++){
                desalloue_tableau(mat_res[j]);
            }
            free(mat_res);
            return 0;
        }
    }
    *M = mat_res;
    return 1;
}

/*Fonction permettant de désallouer la matrice*/

void desalloue_matrice(int**mat, int taille){
    for(int i = 0 ; i < taille ; i++){
        desalloue_tableau(mat[i]);
    }
    free(mat);
}

/*Fonction de remplissage de la matrice avec des entiers aléatoires compris entre 0 et V*/
void remplir_matrice(int** mat, int taille, int V){
    for(int i = 0; i < taille ; i++){
        remplir_tableau(mat[i], taille ,V);
    }
}

/*Fonction d'affichage de la matrice*/
void affiche_matrice(int** mat, int taille){
    for(int i = 0; i < taille ; i++){
        afficher_tableau(mat[i],taille);
        printf("\n");
    }
}
