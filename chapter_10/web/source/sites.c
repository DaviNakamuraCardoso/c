#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sites.h"

int ascii(char c)
{
     int a = (int) c;
     int complements_start = 26;

     switch (a)
     {
         // Brackets
         case 40:
         case 41:
         {
             return (26 + a - 40);
         }
         // Underscore
         case 95:
         {
             return (28 + a - 95);
         }
     }

     // Checks for uppercase chars
     if ((a >= 65) && (a <= 91))
     {
         return (a - 65);
     }
     // Checks for lowercase chars
     else if ((a >= 97) && (a <= 122))
     {
         return (a - 97);
     }

     // Finally, return values for numbers
     return (29 + a - 48);
}


void register_site(char* name, TRIE* root, SITE* site)
{
    TRIE* current = root;
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
        int a = ascii(name[i]);
        if (current->next[a] == NULL)
        {
            current->next[a] = create_trie();
        }

        current = current->next[a];
    }

    current->address = site;

    return;
}



TRIE* create_trie()
{
    TRIE* t;
    t = malloc(sizeof(TRIE));
    for (int i = 0; i < 40; i++)
    {
        t->next[i] = NULL;
    }
    t->address = NULL;

    return t;
}


unsigned short exists(char* site_name, TRIE* root)
{
    TRIE* current = root;
    int i;
    for (i = 0; site_name[i] != '\0'; i++)
    {
        int a = ascii(site_name[i]);
        // If there is no next trie, return false
        if (current->next[a] == NULL)
        {
            return 0;
        }

        current = current->next[a];
    }

    if (current == NULL)
    {
        return 0;
    }

    return current->address == NULL;
}


SITE* create_site(char* name)
{
    SITE* site;

    site = malloc(sizeof(SITE));

    site->name = strdup(name);
    for (int i = 0; i < 40; i++)
    {
        site->from[i] = NULL;
    }

    return site;

}

void add_site(SITE* from, SITE* new, TRIE* root)
{
    int i;
    while (new->from[i] != NULL)
    {
        i++;
    }
    new->from[i] = from;

    register_site(new->name, root, new);

    return;
}
