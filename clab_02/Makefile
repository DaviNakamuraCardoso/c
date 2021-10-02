CC = clang

%.o: %.c
	$(CC) -c $^ -o $@

all: main.o graph.o
	$(CC) $^ -o $@

clean: 
	rm *.o
