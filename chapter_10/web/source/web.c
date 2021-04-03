#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <time.h>
#include "sites.h"
#include "web.h"


int main(int argc, char* argv[])
{

    TRIE* root = create_trie();
    SITE* s = create_site(argv[1]);
    register_site(argv[1], root, s);

    get_urls(argv[1], argv[2], 0, root);

    return 0;
}

void get_urls(char* article_name, char* target, int index, TRIE* root)
{

    if (strcmp(article_name, target) == 0)
    {
        printf("\n\n================== FOUND =====================\n\n");
        SITE* c = get_site(target, root);

        while (c != NULL)
        {
            printf("%s from \n", c->name);
            c = c->from[0];
        }
        exit(0);
        return;
    }

    SITE* previous = get_site(article_name, root);
    if (previous == NULL)
    {
        printf("Could not find a site named %s\n\n", article_name);
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


    int j;
    char st[2000];

    clock_t start = clock();
    double cpu_time_used;
    for (j = 0; j < 600; j++)
    {

        if (cpu_time_used > 1)
        {
            break;
        }
        if (fgets(st, 2000, stdin) == NULL)
        {
            break;
        }

        clock_t end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        char* fmt = malloc(2000* sizeof(char));

        int ind = 0;
        for (int i = 6; st[i] != '/' && st[i] != '"'; i++, ind++)
        {
            if (!check(st[i]))
            {
                fmt = NULL;
                break;
            }
            fmt[ind] = st[i];
        }


        if (fmt == NULL)
        {
            continue;
        }
        else
        {
            fmt[ind] = '\0';
        }

        if (strcmp(fmt, " ") == 0)
        {
            continue;
        }

        if ((int) fmt[0] > 91)
        {
            continue;
        }


        if ((strcmp("Main_Page", fmt) == 0 || strcmp("Case_sensitivity", fmt) == 0) && j >= 3)
        {
            break;
        }


        if (get_site(fmt, root) == NULL)
        {
            printf("Adding %s\n", fmt);
            SITE* s = create_site(fmt);
            add_site(previous, s, root);
            register_site(fmt, root, s);

            if (strcmp(fmt, target) == 0)
            {
                get_urls(fmt, target, index+1, root);
            }
        }
    }

    int i;

    for (i = 0; previous->next[i] != NULL; i++)
    {
        if (strcmp(previous->next[i]->name, " ") == 0 || previous->next[i]->name == NULL)
        {
            continue;
        }
        if (strlen(previous->next[i]->name) == 0)
        {
            continue;
        }


        printf("\n\n\n====Searching for %s =====\n\n\n", previous->next[i]->name);
        get_urls(previous->next[i]->name, target, index+1, root);
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

unsigned short check(char c)
{
    switch (c)
    {
        case '>':
        case '<':
        case '-':
        case '#':
        case ':':
        case '=':
        case '%':
        case ' ':
        case ';':
        {
            return 0;
        }
    }
    int ascii = (int) c;
    if (ascii >= 0 && ascii <= 122)
    {
        return 1;
    }

    return 0;
}
