#include "cluedo.h"

Cartes *init_deck(int *nb_cartes)
{
    Cartes *deck = malloc(sizeof(Cartes) * 22);
    strcpy(deck[0].nom, "Colonel Moutarde");
    strcpy(deck[0].type, "personnage");

    strcpy(deck[1].nom, "Madame Pervenche");
    strcpy(deck[1].type, "personnage");

    strcpy(deck[2].nom, "Mademoiselle Rose");
    strcpy(deck[2].type, "personnage");

    strcpy(deck[3].nom, "Professeur Violet");
    strcpy(deck[3].type, "personnage");

    strcpy(deck[4].nom, "Docteur Orchidée");
    strcpy(deck[4].type, "personnage");

    strcpy(deck[5].nom, "Monsieur Olive");
    strcpy(deck[5].type, "personnage");

    strcpy(deck[6].nom, "cuisine");
    strcpy(deck[6].type, "lieux");

    strcpy(deck[7].nom, "grand salon");
    strcpy(deck[7].type, "lieux");

    strcpy(deck[8].nom, "petit salon");
    strcpy(deck[8].type, "lieux");

    strcpy(deck[9].nom, "salle à manger");
    strcpy(deck[9].type, "lieux");

    strcpy(deck[10].nom, "bureau");
    strcpy(deck[10].type, "lieux");

    strcpy(deck[11].nom, "bibliothèque");
    strcpy(deck[11].type, "lieux");

    strcpy(deck[12].nom, "véranda");
    strcpy(deck[12].type, "lieux");

    strcpy(deck[13].nom, "hall");
    strcpy(deck[13].type, "lieux");

    strcpy(deck[14].nom, "studio");
    strcpy(deck[14].type, "lieux");

    strcpy(deck[15].nom, "chandelier");
    strcpy(deck[15].type, "arme");

    strcpy(deck[16].nom, "clef anglaise");
    strcpy(deck[16].type, "arme");

    strcpy(deck[17].nom, "corde");
    strcpy(deck[17].type, "arme");

    strcpy(deck[18].nom, "matraque");
    strcpy(deck[18].type, "arme");

    strcpy(deck[19].nom, "poignard ");
    strcpy(deck[19].type, "arme");

    strcpy(deck[20].nom, "revolver");
    strcpy(deck[20].type, "arme");

    *nb_cartes = 21;
    return deck;
}

void lancer_des(Joueur *player)
{
    if (player == NULL)
    {
        return;
    }
    int nombre = 0;
    const int MIN = 2, MAX = 12;
    srand(time(NULL));
    nombre = (rand() % (MAX + 1 - MIN)) + MIN;
    printf("Vous avez obtenu %d\n", nombre);
    player->val_des += nombre;
}

Joueur *rentrer_joueurs(int *nb)
{
    printf("Combien de joueurs (humains) pour cette partie ? ");
    scanf("%d", nb);
    getchar();

    Joueur *joueurs = malloc(sizeof(Joueur) * (*nb)); // liste des joueurs de taille nb_joueurs

    for (int i = 0; i < (*nb); i++)
    {
        printf("Rentrez le nom du joueur  %d (max : 30 char) : ", i + 1);
        fgets(joueurs[i].nom, 30, stdin); // on récupere le nom du n-ieme joueur
        if (strchr(joueurs[i].nom, '\n') == NULL)
        {
            // entrée trop longue -> vider le buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        else
        {
            // enlever le '\n'
            joueurs[i].nom[strcspn(joueurs[i].nom, "\n")] = '\0';
        }
        joueurs[i].val_des = 0;
        // initialiser les cartes du joueur
        // pour l'instant je fait pas, a voir plus tard
    }
    return joueurs;
}

void liste_shuffle(Cartes *liste, int taille)
{
    int indice_utilises[50];
    Cartes melange[50];
    for (int i = 0; i < taille; i++)
    {
        int indice;
        int verif = 0;
        while (verif == 0)
        {
            const int MIN = 0, MAX = taille;
            srand(time(NULL));
            indice = (rand() % (MAX + 1 - MIN)) + MIN;
            verif = 1;
            for (int j = 0; j < i; j++)
            {
                if (indice == indice_utilises[j])
                {
                    verif = 0;
                }
            }
        }
        indice_utilises[i] = indice;
        melange[i] = liste[indice];
    }

    // cher malo, on peut pas juste faire liste = melange
    for (int i = 0; i < taille; i++)
    {
        liste[i] = melange[i];
    }
}

Cartes *carte_coupable(Cartes *liste)
{
    Cartes *liste_coupable = malloc(sizeof(Cartes) * 3);
    int indice = 0;
    int MIN = 0, MAX = 5;
    srand(time(NULL));
    indice = (rand() % (MAX + 1 - MIN)) + MIN;
    liste_coupable[0] = liste[indice]; // pour le personnage coupable

    MIN = 6, MAX = 15;
    srand(time(NULL));
    indice = (rand() % (MAX + 1 - MIN)) + MIN;
    liste_coupable[1] = liste[indice]; // pour le lieux du crime

    MIN = 16, MAX = 21;
    srand(time(NULL));
    indice = (rand() % (MAX + 1 - MIN)) + MIN;
    liste_coupable[2] = liste[indice]; // pour l'arme du crime

    return liste_coupable;
}

int accusation(Joueur *player, Cartes *reponse, int nombre_carte)
{
    // on peut que accuser dans la pièce dans la quelle on est donc faudras changer vite fait
    char meutrier[50];
    char arme[50];
    char lieu[50];
    printf("\n Qui souhaitez vous accuser?");
    scanf("%s", &meutrier);
    printf("\n Quelle est l'arme du crime?");
    scanf("%s", &arme);
    printf("\n Ou le crime a t il ete commis");
    scanf("%s", &lieu);
    if (meutrier == reponse[0].nom && arme == reponse[1].nom && lieu == reponse[2].nom)
    {
        printf("BONNE REPONSE.\n %s a donc ete arrete et passera le restant de ses jours en prison \n%s a gagne.", reponse[0].nom, player->nom);
        return 1;
    }
    else
    {
        printf("C'est une mauvaise reponse. \n %s est donc elimine.", player->nom);
        return 0;
    }
}

Joueur *elimination(Joueur *player)
{
    if (player == NULL)
    {
        return NULL;
    }
    printf("\n Le joueur %s possedait : ", player->nom);
    for (int i = 0; i < sizeof(player->cartes); i++)
    {
        if (player->cartes[i].type == "lieux")
        {
            printf("\n Le lieux %s", player->cartes[i].nom);
        }
        if (player->cartes[i].type == "arme")
        {
            printf("\n L'arme' %s", player->cartes[i].nom);
        }
        else
        {
            printf("\n Le suspect %s", player->cartes[i].nom);
        }
    }
    free(player->cartes);
    player->cartes = NULL;
    free(player);
    player = NULL;
}

void afficher_plateau(Cartes *deck_original, int nb_cartes)
{

    if (deck_original == NULL)
    {
        return;
    }

    int k = 0;
    for (int i = 0; i < nb_cartes; i++)
    {
        if (!strcmp(deck_original[i].type, "lieux")) // si le type de la carte est un lieux
        {
            k++;
            printf("%d : %s\n", k, deck_original[i].nom);
        }
    }

    printf("Rentrer le numero du lieu ou vous voulez aller : ");

    return;
}

void distrib(Cartes *liste_melange, Joueur *liste_joueurs, int nombre_joueurs)
{
    int joueur;
    for (int i = 1; i <= 18; i++)
    {
        int position = (i - 1) / nombre_joueurs;
        if ((i - 1) < nombre_joueurs)
        {
            int joueur = (nombre_joueurs % i) - 1;
        }
        else
        {
            int joueur = (i - 1) % nombre_joueurs;
        }
        liste_joueurs[joueur].cartes[position] = liste_melange[i];
    }
}

void tour_joueur(Joueur* joueur, int time_sleep, Cartes * deck_original, int nb_cartes, int * choix)
{

    printf("================\n");
    printf("Au tour %s de jouer \n\n", joueur->nom);
    Sleep(time_sleep);
    lancer_des(&time_sleep);
    Sleep(time_sleep);
    if (joueur->val_des >= 10)
    {
        joueur->val_des = 0;
        printf("Vous avez un score de dés d'au moins 10, vous pouvez aller dans les pièces suivantes : \n");
        Sleep(time_sleep);
        afficher_plateau(deck_original, nb_cartes);
        scanf("%d", &choix);
    }
    else
    {
        printf("Vous n'avez pas un assez bon score de dés !\nVotre score : %d\nScore minimum pour se déplacer : 10\n", joueur->val_des);
    }
    Sleep(time_sleep * 2);
}


void hypothèse(Joueur * player, Joueur * liste_player, int indice_lieu)
{
    if(player == NULL)
    {
        return;
    }
    char lieux[50];
    char meurtrier[50];
    char arme[50];
    int indice;
    if(indice_lieu == 1)
    {
        strcpy(lieux,"cuisine");
    } 
    else if(indice_lieu == 2)
    {
        strcpy(lieux,"grand salon");
    }
    else if(indice_lieu == 3)
    {
        strcpy(lieux,"petit salon");
    }
    else if(indice_lieu == 4)
    {
        strcpy(lieux,"salle à manger");
    }
    else if(indice_lieu == 5)
    {
        strcpy(lieux,"bureau");
    }
    else if(indice_lieu == 6)
    {
        strcpy(lieux,"bibliothèque");
    }
    else if(indice_lieu == 7)
    {
        strcpy(lieux,"véranda");
    }
    else if(indice_lieu == 8)
    {
        strcpy(lieux,"hall");
    }
    else
    {
        strcpy(lieux,"studio");
    }
    printf("\n Sur qui vous avez des soupcons ?");
    scanf("%s",&meurtrier);
    printf("\n Quelle arme de l'hypothese ?");
    scanf("%s",&arme);
    printf("\n Quel joueur interroger ?");
    scanf("%d",&indice);
    Cartes * test;
    for(int i = 0; i < sizeof(liste_player[indice].cartes); i++)
    {
        if(liste_player[indice].cartes[i].nom == (lieux || meurtrier || arme))
        {
            test[i] = liste_player[indice].cartes[i];
        }
    }

    int nombre;
    int max = sizeof(test);
    int min = 0;
    srand(time(NULL));
    nombre = (rand() % (max + 1 - min)) + min;
    printf("Le joueur %d vous montre la carte %s",indice,test[nombre]);
}
