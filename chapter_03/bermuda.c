/* This program checks if a csv row of coordinates is in the bermuda rectangle */
#include <stdio.h>

int main(void)
{
    float latitude;
    float longitude;
    char info[80];


    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    {
        if ((latitude > 26) && (latitude < 34))
        {
            if ((longitude > -76) && (longitude < -64))
            {
                printf("%f,%f,%s\n", latitude, longitude, info);
            }
        }
    }

    return 0;
}
