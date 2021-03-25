/* This program encrypts a file in the command line */
#include <stdio.h>
#include <stdlib.h>
#include "encrypt.h"


int main(int argc, char* args[])
{
    FILE* in = fopen(args[1], "r");
    FILE* out = fopen(args[2], "w");
    char s[80];

    while (fscanf(in, "%79[^\n]\n", s) == 1)
    {
        encrypt(s);
        fprintf(out, "%s\n", s);
    }

    fclose(in);
    fclose(out); 

    return 0;

}
