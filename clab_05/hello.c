#include <stdio.h>

int main(int argc, char** argv)
{
    
    if (argc < 2)
    {
        char name[300];     
        printf("What's your name? ");
        scanf("%s", name);
        printf("Hello, %s!\n", name);

        return 0;
    }

    printf("Hello, %s!\n", argv[1]);

    return 0;
}
