#include <stdio.h>


#define CONTEXT 50

int strlen(char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);

    return i;
} 
unsigned int grep(FILE *f, char *exp);

int main(int argc, char** argv)
{
    FILE* f = stdin;

    if (argc == 3) f = fopen(argv[2], "r");

    grep(f, argv[1]);
     

    fclose(f);

} 

unsigned int grep(FILE *f, char *exp)
{
    char c, prev[CONTEXT] = {0};
    int expl = strlen(exp), arr = 0;

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

               
               printf("\e[35m\e[1m%s\e[0m", exp);

               // Print the next characters
               for (int j = 0; (c = fgetc(f)) != EOF && c != '\n'; j++) putchar(c);
               putchar('\n');
           }

       }
       else i = 0; 
    }
}
