/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_npc_func
*/

#include "rpg.h"
#include "my.h"

void fight_npc_func(main_t *m, float *time_fight)
{
    int pnj[11] = {3, 6, 7, 8, 9, 10, 11, 12, 13, 98, -1};
    void (*flag[11])(main_t *, float *) = {redirection_fight_npc_3,
        redirection_fight_npc_6, redirection_fight_npc_7,
        redirection_fight_npc_8, redirection_fight_npc_9,
        redirection_fight_npc_10, redirection_fight_npc_11,
        redirection_fight_npc_12, redirection_fight_npc_13,
        redirection_fight_npc_98, NULL};

    for (int i = 0; pnj[i] != -1; i += 1) {
        if (m->game->pnj == pnj[i]) {
            flag[i](m, time_fight);
            m->game->fight_npc = true;
            break;
        }
    }
}
