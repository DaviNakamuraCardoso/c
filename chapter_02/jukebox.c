/* Search for a track in the jukebox */
#include <stdio.h>
#include <string.h>



const int length = 6;
char tracks[][80] = {
    "I left my heart in San Francisco",
    "(Theme from) New York, New York",
    "Dancing in the Dark",
    "The Girl from Ipanema",
    "My Way",
    "That's Life"
};


void find_track(char search_for[])
{
    int i;
    for (i = 0; i < length; i++)
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
