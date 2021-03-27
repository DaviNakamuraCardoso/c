#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int ascii(char c)
{
    int a = 0;
    int ascii = (int) c;

    if (ascii >= 97 && ascii <= 122)
    {
        a = ascii - 97;
    }
    else if (ascii >= 65 && ascii <= 90)
    {
        a = ascii - 65;
    }
    else
    {
        a = 26;
    }

    return a;
}

unsigned int is_character(char a)
{
    int ascii = (int) a;
    if (((ascii >= 65) && (ascii <= 91)) || ((ascii >= 97) && (ascii <= 122)) || (ascii == 39))
    {
        return 1;
    }

    return 0;
}


char* clean(char* word)
{
    char* cleaned = malloc(2000*sizeof(char));
    int i = 0;
    int j = 0;
    while (word[i] != '\0')
    {
        if (is_character(word[i]))
        {
            cleaned[j] = word[i];
            j++;
        }
        i++;
    }
    cleaned[j] = '\0';

    return cleaned;
}
