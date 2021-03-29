#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include "sort.h"

int main(void)
{
    int numbers[] = {20, 2, 31, 30, 132, 3};
    qsort(numbers, 6, sizeof(int), compare_numbers);

    puts("These are the numbers in order: ");

    for (int i = 0; i < 6; i++)
    {
        printf("%i\n", numbers[i]);
    }

    char* names[] = {"David", "Alice", "Charlie", "Bob"};
    qsort(names, 4, sizeof(char*), compare_names);
    puts("These are the names in alphabetical order: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
