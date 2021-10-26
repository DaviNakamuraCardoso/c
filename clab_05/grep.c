#include <stdio.h>


#define CONTEXT 25

int strlen(char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);

    return i;
} 

int main(int argc, char** argv)
{
    char* exp = argv[1], c, prev[CONTEXT] = {0};
    int expl = strlen(exp), arr = 0;
    FILE* f = stdin;

    if (argc == 3) f = fopen(argv[2], "r");

    for (int i = 0; (c = fgetc(f)) != EOF;)
    {
       if (arr >= CONTEXT) arr = 0;
       prev[arr++] = c;

       if (exp[i++] == c) 
       {
           if (i == expl) 
           { 
               // Print the previous text
               for (int j = 0; j < CONTEXT - expl; j++) 
               {
                   putchar(prev[arr++]);
                   if (arr >= CONTEXT) arr = 0;

               }  

               
               printf("\e[7m%s\e[0m", exp);

               // Print the next characters
               for (int j = 0; (c = fgetc(f)) != EOF && j < 20 && c != '\n'; j++) putchar(c);
               putchar('\n');
           }

       }
       else i = 0;

       
    } 

    fclose(f);

} 
