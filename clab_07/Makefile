CC = clang
FLAGS = -Wall -Wextra -Wpedantic -Werror -Ofast


EXE = sum cache
BIG_VALS = 100 1000 10000 100000 1000000 10000000
SMALL_VALS = 100 1000 10000 

all: $(EXE)
	for i in $(BIG_VALS); do echo "$$i: "; ./sum $$i; done
	for i in $(SMALL_VALS); do echo "$$i: "; ./cache $$i; done 

%: %.c
	$(CC) $^ -o $@

clean: $(EXE)
	rm -f $^
