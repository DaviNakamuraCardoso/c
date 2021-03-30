#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coeff)
{
    printf("Weight: %3.2f\n", weight);
    printf("Distance: %3.2f\n", distance);
    printf("Calories Burned: %3.2f\n", coeff * weight * distance);

    return;
}
