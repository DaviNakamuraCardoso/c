#include <stdio.h>
#include <string.h>

int main(int argc, const char** argv)
{
    if (argc <= 1) return 1;

    char filename[300], newpath[400];
    size_t i, nplen = strlen(argv[1]);
    strcpy(newpath, argv[1]);

    for (size_t i = 0; (char c = fgetc(stdout)); )
    {
        if (c == '\n')
        {

            filename[i] = '\0';
            newpath[nplen+i] = '\0';
            rename(filename, strcat(newpath, filename));
            i = 0;
        }
        filename[i++] = c;
        newpath[nplen+i] = c;

    }

    return 0;
}
