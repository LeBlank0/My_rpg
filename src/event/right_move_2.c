/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** right_move_2
*/

#include "rpg.h"
#include "my.h"

void cmr_0(main_t *m)
{
    m->game->the_move = 1;
    m->game->old_direction = 'n';
    m->game->direction = 'r';
}

void cmr_9(main_t *m)
{
    int spawn;

    spawn = rand() % 20;
    if (spawn == 5) {
        HOR += 1;
        m->my_game->move_left_right -= 56;
        m->my_game->fight = true;
        return;
    }
    m->game->the_move = 1;
    m->game->old_direction = 'n';
    m->game->direction = 'r';
}

void cmr_ff(main_t *m)
{
    m->game->the_move = 2;
    m->game->old_direction = 'n';
    m->game->direction = 'r';
}

void cmr_8(main_t *m)
{
    int spawn;
    m->my_game->rect_sacha_swim.left = 78;
    sfSprite_setTextureRect(m->my_game->sp_sacha_swim,
    m->my_game->rect_sacha_swim);
    if (m->game->swim == true) {

        spawn = rand() % 20;
        if (spawn == 5) {
            HOR -= 1;
            m->my_game->move_left_right += 56;
            m->my_game->fight = true;
            sfMusic_pause(m->intro->song_game);
            sfMusic_play(m->intro->song_fight);
            return;
        }
        m->game->the_move = 1;
        m->game->old_direction = 'n';
        m->game->direction = 'r';
    }
}