/*Préambule*/

#include<stdio.h>
#include<stdlib.h>


/*Fonction permettant d'allouer la mémoire pour un tableau de taille n 
en procédant par référence à l'aide du pointeur sur tableau T 
(la valeur de retour sert à vérifier le bon déroulement)*/

int alloue_tableau(int**T, int n){
    *T = malloc(n*sizeof(int));
    return (*T!=NULL);
}


/*Fonction permettant de désallouer la mémoire allouée à t
(la valeur de retour sert à vérifier le bon déroulement*/

int desalloue_tableau(int*t){
    free(t);
    return (t==NULL);
}

/*Fonction permettant de remplir le tableau avec des valeurs entières aléatoirement générées entre 0 et V (non-compris).*/

void remplir_tableau(int* tab, int taille, int V){
    for(int i = 0; i < taille ; i++){
        tab[i]= rand()%V;
    }
}

/*Fonction permettant d'afficher un tableau*/

void afficher_tableau(int* tab, int taille){
    for(int i = 0 ; i < taille ; i++){
        printf("%d\t", tab[i]);
    }
}

/*Fonction permettant de calculer la somme des carrés des différences entre les éléments du tableau pris deux à deux
somme_v1 utilise la formule 2.2.1 et somme_v2 celle de 2.2.2*/

int somme_v1(int* tab, int taille){
    int res = 0;
    for(int i = 0 ; i < taille ; i++){
        for(int j = 0 ; j < taille ; j++){
            res += ( tab[i] - tab [j] ) ( tab[i] - tab[j] );
        }
    }
    return res;
}


int somme_v2(int*tab, int taille){
    int res = 0;
    int somme_x1x2;
    for(int i = 0 ; i < taille){
        res += 2 * (tab[i]*tab[i]);
        somme_x1x2 = somme_x1x2 + tab[i];
    }
    somme_x1x2 = 2 * (somme_x1x2*somme_x1x2);
    res += somme_x1x2;
    return res
}
