#include <stdio.h>
#include <dncll.h>

void addll(LINKED_LIST* new, LINKED_LIST** root, int (*cmp) (const void* a, const void* b))
{
    LINKED_LIST** tracer = root;
    while ((*tracer) != NULL && cmp((*tracer), new) < -1)
    {
        tracer = &(*tracer)->next;
    }
    new->next = *tracer;
    *tracer = new;

    return;
}
