/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_npc_func_3
*/

#include "rpg.h"
#include "my.h"

void redirection_fight_npc_10(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){4, 5, 1001},
    (int[3]){6, 7, 1001}, 2);
}

void redirection_fight_npc_11(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){5, 4, 1001},
    (int[3]){7, 7, 1001}, 2);
}

void redirection_fight_npc_12(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){6, 5, 1001},
    (int[3]){7, 8, 1001}, 2);
}

void redirection_fight_npc_13(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){6, 7, 1001},
    (int[3]){8, 8, 1001}, 2);
}

void redirection_fight_npc_98(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[2]){23, 1001},
    (int[2]){70, 1001}, 1);
}
