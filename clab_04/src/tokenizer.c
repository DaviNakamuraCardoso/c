#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer.h>


token_t getnum(FILE* f)
{
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

    printf("Value is %Lf\n", strtold(buff, NULL));

    return (token_t) {.t=NUMBER, .value=strtold(buff, NULL)};

}

token_t getop(FILE* f)
{

    char c = fgetc(f);

    printf("Token is %c\n", c); 

    return (token_t) {.t=SYMBOL};

}

token_t* tokenize(FILE* f, token_t* tokens)
{
   char c;

   for (int i = 0; (c = fgetc(f)) != '\n'; i++)
   {
       if (isblank(c)) continue;
       ungetc(c, f);

       if (isdigit(c)) tokens[i] = getnum(f);
       else tokens[i] = getop(f); 

   }

   return tokens;

}
