#define _GNU_SOURCE 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "songs.h"


int main(int argc, const char** argv)
{ 
    char resolved[256], *path;

    sprintf(resolved, "/home/%s/Music", cuserid(NULL));

    path = resolved;

    if (argc == 2) path = argv[1];

    printf("Hello, Jukebox!\n");
    printf("Opening %s.\n", path);


    return getsongs(path);
}
