#include "cluedo.h"

int main(){
    SetConsoleOutputCP(CP_UTF8); // passer en utf 8 pour avoir les accents

    printf("====== Bienvenue dans cluedo\n");
    
    int nb_joueurs = 0;
    Joueur *liste_joueurs = rentrer_joueurs(&nb_joueurs);

    Cartes * deck = init_deck(); // on initialise tout le deck
    
    int gagnant = 0;// 0 pour non et 1 pour oui

    int tour = 1;
    while (gagnant == 0)
    {
        printf("=====\nTour n°%d=====\n", tour);
        for (int i = 0; i < nb_joueurs; i++)
        {
            printf("Au tour %s de jouer \n\n", liste_joueurs[i].nom);
            lancer_des(&liste_joueurs[i]);
            if (liste_joueurs[i].val_des >= 10)
            {
                liste_joueurs[i].val_des = 0;
                printf("Vous avez un score de dés d'au moins 10, vous pouvez aller dans les pièces suivantes : \n");
                afficher_plateau();
            }
            else{
                printf("Vous n'avez pas un assez bon score de dés :\nVotre score ! %d\nScore minimum pour se déplacer : 10", liste_joueurs[i].val_des);
            }
        }
        gagnant = 1; // pas encore implémenté le systeme de gagnant donc pour éviter les boucles infinies
    }
    


    return 0;
}
