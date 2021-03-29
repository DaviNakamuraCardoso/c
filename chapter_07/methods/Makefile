dogs.o: dogs.h dogs.c
	gcc -c dogs.c
methods.o: dogs.h methods.h methods.c
	gcc -c methods.c
methods: dogs.o methods.o
	gcc dogs.o methods.o -o methods
