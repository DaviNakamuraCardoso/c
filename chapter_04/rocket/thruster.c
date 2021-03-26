#include <stdio.h>
#include "thruster.h"

void thrusters(void)
{
    float version;
    for (version = 0.0; version < 2.5; version += 0.2)
    {
        printf("Starting engine %.2f...\n", version);
    }

    puts("All engines ready!\n");
    return;
}
