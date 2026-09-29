#include "puissance4.h"
#include <stdio.h>
void afficherRegles(void){
    printf("--------PUISSANCE4---------\n");
    printf("Alignez quatre jetons horizontalement, verticalement ou en diagonale.\n");
    printf("Les colonnes sont numerotees de 1 a 7.");
}
//Étape 4
int colonneValide(int colonne){
    return (colonne >= 0 && colonne <= NB_COLONNES-1);
}
//Étape 5
int demanderColonne(void){
    int colonne;
    printf("Choisissez une colonne 1-7 : ");
    scanf("%d", &colonne);
    colonne=colonne-1;
    while(colonneValide(colonne) == 0){
        printf("Colonne invalide. Choisissez une colonne (1-7) : ");
        scanf("%d", &colonne);
        colonne=colonne-1;
    }
    return colonne;
}
//Étape 6 
void changerJoueur(int *joueur){
    if(*joueur == 1){
        *joueur= 2;
    }
    else{
        *joueur= 1;
    }
}
int colonneLibre(int grille[][NB_COLONNES],int colonne){
    return (grille[0][colonne] == VIDE);
}

void initialiserGrille(int grille[NB_LIGNES][NB_COLONNES])
{
    for (int i = 0; i < NB_LIGNES; i++)
    {
       for (int j = 0; j < NB_COLONNES; j++)
       {
         grille[i][j]=VIDE;
       }
       
    }
}
void afficherGrille( int grille[NB_LIGNES][NB_COLONNES])
{
    char c;
     for (int i = 0; i < NB_LIGNES; i++)
    {
       for (int j = 0; j < NB_COLONNES; j++)
       {
        if (grille[i][j] == 1){
           c='x'; 
        }
        else if (grille[i][j] == 2) {
            c='O';
        }
        else {
            c='.';
        }
         printf("grille[%d][%d]=%c\n",i,j,c);
       }
       
    }
}

int placerJeton(int grille[][NB_COLONNES], int colonne, int joueur){
    int ligne = NB_LIGNES - 1;
    while(ligne >= 0 && grille[ligne][colonne] != VIDE){
        ligne--;
    }
    if(ligne < 0){
        return 0;
    }
    grille[ligne][colonne] = joueur;
    return 1;
}

int alignementHorizontal(int grille[][NB_COLONNES], int joueur){
    int i, j;
    for(i = 0; i < NB_LIGNES; i++){
        for(j = 0; j <= NB_COLONNES - 4; j++){
            if(grille[i][j] == joueur && grille[i][j+1] == joueur &&
               grille[i][j+2] == joueur && grille[i][j+3] == joueur){
                return 1;
            }
        }
    }
    return 0;
}

int alignementVertical(int grille[][NB_COLONNES], int joueur){
    int i, j;
    for(j = 0; j < NB_COLONNES; j++){
        for(i = 0; i <= NB_LIGNES - 4; i++){
            if(grille[i][j] == joueur && grille[i+1][j] == joueur &&
               grille[i+2][j] == joueur && grille[i+3][j] == joueur){
                return 1;
            }
        }
    }
    return 0;
}

int alignementDiagonal(int grille[][NB_COLONNES], int joueur){
    int i, j;
    for(i = 0; i <= NB_LIGNES - 4; i++){
        for(j = 0; j <= NB_COLONNES - 4; j++){
            if(grille[i][j] == joueur && grille[i+1][j+1] == joueur &&
               grille[i+2][j+2] == joueur && grille[i+3][j+3] == joueur){
                return 1;
            }
        }
    }
    for(i = 0; i <= NB_LIGNES - 4; i++){
        for(j = 3; j < NB_COLONNES; j++){
            if(grille[i][j] == joueur && grille[i+1][j-1] == joueur &&
               grille[i+2][j-2] == joueur && grille[i+3][j-3] == joueur){
                return 1;
            }
        }
    }
    return 0;
}

int joueurAGagne(int grille[][NB_COLONNES], int joueur){
    return (alignementHorizontal(grille, joueur) ||
            alignementVertical(grille, joueur) ||
            alignementDiagonal(grille, joueur));
}

int grillePleine(int grille[][NB_COLONNES]){
    int j;
    for(j = 0; j < NB_COLONNES; j++){
        if(colonneLibre(grille, j)){
            return 0;
        }
    }
    return 1;
}

void jouerTour(int grille[][NB_COLONNES], int *joueurCourant, int *nombreCoups){
    int colonne;

    printf("Tour du joueur %d\n", *joueurCourant);

    colonne = demanderColonne();
    while(colonneLibre(grille, colonne) == 0){
        printf("Colonne pleine. Choisissez une autre colonne.\n");
        colonne = demanderColonne();
    }

    placerJeton(grille, colonne, *joueurCourant);
    afficherGrille(grille);
    (*nombreCoups)++;
}
void jouerPrototype(void){
    int grille[NB_LIGNES][NB_COLONNES];
    int joueurCourant = 1;
    int nombreCoups = 0;
    int gagne = 0;

    initialiserGrille(grille);
    afficherGrille(grille);

    while(gagne == 0 && grillePleine(grille) == 0){
        jouerTour(grille, &joueurCourant, &nombreCoups);
        gagne = joueurAGagne(grille, joueurCourant);

        if(gagne == 1){
            printf("Le joueur %d a gagne !\n", joueurCourant);
        }
        else if(grillePleine(grille) == 1){
            printf("Match nul.\n");
        }
        else{
            changerJoueur(&joueurCourant);
        }
    }
}
