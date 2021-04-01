utils.o: utils.h utils.c
	gcc -c utils.c
news.o: utils.h news.h news.c
	gcc -c news.c
news: utils.o news.o
	gcc utils.o news.o -o news
