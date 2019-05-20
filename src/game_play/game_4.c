/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_4
*/

#include "rpg.h"
#include "my.h"

void menu_pause_2(int i, main_t *m)
{
    if (i == 5)
        sfSprite_setPosition(SP_MENU_INTRO[i], (sfVector2f) {600,
            m->game->coord});
}

void game_play_bis_2(main_t *m)
{
    for (size_t i = 0; i < 6; i++)
        m->combat->pokemon[1]->pokemon_pv[i] =
        m->combat->pokemon[1]->pokemon_pv_max[i];
}
