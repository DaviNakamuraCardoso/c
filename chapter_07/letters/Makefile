responses.o: letters.h responses.h responses.c
	gcc -c responses.c
letters.o: letters.h letters.c
	gcc -c letters.c
letters: responses.o letters.o
	gcc responses.o letters.o -o letters
