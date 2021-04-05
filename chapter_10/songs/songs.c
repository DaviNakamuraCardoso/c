#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "songs.h"


int main(int argc, char* argv[])
{

    int pc[2];
    pipe(pc);

    pid_t pid = fork();
    if (!pid)
    {
        dup2(pc[1], 1);
        close(pc[0]);

        execlp("curl", "curl", argv[1], NULL);
    }

    dup2(pc[0], 0);
    char cleaned[2000];

    while (fgets(cleaned, 2000, stdin) != NULL)
    {
        char ur[400];
        strcpy(argv[1], ur);
        char* url = strstr(cleaned, "href=");
        if (url != NULL)
        {

            int i = 6;
            int ind = 0;
            char comp[200];
            for (; url[i] != '-'; i++)
            {
                comp[ind] = url[i];
                ind++;
            }

            strcat(ur, comp);
            printf("%s\n", ur);
        }
    }

    return 0;

}
