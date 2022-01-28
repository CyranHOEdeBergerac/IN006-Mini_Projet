all : tme1_exo2p2

tme1_exo2p2 : tme1_exo2p2.o fonctions_tableau.o
	gcc -Wall -o tme1_exo2p2 tme1_exo2p2.o fonctions_tableau.o
	
tme1_exo2p2.o : tme1_exo2p2.c fonctions_tableau.h
	gcc -Wall -c tme1_exo2p2.c
	
fonctions_tableau.o : fonctions_tableau.c fonctions_tableau.h
	gcc -c fonctions_tableau.c

clean : rm -f *.o tme1_exo2p2
