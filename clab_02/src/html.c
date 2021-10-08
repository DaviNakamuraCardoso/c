#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* head = "<!DOCTYPE html><html><head><link rel=\"stylesheet\" href=\"./c.css\"></head><body><svg";
const char* tail = "<script src=\"./c.js\" defer> </script></body></html>";


int html(char* src, char* dest)
{
    FILE* s = fopen(src, "r"), *d = fopen(dest, "w");
    char* match = "<svg", c;
    unsigned int l = strlen(match);


    for (int i = 0; i < l;)
    {
        c = fgetc(s); 

        if (c == match[i]) i++;
        else i = 0; 
    }

    fprintf(d, head);
    
    while ((c = fgetc(s)) != EOF)
        fputc(c, d);

    fprintf(d, tail);

    return 0;

}
