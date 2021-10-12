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
    printf(">> Davi Calculator.\n>> (c) Davi Nakamura Cardoso 2021.\n");

//    stack_t *nums = new_stack(20);
    token_t tokens[30];

    if (f == stdin) putchar('>');

    while (tokenize(f, tokens) != NULL)
    {
        if (f == stdin) putchar('>');
     //   calculate(tokens, stack);
    }

//    release_tokens(tokens);
//    release_stack(nums);

    return 0;
}



