/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** up_move_2_3
*/

#include "rpg.h"
#include "my.h"

void cm_d(main_t *m)
{
    VER = VER_SAVE_2;
    HOR = HOR_SAVE_2;
    m->my_game->move_top_bottom = m->my_game->save_top_2;
    m->my_game->move_left_right = m->my_game->save_side_2;
}

void cm_dd(main_t *m)
{
    VER = VER_SAVE_2;
    HOR = HOR_SAVE_2;
    m->my_game->move_top_bottom = m->my_game->save_top_2;
    m->my_game->move_left_right = m->my_game->save_side_2;
}

void cm_8(main_t *m)
{
    int spawn;
    m->my_game->rect_sacha_swim.left = 26;
    sfSprite_setTextureRect(m->my_game->sp_sacha_swim,
    m->my_game->rect_sacha_swim);
    if (m->game->swim == true) {
        spawn = rand() % 20;
        if (spawn == 5) {
            HOR -= 1;
            m->my_game->move_left_right += 56;
            m->my_game->fight = true;
            return;
        }
        m->game->the_move = 1;
        m->game->old_direction = 'n';
        m->game->direction = 'u';
    }
}
