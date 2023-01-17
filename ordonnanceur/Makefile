CC=gcc
FLAGS=-Wall -g
BINS=ordonnanceurs
all:ordonnanceurs


ordonnanceurs : fonctions.o ordonnanceurs.o
	$(CC) $(FLAGS) $^ -o $@

fonctions.o : fonctions.c
	$(CC) -c $(FLAGS) $^ -o $@ 
	
ordonnanceurs.o : ordonnanceurs.c 
	$(CC) -c $(FLAGS) $^ -o $@

clean:
	rm *.o $(BINS)