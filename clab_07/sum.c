#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int superior(int *nums, unsigned int length)
{
    int sum = 0;
    for (unsigned int i = 0; i < length; i++)
        sum += nums[i];

    return sum;
}

int inferior(int *nums, unsigned int start, unsigned int end)
{
    if (start == end) return nums[end];
    return nums[start] + inferior(nums, start+1, end);
} 

int main(int argc, const char** argv)
{
    unsigned int length = atoi(argv[1]);
    int *huge = calloc(sizeof(int), length);
    double suptime, inftime;

    clock_t start = clock();

    superior(huge, length);

    suptime = (double) (clock() - start) / CLOCKS_PER_SEC;

    printf("Superior: %f\n", suptime);

    start = clock();

    if (length > 100000) 
    {
        printf("The recursive solution is likely to segfault\n");
        return 0;
    }

    inferior(huge, 0, length);

    inftime = (double) (clock() - start) / CLOCKS_PER_SEC;

    printf("Inferior: %f\n", inftime);

    return 0; 
}
