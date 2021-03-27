#include <stdio.h>
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
