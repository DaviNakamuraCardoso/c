#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char** argv) 
{
    char outstr[200];
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);

    if (tmp == NULL) 
    {
        perror("localtime");
        exit(EXIT_FAILURE);
    }

    if (strftime(outstr, sizeof(outstr), "%c", tmp) == 0) 
    {
        fprintf(stderr, "strftime returned 0");
        exit(EXIT_FAILURE);
    }

    puts(outstr);

    return 0;
}
