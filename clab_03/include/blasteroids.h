typedef struct _game
{
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE  *queue;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT *font;
    ALLEGRO_EVENT event;
    unsigned int redraw:1;
    long double previous; 
    SPACESHIP* spaceship;

} GAME;

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720


GAME* setup(void);
unsigned int update(GAME* game);
void draw(GAME* game);
void destroy(GAME* game);
