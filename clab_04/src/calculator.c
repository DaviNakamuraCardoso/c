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
    return b - a;
}

ld_t div(a, b)
    ld_t a, b;
{
    return b / a;
}

ld_t mult(a, b)
    ld_t a, b;
{
    return a * b;
}

ld_t (*operations[]) (ld_t, ld_t) = {
    [ADD] = add,
    [SUB] = sub,
    [MULT] = mult,
    [DIV] = div
};


void calculate (token_t **tokens, stack_t *s, unsigned int length)
{
    enum operation ops[20];
    static unsigned sp = 0;


    for (unsigned int i = 0; i < length; i++)
    {
        if (tokens[i]->t == NUMBER) {
            push(s, tokens[i]->value);
        }
        else 
        {
            ops[sp++] = tokens[i]->op;
        }
    }

    while (sp > 0)
    {
        push(s, operations[ops[--sp]](pop(s), pop(s)));
    }

    return;

} 
