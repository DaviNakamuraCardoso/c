

unsigned int streq(char* a, char* b)
{
    unsigned int i;

    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
    {
        if (a[i] != b[i]) return 0;
    }

    return a[i] == b[i];
}
