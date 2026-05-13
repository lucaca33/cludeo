#include "cluedo.h"

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

void liste_shuffle(cartes * liste[], int taille){
    int indice_utilises[50];
    cartes melange[50];
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
        mélange[i] = liste[indice];
    }
    liste = melange;
}
