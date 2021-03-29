/* Simulates methods using function pointers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dogs.h"


DOG* init(char* name, float weight)
{
    DOG* d = NULL;
    d = malloc(sizeof(DOG));

    // Attributes
    d->name = strdup(name);
    d->weight = weight;

    // Methods
    d->bark = _bark;
    d->free = _free;

    return d;
}

void _bark(DOG* d)
{
    printf("%s says %s\n", d->name, bark_type(d));
    return;
}

void _free(DOG* d)
{
    free(d->name);
    free(d);

    return;
}

char* bark_type(DOG* d)
{
    return sound(_size(d));
}


char* sound(enum sizes s)
{
    char* (*barks[]) (void) = {small_bark, medium_bark, big_bark};

    return barks[s]();
}

char* small_bark(void)
{
    return "woof woof";
}

char* medium_bark(void)
{
    return "Woof Woof";
}

char* big_bark(void)
{
    return "WOOF WOOF";
}

enum sizes _size(DOG* d)
{
    if (d->weight <= 20)
    {
        return SMALL;
    }
    else if (d->weight <= 40)
    {
        return MEDIUM;
    }

    return BIG;
}
