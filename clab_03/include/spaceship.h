typedef struct _spaceship
{
    float sx;
    float sy;
    float heading;
    float speed;
    float shoot_cooldown;
    float acceleration;
    float acceleration_heading;

    unsigned int lives:2;
    unsigned int gone:1;
    ALLEGRO_COLOR color;
    void* blasts;


} SPACESHIP;

SPACESHIP* init_spaceship(void);
void update_spaceship(SPACESHIP* s, ALLEGRO_EVENT event, long double dt);
void draw_spaceship(SPACESHIP* s);
void destroy_spaceship(SPACESHIP* s);
void shoot(SPACESHIP* s);
void update_all_blasts(SPACESHIP* s, long double dt);
void draw_all_blasts(SPACESHIP* s);
