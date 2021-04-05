lib/cnet.o: ./include/cnet.h ./source/cnet.c
	gcc -I ./include -c source/cnet.c -o ./lib/cnet.o
libcnet.a: lib/cnet.o
	ar -rcs libcnet.a lib/cnet.o
