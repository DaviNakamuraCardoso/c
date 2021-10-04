CC = clang


OBJS = main.o graph.o hash.o articles.o
OBJ = $(foreach obj, $(OBJS), $(addprefix ./obj/, $(obj)))


./obj/%.o: ./src/%.c
	$(CC) -I ./include -c $^ -o $@

all: $(OBJ) 
	$(CC) $^ -o links -lcurl
