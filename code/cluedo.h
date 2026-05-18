#ifndef CLUEDO
#define CLUEDO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> // pour l'utf8 et sleep

typedef struct Cartes{
    char nom[30];
    char type[10];
}Cartes;

typedef struct Joueur{
    char nom[30];
    Cartes* cartes;
    int val_des;
}Joueur;

Cartes* carte_coupable(Cartes * liste);
Cartes* melanger_cartes(Cartes * liste);
Cartes * init_deck(int * nb_cartes);

Joueur * rentrer_joueurs(int * nb);
Joueur * elimination(Joueur * player);

void lancer_des(Joueur * player);
void deplacement(Joueur * player);
void hypothese(Joueur * player1, Joueur * player2, Cartes * liste);
int accusation(Joueur * player,Cartes * reponse, int nombre_carte);
void afficher_plateau(Cartes * deck_original, int nb_cartes);
void liste_shuffle(Cartes * liste, int taille);
void tour_joueur(Joueur* joueur, int time_sleep, Cartes * deck_original, int nb_cartes, int * choix);

void afficher_menu();

#endif
