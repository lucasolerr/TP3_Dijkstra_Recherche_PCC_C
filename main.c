#include "stdio.h"
#include "Graphe/Graphe.h"



int main() {
    Graphe* g = lire_graphe("../binaries/graphe1_TP3.txt");
    int sommetInitial, sommetFinal;

    //saisie du numéro du sommet initial pour lancer un parcours
    printf("Sommet initial pour commencer le calcul du PCC :\n");
    scanf(" %d", &sommetInitial);

    //saisie du numéro du sommet final pour lancer un parcours
    printf("Sommet final pour calculer le PCC :\n");
    scanf(" %d", &sommetFinal);

    //afficher le graphe
    graphe_afficher(g);



    return 0;
}