#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <hash.h>

hash_t* new_hash(void)
{
    hash_t* h = malloc(sizeof(hash_t));
    h->table = calloc(sizeof(hashnode_t*), HASHSIZE);
    h->nodes = 0;


    for (int i = 0; i < HASHSIZE; i++)
    {
        h->table[i] = NULL;
    }

    return h;

}


hashnode_t* create(char* word, unsigned int index)
{
    hashnode_t* h = malloc(sizeof(hashnode_t));
    h->word = strdup(word);
    h->index = index; 
    h->next = NULL;

    return h;
}

unsigned int add_hash(hash_t* h, char* word)
{
    unsigned int index = hash(word);
    hashnode_t *first = h->table[index], *new = create(word, ++h->nodes);

    new->next = first;
    h->table[index] = new;


    return h->nodes; 
}

int search_hash(hash_t* h, char* word)
{
    unsigned int index = hash(word);
    
    for (hashnode_t* current = h->table[index]; current != NULL; current = current->next)
    {
        if (current == NULL) return -1;
        if (strcasecmp(current->word, word) == 0) return current->index;
    }

    return -1;
}


int hash(char* word)
{
    unsigned int val = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        val += toupper(word[i]) * 31;
    }

    return val % HASHSIZE;
}
