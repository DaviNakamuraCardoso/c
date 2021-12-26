#include <stdio.h>
#include <stdlib.h>
#include "songs.h"

int main(int argc, const char** argv)
{ 
    const char* path = "~/Music";

    if (argc == 2) path = argv[1];

    printf("Hello, Jukebox!\n");
    printf("Opening %s.\n", path);

    getsongs(path);

    return 0;
}
