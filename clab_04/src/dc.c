#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>
//#include "stack.h"

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
    stack_t nums[50];
    token_t tokens[50];

    puts(">> Davi Calculator.");
    puts(">> (c) Davi Nakamura Cardoso 2021.");


    if (f == stdin) putchar('>');

    while (tokenize(f, tokens) != NULL)
    {
        if (f == stdin) putchar('>');
     //   calculate(tokens, stack);
    }


    return 0;
}



