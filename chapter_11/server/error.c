#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


void error(char* message)
{
    fprintf(stderr, "%s : %s", message, strerror(errno));
    exit(1);
}
