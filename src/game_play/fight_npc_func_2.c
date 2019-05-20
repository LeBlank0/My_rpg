/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fight_npc_func_2
*/

#include "rpg.h"
#include "my.h"

void redirection_fight_npc_3(main_t *m, float *time_fight)
{
    if (m->combat->pokemon[1]->pokemon[0] == 0) {
        launch_fight(m, time_fight, (int[3]){2, 1, 1001},
        (int[3]){5, 5, 1001}, 2);
    }
    if (m->combat->pokemon[1]->pokemon[0] == 1) {
        launch_fight(m, time_fight, (int[3]){0, 2, 1001},
        (int[3]){5, 5, 1001}, 2);
    }
    if (m->combat->pokemon[1]->pokemon[0] == 2) {
        launch_fight(m, time_fight, (int[3]){1, 0, 1001},
        (int[3]){5, 5, 1001}, 2);
    }
}

void redirection_fight_npc_6(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){21, 21, 1001},
    (int[3]){8, 8, 1001}, 2);
}

void redirection_fight_npc_7(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){21, 21, 1001},
    (int[3]){10, 10, 1001}, 2);
}

void redirection_fight_npc_8(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[3]){21, 22, 1001},
    (int[3]){8, 9, 1001}, 2);
}

void redirection_fight_npc_9(main_t *m, float *time_fight)
{
    launch_fight(m, time_fight, (int[4]){21, 21, 22, 1001},
    (int[4]){12, 13, 15, 1001}, 3);
}