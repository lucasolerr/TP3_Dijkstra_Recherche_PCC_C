#include "dijkstra.h"



int rechercherMinimum(pSommet* graphe, int ordre){
    int tempPoids = 1000;
    int tempSommet = -1;
    for (int i = 0; i < ordre; i++) {
        if(graphe[i]->pccTotal < tempPoids && graphe[i]->pccTotal != -1 && graphe[i]->couleur != 1){
            tempPoids = graphe[i]->pccTotal;
            tempSommet = i;
        }
    }

    return tempSommet;
}

int sommetsMarques(pSommet* graphe, int ordre){
    //Boucle parcourant tous les sommets
    for (int i = 0; i < ordre; i++) {
        //Si un sommet est non marqué
        if(graphe[i]->couleur == 0){
            //Retour de 1
            return 1;
        }
    }
    //Si tous les sommets sont marqués retour de 0
    return 0;
}

void actualiserPccSuccesseurs(pSommet* graphe, int ordre, int sommetPredeccesseur){
    pArc tempArc = graphe[sommetPredeccesseur]->arc;

    while (tempArc != NULL){
        if(graphe[tempArc->sommet]->pccTotal == -1){
            graphe[tempArc->sommet]->pccTotal = graphe[sommetPredeccesseur]->pccTotal + tempArc->valeur;
            graphe[tempArc->sommet]->predecesseur = sommetPredeccesseur;

        } else {
            if(graphe[tempArc->sommet]->pccTotal < graphe[sommetPredeccesseur]->pccTotal + tempArc->valeur){
                //Rien
            } else{
                //Sinon on effectue une Mise à Jour du pccTotal (case en orange dans le tableau),
                //un chemin plus court existe depuis sommetRecherche
                graphe[tempArc->sommet]->pccTotal = graphe[sommetPredeccesseur]->pccTotal + tempArc->valeur;
                graphe[tempArc->sommet]->predecesseur = sommetPredeccesseur;
            }
        }



        tempArc = tempArc->arc_suivant;
    }

}

void dijkstra(pSommet* graphe, int ordre, int sommetInital, int sommetFinal){
    //On effectue le parcours depuis le sommet Initial
    int parcours = sommetInital;
    int pccTotal = 0;

    //Boucle parcourant tous les sommets
    for (int i = 0; i < ordre; i++) {
        //Pour chaque sommet, il n'est pas marqué
        graphe[i]->couleur = 0;
        //Son calcul de chemin est équivalent à 0
        graphe[i]->pccTotal = -1;
    }

    //Nous marquons le sommet initial
    graphe[parcours]->couleur = 1;
    //Son chemin le plus cours vers lui-même est donc 0
    graphe[parcours]->pccTotal = 0;

    printf("Liste de decouverte : ");

    //Tant qu'il reste des sommets non marqués
    while (sommetsMarques(graphe, ordre)){

        actualiserPccSuccesseurs(graphe, ordre, parcours);

        parcours = rechercherMinimum(graphe, ordre);

        printf("%d ", parcours);

        graphe[parcours]->couleur = 1;

    }

    printf("\n");

    affichagePcc(graphe, ordre, sommetInital, sommetFinal);
}

void affichagePcc(pSommet* graphe, int ordre, int sommetInitial, int sommetFinal){
    printf("Le PCC entre %d et %d a pour valeur : %d", sommetInitial, sommetFinal, graphe[sommetFinal]->pccTotal);
    int tempCompteur = 0;
    //Si le sommet en question n'a pas déjà de prédécesseur alors

    //on met un temporaire à la valeur de ce sommet
    int tempPred = sommetFinal;

    //on l'affiche
    printf("\n%d", tempPred);

    //Fonction récursive qui permet de parcourir les prédécesseurs de ce sommet
    //Tant que le prédécesseur est != du sommet initial
    while (tempPred != sommetInitial) {
        //le temporaire prend la valeur du prédécesseur du n-1 sommet
        tempCompteur++;
        tempPred = graphe[tempPred]->predecesseur;
        //on affiche ce prédécesseur
        printf(" <-- %d", tempPred);
    }
    //on saute un ligne entre chaque branche de l'arborescence
    printf("\n");

    printf("Longueur du parcours : %d\n", tempCompteur);



}