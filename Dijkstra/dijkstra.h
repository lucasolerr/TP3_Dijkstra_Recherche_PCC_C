#ifndef TP3_DIJKSTRA_RECHERCHE_PCC_C_DIJKSTRA_H
#define TP3_DIJKSTRA_RECHERCHE_PCC_C_DIJKSTRA_H

#include "../Graphe/Graphe.h"


void dijkstra(pSommet* graphe, int ordre, int sommetInital, int sommetFinal);

int sommetsMarques(pSommet* graphe, int ordre);

int rechercheMinimum(pSommet* graphe, int ordre);

void actualiserPcc(pSommet* graphe, int sommetRecherche, int sommetSuccesseur);

void affichagePcc(pSommet* graphe, int ordre, int sommetInitial, int sommetFinal);

#endif
