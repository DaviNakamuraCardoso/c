/* This program launches a rocket */
#include <stdio.h>
#include "launch.h"
#include "thruster.h"


int main(void)
{
    puts("Starting rocket setup...");
    setup();

    puts("Initializing thrusters...");
    thrusters();

    puts("Starting countdown...");
    unsigned short i;
    for (i = 10; i > 0; i--)
    {
        printf("%i\n", i);
    }

    puts("Launch!");


    return 0;
}


void setup(void)
{
    puts("Setup started");

    unsigned short i;
    for (i = 0; i < 20; i++)
    {
        printf(".");
    }

    puts("\nSetup finished\n");

    return;

}
