testing.o: testing.h testing.c
	gcc -c testing.c
matches.o: matches.h testing.h matches.c
	gcc -c matches.c
matches: testing.o matches.o
	gcc testing.o matches.o -o matches
