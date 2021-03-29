#include <stdio.h>
#include "letters.h"
#include "responses.h"

void dump(RESPONSE r)
{
    printf("Dear Mr. %s\n", r.name);
    puts("Unfortunately, your last date contracted us to");
    puts("say that she will not be seeing you again.");
}

void second_chance(RESPONSE r)
{
    printf("Dear Mr. %s\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call us ASAP.");
}

void marriage(RESPONSE r)
{
    printf("Dear Mr. %s\n", r.name);
    puts("Congratulations! Your last date has contacted us");
    puts("with a proposal of marriage.");
}
