/*Préambule*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "fonctions_tableau.h"

/*2.2*/

int somme_v1(int* tab,int taille){
	int res = 0;
	int val;
	for (int i = 0; i<taille; i++){
		for (int j =0; j<taille; j++){
			val = (tab[i] - tab[j]);
			res += val*val;
		}
	}
	return res;
}
/*La complexité est bien en O(n**2) : la première boucle fait n opérations,
et la seconde boucle imbriquée en fait n aussi. Ainsi à chaque itération de
la première on effectue n opérations.*/

int somme_v2(int* tab, int taille){
	int somme = 0;
    int somme_carre = 0;
    for(int i = 0 ; i < taille ; i++){
        somme += tab[i];               //On effectue les deux sommes de notre formule
        somme_carre += tab[i]*tab[i];
    }
    return 2*taille*somme_carre - 2* somme*somme;   //On en fait la somme avec les constantes calculées
}


/*Fonction main permettant d'obtenir les graphiques gnuplot représentant les temps de calcul de nos deux algorithmes*/
int main(){
   /*Ouverture du fichier qui stockera nos valeurs de temps de calcul*/
	FILE* fichier = fopen("sortie_vitesse.txt","w");
   
   /*Itérations des calculs et stockage dans le fichier*/
	for (int n=10; n < 1000; n = n+10){
		/*Création du tableau*/
		int taille = n;
		int* tab;
		alloue_tableau(&tab,taille);
		remplir_tableau(tab,taille,20);

		/*Calcul du temps de calcul*/
		clock_t temps_initial;
		clock_t temps_final;
		double temps_algo1;
		double temps_algo2;
      
      //Algorithme 1
		temps_initial = clock();
		int s1 = somme_v1(tab,taille);
		temps_final = clock();
		temps_algo1 = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;
      
      //Algorithme 2
		temps_initial = clock();
		int s2 = somme_v2(tab,taille);
		temps_final = clock();
		temps_algo2 = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;

      /*Ecriture dans le fichier*/
		fprintf(fichier,"%d\t",n);
		fprintf(fichier,"%f\t",temps_algo1);
		fprintf(fichier,"%f\n",temps_algo2);
		
		/*Libération de la mémoire*/
		desalloue_tableau(tab);
	}

}

