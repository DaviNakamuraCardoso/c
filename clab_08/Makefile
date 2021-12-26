CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror

%.o: %.c
	$(CC) -c $^ -o $@

OBJS = main.o songs.o
EXE = lsongs

all: $(OBJS)
	$(CC) $^ -o $(EXE)

clean: 
	rm $(OBJS) $(EXE)





