#include "cluedo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lancer_des(Joueur * player)
{
    if(player == NULL)
    {
        return NULL;
    }
    int nombre = 0;
    const int MIN = 2, MAX = 12;
    srand(time(NULL));
    nombre = (rand() % (MAX + 1 - MIN)) + MIN;
    printf("Vous avez obtenu %d\n", nombre);
    player->val_des = nombre;
}
