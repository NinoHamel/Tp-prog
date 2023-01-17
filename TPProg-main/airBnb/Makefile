CC=gcc
FLAGS=-Wall -g
BINS=airBnB
all:airBnB

airBnB : fonctions.o tpnote.o
	$(CC) $(FLAGS) $^ -o $@

fonctions.o : fonctions.c
	$(CC) -c $(FLAGS) $^ -o $@
        
tpnote.o : tpnote.c
	$(CC) -c $(FLAGS) $^ -o $@

clean:
	rm *.o $(BINS)
