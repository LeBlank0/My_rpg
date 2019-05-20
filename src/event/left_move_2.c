/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** left_move_2
*/

#include "rpg.h"
#include "my.h"

void cml_0(main_t *m)
{
    m->game->the_move = 1;
    m->game->old_direction = 'n';
    m->game->direction = 'l';
}

void cml_8(main_t *m)
{
    int spawn;
    m->my_game->rect_sacha_swim.left = 52;
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
        m->game->direction = 'l';
    }
}

void cml_n(main_t *m)
{
    VER = VER_SAVE_2;
    HOR = HOR_SAVE_2;
    m->my_game->move_top_bottom = m->my_game->save_top_2;
    m->my_game->move_left_right = m->my_game->save_side_2;
}

void cml_nn(main_t *m)
{
    HOR_SAVE_2 = HOR;
    VER_SAVE_2 = VER;
    VER = 69;
    HOR = 22;
    m->my_game->save_top_2 = m->my_game->move_top_bottom;
    m->my_game->save_side_2 = m->my_game->move_left_right;
    m->my_game->move_top_bottom = -(1058 * 3.5) + 200;
    m->my_game->move_left_right = -(130 * 3.5) + 385;
}

void cml_9(main_t *m)
{
    int spawn;

    spawn = rand() % 20;
    if (spawn == 5) {
        HOR -= 1;
        m->my_game->move_left_right += 56;
        m->my_game->fight = true;
        return;
    }
    m->game->the_move = 1;
    m->game->old_direction = 'n';
    m->game->direction = 'l';
}