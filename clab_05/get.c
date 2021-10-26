#include <stdio.h>
#include "hash.h"

int main(int argc, const char** argv)
{
    FILE* stream = stdout;

    if (argc == 1) 
    {
        printf("Usage: get <value>\n");
        goto end;
    }

    if (argc == 3)
    {
        stream = fopen(argv[2], "w");
        if (stream == NULL) 
        {
           fprintf("Could not open file %s.\n", argv[1]);
           return -1;
        } 
    }

    get(argv[1], stream);

end:
    fclose(stream);
    return 0;
}


int get(FILE* stream)
{ 
}


