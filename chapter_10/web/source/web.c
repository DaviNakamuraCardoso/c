#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include "web.h"

int main(int argc, char* argv[])
{

    get_urls(argv[1], argv[2], 0);

    return 0;
}

void get_urls(char* article_name, char* target, int index)
{

    if (strcmp(article_name, target) == 0)
    {
        printf("FOUND: %i steps to %s\n", index, target);
        exit(0);
        return;
    }

    if (index == 2)
    {
        return;
    }
    char word[200];

    // First pipe
    int fd[2];
    pipe(fd);


    pid_t pid = fork();

    if (!pid)
    {
        dup2(fd[1], 1);
        dup2(fd[1], 2);
        close(fd[0]);

        char link[500];
        sprintf(link, "https://en.wikipedia.org/wiki/%s", article_name);

        execlp("curl", "curl", link, NULL);

    }


    // Second pipe
    int fd2[2];
    pipe(fd2);

    pid_t pid2 = fork();
    if (!pid2)
    {
        dup2(fd[0], 0);
        dup2(fd2[1], 1);

        close(fd2[0]);
        close(fd[1]);

        execlp("grep", "grep", "-o", "/wiki/.*", NULL);

    }

    dup2(fd2[0], 0);
    close(fd2[1]);


    char st[2000];
    while (scanf("%2000[^\n]\n", st))
    {
        char fmt[2000];
        int ind = 0;
        for (int i = 6; st[i] != '/' && st[i] != '"'; i++)
        {
            fmt[ind] = st[i];
            ind++;

        }
        fmt[ind] = '\0';

        char url[4000];

        // sprintf(url, "https://en.wikipedia.org/wiki/%s", fmt);

        if (!(index == 0 && strcmp(fmt, target) == 0))
        {
            printf("Searching on %s\n", fmt);
            get_urls(fmt, target, index+1);

        }

    }
    return;
}

void open_browser(char* url)
{
    pid_t pid = fork();
    if (!pid)
    {
        execlp("x-www-browser", "x-www-browser", url, "&", NULL);
    }
}
