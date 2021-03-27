utils.o: utils.h utils.c
	gcc -c utils.c
speller.o: speller.h utils.h speller.c
	gcc -c speller.c
speller: utils.o speller.o
	gcc utils.o speller.o -o speller
