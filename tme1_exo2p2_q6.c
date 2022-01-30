#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctions_tableau.h"
#include "fonctions_matrice.h"
/*On considère que des matrices carrées pour réutiliser nos fonctions*/

/*Fonction calculant le produit de deux matrices carrées en O(n^3)*/
int** pdt_mat_v1(int** mat1, int** mat2, int taille){
	int** res;
	alloue_matrice(&res,taille);
	for (int ligne = 0; ligne < taille; ligne++){
		for (int col = 0; col < taille; col++){
			int coef;
			for (int k = 0; k < taille; k++){
				coef += (mat1[ligne][k] * mat2[k][col]);
			}
			res[ligne][col] = coef;
		}
	}
	return res;
}


/*Fonction calculant le produit de deux matrices carrées avec une complexité un peu moins importante prenant en compte le fait que 
Les deux matrices sont triangulaires*/

int** pdt_mat_v2(int** mat1, int** mat2, int taille){
	int** res; 
	alloue_matrice(&res, taille);
	int coeff; 		//Sera utilisé pour chaque élément de notre matrice finale en stockant les sommes des produits successifs
	
	
	for(int i = 0; i < taille ; i++){
		for(int j = 0 ; j < taille ; j++){
			coeff = 0;
			for(int k = j ; k < taille ; k ++){
				coeff += mat1[i][k]*mat2[k][j];
			}
			res[i][j] = coeff;
		}
	}
	return res;
}

/*Main permettant comparaison par gnuplot*/
int main(){
    int V = 200;
    FILE* fichier = fopen("sortie_vitesse.txt","w");
    for (int n=10; n < 1000; n = n+100){
        /*Création de la matrice*/
        int taille = n;
        int** mat1;
        int** mat2;
        alloue_matrice(&mat1,taille);
        alloue_matrice(&mat2,taille);
        remplir_matrice(mat1,taille,V);
        remplir_matrice(mat2,taille,V); /*L'objectif ici n'est pas tant d'avoir un résultat mathématique correct 
		que de comparer la complexité temporelle des algorithmes. Le pdt_mat_v2 traitera le même nombre de coefficients
		que les matrices données en argument soient réellement ou non triangulaires. Le résultat sera erroné, mais c'est 
		ici sans importance.*/

        /*Test et comparaison de nos algorithmes*/
        clock_t temps_initial;
        clock_t temps_final;
        double temps_algo1;
        double temps_algo2;
        int** res;

        temps_initial = clock();
        res = pdt_mat_v1(mat1,mat2,taille);
        temps_final = clock();
        temps_algo1 = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

        temps_initial = clock();
        res = pdt_mat_v2(mat1,mat2,taille);
        temps_final = clock();
        temps_algo2 = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

        fprintf(fichier,"%d\t",n);
        fprintf(fichier,"%f\t",temps_algo1);
        fprintf(fichier,"%f\n",temps_algo2);
        
        /*Libération de la mémoire*/
        desalloue_matrice(res,taille);
        desalloue_matrice(mat1,taille);
        desalloue_matrice(mat2,taille);
    }
    /*Fermeture du fichier*/
    fclose(fichier);
}
