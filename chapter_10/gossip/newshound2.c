#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/waith.h>
#include "newshound2.h"


int main(int argc, char* argv[])
{
    char* phrase = argv[1];
    char* vars[] = {"RSS_FEED=https://rss.nytimes.com/services/xml/rss/nyt/HomePage.xml", NULL};
    FILE* f = fopen("stories.txt", "w");
    if (!f)
    {
        error("Couldn't open file!");
    }
    pid_t pid = fork();

    if (pid == -1)
    {
        error("Can't fork process!");
    }

    if (!pid)
    {
        if (dup2(fileno(f), 1) == -1)
        {
            error("Can't redirect standard output.\n");
        }
        if (execle("/usr/bin/python3", "/usr/bin/python3",
            "rssgossip.py", phrase, NULL, vars))
        {
            error("Can't access Python file.");
        }
    }
    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1)
    {
        error("Couldn't wait for process."); 
    }

    return 0;

}


void error(char* message)
{
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}
