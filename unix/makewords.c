#include <stdio.h>
#include <ctype.h>

void makewords(FILE* f); 

int main(int argc, const char** argv)
{
    FILE* f = stdin;

    if (argc >= 2) f = fopen(argv[1], "r" );

    makewords(f);

    fclose(f);
    
}

void makewords(FILE* f)
{
    char word[46] = {0}, c;

    for (int i = 0; (c = fgetc(f)) != EOF; i++)
    {
        if (isalpha(c)) word[i] = c;
        else { 
            word[i] = '\0';
            if (i != 0) printf("%s\n", word);
            i = -1;
            word[0] = '\0';
        }
    } 

}
