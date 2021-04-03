error.o: error.h error.c
	gcc -c error.c
server.o: error.h server.h server.c
	gcc -c server.c
server: error.o server.o
	gcc error.o server.o -o server
