#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

Hash** create_table(void)
{
    Hash** table = calloc(sizeof(Hash), HASHSIZE);

    for (int i = 0; i < HASHSIZE; i++)
    {
        table[i] = NULL;
    }

    return table;

}


Hash* create(char* word)
{
    Hash* h = malloc(sizeof(Hash));
    h->word = strdup(word);
    h->next = NULL;

    return h;
}

void add_hash(Hash** table, char* word)
{
    unsigned int index = hash(word);
    Hash *first = table[index], *new = create(word);

    new->next = first;
    table[index] = new;

    return;
}

unsigned int search_hash(Hash** table, char* word)
{
    unsigned int index = hash(word);
    
    for (Hash* current = table[index]; current != NULL; current = current->next)
    {
        if (current == NULL) return 0;
        if (strcmp(current->word, word) == 0) return 1;
    }

    return 0;
}


int hash(char* word)
{
    unsigned int val = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        val += word[i] * 31;
    }

    return val % HASHSIZE;
}
