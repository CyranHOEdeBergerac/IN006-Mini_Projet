tme1_exo2p2 : fonctions_tableau.c tme1_exo2p1.h
	gcc -Wall -o tme1_exo2p2 fonctions_tableau.o tme1_exo2p2.o

tme1_exo2p2.o : tme1_exo2p2.c tme1_exo2p1.h
	gcc -c -Wall -o tme1_exo2p2 tme1_exo2p2.c

tme1_exo2p1.o : tme1_exo2p1.c
	gcc -c -Wall -o tme1_exo2p1 tme1_exo2p1.c
	
fonctions_tableau.o : tme1_exo2p1.h
	gcc -c -Wall -o fonctions_tableau fonctions_tableau.c
