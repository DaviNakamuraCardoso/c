#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "stack.h"


int main(void)
{
    FILE* f = stdin;

    if (argc >= 2) f = fopen(argv[1], "r");

    dc(f);

    if (f != stdin) fclose(f);
    return 0;
}

int dc(FILE* f)
{
    printf("Davi Calculator.\n(c) Davi Nakamura Cardoso 2021.\n\n");

    stack_t *nums = new_stack(20);

    while ((token_t *tokens = tokenize(f)) != NULL)
    {
        calculate(tokens, stack);
        release_tokens(tokens);
    }

    release_stack(nums);
}


