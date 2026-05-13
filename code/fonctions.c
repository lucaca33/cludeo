#include "cluedo.h"


Cartes * init_deck(){
    Cartes * deck = malloc(sizeof(Cartes)*22);
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

    strcpy(deck[6].nom, "Colonel Moutarde");
    strcpy(deck[6].type, "personnage");


    strcpy(deck[7].nom, "cuisine");
    strcpy(deck[7].type, "lieux");

    strcpy(deck[8].nom, "grand salon");
    strcpy(deck[8].type, "lieux");

    strcpy(deck[9].nom, "petit salon");
    strcpy(deck[9].type, "lieux");

    strcpy(deck[10].nom, "salle à manger");
    strcpy(deck[10].type, "lieux");

    strcpy(deck[11].nom, "cave");
    strcpy(deck[11].type, "lieux");

    strcpy(deck[12].nom, "bureau");
    strcpy(deck[12].type, "lieux");

    strcpy(deck[13].nom, "bibliothèque");
    strcpy(deck[13].type, "lieux");

    strcpy(deck[14].nom, "véranda");
    strcpy(deck[14].type, "lieux");

    strcpy(deck[15].nom, "hall");
    strcpy(deck[15].type, "lieux");

    strcpy(deck[16].nom, "studio");
    strcpy(deck[16].type, "lieux");


    strcpy(deck[17].nom, "chandelier");
    strcpy(deck[17].type, "arme");

    strcpy(deck[18].nom, "clef anglaise");
    strcpy(deck[18].type, "arme");

    strcpy(deck[19].nom, "corde");
    strcpy(deck[19].type, "arme");

    strcpy(deck[20].nom, "matraque");
    strcpy(deck[20].type, "arme");

    strcpy(deck[21].nom, "poignard ");
    strcpy(deck[21].type, "arme");

    strcpy(deck[22].nom, "revolver");
    strcpy(deck[22].type, "arme");
    return deck;
}

void lancer_des(Joueur * player)
{
    if(player == NULL)
    {
        return;
    }
    int nombre = 0;
    const int MIN = 2, MAX = 12;
    srand(time(NULL));
    nombre = (rand() % (MAX + 1 - MIN)) + MIN;
    printf("Vous avez obtenu %d\n", nombre);
    player->val_des = nombre;
}

Joueur * rentrer_joueurs(){
    printf("Combien de joueurs (humains) pour cette partie ? ");
    int nb_joueurs = 0;
    scanf("%d", &nb_joueurs);
    getchar();

    Joueur* joueurs = malloc(sizeof(Joueur)*nb_joueurs); // liste des joueurs de taille nb_joueurs    

    for (int i = 0; i < nb_joueurs; i++)
    {
        printf("Rentrez le nom du joueur  %d (max : 30 char) : ",i+1);
        fgets(joueurs[i].nom, 30, stdin); // on récupere le nom du n-ieme joueur
        joueurs[i].val_des = 0;
        // initialiser les cartes du joueur
        // pour l'instant je fait pas, a voir plus tard
    }
    return joueurs;
}

void liste_shuffle(Cartes * liste, int taille){
    int indice_utilises[50];
    Cartes melange[50];
    for(int i = 0;i < taille;i++){
        int indice;
        int verif = 0;
        while (verif == 0){
            const int MIN = 0, MAX = taille;
            srand(time(NULL));
            indice = (rand() % (MAX + 1 - MIN)) + MIN;
            verif = 1;
            for (int j = 0;j < i; j++){
                if(indice == indice_utilises[j]){
                    verif = 0;
                }
            }
        }
        indice_utilises[i] = indice;
        melange[i] = liste[indice];
    }

    //cher malo, on peut pas juste faire liste = melange 
    for (int i = 0; i < taille; i++)
    {
        liste[i] = melange[i];
    }
}
