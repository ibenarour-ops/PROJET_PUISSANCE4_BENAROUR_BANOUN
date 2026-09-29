#ifndef PUISSANCE4_H
 #define PUISSANCE4_H
 #define NB_LIGNES 6
#define NB_COLONNES 7
#define VIDE 0
 void afficherRegles(void);//y aura pas de retour
 int colonneValide(int colonne);//type de retour:int
 int demanderColonne(void);//type de retour:int
void changerJoueur(int *joueur);
void initialiserGrille(int grille[][NB_COLONNES]);
void afficherGrille(int grille[][NB_COLONNES]);
int colonneLibre(int grille[][NB_COLONNES], int colonne);
int placerJeton(int grille[][NB_COLONNES], int colonne, int joueur);
int alignementHorizontal(int grille[][NB_COLONNES], int joueur);
int alignementVertical(int grille[][NB_COLONNES], int joueur);
int alignementDiagonal(int grille[][NB_COLONNES], int joueur);
int joueurAGagne(int grille[][NB_COLONNES], int joueur);
int grillePleine(int grille[][NB_COLONNES]);
void jouerTour(int grille[][NB_COLONNES], int *joueurCourant, int *nombreCoups);
void jouerPrototype(void);

#endif
