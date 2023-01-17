#ifndef HEADER_ORDONNANCEURS
#define HEADER_ORDONNANCEURS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct processus{
    char nom[30];
    int duree;
    int priorite;
}processus;

typedef struct ordonnanceur{

    int nbProcessus;
    processus liste[100];
}ordonnanceur;

ordonnanceur init_ord(ordonnanceur ord);
ordonnanceur ajout_activite(ordonnanceur ord);
ordonnanceur step(ordonnanceur ord);
ordonnanceur run(ordonnanceur ord);

#endif