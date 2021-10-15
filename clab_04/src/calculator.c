#include <stdio.h>
#include <calculator.h>


ld_t add(a, b)
    ld_t a, b;
{
    return a + b;
}

ld_t sub(a, b)
    ld_t a, b;
{
    return a - b;
}

ld_t div(a, b)
    ld_t a, b;
{
    return a / b;
}


ld_t mult(a, b)
    ld_t a, b;
{
    return a * b;
}

void calculate (token_t **tokens, stack_t *s, unsigned int length)
{
    ld_t (*calculations[20]) (ld_t, ld_t);
    unsigned sp = 0;

    for (unsigned int i = 0; i < length; i++)
    {
        if (tokens[i]->t == NUMBER) {
            push(s, tokens[i]->value);
        }
        else 
        {
            calculations[sp++] = add;
        }
    }

    while (s->sp > 1)
    {
        push(s, add(pop(s), pop(s)));

    }

    return;

} 
