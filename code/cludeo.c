#include "cluedo.h"

int main(){
    SetConsoleOutputCP(CP_UTF8); // passer en utf 8 pour avoir les accents

    Cartes * deck = init_deck();

    printf("%s %s", deck[4].nom, deck[4].type);

    return 0;
}
