#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int by_rows(int **nums, size_t width, size_t height)
{
    int sum = 0;

    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < height; j++)
        {
            sum += nums[i][j];
        }
    }

    return sum;
}

int by_cols(int **nums, size_t width, size_t height)
{
    int sum = 0; 

    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < height; j++)
        {
            sum += nums[j][i];
        }
    }

    return sum;
}


int main(int argc, const char** argv)
{
    size_t length = atol(argv[1]); 

    int **matrix = malloc(length * sizeof(int*));
    for (size_t i = 0; i < length; i++) matrix[i] = malloc(length * sizeof(int));


    clock_t start = clock(); 

    by_rows(matrix, length, length);

    printf("By rows: %f\n", (double) (clock() - start) / 
CLOCKS_PER_SEC);

    start = clock();

    by_cols(matrix, length, length);

    printf("By cols: %f\n", (double) (clock() - start) / CLOCKS_PER_SEC);

    return 0;
} 

