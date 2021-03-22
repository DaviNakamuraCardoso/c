/* Keeps track of the champagne available in stock*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stock = 180;
    int order;

    while (stock > 0)
    {
        printf("The current stock is: %i\n", stock);
        scanf("%i", &order);

        stock = stock - order;

        printf("You ordered %i glasses\n", order);
    }
    puts("We are out of stock, baby!");

    return 0;
}
