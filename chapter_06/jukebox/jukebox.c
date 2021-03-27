/* This program stores songs in a linked list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jukebox.h"

int main(void)
{
    SONG* start = NULL;

    char name[80];

    while (scanf("%79[^\n]\n", name) == 1)
    {
        SONG* s = create(name);
        add_song(&start, s);
    }

    display(start);
    release(start);

    return 0;
}


SONG* create(char* name)
{
    SONG* s = malloc(sizeof(SONG));
    s->name = strdup(name);
    s->next = NULL;

    return s;
}


void add_song(SONG** head, SONG* new)
{
    SONG** tracer = head;

    while ((*tracer) != NULL && strcmp((*tracer)->name, new->name) < 1)
    {
        tracer = &(*tracer)->next;
    }
    new->next = *tracer;
    *tracer = new;

    return;
}


void display(SONG* start)
{
    SONG* i = start;
    for (; i != NULL; i = i->next)
    {
        printf("%s\n", i->name);
    }
}


void release(SONG* start)
{
    SONG* i = start;
    SONG* next = NULL;

    for (; i != NULL; i = next)
    {
        next = i->next;
        free(i->name);
        free(i);
    }

    return;
}
