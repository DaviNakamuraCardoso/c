/* Functions to determine if a value is greater than or equal other */
#include <stdio.h>
#include <string.h>
#include "helper.h"

int compare_names(const void* a, const void* b)
{
    char** name_a = (char**)a;
    char** name_b = (char**)b;

    return strcmp(*name_a, *name_b);
}

int compare_numbers(const void* a, const void* b)
{
    int na = *(int*)a;
    int nb = *(int*)b;

    return na-nb;
}
