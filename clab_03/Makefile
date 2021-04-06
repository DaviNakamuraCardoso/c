# (L)ibraries, (S)ource and (H)eaders
L = ./lib/
S = ./source/
H = ./include/

# Allegro libraries
ALLEGRO = -lallegro -lallegro_font -lallegro_primitives

$(L)spaceship.o: $(S)spaceship.c
	gcc -I$(H) -c $(S)spaceship.c -o $(L)spaceship.o
$(L)blasteroids.o: $(S)blasteroids.c
	gcc -I$(H) -c $(S)blasteroids.c -o $(L)blasteroids.o
blasteroids: $(L)spaceship.o $(L)blasteroids.o
	gcc $(L)spaceship.o $(L)blasteroids.o -o blasteroids -lm $(ALLEGRO)
