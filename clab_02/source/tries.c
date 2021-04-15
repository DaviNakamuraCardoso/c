#include <stdlib.h>
#include <tries.h>

TRIE* create_trie(void)
{
    TRIE* t;
    int i;

    t = malloc(sizeof(TRIE));
    t->passes = 0;

    for (i = 0; i < 200; i++)
    {
        t->next[i] = NULL;
    }

    return t;
}

void add_phrase(TRIE* root, char* start)
{
    TRIE* current;
    int i;

    current = root;
    for (i = 0; start[i] != '\0'; i++)
    {
        int a;

        a = (int) start[i];
        if (a > 200)
        {
            a = 200;
        }
        if (current->next[a]== NULL)
        {
            TRIE* new = create_trie();
            current->next[a] = new;
        }
        current->passes++;
        current = current->next[a];
    }
}
