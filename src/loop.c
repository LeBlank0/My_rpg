/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** loop
*/

#include "rpg.h"
#include "my.h"

int game_loop(main_t *m)
{
    char *ch_scene[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", NULL};
    int (*scene[9])(main_t *) = {intro_emerald, menu_intro, game_play,
        option_display, combat_nature, how_to_play, choice_pokemon, inventory,
        bag};

    while (sfRenderWindow_isOpen(WINDOW)) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        TIME = sfTime_asSeconds(sfClock_getElapsedTime(m->game->clock));
        sfClock_restart(m->game->clock);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            event_game(m);
        for (int i = 0; ch_scene[i] != NULL; i += 1)
            my_strcmp(ch_scene[i], my_itoa(GAME_SCENE)) == 0 ? scene[i](m) : 0;
        sfRenderWindow_display(WINDOW);
    }
    return (0);
}
