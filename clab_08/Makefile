CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror

%.o: %.c
	$(CC) -c $^ -o $@

OBJS = main.o songs.o string.o
EXE = lsongs

all: $(OBJS)
	$(CC) $^ -o $(EXE)
	./$(EXE) ~/Music

clean: 
	rm $(OBJS) $(EXE)





