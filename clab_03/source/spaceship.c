#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <spaceship.h>
#include <blasteroids.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))


float pi(float deg)
{
    return (3.14 * (deg / 180));
}

SPACESHIP* init_spaceship(void)
{
    al_init_primitives_addon();
    SPACESHIP* s;
    s = malloc(sizeof(SPACESHIP));

    // The spaceship starts at the center of the screen
    s->sx = WINDOW_WIDTH / 2;
    s->sy = WINDOW_HEIGHT / 2;

    // 0 degree of inclination, 30 pixels of speed
    s->heading = 0;
    s->speed = 90;

    // Alive
    s->gone = 0;

    // Green
    s->color = al_map_rgb(170, 255, 170);
    s->bitmap = al_create_bitmap(20, 30);

    return s;

}

void draw_spaceship(SPACESHIP* s)
{
    float x1 = s->sx;
    float y1 = s->sy;

    float thickness = 3.0;

    float xo = cos(pi(s->heading + 0));
    float yo = sin(pi(s->heading + 0));

    printf("Xo is %f and Yo is %f\n", xo, yo);

    float xo2 = cos(pi(s->heading + 50));
    float yo2 = sin(pi(s->heading + 50));

    int r = 12;


    al_draw_line(x1 - (xo * r), y1 + (yo * r), x1 + (xo * r), y1 - (yo * r), s->color, thickness);
    al_draw_line(x1 + (xo * r), y1 - (yo * r), x1 + (xo * r), y1 + (yo * r), s->color, thickness);
    // al_draw_line(x1+-6, y1+4, x1-1, y1+4, s->color, thickness);
    // al_draw_line(x1+6, y1+4, x1+1, y1+4, s->color, thickness);
    return;
}


void update_spaceship(SPACESHIP* s, ALLEGRO_EVENT event, long double dt)
{
    float incline_x = cos(pi(s->heading+90));
    float incline_y = sin(pi(s->heading+90));

    s->sx += (s->speed* dt * incline_x);
    s->sy -= (s->speed* dt * incline_y);

    switch (event.keyboard.keycode)
    {
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_W:
        {
            s->speed = MIN(200, s->speed + 5);
            break;
        }
        case ALLEGRO_KEY_DOWN:
        case ALLEGRO_KEY_S:
        {
            s->speed = MAX(5, s->speed - 5);
            break;
        }
        case ALLEGRO_KEY_LEFT:
        case ALLEGRO_KEY_A:
        {
            s->heading += 10 * (dt) * 5;
            break;
        }
        case ALLEGRO_KEY_RIGHT:
        case ALLEGRO_KEY_D:
        {
            s->heading -= 10 * (dt) * 5;
            break;
        }
    }

    if (s->sy >= WINDOW_HEIGHT)
    {
        s->sy = 0;
    }
    else if (s->sy <= 0)
    {
        s->sy = WINDOW_HEIGHT;
    }
    if (s->sx <= 0)
    {
        s->sx = WINDOW_WIDTH;
    }
    else if (s->sx >= WINDOW_WIDTH)
    {
        s->sx = 0;
    }

    return;
}
