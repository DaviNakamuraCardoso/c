#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>
#include <mathutils.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <blasts.h>

#define size 10


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

void update_blast(SPACESHIP* s, BLAST* b, long double dt)
{
    float xo = cos(pi(b->heading + 90));
    float yo = sin(pi(b->heading + 90));

    b->sx -= xo * b->speed * dt;
    b->sy += yo * b->speed * dt;

    if (b->sx >= WINDOW_WIDTH + size)
    {
        destroy_blast(s, b);
    }
    else if (b->sx <= 0 - size)
    {
        destroy_blast(s, b);
    }

    if (b->sy >= WINDOW_HEIGHT + size)
    {
        destroy_blast(s, b);
    }
    else if (b->sy <= 0 - size)
    {
        destroy_blast(s, b);
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

void destroy_blast(SPACESHIP* s, BLAST* b)
{
    BLAST* current = (BLAST*) s->blasts;
    if (current == NULL)
    {
        return;
    }
    else if (current == b)
    {
        s->blasts = b->next;
        free(b);
        return;
    }
    while ((current->next) != b)
    {
        current = current->next;
        if (current == NULL)
        {
            return;
        }
    }

    current->next = b->next;

    free(b);
    return;
}
