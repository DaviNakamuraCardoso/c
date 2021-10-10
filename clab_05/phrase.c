#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

const char* PHRASES[MAXSIZE];

void get_phrase(FILE* f);

int main(int argc, const char** argv)
{
    FILE* f = fopen("/usr/share/phrases/main.phrase", "r");

    if (f == NULL) 
    {
        fprintf(stderr, "No such file or directory: %s\n", argv[1]);
        return 1; 
    }

    get_phrase(f);

    fclose(f);
    
    return 0;
}

void skipblank(FILE* f)
{
    char c;
    do {
        c = fgetc(f);
    } while (c != EOF && c != '"');
}


void get_phrase(FILE* f)
{

    char c, phrase[20000];
    unsigned int count = 0;

    srand((unsigned int)clock());

    skipblank(f);

    for (int i = 0; (c = fgetc(f)) != EOF;)
    {
        if (c == '"')
        {
            // End quote
            if (i != 0) 
            {
                phrase[i] = '\0';
                PHRASES[count++] = strdup(phrase);
                i = 0;

                skipblank(f);
            } 
        }
        else phrase[i++] = c;
    }

    printf("%s\n", PHRASES[rand() % count]);

    return; 
}


