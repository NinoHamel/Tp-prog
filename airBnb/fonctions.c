#include "tpnote.h"

int find_length(char* filepath){

    int nbLogements = -1; //-1 car il y a la première ligne du document

	FILE *fileStream;
	fileStream = fopen(filepath, "r");
	if(!fileStream){
		printf("Erreur d'ouverture du fichier");
	}else{ 

        char buffer[1024];

        while (fgets(buffer,1024,fileStream)) {     
            nbLogements++;   // permet de compter le nombre de logements de manière à initialiser notre tableau de logements dans le main         
        }
 
        // Ferme le fichier

        fclose(fileStream);

    }

    return nbLogements;
}

void read_csv(logement tab[],char* filepath){

	FILE *fileStream;
	fileStream = fopen(filepath, "r");
	if(!fileStream){
		printf("Erreur d'ouverture du fichier");
	}else{

		char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (!feof(fileStream)) {
			fgets(buffer,1024,fileStream);        
			column = 0;
            row++;

            // on saute la première ligne parce qu'il n'y a pas de données dedans
            if (row == 1)
                continue;
 
            // Sépare les données
            char* value = strtok(buffer, ", ");

            
            while (value) {

                switch (column){

                case 0: //colonne 1
                    tab[row-2].index = atof(value);
                    break;

                case 1: //colonne 2
                    tab[row-2].accommodates = atof(value);
                    break;

                case 2: //etc
                    tab[row-2].bedrooms = atof(value);
                    break;

                case 3:
                    tab[row-2].bathrooms = atof(value);
                    break;

                case 4:
                    tab[row-2].beds = atof(value);
                    break;

                case 5:
                    tab[row-2].price = atof(value);
                    break;

                case 6:
                    tab[row-2].minimum_nights = atof(value);
                    break;

                case 7:
                    tab[row-2].maximum_nights = atof(value);
                    break;

                case 8:
                    tab[row-2].number_of_reviews = atof(value);
                    break;                
                
                default:
                    break;
                }
                
                value = strtok(NULL, ", ");
                column++;
            }
        }
 
        // Ferme le fichier
        fclose(fileStream);

	}
}

void distance_logement(logement tab[], logement LogementX, int taille ){

    for(int row=0;row<taille;row++){
        
        tab[row].distance[0] = abs(LogementX.accommodates - tab[row].accommodates); //meubles
        
        tab[row].distance[1] = abs(LogementX.bedrooms - tab[row].bedrooms); //chambres
        
        tab[row].distance[2] = abs(LogementX.beds - tab[row].beds); //lits
    
    }
 
}  

void randomize(logement tab[], int taille){

    srand(time(NULL));
    logement temp; 
    int random;

    for(int i=0; i<taille; i++){ //on inverse au hasard des éléments de notre tableau

        random = rand()%taille; //génére un entier entre 0 et le nombre de logements
        temp = tab[i];
        tab[i] = tab[random];
        tab[random] = temp;

    }


}

void affichage(logement tab[], int taille){

    for(int i=0;i<taille;i++){

        printf("index = %f, accommodates = %f, bedrooms =  %f, bathrooms = %f, beds = %f, price = %f, min_N = %f, max_N = %f, num_Reviews = %f\n",
        tab[i].index,tab[i].accommodates,tab[i].bedrooms,tab[i].bathrooms,tab[i].beds,tab[i].price,tab[i].minimum_nights,tab[i].maximum_nights,tab[i].number_of_reviews);
    }

}

void affichage_distances(logement tab[], int taille){

    for(int i=0;i<taille;i++){

        printf("accommodates = %f, bedrooms =  %f, beds = %f\n",
        tab[i].distance[0],tab[i].distance[1],tab[i].distance[2]);

    }

}

int partition_tri_tab(logement tab[],int low, int high, int type_tri){

    int pivot = tab[high].distance[type_tri];

        int i = low - 1;
        logement temp;

        //on place les éléments plus petits que pivot à gauche et les plus grands à droite à partir de i
        for (int j = low; j < high; j++){
            if(tab[j].distance[type_tri] <= pivot){

                i++;
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;

            }

        }

        //on place le pivot à sa position finale

        temp = tab[i+1];
        tab[i+1] = tab[high];
        tab[high] = temp;
        
        return i+1;

}

void quicksort(logement tab[], int low, int high, int type_tri){

    if( low < high){

        int pi = partition_tri_tab(tab, low, high, type_tri);

        quicksort(tab, low, pi - 1, type_tri);

        quicksort(tab, pi + 1, high, type_tri);
    }


}

float moyenne(logement tab[], int k){

    float resultat=0;

    for(int i=0; i<k; i++){

            resultat += tab[i].price;

        }

        resultat /= k;

        return resultat;


}

// cette partie commentée était un début d'idées pour la question g)
// float fabs(float a){
//     if(a<0){
//         a = -a;
//         return a;
//     }else{
//         return a ; 
//     }
// }

// int 

// float mae(logement tab[], float a , int n){
//     float a= 0 ;

//     for(int i,i<n,i++){
//         a=a+tab[i]
//         a=fabs(a);
//     }
//     a = a / n ;
//     return a; 

// }