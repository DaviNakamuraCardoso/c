#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

const char* songs[300];

int getsongs(const char* path)
{
    char resolved[256];

    realpath(path, resolved);

    DIR* d = opendir(resolved);
    struct dirent *de;

    if (d == NULL)
    {
        fprintf(stderr, "Could not open %s: %s.\n", resolved, strerror(errno));
        exit(1);
    }

    while ((de = readdir(d)) != NULL)
    {
        printf("%s\n", de->d_name);
    } 

    closedir(d);

    return 0;

}
