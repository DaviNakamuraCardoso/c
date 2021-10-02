CC = clang

%.o: %.c
	$(CC) -c $^ -o $@

all: articles.o hash.o main.o graph.o
	$(CC) $^ -o $@ -lcurl

clean: 
	rm *.o
