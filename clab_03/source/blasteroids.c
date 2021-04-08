#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <stdlib.h>
#include <spaceship.h>
#include <blasteroids.h>
#include <asteroids.h>
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

    // Create the game structure
    GAME* game;
    game = malloc(sizeof(GAME));

    // Set all the game variables
    game->timer = al_create_timer(1.0/60.0);
    game->queue = al_create_event_queue();
    game->font = al_create_builtin_font();
    game->display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
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

    check_collisions(game);

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

    destroy_spaceship(game->spaceship);
    free(game);

    return;
}


void check_collisions(GAME* game)
{
    ASTEROID* a = (ASTEROID*) game->asteroids;

    while (a != NULL)
    {
        ASTEROID* b = (ASTEROID* ) game->asteroids;
        while (b != NULL)
        {
            if (a != b)
            {
                float center_ax = a->sx + (20*a->scale*cos(pi(a->twist)));
                float center_ay = a->sy + (20*a->scale*sin(pi(a->twist)));
                float center_bx = b->sx + (20*b->scale*cos(pi(b->twist)));
                float center_by = b->sy + (20*b->scale*sin(pi(b->twist)));

                float dist = sqrt(pow(center_ax-center_bx, 2) + pow(center_ay-center_by, 2));
                if ((dist) < (20*a->scale + 20*b->scale))
                {
                    a->heading -= 180;
                    b->heading -= 180;

                    a->sx += cos(pi(a->heading)) * 30;
                    b->sx += cos(pi(b->heading)) * 30;
                }

            }
            b = b->next;
        }
        a = a->next;
    }

    return;
}
