typedef struct _game
{
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE  *queue;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT *font;

    ALLEGRO_COLOR color;
    ALLEGRO_EVENT event;

    unsigned int redraw:1;
    long double previous;

    SPACESHIP* spaceship;

    // Asteroids
    void* asteroids;
    double asteroid_cooldown;
    unsigned int asteroid_count:8;

} GAME;


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

GAME* setup(void);

unsigned int update(GAME* game);
void check_collisions(GAME* game, long double dt);

// Graphic functions
void draw(GAME* game);
void display_points(GAME* game);


// Setup
void destroy(GAME* game);
