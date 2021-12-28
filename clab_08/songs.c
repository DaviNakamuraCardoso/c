#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include "string.h"

char* paths[500]; 

int getsongs(const char* path)
{
    char *resolved = realpath(path, NULL);
    unsigned char sp = 0;
    
    paths[sp++] = resolved; 

    do {

        char* current = paths[--sp];
        DIR* d = opendir(current);
        struct dirent *de;

        if (d == NULL)
        {
            fprintf(stderr, "Could not open %s: %s.\n", resolved, strerror(errno));
            return 1;
        }

inner:  while ((de = readdir(d)) != NULL)
        {
            char *name = de->d_name;

            if (de->d_type == DT_DIR)
            {
                if (streq(name, ".") || streq(name, "..")) goto inner; 

                char *abspath = strcpy(malloc(256), current);
                strcat(abspath, "/");
                strcat(abspath, name);

                paths[sp++] = abspath;
            }
            printf("%s\n", name); 
        } 

        closedir(d); 
        free(current);

    } while (sp); 

    return 0;

}
