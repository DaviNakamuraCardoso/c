#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned int isurlname(char c)
{
    switch (c)
    {
        case '_':
        case '(':
        case ')':
        case '%':
        case '.':
            return 1; 
    }
    return isalnum(c);
}


unsigned int istrash(char* url)
{
    char* garbage[] = {
        "help",
        "file",
        "help",
        "wikipedia", 
        "category", 
        "special",
        "de_facto", 
        "main_page"
    };

    if (strcasestr(url, "disambiguation") != NULL) return 1;
    for (int i = 0; i < sizeof(garbage) / sizeof(char*); i++)
    {
        if (strcasecmp(garbage[i], url) == 0) return 1;
    }

    return 0; 
}
