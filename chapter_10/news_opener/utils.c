#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


void error(char* message)
{
    fprintf(stderr, "%s : %s", message, strerror(errno));
    exit(1);
}

void open_url(char* url)
{
    char launch[255];

    // Open on Windows
    sprintf(launch, "cmd /c start %s", url);
    system(launch);

    // Open on Linux
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);

    // Open on Mac
    sprintf(launch, "open '%s'", url);
    system(launch);

    return;
}
