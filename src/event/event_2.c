/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_2
*/

#include "rpg.h"
#include "my.h"

void event_scene_one(main_t *m)
{
    if (EVENT.type == sfEvtMouseButtonReleased && m->menu_intro->pos_mous.x
    < resize_left(m, 770) && m->menu_intro->pos_mous.x > resize_left(m, 30) &&
    m->menu_intro->pos_mous.y > resize_top(m, 363) && m->menu_intro->pos_mous.y
    < resize_top(m, 476)
    && m->menu_intro->rect.left == 1600) {
        sfRenderWindow_setMouseCursorVisible(WINDOW, sfFalse);
        GAME_SCENE = 3;
    }
    if (EVENT.type == sfEvtMouseButtonReleased && m->menu_intro->pos_mous.x
    < resize_left(m, 770) && m->menu_intro->pos_mous.x > resize_left(m, 30) &&
    m->menu_intro->pos_mous.y > resize_top(m, 243) && m->menu_intro->pos_mous.y
    < resize_top(m, 356)
    && m->menu_intro->rect.left == 800) {
        sfMusic_stop(m->intro->song);
        sfMusic_play(m->intro->song_game);
        sfRenderWindow_setMouseCursorVisible(WINDOW, sfFalse);
        GAME_SCENE = 2;
    }
    if (m->menu_intro->pos_mous.x < resize_left(m, 770) &&
    m->menu_intro->pos_mous.x > resize_left(m, 30) && m->menu_intro->pos_mous.y
    > resize_top(m, 363) && m->menu_intro->pos_mous.y < resize_top(m, 476))
        m->menu_intro->rect.left = 1600;
    if (m->menu_intro->pos_mous.x < resize_left(m, 770) &&
    m->menu_intro->pos_mous.x > resize_left(m, 30) &&
    m->menu_intro->pos_mous.y > resize_top(m, 243) && m->menu_intro->pos_mous.y
    < resize_top(m, 356))
        m->menu_intro->rect.left = 800;
    if (m->menu_intro->pos_mous.x < resize_left(m, 770) &&
    m->menu_intro->pos_mous.x > resize_left(m, 30) && m->menu_intro->pos_mous.y
    > resize_top(m, 4) && m->menu_intro->pos_mous.y < resize_top(m, 256))
        m->menu_intro->rect.left = 0;
}

void event_scene_zero(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased &&
    EVENT.key.code == sfKeySpace && ((INTRO_SC == false) ||
    (INTRO_SC == true && m->intro->rect.top < 4860))) {
        INTRO_SC = true;
        m->intro->rect.left = 4860;
        m->intro->rect.top = 4860;
    }
    if (EVENT.type == sfEvtKeyReleased &&
        EVENT.key.code == sfKeySpace && INTRO_SC == true &&
        m->intro->rect.top > 4860)
        GAME_SCENE = 1;
}

void event_scene_three(main_t *m)
{
    change_set1(P1, m);
    change_set2(P2, m);
    move_scale(m);
    change_game_scene_options(m);
}

void game_scene_four(main_t *m)
{
    char *ch_scene[3] = {"1", "2", NULL};
    void (*scene[2])(main_t *) = {combat_event_scene_one,
        combat_event_scene_two};

    for (int i = 0; ch_scene[i] != NULL; i += 1)
        my_strcmp(ch_scene[i], my_itoa(COMBAT_SCENE)) == 0 ? scene[i](m) : 0;
}

void game_scene_five(main_t *m)
{
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code ==
        sfKeyBackspace)
        GAME_SCENE = 3;
}
