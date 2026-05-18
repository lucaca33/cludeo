#include "cluedo.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8); // sortie UTF-8
    SetConsoleCP(CP_UTF8);       // entrée clavier UTF-8
    int nb_cartes = 0;
    int temps_sleep = 600; // en ms

    printf("====== Bienvenue dans cluedo\n");

    int rejouer = 0;
    do
    {
        int gagnant = 0; // 0 pour non et 1 pour oui

        int nb_joueurs = 0;
        Joueur *liste_joueurs = rentrer_joueurs(&nb_joueurs);

        Cartes *deck = init_deck(&nb_cartes); // on initialise tout le deck
        Cartes *deck_original = init_deck(&nb_cartes);

        rejouer = 0;
        int tour = 1;
        int choix = 0;
        while (gagnant == 0)
        {
            printf("=====\nTour n°%d\n", tour);
            for (int i = 0; i < nb_joueurs; i++)
            {
                tour_joueur(&liste_joueurs[i], temps_sleep, deck_original, nb_cartes, &choix);
            }
            gagnant = 1; // pas encore implémenté le systeme de gagnant donc c'est pour éviter les boucles infinies
        }
        printf("Partie terminée !\n");
        printf("Voulez-vous rejouer ? (0 pour non, 1 pour oui) : ");
        scanf("%d", &rejouer);
        printf("\n");
    } while (rejouer == 1);

    return 0;
}
