#include "ordonnanceurs.h"

int main(int argc, char const *argv[]){

    ordonnanceur ord; char rep; int nb_act;

    ord = init_ord(ord); //initialisation de l'ordonnanceur avec des valeurs "vides"

    printf("Voulez vous ajouter une activite ? y/n\n");
    scanf("%c",&rep);

    if(rep == 'y'){

        printf("Entrez le nombre d'activite que vous voulez ajouter\n");
        scanf("%d",&nb_act);

        for(int i=0; i<nb_act; i++){
            ord = ajout_activite(ord);
        }

    }

    ord = run(ord);

    return 0;
}
