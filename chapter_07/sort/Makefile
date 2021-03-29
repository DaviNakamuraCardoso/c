helper.o: helper.h helper.c
	gcc -c helper.c
sort.o: sort.h helper.h sort.c
	gcc -c sort.c
sort: helper.o sort.o
	gcc helper.o sort.o -o sort
