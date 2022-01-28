#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonctions_tableau.h" 

/*Fonction permettant d'allouer la mémoire à un tableau pointé par T de taille n*/
int alloue_tableau(int** T, int n){
	*T = (int*)(malloc(n*sizeof(int)));
	return (*T != NULL); /*Vérification du bon fonctionnement*/
}

/*Fonction permettant de désallouer la mémoire de tab*/
int desalloue_tableau(int* tab){
	free(tab);
	return (tab == NULL);
}

/*Fonction permettant de remplir le tableau tab de taille taille avec des entiers aléatoires entre 0 et V (exclu)*/
void remplir_tableau(int* tab, int taille, int V){
	for (int i = 0; i<taille; i++){
		tab[i] = rand()%(V);
	}
}

/*Fonction permettant d'afficher le tableau tab*/
void afficher_tableau(int* tab, int taille){
	printf("[ ");
	for (int i = 0; i<taille; i++){
		printf("%d \t",tab[i]);
	}printf(" ]\n");
}


/*Les deux fonctions permettent de calculer la somme des carrés des différences des éléments de tab deux à deux. La première utilise directement
la formule de l'énoncé, la seconde provient de la formule obtenue en 2.2.2(5) (sur le rapport)*/
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

int somme_v2(int* tab, int taille){
	int somme = 0;
    int somme_carre = 0;
    for(int i = 0 ; i < taille ; i++){
        somme += tab[i];               //On effectue les deux sommes de notre formule
        somme_carre += tab[i]*tab[i];
    }
    return 2*taille*somme_carre - 2* somme*somme;   //On en fait la somme avec les constantes calculées
}
