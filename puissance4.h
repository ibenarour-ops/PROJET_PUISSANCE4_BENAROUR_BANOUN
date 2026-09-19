#ifndef PUISSANCE4_H
 #define PUISSANCE4_H
 void afficherRegles(void);//y aura pas de retour
 int colonneValide(int colonne);//type de retour:int
 int demanderColonne(void);//type de retour:int
void changerJoueur(int *joueur);
 void jouerPrototype(void);//y aura pas de retour
 int colonneValide(int colonne);
 int demanderColonne(void);
void changerJoueur(int *joueur);
 void jouerPrototype(void);
 
 void jouerTour(int *joueurCourant,int *nombreCoups);
#endif