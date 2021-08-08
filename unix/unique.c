#include <stdio.h>
#include <ctype.h>
#include "hash.h"


void unique(FILE* f);

int main(int argc, char** argv)
{
    FILE* f = stdin;

    if (argc >= 2) f = fopen(argv[1], "r");

    unique(f);

    fclose(f);
}


void unique(FILE* f)
{
    Hash** dictionary = create_table();
    char c, word[46];


    for (int i = 0; (c = fgetc(f)) != EOF; i++)
    {
        if (isspace(c)) 
        {
            word[i] = '\0';

            if (!search_hash(dictionary, word))
            {
                add_hash(dictionary, word);
                printf("%s\n", word);
            }

            
            i = -1;
            word[0] = '\0';
            continue;
            
        }

        word[i] = c;
    }
}



