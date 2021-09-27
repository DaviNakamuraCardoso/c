#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "hash.h"

void mismatch(FILE* f, FILE* dict);

int main(int argc, const char** argv)
{
    FILE *dict, *f = stdin;

    if (argc >= 3) 
    {
        f = fopen(argv[1], "r");
        dict = fopen(argv[2], "r");
    }
    else
    {
        dict = fopen(argv[1], "r");
    }

    mismatch(f, dict);

    fclose(f);
    fclose(dict);

    return 0;
}


void loop(FILE* stream, Hash** dictionary, void (*handler) (Hash**, char*))
{
    char c, word[46];

    for (int i = 0; (c = fgetc(stream)) != EOF; i++)
    {
        if (!isalpha(c) && c != '\'')
        {
            word[i] = '\0';
            
            handler(dictionary, word);

            i = -1;
            word[0] = '\0'; 
            continue;
        }

        word[i] = c;

    }
}

void print_notf(Hash** dictionary, char* word)
{
    if (!search_hash(dictionary, word)) puts(word);
}

void mismatch(FILE* f, FILE* dict)
{
    Hash** dictionary = create_table();

    loop(dict, dictionary, &add_hash);
    loop(f, dictionary, &print_notf);

}

