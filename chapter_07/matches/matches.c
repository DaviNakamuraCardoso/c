/* This program filters an array of strings */
#include <stdio.h>
#include "matches.h"
#include "testing.h"


int main(void)
{
    find(sports_no_bieber);
    find(sports_or_workout); 
    find(ns_theater);
    find(arts_theater_or_dining);
}


void find(unsigned int (*match) (char*))
{
    int i;

    puts("Search results");
    puts("--------------------");

    for (i = 0; i < NUM_ADS; i++)
    {
        if (match(ADS[i]))
        {
            printf("%s\n", ADS[i]);
        }
    }
    puts("--------------------");

    return;
}
