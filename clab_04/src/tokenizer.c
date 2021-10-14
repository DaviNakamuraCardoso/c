#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer.h>


token_t *getnum(FILE* f)
{
    token_t* t;
    char c, buff[300];
    int i;

    for (i = 0, c = fgetc(f); isdigit(c); i++, c = fgetc(f)) 
        buff[i] = c;

    if (c == '.') 
    {
        buff[i++] = c;
        for (c = fgetc(f); isdigit(c); i++, c = fgetc(f))
            buff[i] = c;
    }
    
    ungetc(c, f);

    buff[i] = '\0';


    t = malloc(sizeof(token_t));
    t->t = NUMBER;
    t->value = strtold(buff, NULL);

    return t;

}

token_t* getop(FILE* f)
{

    char c = fgetc(f);
    token_t* t = malloc(sizeof(token_t));

    t->t = SYMBOL;

    return t;

}

unsigned int tokenize(FILE* f, token_t** tokens)
{
   char c;
   int i; 

   for (i = 0; (c = fgetc(f)) != '\n'; i++)
   {
       if (isblank(c)) continue;
       if (c == EOF) return NULL;

       ungetc(c, f);

       if (isdigit(c)) tokens[i] = getnum(f);
       else tokens[i] = getop(f); 

   }


   return i;

}
