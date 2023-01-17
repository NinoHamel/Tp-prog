#ifndef HEADER_TPNOTE
#define HEADER_TPNOTE

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define filenamePropre "../csv/airbnb_donnees_propre.csv"
#define filenameEntrainement "../csv/airbnbEntrainement.csv"
#define filenameTest "../csv/airbnbTest.csv"

typedef struct logement{
    float index;
    float accommodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;  
    float minimum_nights;
    float maximum_nights;
    float number_of_reviews;
    float distance[3];
} logement;

int find_length(char* filepath);

void read_csv(logement tab[], char* filepath);

void distance_logement(logement tab[], logement LogementX, int taille );   

void randomize(logement tab[], int taille);

void affichage(logement tab[], int taille);

void affichage_distances(logement tab[], int taille);

int partition_tri_tab(logement tab[],int low, int high, int type_tri);

// float mae(logement tab[], int a , int n);

// float fabs(float a);

void quicksort(logement tab[], int low, int high, int type_tri);

float moyenne(logement tab[], int k);


#endif