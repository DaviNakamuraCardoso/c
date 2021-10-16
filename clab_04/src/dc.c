#include <stdio.h>
#include <stdlib.h>
#include <calculator.h>

int dc(FILE* f);

int main(int argc, const char** argv)
{
    FILE* f = stdin;

    if (argc >= 2) f = fopen(argv[1], "r");

    dc(f);

    if (f != stdin) fclose(f);
    return 0;
}

int dc(FILE* f)
{
    
    token_t* tokens[50];
    stack_t *s = stack(50);

    if (f == stdin) 
    {
        puts(">> Davi Calculator.");
        puts(">> (c) Davi Nakamura Cardoso 2021.");
        putchar('>');
    } 

    for (int i = tokenize(f, tokens); i > 0; i = tokenize(f, tokens))
    {
        calculate(tokens, s, i);

        if (f == stdin) 
        {
            printf("%Lf\n", look(s));
            putchar('>');
        }
    }

    printf("%Lf\n", look(s));


    return 0;
}



