S = ./source/
L = ./libs/
I = ./includes/

$(L)mtwister.o: $(S)mtwister.c
	gcc -I$(I) -c $(S)mtwister.c -o $(L)mtwister.o
$(L)tries.o: $(S)tries.c
	gcc -I$(I) -c $(S)tries.c -o $(L)tries.o
$(L)main.o: $(S)main.c
	gcc -I$(I) -c $(S)main.c -o $(L)main.o
main: $(L)mtwister.o $(L)tries.o $(L)main.o
	gcc -I$(I) -L$(L) $(L)mtwister.o $(L)tries.o $(L)main.o -o main
