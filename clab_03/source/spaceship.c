#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mathutils.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <blasts.h>

#define r 30


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
    s->speed = 50;
    s->acceleration = 5.0;
    s->acceleration_heading = 0;

    // Alive
    s->gone = 0;
    s->lives = 3;

    // Green
    s->color = al_map_rgb(170, 255, 170);

    // No blasts and 0 for cooldown timer
    s->blasts = NULL;
    s->shoot_cooldown = 0;

    return s;
}

void draw_spaceship(SPACESHIP* s)
{
    float x1 = s->sx;
    float y1 = s->sy;

    float thickness = 3.0;

    float xo = cos(pi(s->heading + 70));
    float yo = sin(pi(s->heading + 70));

    float xo2 = cos(pi(s->heading + 110));
    float yo2 = sin(pi(s->heading + 110));


    al_draw_line(x1 + (xo2 * r), y1 - (yo2 * r), x1, y1, s->color, thickness);
    al_draw_line(x1, y1, x1 + (xo * r), y1 - (yo * r), s->color, thickness);
    al_draw_line(x1 + (xo2* r/ 1.3), y1 - (yo2 * r / 1.3), x1 + (xo * r / 1.3), y1 - (yo * r / 1.3), s->color, thickness);
    al_draw_line((x1 + (xo2* r/ 1.4) + x1 + (xo * r / 1.4)) / 2,
    (y1 - (yo2 * r / 1.4) + y1 - (yo * r / 1.4)) / 2, (x1 + (xo2 * r) + x1 + (xo * r)) / 2, (y1 - (yo * r) + y1 - (yo2 * r)) / 2, al_map_rgb(19, 22, 45), thickness);


    draw_all_blasts(s);

    return;

}


void update_spaceship(SPACESHIP* s, ALLEGRO_EVENT event, long double dt)
{
    float incline_x = cos(pi(s->acceleration_heading+90));
    float incline_y = sin(pi(s->acceleration_heading+90));

    s->speed = MAX(70, s->speed + s->acceleration * dt);

    s->sx -= (s->speed* dt * incline_x) + (s->acceleration) * pow(dt, 2) / 2;
    s->sy += (s->speed* dt * incline_y) + (s->acceleration) * pow(dt, 2) / 2;


    switch (event.keyboard.keycode)
    {
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_W:
        {
            s->speed = 800;
            s->acceleration = -1000;
            s->acceleration_heading = s->heading;
            break;
        }
        case ALLEGRO_KEY_DOWN:
        case ALLEGRO_KEY_S:
        {
            s->acceleration = s->acceleration - 100;
            s->acceleration_heading = -s->heading;
            break;
        }
        case ALLEGRO_KEY_LEFT:
        case ALLEGRO_KEY_A:
        {
            s->heading += 10 * (dt) * 50;
            break;
        }
        case ALLEGRO_KEY_RIGHT:
        case ALLEGRO_KEY_D:
        {
            s->heading -= 10 * (dt) * 50;
            break;
        }
        case ALLEGRO_KEY_SPACE:
        {
            shoot(s);
            break;
        }
    }


    if (s->sy >= WINDOW_HEIGHT + r)
    {
        s->sy = 0;
    }
    else if (s->sy <= 0 - r)
    {
        s->sy = WINDOW_HEIGHT;
    }
    if (s->sx <= 0 - r)
    {
        s->sx = WINDOW_WIDTH;
    }
    else if (s->sx >= WINDOW_WIDTH + r)
    {
        s->sx = 0;
    }

    update_all_blasts(s, dt);

    return;
}

void shoot(SPACESHIP* s)
{
    if (s->shoot_cooldown > 0)
    {
        return;
    }
    BLAST* b = init_blast(s);
    BLAST* temp = (BLAST *)s->blasts;
    s->blasts = b;
    b->next = temp;

    s->shoot_cooldown = 0.2;
    return;
}

void update_all_blasts(SPACESHIP* s, long double dt)
{
    BLAST* current = (BLAST*) s->blasts;
    while (current != NULL)
    {
        BLAST* tmp = current->next;
        update_blast(s, current, dt);

        current = tmp;
    }

    s->shoot_cooldown = MAX(0, s->shoot_cooldown - dt);
    return;

}

void draw_all_blasts(SPACESHIP* s)
{
    BLAST* current = (BLAST* )s->blasts;
    while (current != NULL)
    {
        draw_blast(current);
        current = current->next;
    }

    return;
}


void destroy_spaceship(SPACESHIP* s)
{
    BLAST* b = (BLAST*) s->blasts;
    while (b != NULL)
    {
        BLAST* tmp = b->next;
        free(b);
        b = tmp;
    }
    if (s != NULL)
    {
        free(s);
    }


    return;
}
