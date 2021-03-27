typedef struct _song
{
    char* name;
    struct _song* next;
} SONG;


SONG* create(char* name);
void display(SONG* start);
void add_song(SONG** head, SONG* new);
void release(SONG* start);
