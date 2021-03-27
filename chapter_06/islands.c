/* This program creates a set of Linked Lists to represent Islands */
#include <stdio.h>

typedef struct _island
{
    char* name;
    char* opens;
    char* closes;
    struct _island* next;
} ISLAND;


void display(ISLAND* start)
{
    ISLAND* i = start;
    for (; i != NULL; i = i->next)
    {
        printf("Name: %s Open: %s-%s", i->name, i->opens, i->closes);

    }
}

int main(void)
{
        ISLAND amity = {"Amity", "09:00", "17:00", NULL};
        ISLAND craggy = {"Craggy", "09:00", "17:00", NULL};
        ISLAND nublar = {"Nublar", "09:00", "17:00", NULL};
        ISLAND shutter = {"Shutter", "09:00", "17:00", NULL};

        amity.next = &craggy;
        craggy.next = &nublar;
        nublar.next = &shutter;

        display(&amity);


    return 0;
}
