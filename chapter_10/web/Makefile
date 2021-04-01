./libs/sites.o: ./includes/sites.h ./source/sites.c
	gcc -c ./source/sites.c -I ./includes -o ./libs/sites.o
./libs/web.o: ./includes/web.h ./includes/sites.h ./source/web.c
	gcc -c ./source/web.c -I ./includes -o ./libs/web.o
web: ./libs/sites.o ./libs/web.o
	gcc ./libs/web.o -o web
