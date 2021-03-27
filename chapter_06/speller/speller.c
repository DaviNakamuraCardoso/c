/* This program looks for mispellings in text */
#include <stdio.h>
#include <stdlib.h>
#include "speller.h"
#include "utils.h"


int main(int argc, char* args[])
{
    char word[2000];
    TRIE* root = malloc(sizeof(TRIE));

    FILE* reference = NULL;
    FILE* in = NULL;
    FILE* out = NULL;


    reference = fopen(args[1], "r");
    in = fopen(args[2], "r");
    out = fopen(args[3], "w");

    for (int i = 0; i < 27; i++)
    {
        root->next[i] = NULL;
    }

    while (fgets(word, 2000, reference) != NULL)
    {
        add_word(word, root);
    }

    char* wd;

    while (fscanf(in, "%s", wd) == 1)
    {
        if (!exists(wd, root))
        {
            fprintf(out, "%s\n", wd);
        }
    }

    fclose(reference);
    fclose(in);
    fclose(out);

    // release(root);

    return 0;
}


TRIE* create(int a)
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
            current->next[a] = create(word[i]);
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
