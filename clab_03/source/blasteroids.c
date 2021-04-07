#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <stdlib.h>
#include <spaceship.h>
#include <blasteroids.h>


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
    game->timer = al_create_timer(1.0/30.0);
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

    long double time = al_get_timer_count(game->timer) * (1.0) / 30.0;
    game->previous = time;

    return game;

}


unsigned int update(GAME* game)
{
    long double time = al_get_timer_count(game->timer) * (1.0) / 30.0;
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
