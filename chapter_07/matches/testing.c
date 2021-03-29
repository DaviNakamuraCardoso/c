#include <stdio.h>
#include <string.h>

unsigned int sports_no_bieber(char* s)
{
    return (strstr(s, "sports") && !strstr(s, "bieber"));
}

unsigned int sports_or_workout(char* s)
{
    return (strstr(s, "sports") || strstr(s, "working out"));
}

unsigned int ns_theater(char* s)
{
    return (strstr(s, "NS") && strstr(s, "theater"));
}

unsigned int arts_theater_or_dining(char* s)
{
    return (strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining"));
}
