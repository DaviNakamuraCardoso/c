error.o: error.h error.c
	gcc -c error.c
advice.o: error.h advice.h advice.c
	gcc -c advice.c
advice: error.o advice.o
	gcc error.o advice.o -o advice
