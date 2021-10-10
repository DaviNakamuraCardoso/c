#include <stdio.h>

void reverse(char* s)
{
    int l;

    for (l = 0; s[l] != '\0'; l++);

    for (int i = 0; i < l / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = tmp;
    }

    puts(s);
}

int main(int argc, char** argv)
{
    reverse(argv[1]);

    return 0;
}
