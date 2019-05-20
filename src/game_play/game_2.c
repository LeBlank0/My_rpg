/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_2
*/

#include "rpg.h"
#include "my.h"

int choice_pokemon(main_t *m)
{
    sfRenderWindow_drawSprite(WINDOW, m->game->sp_choice, NULL);
    sfSprite_setTextureRect(m->game->pokemon_choice, m->game->rect_pokemon);
    sfRenderWindow_drawSprite(WINDOW, m->game->pokemon_choice, NULL);
    sfRenderWindow_drawSprite(WINDOW, m->game->sp_arrow, NULL);
    sfSprite_setPosition(m->game->sp_arrow, m->game->move_arrow);
    return (0);
}

void ia_move(main_t *m)
{
    static float ia_timer;

    ia_timer += TIME;
    if (ia_timer > 4) {
        m->my_game->rect_ia.left = ((rand() % 4) * 17);
        ia_timer = 0;
    }
    sfSprite_setTextureRect(m->my_game->ia_sprite, m->my_game->rect_ia);
}

void menu_pause(main_t *m)
{
    if (STATE_GAME == true) {
        if (m->game->coord == 445)
            m->game->coord = 185;
        for (int i = 4; i < NB_SP_MENU_INTRO; i++) {
            menu_pause_2(i, m);
            sfRenderWindow_drawSprite(WINDOW, SP_MENU_INTRO[i], NULL);
        }
    }
}

void move_up(main_t *m, float *timer)
{
    static int enter = 0;
    if (enter == 4) {
        enter = 0;
        *timer = 0;
        m->game->the_move--;
        VER -= 1;
        if (m->game->the_move <= 0) {
            m->game->the_move = 0;
            m->game->old_direction = 'u';
            m->game->direction = 'n';
            return;
        }
    }
    if (*timer >= 0.02) {
        m->my_game->move_top_bottom += 14;
        *timer = 0;
        enter++;
    }
}

void move_down(main_t *m, float *timer)
{
    static int enter = 0;
    if (enter == 4) {
        enter = 0;
        *timer = 0;
        m->game->the_move--;
        VER += 1;
        if (m->game->the_move <= 0) {
            m->game->the_move = 0;
            m->game->old_direction = 'd';
            m->game->direction = 'n';
            return;
        }
    }
    if (*timer >= 0.02) {
        m->my_game->move_top_bottom -= 14;
        *timer = 0;
        enter++;
    }
}
