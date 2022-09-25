#include "dijkstra.h"



int rechercherMinimum(pSommet* graphe, int ordre){
    //Création d'un temporaire qui servira de pivot la comparaison du minimum
    int tempPoids = 1000;
    //Création d'un temporaire qui stockera la valeur du sommet ayant le plus petit pccTotal
    int tempSommet = -1;
    //Boucle parcourant tous les sommets
    for (int i = 0; i < ordre; i++) {
        //Si le sommet i a le pccTotal le plus petit et qu'il n'est pas déjà marqué
        if(graphe[i]->pccTotal < tempPoids && graphe[i]->pccTotal != -1 && graphe[i]->couleur != 1){
            //Le pivot prend son pccTotal
            tempPoids = graphe[i]->pccTotal;
            //tempSommet prend la valeur de i
            tempSommet = i;
        }
    }

    //Retour du sommet ayant le plus petit pccTotal
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
    //Création d'un temporaire qui a la valeur du premier successeur
    pArc tempArc = graphe[sommetPredeccesseur]->arc;

    //Tant qu'il reste des successeurs
    while (tempArc != NULL){
        //Si le successeur n'a jamais été découvert
        if(graphe[tempArc->sommet]->pccTotal == -1){
            //On met à jour son pccTotal
            graphe[tempArc->sommet]->pccTotal = graphe[sommetPredeccesseur]->pccTotal + tempArc->valeur;
            //On actualise son prédecesseur
            graphe[tempArc->sommet]->predecesseur = sommetPredeccesseur;

        } else {
            //Si le successeur a déjà été découvert et qu'il a déjà un chemin plus court
            if(graphe[tempArc->sommet]->pccTotal < graphe[sommetPredeccesseur]->pccTotal + tempArc->valeur){
                //Rien
            } else{
                //Sinon on effectue une Mise à Jour du pccTotal (case en orange dans le tableau),
                //un chemin plus court existe depuis sommetRecherche
                graphe[tempArc->sommet]->pccTotal = graphe[sommetPredeccesseur]->pccTotal + tempArc->valeur;
                graphe[tempArc->sommet]->predecesseur = sommetPredeccesseur;
            }
        }


        //On passe au successeur suivant
        tempArc = tempArc->arc_suivant;
    }

}

void dijkstra(pSommet* graphe, int ordre, int sommetInital, int sommetFinal){
    //On effectue le parcours depuis le sommet Initial
    int parcours = sommetInital;

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

    //Tant qu'il reste des sommets non marqués
    while (sommetsMarques(graphe, ordre)){

        //On actualise les pccTotaux des successeurs de parcours
        actualiserPccSuccesseurs(graphe, ordre, parcours);

        //Parcours prend la valeur du sommet déjà découvert ayant le pccTotal le plus petit
        parcours = rechercherMinimum(graphe, ordre);

        //On marque parcours, son pcc est donc connu
        graphe[parcours]->couleur = 1;

    }


    //On affiche les informations de l'exercice
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
    //on saute une ligne entre chaque branche de l'arborescence
    printf("\n");

    //on affiche la longueur du parcours (nombre de sommets devant être parcouru)
    printf("Longueur du parcours : %d\n", tempCompteur);
}