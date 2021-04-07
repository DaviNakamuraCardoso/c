#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <blasts.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))
#define r 30


float local_pi(float deg)
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
    s->speed = 150;

    // Alive
    s->gone = 0;

    // Green
    s->color = al_map_rgb(170, 255, 170);
    s->bitmap = al_create_bitmap(20, 30);

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

    float xo = cos(local_pi(s->heading + 70));
    float yo = sin(local_pi(s->heading + 70));

    float xo2 = cos(local_pi(s->heading + 110));
    float yo2 = sin(local_pi(s->heading + 110));


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
    float incline_x = cos(local_pi(s->heading+90));
    float incline_y = sin(local_pi(s->heading+90));

    s->sx -= (s->speed* dt * incline_x);
    s->sy += (s->speed* dt * incline_y);

    switch (event.keyboard.keycode)
    {
        case ALLEGRO_KEY_UP:
        case ALLEGRO_KEY_W:
        {
            s->speed = MIN(400, s->speed + 50 * dt);
            break;
        }
        case ALLEGRO_KEY_DOWN:
        case ALLEGRO_KEY_S:
        {
            s->speed = MAX(10, s->speed - 50 * dt);
            break;
        }
        case ALLEGRO_KEY_LEFT:
        case ALLEGRO_KEY_A:
        {
            s->heading += 10 * (dt) * 25;
            break;
        }
        case ALLEGRO_KEY_RIGHT:
        case ALLEGRO_KEY_D:
        {
            s->heading -= 10 * (dt) * 25;
            break;
        }
        case ALLEGRO_KEY_SPACE:
        {
            shoot(s);
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

    s->shoot_cooldown = 0.5;
    return;
}

void update_all_blasts(SPACESHIP* s, long double dt)
{
    BLAST* current = s->blasts;
    while (current != NULL)
    {
        update_blast(current, dt);
        current = current->next;
    }

    s->shoot_cooldown = MAX(0, s->shoot_cooldown - dt);
    return;

}

void draw_all_blasts(SPACESHIP* s)
{
    BLAST* current = s->blasts;
    while (current != NULL)
    {
        draw_blast(current);
        current = current->next;
    }

    return;
}


void destroy_spaceship(SPACESHIP* s)
{
    if (s != NULL)
    {
        free(s);
    }

    return;
}
