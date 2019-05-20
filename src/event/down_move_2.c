/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** down_move_2
*/

#include "rpg.h"
#include "my.h"

void cmd_0(main_t *m)
{
    m->game->the_move = 1;
    m->game->direction = 'd';
}

void cmd_9(main_t *m)
{
    int spawn;

    spawn = rand() % 20;
    if (spawn == 5) {
        VER += 1;
        m->my_game->move_top_bottom -= 56;
        m->my_game->fight = true;
        return;
    }
    m->game->the_move = 1;
    m->game->direction = 'd';
}

void cmd_x(main_t *m)
{
    m->game->the_move = 2;
    m->game->direction = 'd';
}

void cmd_l(main_t *m)
{
    VER = VER_SAVE;
    HOR = HOR_SAVE;
    m->my_game->move_top_bottom = m->my_game->save_top;
    m->my_game->move_left_right = m->my_game->save_side;
}

void cmd_8(main_t *m)
{
    int spawn;
    m->my_game->rect_sacha_swim.left = 0;
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
        m->game->direction = 'd';
    }
}