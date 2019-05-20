/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** up_move_2
*/

#include "rpg.h"
#include "my.h"

void cm_0(main_t *m)
{
    m->game->the_move = 1;
    m->game->direction = 'u';
    m->game->old_direction = 'n';
}

void cm_9(main_t *m)
{
    int spawn;

    spawn = rand() % 20;
    if (spawn == 5) {
        VER -= 1;
        m->my_game->fight = true;
        m->my_game->move_top_bottom += 56;
        return;
    }
    m->game->the_move = 1;
    m->game->old_direction = 'n';
    m->game->direction = 'u';
}

void cm_2(main_t *m)
{
    HOR_SAVE = HOR;
    VER_SAVE = VER;
    VER = 47;
    HOR = 140;
    m->my_game->save_top = m->my_game->move_top_bottom;
    m->my_game->save_side = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(960 * 3.5) + 200;
    m->my_game->move_left_right = -(2458 * 3.5) + 385;
}

void cm_3(main_t *m)
{
    HOR_SAVE = HOR;
    VER_SAVE = VER;
    VER = 47;
    HOR = 147;
    m->my_game->save_top = m->my_game->move_top_bottom;
    m->my_game->save_side = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(955 * 3.5) + 200;
    m->my_game->move_left_right = -(2711 * 3.5) + 385;
}

void cm_4(main_t *m)
{
    HOR_SAVE = HOR;
    VER_SAVE = VER;
    VER = 80;
    HOR = 148;
    m->my_game->save_top = m->my_game->move_top_bottom;
    m->my_game->save_side = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(1412 * 3.5) + 200 + 76;
    m->my_game->move_left_right = -(2631 * 3.5) + 385 + 54;
}