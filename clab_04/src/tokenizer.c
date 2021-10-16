#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer.h>

static enum operation ctoop(char c);

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
    t->op = ctoop(c);

    return t;

}

unsigned int tokenize(FILE* f, token_t** tokens)
{
   char c;
   int i; 

   for (i = 0; (c = fgetc(f)) != '\n';)
   {
       if (c == EOF) return 0;
       if (isblank(c)) continue;

       ungetc(c, f);

       if (isdigit(c)) tokens[i++] = getnum(f);
       else tokens[i++] = getop(f); 

   }


   return i;

}


static enum operation ctoop(char c)
{
    enum operation op;

    switch (c)
    {
        case '+': { op = ADD; break; }
        case '-': { op = SUB; break; }
        case '/': { op = DIV; break; }
        case '*': { op = MULT; break; }
    }

    return op;

}


