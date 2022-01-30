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
