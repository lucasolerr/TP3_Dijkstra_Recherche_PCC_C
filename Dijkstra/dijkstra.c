#include "dijkstra.h"

int rechercheMinimum(int n1 , int n2){
    int tempMin = n1;
    if(n2 < n1){
        tempMin = n2;
    }
    return tempMin ;
}

void dijkstra(pSommet* graphe, int ordre, int sommetInital, int sommetFinal){

    for (int i = 0; i < ordre; ++i) {
        graphe[i]->couleur = 0;
        graphe[i]->pcc = -1;
    }

    graphe[sommetInital]->couleur = 1;
    graphe[sommetInital]->pcc = 0;



}