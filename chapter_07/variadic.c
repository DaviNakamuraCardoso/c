#include <stdio.h>
#include <stdarg.h>


void printints(int args, ...)
{
    va_list ap;

    va_start(ap, args);
    int i;

    for (i = 0; i < args; i++)
    {
        printf("argument: %i\n", va_arg(ap, int));
    }
    va_end(ap);

    return;
}

int main(void)
{
    printints(5, 2, 4, 5, 293, 9);
    return 0;
}
