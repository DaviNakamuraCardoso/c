#include <stdio.h>
#include <stdlib.h>
#include <mtwister.h>
#include <tries.h>
#include <main.h>

int main(int argc, char** argv)
{
    FILE* f;
    TRIE* root;
    char* buff;

    f = fopen(argv[1], "r");

    root = read_file(f);


    buff = walk_through(root);

    printf("%s\n", buff);

    return 0;
}

TRIE* read_file(FILE* f)
{
    TRIE* t;
    char buff[2000], book[100];
    int chapter, vers;

    t = create_trie();

    while (fscanf(f, "%s %2000[^\n]\n", book, buff) == 2)
    {
        add_phrase(t, buff);
    }

    return t;
}

char* walk_through(TRIE* root)
{
    int i, j, max, passes;
    double n;
    int nums[200];
    char* phrase = malloc(2000* sizeof(char));
    TRIE* current = root;
    TRIE* next;
    MTRand r = seedRand(200);

    j = 0;
    while (current != NULL)
    {
        max = 0;
        next = NULL;

        for (i = 0; i < 200; i++)
        {
            nums[i] = 0;
            if (current->next[i] != NULL)
            {
                passes = current->next[i]->passes;
                nums[i] = passes;
                max += passes;
            }
        }

        n = ((int) genRand(&r)) % max;
        for (i = 0; i < 200; i++)
        {
            n -= nums[i];
            if (n <= 0)
            {
                next = current->next[i];
                phrase[j] = (char) i;
            }
        }

        current = next;
        j++;
    }
    phrase[j+1] = '\0';
    return phrase;
}
