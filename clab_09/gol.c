#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

size_t indexof(size_t n, size_t size);

typedef enum {
    DEAD,
    ALIVE
} cell_e;

int renderb(cell_e**, size_t);
int updateb(cell_e**, size_t);
cell_e **makeb(size_t size);

int main(void)
{
    printf("Hello, World!\n"); 

    size_t size = 20;

    cell_e **board = makeb(size);
    
    for (;;)
    {
        renderb(board, size);
        updateb(board, size);
        __fpurge(stdout);
    }
    return 0;
}

cell_e **makeb(size_t size)
{ 
    cell_e **board = calloc(size, sizeof(cell_e*));

    for (size_t i = 0; i < size; i++) board[i] = calloc(size, sizeof(cell_e));
    for (size_t i = 0; i < size; i++) for (size_t j = 0; j < size; j++) board[i][j] = rand() % 2;

    return board;
}

int renderb(cell_e **board, size_t size)
{
    for (size_t i = 0; i < size; i++) 
    {
        for (size_t j = 0; j < size; j++) 
        { 
            if (board[i][j]) putchar('#'); else putchar(' ');
        }
        putchar('\n');
    }


    return 0;
}

int updateb(cell_e **board, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            size_t sum = 0;

            for (long k = -3; k < 3; k++)

                sum += board[indexof(i+k, size)][indexof(j+k, size)];

            if (sum > 4 || sum < 2) board[i][j] = DEAD;
            else if (sum == 3) board[i][j] = ALIVE;

        }
    }

    return 0;
}

size_t indexof(size_t n, size_t size)
{
    if (n < 0) return size + n;
    return n % size;
}


