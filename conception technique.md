Classe joueur :
  -  nom du joueur : char[30]
  -  cartes
  -  valeur du lancer de dés : int

Classe cartes : (liste chainé)
  -  nom
  -  type de cartes (pièce, arme, joueur)
  -  suivante
  -  précedente

il faut mélanger les cartes / prendre au pif des cartes :
  -  on en stocke 3 dans un "coffre" qu'on enlève du reste des cartes
  -  on distribue le reste aux joueurs


DÉREOULLEMENT DU JEU :
boucle principale
  -  on demande combien de joueurs (humains)
  -  on leur demande leur noms
  -  on demande si y'a des bots
  -  leur difficultés
  -  mélanger / distribuer cartes
  -  boucle de jeu
  -    -    lancer de dés
       -    déplacement
       -    si une pièce est atteinte : témoignage / accusation
       -    si accusation est bonne : fin du jeu, sinon on révèle les cartes du joueur et la partie continue pour le reste des joueurs. si il ne reste que des bots en jeu les humains on perdus
  -  message de fin
  -  demande si joueur veut rejouer ( on repart en début de boucle principale )
  -  libérer les variables alloués en malloc


fonctions :
  - carte_coupable(cartes * liste) : sauvegarde 3 cartes aléatoire pour la combinaison secrète de type différents et les retire de la liste principale
  - melanger_cartes(cartes * liste) : création  d'une autre liste + prendre les indices aléatoire et placer les cartes de la première liste suivant l'indice dans la deuxième
  - lancer_des(joueur * player) : augmente la valeur de dé du joueur afin de réaliser un déplacement ( entre 2 et 12)
  - deplacement(joueur * player) : affiche une liste de pièce où le joueur peut aller et le déplace selon son choix
  - hypothese(joueur * player, cartes * liste) : le joueur établit une hypothèse et vérifie 
