typedef struct _spaceship
{
    float sx;
    float sy;
    float heading;
    float speed;
    unsigned int gone:1;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP* bitmap;
} SPACESHIP;

SPACESHIP* init_spaceship(void);
void update_spaceship(SPACESHIP* s, ALLEGRO_EVENT event, long double dt); 
void draw_spaceship(SPACESHIP* s);
