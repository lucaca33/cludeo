#ifndef CLUEDO
#define CLUEDO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Cartes{
    char nom[30];
    char type[10];
    struct Cartes* suivante;
    struct Cartes* precedente;
}Cartes;

typedef struct Joueur{
    char nom[30];
    Cartes* cartes;
    int val_des;
}Joueur;

Cartes* carte_coupable(Cartes * liste);
Cartes* melanger_cartes(Cartes * liste);

Joueur * rentrer_joueurs();

void lancer_des(Joueur * player);
void deplacement(Joueur * player);
void hypothese(Joueur * player1, Joueur * player2, Cartes * liste);
void accusation(Joueur * player);
void afficher_menu();
void afficher_plateau(Joueur * player);

#endif