/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** options.c
*/

#include "rpg.h"
#include "my.h"

void print_option(main_t *m)
{
    float y = 185;
    float x = 100;

    for (int i = 0; i < NB_TEXT_OPTION; i++) {
        sfText_setPosition(TEXT[i], (sfVector2f){x, y});
        x += 100;
        if (i == 0)
            x += 200;
        if (i == 4)
            x += 200;
        if (i == 3) {
            y += 80;
            x = 100;
        }
        sfText_setPosition(TEXT[8], (sfVector2f){100, 425});
        sfText_setPosition(TEXT[9], (sfVector2f) {100, 345});
        sfRenderWindow_drawText(WINDOW, TEXT[i], NULL);
    }
    sfSprite_setPosition(SP_MENU_INTRO[2], (sfVector2f){X, COORD});
}

int option_display(main_t *m)
{
    sfRenderWindow_drawSprite(WINDOW, SP_MENU_INTRO[1], NULL);
    print_option(m);
    sfSprite_setColor(SP_MENU_INTRO[2], (sfColor){0, 0, 0, 68});
    select_set(m);
    check_set(m, P1, P2);
    sfMusic_setVolume(m->intro->song, VOLUME);
    sfMusic_setVolume(m->intro->song_game, VOLUME);
    sfMusic_setVolume(m->intro->song_rayquaza, VOLUME);
    sfMusic_setVolume(m->intro->song_fight, VOLUME);
    sfRenderWindow_setFramerateLimit(WINDOW, FPS);
    sfRenderWindow_drawSprite(WINDOW, SP_MENU_INTRO[2], NULL);
    return (0);
}

int how_to_play(main_t *m)
{
    sfRenderWindow_drawSprite(WINDOW, SP_MENU_INTRO[3], NULL);
    sfRenderWindow_display(WINDOW);
    return (0);
}