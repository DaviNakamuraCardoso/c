#include <stdio.h>

int main(int argc, const char** argv)
{
    FILE* stream = stdin;

    if (argc >= 2)
    {
        stream = fopen(argv[1], "r");
        if (stream == NULL)
        {
            fprintf(stderr, "No such file or directory: '%s'\n", argv[1]); return -1;
        }
    } 

    for (char c; (c = fgetc(stream)) != EOF;) putchar(c);

    return 0;

}
