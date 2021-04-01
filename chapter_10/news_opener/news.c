#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "news.h"

int main(int argc, char* argv[])
{
    char* phrase = argv[1];
    char* vars[] = {"RSS_FEED=https://rss.nytimes.com/services/xml/rss/nyt/HomePage.xml", NULL};

    int fd[2];
    if (pipe(fd) == -1)
    {
        error("Could not open pipe.");
    }
    pid_t pid = fork();

    if (!pid)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        if (execle("/usr/bin/python3", "/usr/bin/python3",
            "rssgossip.py", "-u", phrase, NULL, vars) == -1)
        {
            error("Could not open the script. Do you have Python3 installed?");
        }
    }

    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];

    while(fgets(line, 255, stdin))
    {
        if (line[0] == '\t')
        {
            open_url(line + 1);
        }
    }
    return 0;



}
