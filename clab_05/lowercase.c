#include <stdio.h>
#include <ctype.h>

void lowercase(FILE* f);

int main(int argc, const char** argv)
{
    FILE *f = stdin;
    if (argc >= 2) f = fopen(argv[1], "r");

    lowercase(f);

   fclose(f); 
}


void lowerword(char* word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }
}


void lowercase(FILE* f)
{
    char word[46], c;

    for (int i = 0; (c = fgetc(f)) != EOF; i++)
    {
        if (c == '\n' || c == '\0') 
        {
            word[i] = '\0';
            lowerword(word);
            printf("%s\n", word);
            i = -1;
            word[0] = '\0';
            continue;
        }

        word[i] = c;

    } 
}
