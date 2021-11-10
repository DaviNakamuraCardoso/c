/*
 *  Testing the Unix Pipe System 
 */ 

#include <stdio.h>


int main(int argc, char** argv)
{
    char c;
    FILE* f = stdin; 

    if (argc >= 2) f = fopen(argv[1], "r");

    if (f == NULL) 
    {
        fprintf(stderr, "Could not open file %s.", argv[1]);
        return 1;
    } 

    while ((c = fgetc(f)) != EOF)
    {
        fputc(c, stderr);
    }

    fclose(f);

    return 0;
}

