#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <stdlib.h>
#include <math.h>
#include <mathutils.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <asteroids.h>


ASTEROID* init_asteroid(ASTEROID* previous)
{
    ASTEROID* a;
    a = malloc(sizeof(ASTEROID));

    // Common definitions
    a->color = al_map_rgb(170, 170, 170);

    float max = 360;
    a->heading = ((float) random());
    a->twist = 0;

    a->gone = 0;

    if (previous == NULL)
    {
        a->speed = 100;

        // Starts at random position
        a->sx = (random() % 2 == 0) ? (random() + WINDOW_WIDTH) : (-random());
        a->sy = random();

        a->scale = 2;
        a->rot_velocity = 5;

        return a;
    }
    // Start at same position as previous
    a->sx = previous->sx;
    a->sy = previous->sy;

    a->scale = previous->scale * reverse_root(2);
    a->rot_velocity = previous->rot_velocity * 1.5;

    a->speed = previous->speed * 1.5;

    return a;
}


void draw_asteroid(ASTEROID* a)
{
    ALLEGRO_TRANSFORM transform, original;

    original = *al_get_current_transform();
    al_identity_transform(&transform);
    al_scale_transform(&transform, a->scale, a->scale);
    al_translate_transform(&transform, (a->sx), (a->sy));
    al_translate_transform(&transform, -(a->sx+(20 * a->scale)), -(a->sy-(20 * a->scale)));
    al_rotate_transform(&transform, pi(a->twist));
    al_translate_transform(&transform, (a->sx+(20 * a->scale)), (a->sy-(20*a->scale)));

    al_use_transform(&transform);

    al_draw_line(-20, 20, -25, 5, a->color, 2.0f);
    al_draw_line(-25, 5, -25, -10, a->color, 2.0f);
    al_draw_line(-25, -10, -5, -10, a->color, 2.0f);
    al_draw_line(-5, -10, -10, -20, a->color, 2.0f);
    al_draw_line(-10, -20, 5, -20, a->color, 2.0f);
    al_draw_line(5, -20, 20, -10, a->color, 2.0f);
    al_draw_line(20, -10, 20, -5, a->color, 2.0f);
    al_draw_line(20, -5, 0, 0, a->color, 2.0f);
    al_draw_line(0, 0, 20, 10, a->color, 2.0f);
    al_draw_line(20, 10, 10, 20, a->color, 2.0f);
    al_draw_line(10, 20, 0, 15, a->color, 2.0f);
    al_draw_line(0, 15, -20, 20, a->color, 2.0f);

    al_use_transform(&original);
}

void cicle_asteroids(GAME* game, void (*handler) (ASTEROID*))
{
    ASTEROID * previous = (ASTEROID *)game->asteroids;
    while (previous != NULL)
    {
        handler(previous);
        previous = previous->next;
    }
    return;
}


void update_asteroid(ASTEROID* a, long double dt)
{
    float incline_x = cos(pi(a->heading + 90));
    float incline_y = sin(pi(a->heading + 90));

    a->sx += incline_x * dt * a->speed;
    a->sy += incline_y * dt * a->speed;

    a->twist = a->twist + a->rot_velocity * dt * 10;
    a->speed = MIN(a->speed, 200);

    check_bounds(&(a->sx), &(a->sy), a->scale*50);

    return;
}

void update_all_asteroids(GAME* game, long double dt)
{
    ASTEROID* previous = (ASTEROID *) game->asteroids;
    while (previous != NULL)
    {
        update_asteroid(previous, dt);
        previous = previous->next;
    }

    game->asteroid_cooldown -= dt;

    if (game->asteroid_cooldown <= 0 && game->asteroid_count <= 5)
    {
        ASTEROID* a = init_asteroid(NULL);
        add_asteroid(game, a);
        game->asteroid_cooldown = 3;
    }

    return;
}

void add_asteroid(GAME* game, ASTEROID* a)
{
    if (a->scale < 0.5)
    {
        destroy_asteroid(game, a);
        return;
    }
    ASTEROID* tmp = (ASTEROID*) game->asteroids;
    game->asteroids = a;
    a->next = tmp;

    game->asteroid_count++;

    return;
}


float get_distance(ASTEROID* a, ASTEROID* b)
{
    float center_xa, center_ya, center_xb, center_yb, dist;

    // Center a
    float* center_a = asteroid_center(a);
    center_xa = center_a[0];
    center_ya = center_a[1];

    // Center b
    float* center_b = asteroid_center(b);
    center_xb = center_b[0];
    center_yb = center_b[1];

    dist = distance(center_xa, center_ya, center_xb, center_yb);

    free(center_a);
    free(center_b);

    return dist;

}

void destroy_asteroid(GAME* game, ASTEROID* a)
{
    if (a == NULL)
    {
        return;
    }

    ASTEROID* current = (ASTEROID*) game->asteroids;
    if (a == current)
    {
        game->asteroids = a->next;
        free(a);
        return;
    }

    while (current->next != a)
    {
        current = current->next;
        if (current ==  NULL)
        {
            return;
        }
    }

    current->next = a->next;

    free(a);
    game->asteroid_count--;


    return;
}

float* asteroid_center(ASTEROID* a)
{
    float* coordinates = malloc(2*sizeof(float));
    // Center a
    float ratio = 20*a->scale;

    float point_xa = a->sx + ratio - cos(pi(a->twist)) * ratio ;
    float point_ya = a->sy - ratio - sin(pi(a->twist)) * ratio ;
    float center_xa = point_xa + cos(pi(a->twist+90)) * ratio;
    float center_ya = point_ya + sin(pi(a->twist+90)) * ratio;

    coordinates[0] = center_xa;
    coordinates[1] = center_ya;

    return coordinates;
}


void blow(GAME* game, ASTEROID* a)
{
    ASTEROID* child1;
    ASTEROID* child2;

    if (a->scale <= 1)
    {
        destroy_asteroid(game, a);
        return;
    }

    child1 = init_asteroid(a);
    child2 = init_asteroid(a);

    destroy_asteroid(game, a);
    
    add_asteroid(game, child1);
    add_asteroid(game, child2);


    return;
}
