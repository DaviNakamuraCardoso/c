#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char** argv)
{
    double total = atof(argv[1]);
    int time = atoi(argv[2]);
    double interest = atof(argv[3]) / 100;

    printf("Total: %f\n", total);
    printf("Time: %d\n", time);
    printf("Interest: %f\n", interest); 
    printf("%f\n", total * (powf(1 + interest, (float) time))); 

    return 0;
}
