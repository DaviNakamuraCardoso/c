#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* feeds[] = {
        "https://lifehacker.com/rss", 
        "https://rss.nytimes.com/services/xml/rss/nyt/HomePage.xml",
        "http://rss.cnn.com/rss/cnn_topstories.rss",
        "http://rssfeeds.usatoday.com/UsatodaycomNation-TopStories"
    };
    int i;
    char* phrase = argv[1];
    for (i = 0; i < 4; i++)
    {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char* vars[] = {var, NULL};
        pid_t pid = fork();
        if (pid == -1)
        {
            fprintf(stderr, "Cannot fork the script: %s", strerror(errno));
            return 1;
        }
        if (!pid)
        {
            if (execle("/usr/bin/python3", "/usr/bin/python3",
                "rssgossip.py", phrase,NULL, vars) == -1)
            {
                fprintf(stderr, "Cannot run script: %s\n", strerror(errno));
                return 1;
            }
            return 0;
        }
    }

    return 0;

}
