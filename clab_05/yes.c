#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 2) 
    {
        puts("Usage: yes <word>");
        return -1;
    }

    while (1)
    {
        puts(argv[1]);
    }

    return 0;
}
