#include "ordonnanceurs.h"

ordonnanceur init_ord(ordonnanceur ord){

    ord.nbProcessus = 0;

    for (int i = 0; i < 100; i++){

        strcpy(ord.liste[i].nom,"minus_1");// on remplit l'ordonnanceur avec des processus placeholder
        ord.liste[i].duree = -1;
        ord.liste[i].priorite = -1;
        
    }
    
    return ord;

}

ordonnanceur ajout_activite(ordonnanceur ord){

    processus new_process;

    printf("Entrez le nom du processus : \n");
    scanf("%s",new_process.nom);

    printf("Entrez la duree du processus : \n");
    scanf("%d",&new_process.duree);

    printf("Entrez la priorite du processus : \n");
    scanf("%d",&new_process.priorite);

    for(int i=0; i<100;i++){// on parcourt chaque case de l'ordonnanceur à la recherche d'une case libre
        
        if(strcmp(ord.liste[i].nom,"minus_1")==0){//si on trouve une case libre, on entre les informations du nouveau processus
            
            ord.nbProcessus += 1;
            ord.liste[i] = new_process;

            return ord;
        }

    }

    printf("\nFile pleine"); // si on n'a pas trouvé de case libre, on ne rentrera pas dans le if et on ne retournera rien
    exit(EXIT_FAILURE);//on met fin à l'éxécution du programme

}

ordonnanceur step(ordonnanceur ord){

    if(ord.nbProcessus == 0){//si l'ordonnanceur est vide
        printf("La file est vide\n");
        return ord;
    }
    else{

        printf("Nom : %s, duree : %d \nExecution en cours. . . \n",ord.liste[0].nom,ord.liste[0].duree);
        sleep(ord.liste[0].duree);

        //on actualise l'ordonnanceur   
        ord.nbProcessus--;

        for(int i=0; i<99; i++){
            
            ord.liste[i] = ord.liste[i+1];//on recule chaque processus d'une case

        }

        strcpy(ord.liste[99].nom,"minus_1");//on remplit la case laissée vide par un nouveau processus placeholder
        ord.liste[99].duree = -1;
        ord.liste[99].priorite = -1;

        return ord; 

    }

}

ordonnanceur run(ordonnanceur ord){

    int nbTours = ord.nbProcessus;//on éxécutera cette fonction le même nombre de fois qu'il y a de processus dans l'ordonnanceur

    for(int i = 0; i<=nbTours; i++){//on fait un tour de plus pour indiquer que la file est vide
        ord = step(ord);
    }

    return ord;

}