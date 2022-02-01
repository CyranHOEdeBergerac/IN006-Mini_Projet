#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonctions_tableau.h" 

/*Fonction allouant un tableau de taille n à l'adresse contenue dans T*/
int alloue_tableau(int** T, int n){
	*T = (int*)(malloc(n*sizeof(int)));
	return (*T != NULL); /*Vérification du bon fonctionnement*/
}

/*Fonction désallouant la mémoire allouée au tableau tab*/
int desalloue_tableau(int* tab){
	free(tab);
	return (tab == NULL);
}

/*Fonction remplissant le tableau tab de taille taille avec des valeurs aléatoires comprises etre 0 et V exclu*/
void remplir_tableau(int* tab, int taille, int V){
	for (int i = 0; i<taille; i++){
		tab[i] = rand()%(V);
	}
}

/*Fonction remplissant le tableau tab de taille taille avec la valeur V dans toutes ses cases*/
void remplir_tableau_avec (int* tab, int taille, int V){
	for(int i = 0 ; i < taille ; i++){
		tab[i] = V;
	}
}
	
/*Fonction permettant d'afficher le tableau d'entiers tab de taille taille passé en paramètres*/
void afficher_tableau(int* tab, int taille){
	printf("[ ");
	for (int i = 0; i<taille; i++){
		printf("%d \t",tab[i]);
	}printf(" ]\n");
}
