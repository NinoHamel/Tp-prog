#include "tpnote.h"

int main(int argc, char* argv[]){
    logement LogementX;

    printf("Entrez le nombre de meubles de votre logement à tester :\n");
    scanf("%f",&LogementX.accommodates);
    printf("Entrez le nombre de chambres de votre logement à tester :\n");
    scanf("%f",&LogementX.bedrooms);
    printf("Entrez le nombre de lits de votre logement à tester :\n");
    scanf("%f",&LogementX.beds);

    int type_tri;
    printf("Entrez 0 pour estimer selon le nombre de meubles, 1 pour le nombre de chambres et 2 pour le nombre de lits\n");
    scanf("%d",&type_tri);

    int k;
    printf("Entrez k tel que la moyenne sera calculée en fonction des k logements les plus proches (en distance) :\n");
    scanf("%d",&k);
    int taille = find_length(filenamePropre); //trouve le nombre de logement

    logement tab[taille]; //génére le tableau de logement
    read_csv(tab,filenamePropre); //rempli le tableau de logement
    distance_logement(tab, LogementX, taille); //calcul la distance entre les logements et le logement X
    // affichage_distances(tab,taille);

    randomize(tab,taille); //randomize le tableau de logement
    // affichage(tab,taille);

    quicksort(tab,0,taille-1,type_tri); //trie le tableau de logement en fonction du type_tri
    // affichage_distances(tab,taille);
    //affichage(tab,taille); 
    printf("Le prix estimé pour votre logement est : %0.2f\n",moyenne(tab,k));

    //bonus

    int taille_entrainement = find_length(filenameEntrainement);
    logement tabEntrainement[taille_entrainement];
    read_csv(tabEntrainement, filenameEntrainement);

    int taille_test = find_length(filenameTest);
    logement tabTest[taille_test];
    read_csv(tabTest, filenameTest);

	return 0;
}