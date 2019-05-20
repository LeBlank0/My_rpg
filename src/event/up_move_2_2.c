/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** up_move_2_2
*/

#include "rpg.h"
#include "my.h"

void cm_5(main_t *m)
{
    HOR_SAVE = HOR;
    VER_SAVE = VER;
    VER = 80;
    HOR = 27;
    m->my_game->save_top = m->my_game->move_top_bottom;
    m->my_game->save_side = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(1464 * 3.5) + 200;
    m->my_game->move_left_right = -(216 * 3.5) + 385;
}

void cm_6(main_t *m)
{
    HOR_SAVE = HOR;
    VER_SAVE = VER;
    VER = 74;
    HOR = 47;
    m->my_game->save_top = m->my_game->move_top_bottom;
    m->my_game->save_side = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(1326 * 3.5) + 200;
    m->my_game->move_left_right = -(572 * 3.5) + 385;
}

void cm_u(main_t *m)
{
    HOR_SAVE_2 = HOR;
    VER_SAVE_2 = VER;
    VER = 31;
    HOR = 141;
    m->my_game->save_top_2 = m->my_game->move_top_bottom;
    m->my_game->save_side_2 = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(612 * 3.5) + 200;
    m->my_game->move_left_right = -(2441 * 3.5) + 385;
}

void cm_uu(main_t *m)
{
    HOR_SAVE_2 = HOR;
    VER_SAVE_2 = VER;
    VER = 31;
    HOR = 148;
    m->my_game->save_top_2 = m->my_game->move_top_bottom;
    m->my_game->save_side_2 = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(604 * 3.5) + 200;
    m->my_game->move_left_right = -(2721 * 3.5) + 385;
}

void cm_7(main_t *m)
{
    HOR_SAVE = HOR;
    VER_SAVE = VER;
    VER = 60;
    HOR = 49;
    m->my_game->save_top = m->my_game->move_top_bottom;
    m->my_game->save_side = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(1359 * 3.5) + 200;
    m->my_game->move_left_right = -(1199 * 3.5) + 385;
}