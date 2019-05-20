/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_combat_3
*/

#include "rpg.h"
#include "my.h"

void combat_event_enter_scene_one_2(main_t *m)
{
    if (m->game->pnj == 98)
        sfMusic_stop(m->intro->song_rayquaza);
    else
        sfMusic_stop(m->intro->song_fight);
}