#include <stdio.h>
#include <stdlib.h> 
#include <stack.h>

stack_t* stack(unsigned int size)
{
    stack_t *s = malloc(sizeof(stack_t));
    s->nums = calloc(sizeof(ld_t), size);
    s->size = size;
    s->sp = 0;

    return s;
}

ld_t pop(stack_t* s)
{
    if (s->sp <= 0) return 0;

    return s->nums[--(s->sp)];
}

ld_t push(stack_t* s, ld_t v)
{
    return (s->nums[(s->sp)++] = v);
}

ld_t look(stack_t* s)
{
    if (s->sp <= 0) return 0;
    return (s->nums[s->sp-1]);
}



