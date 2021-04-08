# (L)ibraries, (S)ource, (H)eaders, (A)rchives
L = ./lib/
S = ./source/
H = ./include/
A = ./arch/

# Allegro libraries
ALLEGRO = -lallegro -lallegro_font -lallegro_primitives


# Common math functions
$(L)mathutils.o: $(S)mathutils.c
	gcc -I$(H) -c $(S)mathutils.c -o  $(L)mathutils.o


# Util functions archive
$(A)libblastutils.a: $(L)mathutils.o
	ar -rcs $(A)libblastutils.a $(L)mathutils.o

# Asteroids code
$(L)asteroids.o: $(S)asteroids.c
	gcc -I$(H) -c $(S)asteroids.c -o $(L)asteroids.o

# Blasts
$(L)blasts.o: $(S)blasts.c
	gcc -I$(H) -c $(S)blasts.c -o $(L)blasts.o

# Spaceships
$(L)spaceship.o: $(S)spaceship.c
	gcc -I$(H) -c $(S)spaceship.c -o $(L)spaceship.o

# Core
$(L)blasteroids.o: $(S)blasteroids.c
	gcc -I$(H) -c $(S)blasteroids.c -o $(L)blasteroids.o

# Exec
blasteroids: $(L)asteroids.o $(L)blasts.o $(L)spaceship.o $(L)blasteroids.o $(A)libblastutils.a
	gcc $(L)asteroids.o $(L)blasts.o $(L)spaceship.o $(L)blasteroids.o -L$(A) -o blasteroids -lm $(ALLEGRO) -lblastutils
