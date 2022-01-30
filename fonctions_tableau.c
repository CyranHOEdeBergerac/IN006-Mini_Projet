#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonctions_tableau.h" 

/* 2.1 
Les deux fonctions sont, vis-à-vis de l'allocation mémoire, 
équivalentes. Mais la seconde option permet de ne pas occuper 
notre return, et donc de faire retourner à la fonction une autre valeur (commme un entier par exemple) qui pourra par la suite nous permettre de faire des tests si besoin (pour voir si le malloc s'est bien passé par exemple). 
*/
int alloue_tableau(int** T, int n){
	*T = (int*)(malloc(n*sizeof(int)));
	return (*T != NULL); /*Vérification du bon fonctionnement*/
}

int desalloue_tableau(int* tab){
	free(tab);
	return (tab == NULL);
}

void remplir_tableau(int* tab, int taille, int V){
	for (int i = 0; i<taille; i++){
		tab[i] = rand()%(V);
	}
}

void afficher_tableau(int* tab, int taille){
	printf("[ ");
	for (int i = 0; i<taille; i++){
		printf("%d \t",tab[i]);
	}printf(" ]\n");
}
