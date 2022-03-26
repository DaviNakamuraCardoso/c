#include <stdio.h>
#include <stdlib.h>


static void quicksort(int *src, int* dst, size_t length)
{
    if (length <= 1) return;

    int pivot = src[length-1];
    size_t sp = 0, bp;

    for (size_t i = 0; i < length - 1; i++)
        if (src[i] <= pivot) dst[sp++] = src[i];
    
    bp = sp;
    dst[sp++] = pivot; 

    for (size_t i = 0; i < length - 1; i++)
        if (src[i] > pivot) dst[sp++] = src[i];

    quicksort(dst, src, bp);
    quicksort(dst+bp, src+bp, length - bp); 
}


void sorted(int* src, size_t length)
{
    int *dst = malloc(sizeof(int) * length);
    quicksort(src, dst, length);

    for (size_t i = 0; i < length; i++) src[i] = dst[i];

    free(dst);
}

void printl(int *a, size_t length)
{ 
    for (size_t i = 0; i < length; i++) printf("%d,", a[i]);
    printf("\n");
}

int main(void) 
{
    int a[] = {1, 3, 3, 3, 452, 23, 2, 2, 9, 123, 34, 7};
    // {1, 3, 2, 2, 7, 452, 23, 9, 123, 34}

#define LENGTH sizeof(a) / sizeof(int)

    sorted(a, LENGTH);

    printl(a, LENGTH);

    return 0;
}
