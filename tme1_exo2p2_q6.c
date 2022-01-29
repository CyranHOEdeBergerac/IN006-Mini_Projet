/*On considère que des matrices carrées pour réutiliser nos fonctions*/

/*Calcul du produit de deux matrices en O(n^3)*/
tab** pdt_mat_v1(int** mat1, int** mat2, int taille){
	int** res;
	alloue_matrice(&res,taille);
	for (int ligne = 0; ligne < taille; ligne++){
		for (int col = 0; col < taille; col++){
			int coef;
			for (int k = 0; k < taille; k++){
				coef += (mat1[ligne][k] + mat2[k][col]);
			}
			res[ligne][col] = coef;
		}
	}
	return res;
}