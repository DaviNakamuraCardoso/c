/* This program automates the generation of letters */
#include <stdio.h>
#include "letters.h"
#include "responses.h"


int main(void)
{
    RESPONSE responses[] = {{"John", DUMP}, {"Gary", DUMP}, {"William", DUMP},
    {"Luis", MARRIAGE}, {"Matt", SECOND_CHANCE}};

    void (*response_functions[]) (RESPONSE) = {dump, second_chance, marriage};

    int i;
    for (i = 0; i < 5; i++)
    {
        response_functions[responses[i].type](responses[i]);
    }

    return 0;
}
