/* This program looks for mispellings in text */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "speller.h"
#include "utils.h"


int main(int argc, char* args[])
{
    clock_t start, end;
    double cpu_time_used;

    char word[2000];
    TRIE* root = create();

    FILE* reference = NULL;
    FILE* in = NULL;
    FILE* out = NULL;

    start = clock();

    reference = fopen(args[1], "r");
    in = fopen(args[2], "r");
    out = fopen(args[3], "w");


    while (fscanf(reference, "%2000[^\n]\n", word) == 1)
    {
        add_word(word, root);
    }


    while (fscanf(in, "%s", word) == 1)
    {
        char* exibith = clean(word);
        if (!exists(exibith, root))
        {
            fprintf(out, "%s\n", exibith);
        }
        free(exibith);
    }

    fclose(reference);
    fclose(in);
    fclose(out);

    // Free all the memory used by the TRIE
    release(root);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("TIME ELAPSED: %f\n", cpu_time_used);

    return 0;
}


TRIE* create(void)
{
    TRIE* t;
    t = malloc(sizeof(TRIE));


    for (int i = 0; i < 27; i++)
    {
        t->next[i] = NULL;
    }

    t->exists = 0;

    return t;
}


void add_word(char* word, TRIE* root)
{
    int i;
    TRIE* current = root;

    for (i = 0; word[i] != '\0'; i++)
    {
        int a = ascii(word[i]);
        if (current->next[a] == NULL)
        {
            current->next[a] = create();
        }

        current = current->next[a];
    }

    current->exists = 1;

    return;
}


unsigned int exists(char* word, TRIE *root)
{
    int i;
    TRIE* current = root;
    for (i = 0; word[i] != '\0'; i++)
    {
        if (current == NULL)
        {
            return 0;
        }
        current = current->next[ascii(word[i])];
    }
    if (current == NULL)
    {
        return 0;
    }
    unsigned int r = current->exists;

    return r;
}


void release(TRIE* root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < 27; i++)
    {
        if (root->next[i] == NULL)
        {
            continue;
        }
        release(root->next[i]);
    }

    free(root);

}
