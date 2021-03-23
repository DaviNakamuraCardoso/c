/* Checks if a file is safe to open */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Reads a file safely
FILE* sread(char a[80])
{
    FILE* in = NULL;
    if (!(in = fopen(a, "r")))
    {
        fprintf(stderr, "Couldn't open the file %s.\n", a);
    }

    return in;
}

// Safely closes a file
void sclose(FILE* file)
{
    if (file != NULL)
    {
        fclose(file);
    }

    return;
}

// Main function accepts
int main(int argc, char* args[])
{

    FILE* test = sread(args[1]);

    sclose(test);

    return 0;
}
