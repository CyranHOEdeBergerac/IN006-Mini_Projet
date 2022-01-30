#include<stdio.h>
#include<stdlib.h>
#include "fonctions_tableau.h"
#include "fonctions_matrice.h"

/*Fonction permettant de vérifier que tous les éléments de la matrice mat sont différents*/
/*en O(n^4)*/
int mat_diff_v1(int** mat, int taille){
    int val_courante;
    int val_comparaison;
    int meme_element;
    for(int i1 = 0; i1 < taille ; i1++){
        for(int j1 = 0 ; j1 < taille ; j1++){
            val_courante = mat[i1][j1];
            for (int i2 = 0; i2 < taille; i2++){
                for (int j2 = 0; j2 < taille; j2++){
                    val_comparaison = mat[i2][j2];
                    meme_element = (i1==i2)&&(j1==j2);
                    if ( (val_courante == val_comparaison)&&(!meme_element) ){
                        return 0;
                    }
                }
            }
        }
    } 
    return 1;
}

/*meilleure complexité connaissant V : O(n^2)*/
int mat_diff_v2(int** mat, int taille,int V){
    /*On créé un tableau de taille V qu'on remplit de 0*/
    int* tab_comparaison;
    alloue_tableau(&tab_comparaison,V);
    remplir_tableau(tab_comparaison,V,1);
    
    int val_courante;
    for (int i = 0; i < taille; i++){
        for (int j = 0; j < taille; j++){
            val_courante = mat[i][j];
            if (tab_comparaison[val_courante] != 0){
                return 0;
            }
            tab_comparaison[val_courante] = 1;
        }
    }
    return 1;
}

/*Main permettant comparaison par gnuplot*/
int main(){
    //int V = 1000; //choix 1 : fixer V pour toutes les itérations
    FILE* fichier = fopen("sortie_vitesse.txt","w");
    for (int n=10; n < 10000; n = n+100){
        /*Création de la matrice*/
        int taille = n;
        int V = n*10; //choix 2 : faire varier V selon la taille de la matrice (amène au pire des cas)
        int** mat;
        alloue_matrice(&mat,taille);
        remplir_matrice(mat,taille,V);

        /*Test et comparaison de nos algorithmes*/
        clock_t temps_initial;
        clock_t temps_final;
        double temps_algo1;
        double temps_algo2;

        temps_initial = clock();
        mat_diff_v1(mat,taille);
        temps_final = clock();
        temps_algo1 = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

        temps_initial = clock();
        mat_diff_v2(mat,taille,V);
        temps_final = clock();
        temps_algo2 = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

        fprintf(fichier,"%d\t",n);
        fprintf(fichier,"%f\t",temps_algo1);
        fprintf(fichier,"%f\n",temps_algo2);
        
        /*Libération de la mémoire*/
        desalloue_matrice(mat,taille);
    }
    /*Fermeture du fichier*/
    fclose("sortie_vitesse.txt");
}


