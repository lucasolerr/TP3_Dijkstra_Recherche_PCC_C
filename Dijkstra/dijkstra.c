#include "dijkstra.h"

int rechercheMinimum(pSommet* graphe, int sommetRecherche){
    pArc tempArc = graphe[sommetRecherche]->arc;
    int tempSommet = 0;
    while (tempArc != NULL){
        if(tempArc->valeur <= tempArc->arc_suivant->valeur ){
            tempSommet = tempArc->sommet;
        } else{
            tempSommet = tempArc->arc_suivant->sommet;
        }
        tempArc = tempArc->arc_suivant;
    }
    return tempSommet;
}

void actualiserPcc(pSommet* graphe, int sommetRecherche){
    pArc tempArc = graphe[sommetRecherche]->arc;
    while (tempArc != NULL){
        if(graphe[tempArc->sommet]->pcc < graphe[sommetRecherche]->pcc + tempArc->valeur){

        } else{
            graphe[tempArc->sommet]->pcc = graphe[sommetRecherche]->pcc + tempArc->valeur;
        }
        tempArc = tempArc->arc_suivant;
    }
}

int sommetsMarques(pSommet* graphe, int ordre){
    for (int i = 0; i < ordre; ++i) {
        if(graphe[i]->couleur == 0){
            return 1;
        }
    }
    return 0;
}

void dijkstra(pSommet* graphe, int ordre, int sommetInital, int sommetFinal){
    int parcours = sommetInital;
    int pccTotal = 0;
    for (int i = 0; i < ordre; ++i) {
        graphe[i]->couleur = 0;
        graphe[i]->pcc = -1;
    }

    graphe[parcours]->couleur = 1;
    graphe[parcours]->pcc = 0;

    while (sommetsMarques(graphe,ordre)){
        graphe[rechercheMinimum(graphe,parcours)]->predecesseur = parcours;
        parcours = rechercheMinimum(graphe,parcours);
        graphe[parcours]->couleur = 1;
        actualiserPcc(graphe,parcours);
    }
}