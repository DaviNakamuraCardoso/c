#include <stdio.h>
#include "encrypt.h"


int main(void)
{
    char msg[80];

    while (fgets(msg, 79, stdin))
    {
        encrypt(msg);
        printf("%s\n", msg); 
    }
}
