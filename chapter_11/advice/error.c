#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


void error(char* message)
{
    printf("%s : %s", message, strerror(errno));
    exit(1); 
}
