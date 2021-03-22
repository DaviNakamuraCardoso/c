/* Search for a track in the jukebox */
#include <stdio.h>
#include <string.h>



char tracks[][80] = {
    "I left my heart in San Francisco",
    "New York, New York - a wonderful town",
    "Dancing with a Dork",
    "The Girl from Ipanema"
}; 

void find_track(char search_for[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (strstr(tracks[i], search_for))
        {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}


int main(void)
{
    char search_for[80];
    printf("Seach for: ");
    scanf("%79s", search_for);
    find_track(search_for);

    return 0;

}
