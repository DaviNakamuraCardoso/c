/* Get the price of a set of drinks */
#include <stdio.h>
#include <stdarg.h>
#include "drinks.h"


int main(void)
{
    double a = price(1, FUZZY_NAVEL) ;
    double b = price(4, MONKEY_GLAND, MUDSLIDE, MONKEY_GLAND, ZOMBIE);
    double c = price(1, ZOMBIE);
    double d = price(2, ZOMBIE, ZOMBIE);

    printf("Order 1: %f\n", a);
    printf("Order 2: %f\n", b);
    printf("Order 3: %f\n", c);
    printf("Order 4: %f\n", d);

}

double price(int count, ...)
{
    va_list drinks;

    va_start(drinks, count);

    int i;
    double total = 0;

    for (i = 0; i < count; i++)
    {
        total += cost(va_arg(drinks, enum drink));
    }
    va_end(drinks);

    return total;
}

double cost(enum drink d)
{
    switch(d) {
        case MUDSLIDE:
            return 6.79;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
    return 0;
}
