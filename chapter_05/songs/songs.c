/* This program stores songs */
#include <stdio.h>
#include "songs.h"


typedef struct _artist
{
    const char *name;
    unsigned short year_of_birth;

} ARTIST;


typedef struct _band
{
    const char* band_name;
    ARTIST* members[10];
} BAND;



typedef enum
{
    B, A
} RELEASER_TYPE;


typedef union
{
    BAND* band;
    ARTIST* artist;

} RELEASER;


typedef struct _song
{
    const char *name;
    unsigned short year_of_release;
    RELEASER* releaser;
    RELEASER_TYPE type;

} SONG;


void song_catalog(SONG* s)
{

    if (s->type == A)
    {
        printf("Song: %s\nArtist: %s\nReleased: %i\n",
            s->name, s->releaser->artist->name, s->year_of_release
        );
    }
    else
    {
        printf("Song: %s\nBand: %s\nReleased: %i\n",
            s->name, s->releaser->band->band_name, s->year_of_release
        );
    }

    return;
}


int main(void)
{
    ARTIST frank = {"Frank Sinatra", 1915};

    RELEASER fs = {.artist=&frank};

    SONG my_way = {"My Way", 1969, &fs, A};

    ARTIST lv = {"LaVerne Andrews", 1911};
    ARTIST mx = {"Maxene Andrews", 1916,};
    ARTIST p = {"Patty Andrews", 1918};

    ARTIST* group[10];
    group[0] = &lv;
    group[1] = &mx;
    group[2] = &p;

    BAND tas = {"The Andrew Sisters", group};
    RELEASER t = {.band=&tas};

    SONG racc = {"Rum and Coca Cola", 1945, &t, B};


    song_catalog(&my_way);
    song_catalog(&racc);

    return 0;
}
