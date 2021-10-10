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
        "portal",
        "talk",
        "wikipedia", 
        "privacy_policy",
        "cookie_statement",
        "category", 
        "special",
        "de_facto", 
        "main_page", 
        "template",
        "template_talk",
        "cross"
    };

    if (strcasestr(url, "disambiguation") != NULL) return 1;
    if (strcasestr(url, "(identifier)") != NULL) return 1;
    for (int i = 0; i < sizeof(garbage) / sizeof(char*); i++)
    {
        if (strcasecmp(garbage[i], url) == 0) return 1;
    }

    if (url[0] == 'Q')
    {
        for (int i = 1; url[i] != '\0'; i++)
            if (!isdigit(url[i])) goto end;

        return 1; 
    }
    end:

    return 0; 
}
