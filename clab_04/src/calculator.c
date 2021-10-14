#include <stdio.h>
#include <calculator.h>

void calculate(token_t **tokens, stack_t *s, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        if (tokens[i]->t == NUMBER) {
            push(s, tokens[i]->value);
        }
        else 
        {
            ld_t a = pop(s);
            ld_t b = pop(s);
            push(s, a+b);
        }
    }

    return;

} 
