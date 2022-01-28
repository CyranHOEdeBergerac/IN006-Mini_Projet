#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tme1_exo2p1.h" 

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