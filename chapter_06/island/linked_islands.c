/* Stores a linked list of islands in the heap */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _island
{
    char* name;
    char* opens;
    char* closes;
    struct _island* next;
} ISLAND;


ISLAND* create(char* name)
{
    ISLAND* i = malloc(sizeof(ISLAND));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;

    return i;
}

void display(ISLAND* start)
{
    ISLAND* i = start;
    for (; i != NULL; i = i->next)
    {
        printf("Name: %s Open: %s-%s\n", i->name, i->opens, i->closes);

    }
}

void release(ISLAND* start)
{
    ISLAND* i = start;
    ISLAND* next = NULL;

    for (; i != NULL; i = next)
    {
        next = i->next;
        free(i->name);
        free(i);
    }
}

int main(void)
{
    ISLAND* start = NULL;
    ISLAND* i = NULL;
    ISLAND* next = NULL;
    char name[80];

    for (; fgets(name, 80, stdin) != NULL; i = next)
    {
        next = create(name);
        if (start == NULL)
        {
            start = next;
        }
        if (i != NULL)
        {
            i->next = next;
        }
    }
    display(start);
    release(start);
}
