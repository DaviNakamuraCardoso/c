#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "guard.h"


/* Master control program utility */
/* Records guard patrol check-ins */
int main(void)
{
    char comment[80];
    char cmd[120];

    fgets(comment, 80, stdin);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());
    system(cmd);

    return 0;
}

char* now()
{
    time_t t;
    time (&t);
    return asctime(localtime(&t));
}
