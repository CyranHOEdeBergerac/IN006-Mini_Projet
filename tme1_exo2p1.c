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

/*Fonctions permettant de calculer la somme des carr'es des diff'erences entre les éléments du tableau pris deux à deux
somme_v1 utilise la formule 2.2.1 et somme_v2 celle obtenue apre's simplification de la somme de 2.2.1 (voir document
r'eponse 2.2.2(5))*/

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
    int somme = 0;
    int somme_carre = 0
    for(int i = 0 ; i < taille ; i++){
        somme += tab[i];               //On effectue les deux sommes de notre formule
        somme_carre += tab[i]*tab[i];
    }
    return 2*somme_carre - 2* somme*somme;   //On en fait la somme avec les constantes calculées
}
