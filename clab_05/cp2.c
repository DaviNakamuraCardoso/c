#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* s, *d;
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: cp <src> <dest>");
        return -1;
    }

    s = fopen(argv[1], "r");

    if (s == NULL)
    {
        fprintf(stderr, "No such file or directory: %s\n", argv[1]);
        return -1;
    }

    d = fopen(argv[2], "w");

    for (char c = fgetc(s); c != EOF; c = fgetc(s)) fputc(c, d);


    return 0;
}
