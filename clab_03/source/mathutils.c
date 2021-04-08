#include <math.h>
#include <specs.h>


float pi(float deg)
{
    return (3.14 * (deg / 180));
}

// Quake III algo for fast reverse square root
float reverse_root(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;

    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    y = y * (threehalfs - (x2 * y * y));

    return y;

}


void check_bounds(float* x, float* y, int size)
{
    if ((*x) >= WINDOW_WIDTH + size)
    {
        *x = 0-size;
    }
    else if ((*x) <= 0-size)
    {
        *x = WINDOW_WIDTH;
    }

    if ((*y) >= WINDOW_HEIGHT + size)
    {
        *y = -size;
    }
    else if ((*y) <= 0-size)
    {
        *y = WINDOW_HEIGHT + size;
    }

    return;
}


unsigned short binary_search(int arr[], unsigned short len, int target)
{
    unsigned short start, middle, end;

    start = 0;
    end = len;
    middle = (start + end) / 2;

    while (start < end)
    {
        if (target > arr[middle])
        {
            start = middle + 1;
        }
        else if (target < arr[middle])
        {
            end = middle - 1;
        }
        else
        {
            break;
        }

        middle = (start + end) / 2;
    }

    return middle;
}

int compare_numbers(const void* a, const void* b)
{
    int na = *(int *)a;
    int nb = *(int *)b;

    return (na-nb);
}
