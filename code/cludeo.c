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
        printf("Combien de joueurs voulez vous ? : \n");
        scanf("%d",&nb_joueurs);
        Joueur *liste_joueurs = rentrer_joueurs(&nb_joueurs);

        Cartes *deck = init_deck(&nb_cartes); // on initialise tout le deck
        Cartes *deck_original = init_deck(&nb_cartes);
        Cartes *liste_crime = carte_coupable(deck); // on initialise la liste de cartes du crime

        // il manque à enlever les cartes du crime de la liste principale, je dois modifier ma fonction carte_coupables

        liste_shuffle(deck_original,21); // on melange la liste de cartes, 21 pour les 21 cartes en comptant les coupables
        distrib(deck_original,liste_joueurs,nb_joueurs); //on distribue les cartes à chaque joueurs

        rejouer = 0;
        int tour = 1;
        int choix_lieux = 0; // a utiliser pour la fonction deplacement je pense
        int choix_action = 0;
        while (gagnant == 0)
        {
            printf("=====\nTour n°%d\n", tour);
            for (int i = 0; i < nb_joueurs; i++)
            {
                tour_joueur(&liste_joueurs[i], temps_sleep, deck_original, nb_cartes, &choix_lieux);
                scanf("%d",&choix_lieux);
                printf("Choisissez votre action : \n");
                printf("1 : essayer votre hypothèse dans la pièce courante\n");
                printf("2 : tenter une accusation finale\n");
                printf("3 : passer votre tour\n");
                scanf("%d",&choix_action);
                switch (choix_action)
                {
                case 1:
                    hypothese(&liste_joueurs[i],&liste_joueurs,deck_original); // établit une hypothèse
                
                case 2:
                    gagnant = accusation(&liste_joueurs[i], liste_crime, &nb_cartes); // je pense que nb_cartes n'est pas nécessaire, a voir pour celui qui a fais la fonction
                
                case 3:
                    gagnant = 0;
                }

            }
        }
        printf("Partie terminée !\n");
        printf("Voulez-vous rejouer ? (0 pour non, 1 pour oui) : ");
        scanf("%d", &rejouer);
        printf("\n");
    } while (rejouer == 1);

    return 0;
}
