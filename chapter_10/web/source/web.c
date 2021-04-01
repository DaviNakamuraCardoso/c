#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "web.h"

int main(int argc, char* argv[])
{

    char word[200];
    char address[200];
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (!pid)
    {
        dup2(fd[1], 1);
        close(fd[0]);

        sprintf(address, "https://%s", argv[1]);
        execlp("curl", "curl", address, NULL);

    }

    dup2(fd[0], 0);
    close(fd[1]);

    while (fgets(word, 200, stdin))
    {
        printf("%s", word);
    }

    return 0;
}
