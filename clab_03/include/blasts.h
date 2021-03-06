typedef struct _blast
{
    float sx;
    float sy;
    float heading;
    float speed;
    unsigned int gone:1;
    ALLEGRO_COLOR color;
    struct _blast* next;
} BLAST;

BLAST* init_blast(SPACESHIP* s);
void destroy_blast(SPACESHIP* s, BLAST* b);
void update_blast(SPACESHIP* s, BLAST* b, long double dt);
void draw_blast(BLAST* b);
