#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <sys/types.h>
#include <dirent.h>

int main(int argc, const char** argv)
{
    char resolved[400];
    char *path = ".";

    if (argc >= 2) path = argv[1];

    realpath(path, resolved);

    DIR *d = opendir(resolved);
    struct dirent *de = NULL;

    while ((de = readdir(d)) != NULL) 
    {
        printf("%s\n", de->d_name);
    }
    return 0;
}
