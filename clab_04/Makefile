CC = clang
FLAGS = -Wall

S = ./src/
I = ./include/
O = ./obj/

OBJECTS = dc tokenizer
OBJ = $(foreach obj, $(OBJECTS), $(addprefix $(O), $(obj)))
OBJS =  $(foreach obj, $(OBJ), $(addsuffix .o, $(obj)))


$(O)%.o: $(S)%.c
	$(CC) $(FLAGS) -I $(I) -c $^ -o $@

all: $(OBJS)
	$(CC) $(FLAGS) -I $(I) $^ -o dc

