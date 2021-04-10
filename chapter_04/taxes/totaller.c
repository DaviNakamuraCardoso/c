/* This program helps to calculate the bills and taxes */
#include <stdio.h>
#include "totaller.h"


float total = 0;
short count = 0;
short tax_percent = 6;


int main(void)
{
    float val;

    printf("Price item: ");
    while (scanf("%f", &val) == 1)
    {
        printf("Total so far: %.2f\n", add_with_tax(val));
        printf("Price of item: ");
    }

    printf("\nFinal total: %.2f\n", total);
    printf("Number of items: %i\n", count);

    return 0;
}


float add_with_tax(float f)
{
    float tax_rate = 1 + tax_percent / 100.0;
    total = total + (f * tax_rate);
    count = count + 1;

    return total;
}
