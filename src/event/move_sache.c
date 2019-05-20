/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_sache
*/

#include "rpg.h"
#include "my.h"

void left_move(main_t *m)
{
    m->my_game->rect_sacha.left = 28;
    m->my_game->rect_sacha.top += 21;
    sfSprite_setTextureRect(m->my_game->sacha_sprite,
    m->my_game->rect_sacha);
    if (m->my_game->rect_sacha.top >= 42)
        m->my_game->rect_sacha.top = 0;
    m->my_game->pers_move_restart = 1;
}

void right_move(main_t *m)
{
    m->my_game->rect_sacha.left = 42;
    m->my_game->rect_sacha.top += 21;
    sfSprite_setTextureRect(m->my_game->sacha_sprite,
    m->my_game->rect_sacha);
    if (m->my_game->rect_sacha.top >= 42)
        m->my_game->rect_sacha.top = 0;
    m->my_game->pers_move_restart = 2;
}

void up_move(main_t *m)
{
    m->my_game->rect_sacha.left = 14;
    m->my_game->rect_sacha.top += 21;
    sfSprite_setTextureRect(m->my_game->sacha_sprite,
    m->my_game->rect_sacha);
    if (m->my_game->rect_sacha.top >= 42)
        m->my_game->rect_sacha.top = 0;
    m->my_game->pers_move_restart = 3;
}

void down_move(main_t *m)
{
    m->my_game->rect_sacha.left = 0;
    m->my_game->rect_sacha.top += 21;
    sfSprite_setTextureRect(m->my_game->sacha_sprite,
    m->my_game->rect_sacha);
    if (m->my_game->rect_sacha.top >= 42)
        m->my_game->rect_sacha.top = 0;
    m->my_game->pers_move_restart = 4;
}