#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <asteroids.h>
#include <blasts.h>
#include <mathutils.h>
#include <math.h>


int main(void)
{

    GAME* game = setup();
    SPACESHIP* s = init_spaceship();

    game->spaceship = s;

    while (1)
    {
        if (update(game)) {break;}
        draw(game);
    }

    destroy(game);

    return 0;
}

GAME* setup(void)
{
    // Allegro init functions
    al_init();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();

    // Create the game structure
    GAME* game;
    game = malloc(sizeof(GAME));

    // Set all the game variables
    game->timer = al_create_timer(1.0/60.0);
    game->queue = al_create_event_queue();
    game->font = al_load_ttf_font("./fonts/gamer.ttf", 70, 0);
    game->display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    game->color = al_map_rgb(255, 255, 255);
    game->redraw = 1;
    game->event;

    // Register the event sources (keyboard, display, timer)
    al_register_event_source(game->queue, al_get_keyboard_event_source());
    al_register_event_source(game->queue, al_get_display_event_source(game->display));
    al_register_event_source(game->queue, al_get_timer_event_source(game->timer));

    // Start the timer
    al_start_timer(game->timer);

    long double time = al_get_timer_count(game->timer) * (1.0) / 60.0;
    game->previous = time;

    game->asteroids = NULL;
    game->asteroid_count = 0;

    game->asteroid_cooldown = 3;

    return game;

}


unsigned int update(GAME* game)
{
    long double time = al_get_timer_count(game->timer) * (1.0) / 60.0;
    long double dt = time - (game->previous);
    al_wait_for_event(game->queue, &(game->event));

    switch ((game->event).type)
    {
        case ALLEGRO_EVENT_TIMER:
        {
            game->redraw = 1;
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
        {
            return 1;
        }
    }
    game->redraw = 1;
    update_spaceship(game->spaceship, game->event, dt);
    update_all_asteroids(game, dt);

    check_collisions(game, dt);

    // Update timer
    game->previous = time;


    return 0;
}


void draw(GAME* game)
{
    if(game->redraw && al_is_event_queue_empty(game->queue))
    {
        al_clear_to_color(al_map_rgb(19, 22, 45));
        draw_spaceship(game->spaceship);
        cicle_asteroids(game, draw_asteroid);

        display_points(game);
        al_flip_display();

        game->redraw = 0;
    }

    return;
}


void destroy(GAME* game)
{
    al_destroy_font(game->font);
    al_destroy_display(game->display);
    al_destroy_timer(game->timer);
    al_destroy_event_queue(game->queue);
    al_destroy_font(game->font);

    destroy_spaceship(game->spaceship);

    free(game);

    return;
}


void check_collisions(GAME* game, long double dt)
{
    ASTEROID* a = (ASTEROID*) game->asteroids;

    while (a != NULL)
    {
        ASTEROID* a_next = a->next;
        ASTEROID* b = (ASTEROID* ) game->asteroids;

        while (b != NULL)
        {
            ASTEROID* b_next  = b->next;
            if (a != b)
            {

                float limit = (25*a->scale + 25*b->scale);
                if (get_distance(a, b) < limit)
                {
                    a->sx = a->sx - a->speed * dt * cos(pi(a->heading + 90));
                    a->sy = a->sy - 4 * a->speed * dt * sin(pi(a->heading + 90));

                    b->sx = b->sx - 4 * b->speed * dt * cos(pi(b->heading + 90));
                    b->sy = b->sy - 4 * b->speed * dt * sin(pi(b->heading + 90));

                    a->heading = a->heading + 180;
                    b->heading = a->heading + 180;

                    int counter = 0;

                    while (get_distance(a, b) < limit)
                    {
                        a->sx = a->sx + 4 * a->speed * dt * cos(pi(a->heading + 90));
                        a->sy = a->sy + 4 * a->speed * dt * sin(pi(a->heading + 90));

                        b->sx = b->sx + 4 * b->speed * dt * cos(pi(b->heading + 90));
                        b->sy = b->sy + 4 * b->speed * dt * sin(pi(b->heading + 90));

                        a->speed *= 1.25;
                        b->speed *= 1.25;
                        counter++;
                        if (counter >= 5)
                        {
                            blow(game, b);
                        }
                    }
                }
            }
            b = b_next;
        }
        BLAST* blast = (BLAST*) (game->spaceship->blasts);
        float* coords = asteroid_center(a);

        while (blast != NULL)
        {
            BLAST* blast_next = blast->next;
            float d = distance(blast->sx, blast->sy, coords[0], coords[1]);

            if (d < (a->scale * 25))
            {
                destroy_blast(game->spaceship, blast);
                game->spaceship->points += 50 * a->scale;
                blow(game, a);
            }
            blast = blast_next;
        }

        // Check collisions with the spaceship
        float* s_center = spaceship_center(game->spaceship);

        if (distance(s_center[0], s_center[1], coords[0], coords[1]) < (a->scale * 20) &&
            !game->spaceship->gone)
        {
            game->spaceship->lives--;
            game->spaceship->gone = 1;
        }

        free(s_center);
        free(coords);

        a = a_next;
    }
    return;
}


void display_points(GAME* game)
{
    SPACESHIP* s = game->spaceship;

    if (s->point_counter < s->points)
    {
        s->point_counter += 2;
    }

    char points[30];
    sprintf(points, "%i", s->point_counter);
    al_draw_text(game->font, game->color, 20, 20, 40, points);
    return;

}
