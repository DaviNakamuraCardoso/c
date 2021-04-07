#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <blasts.h>

#define size 10

float pi(float deg)
{
    return (3.14 * (deg / 180));
}

BLAST* init_blast(SPACESHIP* s)
{
    BLAST* b;
    b = malloc(sizeof(BLAST));

    b->sx = s->sx;
    b->sy = s->sy;
    b->heading = s->heading;
    b->speed = 400;
    b->gone = 0;
    b->color = al_map_rgb(250, 56, 163);
    b->next = NULL;

    return b;

}

void update_blast(BLAST* b, long double dt)
{
    float xo = cos(pi(b->heading + 90));
    float yo = sin(pi(b->heading + 90));

    b->sx -= xo * b->speed * dt;
    b->sy += yo * b->speed * dt;

    if (b->sx >= WINDOW_WIDTH + size)
    {
        b->sx = 0;
    }
    else if (b->sx <= 0 - size)
    {
        b->sx = WINDOW_WIDTH;
    }

    if (b->sy >= WINDOW_HEIGHT + size)
    {
        b->sy = 0;
    }
    else if (b->sy <= 0 - size)
    {
        b->sy = WINDOW_HEIGHT;
    }

    return;
}

void draw_blast(BLAST* b)
{
    float x = b->sx;
    float y = b->sy;

    float xo = cos(pi(b->heading + 90));
    float yo = sin(pi(b->heading + 90));

    float thickness = 3.0;

    al_draw_line(x, y, x - (size * xo), y + (size * yo), b->color, thickness);

    return;
}
