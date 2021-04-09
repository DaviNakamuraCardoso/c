typedef struct _asteroid
{
    float sx;
    float sy;
    float heading;
    float twist;
    float speed;
    float rot_velocity;
    float scale;
    unsigned int gone:1;
    ALLEGRO_COLOR color;
    struct _asteroid* next;

} ASTEROID;

ASTEROID* init_asteroid(ASTEROID* previous);
void add_asteroid(GAME* game, ASTEROID* a);

// Graphic functions
void draw_asteroid(ASTEROID* a);

// Procedural behavior
void update_asteroid(ASTEROID* a, long double dt);
void update_all_asteroids(GAME* game, long double dt);

void cicle_asteroids(GAME* game, void (*handler) (ASTEROID*));
float get_distance(ASTEROID* a, ASTEROID* b);
float* asteroid_center(ASTEROID* a);
void destroy_asteroid(GAME* game, ASTEROID* a);

void blow(GAME* game, ASTEROID* a); 
