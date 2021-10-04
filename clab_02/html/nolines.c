#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* f = stdin;
    char c;

    if (argc > 1) f = fopen(argv[1], "r");

    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n') putchar(' ');
        else putchar(c);
    }

    fclose(f);
    
}
