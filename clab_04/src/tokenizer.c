#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer.h>

static enum operation ctoop(char c);


token_t* token(enum type ty, const void* a)
{
    token_t* t = malloc(sizeof(token_t));
    t->t = ty;

    switch (ty)
    {
        case NUMBER: 
        {
            t->value = *(ld_t*)a; break;
        }
        case SYMBOL:
        {
            t->op = *(enum operation*) a; break;
        }
    }

    return t;


}

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

    return token(NUMBER, strtold(buff, NULL));

}

token_t* getop(FILE* f)
{

    char c = fgetc(f);
    return token(SYMBOL, ctoop(c));

}

unsigned int tokenize(FILE* f, token_t** tokens)
{
   char c;
   int i; 

   for (i = 0; (c = fgetc(f)) != '\n';)
   {
       if (c == EOF) return i;
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


