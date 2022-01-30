#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonctions_tableau.h"            //On va se servir des fonctions de la partie précédente pour remplir les lignes de la matrice
#include "fonctions_matrice.h"

/*Fonction permettant d'allouer un tableau à deux dimensions représentant une matrice de dimensions n×n en procédant par adresse
(la valeur de retour sert à tester la bonne exécution)*/

int alloue_matrice(int***M, int taille){
    int** mat_res = (int**) malloc( taille *sizeof(int*));
    for(int i = 0 ; i < taille ; i++){
        alloue_tableau(&mat_res[i],taille);
    }
    *M = mat_res;
    return (*M !=NULL);
}

/*Fonction permettant de désallouer la matrice*/

int desalloue_matrice(int**mat, int taille){
    for(int i = 0 ; i < taille ; i++){
        desalloue_tableau(mat[i]);
    }
    free(mat);
    return(mat==NULL);
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